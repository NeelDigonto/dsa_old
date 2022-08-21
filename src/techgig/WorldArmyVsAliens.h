#pragma once
#include <core/Common.h>

#include <iostream>
using namespace std;
struct TimePoint {
    size_t minutes_;
    constexpr static size_t max_minutes = 24ll * 60ll;

    constexpr TimePoint() = delete;
    constexpr TimePoint(size_t _mins) : minutes_{_mins} {}
    constexpr TimePoint(size_t _hrs, size_t _mins) : minutes_{ _hrs * 60 + _mins } {}

    constexpr size_t getHours() const noexcept {
        return minutes_ / 60;
    }

    constexpr inline size_t getMinutes() const noexcept {
        return minutes_ % 60;
    }

    constexpr inline friend void operator+=(TimePoint& lhs, const TimePoint& rhs) noexcept {
        lhs.minutes_ += rhs.minutes_;
    }

    constexpr inline friend TimePoint operator+(const TimePoint& lhs, const TimePoint& rhs) noexcept {
        auto minutes = lhs.minutes_ + rhs.minutes_;
        if (minutes >= max_minutes)
            minutes %= max_minutes;
        return TimePoint{ minutes };
    }

    inline friend ostream& operator<<(ostream& os, const TimePoint& _time_point) {
        if (_time_point.getHours() < 10)
            os << '0';
        os << _time_point.getHours();

        os << ' ';

        if (_time_point.getMinutes() < 10)
            os << '0';
        os << _time_point.getMinutes();

        return os;
    }
};

int _main(int argc, char* a[])
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    size_t launch_hr, lauch_min;
    size_t travel_hr, travel_min;

    cin >> launch_hr >> lauch_min;
    cin >> travel_hr >> travel_min;

    TimePoint launch_time{ launch_hr, lauch_min };
    TimePoint travel_time{ travel_hr, travel_min };

    TimePoint blast_time = launch_time + travel_time;

    cout << blast_time;

    return 0;
}
