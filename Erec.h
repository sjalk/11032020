#ifndef Erec_H
#define Erec_H 1

extern double __p0__[12];// = {1.74558, 1.75789, 1.77675, 1.80182, 1.83308, 1.86808, 1.91001, 1.95468, 1.99553, 2.04191, 2.09133, 2.14474};
extern double __p1__[12];//= {0.96475, 0.94221, 0.91961, 0.90142, 0.88660, 0.86839, 0.86159, 0.85272, 0.84218, 0.82113, 0.79659, 0.77589};
extern double __p2__[12];//= {0.02503, 0.02361, 0.02489, 0.02357, 0.02149, 0.02303, 0.01852, 0.01409, 0.01289, 0.02556, 0.03406, 0.03635};

double GetErecCSZ(double lgs50, double theta);

double GetlgErecCSZ(double lgs50, double theta);

double Getlgs50 (double size, double age);

#endif
