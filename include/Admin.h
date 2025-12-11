#ifndef _ADMIN_H
#define _ADMIN_H

#include "User.h"
#include <string>
using namespace std;


class Admin: public User {
public: 
    
/**
 * @param id
 * @param nama
 */
Admin(int id, string nama);
};

#endif //_ADMIN_H