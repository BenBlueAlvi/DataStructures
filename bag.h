#ifndef BAG_H
#define BAG_H

#include "dynarr.h"

void bagAdd(dynarr* bag, TYPE value);

TYPE bagRemove(dynarr* bag, TYPE value);

int bagContains(dynarr* bag, TYPE value);

#endif
