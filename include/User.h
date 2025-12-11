#ifndef _USER_H
#define _USER_H

#include <string>
using namespace std;

class User {
public: 
    
/**
 * @param id
 * @param name
 */
User(int id, string name);
    
int getId() const;
    
string getNama() const;
    
/**
 * @param nama
 */
void setNama(string nama);
    
string toString() const;
private: 
    int id;
    string nama;
};

#endif //_USER_H