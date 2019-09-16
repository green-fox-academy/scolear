/*

William A. Lathan 	405-709-1865
John K. Miller 	402-247-8568
Hortensia E. Foster 	606-481-6467
Amanda D. Newland 	319-243-5613
Brooke P. Askew 	307-687-2982

Create an application which solves the following problems.

    .What is John K. Miller's phone number?
    .Whose phone number is 307-687-2982?
    .Do we know Chris E. Myers' phone number?

*/

#include <iostream>
#include <map>

int main() {

    bool doWeKnow;

    std::map<std::string, std::string> phoneBook =
            {
                    {"William A. Lathan", "405-709-1865" },
                    {"John K. Miller", "402-247-8568" },
                    {"Hortensia E. Foster", "606-481-6467"},
                    {"Amanda D. Newland", "319-243-5613"},
                    {"Brooke P. Askew", "307-687-2982"}
            };

    // What is John K. Miller's phone number?
    std::cout << phoneBook["John K. Miller"] << std::endl;

    // Whose phone number is 307-687-2982?
    for (std::map<std::string, std::string >::iterator it = phoneBook.begin(); it != phoneBook.end(); it++) {
        if (it->second == "307-687-2982") {
            std::cout << it->first << std::endl;
        }
    }

    // Do we know Chris E. Myers' phone number?
    phoneBook.count("Chris E. Myers") ? std::cout << "Yes." : std::cout << "Nope." << std::endl;



    return 0;
}