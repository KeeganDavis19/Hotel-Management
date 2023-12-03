//#include<iostream>
#include "../headers/hotel.h"

int main(){
    Hotel myHotel("Marriot", "8594 N Haper Rd", "(818) 992-4870", 6);
    //myHotel.displayRooms();


    myHotel.makeReservation("Davis", "12/1/23", "12/5/23");
    myHotel.makeReservation("Roberston", "1/2/24", "1/8/24");
    //std::cout << std::endl << std::endl;
   // myHotel.displayReservations();
    myHotel.checkIn(1001);
    //myHotel.roomReport();
    
    myHotel.reservationReport();
    
    myHotel.lookUp(1001);
    myHotel.checkOut(1001);
    
    myHotel.roomReport();
    myHotel.reservationReport();

}