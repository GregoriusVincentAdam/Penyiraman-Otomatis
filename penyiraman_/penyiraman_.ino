#define BLYNK_TEMPLATE_ID "TMPL6kYqIAchD"
#define BLYNK_TEMPLATE_NAME "Penyiraman"
#define BLYNK_AUTH_TOKEN "xBKTEG9fouXN3yvS3zyXcGLeQr9V7g2c"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Auth token dan informasi WiFi
char auth[] = "xBKTEG9fouXN3yvS3zyXcGLeQr9V7g2c"; // Masukkan token Auth Anda
char ssid[] = "samsung_a53"; // Masukkan nama WIFI Anda
char pass[] = "Vivavi1234"; // Masukkan password WIFI Anda

BlynkTimer timer;
bool autoWatering = false;
bool manualWatering = false; // Tambahkan variabel untuk status penyiraman manual

// Pin komponen
#define sensor A0
#define solenoidValve D3 // Ganti dengan pin solenoid valve Anda

// Kalibrasi sensor (sesuaikan dengan hasil pengukuran Anda)
int dryValue = 800; // Nilai sensor saat tanah kering
int wetValue = 300; // Nilai sensor saat tanah basah

// Tambahkan variabel global untuk menyimpan nilai kelembaban
int currentMoistureValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(solenoidValve, OUTPUT);
  digitalWrite(solenoidValve, LOW); // Pastikan solenoid valve mati saat memulai

  // Memulai koneksi ke server Blynk
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  // Atur interval pengambilan data kelembaban tanah
  timer.setInterval(1000L, soilMoistureSensor); // Interval 1 detik
}

// Fungsi untuk kontrol otomatis solenoid valve
BLYNK_WRITE(V1) {
  autoWatering = param.asInt();
  
  if (!autoWatering) {
    digitalWrite(solenoidValve, LOW); // Pastikan solenoid valve mati jika mode otomatis dinonaktifkan
  }
}

// Fungsi untuk kontrol manual solenoid valve (Tanpa notifikasi)
BLYNK_WRITE(V2) {
  if (autoWatering) return; // Abaikan kontrol manual jika mode otomatis aktif

  int value = param.asInt();
  manualWatering = value; // Update status penyiraman manual
  
  if (manualWatering) {
    digitalWrite(solenoidValve, HIGH); // Aktifkan penyiraman manual
  } else {
    digitalWrite(solenoidValve, LOW); // Matikan penyiraman manual
  }
}

// Fungsi untuk membaca nilai kelembaban tanah
void soilMoistureSensor() {
  int rawValue = analogRead(sensor);
  
  // Kalibrasi nilai kelembaban tanah ke dalam persentase
  currentMoistureValue = map(rawValue, dryValue, wetValue, 0, 100);
  currentMoistureValue = constrain(currentMoistureValue, 0, 100); // Pastikan nilai berada dalam rentang 0-100

  Blynk.virtualWrite(V0, currentMoistureValue); // Kirim nilai kelembaban ke Blynk

  // Jika kelembaban tanah < 40% dan kedua tombol tidak diaktifkan (otomatis dan manual)
  if (currentMoistureValue < 40 && !autoWatering && !manualWatering) {
    String notification = "!!!Tanah mulai kering!!! Harus disiram. Kelembaban tanah saat ini: " + String(currentMoistureValue) + "%";
    Blynk.logEvent("warning_soil_moisture_below_40", notification); // Kirim event ke Blynk Web
  }

  // Jika dalam mode otomatis
  if (autoWatering) {

    if (currentMoistureValue < 40) {
      digitalWrite(solenoidValve, HIGH); // Aktifkan penyiraman otomatis
      String notification = "!!!Tanah mulai kering!!! Mulai menyiram otomatis. Kelembaban tanah saat ini: " + String(currentMoistureValue) + "%";
      Blynk.logEvent("soil_moisture_below_40_otomatis_active", notification); // Kirim event ke Blynk Web
    } else if (currentMoistureValue > 60) {
      digitalWrite(solenoidValve, LOW); // Matikan penyiraman otomatis
      String notification = "Tanah lembab! Penyiraman otomatis berhenti. Kelembaban tanah saat ini: " + String(currentMoistureValue) + "%";
      Blynk.logEvent("soil_moisture_above_60_otomatis_stop_siram", notification); // Kirim event ke Blynk Web
    }
  }

  // Jika dalam mode manual dan kelembaban > 60%, berikan notifikasi
  if (manualWatering && currentMoistureValue > 60) {
    String notification = "Tanah lembab! Matikan penyiraman manual. Kelembaban tanah saat ini: " + String(currentMoistureValue) + "%";
    Blynk.logEvent("manual_soil_moisture_above_60", notification); // Kirim event ke Blynk Web
  }
}

void loop() {
  Blynk.run();
  timer.run();
}
