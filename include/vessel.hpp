#ifndef VESSEL_H
#define VESSEL_H

class Vessel{
    private:
        int capacity;

    public:
        Vessel(int capacity);
        ~Vessel();
        int get_capacity();
};

#endif