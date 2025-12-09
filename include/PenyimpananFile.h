/**
 * Project Program Akademik
 */


#ifndef _PENYIMPANANFILE_H
#define _PENYIMPANANFILE_H

class PenyimpananFile {
public: 
    
/**
 * @param pathInput
 * @param pathOutput
 */
void PenyimpananFile(string pathInput, string pathOutput);
    
/**
 * @param buku
 */
bool muatBuku(List<Buku> buku);
    
/**
 * @param buku
 */
bool simpanBuku(List<Buku> buku);
    
/**
 * @param user
 */
bool muatUser(List<User> user);
    
/**
 * @param user
 */
bool simpanUser(List<User> user);
    
/**
 * @param transaksi
 */
bool muatTransaksi(List<TransaksiPeminjaman> transaksi);
    
/**
 * @param transaksi
 */
bool simpanTransaksi(List<TransaksiPeminjaman> transaksi);
private: 
    string pathInput;
    string pathOutput;
};

#endif //_PENYIMPANANFILE_H