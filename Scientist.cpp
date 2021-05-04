


#include "Board.hpp"
#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

Scientist::Scientist(Board board, City city, int num):Player(board,city), n(num){
}

Player& Scientist::discover_cure(Color color){
    int number_color = 0;
    if (!board.is_have_cure_desease(color) &&
        board.is_have_have_research_station(current_location)) { //check if already have cure for this
        //and have research station
        for (auto it = mine_cards.begin(); it != mine_cards.end(); ++it) {
            if (board.city_to_color(*it) == color) {
                number_color++;
            }
        }
        if(number_color < n){
            throw invalid_argument("you havn't enough cards!!");
        }
    }
    std::set<City> new_mine;
    if (number_color >= n) {
        for (auto it = mine_cards.begin(); it != mine_cards.end(); ++it) {
            if (board.city_to_color(*it) != color || number_color >= n) {
                new_mine.insert(*it);
            }
        }
        mine_cards = new_mine;  //The cards
    }

    return *this;
}