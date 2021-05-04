//
// Created by eviat on 5/2/2021.
//

#ifndef PANDEMIC_A_MEDIC_HPP
#define PANDEMIC_A_MEDIC_HPP
#include "Player.hpp"


namespace pandemic{

    class Medic: public Player {
    public:
        Medic(Board board, City city);
        std::string role() const override{
            return "Medic";
        }
        Player &treat(City city) override;
        Player &fly_direct(City city) override;
        Player &fly_charter(City city) override;
        Player &fly_shuttle(City city) override;
    private:
        void treat_city(City city);
    };
};
#endif //PANDEMIC_A_MEDIC_HPP
