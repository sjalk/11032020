//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Oct 15 10:48:04 2020 by ROOT version 6.14/00
// from TTree wcda/WCDA Events
// found on file: ES.30298.WCDA_EVENT.P1GRBM20M.20191122000115.1387.root
//////////////////////////////////////////////////////////

#ifndef WCDAEvent_h
#define WCDAEvent_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "TObject.h"

class WCDAEvent {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxhits = 1187;
   static constexpr Int_t kMaxhitsplus = 337;

   // Declaration of leaf types
 //WCDAEvent       *Event;
   UInt_t          fUniqueID;
   UInt_t          fBits;
   UInt_t          nhit;
   ULong_t         evt;
   Int_t           hits_;
   UInt_t          hits_fUniqueID[kMaxhits];   //[hits_]
   UInt_t          hits_fBits[kMaxhits];   //[hits_]
   UInt_t          hits_fee[kMaxhits];   //[hits_]
   UInt_t          hits_ch[kMaxhits];   //[hits_]
   UInt_t          hits_anode_charge[kMaxhits];   //[hits_]
   UInt_t          hits_dynode_charge[kMaxhits];   //[hits_]
   UInt_t          hits_charge_over_range_id[kMaxhits];   //[hits_]
   UInt_t          hits_second[kMaxhits];   //[hits_]
   UInt_t          hits_year[kMaxhits];   //[hits_]
   UInt_t          hits_coarse_time[kMaxhits];   //[hits_]
   UInt_t          hits_high_th_fine_time[kMaxhits];   //[hits_]
   UInt_t          hits_low_th_fine_time[kMaxhits];   //[hits_]
   UInt_t          hits_coarse_counter_diff_id[kMaxhits];   //[hits_]
   UInt_t          hits_temprature_sensor_info[kMaxhits];   //[hits_]
   ULong_t         hits_time[kMaxhits];   //[hits_]
   UInt_t          nhitplus;
   Int_t           hitsplus_;
   UInt_t          hitsplus_fUniqueID[kMaxhitsplus];   //[hitsplus_]
   UInt_t          hitsplus_fBits[kMaxhitsplus];   //[hitsplus_]
   UInt_t          hitsplus_fee[kMaxhitsplus];   //[hitsplus_]
   UInt_t          hitsplus_flag[kMaxhitsplus];   //[hitsplus_]
   UInt_t          hitsplus_bdb[kMaxhitsplus];   //[hitsplus_]
   UInt_t          hitsplus_db[kMaxhitsplus];   //[hitsplus_]
   UInt_t          hitsplus_pmt[kMaxhitsplus];   //[hitsplus_]
   ULong_t         hitsplus_time[kMaxhitsplus];   //[hitsplus_]
   UInt_t          hitsplus_second[kMaxhitsplus];   //[hitsplus_]
   UInt_t          hitsplus_ns[kMaxhitsplus];   //[hitsplus_]
   UInt_t          hitsplus_anode_peak[kMaxhitsplus];   //[hitsplus_]
   UInt_t          hitsplus_anode_ped[kMaxhitsplus];   //[hitsplus_]
   UInt_t          hitsplus_anode_time[kMaxhitsplus];   //[hitsplus_]
   UInt_t          hitsplus_dynode_peak[kMaxhitsplus];   //[hitsplus_]
   UInt_t          hitsplus_dynode_ped[kMaxhitsplus];   //[hitsplus_]
   UInt_t          hitsplus_dynode_time[kMaxhitsplus];   //[hitsplus_]
   UInt_t          hitsplus_tail[kMaxhitsplus];   //[hitsplus_]

   // List of branches
   TBranch        *b_Event_fUniqueID;   //!
   TBranch        *b_Event_fBits;   //!
   TBranch        *b_Event_nhit;   //!
   TBranch        *b_Event_evt;   //!
   TBranch        *b_Event_hits_;   //!
   TBranch        *b_hits_fUniqueID;   //!
   TBranch        *b_hits_fBits;   //!
   TBranch        *b_hits_fee;   //!
   TBranch        *b_hits_ch;   //!
   TBranch        *b_hits_anode_charge;   //!
   TBranch        *b_hits_dynode_charge;   //!
   TBranch        *b_hits_charge_over_range_id;   //!
   TBranch        *b_hits_second;   //!
   TBranch        *b_hits_year;   //!
   TBranch        *b_hits_coarse_time;   //!
   TBranch        *b_hits_high_th_fine_time;   //!
   TBranch        *b_hits_low_th_fine_time;   //!
   TBranch        *b_hits_coarse_counter_diff_id;   //!
   TBranch        *b_hits_temprature_sensor_info;   //!
   TBranch        *b_hits_time;   //!
   TBranch        *b_Event_nhitplus;   //!
   TBranch        *b_Event_hitsplus_;   //!
   TBranch        *b_hitsplus_fUniqueID;   //!
   TBranch        *b_hitsplus_fBits;   //!
   TBranch        *b_hitsplus_fee;   //!
   TBranch        *b_hitsplus_flag;   //!
   TBranch        *b_hitsplus_bdb;   //!
   TBranch        *b_hitsplus_db;   //!
   TBranch        *b_hitsplus_pmt;   //!
   TBranch        *b_hitsplus_time;   //!
   TBranch        *b_hitsplus_second;   //!
   TBranch        *b_hitsplus_ns;   //!
   TBranch        *b_hitsplus_anode_peak;   //!
   TBranch        *b_hitsplus_anode_ped;   //!
   TBranch        *b_hitsplus_anode_time;   //!
   TBranch        *b_hitsplus_dynode_peak;   //!
   TBranch        *b_hitsplus_dynode_ped;   //!
   TBranch        *b_hitsplus_dynode_time;   //!
   TBranch        *b_hitsplus_tail;   //!

   WCDAEvent(TTree *tree=0);
   virtual ~WCDAEvent();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
 //  virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef WCDAEvent_cxx
WCDAEvent::WCDAEvent(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("ES.30298.WCDA_EVENT.P1GRBM20M.20191122000115.1387.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("ES.30298.WCDA_EVENT.P1GRBM20M.20191122000115.1387.root");
      }
      f->GetObject("wcda",tree);

   }
   Init(tree);
}

WCDAEvent::~WCDAEvent()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t WCDAEvent::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t WCDAEvent::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void WCDAEvent::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("fUniqueID", &fUniqueID, &b_Event_fUniqueID);
   fChain->SetBranchAddress("fBits", &fBits, &b_Event_fBits);
   fChain->SetBranchAddress("nhit", &nhit, &b_Event_nhit);
   fChain->SetBranchAddress("evt", &evt, &b_Event_evt);
   fChain->SetBranchAddress("hits", &hits_, &b_Event_hits_);
   fChain->SetBranchAddress("hits.fUniqueID", hits_fUniqueID, &b_hits_fUniqueID);
   fChain->SetBranchAddress("hits.fBits", hits_fBits, &b_hits_fBits);
   fChain->SetBranchAddress("hits.fee", hits_fee, &b_hits_fee);
   fChain->SetBranchAddress("hits.ch", hits_ch, &b_hits_ch);
   fChain->SetBranchAddress("hits.anode_charge", hits_anode_charge, &b_hits_anode_charge);
   fChain->SetBranchAddress("hits.dynode_charge", hits_dynode_charge, &b_hits_dynode_charge);
   fChain->SetBranchAddress("hits.charge_over_range_id", hits_charge_over_range_id, &b_hits_charge_over_range_id);
   fChain->SetBranchAddress("hits.second", hits_second, &b_hits_second);
   fChain->SetBranchAddress("hits.year", hits_year, &b_hits_year);
   fChain->SetBranchAddress("hits.coarse_time", hits_coarse_time, &b_hits_coarse_time);
   fChain->SetBranchAddress("hits.high_th_fine_time", hits_high_th_fine_time, &b_hits_high_th_fine_time);
   fChain->SetBranchAddress("hits.low_th_fine_time", hits_low_th_fine_time, &b_hits_low_th_fine_time);
   fChain->SetBranchAddress("hits.coarse_counter_diff_id", hits_coarse_counter_diff_id, &b_hits_coarse_counter_diff_id);
   fChain->SetBranchAddress("hits.temprature_sensor_info", hits_temprature_sensor_info, &b_hits_temprature_sensor_info);
   fChain->SetBranchAddress("hits.time", hits_time, &b_hits_time);
   fChain->SetBranchAddress("nhitplus", &nhitplus, &b_Event_nhitplus);
   fChain->SetBranchAddress("hitsplus", &hitsplus_, &b_Event_hitsplus_);
   fChain->SetBranchAddress("hitsplus.fUniqueID", hitsplus_fUniqueID, &b_hitsplus_fUniqueID);
   fChain->SetBranchAddress("hitsplus.fBits", hitsplus_fBits, &b_hitsplus_fBits);
   fChain->SetBranchAddress("hitsplus.fee", hitsplus_fee, &b_hitsplus_fee);
   fChain->SetBranchAddress("hitsplus.flag", hitsplus_flag, &b_hitsplus_flag);
   fChain->SetBranchAddress("hitsplus.bdb", hitsplus_bdb, &b_hitsplus_bdb);
   fChain->SetBranchAddress("hitsplus.db", hitsplus_db, &b_hitsplus_db);
   fChain->SetBranchAddress("hitsplus.pmt", hitsplus_pmt, &b_hitsplus_pmt);
   fChain->SetBranchAddress("hitsplus.time", hitsplus_time, &b_hitsplus_time);
   fChain->SetBranchAddress("hitsplus.second", hitsplus_second, &b_hitsplus_second);
   fChain->SetBranchAddress("hitsplus.ns", hitsplus_ns, &b_hitsplus_ns);
   fChain->SetBranchAddress("hitsplus.anode_peak", hitsplus_anode_peak, &b_hitsplus_anode_peak);
   fChain->SetBranchAddress("hitsplus.anode_ped", hitsplus_anode_ped, &b_hitsplus_anode_ped);
   fChain->SetBranchAddress("hitsplus.anode_time", hitsplus_anode_time, &b_hitsplus_anode_time);
   fChain->SetBranchAddress("hitsplus.dynode_peak", hitsplus_dynode_peak, &b_hitsplus_dynode_peak);
   fChain->SetBranchAddress("hitsplus.dynode_ped", hitsplus_dynode_ped, &b_hitsplus_dynode_ped);
   fChain->SetBranchAddress("hitsplus.dynode_time", hitsplus_dynode_time, &b_hitsplus_dynode_time);
   fChain->SetBranchAddress("hitsplus.tail", hitsplus_tail, &b_hitsplus_tail);
   Notify();
}

Bool_t WCDAEvent::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void WCDAEvent::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t WCDAEvent::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef WCDAEvent_cxx
