
#ifndef UNTITLED4_SHIP_H
#define UNTITLED4_SHIP_H


#include "transport.h"
#include <iostream>
#include <fstream>

class Ship : public Transport {
public:
    ~Ship() override = default;

    virtual void ToTransport(std::ifstream &input_stream);

    virtual void OutTransport(std::ofstream &output_stream);

    virtual void ToRandTransport();
private:
    int water_displacement;
    enum ship_type {liner = 1, tugboat, tanker} type_s;
};


#endif //UNTITLED4_SHIP_H
