#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
#include "TRandom.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TH2.h"
#include "TLorentzVector"

void rootmacro(Char_t* name = "Pi0_mc_out_250.root") {
	Char_t* filename = Form("/home/alejandro/rootwork/%s", name);
	TFile *file1 = new TFile(filename);
	TTree *tree1 = (TTree*)file1->Get("h1");
	
	Float_t En_bm; 
	TLorentzVecotor v1;

	tree1->SetBranchAddress("En_bm", &En_bm);
	tree1->SetBranchAddress("Px_l0114", &ppx); 
	tree1->SetbranchAddress("Py_l0114", &ppy);
	tree1->SetbranchAddress("Pz_l0114", &ppz);
	tree1->SetbranchAddress("Pt_l0114", &pt);
	tree1->SetbranchAddress("En_l0114", &pE);

	TH1D *a0 = new TH1D("En_bm","Energy of the Incoming Phonton Beam (GeV)", 1000, 0.242, 0.257);
		

	Int_t nentries = (Int_t)tree1->GetEntries();
	Double_t ppx[nentries], ppy[nentries], ppz[nentries], pt[nentries], pE[nentries]; 
	for (Int_t i = 0; i<nentries; i++) { 
		
		tree1->GetEntry(i);
		a0->Fill(En_bm);
		v1. SetPxPyPzE
	}

	a0->Draw();
} 









