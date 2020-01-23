#ifndef RESERVATIONRECORD_H
#define RESERVATIONRECORD_H
#include <string>

using namespace std;

class ReservationRecord
{
    public:
        ReservationRecord();
        double CalculateCost();
        string CurrentChoice();

        string getCustomerName();
        int getRoomType();
        int getNumNights();
        bool getParkingNeeded();

        void setCustomerName(string name);
        void setRoomType(int roomType);
        void setNumNights(int numNights);
        void setParkingNeeded(bool needed);

    private:
        string customerName;
        int roomType;
        int numNights;
        bool parkingNeeded;
};

#endif // RESERVATIONRECORD_H
