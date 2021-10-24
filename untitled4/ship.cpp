#include "ship.h"
#include "random.h"
#include <string>

/// Считывание данных о новом кыруабле.
/// \param input_stream входной файл.
void Ship::ToTransport(std::ifstream &input_stream) {
    try {
        int type_s;
        input_stream >> type_s >> water_displacement;
    } catch(const std::exception &ex) {
        std::cerr << "invalid ship data";
        Timer::TimePrint();
        exit(EXIT_FAILURE);
    }
}

/// Выводим все, что знаем про кораблик.
/// \param output_stream выходной файл.
void Ship::OutTransport(std::ofstream &output_stream) {
    std::string shipType;
    switch (type_s) {
        case liner:
            shipType = "liner";
            break;
        case tugboat:
            shipType = "tugboat";
            break;
        case tanker:
            shipType = "tanker";
            break;
    }
    std::cout << "SHIP. Speed: " + std::to_string(speed) +
                 ", distance: " + std::to_string(the_road) +
                 ", ship type: " + shipType +
                 ", water_displacement: " + std::to_string(water_displacement) + "\n " +
                 " road time: " + std::to_string(RoadTime()) + "\n";
    output_stream << "SHIP. Speed: " + std::to_string(speed) +
                     ", distance: " + std::to_string(the_road) +
                     ", ship type: " + shipType +
                     ", water_displacement: " + std::to_string(water_displacement) + "\n " +
                     " road time: " + std::to_string(RoadTime()) + "\n";
}

/// Придумываем корабль.
void Ship::ToRandTransport() {
    type_s = static_cast<ship_type>(RandInt(1, 3));
    water_displacement = RandInt(20000, 50000);
}
