#include<iostream>
#include"./include/linked_list.hpp"
#include"./include/stack.hpp"
#include"./include/vessel.hpp"
#include"./include/measure.hpp"

int main(int argc, char const *argv[]){
    int q;
    char type;
    LinkedList<Vessel>* vessels = new LinkedList<Vessel>();

    while(scanf("%d %c", &q, &type) != EOF) {
        Measure::execute(vessels, type, q);

        int cell_i = 0;
        std::cout << '[';
        for (Cell<Vessel>* it = vessels->begin(); it != nullptr; it = it->get_next(), cell_i++){
            Vessel* vessel = it->get_object();
            if(vessel != nullptr){
                if(cell_i > 0){
                    std::cout << ", ";
                }
                std::cout << vessel->get_capacity();
            }
        }
        std::cout << ']' << std::endl;
    }

    vessels->clear();
    delete vessels;
    
    return 0;
}
