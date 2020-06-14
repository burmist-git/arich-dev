void makeGraphFromFile(){

  //TGraph * gr_up = new TGraph("./CAu8-5wjt.DX");
  //TGraph * gr_do = new TGraph("./CAd15-17wjt.DX");
  TGraph * gr_up = new TGraph("./ca-u1_transT_data/CAu1-1_transT.dat");
  TGraph * gr_do = new TGraph("./ca-u1_transT_data/CAu1-1_transT.dat");
  TGraph * gr_up_tr = new TGraph();
  TGraph * gr_do_tr = new TGraph();
  cout<<"gr_up->GetN() "<<gr_up->GetN()<<endl;
  cout<<"gr_do->GetN() "<<gr_do->GetN()<<endl;
  Double_t x;
  Double_t y;
  Int_t i = 0;

  for(i = 0;i<gr_up->GetN();i++){
    gr_up->GetPoint(i,x,y);
    if(y>0.0)
      gr_up_tr->SetPoint(i,x,-10.0/TMath::Log(y/100.0));
    else
      gr_up_tr->SetPoint(i,x,0.0);
  }
  for(i = 0;i<gr_do->GetN();i++){
    gr_do->GetPoint(i,x,y);
    if(y>0.0)
      gr_do_tr->SetPoint(i,x,-10.0/TMath::Log(y/100.0));
    else
      gr_do_tr->SetPoint(i,x,0.0);
  }

  gr_up->SetName("TRANSMITTANCE_UP");
  gr_up->SetTitle("TRANSMITTANCE_UP");
  gr_do->SetName("TRANSMITTANCE_DOWN");
  gr_do->SetTitle("TRANSMITTANCE_DOWN");

  gr_up->SetLineWidth(3.0);
  gr_do->SetLineWidth(3.0);
  gr_up->SetLineColor(kBlack);
  gr_do->SetLineColor(kRed);
  gr_up->SetMarkerColor(kBlack);
  gr_do->SetMarkerColor(kRed);

  gr_up_tr->SetLineWidth(3.0);
  gr_do_tr->SetLineWidth(3.0);
  gr_up_tr->SetLineColor(kBlack);
  gr_do_tr->SetLineColor(kRed);
  gr_up_tr->SetMarkerColor(kBlack);
  gr_do_tr->SetMarkerColor(kRed);
  
  gStyle->SetPalette(1);
  gStyle->SetFrameBorderMode(0);
  gROOT->ForceStyle();
  gStyle->SetStatColor(kWhite);
  //gStyle->SetOptStat(kFALSE);
  
  TCanvas *c1 = new TCanvas("c1","plots",10,10,800,800);
  c1->Clear();
  c1->SetFillColor(kWhite);
  c1->GetPad(0)->SetLeftMargin(0.12);
  c1->GetPad(0)->SetRightMargin(0.04);
  c1->GetPad(0)->SetTopMargin(0.07);
  c1->GetPad(0)->SetBottomMargin(0.2);
 
  // draw a frame to define the range
  TMultiGraph *mg = new TMultiGraph();
  mg->SetName("TRANSMITTANCE_UP");
  mg->SetTitle("Optical transmittance of aerogel");
  mg->Add(gr_up);
  mg->Add(gr_do);
  //mg->Add(gr_up_tr);
  //mg->Add(gr_do_tr);

  //mg->SetMinimum(-5.0);
  //mg->SetMaximum(100.0);
  mg->SetMinimum(-5.0);
  //mg->SetMaximum(200.0);

  mg->Draw("APL");

  mg->GetXaxis()->SetTitle("#lambda, nm");
  //mg->GetYaxis()->SetTitle("Transmittance, %");
  mg->GetYaxis()->SetTitle("Transmittance length, mm");

  TLegend *leg = new TLegend(0.6,0.6,0.9,0.9,"","brNDC");
  leg->AddEntry(gr_up, "Up (n=1.0447)","lp");
  leg->AddEntry(gr_do, "Down (n=1.0546)","lp");
  //leg->AddEntry(gr_up_tr, "Up (n=1.0447)","lp");
  //leg->AddEntry(gr_do_tr, "Down (n=1.0546)","lp");
  leg->Draw();

  TF1 *f1 = new TF1("f1","1237.78/x",1.5,5.0);
  TGaxis *axis = new TGaxis( 247.556, -35, 825.187, -35, "f1", 510, "L+", 2);
  //axis->SetLabelColor(kRed);
  axis->SetTitle("h#nu, eV");
  axis->SetLabelSize(0.03);
  axis->Draw();
  //axis->SetTSize(0.000001);

  //Double_t ymax = 100;  
  Double_t ymax = 200;  

  TLine *ln_1 = new TLine(1237.78/1.5, -5,1237.78/1.5, ymax);
  ln_1->SetLineWidth(3.0);
  ln_1->Draw("same");
  TLine *ln_2 = new TLine(1237.78/2.2, -5,1237.78/2.2, ymax);
  ln_2->SetLineWidth(3.0);
  ln_2->Draw("same");
  TLine *ln_3 = new TLine(1237.78/2.9, -5,1237.78/2.9, ymax);
  ln_3->SetLineWidth(3.0);
  ln_3->Draw("same");
  TLine *ln_4 = new TLine(1237.78/3.6, -5,1237.78/3.6, ymax);
  ln_4->SetLineWidth(3.0);
  ln_4->Draw("same");
  TLine *ln_5 = new TLine(1237.78/4.3, -5,1237.78/4.3, ymax);
  ln_5->SetLineWidth(3.0);
  ln_5->Draw("same");
  TLine *ln_6 = new TLine(1237.78/5.0, -5,1237.78/5.0, ymax);
  ln_6->SetLineWidth(3.0);
  ln_6->Draw("same");



  //--------------------------------------
  //<Material name="Aerogel1">
  //<density unit="g/cm3">0.261905</density> 
  //<Property name="RINDEX" unit="eV"> 
  //   <value energy="1.5">1.045</value> 
  //   <value energy="2.2">1.045</value> 
  //   <value energy="2.9">1.045</value> 
  //   <value energy="3.6">1.045</value> 
  //   <value energy="4.3">1.045</value> 
  //   <value energy="5.0">1.045</value> 
  //<Property name="ABSLENGTH" unit="eV"> 
  //   <value energy="1.5">100</value> 
  //   <value energy="2.2">100</value> 
  //   <value energy="2.9">100</value> 
  //   <value energy="3.6">100</value> 
  //   <value energy="4.3">100</value> 
  //   <value energy="5.0">100</value> 
  //<Property name="RAYLEIGH" unit="eV"> 
  //   <value energy="1.5">820.907</value>
  //   <value energy="2.2">177.406</value>
  //   <value energy="2.9">58.758</value>
  //   <value energy="3.6">24.743</value>
  //   <value energy="4.3">12.155</value>
  //   <value energy="5.0">6.649</value>
  //--------------------------------------
  //<Material name="Aerogel2">
  //<density unit="g/cm3">0.309524</density> 
  //<Property name="RINDEX" unit="eV"> 
  //   <value energy="1.5">1.055</value> 
  //   <value energy="2.2">1.055</value> 
  //   <value energy="2.9">1.055</value> 
  //   <value energy="3.6">1.055</value> 
  //   <value energy="4.3">1.055</value> 
  //   <value energy="5.0">1.055</value> 
  //<Property name="ABSLENGTH" unit="eV"> 
  //   <value energy="1.5">100</value> 
  //   <value energy="2.2">100</value> 
  //   <value energy="2.9">100</value> 
  //   <value energy="3.6">100</value> 
  //   <value energy="4.3">100</value> 
  //   <value energy="5.0">100</value> 
  //<Property name="RAYLEIGH" unit="eV"> 
  //   <value energy="1.5">638.483</value>
  //   <value energy="2.2">137.982</value>
  //   <value energy="2.9">45.700</value>
  //   <value energy="3.6">19.244</value>
  //   <value energy="4.3">9.454</value>
  //   <value energy="5.0">5.171</value>
  //--------------------------------------

  //TFile f("graph.root", "recreate");
  //f.cd();
  //gr->Write();
  
  //gr->SetMinimum(0);
  
  //gr->Draw("AL");
}
