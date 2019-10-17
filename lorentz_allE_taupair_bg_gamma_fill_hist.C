TLorentzVector Lorentz(Double_t p[3], Double_t E);
void lorentz_allE_taupair_bg_gamma_fill_hist()  //(const char* filename)
{
  
  //TFile* file = new TFile(filename);
  TTree* t_gamma = (TTree*)_file0->Get("t_gamma");
  std::string filename = Form("taupair_BGx1_0010.gamma.root");
  std::string cname = "c_" + filename;
  TCanvas* c = new TCanvas(cname.c_str(), cname.c_str(), 840, 560);
  TH1* h  = new TH1F(("h_"+filename).c_str(),  ";Energy[GeV]; candidates of taupair bg gamma entry "        , 200, 0, 11.5);
  TH1* hl = new TH1F(("hl_"+filename).c_str(), ";Energy[GeV]; candidates of lorentz taupair bg gamma entry ", 200, 0, 11.5);

  int ncandidates;
  float E[100];
  t_gamma->SetBranchAddress("__ncandidates__", &ncandidates); 
  t_gamma->SetBranchAddress("E", E);
  for (int i = 0; i < t_gamma->GetEntries(); i++) {
    t_gamma->GetEntry(i); 
    for (int in = 0; in < ncandidates; in++) {
    	h -> Fill(E[in]);
	Double_t p[3] = {0,0,0};
	TLorentzVector le = Lorentz(p,E[in]);	
    	/*hl -> Fill(le[3]);*/	hl -> Fill(E[in]);
    }
  }
  h->Draw("hist");
  hl->Draw("hist");
}
TLorentzVector Lorentz(Double_t p[3], Double_t E)
{
	Double_t P_beam[4] = {0.456369, 0, 2.99742, 11};
	const TLorentzVector p4_beam(P_beam[0], P_beam[1],
	                             P_beam[2], P_beam[3]);
	TLorentzVector  p4(p[0], p[1], p[2], E);
	p4.Boost(-p4_beam.BoostVector());
    	return p4;
}
