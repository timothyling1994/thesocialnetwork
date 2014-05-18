/*
 * wallpost.h
 *
 *  Created on: Nov 12, 2013
 *      Author: timothyling
 */

#ifndef WALLPOST_H_
#define WALLPOST_H_

#include <iostream>
#include <string>
#include "wallpostComment.h"
#include "wallpost.h"

using namespace std;
class wallpost
{
private:
		string post;
		string author;
		string date;
		//string onwall;
public:
		wallpost();
		~wallpost();
		void setPost(string thePost);//const string& thePost
		void setAuthor(string theAuthor);
		void setDate(string theDate);
		string getPost()const;
		string getAuthor()const;
		string getDate()const;
		string printAll();
		void addComment(wallpostComment a);
		void deleteComment(wallpostComment b);
		void printComments();
		void getComments(wallpost a);
		vector <wallpostComment> comments;

};

#endif /* WALLPOST_H_ */
