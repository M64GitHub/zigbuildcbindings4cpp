// sid.h (C++ header) - AS EXAMPLE FOR  A C++ LIB ORIGINAL FILE (UNTOUCHED)
#ifndef SID_H
#define SID_H

#include <string>

class SID {
public:
    SID(const std::string &name);
    ~SID();

    void playNote(int note);
    const char *getName() const;

private:
    std::string my_name;
};

#endif // SID_H
