#include "random.h"
#include <stdlib.h>
#include <assert.h>

int RandInt(const int lowerBound, const int upperBound) {
    assert(lowerBound <= upperBound);
    return (rand() % (upperBound - lowerBound + 1)) + lowerBound;
}