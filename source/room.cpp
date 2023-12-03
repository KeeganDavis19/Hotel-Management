
#include"room.h"

Room::Room(){
    roomNum = 000;
    available = true;
    status = "Vacant";
}

Room::Room(int r){
    roomNum = r;
    available = true;
    status = "Vacant";
}

void Room::reserve(){
    available = false;
    status = "Reserved";
}

void Room::checkIn(){
    available = false;
    status = "Checked In";
}

void Room::checkOut(){
    available = true;
    status = "Vacant";
}