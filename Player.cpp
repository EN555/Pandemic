#include "Player.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"
#include <exception>
#include <iostream>

using namespace pandemic;
using namespace std;

Player::Player(Board& board, City city){
    this ->board = board;
    this ->current_location = city;
}

Player& Player::take_card(City city){
    if(mine_cards.find(city) == mine_cards.end()){  //so he can take this card
        mine_cards.insert(city);
        return *this;
    }
    else{
        throw invalid_argument("you can't take this card!!");   //the card already took
    }
}

Player& Player::drive(City city){
    if(board.is_connected(current_location, city)){
        current_location = city;
        return *this;
    }
    else{
        throw invalid_argument("you can't drive to this city!!");
    }
}

Player& Player::fly_direct(City city){
    if(mine_cards.find(city) != mine_cards.end()){  // find the card
        mine_cards.erase(city); //remove the card
        current_location = city;
        return *this;
    }
    else{
        throw invalid_argument("you can't fly direct to this city!!");
    }
}
Player& Player::fly_charter(City city){
    if(mine_cards.find(current_location) != mine_cards.end()){  //the card exist in his mine cards
        mine_cards.erase(current_location);
        current_location = city;
        return *this;
    }
    else{
        throw invalid_argument("you can't fly charter to this city!!");
    }
}
Player& Player::fly_shuttle(City city){
    if(board.is_have_have_research_station(city) && board.is_have_have_research_station(current_location)){
        current_location = city;
        return *this;
    }
    else{
        throw invalid_argument("you can't fly shuttle to this city!!");
    }
}
Player& Player::build(){
    if(mine_cards.find(current_location) != mine_cards.end()) {   //holds at this card
            if(!board.is_have_have_research_station(current_location)){  //and havn't research station at current city
                   board.add_research_station(current_location);
                   return *this;
            }
    }
    if(board.is_have_have_research_station(current_location)){
        return *this;
    }
    throw invalid_argument("you havn't the card!!");

}

Player& Player::discover_cure(Color color) {
    int number_color = 0;
    if (!board.is_have_cure_desease(color) &&
        board.is_have_have_research_station(current_location)) { //check if already have cure for this
                                                                    //and have research station
        for (auto it = mine_cards.begin(); it != mine_cards.end(); ++it) {
            if (board.city_to_color(*it) == color) {
                number_color++;
            }
        }
        if(number_color < 5){
                throw invalid_argument("you havn't enough cards!!");
        }
    }
    std::set<City> new_mine;
    if (number_color >= 5) {
        for (auto it = mine_cards.begin(); it != mine_cards.end(); ++it) {
            if (board.city_to_color(*it) != color || number_color >= 5) {
                new_mine.insert(*it);
            }
        }
    mine_cards = new_mine;  //The cards
    }

    return *this;
}

Player& Player::treat(City city) {
    Color color = board.city_to_color(city);
    if(board[city] == 0){
        throw invalid_argument("The city is already clean!!");
    }
    if(board.is_have_cure_desease(color)) {  //check if found cure to this color

        board[city] = 0;
    }
    else{
        board[city] -=1;
    }
        return *this;
}