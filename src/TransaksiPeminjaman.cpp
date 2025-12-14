#include "TransaksiPeminjaman.h"
#include <string>

/**
 * TransaksiPeminjaman implementation
 */


/**
 * @param id
 * @param idUser
 * @param idBuku
 * @param tanggalPinjam
 */
TransaksiPeminjaman::TransaksiPeminjaman(int id, int idUser, int idBuku, string tanggalPinjam)
    : id(id), idUser(idUser), idBuku(idBuku), tanggalPinjam(tanggalPinjam), 
      tanggalKembali(""), sudahDikembalikan(false) {
}

/**
 * @return int
 */
int TransaksiPeminjaman::getId() const {
    return id;
}

/**
 * @return int
 */
int TransaksiPeminjaman::getIdUser() const {
    return idUser;
}

/**
 * @return int
 */
int TransaksiPeminjaman::getIdBuku() const {
    return idBuku;
}

/**
 * @return string
 */
string TransaksiPeminjaman::getTanggalPinjam() const {
    return tanggalPinjam;
}

/**
 * @return string
 */
string TransaksiPeminjaman::getTanggalKembali() const {
    return tanggalKembali;
}

/**
 * @return bool
 */
bool TransaksiPeminjaman::getSudahDikembalikan() const {
    return sudahDikembalikan;
}

/**
 * @param tanggalKembali
 * @return void
 */
void TransaksiPeminjaman::tandaiDikembalikan(string tanggalKembali) {
    this->tanggalKembali = tanggalKembali;
    this->sudahDikembalikan = true;
}

/**
 * @return string
 */
string TransaksiPeminjaman::toString() const {
    return "ID Transaksi: " + to_string(id) + " | ID User: " + to_string(idUser) + 
           " | ID Buku: " + to_string(idBuku) + " | Tgl Pinjam: " + tanggalPinjam +
           " | Tgl Kembali: " + tanggalKembali + " | Status: " + 
           (sudahDikembalikan ? "Dikembalikan" : "Belum Dikembalikan");
}