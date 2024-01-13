# Remote Transmitter

Kode Arduino ini berfungsi sebagai transmitter menggunakan Arduino Mega bersama dengan modul NRF24L01, joystick, dan tombol. Alat ini dirancang untuk mengirimkan data secara nirkabel ke penerima yang sesuai.

## Components

- Arduino Mega (atau board lain yang kompatibel)
- NRF24L01 Wireless Transceiver Module
- Joystick
- Button
- LCD I2C

## Struktur
Berikut merupakan struktur kode pada program ini:
```
.
├── RemoteTx.ino       File program utama
├── Config             Konfigurasi dan setup proyek
├── Radio              Fungsionalitas modul NRF24L01
├── Screen             Fungsionalitas modul LCD I2C
└── README.md          File README
```