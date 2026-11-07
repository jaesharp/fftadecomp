/* 0x08010514, complete 76 bytes. Set four halfword fields. */
#include "ffta.h"

typedef struct Handle08010514 Handle08010514;
typedef struct {
    u8 unknown_000[0x290];
    u16 field_290;
    u16 field_292;
    u16 field_294;
    u16 field_296;
} Fields08010514;

extern Fields08010514 *func_0800C614(Handle08010514 *handle);

void func_08010514(Handle08010514 *handle, u16 a, u16 b, u16 c, u16 d)
{
    Fields08010514 *fields = func_0800C614(handle);
    fields->field_290 = a;
    fields->field_292 = b;
    fields->field_294 = c;
    fields->field_296 = d;
}
