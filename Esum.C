void Esum()  //(const char* filename)
{
  
  //TFile* file = new TFile(filename);
  TTree* t_gamma = (TTree*)_file0->Get("t_gamma");
  ofstream fout("Esum.dat");
  int ncandidates;
  float E[100];
  float Esum = 0;
  t_gamma->SetBranchAddress("__ncandidates__", &ncandidates); 
  t_gamma->SetBranchAddress("E", E);
  for (int i = 0; i < t_gamma->GetEntries(); i++) {
    t_gamma->GetEntry(i);
    for (int in = 0; in < ncandidates; in++) {
    	Esum +=  E[in];  
    }
    fout << Esum;	fout << "\n";
    Esum = 0;
  }
  fout.close();
}
