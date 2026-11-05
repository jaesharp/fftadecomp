#include "ffta.h"

/* 0x080BDF9C: 216 bytes. */
typedef struct {
    u16 id;
    u8 unknown_02[0xA];
    s16 value;
    u8 unknown_0E[6];
} Action;

typedef struct {
    void *object;
    Action actions[40];
    u16 count;
    u16 unknown_326;
} Group;

typedef struct {
    Group groups[13];
    u16 count;
} Collection;

typedef struct {
    void *source;
    void *target;
    u16 action_id;
    u16 unknown_0A;
    Collection *first;
    Collection *second;
    u8 unknown_14[0x14];
    u8 direction;
} ActionContext;

extern u32 func_080CCD50(u16 action_id, u8 selector);

static inline Group *find_group(Collection *collection, void *object)
{
    s32 i;

    for (i = 0; i < collection->count; i++) {
        if (collection->groups[i].object == object)
            return &collection->groups[i];
    }
    return 0;
}

static inline Action *find_action(Group *group, u16 action_id)
{
    s32 i;

    for (i = 0; i < group->count; i++) {
        if (group->actions[i].id == action_id)
            return &group->actions[i];
    }
    return 0;
}

s32 func_080BDF9C(ActionContext *context)
{
    Group *group;
    Action *action;

    if (context->action_id == 0 || !func_080CCD50(context->action_id, 11)) {
        if (context->source == context->target)
            return 0;
    }

    group = find_group(context->first, context->target);
    if (group == 0)
        group = find_group(context->second, context->target);
    action = find_action(group, context->action_id);
    if (action == 0)
        return 0;

    if (context->direction) {
        if (action->value > 0)
            return 0;
    } else {
        if (action->value < 0)
            return 0;
    }
    return 1;
}
