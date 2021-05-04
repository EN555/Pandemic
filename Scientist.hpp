//
// Created by eviat on 5/3/2021.
//

#ifndef PANDEMIC_A_SCIENTIST_HPP
#define PANDEMIC_A_SCIENTIST_HPP
#include "Player.hpp"


namespace pandemic{

    class Scientist: public Player {
    public:
        Scientist(Board board, City city, int num);
        std::string role() const override{
            return "Scientist";
        }
        Player &discover_cure(Color color) override;
    private:
        int n;
    };
};
#endif //PANDEMIC_A_SCIENTIST_HPP
