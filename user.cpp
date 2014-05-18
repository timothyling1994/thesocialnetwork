/*
 * user.cpp
 *
 *  Created on: Nov 12, 2013
 *      Author: timothyling
 */
#include <iostream>
#include <string>
#include "wallpost.h"
#include "user.h"
#include "wall.h"
#include <fstream>
#include <cstdio>
#include <string>
using namespace std;

user::user()
{
	username = "";
	name = "";
	password = "";
	school = "";
	next = NULL;

}

user::~user()
{}

void user::set_username(string input)
{
	username = input;
}

void user::set_password(string input)
{
	password = input;
}

void user::set_school(string input)
{
	school = input;
}
void user::set_name(string input)
{
	name = input;
}
void user::edit_info (string new_entry, int num_response)
{
		if (num_response == 1)
		{
			password = new_entry;
			cout << "Info Edited" << endl;
		}
		else if (num_response == 2)
		{

			school = new_entry;
			cout << "Info Edited" << endl;
		}
		else
			cout << "No edits made" << endl;

}
void user::otherposts(wallpost a)
{
	own.add_wallpost(a);
}
void user::add_own_wall_post()
{
	wallpost temp;
	string post;
	string date;
	string garbage;
	cout << "Please enter your own wallpost" << endl;
	getline(cin,garbage);
	getline(cin,post);
	cout << "Enter the date" << endl;
	getline(cin,date);
	temp.setPost(post);
	temp.setAuthor("You");
	temp.setDate(date);
	own.add_wallpost(temp);
	own.print();

}
void user::delete_posts(wallpost b)
{
	own.delete_wallpost(b);
}

void user::delete_own_wall_post()
{
	own.delete_own_wallpost1();
}
void user::see_info()
{
	cout << "*************************************************************" << endl;
	cout << "Username: " << username << endl;
	cout << "Password: " << password << endl;
	cout << "School: " << school << endl;
	cout << "*************************************************************" << endl;
}

void user::read_info()
{
	ofstream myfile;
	myfile.open("user.txt");
	if(!myfile.is_open())
	{
		cout << "Cannot open the file" << endl;
	}
	else
	{
		myfile << username << endl;
		myfile << password << endl;
		myfile << school << endl;
	}
}

string user::getUsername()
{
	return username;
}

string user::getPassword()
{
	return password;
}

string user::getSchool()
{
	return school;
}
string user::getName()
{
	return name;
}
