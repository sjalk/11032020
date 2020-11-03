#ifndef detconf_h
#define detconf_h
//Made by Zhiguo Yao <zhiguo.yao@ihep.ac.cn>, 2019/01/16
//Last modified: 2019/03/31
#include <iostream>
#define DC_CHECK_ID

namespace dc {

//put the wcdaconf into the namespace dc
#include "wcdaconf.h"

  static const int ncluster[3] = { 25, 25, 40 };
  static const int nclusterI[4] = { 0, 25, 50, 90 };
  //number of cells alone x direction
  static const int ncellx[3] = { 30, 30, 60 };
  //number of cells alone y direction
  static const int ncelly[3] = { 30, 30, 22 };
  //Number of clusters along x direction
  static const int ncx[3] = { 5, 5, 10 };
  //Number of clusters along y direction
  static const int ncy[3] = { 5, 5, 4 };
  //Number of groups in a cluster
  static const int ngroup = 4;
  //Number of cells in a group
  static const int ncell = 9;

  //These is for number of cells in each station. The real number!
  static const int ncelltot[3] = { 900, 900, 1320 };
  static const int ncelltotI[4] = { 0, 900, 1800, 3120 };

  //Number of groups along x direction in a cluster
  static const int ngx = 2;
  //Number of groups along y direction in a cluster
  static const int ngy = 2;
  //Number of cells along x direction in a group
  static const int ndx = 3;
  //Number of cells along y direction in a group
  static const int ndy = 3;

  static const double wcdacenterx[3] = { -78.68, 74.52, -0.88 };
  static const double wcdacentery[3] = { -47.40, -47.40, 88.20 };
  static const double wcdacenterz[3] = { 0., 0., 0. };

  static bool finit = false;

  static const int maxcell = 3240;
  //Note: 3240 ((25+25+40)*36), not 3120 cells
  //Do not directly use the following 3 arrays, use the function (change
  //"x" in the middle to "f") instead
  static int idcellxig[maxcell];
  //convert index to ig
  static int igcellxiconf[maxcell];
  //index of ig in wcdaconf
  static int iconfxigcell[maxcell];

  static int igcellfid(int sccgd) {
#ifdef DC_CHECK_ID
    if (sccgd<0) return -1;
    int _s = sccgd/10000;
    int _cc = sccgd/100%100;
    int _g = sccgd/10%10;
    int _d = sccgd%10;
    if (_s>3||_cc>ncluster[_s]||_g>3||_d>8) return -1;
    return ((nclusterI[_s] + _cc)*ngroup + _g)*ncell + _d;
#else
    return ((nclusterI[sccgd/10000] + (sccgd/100%100))*ngroup +
            (sccgd/10%10))*ncell + (sccgd%10);
#endif
  }


  static void initconf() {
    if (finit) return;
    finit = true;
    int igcell = 0;
    for (int istation=0; istation<3; ++istation) {
      for (int icluster=0; icluster<ncluster[istation]; ++icluster) {
        for (int igroup=0; igroup<ngroup; ++igroup) {
          for (int icell=0; icell<ncell; ++icell) {
            idcellxig[igcell] = istation*10000 +
                                icluster*100 +
                                igroup*10 +
                                icell;
            igcell++;
          }
        }
      }
    }

    for (int i=0; i<maxcell; ++i) iconfxigcell[i] = -1;

    for (int i=0; i<ncellconf; ++i) {
      int scc = wcdaconf[i][4];
      int igroup = wcdaconf[i][5];
      int icell = wcdaconf[i][6];
      int ig = igcellfid(scc*100+igroup*10+icell);
      igcellxiconf[i] = ig;
      iconfxigcell[ig] = i;
    }
  }


  static int findconf(int ifee, int ich) {
    int i1 = 0;
    int i2 = ncellconf - 1;
    int ix;

    while (true) {
      if (i1>i2) return -1;
      if (int(wcdaconf[i1][0]+0.1)==ifee&&
          int(wcdaconf[i1][1]+0.1)==ich) return i1;
      if (int(wcdaconf[i2][0]+0.1)==ifee&&
          int(wcdaconf[i2][1]+0.1)==ich) return i2;
      ix = (i1+i2)/2;
      if (int(wcdaconf[ix][0]+0.1)==ifee&&
          int(wcdaconf[ix][1]+0.1)==ich) return ix;
  
      if (int(wcdaconf[ix][0]+0.1)>ifee) { ++i1; i2 = ix - 1; }
      else if (int(wcdaconf[ix][0]+0.001)<ifee) { i1 = ix + 1; --i2; }
      else {
        if (int(wcdaconf[ix][1]+0.001)>ich) { ++i1; i2 = ix - 1; }
        else { i1 = ix + 1; --i2; }
      }
    }
  }


  static int idcellfig(int ig) {
    if (!finit) initconf();
    if (ig<0||ig>=maxcell) return -1;
    return idcellxig[ig];
  }


  static int igcellficonf(int iconf) {
    if (!finit) initconf();
    if (iconf<0||iconf>=ncellconf) return -1;
    return igcellxiconf[iconf];
  }


  static int iconffigcell(int ig) {
    if (!finit) initconf();
    if (ig<0||ig>=maxcell) return -1;
    return iconfxigcell[ig];
  }

  static int getigoff(int scc) {
    return igcellfid(scc*100);
  }

  //convert cell ID sccgd to colrow (icol,irow) in the station
  static void colrowcellfid(int sccgd, int *pos) {
    //icol,irow of the cell in the station are returned
    pos[0] = ((sccgd%10000/100)/ncy[sccgd/10000]*ngx +
              (sccgd%100/10)/ngy)*ndx + (sccgd%10)/ndy;
    pos[1] = ((sccgd%10000/100)%ncy[sccgd/10000]*ngy +
              (sccgd%100/10)%ngy)*ndy + (sccgd%10)%ndy;
  }

  static int idcellfcolrow(int istation, int icol, int irow) {
    if (istation<0||istation>2) return -1;
    //icol, irow is the cell index in a station, cell id: sccgd
    //In the third station, irow number can be bigger than the real one!
    if (icol<0||icol>=ndx*ngx*ncx[istation]||
        irow<0||irow>=ndy*ngy*ncy[istation]) return -1;
    int _cc = icol/(ndx*ngx)*ncy[istation] + irow/(ndy*ngy);
    int _g  = icol%(ndx*ngx)/ndx*ngy + irow%(ndy*ngy)/ndy;
    int _d  = icol%(ndx*ngx)%ndx*ndy + irow%(ndy*ngy)%ndy;
    return istation*10000 + _cc*100 + _g*10 + _d;
  }

  static int idcellmcfid(int sccgd) {
    //Note: idcellmc: 0-3119
    int pos[2];
    colrowcellfid(sccgd,pos);
    int istation = sccgd/10000;
    if (istation<0||istation>2) return -1;
    return ncelltotI[istation] + ncelly[istation]*pos[0] + pos[1]; 
  }

  static int idcellfmc(int idmc) {
    if (idmc<0) return -1;
    int icol, irow;
    for (int i=0; i<3; ++i) {
      if (idmc<ncelltotI[i+1]) {
        icol = (idmc-ncelltotI[i])/ncelly[i];
        irow = (idmc-ncelltotI[i])%ncelly[i];
        return idcellfcolrow(i,icol,irow);
      }
    }
    return -1;
  }

  //In the WCDA frame, but the origin is at the LHAASO center
  static void local2global(int istation, double *vin, double *vout) {
    vout[0] = vin[0] + wcdacenterx[istation];
    vout[1] = vin[1] + wcdacentery[istation];
    vout[2] = vin[2] + wcdacenterz[istation];
    return;
  }


  //In the WCDA frame, but the origin is at the LHAASO center
  static void global2local(int istation, double *vin, double *vout) {
    vout[0] = vin[0] - wcdacenterx[istation];
    vout[1] = vin[1] - wcdacentery[istation];
    vout[2] = vin[2] - wcdacenterz[istation];
    return;
  }
}

#endif /* detconf_h */
