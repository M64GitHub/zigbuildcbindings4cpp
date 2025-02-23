// sid_wrapper.h (C header for C compatibility) - NEW WRAPPER FILE ADDED TO LIB
#ifndef SID_WRAPPER_H
#define SID_WRAPPER_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Opaque type for SID object
typedef struct ReSID ReSID;

// C-compatible interface
ReSID* ReSID_create(const char* name);
void ReSID_destroy(ReSID* resid);

const char* ReSID_getName(ReSID* resid);

void ReSID_setDBGOutput(ReSID *resid, bool b);

bool ReSID_setChipModel(ReSID *resid, const char *m);

#ifdef __cplusplus
}
#endif

#endif // SID_WRAPPER_H
//
