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

void deltat_npe(){
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
   double xk,yk;
   for(int i=0;i<=pebins;i++){pe[i]=pemin+pestep*i;}
   TH1D *h = new TH1D("h","",1000,0,3000);
   TH1D *h1= new TH1D("h1","",nbins,xmin,xmax);
   TH1D *hpe = new TH1D("hpe","npe",pebins,pe);
   TH2D *core = new TH2D("core","",1200,-600,600,1200,-600,600);
   TH2D *core1 = new TH2D("core1","",1200,-600,600,1200,-600,600);
   TH1D* angle =  new TH1D("angle","",30,0,60);
   for(int i=0;i<30;i++){
   for(int j=0;j<30;j++){
   xk=((i*5)-72.5-75.5)*0.491542+((j*5)-72.5-56.)*0.870854;
   yk=-((j*5)-72.5-56.)*0.491542+((i*5)-72.5-75.5)*0.870854;
   core1->Fill(yk,xk);
   }
   }
   int k=0;
   //int nevent=471649;//430816;//1228910;//1204789;
   double xc,yc,zen,azi;
   int a,wE,kE,hitig,nmuon,knhit;
   while(!infile.eof()&&(k<nevent))//read txt fie and put data into variables.
   {
   infile>>xc>>yc>>zen>>azi>>nmuon>>knhit;
   core->Fill(yc,xc);
   angle->Fill(zen*57.296);
   //dT=(wT-kT)*1000000000;
   h->Fill(knhit);
   //if(wE == 538515)h1->Fill(deltat*1e9,100);
   //if(deltat*1e9>-1200&&deltat*1e9<-900){h->Fill(kE);}
   /*if(deltat*1e9>-600&&deltat*1e9<800)*///hpe->Fill(log10(npe));
   k++;
   }
   /*
   TFile* a = new TFile("/eos/lhaaso/simulation/wcdamc/g4wcda/data/20191122/1122/ES.30298.WCDA_EVENT.P1GRBM20M.20191122000115.1387.root");
   TTree* t = (TTree*)a->Get("wcda");
   WCDAEvent* wcda = new WCDAEvent(t);
   wcda->
   */

   cout<<"Please Input the option: t or q."<<"\n"<<"t---time"<<"\n"<<"q---charge"<<"\n"<<"c---core"<<"\n"<<"a---angle"<<endl;
   char option;
   cin>>option;
   if(option=='t'){
   //draw deltat
   //for(int i=180;i<210;i++)cout<<h->GetBinContent(i)<<"  "<<i<<endl;
   cout<<" Drawing deltat distri."<<endl;
   h->Draw("");
   //h1->Draw("Psame");
   //h1->Sumw2();
   h->Sumw2();
   h->SetLineColor(kRed);
	//h->Scale(1/h->Integral());
   h->SetMarkerStyle(7);
   h->SetMarkerColor(kRed);
   h->GetXaxis()->SetTitle("nhit");
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

   if(option=='c'){
   cout<<"Drawing core distri."<<endl;
   
   core1->Draw("");
   core1->SetMarkerColor(kBlue);
   core->Draw("same");
   core->GetXaxis()->SetTitle("yc");
   core->GetYaxis()->SetTitle("xc");
   }
   if(option=='a'){
   angle->Draw("");
   angle->Sumw2();
   angle->GetXaxis()->SetTitle("zen");
   }
   infile.close();
}
