TLorentzVector Lorentz(Double_t p[3], Double_t E);
void E_taupair_bg_piandgamma_2fill_hist()  //(const char* filename)
{
  
  //TFile* file = new TFile(filename);
  TTree* t_pi = (TTree*)_file0->Get("t_pi");
  TTree* t_gamma = (TTree*)_file1->Get("t_gamma");
  
  ofstream fout("Esum_taupair_bg_piandgamma_i_evtNum.dat");
  
  std::string filename = Form("Esum_taupair_bg_pi and gammma");
  std::string cname = "c_" + filename;
  TCanvas* c = new TCanvas(cname.c_str(), cname.c_str(), 840, 560);
  TH1* h = new TH1F(("h_"+filename).c_str(), ";Energy[GeV];taupair bg pisum and gammasum Entry ", 300, 0, 11);  
  h->SetFillColor(kRed);
  TH1* h1 = new TH1F(("h1_"+filename).c_str(), ";Energy[GeV];taupair bg pisum and gammasum Entry ", 300, 0, 11);  
  h1->SetFillColor(kBlue);
  int pi_ncandidates;
  int gamma_ncandidates;

  float pi_evtNum;	float gamma_evtNum;
  float pi_px[100];	float gamma_px[100];
  float pi_py[100];	float gamma_py[100];
  float pi_pz[100];	float gamma_pz[100];
  float pi_E[100];	float gamma_E[100];

  float pxsum = 0;
  float pysum = 0;
  float pzsum = 0;
  float Esum = 0;
  int il = 0;
  long int num = 1;
  t_pi->SetBranchAddress("__ncandidates__", &pi_ncandidates);	t_gamma->SetBranchAddress("__ncandidates__", &gamma_ncandidates);  
  t_pi->SetBranchAddress("px", pi_px);				t_gamma->SetBranchAddress("px", gamma_px);
  t_pi->SetBranchAddress("py", pi_py);				t_gamma->SetBranchAddress("py", gamma_py);
  t_pi->SetBranchAddress("pz", pi_pz);				t_gamma->SetBranchAddress("pz", gamma_pz);
  t_pi->SetBranchAddress("E", pi_E);				t_gamma->SetBranchAddress("E", gamma_E);
  t_pi->SetBranchAddress("evtNum", &pi_evtNum);			t_gamma->SetBranchAddress("evtNum", &gamma_evtNum); 
  
  for (int i = 0; i < t_pi -> GetEntries(); i++) {
  	t_pi -> GetEntry(i);
    	for(il ; il < t_gamma -> GetEntries();il++){
    		t_gamma -> GetEntry(il);
  		long int i_pi_evtNum = pi_evtNum;
  		long int i_gamma_evtNum = gamma_evtNum;
   		if(i_pi_evtNum  == i_gamma_evtNum){
			Esum = 0;
    			for (int in = 0; in < pi_ncandidates; in++) {
    				pxsum +=  pi_px[in];
    				pysum +=  pi_py[in];
    				pzsum +=  pi_pz[in];
    				Esum +=  pi_E[in];
				h1->Fill(pi_E[in]);
    			}
    			for (int in = 0; in < gamma_ncandidates; in++) {
    				pxsum +=  gamma_px[in];
    				pysum +=  gamma_py[in];
    				pzsum +=  gamma_pz[in];
    				Esum +=  gamma_E[in];
				h1->Fill(gamma_E[in]);
    			}	
    			//fout << num <<" i_pi_evtnum is  " << i_pi_evtNum << " i_gamma_evtnum is  " << i_gamma_evtNum;	fout << "\n";
			num++;
			Double_t  p[3] = {pxsum,pysum,pzsum};
			//Double_t pl[4] = TLorentzVector(pxsum,pysum,pzsum,Esum);
			//TLorentzVector   a1= Lorentz(p, Esum);
			if(Esum!=0)	h->Fill(Esum);
    			//h->Fill(al[4]);
			il++;
			break;
		}
    	}
 }
 h1->Draw("hist");
 h->Draw("same");
 fout.close();
}
TLorentzVector Lorentz(Double_t p[3], Double_t E)
{
	Double_t P_beam[4] = {0.456369, 0, 2.99742, 11};
	const TLorentzVector p4_beam(P_beam[0], P_beam[1],
	                             P_beam[2], P_beam[3]);
	TLorentzVector  p4(p[0], p[1], p[2], E);
	p4.Boost(-p4_beam.BoostVector());
	E = p4[3];
	return p4;
}
