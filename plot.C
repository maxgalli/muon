
void plot() {

TGraphErrors* gr = new TGraphErrors("data.txt"); //X Y EX EY
gr -> SetName("Graph");
gr -> SetTitle("Graph");
gr->GetXaxis()->SetTitle("X");
gr->GetYaxis()->SetTitle("Y");

//TF1* func = new TF1("v_i_function","x/[0]-[1]/[0]");	//[0]=V0, [1]=R

TCanvas* tela = new TCanvas("Tela","Graph",500,500);

//gr -> Fit(func);
gr -> Draw("AL");

}
