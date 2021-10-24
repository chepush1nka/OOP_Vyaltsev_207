#include "train.h"
#include "random.h"
#include <string>

/// Считывание данных о новом кыруабле.
/// \param input_stream входной файл.
void Train::ToTransport(std::ifstream &input_stream) {
    try {
        input_stream >> number_of_wagons;
    } catch(const std::exception &ex) {
        std::cerr << "invalid train data";
        Timer::TimePrint();
        exit(EXIT_FAILURE);
    }
}

/// Выводим все, что знаем про поезд.
/// \param output_stream выходной файл.
void Train::OutTransport(std::ofstream &output_stream) {
    std::cout << "TRAIN. Speed: " + std::to_string(speed) +
                 ", distance: " + std::to_string(the_road) +
                 ", number of wagons: " + std::to_string(number_of_wagons) + "\n " +
                 " road time: " + std::to_string(RoadTime()) + "\n";
    output_stream << "TRAIN. Speed: " + std::to_string(speed) +
                     ", distance: " + std::to_string(the_road) +
                     ", number of wagons: " + std::to_string(number_of_wagons) + "\n " +
                     " road time: " + std::to_string(RoadTime()) + "\n";
}

/// Придумываем поезд.
void Train::ToRandTransport() {
    number_of_wagons = RandInt(5, 30);
}