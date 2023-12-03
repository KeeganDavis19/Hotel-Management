#include<vector>
#include<iostream>
#include<fstream>
#include "room.h"
#include "reservation.h"

#ifndef HOTEL_H
#define HOTEL_H

class Hotel{
    private:
        std::string name;
        std::string address;
        std::string phoneNum;
        std::vector<Room> roomsVec;
        std::vector<Reservation> reservationVec;

    public:
        Hotel();
        Hotel(std::string n, std::string a, std::string p, int numRooms);
        void displayRooms();
        int makeReservation(std::string guest, std::string in, std::string out);
        void displayReservations();
        void roomReport();
        void reservationReport();
        void lookUp(int confirmNum);
        void checkIn(int confirmNum);
        void checkOut(int confirmNum);

};

#endif
