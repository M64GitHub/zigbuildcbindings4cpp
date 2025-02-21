// sid.cpp (C++ implementation) - AS AN EXAMPLE FOR A C++ LIB ORIGINAL FILE (UNTOUCHED)
#include "sid.h"
#include <iostream>

SID::SID(const std::string &name) : my_name(name) {
    std::cout << "SID instance '" << my_name << "' created.\n";
}

SID::~SID() {
    std::cout << "SID instance '" << my_name << "' destroyed.\n";
}

void SID::playNote(int note) {
    std::cout << "Playing note " << note << " on SID '" << my_name << "'.\n";
}

const char *SID::getName() const {
    return my_name.c_str();
}

