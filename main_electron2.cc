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

#include "/nashome/c/chjang/duneND/ND280/ND280UpConst.hh"
#include "/nashome/c/chjang/duneND/ND280/ND280UpRecoTrack.hh"

//#include "ND280UpConst.hh"
//#include "ND280UpRecoTrack.hh"


int main(int argc, char* argv[])
{
  
  TH2F * hMuon_CosTh_TrueVsReco = new TH2F("hMuon_CosTh_TrueVsReco","Muon CosTheta True Vs Reco",50,-1,+1,50,-1,+1);
  TH2F * hPion_CosTh_TrueVsReco = new TH2F("hPion_CosTh_TrueVsReco","Pion CosTheta True Vs Reco",50,-1,+1,50,-1,+1);
  TH2F * hProt_CosTh_TrueVsReco = new TH2F("hProt_CosTh_TrueVsReco","Prot CosTheta True Vs Reco",50,-1,+1,50,-1,+1);
  TH2F * hElec_CosTh_TrueVsReco = new TH2F("hElec_CosTh_TrueVsReco","Elec CosTheta True Vs Reco",50,-1,+1,50,-1,+1);

  TH1F * hMuon_CosTh_RecMinTr = new TH1F("hMuon_CosTh_RecMinTr","Muon CosTheta Reco-True",400,-1,+1);
  TH1F * hMuon_CosTh_RecMinTr_orig = new TH1F("hMuon_CosTh_RecMinTr_orig","Muon CosTheta Reco-True_orig",400,-1,+1);
  TH1F * hPion_CosTh_RecMinTr = new TH1F("hPion_CosTh_RecMinTr","Pion CosTheta Reco-True",400,-1,+1);
  TH1F * hProt_CosTh_RecMinTr = new TH1F("hProt_CosTh_RecMinTr","Prot CosTheta Reco-True",400,-1,+1);
  TH1F * hElec_CosTh_RecMinTr = new TH1F("hElec_CosTh_RecMinTr","Elec CosTheta Reco-True",400,-1,+1);

  TH1F * hMuon_CosTh_RecMinTr2 = new TH1F("hMuon_CosTh_RecMinTr2","Muon CosTheta Reco-True2",400,-1,+1);
  TH1F * hMuon_CosTh_RecMinTr3 = new TH1F("hMuon_CosTh_RecMinTr3","Muon CosTheta Reco-True3",400,-1,+1);

  TH1F * hMuon_btnAngCos1 = new TH1F("hMuon_btnAngCos1","hMuon_btnAngCos1",2000,-1,+1);
  TH1F * hMuon_btnAngCos2 = new TH1F("hMuon_btnAngCos2","hMuon_btnAngCos2",2000,-1,+1);
  TH1F * hMuon_btnAngAbs1 = new TH1F("hMuon_btnAngAbs1","hMuon_btnAngAbs1",2000,-1,+1);
  TH1F * hMuon_btnAngAbs2 = new TH1F("hMuon_btnAngAbs2","hMuon_btnAngAbs2",2000,-1,+1);

  TH1F * hMuon_qSepInCos = new TH1F("hMuon_qSepInCos","hMuon_qSepInCos",400,-1,+1);
  TH1F * hMuon_qSepInCosF = new TH1F("hMuon_qSepInCosF","hMuon_qSepInCosF",400,-1,+1);

  TH2F * hMuon_Len_TrueVsReco = new TH2F("hMuon_Len_TrueVsReco","Muon Length True Vs Reco",50,0,+3000,50,0,+3000);
  TH2F * hPion_Len_TrueVsReco = new TH2F("hPion_Len_TrueVsReco","Pion Length True Vs Reco",50,0,+3000,50,0,+3000);
  TH2F * hProt_Len_TrueVsReco = new TH2F("hProt_Len_TrueVsReco","Prot Length True Vs Reco",50,0,+3000,50,0,+3000);
  TH2F * hElec_Len_TrueVsReco = new TH2F("hElec_Len_TrueVsReco","Elec Length True Vs Reco",50,0,+3000,50,0,+3000);

  TH1F * hMuon_Len_RecMinTr = new TH1F("hMuon_Len_RecMinTr","Muon Length Reco-True",100,-50,+50);
  TH1F * hPion_Len_RecMinTr = new TH1F("hPion_Len_RecMinTr","Pion Length Reco-True",100,-50,+50);
  TH1F * hProt_Len_RecMinTr = new TH1F("hProt_Len_RecMinTr","Prot Length Reco-True",100,-50,+50);
  TH1F * hElec_Len_RecMinTr = new TH1F("hElec_Len_RecMinTr","Elec Length Reco-True",100,-50,+50);

  TH1F * hMuon_Mom_RecMinTr = new TH1F("hMuon_Mom_RecMinTr","Muon Mom Reco-True",100,-1,+1);
  TH1F * hPion_Mom_RecMinTr = new TH1F("hPion_Mom_RecMinTr","Pion Mom Reco-True",100,-1,+1);
  TH1F * hProt_Mom_RecMinTr = new TH1F("hProt_Mom_RecMinTr","Prot Mom Reco-True",100,-1,+1);
  TH1F * hElec_Mom_RecMinTr = new TH1F("hElec_Mom_RecMinTr","Elec Mom Reco-True",100,-1,+1);

  TH2F * hMuon_Len_RecMinTr_Vs_TrLen = new TH2F("hMuon_Len_RecMinTr_Vs_TrLen","Muon Length (Reco-True) Vs True",100,-50,+50,50,0,+3000);
  TH2F * hPion_Len_RecMinTr_Vs_TrLen = new TH2F("hPion_Len_RecMinTr_Vs_TrLen","Pion Length (Reco-True) Vs True",100,-50,+50,50,0,+3000);
  TH2F * hProt_Len_RecMinTr_Vs_TrLen = new TH2F("hProt_Len_RecMinTr_Vs_TrLen","Prot Length (Reco-True) Vs True",100,-50,+50,50,0,+3000);
  TH2F * hElec_Len_RecMinTr_Vs_TrLen = new TH2F("hElec_Len_RecMinTr_Vs_TrLen","Elec Length (Reco-True) Vs True",100,-50,+50,50,0,+3000);

  TH2F * hMuon_TrMomVsRecoMom = new TH2F("hMuon_TrMomVsRecoMom","All Muons True Mom Vs reco. Mom",100,0,10000,100,0,10000);

  TH2F * hMuon_TrMomVsTrCosTh = new TH2F("hMuon_TrMomVsTrCosTh","All Muons True Mom Vs CosTheta",100,0,10000,30,-1,+1);
  TH2F * hPion_TrMomVsTrCosTh = new TH2F("hPion_TrMomVsTrCosTh","All Pions True Mom Vs CosTheta",100,0,10000,30,-1,+1);
  TH2F * hProt_TrMomVsTrCosTh = new TH2F("hProt_TrMomVsTrCosTh","All Protons True Mom Vs CosTheta",100,0,10000,30,-1,+1);
  TH2F * hElec_TrMomVsTrCosTh = new TH2F("hElec_TrMomVsTrCosTh","All Electrons True Mom Vs CosTheta",100,0,10000,30,-1,+1);

  TH2F * hMuon_RecMomVsTrCosRec = new TH2F("hMuon_RecMomVsCosRec","All Muons Rec Mom Vs CosTheta",100,0,10000,30,-1,+1);
  TH2F * hPion_RecMomVsTrCosRec = new TH2F("hPion_RecMomVsCosRec","All Pions Rec Mom Vs CosTheta",100,0,10000,30,-1,+1);
  TH2F * hProt_RecMomVsTrCosRec = new TH2F("hProt_RecMomVsCosRec","All Protons Rec Mom Vs CosTheta",100,0,10000,30,-1,+1);
  TH2F * hElec_RecMomVsTrCosRec = new TH2F("hElec_RecMomVsCosRec","All Electrons Rec Mom Vs CosTheta",100,0,10000,30,-1,+1);

  TH1F * hMuon_TrMom          = new TH1F("hMuon_TrMom","All Muons True Mom",100,0,10000);
  TH1F * hPion_TrMom          = new TH1F("hPion_TrMom","All Pions True Mom",100,0,10000);
  TH1F * hProt_TrMom          = new TH1F("hProt_TrMom","All Protons True Mom",100,0,10000);

  TH2F * hMuon_AllIso_TrMomVsTrCosTh = new TH2F("hMuon_AllIso_TrMomVsTrCosTh","All IsoTarget Muons True Mom Vs CosTheta",100,0,10000,10,-1,+1);
  TH2F * hPion_AllIso_TrMomVsTrCosTh = new TH2F("hPion_AllIso_TrMomVsTrCosTh","All IsoTarget Pions True Mom Vs CosTheta",100,0,10000,10,-1,+1);
  TH2F * hProt_AllIso_TrMomVsTrCosTh = new TH2F("hProt_AllIso_TrMomVsTrCosTh","All IsoTarget Protons True Mom Vs CosTheta",100,0,10000,10,-1,+1);
  TH2F * hElec_AllIso_TrMomVsTrCosTh = new TH2F("hElec_AllIso_TrMomVsTrCosTh","All IsoTarget Electrons True Mom Vs CosTheta",100,0,10000,10,-1,+1);
  TH2F * hMuon_EffIso_TrMomVsTrCosTh = new TH2F("hMuon_EffIso_TrMomVsTrCosTh","Efficiency IsoTarget Muons True Mom Vs CosTheta",100,0,10000,10,-1,+1);
  TH2F * hPion_EffIso_TrMomVsTrCosTh = new TH2F("hPion_EffIso_TrMomVsTrCosTh","Efficiency IsoTarget Pions True Mom Vs CosTheta",100,0,10000,10,-1,+1);
  TH2F * hProt_EffIso_TrMomVsTrCosTh = new TH2F("hProt_EffIso_TrMomVsTrCosTh","Efficiency IsoTarget Protons True Mom Vs CosTheta",100,0,10000,10,-1,+1);
  TH2F * hElec_EffIso_TrMomVsTrCosTh = new TH2F("hElec_EffIso_TrMomVsTrCosTh","Efficiency IsoTarget Electrons True Mom Vs CosTheta",100,0,10000,10,-1,+1);

  TH1F * hMuon_AllIso_TrMom = new TH1F("hMuon_AllIso_TrMom","All IsoTarget Muons True Mom",100,0,10000);
  TH1F * hPion_AllIso_TrMom = new TH1F("hPion_AllIso_TrMom","All IsoTarget Pions True Mom",100,0,10000);
  TH1F * hProt_AllIso_TrMom = new TH1F("hProt_AllIso_TrMom","All IsoTarget Protons True Mom",100,0,10000);
  TH1F * hElec_AllIso_TrMom = new TH1F("hElec_AllIso_TrMom","All IsoTarget Electrons True Mom",100,0,10000);
  TH1F * hMuon_EffIso_TrMom = new TH1F("hMuon_EffIso_TrMom","Efficiency IsoTarget Muons True Mom",100,0,10000);
  TH1F * hPion_EffIso_TrMom = new TH1F("hPion_EffIso_TrMom","Efficiency IsoTarget Pions True Mom",100,0,10000);
  TH1F * hProt_EffIso_TrMom = new TH1F("hProt_EffIso_TrMom","Efficiency IsoTarget Protons True Mom",100,0,10000);
  TH1F * hElec_EffIso_TrMom = new TH1F("hElec_EffIso_TrMom","Efficiency IsoTarget Electrons True Mom",100,0,10000);

  TH1F * hMuon_AllIso_TrCosTh = new TH1F("hMuon_AllIso_TrCosTh","All IsoTarget Muons True CosTheta",10,-1,+1);
  TH1F * hPion_AllIso_TrCosTh = new TH1F("hPion_AllIso_TrCosTh","All IsoTarget Pions True CosTheta",10,-1,+1);
  TH1F * hProt_AllIso_TrCosTh = new TH1F("hProt_AllIso_TrCosTh","All IsoTarget Protons True CosTheta",10,-1,+1);
  TH1F * hElec_AllIso_TrCosTh = new TH1F("hElec_AllIso_TrCosTh","All IsoTarget Electrons True CosTheta",10,-1,+1);
  TH1F * hMuon_EffIso_TrCosTh = new TH1F("hMuon_EffIso_TrCosTh","Efficiency IsoTarget Muons True CosTheta",10,-1,+1);
  TH1F * hPion_EffIso_TrCosTh = new TH1F("hPion_EffIso_TrCosTh","Efficiency IsoTarget Pions True CosTheta",10,-1,+1);
  TH1F * hProt_EffIso_TrCosTh = new TH1F("hProt_EffIso_TrCosTh","Efficiency IsoTarget Protons True CosTheta",10,-1,+1);
  TH1F * hElec_EffIso_TrCosTh = new TH1F("hElec_EffIso_TrCosTh","Efficiency IsoTarget Electrons True CosTheta",10,-1,+1);

  TH1F * hMuon_Len = new TH1F("hMuon_Len","Muon track length",400,0,3000); // mm 
  TH1F * hPion_Len = new TH1F("hPion_Len","Pion track length",400,0,3000);
  TH1F * hProt_Len = new TH1F("hProt_Len","Prot track length",400,0,3000);
  TH1F * hElec_Len = new TH1F("hElec_Len","Elec track length",400,0,3000);
  TH1F * hMuon_Stopped_Len = new TH1F("hMuon_Stopped_Len","Muon Stopped track length",100,0,2000); // mm 
  TH1F * hPion_Stopped_Len = new TH1F("hPion_Stopped_Len","Pion Stopped track length",100,0,2000);
  TH1F * hProt_Stopped_Len = new TH1F("hProt_Stopped_Len","Prot Stopped track length",100,0,2000);
  TH1F * hElec_Stopped_Len = new TH1F("hElec_Stopped_Len","Elec Stopped track length",100,0,2000);

  TH1F * hMuon_Edep = new TH1F("hMuon_Edep","Muon energy deposit",200,0,10000); // pe
  TH1F * hPion_Edep = new TH1F("hPion_Edep","Pion energy deposit",200,0,10000);
  TH1F * hProt_Edep = new TH1F("hProt_Edep","Proton energy deposit",200,0,10000);
  TH1F * hElec_Edep = new TH1F("hElec_Edep","Electron energy deposit",200,0,10000);
  TH1F * hMuon_Stopped_Edep = new TH1F("hMuon_Stopped_Edep","Muon Stopped energy deposit",200,0,10000); // pe
  TH1F * hPion_Stopped_Edep = new TH1F("hPion_Stopped_Edep","Pion Stopped energy deposit",200,0,10000);
  TH1F * hProt_Stopped_Edep = new TH1F("hProt_Stopped_Edep","Proton Stopped energy deposit",200,0,10000);
  TH1F * hElec_Stopped_Edep = new TH1F("hElec_Stopped_Edep","Electron Stopped energy deposit",200,0,10000);

  TH1F * hMuon_EdepOverLen = new TH1F("hMuon_EdepOverLen","Muon energy deposit over track length",200,0,200); // ~ pe / mm (cube)
  TH1F * hPion_EdepOverLen = new TH1F("hPion_EdepOverLen","Pion energy deposit over track length",200,0,200);
  TH1F * hProt_EdepOverLen = new TH1F("hProt_EdepOverLen","Prot energy deposit over track length",200,0,200);
  TH1F * hElec_EdepOverLen = new TH1F("hElec_EdepOverLen","Elec energy deposit over track length",200,0,200);
  TH1F * hMuon_Stopped_EdepOverLen = new TH1F("hMuon_Stopped_EdepOverLen","Stopping Muon energy deposit over track length",200,0,200);
  TH1F * hPion_Stopped_EdepOverLen = new TH1F("hPion_Stopped_EdepOverLen","Stopping Pion energy deposit over track length",200,0,200);
  TH1F * hProt_Stopped_EdepOverLen = new TH1F("hProt_Stopped_EdepOverLen","Stopping Prot energy deposit over track length",200,0,200);
  TH1F * hElec_Stopped_EdepOverLen = new TH1F("hElec_Stopped_EdepOverLen","Stopping Elec energy deposit over track length",200,0,200);

  TH2F * hMuon_EdepVsLen = new TH2F("hMuon_EdepVsLen","Muon energy deposit Vs track length",200,0,20000,300,0,3000); // ~ pe Vs mm (cube)
  TH2F * hPion_EdepVsLen = new TH2F("hPion_EdepVsLen","Pion energy deposit Vs track length",200,0,20000,300,0,3000); // ~ pe Vs mm (cube)
  TH2F * hProt_EdepVsLen = new TH2F("hProt_EdepVsLen","Prot energy deposit Vs track length",200,0,20000,300,0,3000); // ~ pe Vs mm (cube)
  TH2F * hElec_EdepVsLen = new TH2F("hElec_EdepVsLen","Elec energy deposit Vs track length",200,0,20000,300,0,3000); // ~ pe Vs mm (cube)
  TH2F * hMuon_Stopped_EdepVsLen = new TH2F("hMuon_Stopped_EdepVsLen","Muon Stopped energy deposit Vs track length",200,0,20000,300,0,3000); // ~ pe Vs mm (cube)
  TH2F * hPion_Stopped_EdepVsLen = new TH2F("hPion_Stopped_EdepVsLen","Pion Stopped energy deposit Vs track length",200,0,20000,300,0,3000); // ~ pe Vs mm (cube)
  TH2F * hProt_Stopped_EdepVsLen = new TH2F("hProt_Stopped_EdepVsLen","Prot Stopped energy deposit Vs track length",200,0,20000,300,0,3000); // ~ pe Vs mm (cube)
  TH2F * hElec_Stopped_EdepVsLen = new TH2F("hElec_Stopped_EdepVsLen","Elec Stopped energy deposit Vs track length",200,0,20000,300,0,3000); // ~ pe Vs mm (cube)

  TH2F * hMuon_dedxVSMom = new TH2F("hMuon_dedxVSMom","hMuon_dedxVSMom",50,0,20000,50,0,3); 
  TH2F * hPion_dedxVSMom = new TH2F("hPion_dedxVSMom","hPion_dedxVSMom",50,0,20000,50,0,3);
  TH2F * hProt_dedxVSMom = new TH2F("hProt_dedxVSMom","hProt_dedxVSMom",50,0,20000,50,0,3);

  TH1F * hLikeRatio_MuProt_TrueMu = new TH1F("hLikeRatio_MuProt_TrueMu","hLikeRatio_MuProt_TrueMu",100,-10,10);
  TH1F * hLikeRatio_MuProt_TrueProt = new TH1F("hLikeRatio_MuProt_TrueProt","hLikeRatio_MuProt_TrueProt",100,-10,10);
  TH1F * hLikeRatio_PionProt_TruePion = new TH1F("hLikeRatio_PionProt_TruePion","hLikeRatio_PionProt_TruePion",100,-10,10);
  TH1F * hLikeRatio_PionProt_TrueProt = new TH1F("hLikeRatio_PionProt_TrueProt","hLikeRatio_PionProt_TrueProt",100,-10,10);
  TH1F * hLikeRatio_MuProt_TrueMu2 = new TH1F("hLikeRatio_MuProt_TrueMu","hLikeRatio_MuProt_TrueMu",100,-10,10);
  TH1F * hLikeRatio_MuProt_TrueProt2 = new TH1F("hLikeRatio_MuProt_TrueProt","hLikeRatio_MuProt_TrueProt",100,-10,10);
  TH1F * hLikeRatio_PionProt_TruePion2 = new TH1F("hLikeRatio_PionProt_TruePion","hLikeRatio_PionProt_TruePion",100,-10,10);
  TH1F * hLikeRatio_PionProt_TrueProt2 = new TH1F("hLikeRatio_PionProt_TrueProt","hLikeRatio_PionProt_TrueProt",100,-10,10);

  TH1F * hMuon_CosTh_RecMinTrSep[20];
  TH1F * hMuon_CosTh_RecMinTrSepOrig[20];
  for(Int_t i=0;i<20;i++){
	hMuon_CosTh_RecMinTrSep[i]=new TH1F("hMuon_CosTh_RecMinTrSep","Muon CosTheta Reco-True3 Sep",100,0,+1);
        hMuon_CosTh_RecMinTrSepOrig[i]=new TH1F("hMuon_CosTh_RecMinTrSepOrig","Muon CosTheta Reco-True3 Sep Orig",100,0,+1);
	}


  int event;
  double hitLocation[3],hitPE[6],hitT[6],adc[6],loadc[6],Q[6],hitLowQ[6];
  int separateS=0,separateF=0;
  string track1Name;
  string track2Name;
  int n3Dcase = 0;
  double trueCos,trueC;
  double true3Mom[3];
  double trueLen,trueL;
  double trueMom,trueM;
  double trueCos_muon,trueC_muon;
  double trueLen_muon,trueL_muon;
  double trueMom_muon,trueM_muon,true3Mom_muon[3],true3M_muon;
  double trueCos_pion,trueC_pion;
  double trueLen_pion,trueL_pion;
  double trueMom_pion,trueM_pion,true3Mom_pion[3],true3M_pion;
  double trueCos_proton,trueC_proton;
  double trueLen_proton,trueL_proton;
  double trueMom_proton,trueM_proton,true3Mom_proton[3],true3M_proton;
  
  TH1D* recoEff_ang = new TH1D("reco_eff_ang","reco_eff_ang", 10,-1,1);
  TH1D* recoEff_mom = new TH1D("reco_eff_mom","reco_eff_mom", 21,0,2100);
  TH1D* recoPass_ang = new TH1D("recoPass_ang","recoPass_ang", 10,-1,1);
  TH1D* recoFail_ang = new TH1D("recoFail_ang","recoFail_ang", 10,-1,1);
  TH1D* recoPass_mom = new TH1D("recoPass_mom","recoPass_mom", 21,0,2100);
  TH1D* recoFail_mom = new TH1D("recoFail_mom","recoFail_mom", 21,0,2100);
  TH1D* recoPass_momP = new TH1D("recoPass_momP","recoPass_momP", 21,0,2100);
  TH1D* recoFail_momP = new TH1D("recoFail_momP","recoFail_momP", 21,0,2100);
  
  TH1D* h_contain = new TH1D("h_contain","h_contain", 100,0,1);
  TH1D* t_contain = new TH1D("t_contain","t_contain", 100,0,1);

    TH1F * hChargeID = new TH1F("hChargeID", "hChargeID", 3, -1.5, 1.5);
    TH1F * hRadiusID = new TH1F("hRadiusID", "hRadiusID", 100, 0., 30000.);
    TH1F * hCenterYID = new TH1F("hCenterYID", "hCenterYID", 100, -15000., 15000.);
    TH1F * hCenterZID = new TH1F("hCenterZID", "hCenterZID", 100, -15000., 15000.);
    TH1F * hChi2_NDF  = new TH1F("hChi2_NDF" , "hCHi2_NDF ", 100, 0, 800);

  
  int prim, PDG;
  double ener;
  int muonID = 0;
  cout<<"now doing sample "<<atoi(argv[1])<< " and distance cut for angular resolution is: "<<atof(argv[2])<<endl;
  
  //TFile file(Form("canDeleteData/testEvent_222_particleGun1000MeVMuon_30cone_sample%d.root",atoi(argv[1])));
  TFile file(Form("testEvent_%s.root",argv[1]));
  //TFile file("canDeleteData/testEvent_222_particleGun1000MeVPositron_30cone_sample0.root");
  //TFile file("testEvent_particleGun1000MeVMuon_30cone_0.4Bfield_sample0.root");
  //testEvent_particleGun1000MeVMuon_30cone_0.4Bfield_sample0.root
  //TFile file("testEvent_3DST_222_particleGun1000MeVElectron_30cone_0.4Bfield_sample0.root");
  TTree* c = (TTree*)file.Get("EDepSimTree");
  c->SetBranchAddress("event",&event);
  c->SetBranchAddress("hitLocation",&hitLocation);
  c->SetBranchAddress("hitPE",&hitPE);
  c->SetBranchAddress("hitT",&hitT);
  c->SetBranchAddress("hitADC",&adc);
  c->SetBranchAddress("hitLowADC",&loadc);
  c->SetBranchAddress("hitQ",&Q);
  c->SetBranchAddress("hitLowQ",&hitLowQ);
  c->SetBranchAddress("hitPrim",&prim);
  c->SetBranchAddress("hitPDG",&PDG);
  c->SetBranchAddress("hitE",&ener);
  c->SetBranchAddress("trueLen",&trueLen);
  c->SetBranchAddress("trueMom",&trueMom);
  c->SetBranchAddress("true3Mom",&true3Mom);
  c->SetBranchAddress("trueCos",&trueCos);
  
  Int_t nevent = c->GetEntries();
  
  Int_t nnevent =1000;
  TH2F* hist2D_XY_Q[nnevent];
  TH2F* hist2D_XZ_Q[nnevent];
  TH2F* hist2D_YZ_Q[nnevent];
  TH2F* hist2D_XY_PE[nnevent];
  TH2F* hist2D_XZ_PE[nnevent];
  TH2F* hist2D_YZ_PE[nnevent];
  TH2F* hist2D_XY_ADC[nnevent];
  TH2F* hist2D_XZ_ADC[nnevent];
  TH2F* hist2D_YZ_ADC[nnevent];

  TGraph * graphZY_E[nnevent];
  
  for(Int_t i=0;i<nnevent;i++){
    hist2D_XY_Q[i] = new TH2F("","",200,0,2000,200,0,2000);
    hist2D_XZ_Q[i] = new TH2F("","",200,0,2000,240,0,2400);
    hist2D_YZ_Q[i] = new TH2F("","",200,0,2000,240,0,2400);
    
    hist2D_XY_PE[i] = new TH2F("","",200,0,2000,200,0,2000);
    hist2D_XZ_PE[i] = new TH2F("","",200,0,2000,240,0,2400);
    hist2D_YZ_PE[i] = new TH2F("","",200,0,2000,240,0,2400);
    
    hist2D_XY_ADC[i] = new TH2F("","",200,0,2000,200,0,2000);
    hist2D_XZ_ADC[i] = new TH2F("","",200,0,2000,240,0,2400);
    hist2D_YZ_ADC[i] = new TH2F("","",200,0,2000,240,0,2400);

    graphZY_E[i] = new TGraph();
  }
  
  TH2F* hist2D_XY_E[3][nnevent];
  TH2F* hist2D_XZ_E[3][nnevent];
  TH2F* hist2D_YZ_E[3][nnevent];

  for(Int_t i=0;i<3;i++){
    for(Int_t j=0;j<nnevent;j++){
      hist2D_XY_E[i][j] = new TH2F("","",200,0,2000,200,0,2000);
      hist2D_YZ_E[i][j] = new TH2F("","",200,0,2000,240,0,2400);
      hist2D_XZ_E[i][j] = new TH2F("","",200,0,2000,240,0,2400);
    }
  }
  
  TH2D* muon2DprepCos[nnevent];
  TH2D* muon2DprepCosF[nnevent];
  for(Int_t j=0;j<nnevent;j++){
    muon2DprepCos[j] = new TH2D("","",3,0,3,240,0,2400);
    muon2DprepCosF[j] = new TH2D("","",3,0,3,240,0,2400);
  }
  int eventS=-1;
  int eventE=-2;
  int seeProton =0;
  bool newEvent=false;
  int list[100000]={};
  double happened[10000]={};
  int initA=1;
  double hitInit[3]={};
  double lastHenergy = 0;
  double hardEnergy = 0;
  double hardColl = 0;
  bool doLoop = false;
  double endPoints[200]={};
  double comparePoints[200]={};
  int rotateMove = 0;
  int passR1=0,passR2=0,passR3=0;
  double tempMean = 0, tempTot = 0;
  int rreas=0;
  int rreas2=0;
  
  int nnn = 0;
  for(Int_t ii=0;ii<nevent;ii++){
    
    c->GetEntry(ii);
    
    //if(event == 226 || event ==227) continue;
    event -= atoi(argv[3])*200;
    
    eventS = event;
    //list[eventS] =1;
    if(eventS != eventE){newEvent = true;}
    else {newEvent = false;}
    if(newEvent) {
      cout<<"event "<<event<<endl;
      cout<<hitLocation[0]<<" "<<hitLocation[1]<<" "<<hitLocation[2]<<endl;
      nnn = 0;
    }
    //if(list[eventS]==0 && newEvent) cout<<"double new "<<endl;
    if( !newEvent ){
      //if( event ==1){
      hist2D_XY_Q[event]->Fill(hitLocation[0],hitLocation[1],Q[0]+Q[1]);
      hist2D_XZ_Q[event]->Fill(hitLocation[0],hitLocation[2],Q[2]+Q[3]);
      hist2D_YZ_Q[event]->Fill(hitLocation[1],hitLocation[2],Q[4]+Q[5]);
      hist2D_XY_PE[event]->Fill(hitLocation[0],hitLocation[1],hitPE[0]+hitPE[1]);
      hist2D_XZ_PE[event]->Fill(hitLocation[0],hitLocation[2],hitPE[2]+hitPE[3]);
      hist2D_YZ_PE[event]->Fill(hitLocation[1],hitLocation[2],hitPE[4]+hitPE[5]);
      hist2D_XY_ADC[event]->Fill(hitLocation[0],hitLocation[1],adc[0]+adc[1]);
      hist2D_XZ_ADC[event]->Fill(hitLocation[0],hitLocation[2],adc[2]+adc[3]);
      hist2D_YZ_ADC[event]->Fill(hitLocation[1],hitLocation[2],adc[4]+adc[5]);

      graphZY_E[event]->SetPoint(nnn, hitLocation[2], hitLocation[1]);
      //      graphZY_E[event]->SetPointError(nnn, 5., 5.);
      nnn++;
      //cout<<"PDG and energy "<<PDG<<" "<<ener<<endl;
      
      if((PDG>100 && PDG<10000) || (PDG<-100 && PDG>-10000)){
	if(PDG>0){if(happened[PDG]==1){doLoop==false; } else doLoop == true;}
	else{if(happened[-PDG+1]==1){doLoop==false; } else doLoop == true;}
	if(lastHenergy != PDG && doLoop) {hardEnergy += trueMom;}
	//cout<<PDG<<" "<<trueMom<<" "<<ener<<endl;
	lastHenergy = PDG;
	if(PDG>0)happened[PDG]=1;
	else happened[-PDG+1]=1;
      }
      
      if((PDG>100 && PDG<10000) || (PDG<-100 && PDG>-10000)){
	hardColl += ener;
      }
      
      //proton2212  pion 211  muon 13  electron 11
      if(PDG == 11 || PDG == -11 ){
	
	//loading full PE projections here.
	muon2DprepCosF[event]->Fill(0.,hitLocation[0],(hitPE[0]+hitPE[1]+hitPE[2])/2);
	muon2DprepCosF[event]->Fill(1.,hitLocation[1],(hitPE[0]+hitPE[1]+hitPE[2])/2);
	muon2DprepCosF[event]->Fill(2.,hitLocation[2],(hitPE[0]+hitPE[1]+hitPE[2])/2);
	//if(initA==0 && TMath::Sqrt(TMath::Power(hitLocation[0]-hitInit[0],2) + TMath::Power(hitLocation[1]-hitInit[1],2) + TMath::Power(hitLocation[2]-hitInit[2],2))< 1000 ){
	hist2D_XY_E[0][event]->Fill(hitLocation[0],hitLocation[1],ener);
	hist2D_XZ_E[0][event]->Fill(hitLocation[0],hitLocation[2],ener);
	hist2D_YZ_E[0][event]->Fill(hitLocation[1],hitLocation[2],ener);
	//}
	if(initA==0 && TMath::Sqrt(TMath::Power(hitLocation[0]-hitInit[0],2) + TMath::Power(hitLocation[1]-hitInit[1],2) + TMath::Power(hitLocation[2]-hitInit[2],2))< atof(argv[2]) ){
	  
	  //for(Int_t endPLoop=0;endPLoop<100;endPLoop++){
	  //if(endPoints[endPLoop]==0){endPoints[endPLoop]=hitLocation[1]; comparePoints[endPLoop]=hitLocation[2];}
	  //}
	  
	  /*
	    if(endPoints[0]==0){endPoints[0]=hitLocation[1]; comparePoints[0]=hitLocation[2];}
	    else if(endPoints[1]==0){endPoints[1]=hitLocation[1]; comparePoints[1]=hitLocation[2];}
	    else if(endPoints[2]==0){endPoints[2]=hitLocation[1]; comparePoints[2]=hitLocation[2];}
	    
	    if(rotateMove == 0) {endPoints[3] = hitLocation[1]; rotateMove = 1; comparePoints[3]=hitLocation[2];}
	    if(rotateMove == 1) {endPoints[4] = hitLocation[1]; rotateMove = 2; comparePoints[4]=hitLocation[2];}
	    if(rotateMove == 2) {endPoints[5] = hitLocation[1]; rotateMove = 0; comparePoints[5]=hitLocation[2];}
	    }*/
	  //hist2D_XY_E[0][event]->Fill(hitLocation[0],hitLocation[1],ener);
	  //hist2D_XZ_E[0][event]->Fill(hitLocation[0],hitLocation[2],ener);
	  //hist2D_YZ_E[0][event]->Fill(hitLocation[1],hitLocation[2],ener);
	  
	  // PE /50 works fine, /200 works bad for getting rid of delta ray.
	  muon2DprepCos[event]->Fill(0.,hitLocation[0],(hitPE[0]+hitPE[1]+hitPE[2])/2);
	  muon2DprepCos[event]->Fill(1.,hitLocation[1],(hitPE[0]+hitPE[1]+hitPE[2])/2);
	  muon2DprepCos[event]->Fill(2.,hitLocation[2],(hitPE[0]+hitPE[1]+hitPE[2])/2);
	  
	  trueCos_muon = trueCos;
	  trueLen_muon = trueLen;
	  trueMom_muon = trueMom;
	  true3Mom_muon[0] = true3Mom[0];
	  true3Mom_muon[1] = true3Mom[1];
	  true3Mom_muon[2] = true3Mom[2];
	  
	}
	
	if(initA==1) {
	  hitInit[0]=hitLocation[0];
	  hitInit[1]=hitLocation[1];
	  hitInit[2]=hitLocation[2];
	  initA=0;
	}
      }
      
      if(PDG == 211 || PDG == -211 ){
	hist2D_XY_E[1][event]->Fill(hitLocation[0],hitLocation[1],ener);
	hist2D_XZ_E[1][event]->Fill(hitLocation[0],hitLocation[2],ener);
	hist2D_YZ_E[1][event]->Fill(hitLocation[1],hitLocation[2],ener);
	trueCos_pion = trueCos;
	trueLen_pion = trueLen;
	trueMom_pion = trueMom;
	true3Mom_pion[0] = true3Mom[0];
	true3Mom_pion[1] = true3Mom[1];
	true3Mom_pion[2] = true3Mom[2];
      }
      if( PDG == 2212 ){hist2D_XY_E[2][event]->Fill(hitLocation[0],hitLocation[1],ener);
	hist2D_XZ_E[2][event]->Fill(hitLocation[0],hitLocation[2],ener);
	hist2D_YZ_E[2][event]->Fill(hitLocation[1],hitLocation[2],ener);
	trueCos_proton = trueCos;
	trueLen_proton = trueLen;
	trueMom_proton = trueMom;
	true3Mom_proton[0] = true3Mom[0];
	true3Mom_proton[1] = true3Mom[1];
	true3Mom_proton[2] = true3Mom[2];
      }
    }
    //list[ii]=1;
    //eventE = event;
    //}
    
    if(newEvent && ii>0){
      
      cout<<"hadronic containment.. "<<hardColl<<" "<<hardEnergy<<" "<<hardColl/hardEnergy<<endl;
      h_contain -> Fill(hardColl/hardEnergy);
      hardColl=0;
      hardEnergy=0;
      lastHenergy=0;
      for(Int_t hloop=0;hloop<10000;hloop++){happened[hloop]=0;}
      
      //      if(hist2D_XY_E[0][event-1]->Integral() <=0 || event>=1000 ) continue;
      std::cout << "Going to do tracking for event " <<event<< std::endl;
      
      //TFile input2D("2DExample.root");
      
      // Initialize the object for track reconstruction
      ND280UpRecoTrack nd280UpRecoTrack;
      /*
	TH2F* pp1 = (TH2F*)input2D.Get("XY_E_muon");
	TH2F* pp2 = (TH2F*)input2D.Get("XZ_E_muon");
	TH2F* pp3 = (TH2F*)input2D.Get("YZ_E_muon");
	TH2F* pp4 = (TH2F*)input2D.Get("XY_E_pion");
	TH2F* pp5 = (TH2F*)input2D.Get("XZ_E_pion");
	TH2F* pp6 = (TH2F*)input2D.Get("YZ_E_pion");
	
	TH2F* f2d_xy = (TH2F*)input2D.Get("XY_E_muon");
	TH2F* f2d_xz = (TH2F*)input2D.Get("XZ_E_muon");
	TH2F* f2d_yz = (TH2F*)input2D.Get("YZ_E_muon");
	TH2F* f2d_xy_other = (TH2F*)input2D.Get("XY_E_pion");
	TH2F* f2d_xz_other = (TH2F*)input2D.Get("XZ_E_pion");
	TH2F* f2d_yz_other = (TH2F*)input2D.Get("YZ_E_pion");
      */
      nd280UpRecoTrack.SetMPPCXY(hist2D_XY_E[0][event-1]);
      nd280UpRecoTrack.SetMPPCXZ(hist2D_XZ_E[0][event-1]);
      nd280UpRecoTrack.SetMPPCYZ(hist2D_YZ_E[0][event-1]);
            
      for(int iiii=0;iiii<10;iiii++){
        for(int jjjj=0;jjjj<10;jjjj++){
	  // cout<<f2d_xy->GetBinContent(iiii,jjjj)<<endl;
        }
      }
      
      nd280UpRecoTrack.SetMinPE(0.2); // it is 2. initially
      
      nd280UpRecoTrack.SetTrackSeparationMin(10); // (mm) min track distance is 1 cube
      
      nd280upconv::TargetType_t DetType = nd280upconv::kSuperFGD;
      nd280UpRecoTrack.DoTracking(nd280upconv::kSuperFGD); // run the tracking process
      
      
      
      // Check the track separation
      // if the reco track is separated from all the other tracks
      
      bool isseparated = true;
      
      
      // Check separation between current "itrk" and other tracks "itrkoth"
      
      nd280UpRecoTrack.SetMPPCXY_Other(hist2D_XY_E[1][event-1]);
      nd280UpRecoTrack.SetMPPCXZ_Other(hist2D_XZ_E[1][event-1]);
      nd280UpRecoTrack.SetMPPCYZ_Other(hist2D_YZ_E[1][event-1]);
      
      nd280UpRecoTrack.DoTrackSeparation();
      
      
      isseparated = nd280UpRecoTrack.IsSeparated();
      
      cout<<"well.. isseparted result is "<<isseparated<<endl;
      if (isseparated) separateS ++;
      if (!isseparated) separateF ++;       
      //
      // Get the Reco
      //
      
      // if the reco track is reconstructed
      bool isreco = nd280UpRecoTrack.IsReco();
      // if the reco track is OutFV (entering or exiting)
      bool isoutfv = nd280UpRecoTrack.IsOutFV();
      // reco track deposited energy
      double trkedep = nd280UpRecoTrack.GetEdep();
      // reco track length
      double trklen_reco = nd280UpRecoTrack.GetLength();
      double trklen_recoX = nd280UpRecoTrack.GetLengthX();
      double trklen_recoY = nd280UpRecoTrack.GetLengthY();
      double trklen_recoZ = nd280UpRecoTrack.GetLengthZ();
      double trklen_recoXA = nd280UpRecoTrack.GetLengthX();
      double trklen_recoYA = nd280UpRecoTrack.GetLengthY();
      double trklen_recoZA = nd280UpRecoTrack.GetLengthZ();
      // reco track costheta
      double costh_reco_orig = nd280UpRecoTrack.GetRecoCosTheta();
      double costh_reco = nd280UpRecoTrack.GetRecoCosTheta();
      cout<<"straight line angle "<<costh_reco<<endl;
      
      TH1D* tDreco;
      tDreco = nd280UpRecoTrack.ThreeDLineFit(*muon2DprepCos[event-1]);
      double tDcos = tDreco->GetBinContent(4);
      std::cout<<"^^^^^^^^^^^^^^^^^^^ matching check "<<tDreco->GetBinContent(1)<<" "<<tDreco->GetBinContent(2)<<" "<<tDreco->GetBinContent(3)<<" "<<tDcos<<std::endl;
      //double tDcos = nd280UpRecoTrack.ThreeDLineFit(*muon2DprepCos[event-1]);
      //if(tDcos > 0.95) 
      //{
      costh_reco = tDcos;
      trklen_recoXA = tDreco->GetBinContent(1);
      trklen_recoYA = tDreco->GetBinContent(2);
      trklen_recoZA = tDreco->GetBinContent(3);
      n3Dcase ++ ;
      //}
      
      double utrklen_recoX = trklen_recoX/TMath::Sqrt(trklen_recoX*trklen_recoX+trklen_recoY*trklen_recoY+trklen_recoZ*trklen_recoZ);
      double utrklen_recoY = trklen_recoY/TMath::Sqrt(trklen_recoX*trklen_recoX+trklen_recoY*trklen_recoY+trklen_recoZ*trklen_recoZ);
      double utrklen_recoZ = trklen_recoZ/TMath::Sqrt(trklen_recoX*trklen_recoX+trklen_recoY*trklen_recoY+trklen_recoZ*trklen_recoZ);
      double utrklen_recoXA = trklen_recoXA/TMath::Sqrt(trklen_recoXA*trklen_recoXA+trklen_recoYA*trklen_recoYA+trklen_recoZA*trklen_recoZA);
      double utrklen_recoYA = trklen_recoYA/TMath::Sqrt(trklen_recoXA*trklen_recoXA+trklen_recoYA*trklen_recoYA+trklen_recoZA*trklen_recoZA);
      double utrklen_recoZA = trklen_recoZA/TMath::Sqrt(trklen_recoXA*trklen_recoXA+trklen_recoYA*trklen_recoYA+trklen_recoZA*trklen_recoZA);
      
      double utrue3Mom_muonX = true3Mom_muon[0]/TMath::Sqrt(true3Mom_muon[0]*true3Mom_muon[0]+true3Mom_muon[1]*true3Mom_muon[1]+true3Mom_muon[2]*true3Mom_muon[2]);
      double utrue3Mom_muonY = true3Mom_muon[1]/TMath::Sqrt(true3Mom_muon[0]*true3Mom_muon[0]+true3Mom_muon[1]*true3Mom_muon[1]+true3Mom_muon[2]*true3Mom_muon[2]);
      double utrue3Mom_muonZ = true3Mom_muon[2]/TMath::Sqrt(true3Mom_muon[0]*true3Mom_muon[0]+true3Mom_muon[1]*true3Mom_muon[1]+true3Mom_muon[2]*true3Mom_muon[2]);
      
      if((utrue3Mom_muonX>0 && utrklen_recoXA<0) || (utrue3Mom_muonX<0 && utrklen_recoXA>0)){utrklen_recoXA *= -1;}
      if((utrue3Mom_muonY>0 && utrklen_recoYA<0) || (utrue3Mom_muonY<0 && utrklen_recoYA>0)){utrklen_recoYA *= -1;}
      
      cout<<"three dimensional fit angle "<<costh_reco<<endl;
      cout<<"*************************** Angle between reco. and true tracks: "<<utrklen_recoXA<<" "<<utrklen_recoYA<<" "<<utrklen_recoZA<<" " <<(utrklen_recoXA*utrue3Mom_muonX+utrklen_recoYA*utrue3Mom_muonY+utrklen_recoZA*utrue3Mom_muonZ)/(TMath::Sqrt(TMath::Power(utrklen_recoXA,2)+TMath::Power(utrklen_recoYA,2)+TMath::Power(utrklen_recoZA,2))*TMath::Sqrt(TMath::Power(utrue3Mom_muonX,2)+TMath::Power(utrue3Mom_muonY,2)+TMath::Power(utrue3Mom_muonZ,2)) )<<endl; 
      
      //cout<<"-----------------------------------------------------------------------------------------"<<endl;
      //cout<<"-----------------------------------------------------------------------------------------"<<endl;
      //cout<<"list of reco.A and three-true-mom  "<<utrklen_recoXA<<" "<<utrklen_recoYA<<" "<<utrklen_recoZA<<" "<<utrue3Mom_muonX<<" "<<utrue3Mom_muonY<<" "<<utrue3Mom_muonZ<<endl;
      //cout<<"-----------------------------------------------------------------------------------------"<<endl;
      //cout<<"-----------------------------------------------------------------------------------------"<<endl;
      
      cout<<"-----------------------------------------------------------------------------------------"<<endl;
      /*
	cout<<endPoints[0]<<" "<<comparePoints[0]-hitInit[2]<<" "<<(comparePoints[0]-hitInit[2])* utrklen_recoYA/utrklen_recoZA + hitInit[1]<<endl;
	cout<<endPoints[1]<<" "<<comparePoints[1]-hitInit[2]<<" "<<(comparePoints[1]-hitInit[2])* utrklen_recoYA/utrklen_recoZA + hitInit[1]<<endl;
	cout<<endPoints[2]<<" "<<comparePoints[2]-hitInit[2]<<" "<<(comparePoints[2]-hitInit[2])* utrklen_recoYA/utrklen_recoZA + hitInit[1]<<endl;
	cout<<endPoints[3]<<" "<<comparePoints[3]-hitInit[2]<<" "<<(comparePoints[3]-hitInit[2])* utrklen_recoYA/utrklen_recoZA + hitInit[1]<<endl;
	cout<<endPoints[4]<<" "<<comparePoints[4]-hitInit[2]<<" "<<(comparePoints[4]-hitInit[2])* utrklen_recoYA/utrklen_recoZA + hitInit[1]<<endl;
	cout<<endPoints[5]<<" "<<comparePoints[5]-hitInit[2]<<" "<<(comparePoints[5]-hitInit[2])* utrklen_recoYA/utrklen_recoZA + hitInit[1]<<endl;
	
	if ( endPoints[0] > (comparePoints[0]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1] && endPoints[3] < (comparePoints[3]-hitInit[2])* utrklen_recoYA/utrklen_recoZA + hitInit[1]){cout<<"B-field bending pass 1 "<<endl; passR1++; }
	if ( endPoints[0] > (comparePoints[0]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1] && endPoints[3] < (comparePoints[3]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1] && endPoints[1] > (comparePoints[1]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1] && endPoints[4] < (comparePoints[4]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1]){cout<<"B-field bending pass 2 "<<endl; passR2++; }
	if ( endPoints[0] > (comparePoints[0]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1] && endPoints[3] < (comparePoints[3]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1] && endPoints[1] > (comparePoints[1]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1] && endPoints[4] < (comparePoints[4]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1] && endPoints[2] > (comparePoints[2]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1] && endPoints[5] < (comparePoints[5]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1]){cout<<"B-field bending pass 3 "<<endl; passR3++;}
      */
      double clarH[200]={};
      for(Int_t endPLoop=0; endPLoop<200; endPLoop++){
	tempMean = 0; tempTot = 0;
	for(Int_t smLoop=0;smLoop<hist2D_YZ_E[0][event-1]->GetNbinsX();smLoop++){
	  tempMean += hist2D_YZ_E[0][event-1]->GetBinContent(smLoop+1,endPLoop+1);
	  tempTot += hist2D_YZ_E[0][event-1]->GetBinContent(smLoop+1,endPLoop+1)*(10*smLoop+5) ;
	  //if(hist2D_YZ_E[0][event-1]->GetBinContent(smLoop+1,endPLoop+1)) { tempMean++; tempTot += 10* smLoop + 5;}
	  
	  //      for(Int_t smLoop=0;smLoop<muon2DprepCosF[event-1]->GetNbinsX();smLoop++){
	  //              tempMean += muon2DprepCosF[event-1]->GetBinContent(smLoop+1,endPLoop+1);
	  //        tempTot += muon2DprepCosF[event-1]->GetBinContent(smLoop+1,endPLoop+1)*(10*smLoop+5) ;
	}
	if(tempMean){
	  comparePoints[endPLoop]=10. * endPLoop+5;
	  //cout<<tempTot/tempMean<<" "<<comparePoints[endPLoop]-hitInit[2]<<" "<<(comparePoints[endPLoop]-hitInit[2])* utrklen_recoYA/utrklen_recoZA<<"  "<<(comparePoints[endPLoop]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1]<<endl;
	  clarH[endPLoop] = tempTot/tempMean;
	  //cout<<clarH[endPLoop]<<endl;
	  //if (utrklen_recoZA && (tempTot/tempMean) > (comparePoints[endPLoop]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1] && endPLoop<100 )
	  //{passR1 ++;} 
	  
	  //if(utrklen_recoZA  && comparePoints[endPLoop]-hitInit[2]>0 && endPLoop<100 ){rreas ++ ;}
	  rreas++;
	}
      }
      
      //if( (clarH[0]>(comparePoints[0]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1] && clarH[rreas]<(comparePoints[rreas]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1]) || (clarH[1]>(comparePoints[1]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1] && clarH[rreas-1]<(comparePoints[rreas-1]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1]) || (clarH[2]>(comparePoints[2]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1] && clarH[rreas-2]<(comparePoints[rreas-2]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1]) ) passR1++;
      /*
	if( clarH[4] && ((comparePoints[30]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1]) && ((comparePoints[31]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1] ) && ((comparePoints[32]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1]) ){
	if( TMath::Abs(clarH[4]-((comparePoints[4]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1])) < TMath::Abs(clarH[30]-((comparePoints[30]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1])) &&  TMath::Abs(clarH[4]-((comparePoints[4]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1])) < TMath::Abs(clarH[31]-((comparePoints[31]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1])) &&  TMath::Abs(clarH[4]-((comparePoints[4]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1])) < TMath::Abs(clarH[32]-((comparePoints[32]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1]))  ) 
	{ 
	passR1++;
	hMuon_qSepInCos->Fill(costh_reco);
	}
	else{
	hMuon_qSepInCosF->Fill(costh_reco);
	}
      */
      Int_t leftSid=0;
      Int_t righSid=0;
      for(Int_t dedLoop=0;dedLoop<200;dedLoop++){
	if( clarH[dedLoop] && ((comparePoints[dedLoop]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1])  ){
	  if( clarH[dedLoop]>((comparePoints[dedLoop]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1])  ) righSid++;
	  else leftSid ++;
	}
      }
      if((leftSid>0 && righSid>0 ) && leftSid > righSid) {passR1++; hMuon_qSepInCos->Fill(costh_reco);}
      else if ((leftSid>0 && righSid>0 ) && leftSid < righSid) {hMuon_qSepInCosF->Fill(costh_reco); }
      std::cout<<"siding test "<<leftSid<<" "<<righSid<<std::endl;
      if(leftSid>0 && righSid>0) rreas2++;
      
      if((leftSid>0 && righSid>0 ) && leftSid > righSid && leftSid/righSid > 2.) passR2++;
      /*
	if( clarH[4] && ((comparePoints[20]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1]) && ((comparePoints[21]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1] ) && ((comparePoints[22]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1]) ){
	if( TMath::Abs(clarH[4]-((comparePoints[4]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1])) < TMath::Abs(clarH[20]-((comparePoints[20]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1])) &&  TMath::Abs(clarH[4]-((comparePoints[4]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1])) < TMath::Abs(clarH[21]-((comparePoints[21]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1])) &&  TMath::Abs(clarH[4]-((comparePoints[4]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1])) < TMath::Abs(clarH[22]-((comparePoints[22]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1]))  ) 
	{ 
	passR1++;
	hMuon_qSepInCos->Fill(costh_reco);
	}
	else{
	hMuon_qSepInCosF->Fill(costh_reco);
	}
	
	
	cout<<"reason test.. "<<TMath::Abs(clarH[4]-((comparePoints[4]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1]))<<" "<<TMath::Abs(clarH[30]-((comparePoints[30]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1]))<<" "<<TMath::Abs(clarH[31]-((comparePoints[31]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1]))<<" "<<TMath::Abs(clarH[32]-((comparePoints[32]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1]))<<endl;
	rreas2 ++;
	}
      */
      
      /*
	for(Int_t endPLoop=0; endPLoop<50; endPLoop++){
	cout<<endPoints[endPLoop]<<" "<<comparePoints[endPLoop]-hitInit[2]<<" "<<(comparePoints[endPLoop]-hitInit[2])* utrklen_recoYA/utrklen_recoZA<<"  "<<(comparePoints[endPLoop]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1]<<endl;
	if ( endPoints[endPLoop] > (comparePoints[endPLoop]-hitInit[2])* utrklen_recoYA/utrklen_recoZA+ hitInit[1] )
	{passR1 ++;} 
	}
      */
      cout<<"-----------------------------------------------------------------------------------------"<<endl;
      
      
      double btnAng1 = (utrklen_recoX*utrue3Mom_muonX+utrklen_recoY*utrue3Mom_muonY+utrklen_recoZ*utrue3Mom_muonZ)/(TMath::Sqrt(TMath::Power(utrklen_recoX,2)+TMath::Power(utrklen_recoY,2)+TMath::Power(utrklen_recoZ,2))*TMath::Sqrt(TMath::Power(utrue3Mom_muonX,2)+TMath::Power(utrue3Mom_muonY,2)+TMath::Power(utrue3Mom_muonZ,2)) );
      double btnAng2 = (utrklen_recoXA*utrue3Mom_muonX+utrklen_recoYA*utrue3Mom_muonY+utrklen_recoZA*utrue3Mom_muonZ)/(TMath::Sqrt(TMath::Power(utrklen_recoXA,2)+TMath::Power(utrklen_recoYA,2)+TMath::Power(utrklen_recoZA,2))*TMath::Sqrt(TMath::Power(utrue3Mom_muonX,2)+TMath::Power(utrue3Mom_muonY,2)+TMath::Power(utrue3Mom_muonZ,2)) );
      double btnAng3 = TMath::ACos(btnAng1);
      double btnAng4 = TMath::ACos(btnAng2);	
      //if(btnAng4>0.8 && event>5){cout<<"Stopping due to too high scattering.. at event "<<event<<endl; exit(1); }
      
      hMuon_btnAngCos1->Fill(btnAng1);
      hMuon_btnAngCos2->Fill(btnAng2);
      hMuon_btnAngAbs1->Fill(btnAng3);
      hMuon_btnAngAbs2->Fill(btnAng4);
      hMuon_dedxVSMom->Fill(TMath::Sqrt(TMath::Power(true3Mom_muon[0],2)+TMath::Power(true3Mom_muon[1],2)+TMath::Power(true3Mom_muon[2],2)),trkedep/trklen_reco);
      
      double costh_reco2 = TMath::ACos(costh_reco); 
      double costh_reco2_orig = TMath::ACos(costh_reco_orig);
      
      //cout<<"-------------------- original and 3D fit comparison: "<<costh_reco2_orig<<" "<<costh_reco2<<endl;
      //if(costh_reco2_orig>costh_reco2) {downSel++;}
      //else {upSel++;}
      
      TFile inputPDF("PID_PDF.root");
      TH1F* muonPDF = (TH1F*)inputPDF.Get("Muon");
      TH1F* pionPDF = (TH1F*)inputPDF.Get("Pion");
      TH1F* protPDF = (TH1F*)inputPDF.Get("Prot");
      TH1F* elecPDF = (TH1F*)inputPDF.Get("Elec");
      
      // PDF is not binning-dependent! -Guang Oct.9 2017
      ND280UpPID nd280UpPID;
      nd280UpPID.SetPDF("Muon",muonPDF); // ok until TSpline3 (no TF1!)
      nd280UpPID.SetPDF("Pion",pionPDF);
      nd280UpPID.SetPDF("Prot",protPDF);
      nd280UpPID.SetPDF("Elec",elecPDF);
      nd280UpPID.ChargeID(*graphZY_E[event-1]);
      hChargeID->Fill((float)nd280UpPID.GetChargeID());
      hRadiusID->Fill((float)nd280UpPID.GetRadiusID());
      hCenterYID->Fill((float)nd280UpPID.GetCenterYID());
      hCenterZID->Fill((float)nd280UpPID.GetCenterZID());
      hChi2_NDF ->Fill((float)(nd280UpPID.GetChi2()/nd280UpPID.GetNDF()));
      
      
      cout<<"track length and energy deposit "<<trklen_reco<<" "<<trkedep<<endl;
      double logratio = nd280UpPID.CalcLogLikeRatio("Muon","Prot",trkedep/trklen_reco);
      double logratio2 = nd280UpPID.CalcLogLikeRatio("Muon","Pion",trkedep/trklen_reco);
      double logratio3 = nd280UpPID.CalcLogLikeRatio("Muon","Elec",trkedep/trklen_reco);
      //hLikeRatio_MuProt_TrueMu->Fill(logratio2);
      cout<<"dE/dx AND PID Muon/Proton and Muon/Pion "<<trkedep/trklen_reco<<" "<< logratio<<" "<<logratio2<<endl;
      
      hLikeRatio_MuProt_TrueMu->Fill(logratio);
      hLikeRatio_MuProt_TrueProt->Fill(logratio2);
      hLikeRatio_PionProt_TrueProt->Fill(logratio3);
      if(logratio>0 && logratio2>0 ) {track1Name = "muon"; }
      if(logratio<0 && logratio2>0 ) {track1Name = "proton"; }
      if(logratio2<0 ) {track1Name = "pion"; }
      
      hMuon_RecMomVsTrCosRec->Fill(trkedep,costh_reco);
      
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      //Proton
      
      if(trueMom_proton >0){
	ND280UpRecoTrack nd280UpRecoTrackP;
	
	nd280UpRecoTrackP.SetMPPCXY(hist2D_XY_E[2][event-1]);
	nd280UpRecoTrackP.SetMPPCXZ(hist2D_XZ_E[2][event-1]);
	nd280UpRecoTrackP.SetMPPCYZ(hist2D_YZ_E[2][event-1]);
	
	nd280UpRecoTrackP.SetMinPE(0.2); // it is 2. initially
	
	nd280UpRecoTrackP.SetTrackSeparationMin(10); // (mm) min track distance is 1 cube
	
	nd280UpRecoTrackP.DoTracking(nd280upconv::kSuperFGD); // run the tracking process
	
	
	// Check the track separation
	// if the reco track is separated from all the other tracks
	
	bool isseparatedP = true;
	
	
        // Check separation between current "itrk" and other tracks "itrkoth"
	
        nd280UpRecoTrackP.SetMPPCXY_Other(hist2D_XY_E[0][event-1]);
        nd280UpRecoTrackP.SetMPPCXZ_Other(hist2D_XZ_E[0][event-1]);
        nd280UpRecoTrackP.SetMPPCYZ_Other(hist2D_YZ_E[0][event-1]);
	
        nd280UpRecoTrackP.DoTrackSeparation();
	
        isseparatedP = nd280UpRecoTrackP.IsSeparated();
        cout<<"well.. isseparted result for Proton is "<<isseparatedP<<endl;
	//
	// Get the Reco
	//
	
	// if the reco track is reconstructed
	bool isrecoP = nd280UpRecoTrackP.IsReco();
	// if the reco track is OutFV (entering or exiting)
	bool isoutfvP = nd280UpRecoTrackP.IsOutFV();
	// reco track deposited energy
	double trkedepP = nd280UpRecoTrackP.GetEdep();
	// reco track length
	double trklen_recoP = nd280UpRecoTrackP.GetLength();
	double trklen_recoXP = nd280UpRecoTrackP.GetLengthX();
	double trklen_recoYP = nd280UpRecoTrackP.GetLengthY();
	double trklen_recoZP = nd280UpRecoTrackP.GetLengthZ();
	// reco track costheta
	double costh_recoP = nd280UpRecoTrackP.GetRecoCosTheta();
	
	hProt_RecMomVsTrCosRec->Fill(trkedepP,costh_recoP);
	
	hProt_dedxVSMom->Fill(TMath::Sqrt(TMath::Power(true3Mom_proton[0],2)+TMath::Power(true3Mom_proton[1],2)+TMath::Power(true3Mom_proton[2],2)),trkedepP/trklen_recoP);
	
	if(!isoutfvP){
	  if(isrecoP && isseparatedP) {recoPass_momP->Fill(trueM_proton);}
	  else    {recoFail_momP->Fill(trueM_proton);}
	}
	
	seeProton ++;
      }
      //////////////////////////////////////////////////////////////////////////////////////////////////////////
      
      
      trueC_muon=trueCos_muon;
      trueL_muon=trueLen_muon;
      trueM_muon=trueMom_muon;
      trueC_pion=trueCos_pion;
      trueL_pion=trueLen_pion;
      trueM_pion=trueMom_pion;
      trueC_proton=trueCos_proton;
      trueL_proton=trueLen_proton;
      trueM_proton=trueMom_proton;
      
      if(track1Name == "muon"){ muonID++; }
      
      //if(hitInit[0]>10 && hitInit[0]<990 && hitInit[1]>10 && hitInit[1]<990 && hitInit[2]>10 && hitInit[2]<990){
      //if(track1Name == "muon"){
      hMuon_Len->Fill(trklen_reco);
      hMuon_Edep->Fill(trkedep);
      hMuon_AllIso_TrCosTh->Fill(costh_reco);
      
      hMuon_CosTh_TrueVsReco->Fill(costh_reco ,trueC_muon);
      hMuon_Len_TrueVsReco->Fill(trklen_reco ,trueL_muon);
      hMuon_TrMomVsRecoMom->Fill(trkedep ,trueM_muon);	
      hMuon_CosTh_RecMinTr->Fill(TMath::ACos(trueC_muon));
      hMuon_CosTh_RecMinTr2->Fill(costh_reco2);
      hMuon_CosTh_RecMinTr3->Fill(costh_reco2_orig);
      for(Int_t momm=0;momm<20;momm++){
	if(trueM_muon>momm*500 && trueM_muon<(momm+1)*500){
	  hMuon_CosTh_RecMinTrSep[momm]->Fill(btnAng4); 
	  hMuon_CosTh_RecMinTrSepOrig[momm]->Fill(btnAng3);
	}
      }
      hMuon_CosTh_RecMinTr_orig->Fill(costh_reco2-TMath::ACos(trueC_muon));
      hMuon_Mom_RecMinTr->Fill((trkedep-trueM_muon)/trueM_muon);
      //}
      
      hMuon_TrMomVsTrCosTh->Fill(trueM_muon, trueC_muon);
      hPion_TrMomVsTrCosTh->Fill(trueM_pion, trueC_pion);
      hProt_TrMomVsTrCosTh->Fill(trueM_proton, trueC_proton);
      
      hMuon_TrMom->Fill(trueM_muon);
      hPion_TrMom->Fill(trueM_pion);
      hProt_TrMom->Fill(trueM_proton);
      
      if(!isoutfv){
	if(isreco && isseparated ) {recoPass_ang->Fill(trueC_muon); recoPass_mom->Fill(trueM_muon);}     
	else    {recoFail_ang->Fill(trueC_muon); recoFail_mom->Fill(trueM_muon);}
      }
      //}
      trueCos_muon = -1;
      trueLen_muon = -1;
      trueMom_muon = -1;
      trueCos_pion = -1;
      trueLen_pion = -1;
      trueMom_pion = -1;
      trueCos_proton = -1;
      trueLen_proton = -1;
      trueMom_proton = -1;
      initA = 1;
      
      rotateMove = 0;
      for(Int_t i=0;i<6;i++){endPoints[i]=0;}
      /*
	ND280UpRecoTrack nd280UpRecoTrack2;
	
	nd280UpRecoTrack2.SetMPPCXY(hist2D_XY_E[1][event-1]);
	nd280UpRecoTrack2.SetMPPCXZ(hist2D_XZ_E[1][event-1]);
	nd280UpRecoTrack2.SetMPPCYZ(hist2D_YZ_E[1][event-1]);
	bool isreco2 = nd280UpRecoTrack2.IsReco();
	bool isoutfv2 = nd280UpRecoTrack2.IsOutFV();
	double trkedep2 = nd280UpRecoTrack2.GetEdep();
	double trklen_reco2 = nd280UpRecoTrack2.GetLength();
	double trklen_recoX2 = nd280UpRecoTrack2.GetLengthX();
	double trklen_recoY2 = nd280UpRecoTrack2.GetLengthY();
	double trklen_recoZ2 = nd280UpRecoTrack2.GetLengthZ();
	
	double costh_reco2 = nd280UpRecoTrack2.GetRecoCosTheta();
	ND280UpPID nd280UpPID2;
	nd280UpPID2.SetPDF("Muon",muonPDF); // ok until TSpline3 (no TF1!)
	nd280UpPID2.SetPDF("Pion",pionPDF);
	nd280UpPID2.SetPDF("Prot",protPDF);
	nd280UpPID2.SetPDF("Elec",elecPDF);
	//if(isseparated){
        cout<<endl;
        cout<<"---------------------------------------------------------------------------"<<endl;
        cout<<"Now you are in the second track"<<endl;
        cout<<"track length and energy deposit "<<trklen_reco2<<" "<<trkedep2<<endl;
        double logratioo = nd280UpPID2.CalcLogLikeRatio("Pion","Muon",trkedep2/trklen_reco2);
        double logratioo2 = nd280UpPID2.CalcLogLikeRatio("Pion","Prot",trkedep2/trklen_reco2);
        double logratioo3 = nd280UpPID2.CalcLogLikeRatio("Pion","Elec",trkedep2/trklen_reco2);
        //hLikeRatio_MuProt_TrueMu->Fill(logratio2);
        cout<<"dE/dx AND PID Muon/Proton and Muon/Pion "<<trkedep2/trklen_reco2<<" "<< logratioo<<" "<<logratioo2<<endl;
        cout<<"---------------------------------------------------------------------------"<<endl;
        cout<<endl;
        if(logratioo>0 && logratioo2>0 ) {track1Name = "pion"; }
        if(logratioo2<0 && logratioo>0 ) {track1Name = "proton"; }
        if(logratioo<0 ) {track1Name = "muon"; }
	//}
	*/
      
      
      std::cout<<"summarize information for event: "<<event<<std::endl;
      std::cout<<"if there are multiple tracks: "<<isseparated<<std::endl;
      std::cout<<"if first track successfully reconstructed: "<<isreco<<std::endl;
      std::cout<<"PID for first track: "<<track1Name<<std::endl;
      std::cout<<"First track length, energy deposit and angle to z direction: "<<trklen_reco<<" "<<trkedep<<" "<<costh_reco<<std::endl;
      //  std::cout<<"if second track successfully reconstructed: "<<isreco<<std::endl;
      //  std::cout<<"PID for second track "<<track2Name<<std::endl;
      //  std::cout<<"Second track length, energy deposit and angle to z direction: "<<trklen_reco2<<" "<<trkedep2<<" "<<costh_reco2<<std::endl;
      std::cout<<std::endl;
      
      //if(passR1>rreas/1.8) passR2 ++;
      //passR1 = 0;
      for(Int_t endPLoop=0;endPLoop<200;endPLoop++){
	endPoints[endPLoop]=0; comparePoints[endPLoop]=0;
      }
      rreas = 0;
      
    } 
    //list[ii]=1;
    eventE = event;
  }
  
  std::cout<<"total events "<<rreas2<<" pass 1: "<<passR1<<" pass 2: "<<passR2<<" pass 3: "<<passR3<<std::endl;
  std::cout<<"succesfully separated "<<separateS<<" while not "<<separateF<<std::endl;
  std::cout<<"Muon identified "<<muonID<<" out of "<<event<<std::endl;
  std::cout<<"See proton number: "<<seeProton<<std::endl;
  std::cout<<"3D fit cases is : "<<n3Dcase<<std::endl;
  //TFile *fileout = new TFile(Form("outputFile_update_222_particleGun1000MeVMuon_30cone_2PE_OV2_sample%d_distance%d.root",atoi(argv[1]),atoi(argv[2]) ),"RECREATE");
  TFile *fileout = new TFile(Form("outputFile_%s_distance%d.root",argv[1],atoi(argv[2]) ),"RECREATE");
  //TFile *fileout = new TFile("justTest.root","RECREATE");
  fileout->cd();
  hLikeRatio_MuProt_TrueMu->Write("pid-muon-prot");
  hLikeRatio_MuProt_TrueProt->Write("pid-muon-pion");
  hLikeRatio_PionProt_TrueProt->Write("pid-muon-elec");
  hMuon_Len->Write("len");
  hMuon_Edep->Write("edep");
  hMuon_AllIso_TrCosTh->Write("cos");
  hMuon_CosTh_TrueVsReco->Write("cos2D");
  hMuon_Len_TrueVsReco->Write("len2D");
  hMuon_TrMomVsRecoMom->Write("mom2D");
  recoPass_ang->Write("recoPass_ang");
  recoPass_mom->Write("recoPass_mom");
  recoFail_ang->Write("recoFail_ang");
  recoFail_mom->Write("recoFail_mom");
  recoPass_momP->Write("recoPass_momP");
  recoFail_momP->Write("recoFail_momP");
  hMuon_CosTh_RecMinTr->Write("reco-true_cos");
  hMuon_CosTh_RecMinTr2->Write("reco-true_cos2");
  hMuon_CosTh_RecMinTr3->Write("reco-true_cos3");
  hMuon_CosTh_RecMinTr_orig->Write("reco-true_cos_orig");
  hMuon_Mom_RecMinTr->Write("reco-true_mom");
  h_contain->Write("h_contain");
  hMuon_TrMomVsTrCosTh->Write("hMuon_TrMomVsTrCosTh");
  hPion_TrMomVsTrCosTh->Write("hPion_TrMomVsTrCosTh");
  hProt_TrMomVsTrCosTh->Write("hProt_TrMomVsTrCosTh");
  hMuon_TrMom->Write("hMuon_TrMom");
  hPion_TrMom->Write("hPion_TrMom");
  hProt_TrMom->Write("hProt_TrMom");
  hMuon_RecMomVsTrCosRec->Write("hMuon_RecMomVsTrCosRec");
  hProt_RecMomVsTrCosRec->Write("hProt_RecMomVsTrCosRec");
  for(Int_t i=0;i<20;i++){
    hMuon_CosTh_RecMinTrSep[i]->Write(Form("hMuon_CosTh_RecMinTrSep_%d",i));
    hMuon_CosTh_RecMinTrSepOrig[i]->Write(Form("hMuon_CosTh_RecMinTrSepOrig_%d",i));
  }
  hMuon_btnAngCos1->Write("hMuon_btnAngCos_trad");
  hMuon_btnAngCos2->Write("hMuon_btnAngCos_3D");
  hMuon_btnAngAbs1->Write("hMuon_btnAngAbs_trad");
  hMuon_btnAngAbs2->Write("hMuon_btnAngAbs_3D");
  hMuon_dedxVSMom->Write("hMuon_dedxVSMom");
  hPion_dedxVSMom->Write("hPion_dedxVSMom");
  hProt_dedxVSMom->Write("hProt_dedxVSMom");
  hMuon_qSepInCos->Write("hMuon_qSepInCos");
  hMuon_qSepInCosF->Write("hMuon_qSepInCosF");
  hChargeID->Write("hChargeID");
  hRadiusID->Write("hRadiusID");
  hCenterYID->Write("hCenterYID");
  hCenterZID->Write("hCenterZID");
  hChi2_NDF ->Write("hChi2_NDF");
} 

