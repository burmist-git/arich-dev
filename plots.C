//C, C++
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include <time.h>

using namespace std;

Int_t plots(){

  TString fileN;
  fileN = "./aerogelInfo.out.root";

  TFile *f1 = new TFile(fileN.Data());

  //TH1D *h1_1 = (TH1D*)f1->Get("h1_thickness_A");
  //TH1D *h1_2 = (TH1D*)f1->Get("h1_thickness_B");
  //TH1D *h1_1 = (TH1D*)f1->Get("h1_n_A");
  //TH1D *h1_2 = (TH1D*)f1->Get("h1_n_B");
  //TH1D *h1_1 = (TH1D*)f1->Get("h1_transmLength_A");
  //TH1D *h1_2 = (TH1D*)f1->Get("h1_transmLength_B");
  TH2D *h1_1 = (TH2D*)f1->Get("h2_n_vs_transmLength_A");
  TH2D *h1_2 = (TH2D*)f1->Get("h2_n_vs_transmLength_B");
  //h1_1->Rebin(4);

  //TCanvas *c1 = new TCanvas("c1",fileN.Data(),10,10,800,800);
  TCanvas *c1 = new TCanvas("c1",fileN.Data(),10,10,600,600);
  c1->SetRightMargin(0.03);
  c1->SetLeftMargin(0.09);
  c1->SetTopMargin(0.03);
  c1->SetBottomMargin(0.09);


  gStyle->SetPalette(1);
  gStyle->SetFrameBorderMode(0);
  gROOT->ForceStyle();
  gStyle->SetStatColor(kWhite);
  //gStyle->SetOptStat(kFALSE);
 
  h1_1->SetLineColor(kBlack);
  h1_1->SetLineWidth(3.0);
  h1_2->SetLineColor(kRed);
  h1_2->SetLineWidth(3.0);

  h1_2->SetTitle("");
  //h1_2->Draw();
  //h1_1->Draw("sames");
  h1_2->Draw("ZCOLOR");
  h1_1->Draw("ZCOLOR sames");

  //h1_2->SetMaximum(80);

  h1_2->GetXaxis()->SetTitle("n");
  h1_2->GetYaxis()->SetTitle("Transmittance length, cm");

  //h1_2->GetXaxis()->SetTitle("Thickness, mm");
  //h1_1->GetXaxis()->SetTitle("Charge, Vs");
  //h1_1->GetXaxis()->SetTitle("Amplitude, V");
  //h1_1->GetXaxis()->SetRangeUser(-0.13,-0.12);
  //h1_1->GetXaxis()->CenterTitle();
  //h1_1->GetXaxis()->SetTitleSize(0.05);
  //h1_1->GetXaxis()->SetTitleOffset(0.75);

  /*
  TLegend *leg = new TLegend(0.6,0.6,0.9,0.9,"","brNDC");
  leg->AddEntry(h1_1, "A (Upstream layer)","l");
  leg->AddEntry(h1_2, "B (Downstream layer)","l");
  leg->Draw();
  */

  return 0;
}
