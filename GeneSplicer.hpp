//
// Created by eviat on 5/2/2021.
//

#ifndef PANDEMIC_A_GENESPLICER_HPP
#define PANDEMIC_A_GENESPLICER_HPP
#include "Player.hpp"


namespace pandemic{

    class GeneSplicer: public Player {
    public:
        GeneSplicer(Board board, City city);
        std::string role() const override{
            return "GeneSplicer";
        }
        Player &discover_cure(Color color) override;

    };
};

#endif //PANDEMIC_A_GENESPLICER_HPP
