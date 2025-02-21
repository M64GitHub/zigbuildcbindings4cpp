// sid_c_wrapper.h (C header for C compatibility)
#ifndef SID_C_WRAPPER_H
#define SID_C_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

// Opaque type for SID object
typedef struct SID SID;

// C-compatible interface
SID* SID_create(const char* name);
void SID_destroy(SID* sid);
void SID_playNote(SID* sid, int note);
const char* SID_getName(SID* sid);

#ifdef __cplusplus
}
#endif

#endif // SID_C_WRAPPER_H
//
