#pragma once 

#include <iostream>
#include <string>
#include <sstream>

class Post {
protected:
	std::string _author;
	std::string _title;
	std::string _content;
public:
	Post () {}
	Post (std::string author, std::string title, std::string content) 
		: _author(author), _title(title), _content(content) {}
	std::string toString();
};