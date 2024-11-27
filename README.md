# Sistem Penyiraman Tanaman Otomatis Dengan IoT Sesuai Kelembaban Tanah
Repositori ini berisi kode untuk Sistem Penyiraman Tanaman Otomatis menggunakan IoT dan platform Blynk. Sistem ini memonitor tingkat kelembapan tanah dan mengontrol katup solenoid untuk menyiram tanaman secara otomatis atau manual. Notifikasi akan dikirimkan ke pengguna melalui aplikasi Blynk.

# Fitur
Memantau tingkat kelembapan tanah menggunakan sensor kelembapan tanah kapasitif.
Mendukung mode otomatis dan mode manual:
Mode otomatis: Menyiram tanaman berdasarkan ambang kelembapan tanah yang telah ditentukan.
Mode manual: Penyiraman dapat dikontrol langsung oleh pengguna melalui aplikasi Blynk.
Mengirim notifikasi kepada pengguna:
Tanah terlalu kering.
Penyiraman otomatis dimulai atau berhenti.
Peringatan saat penyiraman manual.
Ambang batas kelembapan tanah dapat dikonfigurasi.
Pemantauan secara real-time melalui aplikasi Blynk.


# Komponen yang Digunakan
- ESP8266 NodeMCU (mikrokontroler)
- Sensor Kelembapan Tanah Kapasitif
- Modul Relay
- Katup Solenoid
- Aplikasi Blynk untuk kontrol IoT dan notifikasi
- Sumber daya: Solar atau baterai (opsional, sesuai dengan konfigurasi sistem Anda)

# Memulai
Prasyarat
Pasang Arduino IDE di komputer Anda.
Tambahkan board ESP8266 pada Arduino IDE.
Pasang pustaka berikut:
Blynk: BlynkSimpleEsp8266.h
**ESP8266WiFi`

# Langkah-Langkah
Clone repositori ini:
bash
Copy code
git clone https://github.com/GregoriusVincentAdam/Penyiraman-Otomatis.git
Buka file .ino di Arduino IDE.
Sesuaikan placeholder berikut dengan informasi Anda:
Token Auth Blynk: Ganti dengan token dari proyek Blynk Anda.
Kredensial WiFi: Ganti dengan SSID dan password WiFi Anda.
Upload kode ke board ESP8266.

# Konfigurasi
Kalibrasi Kelembapan Tanah
Sesuaikan nilai dryValue dan wetValue di kode berdasarkan pembacaan sensor kelembapan tanah Anda:
- dryValue: Nilai sensor saat tanah benar-benar kering.
- wetValue: Nilai sensor saat tanah benar-benar basah.

# Ambang Batas
Sesuaikan ambang kelembapan tanah di fungsi soilMoistureSensor():
Di bawah 40%: Tanah kering, penyiraman dimulai.
Di atas 60%: Tanah basah, penyiraman dihentikan.

# Penggunaan
Buka aplikasi Blynk dan pastikan proyek Anda diatur dengan:
Pin Virtual V0: Menampilkan tingkat kelembapan tanah.
Pin Virtual V1: Mengaktifkan atau menonaktifkan penyiraman otomatis.
Pin Virtual V2: Mengaktifkan atau menonaktifkan penyiraman manual.
Pantau kelembapan tanah secara real-time dan kendalikan sistem penyiraman melalui aplikasi.

# Notifikasi
Sistem mengirimkan notifikasi melalui aplikasi Blynk untuk:
Kelembapan tanah rendah: Memberitahu pengguna bahwa tanah harus disiram.
Status penyiraman otomatis: Ketika penyiraman otomatis dimulai atau dihentikan.
Peringatan mode manual: Menyarankan untuk mematikan penyiraman manual jika tanah cukup basah.
