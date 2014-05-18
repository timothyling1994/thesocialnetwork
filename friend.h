/*
 * friend.h
 *
 *  Created on: Nov 14, 2013
 *      Author: timothyling
 */

#ifndef FRIEND_H_
#define FRIEND_H_

#include "user.h"


class friend_
{
	private:
	int itemCount;
	int maxItems;
	user* friend_ptr;

	public:
	friend_();
	virtual ~friend_();
	void add_user(user new_object);
	void remove_user(user new_object);
	void print();
	void expandArray();
	void read_user();
	bool isEmpty();
	int getCurrentSize();


};


#endif /* FRIEND_H_ */
