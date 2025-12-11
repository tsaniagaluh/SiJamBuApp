#include "Buku.h"
#include <string>

/**
 * Buku implementation
 */


/**
 * @param id
 * @param judul
 * @param penulis
 * @param tahun
 * @param stok
 */
Buku::Buku(int id, string judul, string penulis, int tahun, int stok) 
    : id(id), judul(judul), penulis(penulis), tahunTerbit(tahun), stok(stok) {
}

/**
 * @return int
 */
int Buku::getId() const {
    return id;
}

/**
 * @return string
 */
string Buku::getJudul() const {
    return judul;
}

/**
 * @return string
 */
string Buku::getPenulis() const {
    return penulis;
}

/**
 * @return int
 */
int Buku::getTahun() const {
    return tahunTerbit;
}

/**
 * @return int
 */
int Buku::getStok() const {
    return stok;
}

/**
 * @param judul
 * @return void
 */
void Buku::setJudul(string judul) {
    this->judul = judul;
}

/**
 * @param penulis
 * @return void
 */
void Buku::setPenulis(string penulis) {
    this->penulis = penulis;
}

/**
 * @param tahunTerbit
 * @return void
 */
void Buku::setTahunTerbit(int tahunTerbit) {
    this->tahunTerbit = tahunTerbit;
}

/**
 * @param stok
 * @return void
 */
void Buku::setStok(int stok) {
    this->stok = stok;
}

/**
 * @return bool
 */
bool Buku::tersedia() const {
    return stok > 0;
}

/**
 * @param qty
 * @return bool
 */
bool Buku::kurangiStok(int qty) {
    if (stok >= qty) {
        stok -= qty;
        return true;
    }
    return false;
}

/**
 * @param qty
 * @return void
 */
void Buku::tambahStok(int qty) {
    stok += qty;
}

/**
 * @return string
 */
string Buku::toString() const {
    return "ID: " + to_string(id) + " | Judul: " + judul + " | Penulis: " + penulis + 
           " | Tahun: " + to_string(tahunTerbit) + " | Stok: " + to_string(stok);
}