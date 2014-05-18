/*
 * user.h
 *
 *  Created on: Nov 12, 2013
 *      Author: timothyling
 */

#ifndef USER_H_
#define USER_H_

#include <iostream>
#include <string>
#include "wallpost.h"
#include "wall.h"
#include <fstream>
//#include "friendptr.h"

using namespace std;

class wall;

class user
{
	private:
	string username;
	string name;
	string password;
	string school; //pointer to his/her own wall

	public:
	user();
	~user();
	wall own;
	void set_username(string input);
	void set_password(string input);
	void set_school(string input);
	void set_name(string input);
	void otherposts(wallpost a);
	void delete_posts(wallpost a);

	void edit_info (string new_entry, int num_response);//allows you to edit user info
	void add_own_wall_post();
	void delete_own_wall_post();
	void see_info();
	void read_info();
	string getUsername();
	string getName();
	string getPassword();
	string getSchool();
	user* next;

};
#endif /* USER_H_ */
