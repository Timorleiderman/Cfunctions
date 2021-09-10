#include "mult.h"


int multiply(int x, int y) {
    if (y > 0) {
        return x + multiply(x, y - 1);
    }
    else if (y < 0) {
        return -x + multiply(x, y + 1);
    }

    return 0;
}
