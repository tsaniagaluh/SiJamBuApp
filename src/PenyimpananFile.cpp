/**
 * Project Program Akademik
 */


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
bool PenyimpananFile::muatUser(vector<User>& /* user */) {
    // For now, return true (dummy implementation)
    return true;
}

/**
 * @param user
 * @return bool
 */
bool PenyimpananFile::simpanUser(vector<User>& /* user */) {
    // For now, return true (dummy implementation)
    return true;
}

/**
 * @param transaksi
 * @return bool
 */
bool PenyimpananFile::muatTransaksi(vector<TransaksiPeminjaman>& /* transaksi */) {
    // For now, return true (dummy implementation)
    return true;
}

/**
 * @param transaksi
 * @return bool
 */
bool PenyimpananFile::simpanTransaksi(vector<TransaksiPeminjaman>& /* transaksi */) {
    // For now, return true (dummy implementation)
    return true;
}