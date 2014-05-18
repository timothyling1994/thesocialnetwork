/*
 * userlist.cpp
 *
 *  Created on: Nov 12, 2013
 *      Author: timothyling
 */
#include "userlist.h"
#include <fstream>
#include <iostream>
#include <string>
#include "user.h"
#include <vector>
#include "wallpost.h"
#include "wallpostComment.h"
using namespace std;

userlist::userlist()
{
	tableSize = 11;
	hashtable = new user*[tableSize];
	for (int i = 0; i < tableSize; i++)
	{
		hashtable[i] = new user;
		hashtable[i]->set_name("");
		hashtable[i]->set_username("");
		hashtable[i]->set_password("");
		hashtable[i]->set_school("");
		hashtable[i]->next = NULL;
	}
	hashtableMusic = new user*[tableSize];
	for (int i = 0; i < tableSize; i++)
	{
		hashtableMusic[i] = new user;
		hashtable[i]->set_username("");
		hashtable[i]->next = NULL;
	}

}

userlist::userlist(int initialSize)
{
	tableSize = initialSize;
	hashtable = new user*[tableSize];
	for (int i = 0; i < tableSize; i++)
	{
		hashtable[i] = new user;
		hashtable[i]->set_name("");
		hashtable[i]->set_username("");
		hashtable[i]->set_password("");
		hashtable[i]->set_school("");
		hashtable[i]->next = NULL;
	}
	hashtableMusic = new user*[tableSize];
		for (int i = 0; i < tableSize; i++)
		{
			hashtableMusic[i] = new user;
			hashtable[i]->set_username("");
			hashtable[i]->next = NULL;
		}
}
userlist::~userlist()
{
}
int userlist::hashfunc(string name)
{
	int sum = 0;
	int length = name.length();
	for(int i = 0; i < length; i++)
	{
		sum = sum + (int)name[i];
	}
	int index = sum % tableSize;
	return index;
}
void userlist::add(user object)
{
	int index = hashfunc(object.getUsername());
		if(hashtable[index]->getUsername() == "" && hashtable[index]->getName() == "") //if the hashtable at that point is empty
		{
			hashtable[index]->set_username(object.getUsername());
			hashtable[index]->set_password(object.getPassword());
			hashtable[index]->set_name(object.getName());
			hashtable[index]->set_school(object.getSchool());

		}
		else
		{
			user* new_item = new user;
			user* origins = hashtable[index];
			new_item->set_username(object.getUsername());
			new_item->set_password(object.getPassword());
			new_item->set_name(object.getName());
			new_item->set_school(object.getSchool());
			new_item->next = NULL;

			while(origins->next != NULL) //stops when it reaches the end of the linked list
			{
				origins = origins->next;
			}
			origins->next = new_item;
		}
}

void userlist::searchbyuser(string username)
{
	int new_index = hashfunc(username);
	user* origins = hashtable[new_index];
	bool found = false;

	if(hashtable[new_index]->getUsername() == username) // first entry of the linked list
	{

		found = true;

		cout << hashtable[new_index]->getName() << endl;
		cout << username << endl;
		cout << hashtable[new_index]->getSchool() << endl;

	}
	else
	{
		while(origins->next != NULL)
		{
			origins = origins->next;
			if(origins->getUsername() == username)
			{
				//cout << origins->value;
				found = true;
				cout << username << endl;
				cout << origins->getName() << endl;
				cout << origins->getSchool() << endl;
			}

		}
		if(found == false)
		{
			cout << "Could not find the inputted name" << endl;
		}

		}
		//hashtable[index]
}
int userlist::numChains()
{
	int count = 0;
	for (int i = 0; i < tableSize; i++)
	{
		if (hashtable[i]->getUsername() != "")
		{
			count++;
		}
	}
	return count;
}

int userlist::numBucket()
{
	int count = 0;
	for(int i = 0; i < tableSize; i++)
	{
		if(hashtable[i]->getUsername() != "")
		{
			user* origins;
			origins = hashtable[i];
			while(origins->next != NULL)
			{
				count++;
				origins = origins->next;
			}

		}

	}
	return count;

}
void userlist::genre(string input, string username)
{
	int index = hashfunc(input);
		if(hashtableMusic[index]->getUsername() == "" && hashtableMusic[index]->getName() == "") //if the hashtable at that point is empty
		{
			hashtableMusic[index]->set_username(username);

		}
			else
			{
				user* new_item = new user;
				user* origins = hashtableMusic[index];
				new_item->set_username(username);
				new_item->next = NULL;

				while(origins->next != NULL) //stops when it reaches the end of the linked list
				{
					origins = origins->next;
				}
				origins->next = new_item;
			}
}
void userlist::loadmusic()
{
	ifstream myfile;
	string temp;
	string temp1;
	string users;
	myfile.open("music.txt");
	if(!myfile.is_open())
	{
		cout << "Could not open file" << endl;

	}
	while(!myfile.eof())
	{
		getline(myfile,temp);
		while((temp == "Rock") || (temp == "Rap") || (temp == "Pop") || (temp == "Alternative") || (temp == "Classical"))
		{
			getline(myfile,temp);
			while((temp != "Rock") || (temp != "Rap") || (temp != "Pop") || (temp != "Alternative") || (temp != "Classical"))
			{
				genre(temp,users);
				getline(myfile,temp);
			}

		}
	}
}
void userlist::printMusic(string genre)
{
	int index = hashfunc(genre);
	cout << "The following friends also enjoy this type of music: " << endl;
	user* origins = hashtableMusic[index];
	while(origins->next != NULL)
	{
		string temp = origins->getUsername();
		cout << temp << endl;
		origins = origins->next;
	}
}
void userlist::rehash()
{
	//bool resize = false;
	double load_factor;
	int num_chains;
	int table_items;
	num_chains = numChains();
	table_items = num_chains + numBucket();
	load_factor = table_items/num_chains;
	cout << "Number of Chains: " << num_chains << endl;
	cout << "Number of table items: " << table_items << endl;
	if(load_factor>1)
	{
		//cout << load_factor << endl;
		//resize();
	}

}
void userlist::resize()
{
	int oldtableSize = tableSize;
	tableSize = tableSize * 2;
	user** oldhashtable = hashtable;
	hashtable = new user*[tableSize];
	for (int i = 0; i < tableSize; i++) //initializing new hashtable
	{
		hashtable[i]->set_username("");
		hashtable[i]->set_name("");
		hashtable[i]->set_password("");
		hashtable[i]->set_school("");
		hashtable[i]->next = NULL;

	}
	for (int j = 0; j < oldtableSize; j++)
	{
		if(oldhashtable[j]->getUsername() != "")
		{
			user* oldNode;
			user* new_node = oldhashtable[j];
			while(new_node->getUsername() != "")
			{
				user object;
				string temp = new_node->getUsername();
				string temp1 = new_node->getName();
				string temp2 = new_node->getPassword();
				string temp3 = new_node->getSchool();
				object.set_username(temp);
				object.set_name(temp1);
				object.set_password(temp2);
				object.set_password(temp3);

				add(object);
				oldNode = new_node;
				new_node = new_node->next;
				delete oldNode;
			}

		}
	}
	cout << "Array has been resized" << endl;
	delete[] oldhashtable;
}
void userlist::printTest()
{
	for(int i = 0; i < tableSize; i++)
	{
		user* origins = hashtable[i];
		while(origins != NULL)
		{
			string temp = origins->getUsername();
			string temp1 = origins->getName();
			string temp2 = origins->getPassword();
			string temp3 = origins->getSchool();
			cout << temp1 << endl;
			cout << temp << endl;
			cout << temp2 << endl;
			cout << temp3 << endl;

			origins = origins->next;
		}

	}
}
int userlist::numinBucket(int index)
{
	int count = 1;

		if(hashtable[index]->getUsername() != "")
		{
			user* origins;
			origins = hashtable[index];
			while(origins->next != NULL)
			{
				count++;
				origins = origins->next;
			}

		}


	return count;

}
void userlist::remove(string username)
{
	int new_index = hashfunc(username);
	user* origins = hashtable[new_index];
	if((origins->getUsername() == ""))
	{
		cout << "The inputted name is not in the Hashtable" << endl;
	}
	else if ((origins->getUsername() == username) && (origins->next == NULL))
	{
		origins->set_username("");
		origins->set_password("");
		origins->set_school("");
		origins->set_name("");
		//origins->next == NULL;
	}
	else if((origins->getUsername() == username))
	{
		user* temp;
		temp = hashtable[new_index];
		hashtable[new_index] = hashtable[new_index]->next;
		delete temp;
	}
	else
	{
		user* previous;
		user* current;
		previous = hashtable[new_index];
		current = hashtable[new_index]->next;
		while(current != NULL && current->getUsername() != username)
		{
			previous = current;
			current = current->next;
		}

		if (current == NULL)
		{
			cout << "The inputted name is not within the hashtable" << endl;
		}
		else
		{
			user* deletePtr = current;
			current = current->next;
			previous->next = current;

			delete deletePtr;
		}

}

}

void userlist::search(string part)
{
	vector<string>possibilities;
	int choice;
	for(int i = 0; i < tableSize; i++)
		{
			if(hashtable[i]->getUsername() != "")
			{
				user* origins = hashtable[i];
				while(origins != NULL)
				{
				string temp = origins->getUsername();
				if(temp.find(part))
				{
					possibilities.push_back(temp);
				}
				origins = origins->next;
				}
			}
		}
	int length = possibilities.size();
	cout << "Do you mean?" << endl;
		for (int i = 0; i < length; i++)
		{
			cout << i << ". " << possibilities[i] << endl;
		}
		cout << "Who would you like to add? (Number)" << endl;
		cin >> choice;
		ofstream myfile;
		myfile.open("requests.txt");
		int length1 = possibilities.size();
		for(int i = 0; i < length1; i++)
		{
			myfile << possibilities[i] << endl;
		}

}

bool userlist::valid(string entered_user, string entered_password)
{
	bool validation = false;
	int length = tableSize;
	for (int i = 0; i < length; i++)
	{
		string temp = hashtable[i]->getUsername();
		string temp1 = hashtable[i]->getPassword();
		if ((temp == entered_user)&&(temp1 == entered_password))
		{
			validation = true;
		}
	}
	return validation;

}



void userlist::read_user()
{
	ofstream myfile;
	myfile.open("users.txt");
	int length = tableSize;
	for(int i = 0; i < length; i++)
		{
			string temp = hashtable[i]->getUsername();
			string temp1 = hashtable[i]->getPassword();
			string temp2 = hashtable[i]->getSchool();
			myfile << temp << endl;
			myfile << temp1 << endl;
			myfile << temp2 << endl;
		}
	myfile.close();
}

void userlist::get_users()
{
	ifstream myfile;
	myfile.open("users.txt");
	if(!myfile.is_open())
	{
		cout << "Cannot open the file" << endl;
	}
	while(!myfile.eof())
	{
		user person;
		string username;
		string name;
		string password;
		string school;
		getline(myfile,name);
		getline(myfile,username);
		getline(myfile,password);
		getline(myfile,school);
		person.set_name(name);
		person.set_username(username);
		person.set_password(password);
		person.set_school(school);
		add(person);

	}
}

void userlist::addposts(string user, wallpost a)
{
	int length = tableSize;
	for (int i = 0; i < length; i++)
	{
		string temp = hashtable[i]->getUsername();
		if (temp == user)
		{
			hashtable[i]->otherposts(a);
			cout << "Your post has been added" << endl;
		}
	}
}

void userlist::deleteposts(string user, wallpost a)
{
	int length = tableSize;
	for (int i = 0; i < length; i++)
	{
		string temp = hashtable[i]->getUsername();
		if(temp == user)
		{
			hashtable[i]->delete_posts(a);
		}
	}
}
void userlist::addwall()
{
	int length = tableSize;
	for (int i = 0; i < length; i++)
	{
		string temp = hashtable[i]->getUsername();
		ifstream myfile;
		string username;
		myfile.open("database1.txt");
		while(!myfile.eof())
		{
		getline(myfile,username);
		if (temp == username)
		{
			string current;
			string current1;
			string current2;
			getline(myfile, current);
			getline(myfile,current1);
			unsigned pos = current1.find(":");
			string new_current1;
			new_current1 = current1.substr(pos+1);
			getline(myfile,current2);
			wallpost b;
			b.setPost(current);
			b.setAuthor(new_current1);
			b.setDate(current2);
			hashtable[i]->otherposts(b);

		}
		}

	}
}

void userlist::finduser(string input)
{
	string new_comment;
	string poster;
	string time;
	string garbage;
	int index;
	cout << "All the wallposts and their respective comments" << endl;

	int length = tableSize;
		for (int i = 0; i < length; i++)
		{
			int response;
			string temp = hashtable[i]->getUsername();
			if (temp == input)
			{
				int size = hashtable[i]->own.posts.size();
				for(int j = 0; j<size;j++) //1
				{
					cout << j << "." << hashtable[i]->own.print() << endl;
					index = j;
					int size1 = hashtable[i]->own.posts[j].comments.size();
					for (int k = 0; k < size1; k++)
					{
						string temp1 = hashtable[i]->own.posts[j].comments[k].format();
						cout << temp1 << endl;
					}
				}
				cout << "Which wallpost would you like to comment on?(Choose number)" << endl;
				cin >> response;
				cout << "What would you like to comment. Enter username and time as well" << endl;
				getline(cin,garbage);
				getline(cin,new_comment);
				getline(cin,poster);
				getline(cin,time);
				wallpostComment a;
				a.setComment(new_comment);
				a.setPoster(poster);
				a.setTime(time);
				hashtable[i]->own.posts[index].addComment(a);
			}
		}
}
