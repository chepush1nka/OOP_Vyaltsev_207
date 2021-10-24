#include "container.h"
#include <string>

/// Конструктор контейнера.
Container::Container(): count{0} {
    data = new Transport*[10000];
}

/// Записывание в контейнер нового элемента.
/// \param transport транспорт.
int Container::AddCont(Transport* transport) {
    int ans = 0;
    if (count >= 10000) {
        ans = -1;
    } else {
        count += 1;
        data[count - 1] = transport;
    }
    return ans;
}

/// Заполнений контейнера данными из файла.
/// \param input_stream входной файл.
void Container::FillCont(std::ifstream &input_stream) {
    Transport *transport;
    while (!input_stream.eof()) {
        if ((transport = Transport::StaticToTransport(input_stream)) != nullptr) {
            AddCont(transport);
        }
    }
}

/// Заполняем контейнер случайными значениями.
/// \param inp_count счетчик объектов для генерации.
void Container::FillContRand(int inp_count) {
    while(count < inp_count) {
        AddCont(Transport::StaticToRandTransport());
    }
}

/// Выводим информацию о контейнере.
/// \param output_stream выходной файл.
void Container::OutCont(std::ofstream &output_stream) {
    if(!output_stream) {
        perror("could not write to file");
        Timer::TimePrint();
        exit(EXIT_FAILURE);
    }
    std::cout << "There are "
                 + std::to_string(count) + " vehicles in the container.\n";
    output_stream << "There are "
                     + std::to_string(count) + " vehicles in the container.\n";

    for(int i = 0; i < count; i++) {
        std::string counter = std::to_string(i + 1) + ": ";
        std::cout << counter;
        output_stream << counter;
        data[i]->OutTransport(output_stream);
    }
}

/// Деструктор контейнера
Container::~Container() {
    Clear();
    delete[] data;
}

/// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for(int i = 0; i < count; i++) {
        delete data[i];
    }
    count = 0;
}