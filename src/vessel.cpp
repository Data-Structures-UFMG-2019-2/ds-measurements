#include"../include/vessel.hpp"

Vessel::Vessel(int capacity){
    this->capacity = capacity;
}

Vessel::~Vessel(){
}

int Vessel::get_capacity(){
    return this->capacity;
}