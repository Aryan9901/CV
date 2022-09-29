#ifndef vehicle_h
#define vehicle_h
// include custom headers

#include "date.h"
#include "storable.cpp"
// include standard cpp headers

#include <string>
using namespace std;

// support for different kinds of vehicles for different purposes
typedef enum
{
    bike = 1,
    car = 2,
    towera = 3
} VehicleType;

// Vehicle class which helps to manage vehicle related data
class Vehicle : public Storable
{
private:
    // registration number given by RTO
    string registrationNumber;
    // type of vehicle given by 'vehicletype' enum
    VehicleType type;
    // number of seats this vehicle has
    int seats;
    // name of the vehicle manufacturer
    string companyName;
    // each vehicle has different price per km
    // this will be required to calculate fare when trip ends
    double pricePerKm;
    // this is the date when PUC will expire
    Date PUCExpirationDate;

public:
    /*
        Constructor
        input : Registration number of vehicle
        input : vehicle type
        input : No. of seats
        input : Company name
        input : Price per km
        input : PUC Expiration date
        input : recordID(defaults to 0)
    */
    Vehicle(string registrationNumber, VehicleType type, int seats, string companyName, double pricePerKm, Date PUCExpirationDate, long recordId = 0);
    // Getter methods with const attribute i.e, this method is not changing any data of the current object
    // if this method is not marked as constant, then it cannot be called from constant object of this class.
    // following snippet will give an error if 'getRegistrationNumber' is not marked with const keyword.
    // const Vehicle * object = new Vehicle( ... );
    // auto registrationNo = object->getRegistrationNumber();

    string getRegistrationNumber() const;
    VehicleType getVehicleType() const;
    string getVehicleTypeName() const;
    int getSeats() const;
    string getCompanyName() const;
    double getPricePerKm() const;
    Date getPUCExpirationDate() const;

    // function which sets new pice of the vehicle
    // input : New price of the vehicle

    void setPricePerKm(double newPrice);
    // display record on screen
    void display() const;
    // overridden virtual method
    string toString() const;
    void setDataFrom(Storable *s);
};

#endif