#include "Board.hpp"
#include<fstream>
#include <string>
#include <exception>

using namespace pandemic;
using namespace std;

Board::Board() {
//first insert all the connections then insert the colors
    std::ifstream file{"cities_map.txt"};
    std::string city, color, connection;

    while(!file.eof()){
        file >> city >> color;
        //insert the color
        city_color.insert({cities[city],color});
        //insert the connection
        std::set<City> conc={};
        desease_intense.insert({cities[city],0});
        getline(file, connection);
        stringstream ss;
        ss <<connection;
        string partial;
        while(ss >> partial){    //insert all the connections cities to center city
            connections[cities[city]].insert(cities[partial]);
        }
    }
}
ostream& pandemic::operator<<(ostream& os, Board &board) {    //need to add research stations and is found cure for the deseases
    //intensity of the pandemic in every city
    cout<< "The intensity of the pandemic in every city"<<endl;
    for(auto it = board.desease_intense.begin(); it != board.desease_intense.end(); ++it) {
      City place = it -> first;
      string loc;
        for(auto it_city = board.cities.begin(); it_city != board.cities.end(); ++it_city){
            if(it_city ->second == place){
                loc = it_city -> first;
                break;
            }
        }
        cout<<"The City is: "<< loc << " The Intense of The desease is: "<< it->second <<endl;
    }
    //the cure that already discover
    cout<< "The cure that already discover"<<endl;
    for(auto it = board.is_have_cure.begin(); it != board.is_have_cure.end(); ++it) {
        Color color = *it;
        string str_color;
        for(auto it_color = board.Colors.begin(); it_color != board.Colors.end(); ++it_color){
            if(it_color ->second == color){
                str_color = it_color -> first;
                break;
            }
        }
        cout<<"The Color is: "<< str_color <<endl;
    }

    //the research station that built
    cout<< "The research station that built"<<endl;
    for(auto it = board.research_station.begin(); it != board.research_station.end(); ++it) {
        City place = *it;
        string loc;
        for(auto it_city = board.cities.begin(); it_city != board.cities.end(); ++it_city){
            if(it_city ->second == place){
                loc = it_city -> first;
                break;
            }
        }
        cout<<"The City is: "<< loc <<endl;
    }

    return os;
}

int& Board::operator[](City city) {
    return desease_intense[city];
}

bool Board::is_clean(){
    return desease_intense.empty();  //check if the is empty
}

void Board::remove_cures(){
    is_have_cure.clear();   //remove all from the map
}

void Board::add_research_station(City city) {  //add research station for city
    research_station.insert(city);
}

void Board::add_cure_for_color(Color color){  //add cure for desease
    is_have_cure.insert(color);
}

bool Board::is_connected(City city1, City city2){  //check if the current location connect to this location
    auto ptr = connections.find(city1)->second;
    if(ptr.find(city2) != ptr.end()){
        return true;
    }
    return false;
}

bool Board::is_have_have_research_station(City city){
    if(research_station.find(city) !=research_station.end()){
        return true;
    }
    else{
        return false;
    }
}

bool Board::is_have_cure_desease(Color color){
    if(is_have_cure.find(color) == is_have_cure.end()){ //didn't yet cure for this desease
        return false;
    }
    return true;
}

Color Board::city_to_color(City city){
    string color;
    color = city_color.find(city) ->second;
    return Colors.find(color) -> second;
}

