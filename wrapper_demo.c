// wrapper_demo.c (C code using the C++ library via the wrapper)
#include "sid_wrapper.h"
#include <stdio.h>

int main() {
    SID* sid = SID_create("MySID");
    if (!sid) {
        printf("Failed to create SID instance.\\n");
        return 1;
    }

    printf("SID instance name: %s\\n", SID_getName(sid));
    SID_playNote(sid, 42);
    SID_destroy(sid);

    return 0;
}

/*
Compilation steps (example):

# Compile C++ SID library
c++ -fPIC -c sid.cpp -o sid.o

# Compile wrapper
c++ -fPIC -c sid_wrapper.cpp -o sid_wrapper.o

# Create shared library
c++ -shared sid.o sid_wrapper.o -o libsid.so

# Compile C wrapper demo
gcc wrapper_demo.c -L. -lsid -o wrapper_demo -lstdc++

# Run demo
LD_LIBRARY_PATH=. ./wrapper_demo
*/

