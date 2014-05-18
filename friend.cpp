/*
 * friend.cpp
 *
 *  Created on: Nov 14, 2013
 *      Author: timothyling
 */
/*
 * friendptr.cpp
 *
 *  Created on: Oct 30, 2013
 *      Author: timothyling
 */
#include "friend.h"
#include <iostream>
#include <fstream>
#include "user.h"

friend_::friend_()
{
	itemCount = 0;
	maxItems = 5;
	friend_ptr = new user[5];

}

friend_::~friend_()
{
	delete[]friend_ptr;
}

void friend_::add_user(user object)
{

	bool ableToInsert = (itemCount < maxItems);
		if (ableToInsert)
		{
			friend_ptr[itemCount] = object;
			itemCount++;
		}
		else
		{
			expandArray();
			user* temp = new user [maxItems];// makes a new array that can contain +1 element that previous one
			for (int i = 0; i < itemCount; i++) // copies all the elements from the first array
			{
				temp[i] = friend_ptr[i];
			}

			temp[maxItems-1] = object;
			delete []friend_ptr;
			itemCount++;
			friend_ptr = temp;

		}

}
void friend_::remove_user(user object)
{
	for (int i = 0; i < maxItems; i++)
		{
			string temp = friend_ptr[i].getUsername();
			if (object.getUsername() == temp)
			{
				for (int j = i; j < maxItems-1; j++)
					friend_ptr[j] = friend_ptr[j+1];
				maxItems--;
				itemCount--;
			}
		}
}

void friend_::print()
{
	//for (int i= 0 ; i < itemCount; i++)
	//{
	//	friend_[i].see_info();
	//}
}

void friend_::read_user()
{
	ofstream myfile;
	myfile.open("friends.txt");
	if(!myfile.is_open())
	{
		cout << "Cannot open the file" << endl;
	}

	else
	{
	for (int i = 0; i < itemCount; i++)
	{
		string temp_1 = friend_ptr[i].getUsername();
		myfile << temp_1 << endl;

	}
	}
}

void friend_::expandArray()
{
	maxItems++;
}

int friend_::getCurrentSize()
{
	return itemCount;
}

bool friend_::isEmpty()
{
	if(itemCount == 0)
	{
		return true;
	}
	else
		return false;
}







