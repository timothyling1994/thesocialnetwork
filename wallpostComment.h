/*
 * wallpostComment.h
 *
 *  Created on: Nov 14, 2013
 *      Author: timothyling
 */

#ifndef WALLPOSTCOMMENT_H_
#define WALLPOSTCOMMENT_H_
#include <vector>
#include <string>
using namespace std;

class wallpostComment
{
private:
	string comment;
	string poster;
	string time;

public:
	void setComment(string input);
	void setPoster(string input);
	void setTime(string input);
	string getComment()const;
	string getPoster()const;
	string getTime()const;
	string format();

};




#endif /* WALLPOSTCOMMENT_H_ */
