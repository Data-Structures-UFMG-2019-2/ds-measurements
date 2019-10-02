#ifndef OPERATION_H
#define OPERATION_H

#include"./vessel.hpp"

#define SUBTRACT (-1)
#define ADD (1)

class Operation{
    private:
        int vessel_amount;
        int measured_amount;
    public:
        Operation(int type, Vessel* vessel, int amount);
        ~Operation();
        int get_measured_amount();
};

#endif