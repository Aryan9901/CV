#ifndef error_cpp
#define error_cpp

#include <string>
using namespace std;

class Error
{
private:
    string message;

public:
    Error(string message)
    {
        this->message = message;
    }
    string getMessage() const
    {
        return this->message;
    }
};

class NoSuchRecordError : public Error
{
public:
    NoSuchRecordError() : Error("No Such record found"){};
};

class IOError : public Error
{
public:
    IOError() : Error("I/O Error!Could not open or process file make sure 'vehicles.txt', 'trips.txt' and 'users.txt' file exists in this directory"){};
};

class MemoryError : public Error
{
    MemoryError() : Error("System out of memory!"){};
};

#endif