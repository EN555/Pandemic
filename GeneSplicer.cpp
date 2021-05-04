#include "GeneSplicer.hpp"
#include "Color.hpp"
#include "City.hpp"

using namespace std;
using namespace pandemic;


GeneSplicer::GeneSplicer(Board board, City city):Player(board,city){
}

Player& GeneSplicer::discover_cure(Color color){

    if (!board.is_have_cure_desease(color) &&
        board.is_have_have_research_station(current_location)) { //check if already have cure for this
        //and have research station
        if (mine_cards.size() < 5) {
            throw invalid_argument("you havn't enough cards!!");
        } else {
            std::set <City> new_mine;
            int number = mine_cards.size() - 5;
            int counter = 0;
            for (auto it = mine_cards.begin(); it != mine_cards.end(); ++it) {
                if (counter < number) {
                    counter++;
                    new_mine.insert(*it);
                }
                mine_cards = new_mine;  //The cards
            }
        }
    }
    return *this;
}
