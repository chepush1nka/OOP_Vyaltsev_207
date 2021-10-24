#include "transport.h"
#include "plane.h"
#include "ship.h"
#include "train.h"
#include "random.h"

/// Считывание данных о новом транспорте.
/// \param input_stream входной файл.
Transport *Transport::StaticToTransport(std::ifstream &input_stream) {
    Transport *transport = nullptr;
    int transport_type, speed;
    double the_road;
    input_stream >> transport_type >> speed >> the_road;
    switch (transport_type) {
        case plane:
            transport = new Plane();
            break;
        case ship:
            transport = new Ship();
            break;
        case train:
            transport = new Train();

            break;
        default:
            delete transport;
            std::cerr << "invalid transport data";
            Timer::TimePrint();
            exit(EXIT_FAILURE);
    }
    if (speed < 1 || the_road < 1){
        delete transport;
        std::cerr << "invalid transport data";
        Timer::TimePrint();
        exit(EXIT_FAILURE);
    }
    transport->speed = speed;
    transport->the_road = the_road;
    transport->ToTransport(input_stream);
    return transport;
}

/// Рандомно генерируем данные о транспортных средствах.
Transport *Transport::StaticToRandTransport() {
    Transport *transport = nullptr;

    int transport_type = RandInt(1, 3);
    switch (transport_type) {
        case 1:
            transport = new Plane();
            break;
        case 2:
            transport = new Ship();
            break;
        case 3:
            transport = new Train();
            break;
    }
    transport->speed = RandInt(1, 200);
    transport->the_road = RandInt(5, 2000);
    transport->ToRandTransport();
    return transport;
}

/// Получаем время пути.
/// \param transport транспорт.
double Transport::RoadTime() const {
    return the_road / speed;
}