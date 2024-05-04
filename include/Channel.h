#pragma once
#include <stdbool.h>

// 定义函数指针
typedef int (*handleFunc)(void* arg);

// 定义文件描述符的读写事件
enum FDEvent {
    TIMEOUT = 0X01,
    READEVENT = 0X02,
    WRITEEVENT = 0X04
};

struct Channel
{
    //文件描述符
    int fd;
    // 事件
    int events;
    // 回调函数
    handleFunc readCallBack;
    handleFunc writeCallBack;
    // 回调函数参数
    void* arg;
};

// 初始化Channel
struct Channel* channelInit(int fd, int events, handleFunc readCallBack, handleFunc writeCallBack, void* arg); 
// 修改fd的写事件（检测 或 不检测）
void writeEventEnable(struct Channel* channel, bool flag);
// 判断是否需要检测文件描述符的写事件
bool isWriteEventEnable(struct Channel* channel);

