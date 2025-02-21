// sid.cpp (C++ implementation) - ORIGINAL FILE (UNTOUCHED)
#include "sid.h"
#include <iostream>

SID::SID(const std::string &name) : name(name) {
    std::cout << "SID instance '" << name << "' created.\n";
}

SID::~SID() {
    std::cout << "SID instance '" << name << "' destroyed.\n";
}

void SID::playNote(int note) {
    std::cout << "Playing note " << note << " on SID '" << name << "'.\n";
}

std::string SID::getName() const {
    return name;
}

