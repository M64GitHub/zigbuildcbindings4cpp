// sid_wrapper.cpp (C++ wrapper implementation) - NEW WRAPPER FILE ADDED TO LIB
#include "resid_wrapper.h"
#include "resid.h"

extern "C" {
    ReSID* ReSID_create(const char* name) {
        return new ReSID(name);
    }

    void ReSID_destroy(ReSID* resid) {
        delete resid;
    }

    const char* ReSID_getName(ReSID* resid) {
        return resid->GetName();
    }

    void ReSID_setDBGOutput(ReSID *resid, bool b)
    {
        resid->SetDbgOutput(b);
    }

    bool ReSID_setChipModel(ReSID *resid, const char *m)
    {
        return resid->SetChipModel(m);
    }
}
