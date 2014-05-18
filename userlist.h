/*
 * userlist.h
 *
 *  Created on: Nov 12, 2013
 *      Author: timothyling
 */

#ifndef USERLIST_H_
#define USERLIST_H_
#include <iostream>
#include <vector>
#include "user.h"

using namespace std;


class userlist
{

	public:
		userlist(); //
		userlist(int initialSize); //
		~userlist(); //
		void add (user object);//
		void remove (string username);
		//string get (string name);
		int hashfunc(string name); //could be username or name
		int numBucket();
		void printTest();
		void turkeyBucket();
		int numinBucket(int index);
		void searchbyuser(string username);
		void searchbyname(string name);
		int numChains();
		void rehash();
		int tableSize;
		void resize();
		user** hashtable;
		user** hashtableMusic;
		void search(string part);
		void read_user();
		bool valid(string entered_user, string entered_password);
		void get_users();
		void addposts(string user, wallpost a);
		void finduser(string input);
		void addwall();
		void deleteposts(string user, wallpost a);
		void genre(string gen, string username);
		void loadmusic();
		void printMusic(string genre);



	/*private:
	vector <user> user_list;
	public:
	userlist();
	~userlist();
	void add_user(user object);
	void remove_user(user object);
	void print();
	void read_user();
	void search(string part);
	bool valid(string entered_user, string entered_password);
	void get_users();
	void addposts(string user, wallpost a);
	void deleteposts(string user, wallpost a);
	void finduser(string user);
	void addwall();*/

};



#endif /* USERLIST_H_ */
