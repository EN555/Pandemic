#include "Virologist.hpp"
#include "Color.hpp"

using namespace pandemic;
using namespace std;


Virologist:: Virologist(Board board, City city):Player(board,city){}


Player& Virologist::treat(City city){
    Color color = board.city_to_color(city);

    board[city] =0 ;
    if(board[city] == 0){
        throw invalid_argument("The city is already clean!!");
    }
    if(board.is_have_cure_desease(color)) {  //check if found cure to this color

        board[city] = 0;
    }
    else{
        if(mine_cards.find(city) != mine_cards.end()){   //check if he have this card city
            mine_cards.erase(city);     //remove this card
            board[city] = 0;
        }
    }
    return *this;
}