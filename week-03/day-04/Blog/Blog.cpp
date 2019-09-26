#include "Blog.h"

Blog::Blog() {

}

void Blog::addBlogPost(BlogPost *blogPost) {
    _blogPosts.push_back(blogPost);
}

void Blog::deletePost(int x) {
    if(x >= 0 && x < _blogPosts.size()) {
        _blogPosts.erase(_blogPosts.begin() + x);
    }
}

void Blog::update(int x, BlogPost* newPost) {
    if(x >= 0 && x < _blogPosts.size()) {
        _blogPosts.erase(_blogPosts.begin() + x);
        _blogPosts.insert(_blogPosts.begin() + x, newPost);
    }
}
