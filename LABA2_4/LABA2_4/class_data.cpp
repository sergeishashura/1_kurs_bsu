#include "class_data.hpp"



Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

Date::Date(Date &other)
{
    day = other.day;
    month = other.month;
    year = other.year;
}

Date::Date(Date &&other)
{
    day = other.day;
    month = other.month;
    year = other.year;
    other.day = 0;
    other.month = 0;
    other.year = 0;
}

Date &Date::operator=(Date &other)
{
    if(this != &other)
    {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    return *this;
}

Date &Date::operator=(Date &&other) {
    if(this != &other)
    {
        day = other.day;
        month = other.month;
        year = other.year;
        other.day = 0;
        other.month = 0;
        other.year = 0;
    }
    return *this;
}

Date::~Date() {}

std::string Date::get_date() const
{
    return to_string(day) + "." + to_string(month) + "." + to_string(year);
}

//void Date::add_days_to_date(int num_days)
//{
//    struct tm time_info = {0};
//    time_info.tm_year = year - YEAR_UNIX;
//    time_info.tm_mon = month - MONTH_UNIX;
//    time_info.tm_mday = day;
//    time_t dif_time = mktime(&time_info);
//    int num_seconds = num_days * NUM_SECONDS_IN_DAY;
//    dif_time += num_seconds;
//    localtime_r(&dif_time, &time_info);
//    day = time_info.tm_mday;
//    month = time_info.tm_mon + MONTH_UNIX;
//    year = time_info.tm_year + YEAR_UNIX;
//}
//
//
//void Date::subtract_days_to_date(int nums_days)
//{
//    add_days_to_date(-nums_days);
//}
//
//int Date::get_date_difference(Date& date_2) const
//{
//    struct tm time_info_first = {0};
//    time_info_first.tm_year = year - YEAR_UNIX;
//    time_info_first.tm_mon = month - MONTH_UNIX;
//    time_info_first.tm_mday = day;
//    time_t dif_time_first = mktime(&time_info_first);
//
//    struct tm time_info_second = {0};
//    time_info_second.tm_year = date_2.year - YEAR_UNIX;
//    time_info_second.tm_mon = date_2.month - MONTH_UNIX;
//    time_info_second.tm_mday = date_2.day;
//    time_t dif_time_second = mktime(&time_info_second);
//
//    int nums_days = 0;
//    if (dif_time_first < dif_time_second)
//    {
//        nums_days = (int)(dif_time_second - dif_time_first) / NUM_SECONDS_IN_DAY;
//        return nums_days;
//    }
//    else
//    {
//        nums_days = (int)(dif_time_first - dif_time_second) / NUM_SECONDS_IN_DAY;
//        return nums_days;
//    }
//}

Date& Date::operator+(int num_days)
{
    Date result(*this);
    struct tm time_info = {0};
    time_info.tm_year = result.year - YEAR_UNIX;
    time_info.tm_mon = result.month - MONTH_UNIX;
    time_info.tm_mday = result.day;
    time_t dif_time = mktime(&time_info);
    int num_seconds = num_days * NUM_SECONDS_IN_DAY;
    dif_time += num_seconds;
    localtime_r(&dif_time, &time_info);
    result.day = time_info.tm_mday;
    result.month = time_info.tm_mon + MONTH_UNIX;
    result.year = time_info.tm_year + YEAR_UNIX;
    return result;
    
}

Date& Date::operator-(int num_days)
{
    Date result(*this);
    struct tm time_info = {0};
    time_info.tm_year = result.year - YEAR_UNIX;
    time_info.tm_mon = result.month - MONTH_UNIX;
    time_info.tm_mday = result.day;
    time_t dif_time = mktime(&time_info);
    int num_seconds = num_days * NUM_SECONDS_IN_DAY;
    dif_time -= num_seconds;
    localtime_r(&dif_time, &time_info);
    result.day = time_info.tm_mday;
    result.month = time_info.tm_mon + MONTH_UNIX;
    result.year = time_info.tm_year + YEAR_UNIX;
    return result;
}

int Date::operator-(Date& date_2)
{
    Date result(*this);
    struct tm time_info_first = {0};
    time_info_first.tm_year = year - YEAR_UNIX;
    time_info_first.tm_mon = month - MONTH_UNIX;
    time_info_first.tm_mday = day;
    time_t dif_time_first = mktime(&time_info_first);
    
    struct tm time_info_second = {0};
    time_info_second.tm_year = date_2.year - YEAR_UNIX;
    time_info_second.tm_mon = date_2.month - MONTH_UNIX;
    time_info_second.tm_mday = date_2.day;
    time_t dif_time_second = mktime(&time_info_second);
    
    int nums_days = 0;
    if (dif_time_first < dif_time_second)
    {
        nums_days = (int)(dif_time_second - dif_time_first) / NUM_SECONDS_IN_DAY;
        return nums_days;
    }
    else
    {
        nums_days = (int)(dif_time_first - dif_time_second) / NUM_SECONDS_IN_DAY;
        return nums_days;
    }
}









