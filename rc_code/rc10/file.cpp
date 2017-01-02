//
// Created by patri on 2016/7/20.
//
#include <fstream>
#include <iostream>
using namespace std;

int writeNumberToFile(char* file, int* number, int size) {
    ofstream outFile(file);
    if (!outFile.is_open()) {
        cout << file << " can't open." << endl;
        outFile.close();
        return -1;
    }
    for (int i = 0; i < size; ++i) {
        outFile << "Number " << i << " number is " << number[i] << endl;
    }
    return 0;
}


int getNumberFromFile(char* file,
                      int* dest,
                      int size) {
    fstream inFile(file); // Opens the file
    if (!inFile.is_open()) { // Check file open
        cout << file << " not exist" << endl;
        inFile.close();
        return -1;
    }
    int i = 0;
    while (inFile.good()) {
        //if last read is successfull
        if (i == size) break;
        inFile >> dest[i];
        if (inFile.good()) i++;
    }
    inFile.close();
    return i;
}

int mian(int a) {
    int a[50] = {0};
    int count = getNumberFromFile("mat.txt", a, 50);
    for (int i = 0; i < count; ++i) {
        cout << "a[" << i << "] = " <<  a[i] << endl;
    }
    writeNumberToFile("out.txt", a, count);
}

