
#include "FieldDoctor.hpp"
#include<exception>

using namespace pandemic;
using namespace std;


FieldDoctor::FieldDoctor(Board board, City city):Player(board,city){
}

Player& FieldDoctor::treat(City city){
    if(board[city] == 0){
        throw invalid_argument("No what to decrease!!");
    }
    //check if the city close to him
    if(current_location == city || board.is_connected(current_location, city)){
        board[city] =0;
    }
    return *this;
}