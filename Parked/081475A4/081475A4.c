/* 081475A4: adjust three five-bit palette channels, retaining originals. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u16 data_03003860[];
extern u8 data_03003E68[][12];
extern void *func_081443FC(void *destination, const void *source, u32 bytes);

void func_081475A4(u16 first, u16 count, s16 red, s16 green, s16 blue, u8 restore)
{
    s16 channels[3];
    s16 *changes[3] = { &red, &green, &blue };
    u16 last;
    u16 i;
    u16 j;

    last = first + count - 1;
    if (last > 511)
        last = 511;
    if (restore == 0) {
        for (i = first; i <= last; i++) {
            channels[0] = data_03003860[i] & 0x1F;
            channels[1] = (data_03003860[i] & 0x3E0) >> 5;
            channels[2] = (data_03003860[i] & 0x7C00) >> 10;
            for (j = 0; j < 3; j++) {
                data_03003E68[i][j] = channels[j];
                if (*changes[j] != 0) {
                    channels[j] += *changes[j];
                    if (channels[j] < 0)
                        channels[j] = 0;
                    else if (channels[j] > 31)
                        channels[j] = 31;
                }
            }
            data_03003860[i] = (channels[1] << 5) | channels[0] | (channels[2] << 10);
        }
    } else {
        for (i = first; i <= last; i++) {
            for (j = 0; j < 3; j++) {
                channels[j] = data_03003E68[i][j];
                if (*changes[j] != 0) {
                    channels[j] += *changes[j];
                    if (channels[j] < 0)
                        channels[j] = 0;
                    else if (channels[j] > 31)
                        channels[j] = 31;
                }
            }
            data_03003860[i] = (channels[1] << 5) | channels[0] | (channels[2] << 10);
        }
    }
}
