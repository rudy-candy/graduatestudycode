void Esum_taupair_bg_gamma_fill_hist()  //(const char* filename)
{
  
  //TFile* file = new TFile(filename);
  TTree* t_gamma = (TTree*)_file0->Get("t_gamma");
  //ofstream fout("Esum_taupair_bg_gamma.dat");
  std::string filename = Form("/home/usr/data/belle2/mc/BGx1/taupair_BGx1_0010.gamma.root");
  std::string cname = "c_" + filename;
  TCanvas* c = new TCanvas(cname.c_str(), cname.c_str(), 840, 560);
  TH1* h = new TH1F(("h_"+filename).c_str(), ";Energy[GeV];Entryies of taupair bg gamma ", 200, 0, 11);

  int ncandidates;
  float E[100];
  float Esum = 0;
  int in;
  t_gamma->SetBranchAddress("__ncandidates__", &ncandidates); 
  t_gamma->SetBranchAddress("E", E);
  for (int i = 0; i < t_gamma->GetEntries(); i++) {
    t_gamma->GetEntry(i); 
    Esum = 0;
    for (in = 0; in < ncandidates; in++) {
    	Esum +=  E[in];  
    }
    //fout << Esum;	fout << "\n";
    if(ncandidates!=0)	h->Fill(Esum);
  }
  //fout.close();
  h->Draw("hist");
}
