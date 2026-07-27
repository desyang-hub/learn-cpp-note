#pragma once

struct nonecopyable
{
    nonecopyable() = default;
    ~nonecopyable() = default;

    nonecopyable(const nonecopyable&) = delete;
    nonecopyable& operator=(const nonecopyable&) = delete;

    nonecopyable(nonecopyable&&) = delete;
    nonecopyable& operator=(nonecopyable&&) = delete;
};
