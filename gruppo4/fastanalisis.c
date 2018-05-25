{
  gROOT->Reset();
  TFile f("mug4_.root");
  TTree *Data=f.Get("Data");
  

  TH1F *h1=new TH1F("p11","p11",50,0.,10000.);
  TH1F *h2=new TH1F("p12","p12",50,0.,10000.);

  TCanvas *cc=new TCanvas("sticazzi");
  cc->Divide(1,2);
  cc->cd(1);
  Data->Draw("tdc12*(5000./4095)>>p11","tdc12!=4095&&tdc13==4095&&tdc11==4095&&tdc24==4095&&tdc26==4095");
  cc->cd(2);
  Data->Draw("(tdc14+tdc25)*(5000./4095)>>p12","tdc25!=4095&&tdc12==4095&&tdc11==4095&&tdc13==4095&&tdc24==4095&&tdc26==4095");


  TH1F *hp1=new TH1F("hp1","hp1",50,0.,10000.);
  hp1->Add(p11);
  hp1->Add(p12);
  TCanvas *cc2=new TCanvas("sticazzi2");  
  hp1->Draw();



  
  //////

  TH1F *h3=new TH1F("p21","p21",50,0.,10000.);
  TH1F *h4=new TH1F("p22","p22",50,0.,10000.);

  TCanvas *cc3=new TCanvas("sticazzi3");
  cc3->Divide(1,2);
  cc3->cd(1);
  Data->Draw("tdc17*(5000./4095)>>p21","tdc17!=4095&&tdc15==4095&&tdc16==4095&&tdc25==4095&&tdc24==4095");
  cc3->cd(2);
  Data->Draw("(tdc18+tdc26)*(5000./4095)>>p22","tdc26!=4095&&tdc15==4095&&tdc16==4095&&tdc17==4095&&tdc24==4095&&tdc25==4095");

  TH1F *hp2=new TH1F("hp2","hp2",50,0.,10000.);
  hp2->Add(p21);
  hp2->Add(p22);
  TCanvas *cc4=new TCanvas("sticazzi4");  
  hp2->Draw();

}
