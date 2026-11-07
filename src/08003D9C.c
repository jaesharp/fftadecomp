#include "ffta.h"

typedef union {
    u16 packed;
    struct {
        u8 phase;
        u8 flags;
    } bytes;
} TransferStatus;

typedef struct {
    u8 unknown_00[2];
    u8 mode;
    u8 unknown_03[0x121];
    TransferStatus status;
    u8 unknown_128[4];
    u16 send_counter;
    u16 receive_counter;
    u16 send_chunks;
    u16 receive_chunks;
    u16 send_position;
    u16 receive_position;
    u16 send_count;
    u16 receive_count;
    u16 send_checksum;
    u16 receive_checksum;
    u8 unknown_140[4];
    const u8 *send;
    void *send_destination;
    void *receive;
    void *receive_source;
} SerialTransfer;

extern SerialTransfer data_030028A0;
extern u16 func_080027B8(const u8 *data, u16 count);

/* 0x08003D9C: complete 236-byte owner. */
u32 func_08003D9C(const u8 *send, void *send_destination, u16 send_count,
                  void *receive, void *receive_source, u16 receive_count)
{
    SerialTransfer *state = &data_030028A0;

    if (state->status.packed != 0x101 || state->mode != 3)
        return 0;
    state->status.bytes.phase = 2;
    state->send = send;
    state->send_destination = send_destination;
    state->send_position = 0;
    state->send_counter = 0;
    state->send_chunks = (send_count + 5) / 6;
    state->send_count = send_count;
    state->send_checksum = ~func_080027B8(send, send_count);
    state->receive = receive;
    state->receive_source = receive_source;
    state->receive_position = 0;
    state->receive_counter = 0;
    state->receive_chunks = (receive_count + 5) / 6;
    state->receive_count = receive_count;
    state->receive_checksum = 0;
    state->status.bytes.phase = 12;
    return 1;
}
