void E_taupair_bg_gamma_2fill_hist()  //(const char* filename)
{
  
  //TFile* file = new TFile(filename);
  TTree* t_gamma = (TTree*)_file0->Get("t_gamma");
  ofstream fout("Esum_taupair_bg_gamma.dat");
  std::string filename = Form("taupair_BGx1_0010.gamma.root");
  std::string cname = "c_" + filename;
  TCanvas* c = new TCanvas(cname.c_str(), cname.c_str(), 840, 560);
  TH1* h = new TH1F(("h_"+filename).c_str(), ";Energy[GeV];Entryies of taupair bg gamma ", 200, 0, 11);
  h->SetFillColor(kRed);
  TH1* h1 = new TH1F(("h1_"+filename).c_str(), ";Energy[GeV];Entryies of taupair bg gamma ", 200, 0, 11);
  h1->SetFillColor(kBlue);
  int ncandidates;
  float E[100];
  float Esum = 0;
  float Ec = 0;
  t_gamma->SetBranchAddress("__ncandidates__", &ncandidates); 
  t_gamma->SetBranchAddress("E", E);
  for (int i = 0; i < t_gamma->GetEntries(); i++) {
    t_gamma->GetEntry(i); 
    Esum = 0;
    for (int in = 0; in < ncandidates; in++) {
    	Esum +=  E[in];
	h1 -> Fill(E[in]);
    }
    fout << Esum;	fout << "\n";
    if(ncandidates!=0)	h->Fill(Esum);
  }
  fout.close();
  h1->Draw("hist");
  h->Draw("same");
}
