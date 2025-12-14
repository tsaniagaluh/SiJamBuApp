#include "Controller.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
    cout << "=== SISTEM PEMINJAMAN BUKU ===" << endl;
    cout << "Memulai aplikasi..." << endl << endl;
    
    // Menentukan path file data yang benar
    string pathInput = "data/input.txt";
    string pathOutput = "data/output.txt";
    
    // Jika menjalankan dari direktori build, sesuaikan path
    ifstream testFile(pathInput);
    if (!testFile.is_open()) {
        // Coba dengan prefiks ../ (jika menjalankan dari build/)
        pathInput = "../data/input.txt";
        pathOutput = "../data/output.txt";
    }
    testFile.close();
    
    Controller app(pathInput, pathOutput);
    
    // Muat data dari file
    cout << "Memuat data dari file..." << endl;
    app.uiMuatData();
    cout << endl;
    
    // Mulai loop utama
    app.loopPerintah();
    
    return 0;
}
