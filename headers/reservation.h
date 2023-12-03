#include<string>
#include "room.h"

#ifndef RESERVATION_H
#define RESERVATION_H


class Reservation{
    private:
        std::string name;
        std::string checkIn;
        std::string checkOut;
        static int confirmCount;
        int confrimationNum;
        Room room;

    public:
        Reservation(std::string n, std::string in, std::string out, const Room& r){
            name = n;
            checkIn = in;
            checkOut = out;
            confrimationNum = confirmCount++;
            room = r;
        }

        std::string getName(){ return name; }
        std::string getCheckIn(){ return checkIn; }
        std::string getCheckOut(){ return checkOut; }
        int getConfirmationNum(){ return confrimationNum; }
        const Room& getRm(){ return room; }
        int getRoom(){ return room.getRoomNum(); }

};

#endif