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
        int getRoomSize();
        int getRoomView();
        int getNumNights();
        bool getParkingNeeded();

        void setCustomerName(string name);
        void setRoomSize(int roomSize);
        void setRoomView(int roomView);
        void setNumNights(int numNights);
        void setParkingNeeded(bool needed);

    private:
        string customerName;
        int roomSize;
        int roomView;
        int numNights;
        bool parkingNeeded;
};

#endif // RESERVATIONRECORD_H
