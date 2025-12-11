#ifndef _SISTEMPEMINJAMAN_H
#define _SISTEMPEMINJAMAN_H

#include "Buku.h"
#include "User.h"
#include "TransaksiPeminjaman.h"
#include "PenyimpananFile.h"
#include <vector>
#include <string>
using namespace std;

class SistemPeminjaman {
public: 
    
/**
 * @param pathInput
 * @param pathOutput
 */
SistemPeminjaman(string pathInput, string pathOutput);
    
bool muatData();
    
bool simpanData();
    
/**
 * @param judul
 * @param penulis
 * @param tahunTerbit
 * @param stok
 */
int tambahBuku(string judul, string penulis, int tahunTerbit, int stok);
    
/**
 * @param idBuku
 * @param judul
 * @param penulis
 * @param tahunTerbit
 * @param stok
 */
bool editBuku(int idBuku, string judul, string penulis, int tahunTerbit, int stok);
    
/**
 * @param idBuku
 */
bool hapusBuku(int idBuku);
    
/**
 * @param idBuku
 */
Buku cariBukuById(int idBuku);
    
void tampilkanDaftarBuku();
    
/**
 * @param keyword
 */
void cariBukuByJudul(string keyword);
    
/**
 * @param nama
 */
int tambahUser(string nama);
    
/**
 * @param idUser
 */
User cariUserById(int idUser);
    
void tampilkanDaftarUser();
    
/**
 * @param idUser
 * @param idBuku
 * @param tanggalPinjam
 */
bool pinjamBuku(int idUser, int idBuku, string tanggalPinjam);
    
/**
 * @param idUser
 * @param idBuku
 * @param tanggalKembali
 */
bool kembalikanBuku(int idUser, int idBuku, string tanggalKembali);
    
/**
 * @param idUser
 */
void tampilkanPinjamanUser(int idUser);
private: 
    vector<Buku> daftarBuku;
    vector<User> daftarUser;
    vector<TransaksiPeminjaman> daftarTransaksi;
    PenyimpananFile storage;
    int nextIdBuku;
    int nextIdUser;
    int nextIdTransaksi;
};

#endif //_SISTEMPEMINJAMAN_H