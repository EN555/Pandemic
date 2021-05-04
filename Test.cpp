#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Scientist.hpp"
#include "Researcher.hpp"
#include "Virologist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "Medic.hpp"
#include "doctest.h"

using namespace pandemic;
using namespace std;

TEST_CASE("Board"){    //check the board part
//check the constructor
Board board;
//Taipei Red Shanghai HongKong Osaka Manila - check connected places
CHECK(board.is_connected(City::Taipei, City::Shanghai)==true);
CHECK(board.is_connected(City::Taipei, City::HongKong)==true);
CHECK(board.is_connected(City::Taipei, City::Osaka)==true);
CHECK(board.is_connected(City::Taipei, City::Manila)==true);
//Sydney Red Jakarta Manila LosAngeles - check not connected places
CHECK_FALSE(board.is_connected(City::Taipei, City::Jakarta));
CHECK_FALSE(board.is_connected(City::Taipei, City::LosAngeles));
//check is_clean
CHECK(board.is_clean()==true);
//check remove curses method
CHECK_NOTHROW(board.remove_cures());
//check research station methods
CHECK_FALSE(board.is_have_have_research_station(City::Shanghai));
CHECK_FALSE(board.is_have_have_research_station(City::HongKong));
CHECK_FALSE(board.is_have_have_research_station(City::Osaka));
CHECK_FALSE(board.is_have_have_research_station(City::Manila));
board.add_research_station(City::Shanghai);
CHECK(board.is_have_have_research_station(City::Shanghai)==true);
CHECK_FALSE(board.is_have_have_research_station(City::HongKong));
board.add_research_station(City::HongKong);
CHECK(board.is_have_have_research_station(City::HongKong)==true);
board.add_research_station(City::HongKong);
board.add_research_station(City::HongKong);
CHECK(board.is_have_have_research_station(City::HongKong)==true);
CHECK(board.is_have_have_research_station(City::HongKong)==true);
//check cure desease methods
CHECK_FALSE(board.is_have_cure_desease(Color::Yellow));
CHECK_FALSE(board.is_have_cure_desease(Color::Red));
CHECK_FALSE(board.is_have_cure_desease(Color::Black));
CHECK_FALSE(board.is_have_cure_desease(Color::Blue));
board.add_cure_for_color(Color::Yellow);
board.add_cure_for_color(Color::Red);
board.add_cure_for_color(Color::Black);
board.add_cure_for_color(Color::Blue);
CHECK(board.is_have_cure_desease(Color::Yellow)==true);
CHECK(board.is_have_cure_desease(Color::Red)==true);
CHECK(board.is_have_cure_desease(Color::Black)==true);
CHECK(board.is_have_cure_desease(Color::Blue)==true);

}
