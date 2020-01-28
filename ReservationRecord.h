#ifndef RESERVATIONRECORD_H
#define RESERVATIONRECORD_H
#include <string>
#include <QDate>

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
        int getNumAdults();
        int getNumChildren();
        QDate getStartDate();
        bool getParkingNeeded();
        double getFinalCost();

        void setCustomerName(string name);
        void setRoomSize(int roomSize);
        void setRoomView(int roomView);
        void setNumNights(int numNights);
        void setNumAdults(int adults);
        void setNumChildren(int children);
        void setStartDate(QDate date);
        void setParkingNeeded(bool needed);
        void setFinalCost(double cost);

    private:
        string customerName;
        int roomSize;
        int roomView;
        int numNights;
        int numAdults;
        int numChildren;
        QDate startDate;
        bool parkingNeeded;
        double finalCost;
};

#endif // RESERVATIONRECORD_H
