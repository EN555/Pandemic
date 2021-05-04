#include "Medic.hpp"
#include "Color.hpp"
#include "City.hpp"

using namespace pandemic;
using namespace std;



Medic::Medic(Board board, City city):Player(board, city){
}



Player& Medic::treat(City city){
    Color color = board.city_to_color(city);
    if(board[city] == 0){
        throw invalid_argument("The city is already clean!!");
    }
        board[city] = 0;    //remove all the cubes
    return *this;
}

Player& Medic::fly_direct(City city){
    if(mine_cards.find(city) != mine_cards.end()){  // find the card
        mine_cards.erase(city); //remove the card
        current_location = city;
        treat_city(current_location);
        return *this;
    }
    else{
        throw invalid_argument("you can't fly direct to this city!!");
    }
}
Player& Medic::fly_charter(City city){
    if(mine_cards.find(current_location) != mine_cards.end()){  //the card exist in his mine cards
        mine_cards.erase(current_location);
        current_location = city;
        treat_city(current_location);
        return *this;
    }
    else{
        throw invalid_argument("you can't fly charter to this city!!");
    }
}
Player& Medic::fly_shuttle(City city){
    if(board.is_have_have_research_station(city) && board.is_have_have_research_station(current_location)){
        current_location = city;
        treat_city(current_location);
        return *this;
    }
    else{
        throw invalid_argument("you can't fly shuttle to this city!!");
    }
}

void Medic::treat_city(City city){
    if(board[city] != 0){   //check if any desease to care
        Color color = board.city_to_color(city);
        if(board.is_have_cure_desease(color)){    //if already found care to this desease
            board[city] = 0;
        }
    }
}