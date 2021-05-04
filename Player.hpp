//
// Created by eviat on 5/2/2021.
//

#ifndef PANDEMIC_A_PLAYER_HPP
#define PANDEMIC_A_PLAYER_HPP

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic {
    class Player {
    public:
        Player(Board& board, City city);
        virtual std::string role() const = 0;   // abstract function- without body
        virtual Player &take_card(City city);
        virtual Player &drive(City city);
        virtual Player &fly_direct(City city);
        virtual Player &fly_charter(City city);
        virtual Player &fly_shuttle(City city);
        virtual Player &build();
        virtual Player &discover_cure(Color color);
        virtual Player &treat(City city);

    protected:
        Board board;
        std::set <City> mine_cards;      //the sets of city that the player hold
        City current_location;   //the current location of the player
    };
}

#endif //PANDEMIC_A_PLAYER_HPP
