#include "Post.h"

std::string Post::toString() {
    std::stringstream builder;
    builder << "Author: " << _author << std::endl;
    builder << "Title: " << _title << std::endl;
    builder << "Content: " << std::endl << _content;
    return builder.str();
}