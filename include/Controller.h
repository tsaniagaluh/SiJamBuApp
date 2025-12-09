/**
 * Project Program Akademik
 */


#ifndef _CONTROLLER_H
#define _CONTROLLER_H

class Controller {
public: 
    
/**
 * @param pathInput
 * @param pathOutput
 */
void Controller(string pathInput, string pathOutput);
    
void loopPerintah();
    
void menuAdmin();
    
void menuUser();
    
void uiTambahBuku();
    
void uiEditBuku();
    
void uiHapusBuku();
    
void uiTampilkanDaftarBuku();
    
void uiPinjamBuku();
    
void uiKembalikanBuku();
    
void uiTampilkanPinjamanUser();
    
void uiMuatData();
    
void uiSimpanData();
private: 
    SistemPeminjaman sistem;
};

#endif //_CONTROLLER_H