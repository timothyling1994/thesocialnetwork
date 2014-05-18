
#include <iostream>
#include <string>
#include "wallpost.h"
#include <fstream>


wallpost::wallpost()
{
	 post = "";
	 author = "";
	 date = "";
	 vector <wallpostComment> comments;
	// onwall = "";
}

wallpost::~wallpost()
{}

void wallpost::setPost(string thePost)
{
	post = thePost;
}

void wallpost::setAuthor(string theAuthor)
{
	author = theAuthor;
}

void wallpost::setDate(string theDate)
{
	date = theDate;
}

//void wallpost::setWhoseWall(string user)
//{
//	onwall = user;
//}

string wallpost::getPost()const
{
	return post;
}

string wallpost::getAuthor()const
{
	return author;
}

string wallpost::getDate()const
{
	return date;
}
//string wallpost::getWhoseWall()const
//{
//	return onwall;
//}

string wallpost::printAll()
{
	string all;
	all = post + " posted by:" + author + "on " + date;
	return all;

}

void wallpost::addComment(wallpostComment a)
{
	comments.push_back(a);
}

void wallpost::deleteComment(wallpostComment a)
{
	int length = comments.size();
	string temp1 = a.getComment();
	string temp2 = a.getPoster();
	string temp3 = a.getTime();

		for (int i = 0; i < length; i++)
		{
			string new_temp1 = comments[i].getComment();
			string new_temp2 = comments[i].getPoster();
			string new_temp3 = comments[i].getTime();

			if ((temp1 == new_temp1) && (temp2 == new_temp2) && (temp3 == new_temp3))
			{
				comments.erase(comments.begin() + i);
				comments[i] = comments[i+1]; // get rid of last element

			}
		}
		comments.pop_back();
}

void wallpost::printComments()
{
	int length = comments.size();
	for (int i = 0; i < length; i++)
	{
		comments[i].format();
	}
}

void wallpost::getComments(wallpost a)
{
	ifstream myfile;
	string comp;
	string comp1;
	string comp2;
	string comp3;
	string comment;
	string poster;
	string date;
	myfile.open("database1.txt");
	if(!myfile.is_open())
	{
		cout << "Cannot open file" << endl;
	}
	string temp = a.getPost();
	string temp1 = a.getAuthor();
	string temp2 = a.getDate();

	while(!myfile.eof())
	{
		getline(myfile,comp);
		if (comp == temp)
		{
			getline(myfile,comp1);
			unsigned pos = comp1.find(":");
			string new_current1;
			new_current1 = comp1.substr(pos+1);
			if(temp1 == new_current1)
			{
			//never reaches
				getline(myfile,comp2);
				if(temp2 == comp2)
				{
					cout << temp2 << endl;
					cout << comp2 << endl;
					getline(myfile,comp3);
					while(comp3 != "COMMENTS END")
					{
						wallpostComment ob;
						getline(myfile,comp3);
						cout << comp3 << endl;
						ob.setComment(comp3);
						getline(myfile,comp3);
						cout << comp3 << endl;;
						ob.setPoster(comp3);
						getline(myfile,comp3);
						cout << comp3 << endl;
						ob.setTime(comp3);
						getline(myfile,comp3);
						addComment(ob);

					}
				}
			}
		}

	}
}




