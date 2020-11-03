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
#include"TH1D.h"
#include"TCut.h"
//all in wcda frame
#define X_0          75.5       //x of center of km2a in wcda frame(m)
#define Y_0          56 //x of center of km2a in wcda frame(m)
#define Z_P          0  //height of detector subtract the height of WCDA
#define AZI_0        -118.832   //angle beteen 0 and N in NWSE direction(KM2A)in wcda frame
#define cosa         0.87085373
#define sina         0.49154225 //a is the angel between line of wcda azi = 0 and east
#define c            299792458// m/s
#define PI           3.14159265
#define D2R          0.01745329
#define R2D          57.2957795
using namespace std;





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
 *  * change km2a core position into wcda frame,xk,yk is the
 *   * shower core in km2a file ,xw,yw is the position in wcda
 *    * frame(m)
 *     * ********************************************/
void coreChange(double xk,double yk,double* xw,double* yw){
     
        *xw=xk*cosa+yk*sina+75.5;
        *yw=-xk*sina+yk*cosa+56;
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
void checkNearShower( double hitx,double hity,long double hitt,double corex,double corey,long double coret,double zen,double azi,long double* deltat){
     
       *deltat = coret-(cos(azi*D2R)*sin(zen*D2R)*(hitx-corex)+
		sin(azi*D2R)*sin(zen*D2R)*(hity-corey)+0.03*sqrt((hitx-corex)*(hitx-corex)+(hity-corey)*(hity-corey)))/c-hitt;//coret-d/c is the ideal time of hit

}
/**********************************************
 * transport hittp1(ns) to mjd ( wcda hits)(d)
 * thinking about the precision of double ,just using 
 * the decimal of mjd
 * *******************************************/
void getHitMjd(double hittp1,double mjd,long double *hitmjd){
	*hitmjd = (mjd-int(mjd))*86400.00+(hittp1/1000000000.0);
	//cout<<setprecision(20)<<(mjd-int(mjd))*86400.00<<"  "<<hittp1/1000000000.0<<"  "<<*hitmjd<<endl;
}


/**********************************************
 * in this stage the forward surface using plane fit
 * and we will using curve fit later
 * *****************************************/
int main3(){
	TFile* km2af = new TFile("/eos/user/y/yuehua/datacheck/events_km2a.root");
	TFile* wcdaf = new TFile("/afs/ihep.ac.cn/users/g/gaowk1/scratchfs/data_20191121_night.root");	     
	TTree* km2at = (TTree*)km2af->Get("trec");
	TTree* wcdat = (TTree*)wcdaf->Get("trec");
	double kMjd,wMjd,xc,yc,zen,azi,xc1,yc1,zenc,azic;
	double xcw,ycw,aziw;
	int wNhit;
	int hitig[2500];
	double mynpe[2500];
	double hittp1[2500];
	km2at->SetBranchAddress("mjd",&kMjd);
	km2at->SetBranchAddress("xc",&yc);
	km2at->SetBranchAddress("yc",&xc);
	km2at->SetBranchAddress("zen",&zen);
	km2at->SetBranchAddress("azi",&azi);
	wcdat->SetBranchAddress("mjd",&wMjd);
	wcdat->SetBranchAddress("nhit",&wNhit);
	wcdat->SetBranchAddress("hitig",&hitig);
	wcdat->SetBranchAddress("mynpe",&mynpe);
	wcdat->SetBranchAddress("hittp1",&hittp1);
	wcdat->SetBranchAddress("xc1",&xc1);
	wcdat->SetBranchAddress("yc1",&yc1);
	wcdat->SetBranchAddress("zenc",&zenc);
	wcdat->SetBranchAddress("azic",&azic);
	int wNum = wcdat->GetEntries();
        int kNum = km2at->GetEntries();
	int point =0; 
        int tmp;
	long double deltat;
	double position_x,position_y;
	long double hitt;
	int i =1986393;
        ofstream file;file.open("forwardsurface.txt");
	//for(int k=77681;k<wNum;k++){
		wcdat->GetEntry(21728);
	//	while(i<kNum){
			km2at->GetEntry(1983725);
			cout<<setprecision(16)<<wMjd<<" "<<kMjd<<endl;
                        if((kMjd-3.3179e-11)<wMjd){
				//cout<<setprecision(16)<<k<<"  "<<i<<"  "<<wMjd<<endl;
				coreChange(xc,yc,&xcw,&ycw);
				aziChange(azi,&aziw);
				for(int j = 0;j<wNhit;j++){
					igToPosition(hitig[j] ,&position_x,&position_y);
					getHitMjd(hittp1[j],wMjd,&hitt);
				//	cout<<setprecision(30)<<hittp1[j]<<"  "<<wMjd<<"  "<<hitt<<endl;
					checkNearShower(position_x,position_y,hitt,xcw,ycw,(kMjd-int(kMjd))*86400,zen,aziw,&deltat);
					cout<<setprecision(16)<<"position_x "<<position_x<<" position_y "<<position_y<<" deltat "<<deltat<<endl;
					if (fabs(deltat)<1.67e-6){
                                        	cout<<setprecision(16)<<"  "<<position_x<<"  "<<position_y<<"  "<<deltat<<"  "
						<<"  "<<i<<"  "<<j<<endl;

                                       		// tmp = i;     
     					//	cout<<setprecision(30)<<"position_x "<<position_x<<" position_y "<<position_y<<" deltat "<<deltat<<endl;
                                	}
				}
                               	//if(fabs(kMjd-wMjd)>3.3179e-11){i= 1986393;break;}
     
                        }   
                //i = i+1;
		//}
	//}

	file.close(); 
	return 0;
}
