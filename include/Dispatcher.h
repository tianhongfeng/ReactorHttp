#pragma once
#include "Channel.h"
#include "EventLoop.h"

struct Dispatcher
{
    // init 初始化 epoll poll select 需要的数据块
    void* (*init)();
    // 添加
    int (*add)(struct Channel* channel, struct EventLoop* evLoop);
    // 删除
    int (*remove)(struct Channel* channel, struct EventLoop* evLoop);
    // 事件监测
    int (*dispatch)();
    // 清除数据 关闭fd 或者 释放内存
    int (*clear)();
};
