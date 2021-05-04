//
// Created by eviat on 5/2/2021.
//

#ifndef PANDEMIC_A_RESEARCHER_HPP
#define PANDEMIC_A_RESEARCHER_HPP

#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Researcher: public Player {
    public:
        Researcher(Board board, City city);
        std::string role() const override{
            return "Researcher";
        }
        Player &discover_cure(Color color) override;

    };
};
#endif //PANDEMIC_A_RESEARCHER_HPP
