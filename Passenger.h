//
// Created by Asus on 15.12.2022.
//

#ifndef FIRSTPROJECT_PASSENGER_H
#define FIRSTPROJECT_PASSENGER_H


#include <utility>

#include "Ticket.h"

class User {
    string name;
    map<int, Ticket*> tickets;

public:
    explicit User(string name){
        this->name = std::move(name);

    };

    void addTicket(Ticket *ticket, int ID) {
        tickets.insert({ID, ticket});

    };

    void returnTicket(int ID){
        int returnedMoney = tickets.at(ID)->returnTicket();
        tickets.erase(ID);
        cout << ID << " ticket successfully returned! "<< returnedMoney << "$ returned to " << name << endl;
    };

    void view(){
        for(auto ticket: tickets){
            ticket.second->printTicket();
            cout << endl;
        }
    };

    void view(int ID){
        tickets.at(ID)->printTicket();
        cout << ", name: " + name << endl;
    };

    bool checkIfExists(int ID){
        if(tickets.find(ID) != tickets.end()){
            return true;
        }
        return false;
    };

};


#endif //FIRSTPROJECT_PASSENGER_H
