#include "ReservationRecord.h"
#include <string>
#include <sstream>

using namespace std;

// prices for rooms
const double STANDARD_Q = 284;
const double STANDARD_K = 290;
const double ATRIUM_Q = 325;
const double ATRIUM_K = 350;

extern const double PARK_FEE = 12.75;
extern const double RESORT_FEE = 15;

ReservationRecord::ReservationRecord()
{
    numNights = 1;
    numAdults = 1;
    numChildren = 0;
    parkingNeeded = false;
}

// get room size and type needed and multiply by night to stay
double ReservationRecord :: CalculateCost()
{
    double totalCost = 0;
    int multipleNights = getNumNights();

    int size = getRoomSize();
    int view = getRoomView();

    if(size == 1 && view == 1)
        totalCost += multipleNights * STANDARD_K;
    else if(size == 1 && view == 2)
        totalCost += multipleNights * ATRIUM_K;
    else if (size == 2 && view == 1)
        totalCost += multipleNights * STANDARD_Q;
    else if (size == 2 && view == 2)
        totalCost += multipleNights * ATRIUM_Q;
    else
        totalCost = 0;

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
