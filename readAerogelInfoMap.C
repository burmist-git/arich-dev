//C, C++
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>

//root
#include <TROOT.h>
#include <TFile.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TProfile.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TMath.h>
#include <TVector3.h>

using namespace std;

Int_t readFileInfo( TString fname, TString *serial, Double_t *version, Double_t *nref, Double_t *transmLength, Double_t *thickness);
Int_t readFileMap(TString fname,TString *id, Double_t *ring, Double_t *column,TString *layer);

const Int_t nnMax = 1000;
Int_t verboseLevel = 0;

Int_t readAerogelInfoMap(){
  Int_t i = 0;
  Int_t j = 0;
  //////////// aerogel info ////////////
  Int_t nInfo = 0;
  TString serial[nnMax];
  Double_t version[nnMax];
  Double_t nref[nnMax];
  Double_t transmLength[nnMax];
  Double_t thickness[nnMax];
  TString fnameInfo = "./aerogelInfo.out"; 
  //TString fnamerootInfo = fnameInfo; fnamerootInfo += ".root";
  //////////////////////////////////////
  //////////// aerogel map /////////////
  Int_t nMap = 0;
  TString id[nnMax];
  Double_t ring[nnMax];
  Double_t column[nnMax];
  TString layer[nnMax];
  TString fnameMap = "./aerogelMap.out"; 
  //TString fnamerootMap = fnameMap; fnamerootMap += ".root";
  //////////////////////////////////////
  // --> READING FILE <--
  nInfo = readFileInfo(fnameInfo,serial,version,nref,transmLength,thickness);
  nMap = readFileMap(fnameMap,id,ring,column,layer);
  if(verboseLevel>1){
    for(i = 0;i<nInfo;i++){
      cout<<setw(10)<<serial[i]<<setw(10)<<nref[i]<<setw(10)<<transmLength[i]<<setw(10)<<thickness[i]<<endl;
    }
    for(i = 0;i<nMap;i++){
      cout<<setw(10)<<id[i]<<setw(10)<<ring[i]<<setw(10)<<column[i]<<setw(10)<<layer[i]<<endl;
    }
  }
  //////////////////////////////////////
  //////////////////////////////////////
  // --> LOOP <--
  for(i = 0;i<nMap;i++){
    for(j = 0;j<nInfo;j++){
      if(id[i] == serial[j])
	cout<<setw(10)<<id[i]<<setw(10)<<serial[j]<<endl;
    }
  }
  //////////////////////////////////////
# ifdef __CINT__
  // --> DISPLAY <--
  gStyle->SetPalette(1);
  gStyle->SetFrameBorderMode(0);
  gROOT->ForceStyle();
  gStyle->SetStatColor(kWhite);
  //gStyle->SetOptStat(kFALSE);  
  //TCanvas *c1 = new TCanvas("c1","plots",10,10,800,800);
  //c1->Clear();
  //c1->SetFillColor(kWhite);
  //c1->GetPad(0)->SetLeftMargin(0.12);
  //c1->GetPad(0)->SetRightMargin(0.02);
  //c1->GetPad(0)->SetTopMargin(0.07);
  //c1->GetPad(0)->SetBottomMargin(0.02);
# endif

  return 0;
}

Int_t readFileInfo( TString fname, TString *serial, Double_t *version, Double_t *nref, Double_t *transmLength, Double_t *thickness){
  string mot;
  string mot1;
  string mot2;
  string mot3;
  string mot7;
  ifstream myfile(fname.Data());
  Int_t nn = 0;
  Double_t x1v, x2v, x3v, x4v;
  //[INFO] Version = 2 serial = A001 id = CAu1-1 n = 1.0435 transmLength = 5.6 thickness = 2.03
  //[INFO] Version = 2 serial = A002 id = CAu1-2 n = 1.0437 transmLength = 5.2 thickness = 2.03
  //[INFO] Version = 2 serial = A003 id = CAu1-3 n = 1.0433 transmLength = 5.5 thickness = 2.02
  //[INFO] Version = 2 serial = A004 id = CAu1-4 n = 1.0434 transmLength = 5.7 thickness = 2.04
  //[INFO] Version = 2 serial = A005 id = CAu1-5 n = 1.0435 transmLength = 5.6 thickness = 2.04
  //[INFO] Version = 2 serial = A006 id = CAu1-6 n = 1.0437 transmLength = 5.5 thickness = 2.03
  //[INFO] Version = 2 serial = A007 id = CAu1-7 n = 1.0436 transmLength = 5.5 thickness = 2.03
  //[INFO] Version = 2 serial = A008 id = CAu1-8 n = 1.0441 transmLength = 5.2 thickness = 2.03
  if(myfile.is_open()){
    while(myfile>>mot1>>mot2>>mot3>>x1v){
      myfile>>mot>>mot>>mot7>>mot>>mot>>mot>>mot>>mot>>x2v;
      //cout<<mot7<<endl;
      myfile>>mot>>mot>>x3v;
      myfile>>mot>>mot>>x4v;
      version[nn] = x1v;
      serial[nn] = mot7;
      nref[nn] = x2v;
      transmLength[nn] = x3v;
      thickness[nn] = x4v;
      nn++;
      if(verboseLevel>0)
	cout<<setw(10)<<x1v<<setw(10)<<x2v<<setw(10)<<x3v<<setw(10)<<x4v<<endl;
    }
    myfile.close();
  } 
  else{
    cout << "Unable to open file"; 
  }
  return nn;
}

Int_t readFileMap(TString fname, TString *id, Double_t *ring, Double_t *column,TString *layer){
  string mot;
  string mot4;
  string mot12;
  ifstream myfile(fname.Data());
  Int_t nn = 0;
  Double_t x1v, x2v;
  //[INFO] ID = B076 ring = 1 column = 12 layer: down
  //[INFO] ID = B134 ring = 1 column = 13 layer: down
  //[INFO] ID = B036 ring = 1 column = 14 layer: down
  //[INFO] ID = B027 ring = 1 column = 15 layer: down
  //[INFO] ID = B024 ring = 1 column = 16 layer: down
  //[INFO] ID = B077 ring = 1 column = 17 layer: down
  //[INFO] ID = B084 ring = 1 column = 18 layer: down
  //[INFO] ID = B073 ring = 1 column = 19 layer: down
  //[INFO] ID = B060 ring = 1 column = 20 layer: down
  //[INFO] ID = B074 ring = 1 column = 21 layer: down
  //[INFO] ID = B026 ring = 1 column = 22 layer: down
  if(myfile.is_open()){
    while(myfile>>mot>>mot>>mot>>mot4){
      myfile>>mot>>mot>>x1v;
      myfile>>mot>>mot>>x2v;
      myfile>>mot>>mot12;
      id[nn] = mot4;
      ring[nn] = x1v;
      column[nn] = x2v;
      layer[nn] = mot12;
      nn++;
      if(verboseLevel>0)
	cout<<setw(10)<<mot4<<setw(10)<<x1v<<setw(10)<<x2v<<setw(10)<<mot12<<endl;
    }
    myfile.close();
  } 
  else{
    cout << "Unable to open file"; 
  }
  return nn;
}

# ifndef __CINT__
int main(int argc, char *argv[]){
  readAerogelInfoMap();
  return 0;
}
# endif
