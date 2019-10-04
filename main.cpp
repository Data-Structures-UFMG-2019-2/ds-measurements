#include<iostream>
#include"./include/linked_list.hpp"
#include"./include/vessel.hpp"
#include"./include/measure.hpp"

int main(){
    int q;
    char type;
    LinkedList<Vessel>* vessels = new LinkedList<Vessel>();

    while(scanf("%d %c", &q, &type) != EOF) {
        Measure::execute(vessels, type, q);
    }

    vessels->clear();
    delete vessels;
    
    return 0;
}
