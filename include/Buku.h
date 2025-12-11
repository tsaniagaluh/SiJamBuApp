#ifndef _BUKU_H
#define _BUKU_H

#include <string>
using namespace std;

class Buku {
public: 
    
/**
 * @param id
 * @param judul
 * @param penulis
 * @param tahun
 * @param stok
 */
Buku(int id, string judul, string penulis, int tahun, int stok);
    
int getId() const;
    
string getJudul() const;
    
string getPenulis() const;
    
int getTahun() const;
    
int getStok() const;
    
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
    
bool tersedia() const;
    
/**
 * @param qty
 */
bool kurangiStok(int qty);
    
/**
 * @param qty
 */
void tambahStok(int qty);
    
string toString() const;
private: 
    int id;
    string judul;
    string penulis;
    int tahunTerbit;
    int stok;
};

#endif //_BUKU_H