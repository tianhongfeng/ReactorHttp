#include "Channel.h"

struct Channel* channelInit(int fd, int events, handleFunc readCallBack, handleFunc writeCallBack, void* arg) {

    struct Channel* channel = (struct Channel*)malloc(sizeof(struct Channel));
    channel->fd = fd;
    channel->events = events;
    channel->readCallBack = readCallBack;
    channel->writeCallBack = writeCallBack;
    channel->arg = arg;
    return channel;
}

void writeEventEnable(struct Channel* channel, bool flag) {
    if (flag) {
        channel->events |= WRITEEVENT;
    } else {
        channel->events = channel->events & ~WRITEEVENT;
    }
}

bool isWriteEventEnable(struct Channel* channel) {
    return channel->events & WRITEEVENT;
}