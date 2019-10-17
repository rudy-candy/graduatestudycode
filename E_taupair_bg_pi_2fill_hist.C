void E_taupair_bg_pi_2fill_hist()  //(const char* filename)
{
  
  //TFile* file = new TFile(filename);
  TTree* t_pi = (TTree*)_file0->Get("t_pi");
  ofstream fout("E_taupair_bg_pi_entry_and_candidate.dat");
  std::string filename = Form("home/usr/data/belle2/mc/BGx1/taupair_BGx1_0010.pi.root");
  std::string cname = "c_" + filename;
  TCanvas* c = new TCanvas(cname.c_str(), cname.c_str(), 840, 560);
  //THStack *hs = new THStack("hs","taupair_BGx1_0010.pi.root;Energy[GeV];candidates and Entryies of taupair bg pi"); 
  TH1* h = new TH1F(("h_"+filename).c_str(), ";Energy[GeV];Entryies of taupair bg pi  ", 200, 0, 11);
  h->SetFillColor(kRed);
  TH1* h1 = new TH1F(("h1_"+filename).c_str(), ";Energy[GeV];Entryies of taupair bg pi  ", 200, 0, 11); 
  h1->SetFillColor(kBlue);
  int ncandidates;
  float E[100];
  float Esum;
  t_pi->SetBranchAddress("__ncandidates__", &ncandidates); 
  t_pi->SetBranchAddress("E", E);
  for (int i = 0; i < t_pi->GetEntries(); i++) {
    t_pi->GetEntry(i); 
    Esum = 0;
    for (int in = 0; in < ncandidates; in++) {
    	Esum +=  E[in];
	h1 -> Fill(E[in]);
	fout <<"candidates " <<in<<"    "<< E[in] << "    \n" ;
    }
    fout <<"   Esum "<< Esum << "\n";
    if(Esum != 0)	h->Fill(Esum);
    fout <<"entry  "<< i << "\n";
  }
  fout.close();
  h1  -> Draw("hist");	//hs->Add(h);
  h -> Draw("same");	//hs->Add(h1);
  //hs->Draw("hist");
}
