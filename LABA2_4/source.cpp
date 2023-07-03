#include "source.hpp"

int enter_numbers_day()
{
    int num_days;
    cout << "Enter numbers of day: ";
    cin >> num_days;
    return num_days;
}
void add_day(Date& date)
{
    int num_days = enter_numbers_day();
    date = date + num_days;
    cout << "New date: ";
    cout << date << "\n";
}
void subtract_day(Date& date)
{
    int num_days = enter_numbers_day();
    date = date - num_days;
    cout << "New date: ";
    cout << date << "\n";
}
void calculate_day_between_day(Date& date)
{
    Date date_2;
    cout << "Enter new date: ";
    cin >> date_2;
    int dif_days = date - date_2;
    cout << "The number of days that have passed between two dates :" << dif_days << "\n";
}
