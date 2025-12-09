/**
 * Project Program Akademik
 */


#ifndef _USER_H
#define _USER_H

class User: public User {
public: 
    
/**
 * @param id
 * @param name
 */
void User(int id, string name);
    
int getId();
    
string getNama();
    
/**
 * @param nama
 */
void setNama(string nama);
    
string toString();
private: 
    int id;
    string nama;
};

#endif //_USER_H