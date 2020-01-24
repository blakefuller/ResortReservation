#include "ReservationRecord.h"
#include <string>
#include <sstream>

using namespace std;

ReservationRecord::ReservationRecord()
{

}

// get room type/vehicle park needed and multiply by night to stay
double ReservationRecord :: CalculateCost()
{
    double totalCost = 0;
    int multipleNights = getNumNights();

    if (getParkingNeeded())
    {
        totalCost += multipleNights * 12.75;
    }

    switch(getRoomType())
    {
        case 1:
            totalCost += multipleNights * 284;
            break;
        case 2:
            totalCost += multipleNights * 325;
            break;
        case 3:
            totalCost += multipleNights * 290;
            break;
        case 4:
            totalCost += multipleNights * 350;
            break;
    }
    return totalCost;
}

// Sets all of the member variables into a string
string ReservationRecord :: CurrentChoice()
{
    stringstream ss;
    ss << "Name: " << getCustomerName();
    ss << "\nRoom Type: " << getRoomType();
    ss << "\nNumber of Nights: " << getNumNights();

    string parking;
    if (getParkingNeeded())
        parking = "YES";
    else
        parking = "NO";

    ss << "\nParking needed: " << parking;
    ss << "\nTotal Cost: $" << CalculateCost();

    return ss.str();
}

// Gets the customer name
string ReservationRecord :: getCustomerName()
{
    return customerName;
}

// Gets the room type the user is sleeping in (4 different types)
int ReservationRecord :: getRoomType()
{
    return roomType;
}

// Get the number of nights the user is going to stay in
int ReservationRecord :: getNumNights()
{
    return numNights;
}

// Get a true/false value for the user if they need parking
bool ReservationRecord ::getParkingNeeded()
{
    return parkingNeeded;
}

// // sets the customer name with passed value
void ReservationRecord :: setCustomerName(string name)
{
    customerName = name;
}
// sets the room type with passed value
void ReservationRecord :: setRoomType(int room)
{
    roomType = room;
}

// sets the number of nights with passed value
void ReservationRecord :: setNumNights(int num)
{
    numNights = num;
}
// sets the parking neccessity with passed value
void ReservationRecord :: setParkingNeeded(bool needed)
{
    parkingNeeded = needed;
}