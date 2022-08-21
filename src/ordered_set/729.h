#pragma once
#include <deque>
#include <utility>
#include <concurrent_queue.h>

class MyCalendar {
private:
    ::std::deque<std::pair<int, int>> calendar_;
public:
    MyCalendar() = default;

    bool book(int start, int end) {
        if (calendar_.empty())
        {
            calendar_.emplace_back(std::make_pair(start, end));
            return true;
        }
        
    }
};