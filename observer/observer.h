/**
 * @FilePath     : /cpp/observer/observer.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2025-12-27 21:46:53
 * @LastEditors  : desyang
 * @LastEditTime : 2025-12-27 21:52:38
**/
#ifndef __OBSERVER__
#define __OBSERVER__

#include "subject.h"

class Observer {
public:
    virtual void update(Subject *sub, int value);
};

#endif