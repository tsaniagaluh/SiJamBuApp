/**
 * Project Program Akademik
 */


#ifndef _BUKU_H
#define _BUKU_H

class Buku {
public: 
    
/**
 * @param id
 * @param judul
 * @param penulis
 * @param tahun
 * @param stok
 */
void Buku(int id, string judul, string penulis, int tahun, int stok);
    
int getId();
    
string getJudul();
    
string getPenulis();
    
int getTahun();
    
int getStok();
    
/**
 * @param judul
 */
void setJudul(string judul);
    
/**
 * @param penulis
 */
void setPenulis(string penulis);
    
/**
 * @param tahunTerbit
 */
void setTahunTerbit(int tahunTerbit);
    
/**
 * @param stok
 */
void setStok(int stok);
    
bool tersedia();
    
/**
 * @param qty
 */
bool kurangiStok(int qty);
    
/**
 * @param qty
 */
void tambahStok(int qty);
    
string toString();
private: 
    int id;
    string judul;
    string penulis;
    int tahunTerbit;
    int stok;
};

#endif //_BUKU_H