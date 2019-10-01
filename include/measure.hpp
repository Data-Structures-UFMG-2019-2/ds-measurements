#include"./stack.hpp"
#include"./vessel.hpp"

class Measure{
    private:
        Stack<Vessel> vessels;
        int measured_amount;
    public:
        Measure();
        ~Measure();
};

Measure::Measure(){
}

Measure::~Measure(){
}
