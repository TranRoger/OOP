#include <iostream>
#include "Post.h"
#include "GraphPost.h"
#include "Comment.h"

using namespace std;

int main() {
	std::string author = "Jane";
	std::string title = "3 tips to learn English effectively";
	std::string content = (std::string)"To learn English effectively, you can try these 3 tips.\n" 
	    + (std::string)"1. Practice on a daily basis.\n"
	    + (std::string)"2. Take time to understand difficult paragraphs\n"
	    + (std::string)"3. Try new things everyday\n"
	    ;
	Post p(author, title, content);

    GraphPost gp(author, title, content, 5);
    Comment anna("Anna", "Great work.");
    Comment blash("Blash", "This helps me a lot!");
    Comment jack("Jack", "Thanks for your post.");
    gp.addComment(anna);
    gp.addComment(blash);
    gp.addComment(jack);

	std::cout << gp.toString();
}