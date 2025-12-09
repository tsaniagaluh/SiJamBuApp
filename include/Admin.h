/**
 * Project Program Akademik
 */


#ifndef _ADMIN_H
#define _ADMIN_H

#include "User.h"


class Admin: public Admin, public Admin, public User {
public: 
    
/**
 * @param id
 * @param nama
 */
void Admin(int id, string nama);
};

#endif //_ADMIN_H