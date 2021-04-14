#include "Comment.h"
#include <iostream>
#include <iomanip>
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
#define RESTORE "\033[1;0m"
#define amarillo "\033[1;43m"
#define morado "\033[1;45m"
#define cyan "\033[1;46m"
#define verde "\033[1;42m"


using namespace std;


Comment::Comment(){

cout << DEBUG << "debug: gettin in default constructor of the class comment" << RESTORE << endl;

	this->comment_id = 0;
	this->writer = "NULL";
	this->comment_text = "NULL";
}

Comment::Comment(unsigned int new_comment_id, string new_writer, string new_comment_text){

//cout << DEBUG << "debug: gettin in the constructor by parameters of the class Comment" << RESTORE << endl;

	this->comment_id = new_comment_id;
	this->writer = new_writer;
	this->comment_text = new_comment_text;
}

Comment::~Comment(){

//cout << DEBUG << "debug: gettin in the default destrcutor of the class Comment" << RESTORE << endl;

	this->comment_id = 0;
	this->writer = "NULL";
	this->comment_text = "NULL";
}

void Comment::setCommentID(unsigned int new_comment_id){

//cout << DEBUG << "debug: gettin in setCommentID" << RESTORE << endl;

	this->comment_id = new_comment_id;
}

void Comment::setWriter(string new_writer){

//cout << DEBUG << "debug: gettin in setWriter" << RESTORE << endl;

	this->writer = new_writer;
}

void Comment::setComment_text(string new_text){

//cout << DEBUG << "debug: gettin in setComment_text" << RESTORE << endl;

	this->comment_text = new_text;
//cout << DEBUG << "debug: getting out setComment_text" << RESTORE << endl;
}

unsigned int Comment::getCommentID(){

//cout << DEBUG << "debug: gettin in getCommentID" << RESTORE << endl;

	return this->comment_id;
//cout << DEBUG << "debug: getting out getCommentID" << RESTORE << endl;
}

string Comment::getWriter(){

//cout << DEBUG << "debug: gettin in getWriter" << RESTORE << endl;

	return this->writer;
}

string Comment::getComment_text(){

//cout << DEBUG << "debug: gettin in getComment_text" << RESTORE << endl;

	return this->comment_text;
} 

ostream& operator<<(ostream &flux, Comment comment_to_print){

	flux << "ID of the comment: " << comment_to_print.getCommentID() << endl;
	flux << "User: " << comment_to_print.getWriter() << endl;
	flux << "Comment: " << comment_to_print.getComment_text();
	cout << endl;
}

void Comment::operator=(Comment comment_info){

	this->comment_id = comment_info.comment_id;
	this->writer = comment_info.writer;
	this->comment_text = comment_info.comment_text;
}

