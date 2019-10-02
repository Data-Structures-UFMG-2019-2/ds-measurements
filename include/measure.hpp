#ifndef MEASURE_H
#define MEASURE_H

#include"./linked_list.hpp"
#include"./stack.hpp"
#include"./vessel.hpp"

class Measure{
    private:
        
    public:
        Measure();
        ~Measure();
        static void add_vessel(LinkedList<Vessel>* vessels, int q);
        static void remove_vessel(LinkedList<Vessel>* vessels, int q);
        static int min_measure(LinkedList<Vessel>* vessels, int q);
        static void execute(LinkedList<Vessel>* vessels, char type, int q);
        static void print_vessels(LinkedList<Vessel>* vessels);
};

#endif