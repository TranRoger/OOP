#pragma once

#include <iostream>
#include <string>

class Comment {
private:
    std::string _commentor;
    std::string _content;
public:
    Comment() : _commentor(""), _content("") {}
    Comment(std::string name, std::string comment) : 
        _commentor(name), _content(comment) {}

    std::string commentor() { return _commentor; }
    std::string content() {return _content; }
    std::string toString() {
        return _commentor + ": " + _content + "\n";
    }
};