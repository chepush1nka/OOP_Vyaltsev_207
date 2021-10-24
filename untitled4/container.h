#ifndef UNTITLED4_CONTAINER_H
#define UNTITLED4_CONTAINER_H

#include <iostream>
#include "transport.h"

class Container {
public:
    int count;
    Transport**data;
    Container();
    ~Container();

    int AddCont(Transport *transport);

    void FillCont(std::ifstream &input_stream);

    void FillContRand(int count);

    void OutCont(std::ofstream &output_stream);

    void Container::Clear();
};


#endif //UNTITLED4_CONTAINER_H
