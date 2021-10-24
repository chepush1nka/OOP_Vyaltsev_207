#ifndef UNTITLED4_TRANSPORT_H
#define UNTITLED4_TRANSPORT_H

#include <iostream>
#include <fstream>
#include "timer.h"

class Transport {
public:
    enum transport_type_enum {plane = 1, ship, train} transport_type;
    int speed;
    double the_road;
    virtual ~Transport() = default;

    static Transport *StaticToTransport(std::ifstream &input_stream);

    static Transport *StaticToRandTransport();

    double RoadTime() const;

    virtual void ToTransport(std::ifstream &input_stream) = 0;

    virtual void ToRandTransport() = 0;

    virtual void OutTransport(std::ofstream &output_stream) = 0;
};


#endif //UNTITLED4_TRANSPORT_H
