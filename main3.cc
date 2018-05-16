#include <TFile.h>
#include <TH2F.h>
#include <TH1F.h>
#include <TGraph.h>
#include <TMultiGraph.h>
#include <TTree.h>
#include <TVector3.h>
#include <TFitResult.h>
#include <TFitResultPtr.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TMath.h>
#include <TStopwatch.h>
#include <TPolyMarker3D.h>
#include <string>
#include <iostream>
#include <fstream>
#include <TChain.h>
#include <TString.h>

//#include "ND280UpConst.hh"
#include "ND280UpRecoTrack.cc"

#include "/nashome/c/chjang/edep-sim/src/TG4Event.h"
//#include "~/edep-sim/src/TG4Event.h"

//#include "ND280UpConst.hh"
//#include "ND280UpRecoTrack.hh"


//int main(int argc, char* argv[])
void main3(char* inputname)
{
  cout<<inputname<<" is running"<<endl;
  TG4Event * g4event = NULL;
  TChain * chain = new TChain("EDepSimEvents");
  chain->Add(Form("/pnfs/dune/persistent/users/chjang/data/%s.root", inputname));
  chain->SetBranchAddress("Event", &g4event);

  TH1D * hCharge500 = new TH1D("hCharge500", "hCharge500", 3, -1.5, 1.5);
  TH1D * hCharge1000 = new TH1D("hCharge1000", "hCharge1000", 3, -1.5, 1.5);
  TH1D * hCharge1500 = new TH1D("hCharge1500", "hCharge1500", 3, -1.5, 1.5);
  TH1D * hCharge2000 = new TH1D("hCharge2000", "hCharge2000", 3, -1.5, 1.5);
  TH1D * hCharge2500 = new TH1D("hCharge2500", "hCharge2500", 3, -1.5, 1.5);

  TH1D * hRadius500 = new TH1D("hRadius500", "hRadius500", 100, 0., 50000.);
  TH1D * hRadius1000 = new TH1D("hRadius1000", "hRadius1000", 100, 0., 50000.);
  TH1D * hRadius1500 = new TH1D("hRadius1500", "hRadius1500", 100, 0., 50000.);
  TH1D * hRadius2000 = new TH1D("hRadius2000", "hRadius2000", 100, 0., 50000.);
  TH1D * hRadius2500 = new TH1D("hRadius2500", "hRadius2500", 100, 0., 50000.);

  TH1D * hChi2_NDF500 = new TH1D("hChi2_NDF500", "hChi2_NDF500", 100, 0, 800);
  TH1D * hChi2_NDF1000 = new TH1D("hChi2_NDF1000", "hChi2_NDF1000", 100, 0, 800);
  TH1D * hChi2_NDF1500 = new TH1D("hChi2_NDF1500", "hChi2_NDF1500", 100, 0, 800);
  TH1D * hChi2_NDF2000 = new TH1D("hChi2_NDF2000", "hChi2_NDF2000", 100, 0, 800);
  TH1D * hChi2_NDF2500 = new TH1D("hChi2_NDF2500", "hChi2_NDF2500", 100, 0, 800);

  TH1D * hLength500 = new TH1D("hLength500", "hLength500", 100, 0, 4000);
  TH1D * hLength1000 = new TH1D("hLength1000", "hLength1000", 100, 0, 4000);
  TH1D * hLength1500 = new TH1D("hLength1500", "hLength1500", 100, 0, 4000);
  TH1D * hLength2000 = new TH1D("hLength2000", "hLength2000", 100, 0, 4000);
  TH1D * hLength2500 = new TH1D("hLength2500", "hLength2500", 100, 0, 4000);

  
  TGraph * gYZ = new TGraph();
  
  double hitLocations[3] = {0, 0, 0};
  
  int nPoint = 0;  
  int nevent = chain->GetEntries();
  cout<<"nevent = "<<nevent<<endl;
  for(int i = 0; i < nevent; i++){
    if((i+1)%(nevent/10) == 0)
      cout<<i+1<<"th event run"<<endl;
        chain->GetEntry(i);
	gYZ->Set(0);
    double length = 0;
    nPoint = 0;
    bool l1 = false, l2 = false, l3 = false, l4 = false, l5 = false;
    ND280UpPID nd280UpPID;
    for(auto sg : g4event->SegmentDetectors){
      //cout<<"aa"<<endl;
      for(int ii = 0; ii < sg.second.size();ii++){
	//cout<<length<<endl;
	if(sg.second[ii].TrackLength>=1){//&& sg.second[ii].EnergyDeposit >= 1.){
	  length+=sg.second[ii].TrackLength;
	  
	  int aveX= ((sg.second[ii].Stop.X()+sg.second[ii].Start.X())/2. +1000)/10 ;
	  int aveY= ((sg.second[ii].Stop.Y()+sg.second[ii].Start.Y())/2. +1000)/10 ;
	  int aveZ= ((sg.second[ii].Stop.Z()+sg.second[ii].Start.Z())/2. +1200)/10 ;
	  
	  hitLocations[0] =  aveX*10. + 5 + 0.;
	  //(sg.second[ii].Start.X() + sg.second[ii].Stop.X())/2.;
	  hitLocations[1] = aveY*10. + 5 + 55000.;
	  //(sg.second[ii].Start.Y() + sg.second[ii].Stop.Y())/2.;
	  hitLocations[2] = aveZ*10. + 5 - 591450.;
	  //(sg.second[ii].Start.Z() + sg.second[ii].Stop.Z())/2.;
	  
	  //      prim = sg.second[i].PrimaryId;
	  //PDG = g4event->Primaries[0].Particles[prim].PDGCode;
	  
	  //	cout<<"prim: "<<prim<<", PDG: "<<PDG<<endl;
	  
	  gYZ->SetPoint(nPoint, hitLocations[2], hitLocations[1]);
	  //	gZY->SetPointError(nPoint, 5., 5.);
	  nPoint++;
	  if (!l1 && length > 500){
	    nd280UpPID.ChargeID(*gYZ);
	    hCharge500->Fill(nd280UpPID.GetChargeID());
	    hRadius500->Fill(nd280UpPID.GetRadiusID());
	    hChi2_NDF500->Fill(nd280UpPID.GetChi2()/nd280UpPID.GetNDF());
	    hLength500->Fill(length);
	    l1 = true;
	  }
	  else if (!l2 && length > 1000){
	    nd280UpPID.ChargeID(*gYZ);
	    hCharge1000->Fill(nd280UpPID.GetChargeID());
	    hRadius1000->Fill(nd280UpPID.GetRadiusID());
	    hChi2_NDF1000->Fill(nd280UpPID.GetChi2()/nd280UpPID.GetNDF());
	    hLength1000->Fill(length);
	    l2 = true;
	  }
	  else if (!l3 && length > 1500){
	    nd280UpPID.ChargeID(*gYZ);
	    hCharge1500->Fill(nd280UpPID.GetChargeID());
	    hRadius1500->Fill(nd280UpPID.GetRadiusID());
	    hChi2_NDF1500->Fill(nd280UpPID.GetChi2()/nd280UpPID.GetNDF());
	    hLength1500->Fill(length);
	    l3 = true;
	  }
	  else if (!l4 && length > 2000){
	    nd280UpPID.ChargeID(*gYZ);
	    hCharge2000->Fill(nd280UpPID.GetChargeID());
	    hRadius2000->Fill(nd280UpPID.GetRadiusID());
	    hChi2_NDF2000->Fill(nd280UpPID.GetChi2()/nd280UpPID.GetNDF());
	    hLength2000->Fill(length);
	    l4 = true;
	  }
	  else if (!l5 && length > 2500){
	    nd280UpPID.ChargeID(*gYZ);
	    hCharge2500->Fill(nd280UpPID.GetChargeID());
	    hRadius2500->Fill(nd280UpPID.GetRadiusID());
	    hChi2_NDF2500->Fill(nd280UpPID.GetChi2()/nd280UpPID.GetNDF());
	    hLength2500->Fill(length);
	    l5 = true;
	  }
	  
	  
	}
      }
      //    cout<<"aa"<<endl; 
    }
  }
  
  TFile file(Form("../data/result_%s.root", inputname), "recreate");
  hCharge500->Write("hCharge500");
  hRadius500->Write("hRadius500");
  hChi2_NDF500->Write("hChi2_NDF500");
  hLength500->Write("hLength500");

  hCharge1000->Write("hCharge1000");
  hRadius1000->Write("hRadius1000");
  hChi2_NDF1000->Write("hChi2_NDF1000");
  hLength1000->Write("hLength1000");

  hCharge1500->Write("hCharge1500");
  hRadius1500->Write("hRadius1500");
  hChi2_NDF1500->Write("hChi2_NDF1500");
  hLength1500->Write("hLength1500");

  hCharge2000->Write("hCharge2000");
  hRadius2000->Write("hRadius2000");
  hChi2_NDF2000->Write("hChi2_NDF2000");
  hLength2000->Write("hLength2000");

  hCharge2500->Write("hCharge2500");
  hRadius2500->Write("hRadius2500");
  hChi2_NDF2500->Write("hChi2_NDF2500");
  hLength2500->Write("hLength2500");
}

