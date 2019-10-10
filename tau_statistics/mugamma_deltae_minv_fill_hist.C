TLorentzVector Lorentz(Double_t p[3], Double_t E);
void mugamma_deltae_minv_fill_hist()  //(const char* filename)
{
  
  //TFile* file = new TFile(filename);
  TTree* t_pi = (TTree*)_file0->Get("t_pi");
  TTree* t_gamma = (TTree*)_file1->Get("t_gamma");
  
  //ofstream fout("Esum_taupair_bg_piandgamma_i_evtNum.dat");
  
  std::string filename = Form("deltaE_Minv_hist");
  std::string cname = "c_" + filename;
  TCanvas* c = new TCanvas(cname.c_str(), cname.c_str(), 840, 560);
  TH2* h = new TH2F(("h_"+filename).c_str(), ";Minv[GeV];delta E[GeV]", 300, 0, 15,300,-10,10);  

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
  float psum = 0;
  float Esum = 0;
  float minv = 0;	float deltae = 0;	float obminv = 0;
  float obpxsum = 0;	float obpysum = 0;	float obpzsum = 0;
  float obesum = 0;	float obpsum = 0;	
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
			Esum = 0; pxsum = 0; pysum = 0; pzsum = 0; psum = 0; minv = 0; deltae = 0; obpxsum = 0; obpysum = 0; obpzsum = 0; obesum = 0; obminv = 0; 
    			for (int in = 0; in < pi_ncandidates; in++) {
			        Double_t  p[3] = {pi_px[in],pi_py[in],pi_pz[in]};	//Double_t  p[3] = {0,0,0};
    				TLorentzVector p4 = Lorentz(p,pi_E[in]);	
				Esum  +=  p4[3];        //Esum  +=  pi_E[in];
    				pxsum +=  p4[0];	//pxsum +=  pi_px[in];
    				pysum +=  p4[1];	//pysum +=  pi_py[in];
    				pzsum +=  p4[2];	//pzsum +=  pi_pz[in];
				obesum += pi_E[in];
				obpxsum += pi_px[in];	obpysum += pi_py[in];	obpzsum += pi_pz[in];
    			}
    			for (int in = 0; in < gamma_ncandidates; in++) {
			        Double_t  p[3] = {gamma_px[in],gamma_py[in],gamma_pz[in]};	//Double_t  p[3] = {0,0,0};
    				TLorentzVector p4 = Lorentz(p,pi_E[in]);	
    				Esum   += p4[3];	//Esum  +=  gamma_E[in];
    				pxsum  += p4[0];	//pxsum +=  gamma_px[in];
    				pysum  += p4[1];	//pysum +=  gamma_py[in];
    				pzsum  += p4[2];	//pzsum +=  gamma_pz[in]; 
				obesum += pi_E[in];
				obpxsum += gamma_px[in];	obpysum += gamma_py[in];	obpzsum += gamma_pz[in];
			}	
    			//fout << num <<" i_pi_evtnum is  " << i_pi_evtNum << " i_gamma_evtnum is  " << i_gamma_evtNum;	fout << "\n";
			num++;
			psum = pxsum*pxsum+pysum*pysum+pzsum*pzsum;	obpsum = obpxsum*obpxsum + obpysum*obpysum + obpzsum*obpzsum;
			psum = sqrtf(psum);				obpsum = sqrtf(obpsum);
			minv = Esum*Esum - psum*psum;			obminv = obesum*obesum - obpsum*obesum;
			minv = sqrtf(minv);				obminv = sqrtf(obminv);
			deltae = Esum - 10.6;			
			if(pi_ncandidates!=0 && gamma_ncandidates!=0)h->Fill(minv,deltae);
    			il++;
			break;
		}
    	}
 }
 h->Draw("hist");
 //fout.close();
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
