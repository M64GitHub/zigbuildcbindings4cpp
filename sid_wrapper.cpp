// sid_wrapper.cpp (C++ wrapper implementation) - NEW WRAPPER FILE
#include "sid_wrapper.h"
#include "sid.h"

extern "C" {
    SID* SID_create(const char* name) {
        return new SID(name);
    }

    void SID_destroy(SID* sid) {
        delete sid;
    }

    void SID_playNote(SID* sid, int note) {
        sid->playNote(note);
    }

    const char* SID_getName(SID* sid) {
        return sid->getName().c_str(); // NOTE: For demo purposes only.
    }
}
