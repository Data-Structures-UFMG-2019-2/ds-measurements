#ifndef OPERATION_H
#define OPERATION_H

#include"./vessel.hpp"

class Operation{
    private:
        int vessel_amount;
        int measured_amount;
    public:
        Operation(int vessel_amount, int measured_amount);
        ~Operation();
        int get_measured_amount();
};

#endif