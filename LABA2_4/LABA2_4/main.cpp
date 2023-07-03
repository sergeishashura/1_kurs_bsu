#include "source.hpp"

enum NUM_OF_USER_INPUTS
{
    ADDING_DAY = 1,
    SUBTRACTION_DAY,
    CALCULATING_DAY_BETWEEN_DATES
};

int main()
{
    Date date;
    int user_input;
    cout << "Enter first date:" << "\n";
    cin >> date;
    cout << "Enter num of way:" << "\n";
    cout << "1-Adding a date with a given number of days:" << "\n";
    cout << "2-Subtraction from the date of the specified number of days:" << "\n";
    cout << "3-Calculating the number of days elapsed between two dates:" << "\n";
    cin >> user_input;
    switch (user_input)
    {
        case ADDING_DAY:
            add_day(date);
            break;
        case SUBTRACTION_DAY:
            subtract_day(date);
            break;
        case CALCULATING_DAY_BETWEEN_DATES:
            calculate_day_between_day(date);
            break;
            
        default:
            cout << "Enter correct number";
            break;
    }
    return 0;
}
