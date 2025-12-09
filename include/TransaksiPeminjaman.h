/**
 * Project Program Akademik
 */


#ifndef _TRANSAKSIPEMINJAMAN_H
#define _TRANSAKSIPEMINJAMAN_H

class TransaksiPeminjaman {
public: 
    
/**
 * @param id
 * @param idUser
 * @param idBuku
 * @param tanggalPinjam
 */
void TransaksiPeminjaman(int id, int idUser, int idBuku, string tanggalPinjam);
    
int getId();
    
int getIdUser();
    
int getIdBuku();
    
string getTanggalPinjam();
    
string getTanggalKembali();
    
bool getSudahDikembalikan();
    
/**
 * @param tanggalKembali
 */
void tandaiDikembalikan(string tanggalKembali);
    
string toString();
private: 
    int id;
    int idUser;
    int idBuku;
    string tanggalPinjam;
    string tanggalKembali;
    bool sudahDikembalikan;
};

#endif //_TRANSAKSIPEMINJAMAN_H