/*
 * wall.h
 *
 *  Created on: Nov 12, 2013
 *      Author: timothyling
 */
#ifndef WALL_H_
#define WALL_H_

#include <iostream>
#include <string>
#include "wallpost.h"
//#include <iterator>
#include <vector>


class wall
{

public:
	wall();
	virtual ~wall();
	void add_wallpost(wallpost new_post);
	void delete_wallpost(wallpost new_post);
	void delete_own_wallpost1();
	string print();
	void read_all_wallposts();
	wallpost get (int pos) const;
	vector<wallpost>posts;

};



#endif /* WALL_H_ */
