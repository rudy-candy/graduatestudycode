void candidatessum_taupair_bg_piandgamma_fill_hist()  //(const char* filename)
{
  
  //TFile* file = new TFile(filename);
  TTree* t_pi = (TTree*)_file0->Get("t_pi");
  TTree* t_gamma = (TTree*)_file1->Get("t_gamma");
  //ofstream fout("Esum_taupair_bg_pi.dat");
  std::string filename = Form("taupair_BGx1_0010.piandgamma.root");
  std::string cname = "c_" + filename;
  TCanvas* c = new TCanvas(cname.c_str(), cname.c_str(), 840, 560);
  TH1* h = new TH1F(("h_"+filename).c_str(), ";Candidates;Entryies of taupair bg pi and gamma ", 200, 0, 11);

  int pi_ncandidates;
  int gamma_ncandidates;
  float candidatessum = 0;
  t_pi->SetBranchAddress("__ncandidates__", &pi_ncandidates); 
  t_gamma->SetBranchAddress("__ncandidates__", &gamma_ncandidates); 
  for (int i = 0; i < t_gamma->GetEntries(); i++) {
    t_pi->GetEntry(i); 
    candidatessum = 0;
    for (int in = 0; in < pi_ncandidates; in++) {
    	candidatessum +=  1;  
    }
    //fout << Esum;	fout << "\n";
    h->Fill(candidatessum);
  }
  for (int i = 0; i < t_gamma->GetEntries(); i++) {
    t_gamma->GetEntry(i); 
    candidatessum = 0;
    for (int in = 0; in < gamma_ncandidates; in++) {
    	candidatessum +=  1;  
    }
    h->Fill(candidatessum);
  }
  //fout.close();
  h->Draw("hist");
}
