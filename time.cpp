#include "hpatimer.h"
#include "WCDAEvent.h"
#include <iostream>
#ifndef WCDAEvent_cxx
#define  WCDAEvent_cxx
using namespace std;
void time(){
	TFile*a = new TFile("ES.36180.WCDA_EVENT.P1GRBM20M.20200101102940.523.dat.root");
	TTree* t =(TTree*)a->Get("wcda");
	//KM2AReader km2a;
	//km2a.Init(t);
	WCDAEvent* wcda = new WCDAEvent(t);
	
	//hits.second%86400)+(hits.low_th_fine_time*0.333+16*hits.coarse_time)*1e-9
	
	
	for(int i=0;i<t->GetEntries();i++){
	wcda->GetEntry(i);
	for(int j=0;j<wcda->nhit;j++){
	double a = wcda->hits_low_th_fine_time[j]/3+wcda->hits_coarse_time[j]*16;
	Ttai_t tai;Tmjd_t mjd1;
	tai.assign(wcda->hits_second[j],a);
	mjd1.assign(tai);
	double mjd = mjd1.unpack();
	cout<<setprecision(16)<<mjd<<endl;
	}}
}
