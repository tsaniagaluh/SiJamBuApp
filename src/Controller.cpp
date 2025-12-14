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
    : sistem(pathInput, pathOutput), currentUserId(-1) {
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
        cout << "6. Tampilkan Daftar User" << endl;
        cout << "7. Tampilkan Daftar Transaksi Peminjaman" << endl;
        cout << "8. Kembali" << endl;
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
                uiTampilkanDaftarUser();
                break;
            case 7:
                uiTampilkanDaftarTransaksi();
                break;
            case 8:
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
    
    // Menyimpan current user ID
    currentUserId = idUser;
    
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
                currentUserId = -1;  // Reset current user ID ketika keluar
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
    cout << "\n=== EDIT BUKU ===" << endl;
    cout << "Masukkan ID buku yang akan diedit: ";
    cin >> idBuku;
    cin.ignore();
    
    // Cek jika buku tersedia
    Buku bukuLama = sistem.cariBukuById(idBuku);
    if (bukuLama.getId() == -1) {
        cout << "Gagal: Buku dengan ID " << idBuku << " tidak ditemukan." << endl;
        return;
    }
    
    // Menampilkan opsi edit
    int pilihAtribut = 0;
    bool valid = false;
    
    while (!valid) {
        cout << "\n=== PILIH ATRIBUT YANG AKAN DIEDIT ===" << endl;
        cout << "1. Judul" << endl;
        cout << "2. Penulis" << endl;
        cout << "3. Tahun Terbit" << endl;
        cout << "4. Stok" << endl;
        cout << "5. Batal" << endl;
        cout << "Pilih atribut: ";
        cin >> pilihAtribut;
        cin.ignore();
        
        switch (pilihAtribut) {
            case 1: {
                cout << "Judul saat ini: " << bukuLama.getJudul() << endl;
                cout << "Masukkan judul baru: ";
                string judulBaru;
                getline(cin, judulBaru);
                
                if (sistem.editBukuJudul(idBuku, judulBaru)) {
                    cout << "Judul berhasil diperbarui." << endl;
                } else {
                    cout << "Gagal memperbarui judul." << endl;
                }
                valid = true;
                break;
            }
            case 2: {
                cout << "Penulis saat ini: " << bukuLama.getPenulis() << endl;
                cout << "Masukkan penulis baru: ";
                string penulisBaru;
                getline(cin, penulisBaru);
                
                if (sistem.editBukuPenulis(idBuku, penulisBaru)) {
                    cout << "Penulis berhasil diperbarui." << endl;
                } else {
                    cout << "Gagal memperbarui penulis." << endl;
                }
                valid = true;
                break;
            }
            case 3: {
                cout << "Tahun terbit saat ini: " << bukuLama.getTahun() << endl;
                cout << "Masukkan tahun terbit baru: ";
                int tahunBaru;
                cin >> tahunBaru;
                cin.ignore();
                
                if (sistem.editBukuTahun(idBuku, tahunBaru)) {
                    cout << "Tahun terbit berhasil diperbarui." << endl;
                } else {
                    cout << "Gagal memperbarui tahun terbit." << endl;
                }
                valid = true;
                break;
            }
            case 4: {
                cout << "Stok saat ini: " << bukuLama.getStok() << endl;
                cout << "Masukkan stok baru: ";
                int stokBaru;
                cin >> stokBaru;
                cin.ignore();
                
                if (sistem.editBukuStok(idBuku, stokBaru)) {
                    cout << "Stok berhasil diperbarui." << endl;
                } else {
                    cout << "Gagal memperbarui stok." << endl;
                }
                valid = true;
                break;
            }
            case 5:
                cout << "Edit dibatalkan." << endl;
                valid = true;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
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
void Controller::uiTampilkanDaftarUser() {
    sistem.tampilkanDaftarUser();
}

/**
 * @return void
 */
void Controller::uiTampilkanDaftarTransaksi() {
    sistem.tampilkanDaftarTransaksi();
}

/**
 * @return void
 */
void Controller::uiPinjamBuku() {
    sistem.tampilkanDaftarBuku();
    
    int idBuku;
    string tanggal;
    
    cout << "\n=== PINJAM BUKU ===" << endl;
    cout << "Masukkan ID buku yang akan dipinjam: ";
    cin >> idBuku;
    cin.ignore();
    cout << "Masukkan tanggal peminjaman (DD/MM/YYYY): ";
    getline(cin, tanggal);
    
    sistem.pinjamBuku(currentUserId, idBuku, tanggal);
}

/**
 * @return void
 */
void Controller::uiKembalikanBuku() {
    int idBuku;
    string tanggal;
    
    cout << "\n=== KEMBALIKAN BUKU ===" << endl;
    cout << "Masukkan ID buku yang akan dikembalikan: ";
    cin >> idBuku;
    cin.ignore();
    cout << "Masukkan tanggal pengembalian (DD/MM/YYYY): ";
    getline(cin, tanggal);
    
    sistem.kembalikanBuku(currentUserId, idBuku, tanggal);
}

/**
 * @return void
 */
void Controller::uiTampilkanPinjamanUser() {
    cout << "\n=== RIWAYAT PEMINJAMAN ===" << endl;
    sistem.tampilkanPinjamanUser(currentUserId);
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