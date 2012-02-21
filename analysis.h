//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jan 24 04:07:40 2012 by ROOT version 5.30/03
// from TTree tree/data tree
// found on file: convert_137608_part1_all.root
//////////////////////////////////////////////////////////

#ifndef analysis_h
#define analysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
   const Int_t kMaxtrack = 2786;
   const Int_t kMaxv0s = 15669;
   const Int_t kMaxemc = 186;
   const Int_t kMaxevent = 1;

class analysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           track_;
   UInt_t          track_fUniqueID[kMaxtrack];   //[track_]
   UInt_t          track_fBits[kMaxtrack];   //[track_]
   Short_t         track_fCharge[kMaxtrack];   //[track_]
   Short_t         track_fNcl[kMaxtrack];   //[track_]
   Short_t         track_fNclf[kMaxtrack];   //[track_]
   Short_t         track_fNcls[kMaxtrack];   //[track_]
   Float_t         track_fPt[kMaxtrack];   //[track_]
   Float_t         track_fP[kMaxtrack];   //[track_]
   Float_t         track_fEta[kMaxtrack];   //[track_]
   Float_t         track_fPhi[kMaxtrack];   //[track_]
   Float_t         track_fDedx[kMaxtrack];   //[track_]
   Float_t         track_fDCAxy[kMaxtrack];   //[track_]
   Float_t         track_fDCAz[kMaxtrack];   //[track_]
   Float_t         track_fTPCchi[kMaxtrack];   //[track_]
   Float_t         track_fIntLength[kMaxtrack];   //[track_]
   Float_t         track_fTime[kMaxtrack];   //[track_]
   Float_t         track_fTimePi[kMaxtrack];   //[track_]
   Float_t         track_fTimeK[kMaxtrack];   //[track_]
   Float_t         track_fTimeP[kMaxtrack];   //[track_]
   Float_t         track_fTimeE[kMaxtrack];   //[track_]
   Int_t           v0s_;
   UInt_t          v0s_fUniqueID[kMaxv0s];   //[v0s_]
   UInt_t          v0s_fBits[kMaxv0s];   //[v0s_]
   Short_t         v0s_fPosCharge[kMaxv0s];   //[v0s_]
   Short_t         v0s_fPosNcl[kMaxv0s];   //[v0s_]
   Short_t         v0s_fPosNcls[kMaxv0s];   //[v0s_]
   Float_t         v0s_fPosPt[kMaxv0s];   //[v0s_]
   Float_t         v0s_fPosP[kMaxv0s];   //[v0s_]
   Float_t         v0s_fPosEta[kMaxv0s];   //[v0s_]
   Float_t         v0s_fPosPhi[kMaxv0s];   //[v0s_]
   Float_t         v0s_fPosDedx[kMaxv0s];   //[v0s_]
   Short_t         v0s_fNegCharge[kMaxv0s];   //[v0s_]
   Short_t         v0s_fNegNcl[kMaxv0s];   //[v0s_]
   Short_t         v0s_fNegNcls[kMaxv0s];   //[v0s_]
   Float_t         v0s_fNegPt[kMaxv0s];   //[v0s_]
   Float_t         v0s_fNegP[kMaxv0s];   //[v0s_]
   Float_t         v0s_fNegEta[kMaxv0s];   //[v0s_]
   Float_t         v0s_fNegPhi[kMaxv0s];   //[v0s_]
   Float_t         v0s_fNegDedx[kMaxv0s];   //[v0s_]
   Int_t           v0s_fOnFlyStatus[kMaxv0s];   //[v0s_]
   Float_t         v0s_fAlpha[kMaxv0s];   //[v0s_]
   Float_t         v0s_fPtArm[kMaxv0s];   //[v0s_]
   Float_t         v0s_fPt[kMaxv0s];   //[v0s_]
   Float_t         v0s_fP[kMaxv0s];   //[v0s_]
   Float_t         v0s_fPhi[kMaxv0s];   //[v0s_]
   Float_t         v0s_fEta[kMaxv0s];   //[v0s_]
   Double_t        v0s_fMassK0[kMaxv0s];   //[v0s_]
   Double_t        v0s_fMassLambda[kMaxv0s];   //[v0s_]
   Double_t        v0s_fMassAntiLambda[kMaxv0s];   //[v0s_]
   Int_t           emc_;
   UInt_t          emc_fUniqueID[kMaxemc];   //[emc_]
   UInt_t          emc_fBits[kMaxemc];   //[emc_]
   Int_t           emc_fId[kMaxemc];   //[emc_]
   Int_t           emc_fLabel[kMaxemc];   //[emc_]
   Float_t         emc_fE[kMaxemc];   //[emc_]
   Float_t         emc_fPosX[kMaxemc];   //[emc_]
   Float_t         emc_fPosY[kMaxemc];   //[emc_]
   Float_t         emc_fPosZ[kMaxemc];   //[emc_]
   Double_t        emc_fDisp[kMaxemc];   //[emc_]
   Double_t        emc_fM20[kMaxemc];   //[emc_]
   Double_t        emc_fM02[kMaxemc];   //[emc_]
   Double_t        emc_fDistToBadCh[kMaxemc];   //[emc_]
   Int_t           emc_fCells[kMaxemc];   //[emc_]
 //Event           *event_;
   UInt_t          event_TObject_fUniqueID;
   UInt_t          event_TObject_fBits;
   Int_t           event_fRun;
   Int_t           event_fEvent;
   UInt_t          event_fTime;
   ULong64_t       event_fTrigger;
   Float_t         event_fMag;
   Int_t           event_fNtracks;
   Float_t         event_fVtxzTPC;
   Float_t         event_fVtxzITS;
   Float_t         event_fV0Centr;
   Float_t         event_fTrkCentr;
   Float_t         event_fZdcNC;
   Float_t         event_fZdcNA;
   Float_t         event_fZdcPC;
   Float_t         event_fZdcPA;
   Float_t         event_fMultV0A;
   Float_t         event_fMultV0C;
   Int_t           event_fNV0s;
   Int_t           event_fNClust;

   // List of branches
   TBranch        *b_track_;   //!
   TBranch        *b_track_fUniqueID;   //!
   TBranch        *b_track_fBits;   //!
   TBranch        *b_track_fCharge;   //!
   TBranch        *b_track_fNcl;   //!
   TBranch        *b_track_fNclf;   //!
   TBranch        *b_track_fNcls;   //!
   TBranch        *b_track_fPt;   //!
   TBranch        *b_track_fP;   //!
   TBranch        *b_track_fEta;   //!
   TBranch        *b_track_fPhi;   //!
   TBranch        *b_track_fDedx;   //!
   TBranch        *b_track_fDCAxy;   //!
   TBranch        *b_track_fDCAz;   //!
   TBranch        *b_track_fTPCchi;   //!
   TBranch        *b_track_fIntLength;   //!
   TBranch        *b_track_fTime;   //!
   TBranch        *b_track_fTimePi;   //!
   TBranch        *b_track_fTimeK;   //!
   TBranch        *b_track_fTimeP;   //!
   TBranch        *b_track_fTimeE;   //!
   TBranch        *b_v0s_;   //!
   TBranch        *b_v0s_fUniqueID;   //!
   TBranch        *b_v0s_fBits;   //!
   TBranch        *b_v0s_fPosCharge;   //!
   TBranch        *b_v0s_fPosNcl;   //!
   TBranch        *b_v0s_fPosNcls;   //!
   TBranch        *b_v0s_fPosPt;   //!
   TBranch        *b_v0s_fPosP;   //!
   TBranch        *b_v0s_fPosEta;   //!
   TBranch        *b_v0s_fPosPhi;   //!
   TBranch        *b_v0s_fPosDedx;   //!
   TBranch        *b_v0s_fNegCharge;   //!
   TBranch        *b_v0s_fNegNcl;   //!
   TBranch        *b_v0s_fNegNcls;   //!
   TBranch        *b_v0s_fNegPt;   //!
   TBranch        *b_v0s_fNegP;   //!
   TBranch        *b_v0s_fNegEta;   //!
   TBranch        *b_v0s_fNegPhi;   //!
   TBranch        *b_v0s_fNegDedx;   //!
   TBranch        *b_v0s_fOnFlyStatus;   //!
   TBranch        *b_v0s_fAlpha;   //!
   TBranch        *b_v0s_fPtArm;   //!
   TBranch        *b_v0s_fPt;   //!
   TBranch        *b_v0s_fP;   //!
   TBranch        *b_v0s_fPhi;   //!
   TBranch        *b_v0s_fEta;   //!
   TBranch        *b_v0s_fMassK0;   //!
   TBranch        *b_v0s_fMassLambda;   //!
   TBranch        *b_v0s_fMassAntiLambda;   //!
   TBranch        *b_emc_;   //!
   TBranch        *b_emc_fUniqueID;   //!
   TBranch        *b_emc_fBits;   //!
   TBranch        *b_emc_fId;   //!
   TBranch        *b_emc_fLabel;   //!
   TBranch        *b_emc_fE;   //!
   TBranch        *b_emc_fPosX;   //!
   TBranch        *b_emc_fPosY;   //!
   TBranch        *b_emc_fPosZ;   //!
   TBranch        *b_emc_fDisp;   //!
   TBranch        *b_emc_fM20;   //!
   TBranch        *b_emc_fM02;   //!
   TBranch        *b_emc_fDistToBadCh;   //!
   TBranch        *b_emc_fCells;   //!
   TBranch        *b_event_TObject_fUniqueID;   //!
   TBranch        *b_event_TObject_fBits;   //!
   TBranch        *b_event_fRun;   //!
   TBranch        *b_event_fEvent;   //!
   TBranch        *b_event_fTime;   //!
   TBranch        *b_event_fTrigger;   //!
   TBranch        *b_event_fMag;   //!
   TBranch        *b_event_fNtracks;   //!
   TBranch        *b_event_fVtxzTPC;   //!
   TBranch        *b_event_fVtxzITS;   //!
   TBranch        *b_event_fV0Centr;   //!
   TBranch        *b_event_fTrkCentr;   //!
   TBranch        *b_event_fZdcNC;   //!
   TBranch        *b_event_fZdcNA;   //!
   TBranch        *b_event_fZdcPC;   //!
   TBranch        *b_event_fZdcPA;   //!
   TBranch        *b_event_fMultV0A;   //!
   TBranch        *b_event_fMultV0C;   //!
   TBranch        *b_event_fNV0s;   //!
   TBranch        *b_event_fNClust;   //!

   analysis(TTree *tree=0);
   virtual ~analysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef analysis_cxx
analysis::analysis(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("convert_137608_part1_all.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("convert_137608_part1_all.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

analysis::~analysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t analysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t analysis::LoadTree(Long64_t entry)
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

void analysis::Init(TTree *tree)
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

   fChain->SetBranchAddress("track", &track_, &b_track_);
   fChain->SetBranchAddress("track.fUniqueID", track_fUniqueID, &b_track_fUniqueID);
   fChain->SetBranchAddress("track.fBits", track_fBits, &b_track_fBits);
   fChain->SetBranchAddress("track.fCharge", track_fCharge, &b_track_fCharge);
   fChain->SetBranchAddress("track.fNcl", track_fNcl, &b_track_fNcl);
   fChain->SetBranchAddress("track.fNclf", track_fNclf, &b_track_fNclf);
   fChain->SetBranchAddress("track.fNcls", track_fNcls, &b_track_fNcls);
   fChain->SetBranchAddress("track.fPt", track_fPt, &b_track_fPt);
   fChain->SetBranchAddress("track.fP", track_fP, &b_track_fP);
   fChain->SetBranchAddress("track.fEta", track_fEta, &b_track_fEta);
   fChain->SetBranchAddress("track.fPhi", track_fPhi, &b_track_fPhi);
   fChain->SetBranchAddress("track.fDedx", track_fDedx, &b_track_fDedx);
   fChain->SetBranchAddress("track.fDCAxy", track_fDCAxy, &b_track_fDCAxy);
   fChain->SetBranchAddress("track.fDCAz", track_fDCAz, &b_track_fDCAz);
   fChain->SetBranchAddress("track.fTPCchi", track_fTPCchi, &b_track_fTPCchi);
   fChain->SetBranchAddress("track.fIntLength", track_fIntLength, &b_track_fIntLength);
   fChain->SetBranchAddress("track.fTime", track_fTime, &b_track_fTime);
   fChain->SetBranchAddress("track.fTimePi", track_fTimePi, &b_track_fTimePi);
   fChain->SetBranchAddress("track.fTimeK", track_fTimeK, &b_track_fTimeK);
   fChain->SetBranchAddress("track.fTimeP", track_fTimeP, &b_track_fTimeP);
   fChain->SetBranchAddress("track.fTimeE", track_fTimeE, &b_track_fTimeE);
   fChain->SetBranchAddress("v0s", &v0s_, &b_v0s_);
   fChain->SetBranchAddress("v0s.fUniqueID", v0s_fUniqueID, &b_v0s_fUniqueID);
   fChain->SetBranchAddress("v0s.fBits", v0s_fBits, &b_v0s_fBits);
   fChain->SetBranchAddress("v0s.fPosCharge", v0s_fPosCharge, &b_v0s_fPosCharge);
   fChain->SetBranchAddress("v0s.fPosNcl", v0s_fPosNcl, &b_v0s_fPosNcl);
   fChain->SetBranchAddress("v0s.fPosNcls", v0s_fPosNcls, &b_v0s_fPosNcls);
   fChain->SetBranchAddress("v0s.fPosPt", v0s_fPosPt, &b_v0s_fPosPt);
   fChain->SetBranchAddress("v0s.fPosP", v0s_fPosP, &b_v0s_fPosP);
   fChain->SetBranchAddress("v0s.fPosEta", v0s_fPosEta, &b_v0s_fPosEta);
   fChain->SetBranchAddress("v0s.fPosPhi", v0s_fPosPhi, &b_v0s_fPosPhi);
   fChain->SetBranchAddress("v0s.fPosDedx", v0s_fPosDedx, &b_v0s_fPosDedx);
   fChain->SetBranchAddress("v0s.fNegCharge", v0s_fNegCharge, &b_v0s_fNegCharge);
   fChain->SetBranchAddress("v0s.fNegNcl", v0s_fNegNcl, &b_v0s_fNegNcl);
   fChain->SetBranchAddress("v0s.fNegNcls", v0s_fNegNcls, &b_v0s_fNegNcls);
   fChain->SetBranchAddress("v0s.fNegPt", v0s_fNegPt, &b_v0s_fNegPt);
   fChain->SetBranchAddress("v0s.fNegP", v0s_fNegP, &b_v0s_fNegP);
   fChain->SetBranchAddress("v0s.fNegEta", v0s_fNegEta, &b_v0s_fNegEta);
   fChain->SetBranchAddress("v0s.fNegPhi", v0s_fNegPhi, &b_v0s_fNegPhi);
   fChain->SetBranchAddress("v0s.fNegDedx", v0s_fNegDedx, &b_v0s_fNegDedx);
   fChain->SetBranchAddress("v0s.fOnFlyStatus", v0s_fOnFlyStatus, &b_v0s_fOnFlyStatus);
   fChain->SetBranchAddress("v0s.fAlpha", v0s_fAlpha, &b_v0s_fAlpha);
   fChain->SetBranchAddress("v0s.fPtArm", v0s_fPtArm, &b_v0s_fPtArm);
   fChain->SetBranchAddress("v0s.fPt", v0s_fPt, &b_v0s_fPt);
   fChain->SetBranchAddress("v0s.fP", v0s_fP, &b_v0s_fP);
   fChain->SetBranchAddress("v0s.fPhi", v0s_fPhi, &b_v0s_fPhi);
   fChain->SetBranchAddress("v0s.fEta", v0s_fEta, &b_v0s_fEta);
   fChain->SetBranchAddress("v0s.fMassK0", v0s_fMassK0, &b_v0s_fMassK0);
   fChain->SetBranchAddress("v0s.fMassLambda", v0s_fMassLambda, &b_v0s_fMassLambda);
   fChain->SetBranchAddress("v0s.fMassAntiLambda", v0s_fMassAntiLambda, &b_v0s_fMassAntiLambda);
   fChain->SetBranchAddress("emc", &emc_, &b_emc_);
   fChain->SetBranchAddress("emc.fUniqueID", emc_fUniqueID, &b_emc_fUniqueID);
   fChain->SetBranchAddress("emc.fBits", emc_fBits, &b_emc_fBits);
   fChain->SetBranchAddress("emc.fId", emc_fId, &b_emc_fId);
   fChain->SetBranchAddress("emc.fLabel", emc_fLabel, &b_emc_fLabel);
   fChain->SetBranchAddress("emc.fE", emc_fE, &b_emc_fE);
   fChain->SetBranchAddress("emc.fPosX", emc_fPosX, &b_emc_fPosX);
   fChain->SetBranchAddress("emc.fPosY", emc_fPosY, &b_emc_fPosY);
   fChain->SetBranchAddress("emc.fPosZ", emc_fPosZ, &b_emc_fPosZ);
   fChain->SetBranchAddress("emc.fDisp", emc_fDisp, &b_emc_fDisp);
   fChain->SetBranchAddress("emc.fM20", emc_fM20, &b_emc_fM20);
   fChain->SetBranchAddress("emc.fM02", emc_fM02, &b_emc_fM02);
   fChain->SetBranchAddress("emc.fDistToBadCh", emc_fDistToBadCh, &b_emc_fDistToBadCh);
   fChain->SetBranchAddress("emc.fCells", emc_fCells, &b_emc_fCells);
   fChain->SetBranchAddress("event.TObject.fUniqueID", &event_TObject_fUniqueID, &b_event_TObject_fUniqueID);
   fChain->SetBranchAddress("event.TObject.fBits", &event_TObject_fBits, &b_event_TObject_fBits);
   fChain->SetBranchAddress("event.fRun", &event_fRun, &b_event_fRun);
   fChain->SetBranchAddress("event.fEvent", &event_fEvent, &b_event_fEvent);
   fChain->SetBranchAddress("event.fTime", &event_fTime, &b_event_fTime);
   fChain->SetBranchAddress("event.fTrigger", &event_fTrigger, &b_event_fTrigger);
   fChain->SetBranchAddress("event.fMag", &event_fMag, &b_event_fMag);
   fChain->SetBranchAddress("event.fNtracks", &event_fNtracks, &b_event_fNtracks);
   fChain->SetBranchAddress("event.fVtxzTPC", &event_fVtxzTPC, &b_event_fVtxzTPC);
   fChain->SetBranchAddress("event.fVtxzITS", &event_fVtxzITS, &b_event_fVtxzITS);
   fChain->SetBranchAddress("event.fV0Centr", &event_fV0Centr, &b_event_fV0Centr);
   fChain->SetBranchAddress("event.fTrkCentr", &event_fTrkCentr, &b_event_fTrkCentr);
   fChain->SetBranchAddress("event.fZdcNC", &event_fZdcNC, &b_event_fZdcNC);
   fChain->SetBranchAddress("event.fZdcNA", &event_fZdcNA, &b_event_fZdcNA);
   fChain->SetBranchAddress("event.fZdcPC", &event_fZdcPC, &b_event_fZdcPC);
   fChain->SetBranchAddress("event.fZdcPA", &event_fZdcPA, &b_event_fZdcPA);
   fChain->SetBranchAddress("event.fMultV0A", &event_fMultV0A, &b_event_fMultV0A);
   fChain->SetBranchAddress("event.fMultV0C", &event_fMultV0C, &b_event_fMultV0C);
   fChain->SetBranchAddress("event.fNV0s", &event_fNV0s, &b_event_fNV0s);
   fChain->SetBranchAddress("event.fNClust", &event_fNClust, &b_event_fNClust);
   Notify();
}

Bool_t analysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void analysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t analysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef analysis_cxx
