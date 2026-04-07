#pragma once


namespace lock
{


class Locker
{
protected:
    Locker() = default;
public:
    virtual ~Locker() = default;
    virtual void lock() = 0;
    virtual void unlock() = 0;
};


} // namespace lock