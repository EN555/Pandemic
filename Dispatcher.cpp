

#include "Dispatcher.hpp"
using namespace pandemic;
using namespace std;

Dispatcher::Dispatcher(Board board, City city):Player(board, city){
}


Player& Dispatcher::fly_direct(City city){
    //first check if he in research station
    if(board.is_have_have_research_station(current_location)){
        current_location = city;
    }
    //if haven't research station
    if(mine_cards.find(current_location) != mine_cards.end()){  //the card exist in his mine cards
        mine_cards.erase(current_location);
        current_location = city;
        return *this;
    }
    else{
        throw invalid_argument("you can't fly charter to this city!!");
    }
    return  *this;
}