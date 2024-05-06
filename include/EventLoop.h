#pragma once

#include "Dispatcher.h"

struct EventLoop {
    struct Dispatcher* dispatcher;
    void* dispatcherData;
};