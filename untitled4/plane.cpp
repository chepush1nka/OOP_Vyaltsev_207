#include "plane.h"
#include "random.h"
#include <string>

/// Считывание данных о новом самолете.
/// \param input_stream входной файл.
void Plane::ToTransport(std::ifstream &input_stream) {
    try {
        input_stream >> flight_range >> load_capacity;
    } catch(const std::exception &ex) {
        std::cerr << "invalid plane data";
        Timer::TimePrint();
        exit(EXIT_FAILURE);
    }
}

/// Выводим все, что знаем про самолет.
/// \param output_stream выходной файл.
void Plane::OutTransport(std::ofstream &output_stream) {
    std::cout << "PLANE. Speed: " + std::to_string(speed) +
                 ", distance: " + std::to_string(the_road) +
                 ", load capacity: " + std::to_string(load_capacity) +
                 ", flight range: " + std::to_string(flight_range) + "\n" +
                 "road time: " + std::to_string(RoadTime()) + "\n";
    output_stream << "PLANE. Speed: " + std::to_string(speed) +
                     ", distance: " + std::to_string(the_road) +
                     ", load capacity: " + std::to_string(load_capacity) +
                     ", flight range: " + std::to_string(flight_range) + "\n" +
                     "road time: " + std::to_string(RoadTime()) + "\n";
}

/// Придумываем самолет.
void Plane::ToRandTransport() {
    flight_range = RandInt(800, 5000);
    load_capacity = RandInt(100, 450);
}