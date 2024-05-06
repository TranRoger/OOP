#include "GraphPost.h"

std::string GraphPost::toString() {
    std::stringstream builder;
    builder << Post::toString() << std::endl;
    builder << "Likes: " << _likes << std::endl;
    builder << "Comments: " << _comments.size() << std::endl;
    for (auto c : _comments) {
        builder << "- " << c.toString();
    }
    return builder.str();
}