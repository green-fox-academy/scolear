#ifndef BLOG_BLOG_H
#define BLOG_BLOG_H

#include <vector>
#include "BlogPost.h"

class Blog {
public:
    Blog();

    void addBlogPost(BlogPost* blogPost);
    void deletePost(int);
    void update(int, BlogPost*);

private:
    std::vector<BlogPost*> _blogPosts;
};


#endif //BLOG_BLOG_H
