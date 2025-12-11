#include "Controller.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * Controller implementation
 */


/**
 * @param pathInput
 * @param pathOutput
 */
Controller::Controller(string pathInput, string pathOutput)
    : sistem(pathInput, pathOutput) {
}

/**
 * @return void
 */
void Controller::loopPerintah() {
    int pilihan = 0;
    while (true) {
        cout << "\n=== SISTEM PEMINJAMAN BUKU ===" << endl;
        cout << "1. Menu Admin" << endl;
        cout << "2. Menu User" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1:
                menuAdmin();
                break;
            case 2:
                menuUser();
                break;
            case 3:
                cout << "Simpan data sebelum keluar? (y/n): ";
                char opsi;
                cin >> opsi;
                if (opsi == 'y' || opsi == 'Y') {
                    uiSimpanData();
                }
                cout << "Terima kasih! Sampai jumpa." << endl;
                return;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }
}

/**
 * @return void
 */
void Controller::menuAdmin() {
    int pilihan = 0;
    while (true) {
        cout << "\n=== MENU ADMIN ===" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Edit Buku" << endl;
        cout << "3. Hapus Buku" << endl;
        cout << "4. Tampilkan Daftar Buku" << endl;
        cout << "5. Cari Buku" << endl;
        cout << "6. Kembali" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1:
                uiTambahBuku();
                break;
            case 2:
                uiEditBuku();
                break;
            case 3:
                uiHapusBuku();
                break;
            case 4:
                uiTampilkanDaftarBuku();
                break;
            case 5:
                {
                    string keyword;
                    cout << "Masukkan judul buku (atau sebagian): ";
                    getline(cin, keyword);
                    sistem.cariBukuByJudul(keyword);
                }
                break;
            case 6:
                return;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }
}

/**
 * @return void
 */
void Controller::menuUser() {
    int idUser;
    cout << "Masukkan ID User (0 untuk user baru): ";
    cin >> idUser;
    cin.ignore();
    
    if (idUser == 0) {
        string nama;
        cout << "Masukkan nama: ";
        getline(cin, nama);
        idUser = sistem.tambahUser(nama);
        cout << "User baru dibuat dengan ID: " << idUser << endl;
    }
    
    int pilihan = 0;
    while (true) {
        cout << "\n=== MENU USER (ID: " << idUser << ") ===" << endl;
        cout << "1. Pinjam Buku" << endl;
        cout << "2. Kembalikan Buku" << endl;
        cout << "3. Lihat Riwayat Peminjaman" << endl;
        cout << "4. Lihat Daftar Buku" << endl;
        cout << "5. Kembali" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1:
                uiPinjamBuku();
                break;
            case 2:
                uiKembalikanBuku();
                break;
            case 3:
                uiTampilkanPinjamanUser();
                break;
            case 4:
                uiTampilkanDaftarBuku();
                break;
            case 5:
                return;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }
}

/**
 * @return void
 */
void Controller::uiTambahBuku() {
    string judul, penulis;
    int tahun, stok;
    
    cout << "\n=== TAMBAH BUKU ===" << endl;
    cout << "Masukkan judul: ";
    getline(cin, judul);
    cout << "Masukkan penulis: ";
    getline(cin, penulis);
    cout << "Masukkan tahun terbit: ";
    cin >> tahun;
    cout << "Masukkan stok: ";
    cin >> stok;
    cin.ignore();
    
    int idBuku = sistem.tambahBuku(judul, penulis, tahun, stok);
    cout << "Buku berhasil ditambahkan dengan ID: " << idBuku << endl;
}

/**
 * @return void
 */
void Controller::uiEditBuku() {
    sistem.tampilkanDaftarBuku();
    
    int idBuku;
    string judul, penulis;
    int tahun, stok;
    
    cout << "\n=== EDIT BUKU ===" << endl;
    cout << "Masukkan ID buku yang akan diedit: ";
    cin >> idBuku;
    cin.ignore();
    
    cout << "Masukkan judul baru: ";
    getline(cin, judul);
    cout << "Masukkan penulis baru: ";
    getline(cin, penulis);
    cout << "Masukkan tahun terbit baru: ";
    cin >> tahun;
    cout << "Masukkan stok baru: ";
    cin >> stok;
    cin.ignore();
    
    if (sistem.editBuku(idBuku, judul, penulis, tahun, stok)) {
        cout << "Buku berhasil diperbarui." << endl;
    } else {
        cout << "Gagal memperbarui buku (ID tidak ditemukan)." << endl;
    }
}

/**
 * @return void
 */
void Controller::uiHapusBuku() {
    sistem.tampilkanDaftarBuku();
    
    int idBuku;
    cout << "\n=== HAPUS BUKU ===" << endl;
    cout << "Masukkan ID buku yang akan dihapus: ";
    cin >> idBuku;
    cin.ignore();
    
    cout << "Apakah Anda yakin ingin menghapus buku ini? (y/n): ";
    char konfirmasi;
    cin >> konfirmasi;
    cin.ignore();
    
    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        if (sistem.hapusBuku(idBuku)) {
            cout << "Buku berhasil dihapus." << endl;
        } else {
            cout << "Gagal menghapus buku (ID tidak ditemukan)." << endl;
        }
    } else {
        cout << "Penghapusan dibatalkan." << endl;
    }
}

/**
 * @return void
 */
void Controller::uiTampilkanDaftarBuku() {
    sistem.tampilkanDaftarBuku();
}

/**
 * @return void
 */
void Controller::uiPinjamBuku() {
    sistem.tampilkanDaftarBuku();
    
    int idUser, idBuku;
    string tanggal;
    
    cout << "\n=== PINJAM BUKU ===" << endl;
    cout << "Masukkan ID user: ";
    cin >> idUser;
    cout << "Masukkan ID buku yang akan dipinjam: ";
    cin >> idBuku;
    cin.ignore();
    cout << "Masukkan tanggal peminjaman (DD/MM/YYYY): ";
    getline(cin, tanggal);
    
    sistem.pinjamBuku(idUser, idBuku, tanggal);
}

/**
 * @return void
 */
void Controller::uiKembalikanBuku() {
    int idUser, idBuku;
    string tanggal;
    
    cout << "\n=== KEMBALIKAN BUKU ===" << endl;
    cout << "Masukkan ID user: ";
    cin >> idUser;
    cout << "Masukkan ID buku yang akan dikembalikan: ";
    cin >> idBuku;
    cin.ignore();
    cout << "Masukkan tanggal pengembalian (DD/MM/YYYY): ";
    getline(cin, tanggal);
    
    sistem.kembalikanBuku(idUser, idBuku, tanggal);
}

/**
 * @return void
 */
void Controller::uiTampilkanPinjamanUser() {
    int idUser;
    cout << "\n=== RIWAYAT PEMINJAMAN ===" << endl;
    cout << "Masukkan ID user: ";
    cin >> idUser;
    cin.ignore();
    
    sistem.tampilkanPinjamanUser(idUser);
}

/**
 * @return void
 */
void Controller::uiMuatData() {
    cout << "\n=== MUAT DATA ===" << endl;
    if (sistem.muatData()) {
        cout << "Data berhasil dimuat." << endl;
    } else {
        cout << "Gagal memuat data." << endl;
    }
}

/**
 * @return void
 */
void Controller::uiSimpanData() {
    cout << "\n=== SIMPAN DATA ===" << endl;
    if (sistem.simpanData()) {
        cout << "Data berhasil disimpan." << endl;
    } else {
        cout << "Gagal menyimpan data." << endl;
    }
}