#include "animal.h"
#include <iostream>

using namespace std;

void dog::eat() {
    cout << "Dogs eat bones" << endl;
}

#ifdef TALK
void dog::talk() {
    cout << "Bark..." << endl;
}
#endif

animal* lookup() {
    return new dog();
}
