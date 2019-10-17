void candidatesfrac_pi()  //(const char* filename)
{
  
  //TFile* file = new TFile(filename);
  TTree* t_pi = (TTree*)_file0->Get("t_pi");
  //ofstream fout("Esum_taupair_bg_pi.dat");
  //std::string filename = Form("taupair_BGx1_0010.pi.root");
  //std::string cname = "c_" + filename;
  //TCanvas* c = new TCanvas(cname.c_str(), cname.c_str(), 840, 560);
  //TH1* h = new TH1F(("h_"+filename).c_str(), ";Candidates;Entryies of taupair bg pi  ", 200, 0, 11);

  int ncandidates;
  int candidatessum = 0;
  long f[100];
  int in;
  t_pi->SetBranchAddress("__ncandidates__", &ncandidates); 
  for (int i = 0; i < t_pi->GetEntries(); i++) {
    t_pi->GetEntry(i); 
    candidatessum = 0;
    for (in = 0; in < ncandidates; in++) {
    	candidatessum +=  1;
    }
    f[candidatessum] += 1;
    //fout << Esum;	fout << "\n";
    //h->Fill(candidatessum);
  }
  for (int im=0; im <100;im++){
  	//f[im] = f[im]/210000;
  	if(f[im] != 0){
		cout << im << "prong function is" << f[im]  <<"\n";
	}
  }
  //fout.close();
  //h->Draw("hist");
}
