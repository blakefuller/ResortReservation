#include "ReservationRecord.h"
#include <string>
#include <sstream>

using namespace std;

// prices for rooms
const double STANDARD_Q = 284;
const double STANDARD_K = 290;
const double ATRIUM_Q = 325;
const double ATRIUM_K = 350;

const double PARK_FEE = 12.75;
const double RESORT_FEE = 15;

ReservationRecord::ReservationRecord()
{

}

// get room Size/vehicle park needed and multiply by night to stay
double ReservationRecord :: CalculateCost()
{
    double totalCost = 0;
    int multipleNights = getNumNights();

    if (getParkingNeeded())
    {
        totalCost += multipleNights * PARK_FEE;
    }

    switch(getRoomSize())
    {
        case 1:
            totalCost += multipleNights * STANDARD_Q;
            break;
        case 2:
            totalCost += multipleNights * ATRIUM_Q;
            break;
        case 3:
            totalCost += multipleNights * STANDARD_K;
            break;
        case 4:
            totalCost += multipleNights * ATRIUM_K;
            break;
    }
    return totalCost;
}

// Sets all of the member variables into a string
string ReservationRecord :: CurrentChoice()
{
    stringstream ss;
    ss << "Name: " << getCustomerName();
    ss << "\nRoom Size: " << getRoomSize();
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

// Gets the room Size the user is sleeping in (4 different Sizes)
int ReservationRecord :: getRoomSize()
{
    return roomSize;
}

int ReservationRecord :: getRoomView()
{
    return roomView;
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
// sets the room Size with passed value
void ReservationRecord :: setRoomSize(int room)
{
    roomSize = room;
}

void ReservationRecord :: setRoomView(int room)
{
    roomView = room;
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

void ReservationRecord :: setStartDate(QDate date)
{
    startDate = date;
}

QDate ReservationRecord :: getStartDate()
{
    return startDate;
}

void ReservationRecord :: setNumAdults(int adults)
{
    numAdults = adults;
}

void ReservationRecord :: setNumChildren(int children)
{
    numChildren = children;
}

int ReservationRecord :: getNumAdults()
{
    return numAdults;
}

int ReservationRecord :: getNumChildren()
{
    return numChildren;
}
