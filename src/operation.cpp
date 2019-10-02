#include"../include/operation.hpp"

Operation::Operation(int vessel_amount, int measured_amount){
    this->vessel_amount = vessel_amount;
    this->measured_amount = measured_amount;
}

Operation::~Operation(){

}

int Operation::get_measured_amount(){
    return this->measured_amount;
}