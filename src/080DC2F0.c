/* Target: 44 bytes at 080DC2F0. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct Task Task;
typedef struct {
    u16 state;
    u16 unknown_02;
    u32 identifier;
    u8 unknown_08[12];
    s16 enabled;
    u16 parameter;
    u16 mode;
    u16 unknown_1A;
} DcRequest;

extern int func_080DB6D0(Task *, DcRequest *, void *);
extern Task *func_08005B6C(int (*)(Task *, DcRequest *, void *), u16,
                          const DcRequest *, Task *);

Task *func_080DC2F0(u32 identifier, u8 enabled, u16 parameter, Task *parent)
{
    DcRequest request;

    /* The scheduler copies all 28 bytes; unspecified members remain unknown. */
    request.identifier = identifier;
    request.enabled = enabled;
    request.parameter = parameter;
    request.mode = 3;
    return func_08005B6C(func_080DB6D0, 16, &request, parent);
}
