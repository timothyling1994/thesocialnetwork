/*
 * wallpostComment.cpp
 *
 *  Created on: Nov 14, 2013
 *      Author: timothyling
 */
#include <iostream>
#include <vector>
#include "wallpostComment.h"
using namespace std;

void wallpostComment::setComment(string input)
{
	comment = input;
}

void wallpostComment::setPoster(string input)
{
	poster = input;
}

void wallpostComment::setTime(string input)
{
	time = input;
}

string wallpostComment::getComment()const
{
	return comment;
}
string wallpostComment::getPoster()const
{
	return poster;
}
string wallpostComment::getTime()const
{
	return time;
}
string wallpostComment::format()
{
	string all;
	all = comment + " by: " + poster + " on: " + time;
	return all;
}
