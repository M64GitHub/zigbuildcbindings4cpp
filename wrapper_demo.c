// wrapper_demo.c (C code using the C++ library)
#include "sid_c_wrapper.h"
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

