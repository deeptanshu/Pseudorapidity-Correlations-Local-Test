#define analysis_cxx
#include "analysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TMath.h>

void analysis::Loop()
{
 if (fChain == 0) return;
    
   TFile *f = new TFile("correlationi_highpt.root","RECREATE");
   Float_t phitrig,phiassoc,phiassoc1; 
   Float_t pi = TMath::Pi();
   Int_t ntrigs=0;  
   TH1F* trden = new TH1F("trden","Track Distribution",500,0,3000);
   TH1F* trphi = new TH1F("trphi","#phi Distribution",1000,0,7);
   TH1F* treta = new TH1F("treta","#eta Distribution",500,-1,1);
   TH1F* treta_c1 = new TH1F("treta_c1","#eta Distribution (Class-I)",500,-1,1);
   TH1F* treta_c2 = new TH1F("treta_c2","#eta Distribution (Class-II)",500,-1,1);
   TH1F* treta_c3 = new TH1F("treta_c3","#eta Distribution (Class-III)",500,-1,1);
   TH1F* delphi = new TH1F("delphi","#Delta #phi Distribution (3#leq pT#leq 5 ,1#leq pA#leq 2, |#Delta #eta|<0.8 )",100,0,3);
   TH1F* deleta = new TH1F("deleta","#Delta #eta Distribution (3#leq pT#leq 5 ,1#leq pA#leq 2,  |#Delta #eta|<0.8 )",600,0,3);
   TH2F* phi = new TH2F("phi","#phi Correlation",100,0,8,100,0,8);
   TH2F* phi_trig = new TH2F("phi_trig","#phi Correlation",200,-8,8,200,-8,8);
   TH2F* phi_mod = new TH2F("phi_mod","#phi Correlation",200,2.8,3.5,200,2.8,3.5);
   TH2F* eta = new TH2F("eta","#eta Correlation",30,-1,1,30,-1,1);
   TH2F* eta_trig = new TH2F("eta_trig","#eta Correlation",30,-2,2,30,-2,2);
   TH2F* eta_mod = new TH2F("eta_mod","#eta Correlation",30,0,1.6,30,0,1.6);
   TH2F* eta_phi = new TH2F("eta_phi","#eta #phi Correlation",40,-1.6,1.6,40,-7,7);
   TH1F* deleta_c1 = new TH1F("deleta_c1","#Delta #eta Distribution (Class-I)",600,0,3);
   TH1F* deleta_c2 = new TH1F("deleta_c2","#Delta #eta Distribution (Class-I)",600,0,3);
   TH1F* deleta_c3 = new TH1F("deleta_c3","#Delta #eta Distribution (Class-I)",600,0,3);
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;

 for (Long64_t jentry=0; jentry<200;jentry++) {				// Start Event Loop
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if((jentry+1)%1000==0)  cout << "Event: " << jentry+1 << endl;		// Event Counter 
      trden->Fill(event_fNtracks);						// Fill Histogram for track multiplicity by event
      for (Int_t t1=0; t1 < event_fNtracks; t1++) {				// Start loop over tracks. Trigger Loop or t1-Loop
	if(track_fPt[t1]<2 || TMath::Abs(track_fEta[t1])>1) continue;		// Pt and eta cuts
	trphi->Fill(track_fPhi[t1]);						// phi distribution
	treta->Fill(track_fEta[t1]);						// eta distribution
	if(event_fNtracks >=2300)  treta_c1->Fill(track_fEta[t1]);
        if(event_fNtracks >= 1600 && event_fNtracks < 2300) treta_c2->Fill(track_fEta[t1]);
	if(event_fNtracks >= 1200 && event_fNtracks < 1600) treta_c3->Fill(track_fEta[t1]);
	if(track_fPhi[t1]<pi) phitrig = pi+track_fPhi[t1];			// locate diametrically opposite angle
      	if(track_fPhi[t1]>=pi) phitrig = track_fPhi[t1]-pi;			// locate diametrically opposite angle
	if (track_fPt[t1]<4 ) continue;						// Pt cut for triggers 
	else  { 
	  ntrigs++;
	  for (Int_t t2=0; t2 < event_fNtracks; t2++) {				// Loop over tracks. Assoc1 Loop or t2-loop
	    phiassoc=track_fPhi[t2];

	    if(TMath::Abs(phiassoc-phitrig) > (pi)/6 ||   (track_fPt[t2])>4 || track_fPt[t2]<2 ) continue; // Pt cut for associated and checking azimuth sector
	    else{ 		  eta_phi->Fill(track_fEta[t2]-track_fEta[t1],track_fPhi[t2]-track_fPhi[t1]);

	      for (Int_t t3=0; t3 < event_fNtracks; t3++) {			// Looking for second associated particle, t3-Loop
		 phiassoc1=track_fPhi[t3];
		 if(TMath::Abs(phiassoc1-phiassoc) > pi/3  || (track_fPt[t3])>4 || track_fPt[t3]<2) continue;
		  else if (t2!=t3) { 
		    if(TMath::Abs(track_fEta[t2])<1 && TMath::Abs(track_fEta[t3])<1){
		    delphi->Fill(TMath::Abs(phiassoc-phiassoc1));
		    deleta->Fill(TMath::Abs(track_fEta[t2]-track_fEta[t3]));
		    phi->Fill(phiassoc,phiassoc1);
		    phi_trig->Fill(phiassoc-track_fPhi[t1],phiassoc1-track_fPhi[t1]);
		    phi_mod->Fill(TMath::Abs(phiassoc-track_fPhi[t1]),TMath::Abs(phiassoc1-track_fPhi[t1]));
		    eta->Fill(track_fEta[t2],track_fEta[t3]);
		    eta_trig->Fill(track_fEta[t2]-track_fEta[t1],track_fEta[t3]-track_fEta[t1]);
		    eta_mod->Fill(TMath::Abs(track_fEta[t2]-track_fEta[t1]),TMath::Abs(track_fEta[t3]-track_fEta[t1]));
		    if(event_fNtracks >=2300)    deleta_c1->Fill(TMath::Abs(track_fEta[t2]-track_fEta[t3]));
		    if(event_fNtracks >= 1600 && event_fNtracks < 2300)   deleta->Fill(TMath::Abs(track_fEta[t2]-track_fEta[t3]));
		    if(event_fNtracks >= 1200 && event_fNtracks < 1600)   deleta->Fill(TMath::Abs(track_fEta[t2]-track_fEta[t3]));
	   
		
				    }
		    }
	       }
}
 	    }
        }}

   }
   gROOT->SetStyle("Plain");
   gStyle->SetPalette(1);

   TH1D* eta_proj_1 = eta->ProjectionX("eta_proj_1",0,200);
   TH1D* eta_proj_2 = eta->ProjectionX("eta_proj_2",200,400);
   TH1D* eta_proj_3 = eta->ProjectionX("eta_proj_3",400,600);
   TH1D* eta_proj_4 = eta->ProjectionX("eta_proj_4",600,800);
   TH1D* eta_proj_5 = eta->ProjectionX("eta_proj_5",800,999);
   TH1D* eta_proj_1y = eta->ProjectionY("eta_proj_1y",0,200);
   TH1D* eta_proj_2y = eta->ProjectionY("eta_proj_2y",200,400);
   TH1D* eta_proj_3y = eta->ProjectionY("eta_proj_3y",400,600);
   TH1D* eta_proj_4y = eta->ProjectionY("eta_proj_4y",600,800);
   TH1D* eta_proj_5y = eta->ProjectionY("eta_proj_5y",800,999);

//if (ntrigs !=0) deleta->Scale(1/ntrigs);

 cout << "\n Number of Triggers = " << ntrigs << endl;

//   TCanvas* c1 = new TCanvas("c1", "#eta correlation", 600, 650);
//   TCanvas* c2 = new TCanvas("c2", "#phi correlation", 600, 650);
//   TCanvas* c3 = new TCanvas("c3", "eta pairs", 400, 300);
//   TCanvas* c4 = new TCanvas("c4", "phi pairs", 400, 300);
//   TCanvas* c7 = new TCanvas("c7", "Eta projections", 1400, 600);
//   TCanvas* c6 = new TCanvas("c6", "phi correlationis by centrality", 900, 400);

  //TCanvas* c11 = new TCanvas("c11", "#eta Distributions", 800, 550);
//c11->Divide(2,2);

//c3->Divide(2,2);
   Double_t n1 = 1/(deleta->Integral());
   //n2 = 1/(delphi->Integral()):
   deleta->Scale(n1/(ntrigs));
   //delphi->Scale(n2);
   deleta->GetXaxis()->SetTitle("|#Delta#eta|");
   deleta->GetYaxis()->SetTitle("#frac{dN_{pairs}}{d|#Delta#eta |}");
   delphi->GetXaxis()->SetTitle("|#Delta#phi|");
   delphi->GetYaxis()->SetTitle("#frac{dN_{pairs}}{d|#Delta#phi |}");
   eta->GetXaxis()->SetTitle("#eta_{1}");
   eta->GetYaxis()->SetTitle("#eta_{2}");
   phi->GetXaxis()->SetTitle("#phi_{2}");
   phi->GetYaxis()->SetTitle("#phi_{3}");
   phi_trig->GetXaxis()->SetTitle("#Delta #phi_{13}");
   phi_trig->GetYaxis()->SetTitle("#Delta #phi_{23}");
   phi_mod->GetXaxis()->SetTitle("|#Delta #phi_{13}|");
   phi_mod->GetYaxis()->SetTitle("|#Delta #phi_{23}|");
   eta_mod->GetXaxis()->SetTitle("|#Delta #eta_{13}|");
   eta_mod->GetYaxis()->SetTitle("|#Delta #eta_{23}|");
   eta_trig->GetXaxis()->SetTitle("#Delta #eta_{13}");
   eta_trig->GetYaxis()->SetTitle("#Delta #eta_{23}");
   treta->GetYaxis()->SetTitle("dN/d#eta");
   treta_c1->GetYaxis()->SetTitle("dN^{I}/d#eta");
   treta_c2->GetYaxis()->SetTitle("dN^{II}/d#eta");
   treta_c3->GetYaxis()->SetTitle("dN^{III}/d#eta");
   treta->GetXaxis()->SetTitle("#eta");
   treta_c1->GetXaxis()->SetTitle("#eta");
   treta_c2->GetXaxis()->SetTitle("#eta");
   treta_c3->GetXaxis()->SetTitle("#eta");
  deleta_c1->GetYaxis()->SetTitle("dN^{I}/d#Delta#eta");
   deleta_c2->GetYaxis()->SetTitle("dN^{II}/d#Delta#eta");
   deleta_c3->GetYaxis()->SetTitle("dN^{III}/d#Delta#eta");
    deleta_c1->GetXaxis()->SetTitle("#eta");
    deleta_c2->GetXaxis()->SetTitle("#eta");
   deleta_c3->GetXaxis()->SetTitle("#eta");

/*
c11->cd(1);
treta->Draw();
c11->cd(2);
treta_c1->Draw();
c11->cd(3);
treta_c2->Draw();
c11->cd(4);
treta_c3->Draw();
*/





//   c1->Divide(2,3);
//   c2->Divide(2,3);
//   c7->Divide(5,2);
//   c6->Divide(3,2);
   
/*   c1->cd(1);
   eta->Draw("LEGO2");
   c1->cd(2);
   eta->Draw("zcol");
   c1->cd(3);
   eta_trig->Draw("LEGO2");
   c1->cd(4);
   eta_trig->Draw("zcol");
   c1->cd(5);
   eta_mod->Draw("LEGO2");
   c1->cd(6);
   eta_mod->Draw("zcol");*/

  /* c2->cd(1);
   phi->Draw("LEGO2");
   c2->cd(2);
   phi->Draw("zcol");
   c2->cd(3);
   phi_trig->Draw("LEGO2");
   c2->cd(4);
   phi_trig->Draw("zcol");
   c2->cd(5);
   phi_mod->Draw("zcol");
   c2->cd(6);
   phi_mod->Draw("LEGO2");
*/
/*   c3->cd(1);
   deleta->Draw();
   c3->cd(2);
   deleta_c1->Draw();
   c3->cd(3);
   deleta_c2->Draw();
   c3->cd(4);
   deleta_c3->Draw();*/
  /* c4->cd();
   delphi->Draw();*/
   
/*   c7->cd(1);
   eta_proj_1->Draw();
   c7->cd(2);
   eta_proj_2->Draw();
   c7->cd(3);
   eta_proj_3->Draw();
   c7->cd(4);
   eta_proj_4->Draw();
   c7->cd(5);
   eta_proj_5->Draw();
   c7->cd(6);
   eta_proj_1y->Draw();
   c7->cd(7);
   eta_proj_2y->Draw();
   c7->cd(8);
   eta_proj_3y->Draw();
   c7->cd(9);
   eta_proj_4y->Draw();
   c7->cd(10);
   eta_proj_5y->Draw();*/


   TCanvas* c23 = new TCanvas("c3", "eta pairs", 400, 300);
c23->cd();
eta_phi->Draw("SURF2");



/*
   c6->cd(1);
   c6_1->SetLogy();
   trden->Draw();
   c6->cd(2);
   phi_mod_c1->Draw("zcol");
   c6->cd(3);
   phi_mod_c2->Draw("zcol");
   c6->cd(4);
   phi_mod_c3->Draw("zcol");
   c6->cd(5);
   phi_mod_c4->Draw("zcol");
   c6->cd(6);
   phi_mod_c5->Draw("zcol");
  */ 

   
   phi_mod->Write();
   phi->Write();
   phi_trig->Write();
   eta->Write();
   trphi->Write();
   treta->Write();
   treta_c1->Write();
   treta_c2->Write();
   treta_c3->Write();
   trden->Write();
   delphi->Write();
   deleta->Write();
    deleta_c1->Write();
 deleta_c2->Write();
 deleta_c3->Write();

}
