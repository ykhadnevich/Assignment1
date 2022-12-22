#ifndef FIRSTPROJECT_TICKET_H
#define FIRSTPROJECT_TICKET_H


#include <utility>

#include "Plane.h"


class Ticket {
    Plane* plane;
    string seatName;

public:
    Ticket(Plane* flight, string seatName){
        this->plane = flight;
        this->seatName = std::move(seatName);
    }
    int returnTicket(){
        plane->returnTicket(seatName);
        return plane->getPrice(seatName);
    }
    void printTicket(){
        cout << "Flight: " + plane->getNumber() + ", date: " + plane->getDate() + ", seat: " + seatName
                + ", price: " + to_string(plane->getPrice(seatName));
    }
};


#endif //FIRSTPROJECT_TICKET_H