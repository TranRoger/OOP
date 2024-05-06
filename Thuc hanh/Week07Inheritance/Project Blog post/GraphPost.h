#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include "Post.h"
#include "Comment.h"

class GraphPost : private Post {
private:
    int _likes;
    std::vector<Comment> _comments;
public:
    GraphPost() : _likes(0) {}
    GraphPost(std::string author, std::string title, std::string content, int likes) :
        Post(author, title, content), _likes(likes) {}

    int likes() { return _likes; }
    std::string toString();
    void addComment(Comment c) { _comments.push_back(c); }
};