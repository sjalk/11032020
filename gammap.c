#include "gammap.h"

double GetEstUpLimit(double lgErec) {
    if(lgErec < 1. || lgErec >= 3.2) return -2.36;
    else {
        int iE = int((lgErec - 1.)/0.2);
        return __EST__[iE];
    }
}
