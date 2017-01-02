//
// Created by patri on 2016/7/19.
//

#include <iostream>

using std::cout;
using std::endl;

int mian(int a) {
    std::string str1("New String1"); //Constructor
    std::string str2 = "String2";    //Assignment Construction

    cout << str1 + "&" + str2 << endl;  //"New String1&String2"

    cout << str1.substr(4, 6) << endl; //"String1"

    cout << "Length of str2: " << str2.length() << endl; //Get length

    cout << (str1 == str2) << endl;     //Overloaded "=="
    cout << (str1 == "Equal?") << endl; //Makes comparing easier

    char character = str1[1]; //Acess individual character

    const char *c_string = str1.c_str();
// Get a c_style string, you cannot modify it!!
}