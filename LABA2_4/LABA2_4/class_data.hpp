#include <iostream>

using namespace std;

const unsigned int NUM_SECONDS_IN_DAY = 86400;
const unsigned int YEAR_UNIX = 1900;
const unsigned int MONTH_UNIX = 1;
const unsigned int DAY_UNIX = 1;

class Date
{
private:
    int day, month, year;
public:
    Date();
    Date(int d, int m, int y);
    Date(Date& other);
    Date(Date&& other);
    Date& operator=(Date& other);
    Date& operator=(Date&& other);
    Date& operator+(int num_days);
    Date& operator-(int num_days);
    int operator-(Date& other);
    ~Date();
    friend ostream& operator<<(ostream& os, Date& date) {return os << date.get_date();}
    friend istream& operator>>(istream& is, Date& date)
    {
        char interim_date;
        return is >> date.day >> interim_date >> date.month >> interim_date >> date.year;
    }
    string get_date() const;
//    void add_days_to_date(int num_days);
//    void subtract_days_to_date(int num_days);
//    int get_date_difference(Date& date_2) const;
};
