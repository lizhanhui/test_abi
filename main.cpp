#include <iostream>
#include "dl_animal.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    load_library();
    animal* instance = dl_lookup();
    instance->eat();
    delete instance;
    unload_library();
    return 0;
}
