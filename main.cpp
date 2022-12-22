#include <iostream>
#include <fstream>
#include <string>
#include "Passenger.h"

using namespace std;
int ID = 12345;

vector<string> split(const string& line, char delim);

int main(){
    vector<Plane> flights;
    map<string, User> users;
    ifstream myFile;
    myFile.open("Plane.txt");
    string line;
    getline(myFile, line);
    int length = stoi(line);
    for(int i = 0; i < length; i++){
        getline(myFile, line);
        cout << line << endl;
        vector<string> flightData = split(line, ' ');
        auto flight = Plane(flightData[0],
                            flightData[1],
                            stoi(flightData[2]),
                            flightData[3],
                            flightData[5],
                            stoi(flightData[4]),
                            stoi(flightData[6]));
        flights.push_back(flight);
    }
    string command;
    string entered;
    while(true) {
        cout << "Command: ";
        getline(cin, entered);
        vector<string> parametrs = split(entered, ' ');
        command = parametrs[0];
        if(command == "stop"){
            break;
        }
        else if(command == "check"){
            string date = parametrs[1];
            string flightNum = parametrs[2];
            for(auto & flight : flights){
                if(flight.getDate() == date && flight.getNumber() == flightNum){
                    flight.check();
                    break;
                }
            }
        }
        else if(command == "book"){
            for(auto & flight : flights){
                string date = parametrs[1];
                string flightNum = parametrs[2];
                string seatName = parametrs[3];
                string userName = parametrs[4];
                if(flight.getDate() == date && flight.getNumber() == flightNum){
                    flight.book(seatName);
                    auto ticket =  Ticket(&flight, seatName);
                    if(users.find(userName) != users.end()){
                        users.at(userName).addTicket(&ticket, ID);
                        ID++;
                    }
                    else{
                        User user =  User(userName);
                        users.insert({userName, user});
                        users.at(userName).addTicket(&ticket, ID);
                        ID++;
                    }
                    cout << "Ticket booked with ID: " << ID - 1 << endl;
                }
            }
        }
        else if(command == "return"){
            int ticketID = stoi(parametrs[1]);
            for(auto user: users){
                if(user.second.checkIfExists(ticketID)){
                    user.second.returnTicket(ticketID);
                    break;
                }
            }
        }
        else if(command == "viewID"){
            int ticketID = stoi(parametrs[1]);
            for(auto user: users){
                if(user.second.checkIfExists(ticketID)){
                    user.second.view(ticketID);
                    break;
                }
            }
        }
        else if (command == "view"){
            string name = parametrs[1];
            users.at(name).view();
        }

    }
}

vector<string> split(const string& line, char delim) {
    vector<string> result;
    string part;
    for(int i = 0; i < line.length(); i++){
        if(line[i] != delim && line.length() - 1 != i){
            part += line[i];
        }
        else if(line.length() - 1 == i){
            part += line[i];
            result.push_back(part);
        }
        else{
            result.push_back(part);
            part = "";
        }
    }
    return result;
}
