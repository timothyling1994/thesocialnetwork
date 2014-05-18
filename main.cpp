/*
 * main.cpp
 *
 *  Created on: Nov 12, 2013
 *      Author: timothyling
 */
#include "wallpost.h"
#include "wall.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "user.h"
#include "userlist.h"
//#include "user.h"
//#include "friendptr.h"
using namespace std;

userlist thing;

void profile (string enter_username, string enter_password);
void addnewUser(string name, string username, string password, string school);
bool available(string new_username, bool &open);

void profile (string enter_username, string enter_password)
{

	thing.get_users();
	thing.addwall();
	bool leave = false;
	bool access = thing.valid(enter_username, enter_password);

	if (!access == false)
	{
		cout << "You have successfully logged in." << endl;
		while(!leave)
		{

		int response;
		cout << "What would you like to do?" << endl;
		cout << "Press" << endl;
		cout << "1.Post Own Wall Post" << endl;
		cout << "2.Delete Friend's Wall Post" << endl;
		cout << "3.Delete Own Wall post" << endl;
		cout << "4.To Edit Information" << endl;
		cout << "5.Send Friend Requests" << endl;
		cout << "6.View Friends" << endl;
		cout << "7.Delete Friends" << endl;
		cout << "8.Post on Friend's Wall" << endl;
		cout << "9.View Friend Requests" << endl;
		cout << "10.Delete Own Post On Friend's Wall" << endl;
		cout << "11.See Friend's Walls and Comment On Them" << endl;
		cout << "12.Print out all comments" << endl;
		cout << "13.Sort all the comments" << endl;
		cout << "14.See what genre of music your friends like!" << endl;
		cout << "15.To Exit" << endl;
		cin >> response;

	if (response == 1)
	{
	user object;
	//object.load_wall();
	object.add_own_wall_post();
	}
	else if (response == 2)
	{
	wallpost deletewp;
	string post;
	string garbage;
	string author;
	string date;
	cout << "What post would you like to delete?" << endl;
	cout << "Enter the post, author, and date all separated by an enter" << endl;
	getline(cin,garbage);
	getline(cin,post);
	getline(cin,author);
	getline(cin,date);
	deletewp.setPost(post);
	deletewp.setAuthor(author);
	deletewp.setDate(date);

	}
	else if (response == 3)
	{
		user object;
		object.delete_own_wall_post();
	}

	else if (response == 4)
	{
		user object;
		int response;
		string input;
		cout << "What would you like to edit?" << endl;
		cout << "1. Password" << endl;
		cout << "2. School" << endl;
		cin >> response;
		cout << "What is the new entry?" << endl;
		cin >> input;
		object.edit_info(input, response);

	}
	else if (response == 8)
	{
		string message;
		string garbage;
		string date;
		string user;
		cout << "What would you like to post?" << endl;
		cout << "What is the date" << endl;
		getline(cin, garbage);
		getline(cin, message);
		getline(cin, date);
		wallpost a;
		a.setPost(message);
		a.setAuthor(enter_username);
		a.setDate(date);
		cout<<"Enter the username whose wall you want to post on" << endl;
		cin >> user;
		thing.addposts(user, a);

	}
	else if (response == 10)
	{
		string post;
		string time;
		string user;
		cout << "Please input wallpost, time, and user" << endl;
		getline(cin,post);
		getline(cin,time);
		getline(cin,user);
		wallpost a;
		a.setAuthor(enter_username);
		a.setPost(post);
		a.setDate(time);
		thing.deleteposts(user,a);
	}
	else if (response == 11)
	{
		string garbage;
		string response;
		cout << "First, who's wall would you like to see (enter user)" << endl;
		getline(cin,garbage);
		getline(cin,response);
		thing.finduser(response);

	}
	else if (response == 12)
	{
		string garbage;
		string response;
		cout << "Whose's wall would you like to see?" << endl;
		getline(cin,garbage);
		getline(cin,response);
		thing.finduser(response);
	}
	else if (response == 13)
	{
		//int length = thing.user_list.size();
		//for (int i = 0; i < length; i++)
		//{
		//int length1 = thing.user_list[i].own.posts.size();
		//	for(int j = 0; j < length1; j++)
		//	{
		//		int size1 = user_list[i].own.posts[j].comments.size();
		//	}

		//}

	}
	else if (response == 14)
	{
		int answer;
		cout << "What genre of music do you like?" << endl;
		cout << "1. Rock" << endl;
		cout << "2. Rap" << endl;
		cout << "3. Alternative" << endl;
		cout << "4. Classical" << endl;
		cout << "5. Pop" << endl;
		cin >> answer;
		if (answer == 1)
		{
			//thing.loadmusic();
			thing.genre("Rock",enter_username);
			thing.printMusic("Rock");
		}
		else if (answer == 2)
		{
			//thing.loadmusic();
			thing.genre("Rap",enter_username);
			thing.printMusic("Rap");
		}
		else if(answer == 3)
		{
			//thing.loadmusic();
			thing.genre("Alternative",enter_username);
			thing.printMusic("Alternative");
		}
		else if(answer == 4)
		{
			//thing.loadmusic();
			thing.genre("Classical",enter_username);
			thing.printMusic("Classical");
		}
		else if  (answer == 5)
		{
			//thing.loadmusic();
			thing.genre("Pop",enter_username);
			thing.printMusic("Pop");
		}
		else
		{
			cout<< "That number is not available" << endl;
		}


	}
	else if (response == 15)
	{
		leave = true;
	}
	}
	}
	else
	{
		cout << "Wrong username/password combination" << endl;
	}

}

int main()
{

	int response;
	string enter_username;
	string enter_password;
	string new_username;
	string new_password;
	cout << "Welcome to Facebook 2.0 Social Network!" << endl;
	cout << "Would you like to?" << endl;
	cout << "1. Log in as a User" << endl;
	cout << "2. Create a new User" << endl;
	cout << "3. Quit" << endl;
	cin >> response;

	if (response == 1)
	{
		cout << "Please enter your username ex:(timothyling1994)" << endl;
		cin >> enter_username;
		cout << "Please enter your password ex:(the_hammer)" << endl;
		cin >> enter_password;
		cout << "Please wait. Signing in..." << endl;
		profile(enter_username, enter_password);

	}

	else if (response == 2)
	{
		bool open = true;
		string school;
		string new_name;
		cout << "Please enter your name" << endl;
		cin.ignore();
		getline(cin,new_name);
		while(open != false)
		{
		cout << "Please enter the username you would like to assume" << endl;
		//cin.ignore();
		getline(cin,new_username);
		available(new_username, open);

		}
		cout << "Please enter a password for " << new_username << endl;
		cin.ignore();
		getline(cin,new_password);
		cout << "Please enter your school" << endl;
		cin.ignore();
		getline(cin,school);
		cout << "The username and password has been entered into the database." << endl;
		addnewUser(new_name, new_username, new_password, school);
	}

	else if (response == 3)
	{
		return 0;
	}

	else
		cout << "Not a valid response." << endl;

	cout << "Exiting the Social Network!" << endl;
	return 0;

}

void addnewUser(string name, string username, string password, string school)
{

	user new_mem;
	new_mem.set_username(username);
	new_mem.set_password(password);
	new_mem.set_school(school);
	new_mem.set_name(name);
	//thing.get_users();
	//thing.add_user(new_mem);
	cout << "Your account has been made!" << endl;
	//thing.print();

}
bool available(string new_username, bool &open)
{
	bool temp = false;
	ifstream myfile;
	myfile.open("users.txt");
	if(!myfile.is_open())
	{
		cout << "Could not open the file" << endl;
	}
	while(!myfile.eof())
	{
		string username;
		string name;
		string password;
		string school;
		getline(myfile,name);
		getline(myfile,username);
		getline(myfile,password);
		getline(myfile,school);
		if(username == new_username)
		{
			cout << "Username is already taken!" << endl;
			temp = true;
		}
	}
	if(temp == true)
	{
		return open;
	}
	else
	{
		open = false;
	}

	return open;
}



