
#include <sys/stat.h>
#include <unistd.h>
#include "helperAnalysisPresenter.C"
#include "helperControlPlots.C"
#include <stdio.h>
#include <vector>

void makeControlPlotsWFlavor(TString ofname = "assemblerW_el.root", std::string flavor="electron", int step=1, std::string product="BASICCALOJETS1PT20MATCHED") {

	///////////////////////
	// Binning/selection //
	///////////////////////
	
	// Specify axes and bins of multidimensional histogram
	// For inclusive table
	//std::string varexp = "MET[0]{0,2000,40,\"MET\"}:sumIPpTNormGOODSIGNALJETSCD{0,200,100}:refitVertexDistanceToBeamGOODSIGNALJETSCD{0,100,1000}:refitVertexChi2NDoFGOODSIGNALJETSCD{0,10,100}";
	
  std::string varexp = "MET[0]{0,1200,24,\"MET\"}:HLTHT[0]{0,1500,30,\"HT\"}:NBASICCALOJETSMATCHED[0]{0,8}:NBASICCALOJETS1MATCHED[0]{0,8}:NBASICCALOJETS1PT20MATCHED[0]{0,8}:NALLCALOJETS[0]{0,10}:MT[0]{0,200,20,\"MT\"}:WPT[0]{0,200,20,\"WPT\"}:(NGOODMUONS[0]+NGOODELECTRONS[0]){0,5,5,\"NGOODLEPTONS\"}:NINCLUSIVETAGGEDCALOJETSE[0]{0,5}:NINCLUSIVETAGGEDCALOJETSF[0]{0,5}:M_INCLUSIVETAGGEDCALOJETSE[0]{0,100}:MASSDISPLACED_INCLUSIVETAGGEDCALOJETSE[0]{0,100}:ONZ{0,1}:PTOSSF[0]{0,200,20,\"PTOSSF\"}:MLL[0]{0,150,15,\"MLL\"}";
  //std::string varexp = "MET[0]{0,1200,24,\"MET\"}:HLTHT[0]{0,1500,30,\"HT\"}:NBASICCALOJETSMATCHED[0]{0,8}:NBASICCALOJETS1MATCHED[0]{0,8}:NBASICCALOJETS1PT20MATCHED[0]{0,8}:NALLCALOJETS[0]{0,10}:MT[0]{0,200,20,\"MT\"}:WPT[0]{0,200,20,\"WPT\"}:(NGOODMUONS[0]+NGOODELECTRONS[0]){0,5,5,\"NGOODLEPTONS\"}:NINCLUSIVETAGGEDCALOJETSMATCHED[0]{0,10}:NINCLUSIVETAGGEDCALOJETS[0]{0,10}:SSPH[0]{0,1,20,\"SSPH\"}:HSPH[0]{0,1,20,\"HSPH\"}:LSPH[0]{0,1,20,\"LSPH\"}:stupakR[0]{0,0.4,50,\"STUPAKR\"}:stupakR2[0]{0,0.4,50,\"STUPAKR2\"}:Min$(abs(LEPTON_DPHI)){0,3.142,32,\"MINLEPTONDPHI\"}:Max$(abs(LEPTON_DPHI)){0,3.142,32,\"MAXLEPTONDPHI\"}:LRM[0]{0,3,60,\"LRM\"}:NINCLUSIVETAGGEDCALOJETSE[0]{0,5}:NINCLUSIVETAGGEDCALOJETSF[0]{0,5}:M_INCLUSIVETAGGEDCALOJETSE[0]{0,100}:MASSDISPLACED_INCLUSIVETAGGEDCALOJETSE[0]{0,100}:ONZ{0,1}:PTOSSF[0]{0,200,20,\"PTOSSF\"}:MLL[0]{0,150,15,\"MLL\"}";

	varexp += getVariableExpression(product,step);
	
	// Global cuts, if desired
	// Get rid of photon conversions
	TString selection = "hasGoodVertex && NBASICCALOJETS1PT20[0] > 0 && NGOODLEPTONS[0] == 1";
	// Cut down charge flips
	// commented out because NPOSGOODMUONS etc. is not available in tcH ntuple	


	PhysicsContribution* signal1m = new PhysicsContribution("signal","./addedHistos/allHistos_WminusH_HToSSTobbbb_WToLNu_MH-125_MS-55_ctauS-10_TuneCUETP8M1_13TeV-powheg-pythia8_0.root",0.5313*0.326*0.2,"WH m_s = 55, ctau = 1 cm",false,"treeR",kGreen+2,0.001);
	PhysicsContribution* signal1p = new PhysicsContribution("signal","./addedHistos/allHistos_WplusH_HToSSTobbbb_WToLNu_MH-125_MS-55_ctauS-10_TuneCUETP8M1_13TeV-powheg-pythia8_0.root",0.8377*0.326*0.2,"WH m_s = 55, ctau = 1 cm",false,"treeR",kGreen+2,0.001);
	PhysicsContribution* signal2m = new PhysicsContribution("signal","./addedHistos/allHistos_WminusH_HToSSTobbbb_WToLNu_MH-125_MS-15_ctauS-1000_TuneCUETP8M1_13TeV-powheg-pythia8_0.root",0.5313*0.326*0.2,"WH m_s = 15, ctau = 100 cm",false,"treeR",kRed+3,0.001);
	PhysicsContribution* signal2p = new PhysicsContribution("signal","./addedHistos/allHistos_WplusH_HToSSTobbbb_WToLNu_MH-125_MS-15_ctauS-1000_TuneCUETP8M1_13TeV-powheg-pythia8_0.root",0.8377*0.326*0.2,"WH m_s = 15, ctau = 100 cm",false,"treeR",kRed+3,0.001);
	
	////////////////////////
	// Initialize and run //
	////////////////////////
        Assembler* assembler = NULL;
        TFile ofile(ofname);
        if(ofile.IsOpen()){
          assembler = (Assembler*)ofile.Get("assembler");
        }
        if(!assembler){
	  assembler = new Assembler(ofname, "RECREATE");
	  init(assembler);
	  if(flavor == "electron"){
	    selection += "&& NGOODELECTRONS[0] == 1 && ELECTRON_PT[0] > 45";
	    setupDataElectron(assembler);
	  }else if(flavor == "muon"){
	    selection += "&& NGOODMUONS[0] == 1 && MUON_PT[0] > 45";
	    setupDataMuon(assembler);
	  }else{
	    selection += "&& ((NGOODMUONS[0] > 0 && MUON_PT[0] > 45) || (NGOODELECTRONS[0] > 0 && ELECTRON_PT[0] > 45))";
	    setupData(assembler);
	  }

	  setupBackgroundMC(assembler);
	  //setupBackgroundDD(assembler);
	  assembler->addContribution(signal1m); //********** // It is important to add the signal before setting up the rake rates
	  assembler->addContribution(signal1p); //********** // It is important to add the signal before setting up the rake rates
	  assembler->addContribution(signal2m); //********** // It is important to add the signal before setting up the rake rates
	  assembler->addContribution(signal2p); //********** // It is important to add the signal before setting up the rake rates
	  assembler->addBundle(new Bundle("signal", "signal1",false,kGreen+2));
	  assembler->getBundle("signal1")->addComponent(signal1m);
	  assembler->getBundle("signal1")->addComponent(signal1p);
	  assembler->addBundle(new Bundle("signal", "signal2",false,kRed+3));
	  assembler->getBundle("signal2")->addComponent(signal2m);
	  assembler->getBundle("signal2")->addComponent(signal2p);
	  assembler->addBundle(new Bundle("signal", "SignalBundle"));
	  assembler->getBundle("SignalBundle")->addComponent(assembler->getBundle("signal1"));
	  assembler->getBundle("SignalBundle")->addComponent(assembler->getBundle("signal2"));

	  //setupFakeRates(assembler);
	  assembler->setDebug(true);
	  assembler->process(varexp, selection);
	  //assembler->save();
	}
	//TString fileStart=TString::Format("set%i_MET400_"+product+"_",step);
	std::string fileStart=std::string(TString::Format("W_%s_set%i_%s_",flavor.c_str(),step,product.c_str()).Data());

	assembler->setDefaultBundle(assembler->getBundle("lvl0")); 

	//assembler->setRange("ONZ",1);
	//assembler->setRange("NGOODLEPTONS",2,2);

	makePlots(assembler,fileStart,product,step);
	makePlotsW(assembler,fileStart,product,step);
	ofile.Close();
	
	delete assembler;
}
