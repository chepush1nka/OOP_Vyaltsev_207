#include "timer.h"
#include "stdio.h"
clock_t Timer::clockStart;
clock_t Timer::clockEnd;

/// Вывод информации о времени работы программы.
void Timer::TimePrint() {
    clockEnd = clock();
    float seconds = (float)(clockEnd - clockStart) / CLOCKS_PER_SEC;
    fprintf(stdout, "The program has worked for %.9g seconds\n", seconds);
}