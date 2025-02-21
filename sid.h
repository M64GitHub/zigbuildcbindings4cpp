// sid.h (C++ header) - ORIGINAL FILE (UNTOUCHED)
#ifndef SID_H
#define SID_H

#include <string>

class SID {
public:
    SID(const std::string &name);
    ~SID();

    void playNote(int note);
    std::string getName() const;

private:
    std::string name;
};

#endif // SID_H
//
