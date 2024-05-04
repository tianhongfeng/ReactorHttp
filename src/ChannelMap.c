#include "ChannelMap.h"
#include <stdio.h>
#include <stdlib.h>

struct ChannelMap* ChannelMapInit(int size) {
    struct ChannelMap* map = (struct ChannelMap*)malloc(sizeof(struct ChannelMap));
    map->size = size;
    map->list = (struct Channel**)malloc(size * sizeof(struct Channel*));
    return map;
}

void ChannelMapClear(struct ChannelMap* map) {
    if (map != NULL) {
        for (int i = 0; i < map->size; i++) {
            if (map->list[i] != NULL) {
                free(map->list[i]);
            }
        }
        free(map->list);
        map->list = NULL;
    }
    map->size = 0;
}

// unitsize 数组每个元素占空间大小
bool makeMapRoom(struct ChannelMap* map, int newSize, int unitsize) {
    if (map->size < newSize) {
        int curSize = map->size;
        // 容量每次扩大为原来的一倍
        while (curSize < newSize) {
            curSize *= 2;
        }
        // 扩容, 由于扩容之后可能找了一块新的的内存空间，因此map->list 需要重新赋值
        struct Channle** temp = realloc(map->list, curSize * unitsize);
        if (temp == NULL) {
            return false;
        }
        map->list = temp;
        memset(&map->list[map->size], 0, (curSize - map->size) * unitsize); // 清空扩容的空间
        map->size = curSize;
    }
    return true;
}

