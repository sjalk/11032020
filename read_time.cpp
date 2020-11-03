#define KM2AEvent_cxx
#include<TFile.h>
#include"KM2AEvent.h"

void read_time(){

	TFile* km2af = new
	TFile("/eos/lhaaso/rec/km2a/half_array/2020_V1/0112/ES.37661.KM2A_EVENT.PHYSIC_HALF_EDMD_OVERLAP.20200112015937.018.dat.root");
	TTree* km2at = (TTree*)km2af->Get("nt1");
	KM2AEvent* km2a = new KM2AEvent(km2at);
	int kNum = km2at->GetEntries();
	double ne,nu ;
	TH2D* h = new TH2D("h","",2000,0,2000,1000,0,1000);
	for(int k = 1;k<kNum;k++){
	km2a->GetEntry(k);
	ne= km2a->NpE3;
	nu= km2a->NuM4;
	h->Fill(ne,nu);
	}
	h->GetXaxis()->SetTitle("ne");
	h->GetYaxis()->SetTitle("nu");
	h->Draw("");
}
