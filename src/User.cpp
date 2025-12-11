/**
 * Project Program Akademik
 */


#include "User.h"

/**
 * User implementation
 */


/**
 * @param id
 * @param name
 */
User::User(int id, string name) 
    : id(id), nama(name) {
}

/**
 * @return int
 */
int User::getId() const {
    return id;
}

/**
 * @return string
 */
string User::getNama() const {
    return nama;
}

/**
 * @param nama
 * @return void
 */
void User::setNama(string nama) {
    this->nama = nama;
}

/**
 * @return string
 */
string User::toString() const {
    return "ID: " + to_string(id) + " | Nama: " + nama;
}