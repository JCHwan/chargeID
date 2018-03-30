#include "/Users/tangbae/edep-sim/src/TG4Event.h"

#include <iostream>

bool fCenter(double * sPoint, double * mPoint, double * ePoint, double * center);
double circle_Hi(double * x, double * p);
double circle_Lo(double * x, double * p);

void find_center2(int nn, int nnn){
  TG4Event * g4event = NULL;
  TChain * chain = new TChain("EDepSimEvents");
  chain->Add("1GeV_random-.root");
  chain->SetBranchAddress("Event", &g4event);
  
  //cout<<Argv(0)<<endl;
  
  double hitLocations[3] = {0, 0, 0};
  
  
  TGraphErrors * gYZ = new TGraphErrors();
  TGraph * gZY = new TGraph();
  
  TGraph * gCenter = new TGraph();
  
  //  TH2D * hYZ = new TH2D("hYZ", "hYZ", 14600, -200000, -54000, 18000, 520000, 600000);
  
  //  TH1D * hRadius = new TH1D("hRadius", "hRadius", 1000, 0, 80000);
  TH1D * hCentYY = new TH1D("hCentYY", "hCentYY", 1000, -120000, 120000);
  TH1D * hCentZZ = new TH1D("hCentZZ", "hCentZZ", 1000, -80000, 80000);
  
  double sPoint[2] = {0, 0};
  double mPoint[2] = {0, 0};
  double ePoint[2] = {0, 0};
  double center[2] = {0, 0}; 
  
  double centerY = 0, centerZ = 0;
  
  //  TF1 *  fFit = new TF1("fFit", "[3]*TMath::Sqrt([0]*[0] - (x - [1])*(x - [1])) + [2]", -60000., -55000.);
  //  TF1 *  fFit = new TF1("fFit", "TMath::Sqrt([0]*[0] - (x - [1])*(x - [1])) + [2]", -60000., -55000.);
  
  
  
  int nPoint = 0;
  double ncenter = 0.;
  int nevent = chain->GetEntries();
  cout<<"nevent = "<<nevent<<endl;
  chain->GetEntry(nn);
  for(auto sg : g4event->SegmentDetectors){
    for(int ii = 0; ii < sg.second.size();ii++){
      if(sg.second[ii].TrackLength>=1){//&& sg.second[ii].EnergyDeposit >= 1.){

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
	
	gZY->SetPoint(nPoint, hitLocations[2], hitLocations[1]);
	//	gZY->SetPointError(nPoint, 5., 5.);
	nPoint++;
	
      }
    }
  }
  
  //	hYZ->Fill(hitLocations[1], hitLocations[2]);
  for(int i = 0; 2*i < nPoint; i++){
    if( (i % nnn) == 0){

      gZY->GetPoint(0, sPoint[0], sPoint[1]);
      gZY->GetPoint(i, mPoint[0], mPoint[1]);
      gZY->GetPoint(2*i, ePoint[0], ePoint[1]);

      if (ncenter > 0){
	if(!fCenter(sPoint, mPoint, ePoint, center)){
	  cout<<"Failed to find center"<<endl;
	  continue;
	}
	double R = TMath::Sqrt((center[0] - mPoint[0])*(center[0] - mPoint[0]) + (center[1] - mPoint[1])*(center[1] - mPoint[1]));
	//		cout<<"center: "<<center[0]<<", "<<center[1]<<endl;
		//		cout<<"Radius: "<<R<<endl;
	//	hRadius->Fill(R);
	hCentYY->Fill(center[1]);
	hCentZZ->Fill(center[0]);
	//centerY += 
	//	gYZ->SetPoint(nPoint, center[0], center[1]);
	//	cout<<"ncenter: "<<ncenter<<endl;
      }
	ncenter += 1.;
      //      nPoint ++;
    }
  }
  
  //  double fGrad = (mPoint[1] - sPoint[1])/(mPoint[0] - sPoint[0]);
  //  double sGrad = (ePoint[1] - mPoint[1])/(ePoint[0] - mPoint[0]);
  //  cout<<"sPoint: "<<sPoint[0]<<", "<<sPoint[1]<<endl;
  //  cout<<"mPoint: "<<mPoint[0]<<", "<<mPoint[1]<<endl;
  //  cout<<"ePoint: "<<ePoint[0]<<", "<<ePoint[1]<<endl;

  //  TF1 * f1 = new TF1("f1", "-[0]*(x - [1]) + [2]", center[0], sPoint[0]);
  //  f1->SetParameters(1/fGrad, (mPoint[0] + sPoint[0])/2., (mPoint[1] + sPoint[1])/2.);
  //  TF1 * f2 = new TF1("f2", "-[0]*(x - [1]) + [2]", center[0], sPoint[0]);
  //  f2->SetParameters(1/sGrad, (mPoint[0] + ePoint[0])/2., (mPoint[1] + ePoint[1])/2.);


  
  /*  
  for (int i = 0; i < gCenter->GetN(); i++){
    double cenX, cenY;
    gCenter->GetPoint(i, cenX, cenY);
    //    cout<<cenX<<", "<<cenY<<endl;
    gYZ->SetPoint(nPoint, cenX, cenY);
    nPoint++;
  }
  */

  gZY->SetMarkerStyle(20);
  gZY->SetMarkerSize(0.5);
  /*
  TCanvas * cTrack = new TCanvas("cTrack", "cTrack", 800, 600);
  gYZ->Draw("AP");

  TCanvas * canR = new TCanvas("canR", "canR", 800, 600);
  hRadius->Draw();
  TCanvas * canY = new TCanvas("canY", "canY", 800, 600);
  hCentYY->Draw();
  TCanvas * canZ = new TCanvas("canZ", "canZ", 800, 600);
  hCentZZ->Draw();
  */

  gZY->GetPoint(nnn, ePoint[0], ePoint[1]);
  gZY->GetPoint(0, sPoint[0], sPoint[1]);
  center[0] = hCentZZ->GetBinCenter(hCentZZ->GetMaximumBin());
  center[1] = hCentYY->GetBinCenter(hCentYY->GetMaximumBin());

  cout<<"center: "<<center[0]<<", "<<center[1]<<endl;
  
  TVector3 vRadius(0, sPoint[0] - center[0], sPoint[1]-center[1]);
  //  TVector3 vRadius(0, sPoint[0]-hCentYY->GetMean(), sPoint[1] - hCentZZ->GetMean());
  TVector3 vTrack(0, ePoint[0] - sPoint[0], ePoint[1] - sPoint[1]);
  TVector3 vCenter = vRadius.Cross(vTrack);
  //  cout<<"centerHist= "<<hCentYY->GetMean()<<", "<<hCentZZ->GetMean()<<endl;
  
  double R = vRadius.Mag();
  cout<<"Radius: "<<R<<endl;
  
  //  TF1 * cHi = new TF1("cHi", circle_Hi, center[1] - R, center[0] + R, 3);
  //  cHi->SetParameters(R, center[0], center[1]);
  //  TF1 * cLo = new TF1("cLo", circle_Lo, center[0] - R, center[0] + R, 3);
  //  cLo->SetParameters(R, center[0], center[1]);

  
  TF1 * fFit = NULL;
  
  if (vCenter.X() < 0){
    gYZ->SetTitle("ID = mu-");
    fFit = new TF1("fFit", circle_Hi, center[0] - 3*R, center[0] + 3*R, 3);
    fFit->SetParameters(R, center[0], center[1]);
    gZY->Fit(fFit, "q0");
  }else{
    gYZ->SetTitle("ID = mu+");
    fFit = new TF1("fFit", circle_Lo, center[0] - 3*R, center[0] + 3*R, 3);
    fFit->SetParameters(R, center[0], center[1]);
    gZY->Fit(fFit, "q0");
  }

  cout<<"Fit"<<endl;
  //  gYZ->Fit(cHi);
  cout<<"chi: "<<fFit->GetChisquare()<<endl;
  cout<<"ndf: "<<fFit->GetNDF()<<endl;
  cout<<"chi/ndf: "<<fFit->GetChisquare()/((double)fFit->GetNDF())<<endl;

  
  //  TF1 fGausY("fGausY", "[3]*TMath::Gaus(x, [0], [1])", -120000, 120000);
  //  fGausY.SetParameters(center[1], TMath::Sqrt(TMath::Abs(center[1])), 2.*(double)hCentYY->GetEntries());
  //  hCentYY->Fit(&fGausY);
  //  TF1 fGausZ("fGausZ", "[3]*TMath::Gaus(x, [0], [1])", -80000, 80000);
  //  fGausZ.SetParameters(center[0], TMath::Sqrt(TMath::Abs(center[0])), 2.*(double)hCentZZ->GetEntries());
  //  hCentZZ->Fit(&fGausZ);

  
  //  cout<<"PVal: "<<fFit->GetProb()<<endl;
  
  

  /*
  cout<<"Fit cLo"<<endl;
  gYZ->Fit(cLo);
  cout<<"chi/ndf: "<<cLo->GetChisquare()/((double)cLo->GetNDF())<<endl;
  */
  
  TCanvas * can = new TCanvas("can", "can", 1200, 450);
  can->Divide(3, 1);
  can->cd(1);
  gZY->Draw("AP");
  gZY->SetTitle(Form("R: %.1lf, Chi/NDF: %.1lf", fFit->GetParameter(0), fFit->GetChisquare()/(double)fFit->GetNDF()));
  fFit->Draw("same");
  //  hRadius->Draw();
  //  hRadius->SetTitle(Form("R: %.1lf, max: %.1lf", R,  hRadius->GetBinCenter(hRadius->GetMaximumBin())));
  //  can->cd(2);
  //  hRadius->Draw("AP");
  //  cHi->Draw("same");
  //  cLo->Draw("same");
  can->cd(2);
  hCentYY->Draw();
  hCentYY->SetTitle(Form("max: %.1lf", center[1]));
  //  fGausY.Draw("same");
  can->cd(3);
  hCentZZ->Draw();
  hCentZZ->SetTitle(Form("max: %.1lf", center[0]));
  //  fGausZ.Draw("same");
  
  //  can->Print(Form("plots/1GeV_noError+%d.png", nn));
  can->Print(Form("plots/1GeV_mu-/1GeV_sample%d.png", nn));
  
}

bool fCenter(double * sPoint, double * mPoint, double * ePoint, double * center)
{
  double fGrad = (mPoint[1] - sPoint[1])/(mPoint[0] - sPoint[0]);
  double sGrad = (ePoint[1] - mPoint[1])/(ePoint[0] - mPoint[0]);

  //  cout<<"sPoint: "<<sPoint[0]<<", "<<sPoint[1]<<endl;
  //  cout<<"mPoint: "<<mPoint[0]<<", "<<mPoint[1]<<endl;
  //  cout<<"ePoint: "<<ePoint[0]<<", "<<ePoint[1]<<endl;
  
  //  cout<<"fGrad: "<<fGrad<<endl;
  //  cout<<"sGrad: "<<sGrad<<endl;
  
  //  cout<<"cenX: ="<<((ePoint[1]-sPoint[1]) - (mPoint[0] + ePoint[0])/fGrad + (sPoint[0] + mPoint[0])/sGrad)/(2.*(1/fGrad - 1/sGrad))<<endl;
  
  if (fGrad == sGrad)
    return false;

  ROOT::Math::SMatrix<double, 2, 2> m1;
  m1(0, 0) = mPoint[0] - sPoint[0]; 
  //  m1(0, 0) = sPoint[0] - mPoint[0]; 
  m1(0, 1) = mPoint[1] - sPoint[1]; 
  m1(1, 0) = ePoint[0] - mPoint[0]; 
  //  m1(1, 0) = mPoint[0] - ePoint[0]; 
  m1(1, 1) = ePoint[1] - mPoint[1];
  ROOT::Math::SMatrix<double, 2, 1> m2;
  m2(0, 0) = (-sPoint[0]*sPoint[0] - sPoint[1]*sPoint[1] + mPoint[0]*mPoint[0] + mPoint[1]*mPoint[1])/2.;
  //  m2(0, 0) = (sPoint[0]*sPoint[0] - sPoint[1]*sPoint[1] - mPoint[0]*mPoint[0] + mPoint[1]*mPoint[1])/2.;
  m2(1, 0) = (-mPoint[0]*mPoint[0] - mPoint[1]*mPoint[1] + ePoint[0]*ePoint[0] + ePoint[1]*ePoint[1])/2.;
  //  m2(1, 0) = (mPoint[0]*mPoint[0] - mPoint[1]*mPoint[1] - ePoint[0]*ePoint[0] + ePoint[1]*ePoint[1])/2.;
  m1.Invert();

  ROOT::Math::SMatrix<double, 2, 1> m3;
  
  m3 = m1*m2;

  center[0] = m3(0, 0);
  center[1] = m3(1, 0);
  return true;
}

double circle_Hi(double * x, double * p)
{
  double xx = x[0];
  return TMath::Sqrt(p[0]*p[0] - (xx-p[1])*(xx-p[1])) + p[2];

}
double circle_Lo(double * x, double * p)
{
  double xx = x[0];
  return -TMath::Sqrt(p[0]*p[0] - (xx-p[1])*(xx-p[1])) + p[2];

}
