#include "PenyimpananFile.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

/**
 * PenyimpananFile implementation
 */


/**
 * @param pathInput
 * @param pathOutput
 */
PenyimpananFile::PenyimpananFile(string pathInput, string pathOutput)
    : pathInput(pathInput), pathOutput(pathOutput) {
}

/**
 * @param buku
 * @return bool
 */
bool PenyimpananFile::muatBuku(vector<Buku>& buku) {
    ifstream file(pathInput);
    if (!file.is_open()) {
        cout << "File input tidak ditemukan: " << pathInput << endl;
        return false;
    }
    
    string line;
    int lineNum = 0;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        
        istringstream iss(line);
        int id, tahun, stok;
        string judul, penulis;
        
        if (iss >> id >> judul >> penulis >> tahun >> stok) {
            buku.push_back(Buku(id, judul, penulis, tahun, stok));
        }
        lineNum++;
    }
    
    file.close();
    return true;
}

/**
 * @param buku
 * @return bool
 */
bool PenyimpananFile::simpanBuku(vector<Buku>& buku) {
    ofstream file(pathOutput);
    if (!file.is_open()) {
        cout << "Gagal membuka file output: " << pathOutput << endl;
        return false;
    }
    
    file << "# DAFTAR BUKU" << endl;
    for (const auto& b : buku) {
        file << b.getId() << " " << b.getJudul() << " " << b.getPenulis() << " " 
             << b.getTahun() << " " << b.getStok() << endl;
    }
    
    file.close();
    return true;
}

/**
 * @param user
 * @return bool
 */
bool PenyimpananFile::muatUser(vector<User>& user) {
    ifstream file(pathInput);
    if (!file.is_open()) {
        cout << "File input tidak ditemukan: " << pathInput << endl;
        return false;
    }
    
    string line;
    bool inUserSection = false;
    int lineNum = 0;
    
    while (getline(file, line)) {
        // Cek jika ini adalah section header user
        if (line.find("DAFTAR BUKU") != string::npos) {
            inUserSection = false;
            continue;
        }
        if (line.find("DAFTAR USER") != string::npos) {
            inUserSection = true;
            continue;
        }
        if (line.find("DAFTAR TRANSAKSI") != string::npos) {
            inUserSection = false;
            continue;
        }
        
        // Skip baris kosong dan komentar
        if (line.empty() || line[0] == '#') {
            continue;
        }
        
        if (!inUserSection) continue;
        
        istringstream iss(line);
        int id;
        string nama;
        
        if (iss >> id && getline(iss, nama)) {
            if (!nama.empty() && nama[0] == ' ') {
                nama = nama.substr(1);
            }
            user.push_back(User(id, nama));
        }
        lineNum++;
    }
    
    file.close();
    return true;
}

/**
 * @param user
 * @return bool
 */
bool PenyimpananFile::simpanUser(vector<User>& user) {
    ofstream file(pathOutput, ios::app);  // Append ke file yang sudah ada
    if (!file.is_open()) {
        cout << "Gagal membuka file output: " << pathOutput << endl;
        return false;
    }
    
    file << "\n# DAFTAR USER" << endl;
    for (const auto& u : user) {
        file << u.getId() << " " << u.getNama() << endl;
    }
    
    file.close();
    return true;
}

/**
 * @param transaksi
 * @return bool
 */
bool PenyimpananFile::muatTransaksi(vector<TransaksiPeminjaman>& transaksi) {
    ifstream file(pathInput);
    if (!file.is_open()) {
        cout << "File input tidak ditemukan: " << pathInput << endl;
        return false;
    }
    
    string line;
    bool inTransaksiSection = false;
    int lineNum = 0;
    
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') {
            // Cek jika ini adalah section header transaksi
            if (line.find("TRANSAKSI") != string::npos || line.find("PEMINJAMAN") != string::npos) {
                inTransaksiSection = true;
            }
            continue;
        }
        
        if (!inTransaksiSection) continue;
        
        istringstream iss(line);
        int id, idUser, idBuku;
        string tanggalPinjam, tanggalKembali;
        
        if (iss >> id >> idUser >> idBuku >> tanggalPinjam >> tanggalKembali) {
            TransaksiPeminjaman t(id, idUser, idBuku, tanggalPinjam);
            // Parse tanggalKembali dan status jika ada
            if (tanggalKembali != "-") {
                t.tandaiDikembalikan(tanggalKembali);
            }
            transaksi.push_back(t);
        }
        lineNum++;
    }
    
    file.close();
    return true;
}

/**
 * @param transaksi
 * @return bool
 */
bool PenyimpananFile::simpanTransaksi(vector<TransaksiPeminjaman>& transaksi) {
    ofstream file(pathOutput, ios::app);  // Append ke file yang sudah ada
    if (!file.is_open()) {
        cout << "Gagal membuka file output: " << pathOutput << endl;
        return false;
    }
    
    file << "\n# DAFTAR TRANSAKSI PEMINJAMAN" << endl;
    file << "# Format: ID IDUser IDBuku TanggalPinjam TanggalKembali" << endl;
    for (const auto& t : transaksi) {
        file << t.getId() << " " << t.getIdUser() << " " << t.getIdBuku() << " "
             << t.getTanggalPinjam() << " " 
             << (t.getTanggalKembali().empty() ? "-" : t.getTanggalKembali()) << endl;
    }
    
    file.close();
    return true;
}