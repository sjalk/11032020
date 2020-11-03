#include "nkg.h"
#include "TMath.h"
double NKGVO(double r, double age, double size){
    double rm = 40.;
    double cs = TMath::Gamma(4.5 - age)/(TMath::Gamma(age-0.5)*TMath::Gamma(5.0-2.*age));
    cs = cs/(2*TMath::Pi()*rm*rm);
    return size*cs*TMath::Power(r/rm,age-2.5)*pow(1+r/rm,age-4.5);
}

double NKGV0(double r, double age, double size) {
    double rm = 40.;
    double cs = TMath::Gamma(4.5 - age)/(TMath::Gamma(age-0.5)*TMath::Gamma(5.0-2.*age));
    cs = cs/(2*TMath::Pi()*rm*rm);
    return size*cs*TMath::Power(r/rm,age-2.5)*pow(1+r/rm,age-4.5);
}

double NKGV1(double r, double age, double size) {
    double rm = 130.;
    double cs = TMath::Gamma(4.5-age)/(TMath::Gamma(age-0.5)*TMath::Gamma(5.0-2.*age));
    cs = cs/(2*TMath::Pi()*rm*rm);
    return size*cs*TMath::Power(r/rm,age-2.5)*pow(1+r/rm,age-4.5);
}

