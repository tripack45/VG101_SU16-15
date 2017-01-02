//
// Created by patri on 2016/7/18.
//

#include <iostream>
using namespace std;

class Obj{
    const char* name;
public:
    Obj(const char* str): name(str) {
        cout << name << " is constructed!" << endl;
    };
    ~Obj() {
        cout << name << " is destructed" << endl;
    }
};

int mian(int a) {
    cout << "Program begin" <<endl;
    Obj objLocal("Local object1");
    Obj objLocal2("Local object2");
    Obj* objPtr = new Obj("Dynamic 1");
    Obj* leakPtr = new Obj("ObjLeak");
    cout << "This one will leak" << endl;
    delete objPtr;
    cout << "Function ends here" << endl;
}

