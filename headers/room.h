#include <string>

#ifndef ROOM_H
#define ROOM_H

class Room{
    private:
        int roomNum;
        bool available;
        std::string status;

    public:
        Room();
        Room(int r);
        int getRoomNum(){ return roomNum; }
        bool isAvaiable(){ return available; }
        std::string getStatus(){ return status; }
        void reserve();
        void checkIn();
        void checkOut();

};

#endif