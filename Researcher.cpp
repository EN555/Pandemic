#include "Board.hpp"
#include "Researcher.hpp"

using namespace std;
using namespace pandemic;

Researcher::Researcher(Board board, City city):Player(board, city){
}

Player& Researcher::discover_cure(Color color){
    int number_color = 0;
    if (!board.is_have_cure_desease(color)){ //check if already have cure for this
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