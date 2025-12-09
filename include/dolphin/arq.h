#ifndef _DOLPHIN_ARQ
#define _DOLPHIN_ARQ

#include "dolphin/ar.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ARQ_DMA_ALIGNMENT 32

#define ARQ_TYPE_MRAM_TO_ARAM ARAM_DIR_MRAM_TO_ARAM
#define ARQ_TYPE_ARAM_TO_MRAM ARAM_DIR_ARAM_TO_MRAM

struct ARQRequest {
    /* 0x00 */ struct ARQRequest *next;
    /* 0x04 */ u32 owner;
    /* 0x08 */ u32 type;
    /* 0x0C */ u32 priority;
    /* 0x10 */ u32 source;
    /* 0x14 */ u32 dest;
    /* 0x18 */ u32 length;
    /* 0x1C */ ARQCallback callback;
};

typedef struct ARQRequest ARQRequest;

void ARQInit(void);
void ARQReset(void);
void ARQPostRequest(ARQRequest* request, u32 owner, u32 type, u32 priority, u32 source, u32 dest, u32 length, ARQCallback callback);
void ARQRemoveRequest(ARQRequest* request);
void ARQRemoveOwnerRequest(u32 owner);
void ARQFlushQueue(void);
void ARQSetChunkSize(u32 size);
u32 ARQGetChunkSize(void);
BOOL ARQCheckInit(void);

#ifdef __cplusplus
}
#endif

#endif // _DOLPHIN_ARQ
