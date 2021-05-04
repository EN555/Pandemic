#include "OperationsExpert.hpp"
#include "Color.hpp"
#include "City.hpp"
using namespace pandemic;
using namespace std;

OperationsExpert::OperationsExpert(Board board, City city): Player(board,city){}
//const std::string OperationsExpert::role(Board board,City city) const{
//    return "OperationExpert";
//}
Player& OperationsExpert::build(){
    if(!board.is_have_have_research_station(current_location)){  //and havn't research station at current city
        board.add_research_station(current_location);
        return *this;
    }
    return *this;
}
