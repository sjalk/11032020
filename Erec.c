#include "Erec.h"
#include "nkg.h"
#include "TMath.h"
/********************  CSZ's work ****************************/
double __p0__[12] = {1.74558, 1.75789, 1.77675, 1.80182, 1.83308, 1.86808, 1.91001, 1.95468, 1.99553, 2.04191, 2.09133, 2.14474};
double __p1__[12] = {0.96475, 0.94221, 0.91961, 0.90142, 0.88660, 0.86839, 0.86159, 0.85272, 0.84218, 0.82113, 0.79659, 0.77589};
double __p2__[12] = {0.02503, 0.02361, 0.02489, 0.02357, 0.02149, 0.02303, 0.01852, 0.01409, 0.01289, 0.02556, 0.03406, 0.03635};


double GetErecCSZ(double lgs50, double theta) {
	int k = int ( (1./cos(theta) - 1)/0.05 );
	if(k < 0) k = 0;
	if(k > 11) k = 11;
	return TMath::Power(10, __p2__[k] * lgs50 * lgs50 + __p1__[k] * lgs50 + __p0__[k]);
}

double GetlgErecCSZ(double lgs50, double theta) {
	int k = int ( (1./cos(theta) - 1)/0.05 );
    if(k < 0) k = 0;
    if(k > 11) k = 11;
    return __p2__[k] * lgs50 * lgs50 + __p1__[k] * lgs50 + __p0__[k];
}

double Getlgs50 (double size, double age) {
    return TMath::Log10(NKGV1(50., age, size));
}
