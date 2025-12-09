/**
 * Project Program Akademik
 */


#include "SistemPeminjaman.h"

/**
 * SistemPeminjaman implementation
 */


/**
 * @param pathInput
 * @param pathOutput
 */
void SistemPeminjaman::SistemPeminjaman(string pathInput, string pathOutput) {

}

/**
 * @return bool
 */
bool SistemPeminjaman::muatData() {
    return false;
}

/**
 * @return bool
 */
bool SistemPeminjaman::simpanData() {
    return false;
}

/**
 * @param judul
 * @param penulis
 * @param tahunTerbit
 * @param stok
 * @return int
 */
int SistemPeminjaman::tambahBuku(string judul, string penulis, int tahunTerbit, int stok) {
    return 0;
}

/**
 * @param idBuku
 * @param judul
 * @param penulis
 * @param tahunTerbit
 * @param stok
 * @return bool
 */
bool SistemPeminjaman::editBuku(int idBuku, string judul, string penulis, int tahunTerbit, int stok) {
    return false;
}

/**
 * @param idBuku
 * @return bool
 */
bool SistemPeminjaman::hapusBuku(int idBuku) {
    return false;
}

/**
 * @param idBuku
 * @return Buku
 */
Buku SistemPeminjaman::cariBukuById(int idBuku) {
    return null;
}

/**
 * @return void
 */
void SistemPeminjaman::tampilkanDaftarBuku() {
    return;
}

/**
 * @param keyword
 * @return void
 */
void SistemPeminjaman::cariBukuByJudul(string keyword) {
    return;
}

/**
 * @param nama
 * @return int
 */
int SistemPeminjaman::tambahUser(string nama) {
    return 0;
}

/**
 * @param idUser
 * @return User
 */
User SistemPeminjaman::cariUserById(int idUser) {
    return null;
}

/**
 * @return void
 */
void SistemPeminjaman::tampilkanDaftarUser() {
    return;
}

/**
 * @param idUser
 * @param idBuku
 * @param tanggalPinjam
 * @return bool
 */
bool SistemPeminjaman::pinjamBuku(int idUser, int idBuku, string tanggalPinjam) {
    return false;
}

/**
 * @param idUser
 * @param idBuku
 * @param tanggalKembali
 * @return bool
 */
bool SistemPeminjaman::kembalikanBuku(int idUser, int idBuku, string tanggalKembali) {
    return false;
}

/**
 * @param idUser
 * @return void
 */
void SistemPeminjaman::tampilkanPinjamanUser(int idUser) {
    return;
}