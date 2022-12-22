#ifndef FIRSTPROJECT_PLANE_H
#define FIRSTPROJECT_PLANE_H


#include <iostream>
#include <cstring>
#include <map>
#include "map"
#include "vector"
#include <sstream>
#include <string>
#include <utility>
#include <cstring>

using namespace std;

class Plane{
    map<string,bool> places;
    map<string,int> prices;
    string date;
    string name;

public:

    Plane(string& date, string& name, int rows, string& first, string& last, int firstPrice, int lastPrice){
        std::vector<string> row = split(first ,"-") ;
        std::vector<string> rowLast = split(last ,"-") ;
        this->date = date;
        this->name = name;

        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(int i = 0; i < rows; i++){
            char letter = alphabet[i];

            int firstSeat = stoi(row[0]);
            int lastSeat = stoi(row[1]);

            for(int j= firstSeat; j <= lastSeat; j++){
                string seatNumber = letter + to_string(j);
                places.insert({seatNumber, false});
                prices.insert({seatNumber, firstPrice});
            }

            firstSeat = stoi(rowLast[0]);
            lastSeat = stoi(rowLast[1]);
            for(int j = firstSeat; j <= lastSeat; j++){
                string seatNumber = letter + to_string(j);
                places.insert({seatNumber, false});
                prices.insert({seatNumber, lastPrice});
            }
        }
    };

    void check() {
        for (const auto& place: places) {
            if (!place.second) {
                cout << place.first<< " " << prices.at(place.first) << "$" << endl;
            }
        }
        cout << endl;

    };

    int book(const string& seatName){
        if(places.at(seatName)){
            cout << "This seat is already booked!" << endl;
            throw invalid_argument("This seat is already booked!");
        }
        places.at(seatName) = true;
        return prices.at(seatName);
    };
    void returnTicket(const string& seatName){
        places.at(seatName) = false;
    };
    int getPrice(const string& seatName){
        return prices.at(seatName);
    };
    string getDate() {

        return date;
    };

    string getNumber() {
        return name;
    };


private:
    static std::vector<std::string> split(std::string& str, const char* delim) {
        std::vector<std::string> result;
        std::stringstream ss(str);
        std::string token;
        while (std::getline(ss, token, *delim)) {
            result.push_back(token);
        }
        return result;
    }
};


#endif //FIRSTPROJECT_PLANE_H