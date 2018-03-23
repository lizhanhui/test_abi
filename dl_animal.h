#ifndef DL_ANIMAL_H
#define DL_ANIMAL_H

#include <dlfcn.h>

#include <string>

#include "animal.h"


typedef animal* (*Fn)();
void* handle = NULL;

void load_library() {
#ifdef __APPLE__
    std::string extension = ".dylib";
#endif

#ifdef __linux__
    std::string extension = ".so";
#endif

    std::string lib_name("libanimal");

    lib_name.append(extension);

    handle = dlopen(lib_name.c_str(), RTLD_LAZY);
}

animal* dl_lookup() {
    Fn f = (Fn)dlsym(handle, "lookup");
    animal* animal_ = f();
    return animal_;
}

void unload_library() {
    if (NULL != handle) {
        dlclose(handle);
    }
}

#endif // DL_ANIMAL_H
