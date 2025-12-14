# SiJamBu - Sistem Peminjaman Buku

**SiJamBu** adalah aplikasi peminjaman buku berbasis C++ dengan mengimplementasikan Object-Oriented Programming yang dirancang untuk mengelola:
- Koleksi buku dengan sistem stock management
- Data pengguna (user)
- Transaksi peminjaman dan pengembalian buku
- Persistent storage ke file

## Quick Start

### 1. Run Aplikasi
```bash
# Windows
build\SiJamBu.exe

# Linux/macOS
./build/SiJamBu
```

### 2. Menu Utama
```
1. Menu Admin    → Kelola buku (CRUD)
2. Menu User     → Pinjam/kembalikan buku
3. Keluar        → Exit dengan save option
```

### 3. Contoh Penggunaan
```
Admin Mode:
  - Tambah stok buku baru
  - Edit/update detail buku
  - Hapus buku dari sistem
  - Lihat daftar lengkap buku

User Mode:
  - Register user baru (auto ID)
  - Pinjam buku 
  - Kembalikan buku
  - Lihat riwayat peminjaman
```

---

## Fitur Utama

### F-01: Tambah Buku
Admin menambah data buku baru dengan validasi dan auto-generate ID.

### F-02: Edit Buku
Admin mengedit detail buku yang sudah ada (judul, penulis, tahun, stok).

### F-03: Hapus Buku
Admin menghapus buku dari sistem dengan konfirmasi.

### F-04: Tampil Daftar Buku
Menampilkan semua buku dengan detail lengkap (ID, Judul, Penulis, Tahun, Stok).

### F-05: Pinjam Buku
User meminjam buku dengan validasi stock ketersediaan dan auto-recording transaksi.

### F-06: Kembalikan Buku
User mengembalikan buku dengan update status transaksi dan restore stok.

### F-07: Load Data
Membaca data buku dari file input.txt saat aplikasi startup.

### F-08: Save Data
Menyimpan perubahan data ke file output.txt.

---

## Struktur Proyek

```
SiJamBuApp/
├── include/                    # Header files
│   ├── Buku.h                 
│   ├── User.h                
│   ├── Admin.h             
│   ├── SistemPeminjaman.h     # Core business logic
│   ├── TransaksiPeminjaman.h  
│   ├── Controller.h           # UI coordinator
│   └── PenyimpananFile.h      # File I/O layer
│
├── src/                        # Source implementation
│   ├── Buku.cpp
│   ├── User.cpp
│   ├── Admin.cpp
│   ├── SistemPeminjaman.cpp   
│   ├── TransaksiPeminjaman.cpp
│   ├── Controller.cpp          
│   ├── PenyimpananFile.cpp
│   └── main.cpp
│
├── build/
│   └── SiJamBu.exe                
│
├── data/
│   ├── input.txt              
│   └── output.txt             
│
└── docs/
    ├── README.md              
    └── SiJamBuApp_UML.mdj     # Use Case & Class Diagram
```

---

## Spesifikasi Teknis

### Requirements
- **Compiler:** GCC/Clang with C++17 support
- **OS:** Windows, Linux, macOS
- **Dependencies:** None (standard library only)
- **Size:** ~3.2 MB executable

### Compile Command
```bash
g++ -std=c++17 -Wall -Wextra -I include src/*.cpp -o build/SiJamBu.exe
```