#ifndef _TRANSAKSIPEMINJAMAN_H
#define _TRANSAKSIPEMINJAMAN_H

#include <string>
using namespace std;

class TransaksiPeminjaman {
public: 
    
/**
 * @param id
 * @param idUser
 * @param idBuku
 * @param tanggalPinjam
 */
TransaksiPeminjaman(int id, int idUser, int idBuku, string tanggalPinjam);
    
int getId() const;
    
int getIdUser() const;
    
int getIdBuku() const;
    
string getTanggalPinjam() const;
    
string getTanggalKembali() const;
    
bool getSudahDikembalikan() const;
    
/**
 * @param tanggalKembali
 */
void tandaiDikembalikan(string tanggalKembali);
    
string toString() const;
private: 
    int id;
    int idUser;
    int idBuku;
    string tanggalPinjam;
    string tanggalKembali;
    bool sudahDikembalikan;
};

#endif //_TRANSAKSIPEMINJAMAN_H