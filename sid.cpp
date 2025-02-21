// sid.cpp (C++ implementation)
#include "sid.h"
#include "sid_c_wrapper.h"
#include <iostream>

SID::SID(const std::string &name) : name(name) {
    std::cout << "SID instance '" << name << "' created.\\n";
}

SID::~SID() {
    std::cout << "SID instance '" << name << "' destroyed.\\n";
}

void SID::playNote(int note) {
    std::cout << "Playing note " << note << " on SID '" << name << "'.\\n";
}

std::string SID::getName() const {
    return name;
}

// C interface implementations
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
        // WARNING: Returning a pointer to temporary memory. For demo purposes only.
        return sid->getName().c_str();
    }
}

