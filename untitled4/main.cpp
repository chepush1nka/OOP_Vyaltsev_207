#include <iostream>
#include "container.h"
#include "timer.h"
#include "exceptions.h"

/// Метод для сортировки элементов контейнера слиянием (Merge Sort).
/// \param i индекс левой границы.
/// \param j индекс правой границы.
/// \param container контейнер.
/// \param help_container вспомогательный контейнер.
void StraightMerge(int i, int j, Container *container, Container *help_container){
    if (j == -1) {
        j = container->count-1;
    }
    if (j <= i) {
        return;
    }
    int mid = (i + j) / 2;
    // Отправляем на сортировку половинки контейнера.
    StraightMerge(i, mid, container, help_container);
    StraightMerge(mid + 1, j, container, help_container);
    int pointer_left = i;
    int pointer_right = mid + 1;
    int k;
    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) {
            help_container->data[k] = container->data[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) {
            help_container->data[k] = container->data[pointer_left];
            pointer_left++;
        } else if ((container->data[pointer_left])->RoadTime() > (container->data[pointer_right])->RoadTime()) {
            help_container->data[k] = container->data[pointer_left];
            pointer_left++;
        } else {
            help_container->data[k] = container->data[pointer_right];
            pointer_right++;
        }
    }
    for (k = i; k <= j; k++) {
        container->data[k] = help_container->data[k];
    }
}

int main(int argc, char* argv[]) {
    Timer::clockStart = clock();
    if(argc != 4) {
        Exceptions::WrongArguments();
        Timer::TimePrint();
        exit(EXIT_FAILURE);
    }
    Container container = Container();
    if (strcmp(argv[1], "-f") == 0) {
        std::ifstream input_stream;
        input_stream.open(argv[2]);
        if(!input_stream) {
            perror("invalid input file");
            Timer::TimePrint();
            exit(EXIT_FAILURE);
        }
        container.FillCont(input_stream);
    }
    else if(strcmp(argv[1], "-n") == 0) {
        int size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            std::cerr << "the program was waiting for a positive number less than 10000"
                         "as the third argument\n";
            Timer::TimePrint();
            exit(EXIT_FAILURE);
        }
        srand(time(0));
        container.FillContRand(size);
    }
    else {
        Exceptions::WrongMode();
        Timer::TimePrint();
        exit(EXIT_FAILURE);
    }
    std::ofstream output_stream;
    output_stream.open(argv[3]);
    if(!output_stream) {
        perror("invalid output file");
        Timer::TimePrint();
        exit(EXIT_FAILURE);
    }
    container.OutCont(output_stream);
    Container help_container = Container();
    StraightMerge(0, -1, &container, &help_container);
    std::cout << "\n\nBest time:\n";
    output_stream << "\n\nBest time:\n";
    container.OutCont(output_stream);
    Timer::TimePrint();
    return 0;
}