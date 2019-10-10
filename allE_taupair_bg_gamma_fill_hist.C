void allE_taupair_bg_gamma_fill_hist()  //(const char* filename)
{
  
  //TFile* file = new TFile(filename);
  TTree* t_gamma = (TTree*)_file0->Get("t_gamma");
  std::string filename = Form("0010.gamma.root");
  std::string cname = "c_" + filename;
  TCanvas* c = new TCanvas(cname.c_str(), cname.c_str(), 840, 560);
  TH1* h = new TH1F(("h_"+filename).c_str(), ";Energy[GeV];candidates of taupair bg gamma ", 200, 0, 11);

  int ncandidates;
  float E[100];
  t_gamma->SetBranchAddress("__ncandidates__", &ncandidates); 
  t_gamma->SetBranchAddress("E", E);
  for (int i = 0; i < t_gamma->GetEntries(); i++) {
    t_gamma->GetEntry(i); 
    for (int in = 0; in < ncandidates; in++) {
    	h -> Fill(E[in]);  
    }
  }
  h->Draw("hist");
}
