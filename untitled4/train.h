#ifndef UNTITLED4_TRAIN_H
#define UNTITLED4_TRAIN_H


#include "transport.h"
#include <iostream>

class Train : public Transport {
public:
    ~Train() override = default;

    virtual void ToTransport(std::ifstream &input_stream);

    virtual void OutTransport(std::ofstream &output_stream);

    virtual void ToRandTransport();
private:
    int number_of_wagons;
};


#endif //UNTITLED4_TRAIN_H
