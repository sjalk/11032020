//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Oct 28 09:37:00 2020 by ROOT version 6.14/00
// from TTree nt1/LHAASO Reconstructed Data
// found on file: /eos/lhaaso/rec/km2a/half_array/2020_V1/0112/ES.37661.KM2A_EVENT.PHYSIC_HALF_EDMD_OVERLAP.20200112015937.018.dat.root
//////////////////////////////////////////////////////////

#ifndef KM2AEvent_h
#define KM2AEvent_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class KM2AEvent {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        Nevent;
   Double_t        mjd;
   Double_t        NhitE;
   Double_t        NfiltE;
   Double_t        NhitM;
   Double_t        NfiltM;
   Double_t        NpE1;
   Double_t        NpE2;
   Double_t        NpE3;
   Double_t        NuM1;
   Double_t        NuM2;
   Double_t        NuM3;
   Double_t        NuM4;
   Double_t        r_Corex;
   Double_t        r_Corey;
   Double_t        r_Theta;
   Double_t        r_Phi;
   Double_t        chi;
   Double_t        a;
   Double_t        NtrigE;
   Double_t        size;
   Double_t        age;
   Double_t        dr;
   Double_t        nMD50;

   // List of branches
   TBranch        *b_Nevent;   //!
   TBranch        *b_mjd;   //!
   TBranch        *b_NhitE;   //!
   TBranch        *b_NfiltE;   //!
   TBranch        *b_NhitM;   //!
   TBranch        *b_NfiltM;   //!
   TBranch        *b_NpE1;   //!
   TBranch        *b_NpE2;   //!
   TBranch        *b_NpE3;   //!
   TBranch        *b_NuM1;   //!
   TBranch        *b_NuM2;   //!
   TBranch        *b_NuM3;   //!
   TBranch        *b_NuM4;   //!
   TBranch        *b_r_Corex;   //!
   TBranch        *b_r_Corey;   //!
   TBranch        *b_r_Theta;   //!
   TBranch        *b_r_Phi;   //!
   TBranch        *b_chi;   //!
   TBranch        *b_a;   //!
   TBranch        *b_NtrigE;   //!
   TBranch        *b_size;   //!
   TBranch        *b_age;   //!
   TBranch        *b_dr;   //!
   TBranch        *b_nMD50;   //!

   KM2AEvent(TTree *tree=0);
   virtual ~KM2AEvent();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
 //  virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef KM2AEvent_cxx
KM2AEvent::KM2AEvent(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/lhaaso/rec/km2a/half_array/2020_V1/0112/ES.37661.KM2A_EVENT.PHYSIC_HALF_EDMD_OVERLAP.20200112015937.018.dat.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/eos/lhaaso/rec/km2a/half_array/2020_V1/0112/ES.37661.KM2A_EVENT.PHYSIC_HALF_EDMD_OVERLAP.20200112015937.018.dat.root");
      }
      f->GetObject("nt1",tree);

   }
   Init(tree);
}

KM2AEvent::~KM2AEvent()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t KM2AEvent::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t KM2AEvent::LoadTree(Long64_t entry)
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

void KM2AEvent::Init(TTree *tree)
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

   fChain->SetBranchAddress("Nevent", &Nevent, &b_Nevent);
   fChain->SetBranchAddress("mjd", &mjd, &b_mjd);
   fChain->SetBranchAddress("NhitE", &NhitE, &b_NhitE);
   fChain->SetBranchAddress("NfiltE", &NfiltE, &b_NfiltE);
   fChain->SetBranchAddress("NhitM", &NhitM, &b_NhitM);
   fChain->SetBranchAddress("NfiltM", &NfiltM, &b_NfiltM);
   fChain->SetBranchAddress("NpE1", &NpE1, &b_NpE1);
   fChain->SetBranchAddress("NpE2", &NpE2, &b_NpE2);
   fChain->SetBranchAddress("NpE3", &NpE3, &b_NpE3);
   fChain->SetBranchAddress("NuM1", &NuM1, &b_NuM1);
   fChain->SetBranchAddress("NuM2", &NuM2, &b_NuM2);
   fChain->SetBranchAddress("NuM3", &NuM3, &b_NuM3);
   fChain->SetBranchAddress("NuM4", &NuM4, &b_NuM4);
   fChain->SetBranchAddress("r_Corex", &r_Corex, &b_r_Corex);
   fChain->SetBranchAddress("r_Corey", &r_Corey, &b_r_Corey);
   fChain->SetBranchAddress("r_Theta", &r_Theta, &b_r_Theta);
   fChain->SetBranchAddress("r_Phi", &r_Phi, &b_r_Phi);
   fChain->SetBranchAddress("chi", &chi, &b_chi);
   fChain->SetBranchAddress("a", &a, &b_a);
   fChain->SetBranchAddress("NtrigE", &NtrigE, &b_NtrigE);
   fChain->SetBranchAddress("size", &size, &b_size);
   fChain->SetBranchAddress("age", &age, &b_age);
   fChain->SetBranchAddress("dr", &dr, &b_dr);
   fChain->SetBranchAddress("nMD50", &nMD50, &b_nMD50);
   Notify();
}

Bool_t KM2AEvent::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void KM2AEvent::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t KM2AEvent::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef KM2AEvent_cxx
