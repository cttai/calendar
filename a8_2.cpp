/*Christine Tai
This program is designed to print out a calendar
for one year. First, the user is asked to input
a year and the day of the week January 1st falls
on. Days of the week will be numbered 0 through
6 for Sunday through Saturday. Each successive
month starts on the day of the week that follows
the last day of the preceding month. Leap year
is also accounted for in this program. The program
prints out the calendar starting with the year
and then prints the days of January through December.
*/


#include <iostream>
#include <iomanip>
using namespace std;


void getData(int& year, int& dayOfWeek);
void printCalendar(int year, int dayOfWeek);
void printMonth(int year, int dayOfWeek);
void printHeader(int monthCount);
void printSpacesBefore1(int dayOfWeekCount);
void printDaysInMonth(int monthCount, int dayOfWeek,
                      int year, int& dayOfWeekCount);
bool isLeapYear(int year);



int main()
{
    int year;                                       // the year for the calendar
    int dayOfWeek;                                  // the day of the week that January 1st falls on

    getData(year, dayOfWeek);
    printCalendar(year, dayOfWeek);
}











/* This function is designed to get
the year of the calendar from the user
(the value for the variable year) and
the day of the week that January 1st
falls on, numbered 0 through 6 for
Sunday through Saturday (the value for
the variable dayOfWeek).
*/


void getData(int& year, int& dayOfWeek) {
    cout << "What year do you want a calendar for? ";
    cin >> year;
    cout << "What day of the week does January 1 fall on" << endl
         << "(0 for Sunday, 1 for Monday, etc.)?  ";
    cin >> dayOfWeek;
}












/* This function is designed to print
out the calendar. First it prints out
spaces and then the year the user
inputted. Then it prints out one month
at a time, which are based on the year
and the dayOfWeek.
*/


void printCalendar(int year, int dayOfWeek) {
    cout << endl << "         " << year;
    printMonth(year, dayOfWeek);
}












/* This function is designed to print out
one month at a time. It is broken down to
print the header for each month, then print
the spaces before the 1st of each month, and
then print the days in each month.
*/


void printMonth(int year, int dayOfWeek) {
    static int dayOfWeekCount = dayOfWeek;

    for (int monthCount = 1; monthCount <= 12; monthCount++) {
        printHeader(monthCount);
        printSpacesBefore1(dayOfWeekCount);
        printDaysInMonth(monthCount, dayOfWeek,
                         year, dayOfWeekCount);
    }
}











/* This function is designed to print
a header, which consists of the month,
the days of the week, and then a line
of -'s. The month is based on the
number in monthCount (1-12 for the
months Jaunuary - December).
*/


void printHeader(int monthCount) {
    string month;                                     // The name for each month

    switch (monthCount) {
        case (1) : month = "January";
                   break;
        case (2) : month = "February";
                   break;
        case (3) : month = "March";
                   break;
        case (4) : month = "April";
                   break;
        case (5) : month = "May";
                   break;
        case (6) : month = "June";
                   break;
        case (7) : month = "July";
                   break;
        case (8) : month = "August";
                   break;
        case (9) : month = "September";
                   break;
        case (10) : month = "October";
                    break;
        case (11) : month = "November";
                    break;
        case (12) : month = "December";
                    break;
    }
    cout << endl << endl << "        " << month;
    cout << endl << "  S  M  T  W  T  F  S" << endl;
    cout << "---------------------" << endl;
}












/* This function is designed to print
out the spaces before the 1st of each
month so that each successive month
starts on the day of the week that
follows the last day of the preceding
month. The number in dayOfWeekCount is
used to determine how many spaces are
needed.
*/


void printSpacesBefore1(int dayOfWeekCount) {
    for (int count = 0; count <= (dayOfWeekCount % 7); count++) {
        if (count > 0) {
            cout << "   ";
        }
    }
}











/* This function is designed to print the days
in each month. Based on the monthCount, the
number 1 though 12 determine how many days are
in each month(numOfDaysInMonth), including the
possibility of leapyear. Also, at the end of
each week, the days will continue to print out
at the next line.
*/


void printDaysInMonth(int monthCount, int dayOfWeek,
                      int year, int& dayOfWeekCount) {
    int numOfDaysInMonth;                                     // number of days each month has
    int day;                                                  // how many days for that month that has been printed

    switch (monthCount) {
        case (1) :
        case (3) :
        case (5) :
        case (7) :
        case (8) :
        case (10) :
        case (12) : numOfDaysInMonth = 31;
                    break;
        case (2) : numOfDaysInMonth = 28;
                   if (isLeapYear(year)) {
                       numOfDaysInMonth = 29;
                   }
                   break;
        case (4) :
        case (6) :
        case (9) :
        case (11) : numOfDaysInMonth = 30;
                    break;
    }

    dayOfWeek = dayOfWeekCount;

    for (day = 1; day <= numOfDaysInMonth; day++) {
        cout << setw(3) << day;

        if ((day + dayOfWeek) % 7 == 0) {
            cout << endl;
        }
        dayOfWeekCount++;
    }
}











/* This function is designed to determine
whether the year inputted by the user is
a leap year. If the year is divisible by
400, it is a leap year. The years divisible
by 4 are leap years except for years
divisible by 100.
*/


bool isLeapYear(int year) {
    if (year % 400 == 0){
        return true;
    }

    if (year % 100 == 0){
        return false;
    }

    return year % 4 == 0;
}
