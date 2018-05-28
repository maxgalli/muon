{
  gROOT->Reset();
  TFile *f = new TFile("mug4_.root","RECREATE");
  
  TTree *T = new TTree("Data","data from ascii file");
  Long64_t nlines = T->ReadFile("mu-g4.txt","tdc11/I:tdc12/I:tdc13/I:tdc14/I:tdc15/I:tdc16/I:tdc17/I:tdc18/I:tdc21/I:tdc22/I:tdc23/I:tdc24/I:tdc25/I:tdc26/I:tdc27/I:tdc28/I");
  printf(" found %lld points\n",nlines);
  T->Write();
  f->Close();
}
