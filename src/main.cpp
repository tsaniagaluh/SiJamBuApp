/**
 * Sistem Peminjaman Buku
 */

#include "Controller.h"
#include <iostream>
using namespace std;

int main() {
    cout << "=== SISTEM PEMINJAMAN BUKU ===" << endl;
    cout << "Memulai aplikasi..." << endl << endl;
    
    // Initialize controller with input and output paths
    string pathInput = "data/input.txt";
    string pathOutput = "data/output.txt";
    
    Controller app(pathInput, pathOutput);
    
    // Load data from file
    cout << "Memuat data dari file..." << endl;
    app.uiMuatData();
    cout << endl;
    
    // Start main loop
    app.loopPerintah();
    
    return 0;
}
