#include "SistemPeminjaman.h"
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * SistemPeminjaman implementation
 */


/**
 * @param pathInput
 * @param pathOutput
 */
SistemPeminjaman::SistemPeminjaman(string pathInput, string pathOutput)
    : storage(pathInput, pathOutput), nextIdBuku(1), nextIdUser(1), nextIdTransaksi(1) {
}

/**
 * @return bool
 */
bool SistemPeminjaman::muatData() {
    bool success = storage.muatBuku(daftarBuku) && storage.muatUser(daftarUser) && 
                   storage.muatTransaksi(daftarTransaksi);
    
    if (success) {
        // Update nextIdBuku menjadi max ID + 1
        if (!daftarBuku.empty()) {
            int maxBukuId = 0;
            for (const auto& buku : daftarBuku) {
                if (buku.getId() > maxBukuId) {
                    maxBukuId = buku.getId();
                }
            }
            nextIdBuku = maxBukuId + 1;
        }
        
        // Update nextIdUser menjadi max ID + 1
        if (!daftarUser.empty()) {
            int maxUserId = 0;
            for (const auto& user : daftarUser) {
                if (user.getId() > maxUserId) {
                    maxUserId = user.getId();
                }
            }
            nextIdUser = maxUserId + 1;
        }
        
        // Update nextIdTransaksi menjadi max ID + 1
        if (!daftarTransaksi.empty()) {
            int maxTransaksiId = 0;
            for (const auto& transaksi : daftarTransaksi) {
                if (transaksi.getId() > maxTransaksiId) {
                    maxTransaksiId = transaksi.getId();
                }
            }
            nextIdTransaksi = maxTransaksiId + 1;
        }
    }
    
    return success;
}

/**
 * @return bool
 */
bool SistemPeminjaman::simpanData() {
    return storage.simpanBuku(daftarBuku) && storage.simpanUser(daftarUser) && 
           storage.simpanTransaksi(daftarTransaksi);
}

/**
 * @param judul
 * @param penulis
 * @param tahunTerbit
 * @param stok
 * @return int
 */
int SistemPeminjaman::tambahBuku(string judul, string penulis, int tahunTerbit, int stok) {
    Buku bukuBaru(nextIdBuku, judul, penulis, tahunTerbit, stok);
    daftarBuku.push_back(bukuBaru);
    return nextIdBuku++;
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
    for (auto& buku : daftarBuku) {
        if (buku.getId() == idBuku) {
            buku.setJudul(judul);
            buku.setPenulis(penulis);
            buku.setTahunTerbit(tahunTerbit);
            buku.setStok(stok);
            return true;
        }
    }
    return false;
}

/**
 * @param idBuku
 * @param judul
 * @return bool
 */
bool SistemPeminjaman::editBukuJudul(int idBuku, string judul) {
    for (auto& buku : daftarBuku) {
        if (buku.getId() == idBuku) {
            buku.setJudul(judul);
            return true;
        }
    }
    return false;
}

/**
 * @param idBuku
 * @param penulis
 * @return bool
 */
bool SistemPeminjaman::editBukuPenulis(int idBuku, string penulis) {
    for (auto& buku : daftarBuku) {
        if (buku.getId() == idBuku) {
            buku.setPenulis(penulis);
            return true;
        }
    }
    return false;
}

/**
 * @param idBuku
 * @param tahunTerbit
 * @return bool
 */
bool SistemPeminjaman::editBukuTahun(int idBuku, int tahunTerbit) {
    for (auto& buku : daftarBuku) {
        if (buku.getId() == idBuku) {
            buku.setTahunTerbit(tahunTerbit);
            return true;
        }
    }
    return false;
}

/**
 * @param idBuku
 * @param stok
 * @return bool
 */
bool SistemPeminjaman::editBukuStok(int idBuku, int stok) {
    for (auto& buku : daftarBuku) {
        if (buku.getId() == idBuku) {
            buku.setStok(stok);
            return true;
        }
    }
    return false;
}

/**
 * @param idBuku
 * @return bool
 */
bool SistemPeminjaman::hapusBuku(int idBuku) {
    auto it = find_if(daftarBuku.begin(), daftarBuku.end(),
                     [idBuku](const Buku& b) { return b.getId() == idBuku; });
    if (it != daftarBuku.end()) {
        daftarBuku.erase(it);
        return true;
    }
    return false;
}

/**
 * @param idBuku
 * @return Buku
 */
Buku SistemPeminjaman::cariBukuById(int idBuku) {
    for (auto& buku : daftarBuku) {
        if (buku.getId() == idBuku) {
            return buku;
        }
    }
    // Return dummy book jika tidak ditemukan (ID -1 menunjukkan tidak ditemukan)
    return Buku(-1, "", "", 0, 0);
}

/**
 * @return void
 */
void SistemPeminjaman::tampilkanDaftarBuku() {
    if (daftarBuku.empty()) {
        cout << "Belum ada data buku." << endl;
        return;
    }
    cout << "\n=== DAFTAR BUKU ===" << endl;
    for (const auto& buku : daftarBuku) {
        cout << buku.toString() << endl;
    }
}

/**
 * @param keyword
 * @return void
 */
void SistemPeminjaman::cariBukuByJudul(string keyword) {
    cout << "\n=== HASIL PENCARIAN ===" << endl;
    bool found = false;
    for (const auto& buku : daftarBuku) {
        if (buku.getJudul().find(keyword) != string::npos) {
            cout << buku.toString() << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Tidak ada buku dengan judul mengandung '" << keyword << "'." << endl;
    }
}

/**
 * @param nama
 * @return int
 */
int SistemPeminjaman::tambahUser(string nama) {
    User userBaru(nextIdUser, nama);
    daftarUser.push_back(userBaru);
    return nextIdUser++;
}

/**
 * @param idUser
 * @return User
 */
User SistemPeminjaman::cariUserById(int idUser) {
    for (auto& user : daftarUser) {
        if (user.getId() == idUser) {
            return user;
        }
    }
    // Return dummy user jika tidak ditemukan (ID -1 menunjukkan tidak ditemukan)
    return User(-1, "");
}

/**
 * @return void
 */
void SistemPeminjaman::tampilkanDaftarUser() {
    if (daftarUser.empty()) {
        cout << "Belum ada data user." << endl;
        return;
    }
    cout << "\n=== DAFTAR USER ===" << endl;
    for (const auto& user : daftarUser) {
        cout << user.toString() << endl;
    }
}

/**
 * @param idUser
 * @param idBuku
 * @param tanggalPinjam
 * @return bool
 */
bool SistemPeminjaman::pinjamBuku(int idUser, int idBuku, string tanggalPinjam) {
    // Cek user ada
    if (cariUserById(idUser).getId() == -1) {
        cout << "User dengan ID " << idUser << " tidak ditemukan." << endl;
        return false;
    }
    
    // Cari buku
    for (auto& buku : daftarBuku) {
        if (buku.getId() == idBuku) {
            if (!buku.tersedia()) {
                cout << "Buku tidak tersedia (stok habis)." << endl;
                return false;
            }
            // Kurangi stok
            if (buku.kurangiStok(1)) {
                // Buat transaksi
                TransaksiPeminjaman transaksi(nextIdTransaksi, idUser, idBuku, tanggalPinjam);
                daftarTransaksi.push_back(transaksi);
                nextIdTransaksi++;
                cout << "Peminjaman berhasil. Transaksi ID: " << (nextIdTransaksi - 1) << endl;
                return true;
            }
        }
    }
    cout << "Buku dengan ID " << idBuku << " tidak ditemukan." << endl;
    return false;
}

/**
 * @param idUser
 * @param idBuku
 * @param tanggalKembali
 * @return bool
 */
bool SistemPeminjaman::kembalikanBuku(int idUser, int idBuku, string tanggalKembali) {
    // Cari transaksi yang belum dikembalikan
    for (auto& transaksi : daftarTransaksi) {
        if (transaksi.getIdUser() == idUser && transaksi.getIdBuku() == idBuku && 
            !transaksi.getSudahDikembalikan()) {
            // Tandai dikembalikan
            transaksi.tandaiDikembalikan(tanggalKembali);
            
            // Tambah stok buku
            for (auto& buku : daftarBuku) {
                if (buku.getId() == idBuku) {
                    buku.tambahStok(1);
                    cout << "Pengembalian berhasil." << endl;
                    return true;
                }
            }
        }
    }
    cout << "Transaksi peminjaman tidak ditemukan." << endl;
    return false;
}

/**
 * @param idUser
 * @return void
 */
void SistemPeminjaman::tampilkanPinjamanUser(int idUser) {
    cout << "\n=== DAFTAR PEMINJAMAN USER ID " << idUser << " ===" << endl;
    bool found = false;
    for (const auto& transaksi : daftarTransaksi) {
        if (transaksi.getIdUser() == idUser) {
            cout << transaksi.toString() << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Tidak ada riwayat peminjaman untuk user ini." << endl;
    }
}

/**
 * Display seluruh transaksi
 */
void SistemPeminjaman::tampilkanDaftarTransaksi() {
    if (daftarTransaksi.empty()) {
        cout << "Belum ada data transaksi peminjaman." << endl;
        return;
    }
    cout << "\n=== DAFTAR TRANSAKSI PEMINJAMAN ===" << endl;
    for (const auto& transaksi : daftarTransaksi) {
        cout << transaksi.toString() << endl;
    }
}