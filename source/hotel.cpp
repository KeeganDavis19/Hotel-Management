#include"../headers/hotel.h"


int Reservation::confirmCount = 1000;
Hotel::Hotel(){
    name = "Unnamed Hotel";
    address = "No address";
    phoneNum = "(000) 000-0000";
}

Hotel::Hotel(std::string n, std::string a, std::string p, int numRooms){
    name = n;
    address = a;
    phoneNum = p;
    for(int i = 0; i < numRooms; i++){
        Room curRoom(100 + i);
        roomsVec.push_back(curRoom);
    }
}

void Hotel::displayRooms(){
    for(std::vector<Room>::iterator it = roomsVec.begin(); it != roomsVec.end(); it++){
        Room& cur_room = *it;
        std::cout << "Room: " << cur_room.getRoomNum() << std::endl;
    }
}

int Hotel::makeReservation(std::string guest, std::string in, std::string out){
    for(std::vector<Room>::iterator it = roomsVec.begin(); it != roomsVec.end(); it++){
        Room& cur_room = *it;
        if(cur_room.isAvaiable()){
            cur_room.reserve();
            Reservation cur_reservation(guest, in, out, cur_room.getRoomNum());
            reservationVec.push_back(cur_reservation);
            return cur_reservation.getConfirmationNum();
        }
    }
    return 0;
}

void Hotel::displayReservations(){
    for(std::vector<Reservation>::iterator it = reservationVec.begin(); it != reservationVec.end(); it++){
        Reservation& cur_res = *it;
        std::cout << "Reservation: " << cur_res.getConfirmationNum() << std::endl;
        std::cout << "\tGuest: " << cur_res.getName() << std::endl;
        std::cout << "\t" << cur_res.getCheckIn() << " to " << cur_res.getCheckOut() << std::endl;
    }
}


void Hotel::roomReport(){
    std::ofstream fout;
    fout.open("rooms.txt");
    if(fout.fail()){
        std::cout << "Failure to open 'rooms.txt'." << std::endl;
    }

    fout << name << " Rooms Report" << std::endl << std::endl;
    fout << "Room:\tAvailability:" << std::endl; 
    fout << "----------------------" << std::endl;
    for(std::vector<Room>::iterator it = roomsVec.begin(); it != roomsVec.end(); it++){
        Room& cur_room = *it;
        fout << cur_room.getRoomNum() << "\t\t";
        if(cur_room.isAvaiable()){
            fout << "Available" << std::endl;
        } else{
            fout << "Reserved" << std::endl;
        }
    }

    fout.close();
}

void Hotel::reservationReport(){
    std::ofstream fout;
    fout.open("reservations.txt");
    if(fout.fail()){
        std::cout << "Failure to open 'reservations.txt'." << std::endl;
    }


    fout << name << " Reservations Report" << std::endl;
    fout << "------------------------------"  << std::endl << std::endl;

    for(std::vector<Reservation>::iterator it = reservationVec.begin(); it != reservationVec.end(); it++){
        Reservation& cur_res = *it;
        Room& cur_room = const_cast<Room&>(cur_res.getRm());
        fout << "Confrimation Number: " << cur_res.getConfirmationNum() << std::endl;
        fout << "\tGuest: " << cur_res.getName() << std::endl;
        fout << "\tRoom:" << cur_res.getRoom() << std::endl;
        fout << "\tFrom: " << cur_res.getCheckIn() << "\tTo: " << cur_res.getCheckOut() << std::endl;
        fout << "\tStatus: " << cur_room.getStatus() << std::endl << std::endl;
    }

    fout.close();

}

void Hotel::lookUp(int confirmNum){
    for(std::vector<Reservation>::iterator it = reservationVec.begin(); it != reservationVec.end(); it++){
        Reservation& cur = *it;
        if(cur.getConfirmationNum() == confirmNum){
            std::cout << "Reservation " << confirmNum << ":" << std::endl;
            std::cout << "\tGuest Name: " << cur.getName() << std::endl;
            std::cout << "\tRoom: " << cur.getRoom() << std::endl;
            std::cout << "\tCheck In: " << cur.getCheckIn() << std::endl;
            std::cout << "\tCheck Out: " << cur.getCheckOut() << std::endl << std::endl;
            return;
        }
    }
    std::cout << "No reservation matches confimation number: " << confirmNum << std::endl;
}

void Hotel::checkIn(int confirmNum){
    for(std::vector<Reservation>::iterator it = reservationVec.begin(); it != reservationVec.end(); it++){
        Reservation& cur = *it;
        if(cur.getConfirmationNum() == confirmNum){
            Room& cur_room = const_cast<Room&>(cur.getRm());
            cur_room.checkIn();
            std::cout << "Reservation: " << confirmNum << " - Successful check in." << std::endl;
            return;
        }
    }
    std::cout << "Failure to check in." << std::endl;
}

void Hotel::checkOut(int confirmNum){
    for(std::vector<Reservation>::iterator it = reservationVec.begin(); it != reservationVec.end(); it++){
        Reservation& cur = *it;
        if(cur.getConfirmationNum() == confirmNum){
            Room& cur_room = const_cast<Room&>(cur.getRm());
            cur_room.checkOut();
            std::cout << "Reservation: " << confirmNum << " - Successful check out." << std::endl;
            reservationVec.erase(it);
            return;
        }
    }
    std::cout << "Failure to check out." << std::endl;
}
