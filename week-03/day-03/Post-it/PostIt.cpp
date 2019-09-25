#include "PostIt.h"
#include <utility>
#include <iostream>

PostIt::PostIt() {
    _backgroundColor = "0";
    _text = "0";
    _textColor = "0";
    _width = 0;
    _height = 0;
}

PostIt::PostIt(std::string backgroundColor, std::string text, std::string textColor) {
    _backgroundColor = backgroundColor;
    _text = text;
    _textColor = textColor;
    _width = 0;
    _height = 0;
}

PostIt::~PostIt() {
    std::cout << "i dont feel so good mr stark. \n";
}

int PostIt::area()
{
    return _width * _height;
}

void PostIt::setWidth(int width) {
    _width = width;
}

void PostIt::setHeight(int height) {
    _height = height;
}

void PostIt::setBackgroundColor(const std::string &backgroundColor) {
    _backgroundColor = backgroundColor;
}

void PostIt::setText(const std::string &text) {
    _text = text;
}

void PostIt::setTextColor(const std::string &textColor) {
    _textColor = textColor;
}

std::string PostIt::getText() {
    return _text;
}

std::string PostIt::getTextColor() {
    return _textColor;
}