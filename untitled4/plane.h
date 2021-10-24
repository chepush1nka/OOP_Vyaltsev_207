#ifndef UNTITLED4_PLANE_H
#define UNTITLED4_PLANE_H

#include "transport.h"
#include <iostream>

class Plane : public Transport {
public:
    ~Plane() override = default;

    virtual void ToTransport(std::ifstream &input_stream);

    virtual void OutTransport(std::ofstream &output_stream);

    virtual void ToRandTransport();
private:
    int flight_range, load_capacity;
};


#endif //UNTITLED4_PLANE_H
