#include <iostream>
#include <TH1.h>

#include "RutgersIAF/AnalysisPresenter/interface/Assembler.h"
#include "RutgersIAF/AnalysisPresenter/interface/Bundle.h"
#include "RutgersIAF/AnalysisPresenter/interface/Channel.h"
#include "RutgersIAF/AnalysisPresenter/interface/PhysicsContribution.h"

// Load library, see https://root.cern.ch/phpBB2/viewtopic.php?f=3&t=19471
namespace {
  int loadMyLibraryTriggerFunc() {
    gSystem->Load("libRutgersIAFAnalysisPresenter.so");
    return 0;
  }
  int loadMyLibraryTrigger = loadMyLibraryTriggerFunc();
}

void init(Assembler* assembler) {
	TH1::AddDirectory(false);
	TH1::SetDefaultSumw2(true);
	//assembler->addBundle(new Bundle("background","qcdMCBundle"));
	/*	
	assembler->addBundle(new Bundle("background", "Fakes"));
	assembler->addBundle(new Bundle("background", "TrackFakes"));
	assembler->addBundle(new Bundle("background", "PhotonFakes"));
	assembler->addBundle(new Bundle("background", "TauFakes"));
	assembler->addBundle(new Bundle("background", "Higgs"));
	assembler->addBundle(new Bundle("background", "Rare MC"));
	assembler->addBundle(new Bundle("background","QCD MC"));
	*/
}

std::string getDataFileName() {
	return "20150729_data";
	//return "20150623_data.1event";
}

void prepare(Assembler* assembler) {
	Bundle* fakeBundle = assembler->getBundle("Fakes");
	for(const auto &bundleName : {"TrackFakes", "PhotonFakes", "TauFakes"}) {
		Bundle* bundle = assembler->getBundle(bundleName);
		if(bundle->getComponents().size() > 0) {
			fakeBundle->addComponent(bundle);
		}
	}
	
	Bundle* presentationBundle = new Bundle("background", "presentationBundle");
	for(const auto &bundleName : {"Fakes", "Higgs", "Rare MC"}) {
		Bundle* bundle = assembler->getBundle(bundleName);
		if(bundle->getComponents().size() > 0) {
			presentationBundle->addComponent(bundle);
		}
	}
	assembler->addBundle(presentationBundle);
	
	Bundle* fakePresentationBundle = new Bundle("background", "fakePresentationBundle");
	for(const auto &bundleName : {"TrackFakes", "PhotonFakes", "TauFakes", "Higgs", "Rare MC"}) {
		Bundle* bundle = assembler->getBundle(bundleName);
		if(bundle->getComponents().size() > 0) {
			fakePresentationBundle->addComponent(bundle);
		}
	}
	assembler->addBundle(fakePresentationBundle);
	
//	assembler->setDefaultBundle(presentationBundle);
//	assembler->getDefaultBundle()->print();
}

void setupData(Assembler* assembler, float scale=1.0) {
	dilep = true;
	//std::string prefix = "/cms/matt/mwalker/Analysis/20160913_VHdata/addedHistos/";
	std::string prefix = "./addedHistos/";
	//std::string prefix = "root://cmseos.fnal.gov//store/group/lpchbb/mwalker/AnalysisTrees/";
	std::vector<PhysicsContribution*> dataContributions;

	for(int i = 0; i < 220; i++){
	  float lumi = 0.0001;
	  if(i == 18)continue;
	  if(i == 0)lumi = 7554;
	  //if(i > 4)continue;
	  PhysicsContribution* data = new PhysicsContribution("data",prefix+TString::Format("allHistos_SingleElectron_%i.root",i), lumi*scale, TString::Format("7.5/fb @ 13 TeV SingleElectron%i",i));
	  data->addWeight("(hasSingleElTriggers && !hasSingleMuTriggers)");
	  dataContributions.push_back(data);
	}
	
	for(int i = 0; i < 220; i++){
	  float lumi = 0.0001;
	  //if(i == 0)lumi = 7554;
	  PhysicsContribution* data = new PhysicsContribution("data",prefix+TString::Format("allHistos_SingleMuon_%i.root",i), lumi*scale, TString::Format("7.5/fb @ 13 TeV SingleMuon%i",i));
	  data->addWeight("hasSingleMuTriggers");
	  dataContributions.push_back(data);
	}
	
	for (auto data : dataContributions){
	  //data->addWeight("(hasSingleElTriggers || hasSingleMuTriggers)");
	  assembler->addContribution(data);
	}
}
void setupDataMuon(Assembler* assembler, float scale=1.0) {
	dilep = true;
	//std::string prefix = "/cms/matt/mwalker/Analysis/20160913_VHdata/addedHistos/";
	std::string prefix = "./addedHistos/";
	//std::string prefix = "root://cmseos.fnal.gov//store/group/lpchbb/mwalker/AnalysisTrees/";
	std::vector<PhysicsContribution*> dataContributions;

	
	for(int i = 0; i < 220; i++){
	  float lumi = 0.0001;
	  if(i == 0)lumi = 7554;
	  PhysicsContribution* data = new PhysicsContribution("data",prefix+TString::Format("allHistos_SingleMuon_%i.root",i), lumi*scale, TString::Format("7.5/fb @ 13 TeV SingleMuon%i",i));
	  data->addWeight("hasSingleMuTriggers");
	  dataContributions.push_back(data);
	}
	
	for (auto data : dataContributions){
	  //data->addWeight("(hasSingleElTriggers || hasSingleMuTriggers)");
	  assembler->addContribution(data);
	}
}

void setupDataElectron(Assembler* assembler, float scale=1.0) {
	dilep = true;
	//std::string prefix = "/cms/matt/mwalker/Analysis/20160913_VHdata/addedHistos/";
	std::string prefix = "./addedHistos/";
	//std::string prefix = "root://cmseos.fnal.gov//store/group/lpchbb/mwalker/AnalysisTrees/";
	std::vector<PhysicsContribution*> dataContributions;

	for(int i = 0; i < 220; i++){
	  float lumi = 0.0001;
	  if(i == 18)continue;
	  if(i == 0)lumi = 7554;
	  //if(i > 4)continue;
	  PhysicsContribution* data = new PhysicsContribution("data",prefix+TString::Format("allHistos_SingleElectron_%i.root",i), lumi*scale, TString::Format("7.5/fb @ 13 TeV SingleElectron%i",i));
	  data->addWeight("hasSingleElTriggers");
	  dataContributions.push_back(data);
	}
		
	for (auto data : dataContributions){
	  //data->addWeight("(hasSingleElTriggers || hasSingleMuTriggers)");
	  assembler->addContribution(data);
	}
}




void setupBackgroundMC(Assembler* assembler, bool dilep = false, bool ttbar = true, bool onlyTTF = false) {
  
	dilep = true;
	std::string prefix = "./addedHistos/";
	//std::string prefix = "root://cmseos.fnal.gov//store/group/lpchbb/mwalker/AnalysisTrees/";
	std::string infix =  "";
	std::string suffix = ".root";
	
	
	std::vector<PhysicsContribution*> mc;
	
	//Bundle* qcdMCBundle = new Bundle("background","qcdMCBundle",false,kTeal-7);
	Bundle* ttBarBundle = new Bundle("background","ttBarBundle");
	Bundle* WJetsMCBundle = new Bundle("background","WJetsMCBundle",false,kBlue+2);
	Bundle* singleTopBundle = new Bundle("background","single top",false,39);
	Bundle* dyBundle = new Bundle("background","DYtoLL+jets",false,49);
	//assembler->addBundle(qcdMCBundle);
	//assembler->addBundle(ttBarBundle);
	//assembler->addBundle(WJetsMCBundle);
	assembler->addBundle(singleTopBundle);
	assembler->addBundle(dyBundle);

	
	PhysicsContribution* dyjets = new PhysicsContribution("backgroundMC", "./allHistos_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8" + infix + suffix,6025,"DYJets", false, "treeR",8);
	dyBundle->addComponent(dyjets);
	mc.push_back(dyjets);

	PhysicsContribution* dyjets5 = new PhysicsContribution("backgroundMC", "./allHistos_DYJetsToLL_M-5to50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8" + infix + suffix,7160,"DYJets", false, "treeR",8);
	dyBundle->addComponent(dyjets5);
	mc.push_back(dyjets5);

	PhysicsContribution* wjets = new PhysicsContribution("backgroundMC", "./allHistos_WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8" + infix + suffix,20489*3,"WJets",false,"treeR",9);
	//WJetsMCBundle->addComponent(wjets);
	mc.push_back(wjets);

	PhysicsContribution* ttJets = new PhysicsContribution("backgroundMC", "./allHistos_TT_TuneCUETP8M1_13TeV-powheg-pythia8" + infix + suffix, 831.76 , "TTbar", false, "treeR", 38); // 0.821 dilepton normalization
	//ttBarBundle->addComponent(ttJets);
	mc.push_back(ttJets);
	
	PhysicsContribution* WmHtoBB = new PhysicsContribution("backgroundMC", prefix + "allHistos_WminusH_HToBB_WToLNu_M125_13TeV_powheg_pythia8_0" + infix + suffix, 0.5313 * 0.577 *0.324, "WHtoBB", false, "treeR", 33); // 0.821 dilepton normalization
	mc.push_back(WmHtoBB);
	PhysicsContribution* WpHtoBB = new PhysicsContribution("backgroundMC", prefix + "allHistos_WplusH_HToBB_WToLNu_M125_13TeV_powheg_pythia8_0" + infix + suffix, 0.8377 * 0.577 *0.324  , "WHtoBB", false, "treeR", 33); // 0.821 dilepton normalization
	mc.push_back(WpHtoBB);
	

        PhysicsContribution* st_t_antitop = new PhysicsContribution("backgroundMC", prefix + "allHistos_ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1_0" + infix + suffix, 26.23, "single top t-channel antitop", false, "treeR", kBlue+2);
        singleTopBundle->addComponent(st_t_antitop);
        mc.push_back(st_t_antitop);

        PhysicsContribution* st_t_top = new PhysicsContribution("backgroundMC", prefix + "allHistos_ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1_0" + infix + suffix, 44.09, "single top t-channel top", false, "treeR", kOrange+2);
        singleTopBundle->addComponent(st_t_top);
        mc.push_back(st_t_top);

        PhysicsContribution* st_tW_antitop = new PhysicsContribution("backgroundMC", prefix + "allHistos_ST_tW_antitop_5f_NoFullyHadronicDecays_13TeV-powheg_TuneCUETP8M1_0" + infix + suffix, 38.09, "single top tW antitop", false, "treeR", kTeal-7);
        singleTopBundle->addComponent(st_tW_antitop);
        mc.push_back(st_tW_antitop);

        PhysicsContribution* st_tW_top = new PhysicsContribution("backgroundMC", prefix + "allHistos_ST_tW_top_5f_NoFullyHadronicDecays_13TeV-powheg_TuneCUETP8M1_0" + infix + suffix, 38.09, "single top tW top", false, "treeR", kAzure-6);
        singleTopBundle->addComponent(st_tW_top);
        mc.push_back(st_tW_top);

        PhysicsContribution* st_s_top = new PhysicsContribution("backgroundMC", prefix + "allHistos_ST_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1_0" + infix + suffix, 10.11, "single top s", false, "treeR", kAzure-6);
        singleTopBundle->addComponent(st_s_top);
        mc.push_back(st_s_top);

	//PhysicsContribution* wjets = new PhysicsContribution("backgroundMC", prefix + "allHistos_WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8" + infix + suffix, 61526.7 , "WtoLNu + Jets", false, "treeR", 42);
	//mc.push_back(wjets);

	PhysicsContribution* ZHtoBB = new PhysicsContribution("backgroundMC", prefix + "allHistos_ZH_HToBB_ZToLL_M125_13TeV_powheg_pythia8_0" + infix + suffix, 0.8696 * 0.577 * 0.102, "ZHtoBB", false, "treeR", 35); // 0.821 dilepton normalization
	mc.push_back(ZHtoBB);
	

	PhysicsContribution* ggZHtoBB = new PhysicsContribution("backgroundMC", prefix + "allHistos_ggZH_HToBB_ZToLL_M125_13TeV_powheg_pythia8_0" + infix + suffix, 0.1227*0.577*0.102, "ggZHtoBB", false, "treeR", 34);
	mc.push_back(ggZHtoBB);

	/*
	PhysicsContribution* zjets = new PhysicsContribution("backgroundMC", prefix + "allHistos_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8" + infix + suffix, 6025.2, "DY M50 + Jets", false, "treeR", 49);
	mc.push_back(zjets);
	dyBundle->addComponent(zjets);

	PhysicsContribution* zjets2 = new PhysicsContribution("backgroundMC", prefix + "allHistos_DYJetsToLL_M-5to50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8" + infix + suffix, 7160, "DY M5to50 + Jets", false, "treeR", 49);
	mc.push_back(zjets2);
	dyBundle->addComponent(zjets2);
	*/

	//PhysicsContribution* zhtotautau = new PhysicsContribution("backgroundMC", prefix + "allHistos_ZHToTauTau_M125_13TeV_powheg_pythia8" + infix + suffix, 0.8696 * 0.0622, "ZHtoTauTau",false, "treeR",34);
	//mc.push_back(zhtotautau);

	//PhysicsContribution* wz2l2q = new PhysicsContribution("backgroundMC", prefix+"allHistos_WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8" + infix + suffix, 5.52, "WZto2L2q" , false, "treeR", 38);
	//mc.push_back(wz2l2q);

	//PhysicsContribution* wz3lnu = new PhysicsContribution("backgroundMC", prefix+"allHistos_WZTo3LNu_TuneCUETP8M1_13TeV-powheg-pythia8" + infix + suffix, 4.43, "WZto3LNu" , false, "treeR", 36);
	//mc.push_back(wz3lnu);

	PhysicsContribution* wz = new PhysicsContribution("backgroundMC", prefix+"allHistos_WZ_TuneCUETP8M1_13TeV-pythia8_0" + infix + suffix, 63, "WZ" , false, "treeR", 36);
	mc.push_back(wz);
	PhysicsContribution* ww = new PhysicsContribution("backgroundMC", prefix+"allHistos_WW_TuneCUETP8M1_13TeV-pythia8_0" + infix + suffix, 118.7, "WW" , false, "treeR", 38);
	mc.push_back(ww);

	PhysicsContribution* zz = new PhysicsContribution("backgroundMC", prefix+"allHistos_ZZ_TuneCUETP8M1_13TeV-pythia8_0" + infix + suffix,10.32, "ZZ", false, "treeR", 30);
	mc.push_back(zz);

	//PhysicsContribution* zz2l2q = new PhysicsContribution("backgroundMC", prefix+"allHistos_ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8" + infix + suffix,3.38, "ZZto4L", false, "treeR", 32);
	//mc.push_back(zz2l2q);

	//PhysicsContribution* ww2l2nu = new PhysicsContribution("backgroundMC", prefix + "allHistos_WWTo2L2Nu_13TeV-powheg" + infix + suffix , 12.46, "WWto2L2Nu", false, "treeR",41);
	//mc.push_back(ww2l2nu);

	for(auto &contribution : mc) {
		contribution->addWeight("FLATWEIGHT[0]");
		//contribution->addFlatUncertainty("bg_syst",0.30);
		//contribution->addWeight("TRIGGERACCEPT");
		assembler->addContribution(contribution);
	}

	Bundle* lvl0Bundle = new Bundle("background","lvl0");
	//lvl0Bundle->addComponent(qcdMCBundle);
	//lvl0Bundle->addComponent(WJetsMCBundle);
	//lvl0Bundle->addComponent(ttBarBundle);
	lvl0Bundle->addComponent(singleTopBundle);
	lvl0Bundle->addComponent(dyBundle);
	assembler->addBundle(lvl0Bundle);
  
}

void setupBackgroundMC_W(Assembler* assembler, bool dilep = false, bool ttbar = true, bool onlyTTF = false) {
  
	dilep = true;
	std::string prefix = "./addedHistos/";
	//std::string prefix = "root://cmseos.fnal.gov//store/group/lpchbb/mwalker/AnalysisTrees/";
	std::string infix =  "";
	std::string suffix = ".root";
	
	
	std::vector<PhysicsContribution*> mc;
	
	//Bundle* qcdMCBundle = new Bundle("background","qcdMCBundle",false,kTeal-7);
	//Bundle* ttBarBundle = new Bundle("background","ttBarBundle");
	//Bundle* WJetsMCBundle = new Bundle("background","WJetsMCBundle",false,kBlue+2);
	Bundle* singleTopBundle = new Bundle("background","single top",false,39);
	//assembler->addBundle(qcdMCBundle);
	//assembler->addBundle(ttBarBundle);
	//assembler->addBundle(WJetsMCBundle);
	assembler->addBundle(singleTopBundle);


	PhysicsContribution* ttJets = new PhysicsContribution("backgroundMC", prefix + "allHistos_TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8" + infix + suffix, 831.76 , "TTbar", false, "treeR", 38); // 0.821 dilepton normalization
	//ttBarBundle->addComponent(ttJets);
	mc.push_back(ttJets);

	PhysicsContribution* WHtoBB = new PhysicsContribution("backgroundMC", prefix + "allHistos_WH_HToBB_WToLNu_M125_13TeV_amcatnloFXFX_madspin_pythia8" + infix + suffix, 1.369 * 0.324 * 0.577 , "WHtoBB", false, "treeR", 33); // 0.821 dilepton normalization
	//ttBarBundle->addComponent(ttJets);
	mc.push_back(WHtoBB);
	

        PhysicsContribution* st_t_antitop = new PhysicsContribution("backgroundMC", prefix + "allHistos_ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1" + infix + suffix, 26.23, "single top t-channel antitop", false, "treeR", kBlue+2);
        singleTopBundle->addComponent(st_t_antitop);
        mc.push_back(st_t_antitop);

        PhysicsContribution* st_t_top = new PhysicsContribution("backgroundMC", prefix + "allHistos_ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1" + infix + suffix, 44.09, "single top t-channel top", false, "treeR", kOrange+2);
        singleTopBundle->addComponent(st_t_top);
        mc.push_back(st_t_top);

        PhysicsContribution* st_tW_antitop = new PhysicsContribution("backgroundMC", prefix + "allHistos_ST_tW_antitop_5f_DS_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1" + infix + suffix, 35.6, "single top tW antitop", false, "treeR", kTeal-7);
        singleTopBundle->addComponent(st_tW_antitop);
        mc.push_back(st_tW_antitop);

        PhysicsContribution* st_tW_top = new PhysicsContribution("backgroundMC", prefix + "allHistos_ST_tW_top_5f_DS_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1" + infix + suffix, 35.6, "single top tW top", false, "treeR", kAzure-6);
        singleTopBundle->addComponent(st_tW_top);
        mc.push_back(st_tW_top);

	PhysicsContribution* wjets = new PhysicsContribution("backgroundMC", prefix + "allHistos_WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8" + infix + suffix, 61526.7 , "WtoLNu + Jets", false, "treeR", 42);
	mc.push_back(wjets);


	for(auto &contribution : mc) {
		contribution->addWeight("FLATWEIGHT[0]");
		//contribution->addFlatUncertainty("bg_syst",0.30);
		//contribution->addWeight("TRIGGERACCEPT");
		assembler->addContribution(contribution);
	}

	Bundle* lvl0Bundle = new Bundle("background","lvl0");
	//lvl0Bundle->addComponent(qcdMCBundle);
	//lvl0Bundle->addComponent(WJetsMCBundle);
	lvl0Bundle->addComponent(singleTopBundle);
	assembler->addBundle(lvl0Bundle);
  
}

void setupBackgroundMC_Z(Assembler* assembler, bool dilep = false, bool ttbar = true, bool onlyTTF = false) {
  
	dilep = true;
	std::string prefix = "./addedHistos/";
	//std::string prefix = "root://cmseos.fnal.gov//store/group/lpchbb/mwalker/AnalysisTrees/";
	std::string infix =  "";
	std::string suffix = ".root";
	
	
	std::vector<PhysicsContribution*> mc;
	
	//Bundle* qcdMCBundle = new Bundle("background","qcdMCBundle",false,kTeal-7);
	//Bundle* ttBarBundle = new Bundle("background","ttBarBundle");
	//Bundle* WJetsMCBundle = new Bundle("background","WJetsMCBundle",false,kBlue+2);
	//Bundle* singleTopBundle = new Bundle("background","single top",false,39);
	Bundle* dyBundle = new Bundle("background","DYtoLL+jets",false,49);
	//assembler->addBundle(qcdMCBundle);
	//assembler->addBundle(ttBarBundle);
	//assembler->addBundle(WJetsMCBundle);
	//assembler->addBundle(singleTopBundle);
	assembler->addBundle(dyBundle);


	PhysicsContribution* ttJets = new PhysicsContribution("backgroundMC", prefix + "allHistos_TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8" + infix + suffix, 831.76 , "TTbar", false, "treeR", 38); // 0.821 dilepton normalization
	//ttBarBundle->addComponent(ttJets);
	mc.push_back(ttJets);

	PhysicsContribution* ZHtoBB = new PhysicsContribution("backgroundMC", prefix + "allHistos_ZH_HToBB_ZToLL_M125_13TeV_powheg_pythia8" + infix + suffix, 0.8696 * 0.577 * 0.102, "ZHtoBB", false, "treeR", 33); // 0.821 dilepton normalization
	//ttBarBundle->addComponent(ttJets);
	mc.push_back(ZHtoBB);
	

	PhysicsContribution* zjets = new PhysicsContribution("backgroundMC", prefix + "allHistos_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8" + infix + suffix, 6025.2, "DY M50 + Jets", false, "treeR", 49);
	mc.push_back(zjets);
	dyBundle->addComponent(zjets);

	PhysicsContribution* zjets2 = new PhysicsContribution("backgroundMC", prefix + "allHistos_DYJetsToLL_M-5to50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8" + infix + suffix, 7160, "DY M5to50 + Jets", false, "treeR", 49);
	mc.push_back(zjets2);
	dyBundle->addComponent(zjets2);


	PhysicsContribution* zhtotautau = new PhysicsContribution("backgroundMC", prefix + "allHistos_ZHToTauTau_M125_13TeV_powheg_pythia8" + infix + suffix, 0.8696 * 0.0622, "ZHtoTauTau",false, "treeR",34);
	mc.push_back(zhtotautau);

	PhysicsContribution* wz2l2q = new PhysicsContribution("backgroundMC", prefix+"allHistos_WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8" + infix + suffix, 5.52, "WZto2L2q" , false, "treeR", 38);
	mc.push_back(wz2l2q);

	PhysicsContribution* wz3lnu = new PhysicsContribution("backgroundMC", prefix+"allHistos_WZTo3LNu_TuneCUETP8M1_13TeV-powheg-pythia8" + infix + suffix, 4.43, "WZto3LNu" , false, "treeR", 36);
	mc.push_back(wz3lnu);

	PhysicsContribution* zz4l = new PhysicsContribution("backgroundMC", prefix+"allHistos_ZZTo4L_13TeV_powheg_pythia8" + infix + suffix,1.26, "ZZto4L", false, "treeR", 30);
	mc.push_back(zz4l);

	PhysicsContribution* zz2l2q = new PhysicsContribution("backgroundMC", prefix+"allHistos_ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8" + infix + suffix,3.38, "ZZto4L", false, "treeR", 32);
	mc.push_back(zz2l2q);

	PhysicsContribution* ww2l2nu = new PhysicsContribution("backgroundMC", prefix + "allHistos_WWTo2L2Nu_13TeV-powheg" + infix + suffix , 12.46, "WWto2L2Nu", false, "treeR",41);
	mc.push_back(ww2l2nu);

	for(auto &contribution : mc) {
		contribution->addWeight("FLATWEIGHT[0]");
		//contribution->addFlatUncertainty("bg_syst",0.30);
		//contribution->addWeight("TRIGGERACCEPT");
		assembler->addContribution(contribution);
	}

	Bundle* lvl0Bundle = new Bundle("background","lvl0");
	//lvl0Bundle->addComponent(qcdMCBundle);
	//lvl0Bundle->addComponent(WJetsMCBundle);
	//lvl0Bundle->addComponent(singleTopBundle);
	lvl0Bundle->addComponent(dyBundle);
	assembler->addBundle(lvl0Bundle);
  
}


void setupBackgroundDD(Assembler* assembler, TString option = "", bool syst = false) {
	cout << "NOTICE: Data-driven background samples currently unavailable" << endl;
	return;
	
	std::string prefix = "/cms/thomassen/2014/Analysis/data/histograms/";
	std::string body = getDataFileName();
	std::string suffix = ".root";
	
	////// Tracks
	PhysicsContribution* fakeTracks = new PhysicsContribution("backgroundDD", prefix + body + suffix, assembler->getLumi(), "fakeTracks", false, "treeRfakeTracks", (option == "justTracks") ? kWhite : -1);
/*	fakeTracks->addWeight(
		"(Sum$(fakeRoleGOODELECTRONS) + Sum$(fakeRoleGOODMUONS) == 0)"
		" + (Sum$(fakeRoleGOODELECTRONS) > 0)"
			" * 4 * ("
				"(Min$(PTGOODELECTRONS) > 10 && Min$(PTGOODELECTRONS) < 15) * 0.09"
				" + (Min$(PTGOODELECTRONS) > 15 && Min$(PTGOODELECTRONS) < 20) * 0.26"
				" + (Min$(PTGOODELECTRONS) > 20 && Min$(PTGOODELECTRONS) < 25) * 0.58"
				" + (Min$(PTGOODELECTRONS) > 25)"
		")"
		" + (Sum$(fakeRoleGOODMUONS) > 0)"
			" * ("
				"(Min$(PTGOODMUONS) > 10 && Min$(PTGOODMUONS) < 15) * 1.13"
				" + (Min$(PTGOODMUONS) > 15)"
		")"
	);
*/	
	if(syst) {
		fakeTracks->addFlatUncertainty("trackFit", 0.17);
	}
	if(option != "noTracks" && option != "justTaus" && option != "justPhotons" && option != "fakeTaus2L") {
		assembler->getBundle("TrackFakes")->addComponent(fakeTracks);
		assembler->addContribution(fakeTracks);
	}
	
	////// Taus
	PhysicsContribution* fakeTaus = new PhysicsContribution("backgroundDD", prefix + body + suffix, assembler->getLumi(), "fakeTaus", false, "treeRfakeTaus");
	//fakeTaus->addWeight("Sum$(fakeRoleGOODTAUS > 0 && abs(TOTALISOGOODTAUS - 10.5) > 4.5) == 0"); // taken care of in the fake rate definition
	if(syst) {
		fakeTaus->addFlatUncertainty("tauFit", 0.05); // for HT > 200 GeV, it is that high
	}
	if(option != "noTaus" && option != "justTracks" && option != "justPhotons" && option != "fakeTaus2L") {
		assembler->getBundle("TauFakes")->addComponent(fakeTaus);
		assembler->addContribution(fakeTaus);
	}
	
	////// Taus (2L)
	PhysicsContribution* fakeTaus2L = new PhysicsContribution("backgroundDD", prefix + body + suffix, assembler->getLumi(), "fakeTaus2L", false, "treeRfakeTaus");
	//fakeTaus2L->addWeight("Sum$(fakeRoleGOODTAUS > 0 && abs(TOTALISOGOODTAUS - 10.5) > 4.5) == 0"); // taken care of in the fake rate definition
	if(syst) {
		fakeTaus2L->addFlatUncertainty("tauFit", 0.05); // for HT > 200 GeV, it is that high
	}
	if(option == "fakeTaus2L") {
		assembler->addContribution(fakeTaus2L);
	}
	
	////// Photons
	PhysicsContribution* fakePhotons = new PhysicsContribution("backgroundDD", prefix + body + suffix, assembler->getLumi(), "fakePhotons", false, "treeRfakePhotons");
	if(syst) {
		fakePhotons->addFlatUncertainty("photonElFake", 0.15);
		//fakePhotons->addFlatUncertainty("photonFudge", 0.25);
		//fakePhotons->setEnsembleFakeRateParam(fakeTracks, "NPROMPTTRACKS7", "0*(x < [0]) + 1*(x > 2*[0]) + (x/[0] - 1)*(x >= [0] && x <= 2*[0])");
	}
	if(option != "noPhotons" && option != "justTracks" && option != "justTaus" && option != "fakeTaus2L") {
		assembler->getBundle("PhotonFakes")->addComponent(fakePhotons);
		assembler->addContribution(fakePhotons);
	}
}

void setupFakeRates(Assembler* assembler) {
	cout << "NOTICE: Fake rates currently unavailable" << endl;
	return;
	
	// We found that NGOODJETS and HT binning does not work very well; NPROMPTINCLUSIVETRACK7 binning does a good job at least in 0b regions.
	assembler->setFakeRate("nTrackFakeMuons",
		"(NGOODTAUS[0] == 0) * ("
			"0.0154"
			" * (1 + 1.2 * (NBJETSCSVM[0] > 0))"
		")"
		" * (nTrackFakeElectrons[0] + nTrackFakeMuons[0] == 1)" // disable multiple proxies (precaution to avoid problems like with taus)
	);
	assembler->setFakeRate("nTrackFakeElectrons",
		"(NGOODTAUS[0] == 0) * ("
			"((NLEPTONS[0]==3&&NGOODELECTRONS[0]==1)*(0.006771 + 0.005532*NPROMPTNONISOINCLUSIVETRACKS7[0]) + (NLEPTONS[0]==3&&NGOODELECTRONS[0]==3)*(0.009287 + -0.001487*NPROMPTNONISOINCLUSIVETRACKS7[0])"
			"+ (NLEPTONS[0]!=3||!(NGOODELECTRONS[0]%2))*(0.007453 + 0.003052*NPROMPTNONISOINCLUSIVETRACKS7[0]))" // this is not the average of the above, but measured (because of relative fractions)
			" * (1 + 1.2 * (NBJETSCSVM[0] > 0))"
		")"
		" * (nTrackFakeElectrons[0] + nTrackFakeMuons[0] == 1)" // disable multiple proxies (precaution to avoid problems like with taus)
	);
	
	// mZ = 90 \pm 15
	assembler->setFakeRate("nTauFakeTaus",
		"Alt$(fakeRoleGOODTAUS > 0 && TOTALISOGOODTAUS > 6 && TOTALISOGOODTAUS < 15, 0) * (" // w/o track/photon subtraction and with 200 binning
		//"Alt$(Sum$(fakeRoleGOODTAUS > 0 && abs(TOTALISOGOODTAUS - 10.5) > 4.5) == 0, 0) * (" // w/o track/photon subtraction and with 200 binning
			"(NBJETSCSVM[0] == 0) * ("
				"(NLEPTONS[0]==3&&NGOODMUONS[0]==0) * (0.2584 - 0.0003302 * HT[0])"
				" + (NLEPTONS[0]==3&&NGOODMUONS[0]==2) * (0.2504 - 0.0002508 * HT[0])"
				" + (NLEPTONS[0]!=3 || NGOODMUONS[0]==1) * (0.2544 - 0.0002905 * HT[0])"
			") + (NBJETSCSVM[0] > 0) * ("
				"(NLEPTONS[0]==3&&NGOODMUONS[0]==0) * (0.2100 - 0.0003165 * HT[0])"
				" + (NLEPTONS[0]==3&&NGOODMUONS[0]==2) * (0.2354 - 0.0002913 * HT[0])"
				" + (NLEPTONS[0]!=3 || NGOODMUONS[0]==1) * (0.2227 - 0.0003039 * HT[0])"
			")"
			//"(HT[0] <= 200) * 0.2275 + (HT[0] > 200) * 0.15"
		")"
		" * (nTauFakeTaus[0] == 1)" // disable multiple fake taus (overprediction for 2l+2tau channels because of double-counting from 2L and from 3L seeds)
	);
	
	// Photon fake rates for Asymmetric Internal Conversions (AIC)
	// AIC reduces the pt of the emitting lepton, and can push on-Z pairs below the Z peak. This causes migration between on-Z/off-Z etc.
	// Looking at the AIC control region, we find that we should adjust the fake rate outside MLEPTONS = 75..100.
	assembler->setFakeRate("nPhotonFakeMuons",
		"(NGOODTAUS[0] == 0) * ("
			"(NOSSF == 1 && !ONZ && MOSSF < 91) * 0.00295 / ( (1 + 0.5 * (MLIGHTLEPTONS[0] < 75 || MLIGHTLEPTONS[0] > 100) ) * (1 + ONZ) ) * (1 + 1.2 * (NBJETSCSVM[0] > 0))"
		")"
		" * (nPhotonFakeElectrons[0] + nPhotonFakeMuons[0] == 1)" // disable multiple proxies (precaution to avoid problems like with taus)
	);
	assembler->setFakeRate("nPhotonFakeElectrons",
		"(NGOODTAUS[0] == 0) * ("
			"0.0088 / ( (1 + 0.5 * (MLIGHTLEPTONS[0] < 75 || MLIGHTLEPTONS[0] > 100) ) * (1 + ONZ) ) * (1 + 1.2 * (NBJETSCSVM[0] > 0))"
		")"
		" * (nPhotonFakeElectrons[0] + nPhotonFakeMuons[0] == 1)" // disable multiple proxies (precaution to avoid problems like with taus)
	);
}

#include <TCanvas.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TStyle.h>

TCanvas* makeNicePlot(TCanvas* c, const char* axistitle="")
{
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);

  c->cd();
  c->SetTopMargin(0.001);
  c->SetRightMargin(0.001);
  c->SetBottomMargin(0.001);
  c->SetLeftMargin(0.001);

  TPad* pad1 = (TPad*)c->GetPrimitive("pad1");
  pad1->SetTopMargin(0.05);
  pad1->SetBottomMargin(0.01);
  pad1->SetRightMargin(0.01);
  double xmin,xmax,ymin,ymax;
  pad1->GetRangeAxis(xmin,ymin,xmax,ymax);
  if(ymin < 1)ymin = 2e-2;
  if(pad1->GetLogy())ymax *= 10;
  else ymax *= 1.5;
  pad1->RangeAxis(xmin,ymin,xmax,ymax);

  TPad* pad2 = (TPad*)c->GetPrimitive("pad2");
  pad2->SetBottomMargin(0.15);
  pad2->SetTopMargin(0.01);
  pad2->SetRightMargin(0.01);

  pad1->RedrawAxis();
  pad2->RedrawAxis();

  TList* list = c->GetListOfPrimitives();
  //cout<<"make nice plot "<<list->GetEntries()<<endl;
  TH1* h = 0;
  THStack* stack = 0;
  TLegend* legend = NULL;
  for(int i = 0; i < list->GetEntries(); i++) {
    TObject* obj = list->At(i);
    TString cname(obj->ClassName());
    if(cname.Contains("TH1")){
      h = ((TH1*)obj);
      ((TH1*)obj)->SetStats(false);
    } else if(cname == "TLegend") {
      legend = ((TLegend*)obj);
    }
  }

  list = pad1->GetListOfPrimitives();
  pad1->cd();
  //cout<<"make nice plot "<<list->GetEntries()<<endl;
  for(int i = 0; i < list->GetEntries(); i++){
    TObject* obj = list->At(i);
    //cout<<i<<" "<<obj->GetName()<<endl;
    TString cname(obj->ClassName());
    TString oname(obj->GetName());
    if(cname.Contains("TH1")){
      ((TH1*)obj)->SetStats(false);
      //cout<<i<<" "<<((TH1*)obj)->Integral()<<endl;
    }else if(cname == "TLegend"){
      //((TLegend*)obj)->SetFillColor(kWhite);
      legend = ((TLegend*)obj);
      legend->SetFillStyle(0);
    }
    if(oname.Contains("Data") || oname.Contains("dummy")){
      ((TH1*)obj)->SetMarkerColorAlpha(kBlack,0);
      ((TH1*)obj)->SetLineColorAlpha(kBlack,0);
    }
    if(oname.Contains("ctau")){
      ((TH1*)obj)->SetMarkerColor(((TH1*)obj)->GetFillColor());
    }
  }
  if(legend){
    legend->SetX1NDC(0.55);
    legend->SetX2NDC(0.95);
    legend->SetY1NDC(0.65);
    legend->SetY2NDC(0.93);
  }


  //if(legend)legend->Draw();

  TList* list2 = pad2->GetListOfPrimitives();
  pad2->cd();
  for(int i = 0; i < list2->GetEntries(); i++){
    TObject* obj = list2->At(i);
    TString cname(obj->ClassName());
    if(cname.Contains("TH1")){
      float offset = ((TH1*)obj)->GetXaxis()->GetTitleOffset();
      float fontsize = ((TH1*)obj)->GetXaxis()->GetTitleSize();
      ((TH1*)obj)->GetXaxis()->SetTitleOffset(1.1*offset);
      ((TH1*)obj)->GetXaxis()->SetTitleFont(42);
      ((TH1*)obj)->GetXaxis()->SetTitleSize(1.1*fontsize);
      if(TString(axistitle) != "" && TString(((TH1*)obj)->GetXaxis()->GetTitle()) != ""){
        ((TH1*)obj)->GetXaxis()->SetTitle(axistitle);
      }
    }
  }

  c->cd();

  TLatex* latex = new TLatex;
  latex->SetNDC();
  latex->SetTextFont(61);
  latex->SetTextSize(0.04);
  latex->DrawLatex(0.16,0.915,"CMS Preliminary");

  latex->SetTextSize(0.03);
  latex->SetTextFont(42);
  latex->DrawLatex(0.75,0.97,"7.6 fb^{-1} (13 TeV)");

  c->Update();
  pad1->Update();
  pad2->Update();

  return c;

}

TCanvas* VecTH1ToTCanvas(std::vector<TH1*> histos){
  TCanvas* canvas = new TCanvas("c","",800,1200);
  canvas->Divide(2,4);
  int npad = 1;
  for(auto &h : histos){
    TVirtualPad* pad = canvas->cd(npad);
    pad->SetLogy();
    h->Draw();
    npad++;
  }
  return canvas;
}

void writeUncertainties(AssemblerProjection* projection, TString type) {
	cout << endl << "====== now printing uncertainties for contributions of type " << type << endl;
	if(!projection->has(type)) {
		cerr << "Projection does not have contributions of type " << type << endl;
		return;
	}
	
	auto uncertaintyNames = projection->getUncertaintyNames();
	for(int i = 1; i <= 5; ++i) {
		cout << endl;
		cout << "BIN " << i << endl;
		cout << "TOTAL:";
		cout << " " << projection->getBin(type, i);
		cout << " pm " << projection->getBinStat(type, i) << " pm " << projection->getBinSyst(type, i) << endl;
		for(const auto &uncertaintyName : uncertaintyNames) {
			cout << "uncertainty name: " << uncertaintyName << " " << projection->getBinSyst(type, i, uncertaintyName) << endl;
		}
		cout << endl;
		
		for(const auto &bundleName : projection->getBundleNames(type)) {
			cout << "bundleName: " << bundleName;
			cout << " " << projection->getBin(type, i, bundleName);
			cout << " pm " << projection->getBinStat(type, i, bundleName) << endl;
			for(const auto &uncertaintyName : uncertaintyNames) {
				cout << "uncertainty name: " << uncertaintyName << " " << projection->getBinSyst(type, i, uncertaintyName, bundleName) << endl;
			}
		}
	}
}
