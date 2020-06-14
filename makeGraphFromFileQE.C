void makeGraphFromFileQE(){

  TGraph * gr = new TGraph("./qe_vs_lam.dat");
  gr->SetName("Q.E.");
  gr->SetTitle("Q.E.");

  gr->SetLineWidth(3.0);
  gr->SetLineColor(kBlack);
  gr->SetMarkerStyle(21);
  gr->SetMarkerColor(kBlack);
  gStyle->SetPalette(1);
  gStyle->SetFrameBorderMode(0);
  gROOT->ForceStyle();
  gStyle->SetStatColor(kWhite);
  //gStyle->SetOptStat(kFALSE);
  
  TCanvas *c1 = new TCanvas("c1","plots",10,10,1200,800);
  c1->Clear();
  c1->SetFillColor(kWhite);
  c1->GetPad(0)->SetLeftMargin(0.1);
  c1->GetPad(0)->SetRightMargin(0.04);
  c1->GetPad(0)->SetTopMargin(0.07);
  c1->GetPad(0)->SetBottomMargin(0.1);
 
  gr->GetXaxis()->SetTitle("#lambda, nm");
  gr->GetYaxis()->SetTitle("Relative Q.E. ");

  gr->Draw("APL");
}
