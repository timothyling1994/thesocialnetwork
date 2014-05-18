/*
 * wall.cpp
 *
 *  Created on: Nov 12, 2013
 *      Author: timothyling
 */
/*
 * wall.cpp
 *
 *  Created on: Oct 26, 2013
 *      Author: timothyling
 */

#include <iostream>
#include <string>
#include "wall.h"
#include "wallpost.h"
#include <fstream>
#include <vector>
using namespace std;

wall::wall()
{
	vector<wallpost>posts;
}

wall::~wall()
{
}

void wall::add_wallpost(wallpost object)
{
	posts.push_back(object);
	int length = posts.size();
	posts[length-1].getComments(object);
	//everything is stored correctly
	//read_all_wallposts();
}

void wall::delete_wallpost(wallpost new_post)
{
	int length = posts.size();
	string temp1 = new_post.getPost();
	string temp2 = new_post.getAuthor();
	string temp3 = new_post.getDate();

	for (int i = 0; i < length; i++)
	{
		string new_temp1 = posts[i].getPost();
		string new_temp2 = posts[i].getAuthor();
		string new_temp3 = posts[i].getDate();

		if ((temp1 == new_temp1) && (temp2 == new_temp2) && (temp3 == new_temp3))
		{
			posts.erase(posts.begin() + i);
			posts[i] = posts[i+1]; // get rid of last element

		}
	}
	posts.pop_back();
	read_all_wallposts();
}

string wall::print()
{
	string all;
	int length = posts.size();
	for (int i = 0; i < length; i++)
	{
		string temp1 = posts[i].getPost();
		string temp2 = posts[i].getAuthor();
		string temp3 = posts[i].getDate();
		all = temp1 + " by: " + temp2 + " on: " + temp3;
		return all;
	}
}

void wall::read_all_wallposts()
{
	ofstream myfile;
	myfile.open("database2.txt");
	string a;

	int length = posts.size();
	for(int i = 0; i < length; i++)
	{
		string temp = posts[i].getPost();
		string temp1 = posts[i].getAuthor();
		string temp2 = posts[i].getDate();
		myfile << temp << endl;
		myfile << temp1 << endl;
		myfile << temp2 << endl;
	}
}
wallpost wall::get (int pos) const
{
	return posts[pos];
}

void wall::delete_own_wallpost1()
{
	int length = posts.size();
	for (int i = 0; i < length; i++)
	{
		string temp;
		temp = posts[i].getAuthor();
		if (temp == "You")
		{
			posts.erase(posts.begin() + i);
			posts[i] = posts[i+1];
		}

	}
	posts.pop_back();
	//read_all_wallposts();
}













