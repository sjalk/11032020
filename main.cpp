#ifndef WCDAEvent_cxx
#define WCDAEvent_cxx
#define KM2AEvent_cxx
#define hpatimer_cc
#include"TROOT.h"
#include"TFile.h"
#include<iostream>
#include<fstream>
#include<string>
#include"TTree.h"
#include"TBranch.h"
#include"TCanvas.h"
#include"TLegend.h"
#include"TMath.h"
#include"KM2AEvent.h"
#include"TH2D.h"
#include"TCut.h"
#include"WCDAEvent.h"
#include<stdio.h>
#include"wcdaconf.h"
#include"detconf.h"
#include"hpatimer.h"
//all in wcda frame
#define X_0          75.5       //x of center of km2a in wcda frame(m)
#define Y_0          56 //x of center of km2a in wcda frame(m)
#define Z_P          0  //height of detector subtract the height of WCDA
#define AZI_0        -118.832   //angle beteen 0 and N in NWSE direction(KM2A)in wcda frame
#define sina         -0.87085373
#define cosa         0.49154225 //a is the angel between line of wcda azi = 0 and east
#define c            299792458// m/s
#define PI           3.14159265
#define D2R          0.01745329
#define R2D          57.2957795
using namespace std;


int getdtai(UInt_t sec)  {
  if (sec >= 1483228800LL) return 37;
  if (sec >= 1435708800LL) return 36;
  if (sec >= 1341100800LL) return 35;
  if (sec >= 1230768000LL) return 34;
  if (sec >= 1136073600LL) return 33;
  if (sec >= 915148800LL) return 32;
  if (sec >= 867715200LL) return 31;
  if (sec >= 820454400LL) return 30;
  if (sec >= 773020800LL) return 29;
  if (sec >= 741484800LL) return 28;
  if (sec >= 709948800LL) return 27;
  if (sec >= 662688000LL) return 26;
  if (sec >= 631152000LL) return 25;
  if (sec >= 567993600LL) return 24;
  if (sec >= 489024000LL) return 23;
  if (sec >= 425865600LL) return 22;
  if (sec >= 394329600LL) return 21;
  if (sec >= 362793600LL) return 20;
  if (sec >= 315532800LL) return 19;
  if (sec >= 283996800LL) return 18;
  if (sec >= 252460800LL) return 17;
  if (sec >= 220924800LL) return 16;
  if (sec >= 189302400LL) return 15;
  if (sec >= 157766400LL) return 14;
  if (sec >= 126230400LL) return 13;
  if (sec >= 94694400LL) return 12;
  if (sec >= 78796800LL) return 11;
  if (sec >= 63072000LL) return 10;
  return 0;
}


/*************************************************
 * * this position origin from the 0th detector using
 * * (0,0),1st detector using (0,1)and 3rd detector 
 * * using (1,0).
 * * other detector (position_x,position_y)
 * *position_x = hitig_position1[int(ig/9)][0]*3+hitig_position2[ig%9][0]
 * *position_y = hitig_position1[int(ig/9)][1]*3+hitig_position2[ig%9][1]
 * * ***********************************************/
int hitig_position2[9][2]=
{
{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}
};
int hitig_position1[100][2]=
{
{0,0},{0,1},{1,0},{1,1},{0,2},{0,3},{1,2},{1,3},{0,4},{0,5},
{1,4},{1,5},{0,6},{0,7},{1,6},{1,7},{0,8},{0,9},{1,8},{1,9},
{2,0},{2,1},{3,0},{3,1},{2,2},{2,3},{3,2},{3,3},{2,4},{2,5},
{3,4},{3,5},{2,6},{2,7},{3,6},{3,7},{2,8},{2,9},{3,8},{3,9},
{4,0},{4,1},{5,0},{5,1},{4,2},{4,3},{5,2},{5,3},{4,4},{4,5},
{5,4},{5,5},{4,6},{4,7},{5,6},{5,7},{4,8},{4,9},{5,8},{5,9},
{6,0},{6,1},{7,0},{7,1},{6,2},{6,3},{7,2},{7,3},{6,4},{6,5},
{7,4},{7,5},{6,6},{6,7},{7,6},{7,7},{6,8},{6,9},{7,8},{7,9},
{8,0},{8,1},{9,0},{9,1},{8,2},{8,3},{9,2},{9,3},{8,4},{8,5},
{9,4},{9,5},{8,6},{8,7},{9,6},{9,7},{8,8},{8,9},{9,8},{9,9}
};


/***********************************************
 *  * change wcda hits position into km2a frame,xk,yk is the
 *   * shower core in km2a file ,xw,yw is the position in wcda
 *    * frame(m)
 *     * ********************************************/
void coreChange(double xw,double yw,double* xk,double* yk){
     
        *xk=(xw-75.5)*0.491542+(yw-56.)*0.870854;
        *yk=-(yw-56.)*0.491542+(xw-75.5)*0.870854;
}
/***********************************************
 *  * change km2a azi into wcda azi(degree),be aware of 
 *   * the NWSE(counterclockwise) direction
 *    * **********************************************/
void aziChange(double azik,double* aziw){
       if(azik+118.832<360.0){*aziw = azik+118.832;}
       else{*aziw = azik+118.832-360;}
}
/*************************************************
 *  * change the number of wcda detector into the x and y
 *   * in wcda frame(m)
 *    **************************************************/
 void igToPosition(int ig ,double* px,double *py){
        *px = hitig_position1[int(ig/9)][0]*3.0+hitig_position2[ig%9][0]*1.0-75.5;
        *py = hitig_position1[int(ig/9)][1]*3.0+hitig_position2[ig%9][1]*1.0-75.5;
 }
/***********************************************
 *  * using forward surface to check if a hit is near the 
 *   * shower and give the time distence,zen and azi is the 
 *    * direction of a shower in km2a. 
 *     * unit:m,m,s,m,m,s,degree,degree,s
 *      * ALL IN THE WCDA FRAME
 *       * *********************************************/
void checkNearShower( double hitx,double hity,long double hitt,double corex,double corey,long double coret,double zen,double azi,long double* deltat,double* ri){
	
	double di = sqrt((hitx-corex)*(hitx-corex)+(hity-corey)*(hity-corey));
        double projection = (sin((azi-PI/2))*sin(zen)*(-corex+hitx)+cos((azi-PI/2))*sin(zen)*(-corey+hity));
        double costheta = projection/di;
        double sintheta = sqrt(1-costheta*costheta);
         *ri = sintheta*sqrt((hitx-corex)*(hitx-corex)+(hity-corey)*(hity-corey));
        *deltat = -coret+(projection-0.03*(*ri))/c+hitt;//coret-d/c is the ideal time of hit,unit:s
	

}     
/**********************************************
 * transport these time to mjd(just decimal of mjd) ( wcda hits)(d)
 * thinking about the precision of double ,just using 
 * the decimal of mjd
 * *******************************************/
void getHitMjd(UInt_t second,UInt_t low_th,UInt_t coarse_time, long double *hitmjd){
	
	long long sec = (long long)((long long)second+(low_th*0.333+16.*coarse_time)*1.e-9);	
	double subsec = second-sec+(low_th*0.333+16.*coarse_time)*1.e-9;
	long long sec1 = sec  - getdtai(sec);
	*hitmjd = sec1%86400+subsec;
	
	/*
	double a1 = low_th/3.+coarse_time*16.;
        Ttai_t tai;Tmjd_t mjd1;
        tai.assign(second,a1*1e-9);
        mjd1.assign(tai);
        *hitmjd = mjd1.sec+mjd1.subsec;
	*/
	//cout<<setprecision(16)<<*hitmjd<<endl;

}
/***************************************
 * transport fee and channel to position x,y
 * unit:m            wrong!!!!!!!!!!!!!!!
 * ***************************************/
void igToPosition(UInt_t fee,UInt_t ch,double* px,double* py){
//	cout<<fee<<"  "<<ch<<endl;
	*px = hitig_position1[fee][0]*3.0+hitig_position2[ch][0]*1.0-75.5;
	*py = hitig_position1[fee][1]*3.0+hitig_position2[ch][1]*1.0-75.5;
}
/**********************************************
 *
 * *********************************************/
void getIg(UInt_t fee,UInt_t ch,int* ig){
	int iconf = dc::findconf(fee,ch);
	*ig = dc::igcellficonf(iconf);
	if(*ig>=900)cout<<iconf<<"  "<<*ig<<endl;

}
/***********************************************
 * read charge calibration txt
 * *********************************************/
void getCalibration(string chargefile,double spe[],double da[]){
	int itmp1, itmp2, itmp3;
	double tmp_spe, tmp_da, tmp6;
	char buf[200];
	ifstream spefile(chargefile);
	while (spefile.getline(buf,200)) {
		sscanf(buf,"%d %d %lf %lf %d %lf\n",&itmp1, &itmp2, &tmp_spe, &tmp_da, &itmp2, &tmp6);
	     	spe[itmp1-1]=tmp_spe;
	    	da[itmp1-1]=tmp_da;
	  //   	cout<<"charming charge="<<itmp1-1<<" "<<spe[itmp1-1]<<" "<<da[itmp1-1]<<endl;
	  }
	   spefile.close();
}

#if 1
/*****************************************
 * change anode and dynode to npe,which means 
 * charge calibration
 *****************************************/
 void getCharge(UInt_t anode_charge,UInt_t dynode_charge,double spe,double da,double* npe){
 	if(anode_charge<3700){ *npe = double(anode_charge)/spe;}
	else{
	if(dynode_charge<3700)
	{*npe = double(dynode_charge)*da/spe;}
	else{*npe =0;}
	}
 }


/**********************************************
 * the main code
 * *****************************************/
int  main(){
	TFile* km2af = new 
	TFile("/eos/lhaaso/rec/km2a/half_array/2020_V1/0112/ES.37661.KM2A_EVENT.PHYSIC_HALF_EDMD_OVERLAP.20200112015937.018.dat.root");	
	TFile* wcdaf = new 
	TFile("~/eos/ES.37527.WCDA_EVENT.P1GRBM20M.20200112015908.2927.dat.root");	     
	TTree* km2at = (TTree*)km2af->Get("nt1");
	//TTree* wcdat = (TTree*)wcdaf->Get("wcda");
	TTree* wcdat;
	wcdaf->GetObject("wcda",wcdat);
	WCDAEvent* wcdae = new WCDAEvent(wcdat);
	KM2AEvent* km2a = new KM2AEvent(km2at);
	double zen =0;
	double azi =0;
	double kMjd,wMjd,xc,yc,xc1,yc1,zenc,azic;
	double xck,yck,aziw;
	double nmuon,knhit;
	/***************************
	km2at->SetBranchAddress("mjd",&kMjd);
	km2at->SetBranchAddress("r_Corex",&xc);
	km2at->SetBranchAddress("r_Corey",&yc);
	km2at->SetBranchAddress("r_Theta",&zen);
	km2at->SetBranchAddress("r_Phi",&azi);
	km2at->SetBranchAddress("NfiltM",&nmuon);
	km2at->SetBranchAddress("NfiltE",&knhit);
	*****************************/
	int wNum = wcdat->GetEntries();
        int kNum = km2at->GetEntries();
	double spe[900];
	double da[900];
	getCalibration("./0531.txt",spe,da);
	//cout<<spe[0]<<da[0]<<endl;
	double npe;
	int ig =0;
	long double deltat;
	double position_x,position_y;
	long double hitt;
	int i =0;
	int iconf;
	double km2ati,ri,projection;
	UInt_t second;
	UInt_t low_th;
	UInt_t coarse;
	UInt_t fee;
	UInt_t ch;
	UInt_t anode;
	UInt_t dynode;
	#if 0
	wcdae->GetEntry(389779);
	wcdae->Show(389779);
	for(int i=0;i<wcdae->nhit;i++){
	
	getHitMjd(wcdae->hits_second[i],wcdae->hits_low_th_fine_time[i],wcdae->hits_coarse_time[i],&hitt);
	
	cout<<setprecision(16)<<wcdae->nhit<<"  "<<i<<"  "<<wcdae->hits_second[i]
	<<"  "<<wcdae->hits_low_th_fine_time[i]<<"  "<<wcdae->hits_coarse_time[i]<<"  "<<hitt<<endl;
	 }
	 km2at->GetEntry(86248);
	 
	 cout<<setprecision(16)<<" kmjd "<<"   "<<(kMjd-int(kMjd))*86400.+5e-6<<endl;
	#endif
	#if 1
	//ofstream file;file.open("015937_direct_select_large.txt");
        //for(int k = 1;k<kNum;k++){
	TCanvas* c1 = new TCanvas("c1","",800,800*0.8);
	TH2D* h= new TH2D("h","",500,0 ,500,1000,-1500,1500);
                km2a->GetEntry(86248);
		kMjd = km2a->mjd;
		yc = km2a->r_Corex;
		xc = -km2a->r_Corey;
		zen = km2a->r_Theta;
		azi = km2a->r_Phi;
		nmuon = km2a->NfiltM;
		knhit = km2a->NfiltE;
		projection = (sin((azi-PI/2))*sin(zen)*(-xc)+cos((azi-PI/2))*sin(zen)*(-yc));
		km2ati = (kMjd-int(kMjd))*86400+5.70089e-6;
		cout<<"km2ati: "<<projection<<endl;
	//	if(nmuon<=5||knhit<=20)continue;
	//	while(i<wNum){
			wcdae->GetEntry(389779);
			for(int j = 0;j<wcdae->nhit;j++){
				
				second = wcdae->hits_second[j];
				low_th = wcdae->hits_low_th_fine_time[j];
				coarse = wcdae->hits_coarse_time[j];
				getHitMjd(second,low_th,coarse,&hitt);
                  		if((km2ati-1.5e-6)<hitt){
					fee = wcdae->hits_fee[j];
					ch = wcdae->hits_ch[j];
					iconf = dc::findconf(fee,ch);
					position_x = wcdaconf[iconf][2];
					position_y = wcdaconf[iconf][3];
					ig = wcdaconf[iconf][7];
					coreChange(position_x,position_y,&xck,&yck);
					checkNearShower(xck,yck,hitt,xc,yc,km2ati,zen,azi,&deltat,&ri);
				//	cout<<ri<<"  "<<deltat*1e9<<"  "<<xc<<"  "<<yc<<"  "<<endl;
					h->Fill(ri,deltat*1e9);
					if (fabs(deltat)<1.5e-6){
						anode = wcdae->hits_anode_charge[j];
						dynode = wcdae->hits_dynode_charge[j];
						getCharge(anode,dynode,spe[ig],da[ig],&npe);
                          //              	cout<<setprecision(16)<<km2ati<<"  "<<hitt<<"  "<<deltat<<"  "<<npe
			//			<<"  "<<"  "<<"  "<<j<<endl;

                                	}
					//if(fabs(km2ati-hitt)<1.5e-6)file<<setprecision(16)<<km2ati<<"  "<<hitt<<"  "<<i<<"  "<<k<<"  "<<j<<endl;
     				}
			}
         //               if(hitt>(km2ati+1.5e-6)){break;}   
                	i = i+1;
//		}
//	}
//	file.close(); 
h->SetMarkerStyle(21);
h->Draw("");
c1->SaveAs("a.png");
#endif	
return 0;
}
#endif
#endif
