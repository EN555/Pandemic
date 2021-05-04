//
// Created by eviat on 5/2/2021.
//

#ifndef PANDEMIC_A_VIROLOGIST_HPP
#define PANDEMIC_A_VIROLOGIST_HPP
#include "Player.hpp"


namespace pandemic{

    class Virologist: public Player {
    public:
        Virologist(Board board, City city);
        std::string role() const override{
            return "Virologist";
        }
        Player &treat(City city) override;

    };
};

#endif //PANDEMIC_A_VIROLOGIST_HPP
