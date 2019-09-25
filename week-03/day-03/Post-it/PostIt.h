#ifndef POST_IT_POSTIT_H
#define POST_IT_POSTIT_H

#include <string>

class PostIt {

public:
    PostIt();
    PostIt(std::string, std::string, std::string);
    ~PostIt();

    void setWidth(int width);

    void setHeight(int height);

    void setBackgroundColor(const std::string &backgroundColor);

    void setText(const std::string &text);

    void setTextColor(const std::string &textColor);

    std::string getText();

    std::string getTextColor();

    int area();

private:
    std::string _backgroundColor;
    std::string _text;
    std::string _textColor;
    int _width;
    int _height;

};

#endif //POST_IT_POSTIT_H
