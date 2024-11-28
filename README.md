# Sistem Penyiraman Tanaman Otomatis Dengan IoT Sesuai Kelembaban Tanah 🌱💧

# 🔍 Overview
Repositori ini berisi kode untuk Sistem Penyiraman Tanaman Otomatis menggunakan IoT dan platform Blynk. Sistem ini memonitor tingkat kelembapan tanah dan mengontrol katup solenoid untuk menyiram tanaman secara otomatis atau manual. Notifikasi akan dikirimkan ke pengguna melalui aplikasi Blynk.

# ✨ Fitur Utama
1. Pemantauan Kelembapan Tanah
   Menggunakan sensor kelembapan tanah kapasitif untuk membaca kondisi tanah.
2. Dukungan Mode Penyiraman
   - Mode Otomatis: Penyiraman dilakukan berdasarkan ambang kelembapan yang telah ditentukan.
   - Mode Manual: Penyiraman dikontrol langsung melalui aplikasi Blynk.
3. Notifikasi Pengguna
   - Tanah terlalu kering.
   - Penyiraman otomatis dimulai atau dihentikan.
   - Peringatan saat penyiraman manual aktif.
4. Ambang Kelembapan Dapat Dikustomisasi
   Ambang batas dapat diubah sesuai kebutuhan pengguna.
5. Pemantauan Real-Time
   Pantau data kelembapan tanah dan status sistem melalui aplikasi Blynk.

# 🛠️ Komponen yang Digunakan
- ESP8266 NodeMCU (mikrokontroler utama).
- Sensor Kelembapan Tanah Kapasitif.
- Modul Relay untuk mengontrol solenoid valve.
- Solenoid Valve sebagai pengatur aliran air.
- Aplikasi Blynk untuk pemantauan, kontrol, dan notifikasi IoT.
- Sumber Daya: Dapat menggunakan solar cell atau baterai (opsional sesuai konfigurasi).

# 📋 Software Requirements
1. Pasang Arduino IDE di komputer Anda.
2. Tambahkan board ESP8266 pada Arduino IDE.
3. Pasang pustaka berikut:
   - Blynk: BlynkSimpleEsp8266.h
   - ESP8266WiFi

# 🚀 Installation Guide
1. Clone repositori ini:
   git clone https://github.com/GregoriusVincentAdam/Penyiraman-Otomatis.git
2. Buka file .ino di Arduino IDE.
3. Sesuaikan placeholder berikut dengan informasi Anda:
   - Token Auth Blynk: Ganti dengan token dari proyek Blynk Anda.
   - Kredensial WiFi: Ganti dengan SSID dan password WiFi Anda.
   - Upload kode ke board ESP8266.

# ⚙️ Configuration
Kalibrasi Sensor Kelembapan Tanah
   Sesuaikan nilai dryValue dan wetValue di kode berdasarkan pembacaan sensor kelembapan tanah Anda:
   - dryValue: Nilai sensor saat tanah benar-benar kering.
   - wetValue: Nilai sensor saat tanah benar-benar basah.

Pengaturan Ambang Batas
  Sesuaikan ambang kelembapan tanah di fungsi soilMoistureSensor():
  - Di bawah 40%: Tanah kering, penyiraman dimulai.
  - Di atas 60%: Tanah basah, penyiraman dihentikan.

# 🕹️ Penggunaan Sistem
1. Buka aplikasi Blynk dan pastikan proyek Anda diatur dengan:
   - Pin Virtual V0: Menampilkan tingkat kelembapan tanah.
   - Pin Virtual V1: Mengaktifkan atau menonaktifkan penyiraman otomatis.
   - Pin Virtual V2: Mengaktifkan atau menonaktifkan penyiraman manual.
2. Pantau dan kendalikan sistem
   - Gunakan aplikasi untuk memantau kelembapan tanah secara real-time.
   - Kendalikan mode penyiraman sesuai kebutuhan Anda.

# 🔔 Notifikasi yang Dikirim Sistem
Sistem mengirimkan notifikasi melalui aplikasi Blynk untuk:
1. Kelembapan tanah rendah: Memberitahu pengguna bahwa tanah harus disiram.
2. Status penyiraman otomatis: Ketika penyiraman otomatis dimulai atau dihentikan.
3. Peringatan mode manual: Menyarankan untuk mematikan penyiraman manual jika tanah cukup basah.
