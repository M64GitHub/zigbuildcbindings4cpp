// resid.h, 2023, m64

#ifndef SDL_RESID_H
#define SDL_RESID_H

#include "audio-config.h"
#include "resid/sid.h"
#include "resid/siddefs.h"

typedef struct S_ReSIDPbData {
    short buf1[CFG_AUDIO_BUF_SIZE+1];
    short buf2[CFG_AUDIO_BUF_SIZE+1];
    short *buf_playing = 0;
    short *buf_next = 0;
    char buf_consumed = 0;
    char buf_lock = 0;
    char play = 0;
    unsigned long stat_cnt = 0;
    unsigned long stat_bufwrites = 0;
    unsigned long stat_buf_underruns = 0;
    unsigned long stat_framectr = 0;
} ReSIDPbData;

class ReSID 
{
public:
    ReSID(const char *name);
    ~ReSID();

    const char *GetName() const;
    const char *GetModel() const;

    void SetChipModel(chip_model m);
    bool SetChipModel(const char *m);
    void WriteRegs(unsigned char *regs, int len);

    // dumb audio rendering, not frame aware
    int Clock(unsigned int cycles, short *buf, int buflen);

    void SetDbgOutput(bool b);
    
    // calculated CONSTANTS
    int SAMPLES_PER_FRAME;
    int CYCLES_PER_FRAME;
    double CYCLES_PER_SAMPLE;

    unsigned char shadow_regs[32];

private:
    void precalc_constants();
    char name[1024];
    SID  sid;
    chip_model model;
    bool dbg_output;
};

#endif

