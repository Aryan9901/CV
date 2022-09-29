#ifndef Date_h
#define Date_h

/* include custom headers */

#include "storable.cpp"
/* include standard headers */

#include <ctime>
#include <string>

using namespace std;

typedef struct Date : Serializable
{
private:
    /* structure holding date & time info. */
    struct tm date;
    bool empty;

public:
    /* Constructor, create date from string */
    Date(string date);
    /* create date from current time */
    Date();

    /* add given numbers of days in this date */
    Date operator+(int days);

    // if this date is greater than given date:
    bool operator>(Date date) const;

    // if this date greater than or equal to given date
    bool operator>=(Date date) const;

    // if this date is less than given date:
    bool operator<(Date date) const;

    // if this date less than or equal to given date
    bool operator<=(Date date) const;

    bool isEmpty() const;
    string toString() const;
} Date;

#endif