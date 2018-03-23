#ifndef DL_ANIMAL_H
#define DL_ANIMAL_H

#include <dlfcn.h>
#include "animal.h"

typedef animal* (*Fn)();
void* handle = NULL;

void load_library() {
    handle = dlopen("libanimal.dylib", RTLD_LAZY);
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
