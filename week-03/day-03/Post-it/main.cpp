#include <iostream>
#include "PostIt.h"

/*
Create a PostIt class that has
a backgroundColor
a text on it
a textColor
Create a few example post-it objects:
an orange with blue text: "Idea 1"
a pink with black text: "Awesome"
a yellow with green text: "Superb!"
*/

int main() {

    // Initializing with setters:
    PostIt post2;
    post2.setBackgroundColor("yellow");
    post2.setTextColor("green");
    post2.setText("Superb!");

    // initializing with constructor:
    PostIt post3("pink", "Awesome", "black");

    std::cout << post3.getText();

    /*
    // bad practice to access class member variables directly:
    PostIt post1;
    post1.backgroundColor = "orange";
    post1.textColor = "blue";
    post1.text = "Idea 1";
*/
    return 0;
}