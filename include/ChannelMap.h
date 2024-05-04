#pragma once

#include <stdbool.h>

struct ChannelMap {
    int size; // 记录指针指向的数组的元素个数
    // strucr Channel* list[] 
    struct Channel** list;
};

// 初始化
struct ChannelMap* ChannelMapInit(int size);
// 清空map
void ChannelMapClear(struct ChannelMap*);
// 扩容map
bool makeMapRoom(struct ChannelMap*, int newSize, int unitsize);

