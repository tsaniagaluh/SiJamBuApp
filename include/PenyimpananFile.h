#ifndef _PENYIMPANANFILE_H
#define _PENYIMPANANFILE_H

#include "Buku.h"
#include "User.h"
#include "TransaksiPeminjaman.h"
#include <vector>
#include <string>
using namespace std;

class PenyimpananFile {
public: 
    
/**
 * @param pathInput
 * @param pathOutput
 */
PenyimpananFile(string pathInput, string pathOutput);
    
/**
 * @param buku
 */
bool muatBuku(vector<Buku>& buku);
    
/**
 * @param buku
 */
bool simpanBuku(vector<Buku>& buku);
    
/**
 * @param user
 */
bool muatUser(vector<User>& user);
    
/**
 * @param user
 */
bool simpanUser(vector<User>& user);
    
/**
 * @param transaksi
 */
bool muatTransaksi(vector<TransaksiPeminjaman>& transaksi);
    
/**
 * @param transaksi
 */
bool simpanTransaksi(vector<TransaksiPeminjaman>& transaksi);
private: 
    string pathInput;
    string pathOutput;
};

#endif //_PENYIMPANANFILE_H