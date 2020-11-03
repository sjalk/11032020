#include"TROOT.h"
#include"TH1D.h"
#include"TChain.h"
#include"TCanvas.h"
#include"TFile.h"
#include"TTree.h"
#include<iostream>
#include<fstream>
#include<math.h>
#include"TLegend.h"
#include"stdio.h"
#include <string>
#include "WCDAEvent.h"
using namespace std;

void npecheck(){
//int main(){
   ifstream infile;
   //infile.open("/afs/ihep.ac.cn/users/g/gaowk1/eos/015937.txt");
   cout<<"Please put the path and total lines of infile here, and then press 'enter'"<<endl;
   string infile_path;
   int nevent;
   cin>>infile_path>>nevent;
   infile.open(infile_path);
   if(!infile){
   cout<<"Unable to open infile!!!"<<endl;
   exit(1);//terminate with error
   }
  // infile.open("/afs/ihep.ac.cn/users/g/gaowk1/eos/015937_direct_select_large.txt");
   
   TCanvas *c1 = new TCanvas("c1","deltat&&npe",200,10,700,500);
   //c1->SetLogy();
   int nbins=10000;
   double xmin=70000;
   double xmax=80000;
   int pebins=50;
   double pemin=-0.5,pe[51];
   double pestep=0.05;
   for(int i=0;i<=pebins;i++){pe[i]=pemin+pestep*i;}
   TH1D *h = new TH1D("h","deltat",nbins,xmin,xmax);
   TH1D *h1= new TH1D("h1","",nbins,xmin,xmax);
   TH1D *hpe = new TH1D("hpe","npe",pebins,pe);
   int k=0;
   //int nevent=471649;//430816;//1228910;//1204789;
   double kT,wT,deltat,deltatnew,npe,dT;
   int a,wE,kE,hitig;
   while(!infile.eof()&&(k<nevent))//read txt fie and put data into variables.
   {
   infile>>kT>>wT>>deltat>>deltatnew>>npe>>wE>>kE>>hitig;
   //dT=(wT-kT)*1000000000;
   //h->Fill(deltatnew*1000000000);
   //if(wE == 538515)h1->Fill(deltat*1e9,100);
   if(deltat*1e9>-1200&&deltat*1e9<-900){h->Fill(kE);}
   if(deltat*1e9>-600&&deltat*1e9<800)hpe->Fill(log10(npe));
   k++;
   }
   /*
   TFile* a = new TFile("/eos/lhaaso/simulation/wcdamc/g4wcda/data/20191122/1122/ES.30298.WCDA_EVENT.P1GRBM20M.20191122000115.1387.root");
   TTree* t = (TTree*)a->Get("wcda");
   WCDAEvent* wcda = new WCDAEvent(t);
   wcda->
   */
   cout<<"Please Input the option: t or q."<<"\n"<<"t---time"<<"\n"<<"q---charge"<<endl;
   char option;
   cin>>option;
   if(option=='t'){
   //draw deltat
   //for(int i=180;i<210;i++)cout<<h->GetBinContent(i)<<"  "<<i<<endl;
   cout<<" Drawing deltat distri."<<endl;
   h->Draw("");
   h1->Draw("Psame");
   h1->Sumw2();
   h->Sumw2();
   h->SetLineColor(kRed);
	//h->Scale(1/h->Integral());
   h->SetMarkerStyle(7);
   h->SetMarkerColor(kRed);
   h->GetXaxis()->SetTitle("deltat[ns]");
       // h->GetYaxis()->SetTitle("norm hits");
   }

   if(option=='q'){
   //draw npe
   cout<<"Drawing Npe distri."<<endl;
   hpe->Draw("E");
   hpe->Sumw2();
   hpe->SetLineColor(kRed);
       hpe->Scale(1/hpe->Integral());
   hpe->SetMarkerStyle(7);
   hpe->SetMarkerColor(kRed);
   hpe->GetXaxis()->SetTitle("log_{10}npe");
      // h->GetYaxis()->SetTitle("norm hits");
   }
   infile.close();
}
