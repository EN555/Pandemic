//
// Created by eviat on 5/2/2021.
//

#ifndef PANDEMIC_A_OPERATIONEXPERT_HPP
#define PANDEMIC_A_OPERATIONEXPERT_HPP

#include "Player.hpp"


namespace pandemic{

    class OperationsExpert: public Player {
    public:
        OperationsExpert(Board board, City city);
        std::string role() const override{
            return "OperationExpert";
        }
        Player &build() override;

    };
};
#endif //PANDEMIC_A_OPERATIONEXPERT_HPP
