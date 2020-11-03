//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Nov  3 10:16:52 2020 by ROOT version 6.14/00
// from TTree event/KM2A Events
// found on file: /eos/lhaaso/decode/km2a/2020/0112/ES.37661.KM2A_EVENT.PHYSIC_HALF_EDMD_OVERLAP.20200112015937.018.dat.root
//////////////////////////////////////////////////////////

#ifndef KM2AHits_h
#define KM2AHits_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "TObject.h"

class KM2AHits {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxhits = 15679;

   // Declaration of leaf types
 //KM2AEvent       *Event;
   UInt_t          fUniqueID;
   UInt_t          fBits;
   Int_t           ev_n;
   Double_t        mjd;
   Double_t        dt;
   Double_t        fs;
   Int_t           nhit;
   Int_t           nmd;
   Float_t         phi[3];
   Float_t         theta[3];
   Int_t           nfit;
   Float_t         core_x;
   Float_t         core_y;
   Double_t        c0;
   Double_t        a;
   Double_t        b;
   Double_t        r;
   Double_t        x2;
   Int_t           hits_;
   UInt_t          hits_fUniqueID[kMaxhits];   //[hits_]
   UInt_t          hits_fBits[kMaxhits];   //[hits_]
   UInt_t          hits_id[kMaxhits];   //[hits_]
   UChar_t         hits_mode[kMaxhits];   //[hits_]
   UInt_t          hits_ns[kMaxhits];   //[hits_]
   UInt_t          hits_qa[kMaxhits];   //[hits_]
   UInt_t          hits_qd[kMaxhits];   //[hits_]
   UChar_t         hits_peakTimeAnode[kMaxhits];   //[hits_]
   UChar_t         hits_peakTimeDynode[kMaxhits];   //[hits_]
   UInt_t          hits_peda[kMaxhits];   //[hits_]
   UInt_t          hits_pedd[kMaxhits];   //[hits_]
   UChar_t         hits_tag[kMaxhits];   //[hits_]
   Int_t           hits_oe[kMaxhits];   //[hits_]
   Float_t         hits_x[kMaxhits];   //[hits_]
   Float_t         hits_y[kMaxhits];   //[hits_]
   Float_t         hits_z[kMaxhits];   //[hits_]
   Float_t         hits_t0[kMaxhits];   //[hits_]
   Float_t         hits_t[kMaxhits];   //[hits_]

   // List of branches
   TBranch        *b_Event_fUniqueID;   //!
   TBranch        *b_Event_fBits;   //!
   TBranch        *b_Event_ev_n;   //!
   TBranch        *b_Event_mjd;   //!
   TBranch        *b_Event_dt;   //!
   TBranch        *b_Event_fs;   //!
   TBranch        *b_Event_nhit;   //!
   TBranch        *b_Event_nmd;   //!
   TBranch        *b_Event_phi;   //!
   TBranch        *b_Event_theta;   //!
   TBranch        *b_Event_nfit;   //!
   TBranch        *b_Event_core_x;   //!
   TBranch        *b_Event_core_y;   //!
   TBranch        *b_Event_c0;   //!
   TBranch        *b_Event_a;   //!
   TBranch        *b_Event_b;   //!
   TBranch        *b_Event_r;   //!
   TBranch        *b_Event_x2;   //!
   TBranch        *b_Event_hits_;   //!
   TBranch        *b_hits_fUniqueID;   //!
   TBranch        *b_hits_fBits;   //!
   TBranch        *b_hits_id;   //!
   TBranch        *b_hits_mode;   //!
   TBranch        *b_hits_ns;   //!
   TBranch        *b_hits_qa;   //!
   TBranch        *b_hits_qd;   //!
   TBranch        *b_hits_peakTimeAnode;   //!
   TBranch        *b_hits_peakTimeDynode;   //!
   TBranch        *b_hits_peda;   //!
   TBranch        *b_hits_pedd;   //!
   TBranch        *b_hits_tag;   //!
   TBranch        *b_hits_oe;   //!
   TBranch        *b_hits_x;   //!
   TBranch        *b_hits_y;   //!
   TBranch        *b_hits_z;   //!
   TBranch        *b_hits_t0;   //!
   TBranch        *b_hits_t;   //!

   KM2AHits(TTree *tree=0);
   virtual ~KM2AHits();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   //virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef KM2AHits_cxx
KM2AHits::KM2AHits(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/lhaaso/decode/km2a/2020/0112/ES.37661.KM2A_EVENT.PHYSIC_HALF_EDMD_OVERLAP.20200112015937.018.dat.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/eos/lhaaso/decode/km2a/2020/0112/ES.37661.KM2A_EVENT.PHYSIC_HALF_EDMD_OVERLAP.20200112015937.018.dat.root");
      }
      f->GetObject("event",tree);

   }
   Init(tree);
}

KM2AHits::~KM2AHits()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t KM2AHits::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t KM2AHits::LoadTree(Long64_t entry)
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

void KM2AHits::Init(TTree *tree)
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
   fChain->SetBranchAddress("ev_n", &ev_n, &b_Event_ev_n);
   fChain->SetBranchAddress("mjd", &mjd, &b_Event_mjd);
   fChain->SetBranchAddress("dt", &dt, &b_Event_dt);
   fChain->SetBranchAddress("fs", &fs, &b_Event_fs);
   fChain->SetBranchAddress("nhit", &nhit, &b_Event_nhit);
   fChain->SetBranchAddress("nmd", &nmd, &b_Event_nmd);
   fChain->SetBranchAddress("phi[3]", phi, &b_Event_phi);
   fChain->SetBranchAddress("theta[3]", theta, &b_Event_theta);
   fChain->SetBranchAddress("nfit", &nfit, &b_Event_nfit);
   fChain->SetBranchAddress("core_x", &core_x, &b_Event_core_x);
   fChain->SetBranchAddress("core_y", &core_y, &b_Event_core_y);
   fChain->SetBranchAddress("c0", &c0, &b_Event_c0);
   fChain->SetBranchAddress("a", &a, &b_Event_a);
   fChain->SetBranchAddress("b", &b, &b_Event_b);
   fChain->SetBranchAddress("r", &r, &b_Event_r);
   fChain->SetBranchAddress("x2", &x2, &b_Event_x2);
   fChain->SetBranchAddress("hits", &hits_, &b_Event_hits_);
   fChain->SetBranchAddress("hits.fUniqueID", hits_fUniqueID, &b_hits_fUniqueID);
   fChain->SetBranchAddress("hits.fBits", hits_fBits, &b_hits_fBits);
   fChain->SetBranchAddress("hits.id", hits_id, &b_hits_id);
   fChain->SetBranchAddress("hits.mode", hits_mode, &b_hits_mode);
   fChain->SetBranchAddress("hits.ns", hits_ns, &b_hits_ns);
   fChain->SetBranchAddress("hits.qa", hits_qa, &b_hits_qa);
   fChain->SetBranchAddress("hits.qd", hits_qd, &b_hits_qd);
   fChain->SetBranchAddress("hits.peakTimeAnode", hits_peakTimeAnode, &b_hits_peakTimeAnode);
   fChain->SetBranchAddress("hits.peakTimeDynode", hits_peakTimeDynode, &b_hits_peakTimeDynode);
   fChain->SetBranchAddress("hits.peda", hits_peda, &b_hits_peda);
   fChain->SetBranchAddress("hits.pedd", hits_pedd, &b_hits_pedd);
   fChain->SetBranchAddress("hits.tag", hits_tag, &b_hits_tag);
   fChain->SetBranchAddress("hits.oe", hits_oe, &b_hits_oe);
   fChain->SetBranchAddress("hits.x", hits_x, &b_hits_x);
   fChain->SetBranchAddress("hits.y", hits_y, &b_hits_y);
   fChain->SetBranchAddress("hits.z", hits_z, &b_hits_z);
   fChain->SetBranchAddress("hits.t0", hits_t0, &b_hits_t0);
   fChain->SetBranchAddress("hits.t", hits_t, &b_hits_t);
   Notify();
}

Bool_t KM2AHits::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void KM2AHits::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t KM2AHits::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef KM2AHits_cxx
