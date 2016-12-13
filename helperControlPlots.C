TString getVariableExpression(TString product, int step)
{
  TString varexp = "";
  if(product.Contains("DIJET")){
    if(step > 0){
      varexp += ":PT_"+product+"{0,500,50}";
      varexp += ":ETA_"+product+"{-2.4,2.4,24}";
      varexp += ":PHI_"+product+"{-3.142,3.142,32}";
      varexp += ":LXY_"+product+"{0,40,40}";
      varexp += ":LXYSIG_"+product+"{0,100,100}";
      varexp += ":POSIP2DFRAC_"+product+"{0,1,20}";
      varexp += ":PROMPTENERGYFRAC_"+product+"{0,1,20}";
      varexp += ":TRKAVGPT_"+product+"{0,40,80}";
      varexp += ":VTXMASS_"+product+"{0,20,100}";
      varexp += ":VTXPT_"+product+"{0,100,100}";
      varexp += ":ALPHAMAX_"+product+"{0,1,20}";
      varexp += ":BESTCLUSTERLXY_"+product+"{0,40,40}";
      varexp += ":MEDIANIPLOG10SIG_"+product+"{-1,4,50}";
      varexp += ":MEDIANTRACKANGLE_"+product+"{0,3.142,32}";
      varexp += ":MEDIANTRACKANGLELOG10_"+product+"{-3,0.5,35}";
      varexp += ":OPENINGANGLE_"+product+"{0,3.142,32}";
      varexp += ":TOTALTRACKANGLE_"+product+"{-3.142,3.142,32}";
      varexp += ":TRACKENERGY1_"+product+"{0,400,80}";
      varexp += ":TRACKENERGY2_"+product+"{0,400,80}";
      varexp += ":TRACKMASS1_"+product+"{0,20,20}";
      varexp += ":TRACKMASS2_"+product+"{0,20,20}";
      varexp += ":NAVGMISSHITSAFTERVERT_"+product+"{0,3,15}";
    }
    if(step > 1){
    }
    if(step > 2){
    }
  }else{
    if(step > 0){
      //varexp += ":SUMIP_"+product+"{0,100,20}";
      varexp += ":SUMIPSIG_"+product+"{0,1000,100}";
      //varexp += ":NTRACKSIPSIGGT10_"+product+"{0,20,20}";
      //varexp += ":NTRACKSIPLT0P05_"+product+"{0,40,20}";
      //varexp += ":NTRACKSIPSIGLT5_"+product+"{0,40,20}";
      varexp += ":NMATCHEDTRACKS_"+product+"{0,20,20}";
      //varexp += ":SUMIPLOGSIG_"+product+"{-20,100,24}";
      varexp += ":PT_"+product+"{0,500,50}";
      //varexp += ":IVFSCORE_"+product+"{0,10000,20}";
      varexp += ":ETA_"+product+"{-2.4,2.4,24}";
      varexp += ":METDELTAR_"+product+"{0,5,50}";
      varexp += ":METANGLE_DPHI_"+product+"{0,3.142,32}";
      varexp += ":METANGLE_DANGLE_"+product+"{0,3.142,32}";
      //varexp += ":TRACKMASS_"+product+"{0,50,50}";
      varexp += ":TRACKENERGY_"+product+"{0,200,100}";
      varexp += ":TOTALTRACKANGLE_"+product+"{0,3.142,32}";
      varexp += ":TOTALTRACKPT_"+product+"{0,200,100}";
      //varexp += ":LINEARRADIALMOMENT_"+product+"{0,1,50}";
      //varexp += ":MEDIANIPLOGSIG_"+product+"{-6,6,60}";//*
      varexp += ":MEDIANIPLOG10SIG_"+product+"{-1,4,50}";//*
      varexp += ":MEDIANLOG10TRACKANGLE_"+product+"{-4,1.0,50}";//*
      varexp += ":Min$(METANGLE_DPHI_"+product+"){0,3.142,32,\"MINMETDPHI_"+product+"\"}";
      varexp += ":Max$(METANGLE_DPHI_"+product+"){0,3.142,32,\"MAXMETDPHI_"+product+"\"}";
      varexp += ":Min$(LEPANGLE_DPHI_"+product+"){0,3.142,32,\"MINLEPDPHI_"+product+"\"}";
      varexp += ":Max$(LEPANGLE_DPHI_"+product+"){0,3.142,32,\"MAXLEPDPHI_"+product+"\"}";
      varexp += ":ALPHAMAX_"+product+"{0,1,20}";//**
      //varexp += ":ALPHAMAXPRIME_"+product+"{0,1,20}";//**
      varexp += ":BETA_"+product+"{0,1,20}";//**
      //varexp += ":ALPHAMAX2_"+product+"{0,1,20}";//**
      //varexp += ":ALPHAMAXPRIME2_"+product+"{0,1,20}";//**
      //varexp += ":BETA2_"+product+"{0,1,20}";//**
      //varexp += ":ASSOCAPLANARITY_"+product+"{0,1,20}";
      //varexp += ":ASSOCSPHERICITY_"+product+"{0,1,20}";
      //varexp += ":ASSOCTHRUSTMAJOR_"+product+"{0,1,20}";
      //varexp += ":ASSOCTHRUSTMINOR_"+product+"{0,1,20}";
      varexp += ":MISSINGINNER_"+product+"{0,10,10}";
      varexp += ":MISSINGOUTER_"+product+"{0,10,10}";
      varexp += ":AVGMISSINGINNER_"+product+"{0,5,50}";
      varexp += ":AVGMISSINGOUTER_"+product+"{0,5,50}";
    }
    if(step > 1){
    }
    if(step > 2){
      varexp += ":MISSHITSAFTERVERTPERTRACK_"+product+"{0,5,50}";//**
      varexp += ":AVFVERTEXTRANSVERSESIG_"+product+"{0,1000,10}";//**
      varexp += ":AVFVERTEXTRACKMASS_"+product+"{0,100,20}";//**
      varexp += ":AVFVERTEXTRACKENERGY_"+product+"{0,500,20}";//**
      //varexp += ":AVFVERTEXTOTALCHISQUARED_"+product+"{0,800,20}";//**
      varexp += ":AVFVERTEXDISTANCETOBEAM_"+product+"{0,100,100}";//**
      //varexp += ":AVFVERTEXDEGREESOFFREEDOM_"+product+"{0,100,20}";//**
      //varexp += ":AVFVERTEXCHI2NDOF_"+product+"{0,100,20}";//**
      //varexp += ":AVFDISTTOPV_"+product+"{0,100,20}";//**
      varexp += ":AVFBEAMSPOTRECOILPT_"+product+"{0,200,50}";//**
      varexp += ":AVFBEAMSPOTDELTAPHI_"+product+"{-3.142,3.142,50}";//**
      varexp += ":NCLEANMATCHEDTRACKS_"+product+"{0,60,20}";//**
      varexp += ":ASSOCIATEDTRACKPT_"+product+"{0,500,100}";//**
      varexp += ":(TOTALTRACKPT_"+product+"/ASSOCIATEDTRACKPT_"+product+"){0,1,50,\"ASSOCIATEDRATIO_"+product+"\"}";
      varexp += ":AVFASSOCAPLANARITY_"+product+"{0,1,20}";
      varexp += ":AVFASSOCSPHERICITY_"+product+"{0,1,20}";
      varexp += ":AVFASSOCTHRUSTMAJOR_"+product+"{0,1,20}";
      varexp += ":AVFASSOCTHRUSTMINOR_"+product+"{0,1,20}";
    } 
  }
  return varexp;
  
}

void makePlots(Assembler* assembler, std::string fileStart, std::string product,int step)
{
	makeNicePlot(assembler->project("MET",true,assembler->getDefaultBundle())->plot(true),"MET [GeV]")->SaveAs(TString(fileStart+"MET.pdf").Data());
	makeNicePlot(assembler->project("HT",true,assembler->getDefaultBundle())->plot(true),"HT [GeV]")->SaveAs(TString(fileStart+"HT.pdf").Data());
	//makeNicePlot(assembler->project("LRM",true,assembler->getDefaultBundle())->plot(true),"Basic calojet Linear Radial Moment from summed jet axis")->SaveAs(TString(fileStart+"LRM.pdf").Data());
	//makeNicePlot(assembler->project("SSPH",true,assembler->getDefaultBundle())->plot(true),"2D Sphericity")->SaveAs(TString(fileStart+"SSPH.pdf").Data());
	//makeNicePlot(assembler->project("LSPH",true,assembler->getDefaultBundle())->plot(true),"2D Sphericity (lepton + jets)")->SaveAs(TString(fileStart+"LSPH.pdf").Data());
	//makeNicePlot(assembler->project("HSPH",true,assembler->getDefaultBundle())->plot(true),"2D Sphericity (jets)")->SaveAs(TString(fileStart+"HSPH.pdf").Data());
	//makeNicePlot(assembler->project("MINLEPTONDPHI",true,assembler->getDefaultBundle())->plot(true),"Min #Delta#phi MET - leptons")->SaveAs(TString(fileStart+"MINLEPDPHI.pdf").Data());
	//makeNicePlot(assembler->project("MAXLEPTONDPHI",true,assembler->getDefaultBundle())->plot(true),"Max #Delta#phi MET - leptons")->SaveAs(TString(fileStart+"MAXLEPDPHI.pdf").Data());
	//makeNicePlot(assembler->project("STUPAKR",true,assembler->getDefaultBundle())->plot(true),"Stupak R")->SaveAs(TString(fileStart+"STUPAKR.pdf").Data());
	//makeNicePlot(assembler->project("STUPAKR2",true,assembler->getDefaultBundle())->plot(true),"Stupak R2")->SaveAs(TString(fileStart+"STUPAKR2.pdf").Data());
	makeNicePlot(assembler->project("NBASICCALOJETSMATCHED[0]",true,assembler->getDefaultBundle())->plot(true),"N_{basic calojets}")->SaveAs(TString(fileStart+"NBASICCALOJETS.pdf").Data());
	makeNicePlot(assembler->project("NBASICCALOJETS1PT20MATCHED[0]",true,assembler->getDefaultBundle())->plot(true),"N_{basic calojets} (at least 1 track, p_{T} > 20 GeV)")->SaveAs(TString(fileStart+"NBASICCALOJETS1PT20.pdf").Data());
	makeNicePlot(assembler->project("NALLCALOJETS[0]",true,assembler->getDefaultBundle())->plot(true),"N_{calojets}")->SaveAs(TString(fileStart+"NALLCALOJETS.pdf").Data());
	//makeNicePlot(assembler->project("NDIJETSGOODVTXMATCHED[0]",true,assembler->getDefaultBundle())->plot(true),"N_{dijets w/ vtx}")->SaveAs((fileStart+"NDIJETSGOODVTX.pdf").Data());
	makeNicePlot(assembler->project("NGOODLEPTONS",true,assembler->getDefaultBundle())->plot(true),"N_{leptons}")->SaveAs(TString(fileStart+"NLEPTONS.pdf").Data());
	//makeNicePlot(assembler->project("NINCLUSIVETAGGEDCALOJETSMATCHED[0]",true,assembler->getDefaultBundle())->plot(true),"N_{tagged} (matched)")->SaveAs(TString(fileStart+"NTAGGEDMATCHED.pdf").Data());
	//makeNicePlot(assembler->project("NINCLUSIVETAGGEDCALOJETS[0]",true,assembler->getDefaultBundle())->plot(true),"N_{tagged} (matched)")->SaveAs(TString(fileStart+"NTAGGED.pdf").Data());
	//makeNicePlot(assembler->project("NINCLUSIVETAGGEDCALOJETSE[0]",true,assembler->getDefaultBundle())->plot(true),"N_{tagged} (matched)")->SaveAs(TString(fileStart+"NTAGGEDE.pdf").Data());
	makeNicePlot(assembler->project("NINCLUSIVETAGGEDCALOJETSF[0]",true,assembler->getDefaultBundle())->plot(true),"N_{tagged} (matched)")->SaveAs(TString(fileStart+"NTAGGEDF.pdf").Data());
	//makeNicePlot(assembler->project("M_INCLUSIVETAGGEDCALOJETSE[0]",true,assembler->getDefaultBundle())->plot(true),"Jet Invariant mass (calo)")->SaveAs(TString(fileStart+"MINCLUSIVETAGGEDCALOJETSE.pdf").Data());
	//makeNicePlot(assembler->project("MASSDISPLACED_INCLUSIVETAGGEDCALOJETSE[0]",true,assembler->getDefaultBundle())->plot(true),"Jet Invariant mass (track)")->SaveAs(TString(fileStart+"MDISPLACEDINCLUSIVETAGGEDCALOJETSE.pdf").Data());
	if(TString(product).Contains("DIJET")){
	  if(step > 0){
	    makeNicePlot(assembler->project("PT_"+product,true,assembler->getDefaultBundle())->plot(true), "p_{T}")->SaveAs(TString(fileStart+"PT.pdf").Data());
	    makeNicePlot(assembler->project("ETA_"+product,true,assembler->getDefaultBundle())->plot(true), "#eta")->SaveAs(TString(fileStart+"ETA.pdf").Data());
	    makeNicePlot(assembler->project("PHI_"+product,true,assembler->getDefaultBundle())->plot(true), "#phi")->SaveAs(TString(fileStart+"PHI.pdf").Data());
	    makeNicePlot(assembler->project("LXY_"+product,true,assembler->getDefaultBundle())->plot(true), "transverse distance")->SaveAs(TString(fileStart+"LXY.pdf").Data());
	    makeNicePlot(assembler->project("LXYSIG_"+product,true,assembler->getDefaultBundle())->plot(true), "transverse distance significance")->SaveAs(TString(fileStart+"LXYSIG.pdf").Data());
	    makeNicePlot(assembler->project("POSIP2DFRAC_"+product,true,assembler->getDefaultBundle())->plot(true), "positive IP2D fraction")->SaveAs(TString(fileStart+"POSIP2DFRAC.pdf").Data());
	    makeNicePlot(assembler->project("PROMPTENERGYFRAC_"+product,true,assembler->getDefaultBundle())->plot(true), "prompt energy fraction")->SaveAs(TString(fileStart+"PROMPTENERGYFRAC.pdf").Data());
	    makeNicePlot(assembler->project("TRKAVGPT_"+product,true,assembler->getDefaultBundle())->plot(true), "average track pt")->SaveAs(TString(fileStart+"TRKAVGPT.pdf").Data());
	    makeNicePlot(assembler->project("VTXMASS_"+product,true,assembler->getDefaultBundle())->plot(true), "vertex mass")->SaveAs(TString(fileStart+"VTXMASS.pdf").Data());
	    makeNicePlot(assembler->project("VTXPT_"+product,true,assembler->getDefaultBundle())->plot(true), "vertex p_{T}")->SaveAs(TString(fileStart+"VTXPT.pdf").Data());
	    makeNicePlot(assembler->project("ALPHAMAX_"+product,true,assembler->getDefaultBundle())->plot(true), "#alpha_{max}")->SaveAs(TString(fileStart+"ALPHAMAX.pdf").Data());
	    makeNicePlot(assembler->project("BESTCLUSTERLXY_"+product,true,assembler->getDefaultBundle())->plot(true), "best cluster lxy")->SaveAs(TString(fileStart+"BESTCLUSTERLXY.pdf").Data());
	    makeNicePlot(assembler->project("MEDIANIPLOG10SIG_"+product,true,assembler->getDefaultBundle())->plot(true), "median track log10 ip significance")->SaveAs(TString(fileStart+"MEDIANIPLOG10SIG.pdf").Data());
	    makeNicePlot(assembler->project("MEDIANTRACKANGLE_"+product,true,assembler->getDefaultBundle())->plot(true), "median track angle")->SaveAs(TString(fileStart+"MEDIANTRACKANGLE.pdf").Data());
	    makeNicePlot(assembler->project("MEDIANTRACKANGLELOG10_"+product,true,assembler->getDefaultBundle())->plot(true), "median log10 track angle")->SaveAs(TString(fileStart+"MEDIANTRACKANGLELOG10.pdf").Data());
	    makeNicePlot(assembler->project("OPENINGANGLE_"+product,true,assembler->getDefaultBundle())->plot(true), "dijet opening angle")->SaveAs(TString(fileStart+"OPENINGANGLE.pdf").Data());
	    makeNicePlot(assembler->project("TOTALTRACKANGLE_"+product,true,assembler->getDefaultBundle())->plot(true), "total track angle")->SaveAs(TString(fileStart+"TOTALTRACKANGLE.pdf").Data());
	    makeNicePlot(assembler->project("TRACKENERGY1_"+product,true,assembler->getDefaultBundle())->plot(true), "jet1 track energy")->SaveAs(TString(fileStart+"TRACKENERGY1.pdf").Data());
	    makeNicePlot(assembler->project("TRACKMASS1_"+product,true,assembler->getDefaultBundle())->plot(true), "jet1 track mass")->SaveAs(TString(fileStart+"TRACKMASS1.pdf").Data());
	    makeNicePlot(assembler->project("TRACKENERGY2_"+product,true,assembler->getDefaultBundle())->plot(true), "jet2 track energy")->SaveAs(TString(fileStart+"TRACKENERGY2.pdf").Data());
	    makeNicePlot(assembler->project("TRACKMASS2_"+product,true,assembler->getDefaultBundle())->plot(true), "jet2 track mass")->SaveAs(TString(fileStart+"TRACKMASS2.pdf").Data());
	    makeNicePlot(assembler->project("NAVGMISSHITSAFTERVERT_"+product,true,assembler->getDefaultBundle())->plot(true), "average missing hits after vertex")->SaveAs(TString(fileStart+"NAVGMISSHITSAFTERVERT.pdf").Data());


	  }
	}else{
	  if(step > 0){
	    //makeNicePlot(assembler->project("SUMIP_"+product,true,assembler->getDefaultBundle())->plot(true),"SUM IP")->SaveAs(TString(fileStart+"SUMIP.pdf").Data());
	    makeNicePlot(assembler->project("SUMIPSIG_"+product,true,assembler->getDefaultBundle())->plot(true),"SUM IP Significance")->SaveAs(TString(fileStart+"SUMIPSIG.pdf").Data());
	    //makeNicePlot(assembler->project("SUMIPLOGSIG_"+product,true,assembler->getDefaultBundle())->plot(true),"SUM IP Log Significance")->SaveAs(TString(fileStart+"SUMIPLOGSIG.pdf").Data());
	    //makeNicePlot(assembler->project("NTRACKSIPSIGGT10_"+product,true,assembler->getDefaultBundle())->plot(true),"Number of tracks with IPSIG > 10")->SaveAs(TString(fileStart+"NTRACKSIPSIGGT10.pdf").Data());
	    //makeNicePlot(assembler->project("NTRACKSIPLT0P05_"+product,true,assembler->getDefaultBundle())->plot(true),"Number of tracks with IP < 0.05")->SaveAs(TString(fileStart+"NTRACKSIPLT0P05.pdf").Data());
	    //makeNicePlot(assembler->project("NTRACKSIPSIGLT5_"+product,true,assembler->getDefaultBundle())->plot(true),"Number of tracks with IPSIG < 5")->SaveAs(TString(fileStart+"NTRACKSIPSIGLT5.pdf").Data());
	    makeNicePlot(assembler->project("NMATCHEDTRACKS_"+product,true,assembler->getDefaultBundle())->plot(true),"Number of matched tracks")->SaveAs(TString(fileStart+"NMATCHEDTRACKS.pdf").Data());
	    makeNicePlot(assembler->project("PT_"+product,true,assembler->getDefaultBundle())->plot(true),"p_{T} [GeV]")->SaveAs(TString(fileStart+"PT.pdf").Data());
	    makeNicePlot(assembler->project("ETA_"+product,true,assembler->getDefaultBundle())->plot(true),"#eta")->SaveAs(TString(fileStart+"ETA.pdf").Data());
	    //makeNicePlot(assembler->project("IVFSCORE_"+product,true,assembler->getDefaultBundle())->plot(true),"IVF Score")->SaveAs((fileStart+"IVFSCORE.pdf").Data());
	    makeNicePlot(assembler->project("METDELTAR_"+product,true,assembler->getDefaultBundle())->plot(true),"DeltaR to MET")->SaveAs(TString(fileStart+"METDELTAR.pdf").Data());
	    makeNicePlot(assembler->project("METANGLE_DPHI_"+product,true,assembler->getDefaultBundle())->plot(true),"#Delta #phi to MET")->SaveAs(TString(fileStart+"METDELTA_PHI.pdf").Data());
	    makeNicePlot(assembler->project("METANGLE_DANGLE_"+product,true,assembler->getDefaultBundle())->plot(true),"Delta angle to MET")->SaveAs(TString(fileStart+"METDELTA_ANGLE.pdf").Data());
	    makeNicePlot(assembler->project("MINMETDPHI_"+product,true,assembler->getDefaultBundle())->plot(true),"Minimum #Delta#phi to MET")->SaveAs(TString(fileStart+"MINMETDPHI.pdf").Data());
	    makeNicePlot(assembler->project("MAXMETDPHI_"+product,true,assembler->getDefaultBundle())->plot(true),"Maximum #Delta#phi to MET")->SaveAs(TString(fileStart+"MAXMETDPHI.pdf").Data());
	    makeNicePlot(assembler->project("MINLEPDPHI_"+product,true,assembler->getDefaultBundle())->plot(true),"Minimum #Delta#phi to Lepton")->SaveAs(TString(fileStart+"MINJETLEPDPHI.pdf").Data());
	    makeNicePlot(assembler->project("MAXLEPDPHI_"+product,true,assembler->getDefaultBundle())->plot(true),"Maximum #Delta#phi to Lepton")->SaveAs(TString(fileStart+"MAXJETLEPDPHI.pdf").Data());
	    //makeNicePlot(assembler->project("MEDIANIPLOGSIG_"+product,true,assembler->getDefaultBundle())->plot(true),"Median IP Log Significance")->SaveAs(TString(fileStart+"MEDIANIPLOGSIG.pdf").Data());
	    makeNicePlot(assembler->project("MEDIANIPLOG10SIG_"+product,true,assembler->getDefaultBundle())->plot(true),"Median IP Log10 Significance")->SaveAs(TString(fileStart+"MEDIANIPLOG10SIG.pdf").Data());
	    makeNicePlot(assembler->project("MEDIANLOG10TRACKANGLE_"+product,true,assembler->getDefaultBundle())->plot(true),"Median Log10 Track Angle")->SaveAs(TString(fileStart+"MEDIANLOGTRACKANGLE.pdf").Data());
	    makeNicePlot(assembler->project("TOTALTRACKPT_"+product,true,assembler->getDefaultBundle())->plot(true),"sum Track p_{T} [GeV]")->SaveAs(TString(fileStart+"TOTALTRACKPT.pdf").Data());
	    makeNicePlot(assembler->project("TOTALTRACKANGLE_"+product,true,assembler->getDefaultBundle())->plot(true),"sum Track angle")->SaveAs(TString(fileStart+"TOTALTRACKANGLE.pdf").Data());
	    //makeNicePlot(assembler->project("TRACKMASS_"+product,true,assembler->getDefaultBundle())->plot(true),"Track Mass [GeV]")->SaveAs((fileStart+"TRACKMASS.pdf").Data());
	    makeNicePlot(assembler->project("TRACKENERGY_"+product,true,assembler->getDefaultBundle())->plot(true),"Track Energy [GeV]")->SaveAs(TString(fileStart+"TRACKENERGY.pdf").Data());
	    //makeNicePlot(assembler->project("LINEARRADIALMOMENT_"+product,true,assembler->getDefaultBundle())->plot(true),"Linear Radial Moment")->SaveAs(TString(fileStart+"LINEARRADIALMOMENT.pdf").Data());
	    makeNicePlot(assembler->project("ALPHAMAX_"+product,true,assembler->getDefaultBundle())->plot(true),"alphaMax")->SaveAs(TString(fileStart+"ALPHAMAX.pdf").Data());
	    //makeNicePlot(assembler->project("ALPHAMAXPRIME_"+product,true,assembler->getDefaultBundle())->plot(true),"alphaMaxPrime")->SaveAs(TString(fileStart+"ALPHAMAXPRIME.pdf").Data());
	    makeNicePlot(assembler->project("BETA_"+product,true,assembler->getDefaultBundle())->plot(true),"beta")->SaveAs(TString(fileStart+"BETA.pdf").Data());
	    //makeNicePlot(assembler->project("ALPHAMAX2_"+product,true,assembler->getDefaultBundle())->plot(true),"alphaMax2")->SaveAs(TString(fileStart+"ALPHAMAX2.pdf").Data());
	    //makeNicePlot(assembler->project("ALPHAMAXPRIME2_"+product,true,assembler->getDefaultBundle())->plot(true),"alphaMaxPrime2")->SaveAs(TString(fileStart+"ALPHAMAXPRIME2.pdf").Data());
	    //makeNicePlot(assembler->project("BETA2_"+product,true,assembler->getDefaultBundle())->plot(true),"beta2")->SaveAs(TString(fileStart+"BETA2.pdf").Data());
	    //makeNicePlot(assembler->project("ASSOCAPLANARITY_"+product,true,assembler->getDefaultBundle())->plot(true),"track aplanarity")->SaveAs(TString(fileStart+"ASSOCAPLANARITY.pdf").Data());
	    //makeNicePlot(assembler->project("ASSOCSPHERICITY_"+product,true,assembler->getDefaultBundle())->plot(true),"track sphericity")->SaveAs(TString(fileStart+"ASSOCSPHERICITY.pdf").Data());
	    //makeNicePlot(assembler->project("ASSOCTHRUSTMAJOR_"+product,true,assembler->getDefaultBundle())->plot(true),"track thrust major")->SaveAs(TString(fileStart+"ASSOCTHRUSTMAJOR.pdf").Data());
	    //makeNicePlot(assembler->project("ASSOCTHRUSTMINOR_"+product,true,assembler->getDefaultBundle())->plot(true),"track thrust minor")->SaveAs(TString(fileStart+"ASSOCTHRUSTMINOR.pdf").Data());
	    makeNicePlot(assembler->project("MISSINGINNER_"+product,true,assembler->getDefaultBundle())->plot(true),"Missing Inner Hits")->SaveAs(TString(fileStart+"MISSINGINNER.pdf").Data());
	    makeNicePlot(assembler->project("MISSINGOUTER_"+product,true,assembler->getDefaultBundle())->plot(true),"Missing Outer Hits")->SaveAs(TString(fileStart+"MISSINGOUTER.pdf").Data());
	    makeNicePlot(assembler->project("AVGMISSINGINNER_"+product,true,assembler->getDefaultBundle())->plot(true),"Avg. Missing Inner Hits per track")->SaveAs(TString(fileStart+"AVGMISSINGINNER.pdf").Data());
	    makeNicePlot(assembler->project("AVGMISSINGOUTER_"+product,true,assembler->getDefaultBundle())->plot(true),"Avg. Missing Outer Hits per track")->SaveAs(TString(fileStart+"AVGMISSINGOUTER.pdf").Data());

	  }
	  if(step > 1){
	  }
	  if(step > 2){
	    makeNicePlot(assembler->project("AVFVERTEXTRANSVERSESIG_"+product,true,assembler->getDefaultBundle())->plot(true),"Vertex transverse significance")->SaveAs(TString(fileStart+"AVFVERTEXTRANSVERSESIG.pdf").Data());
	    makeNicePlot(assembler->project("AVFVERTEXTRACKMASS_"+product,true,assembler->getDefaultBundle())->plot(true),"Vertex track mass [GeV]")->SaveAs(TString(fileStart+"AVFVERTEXTRACKMASS.pdf").Data());
	    makeNicePlot(assembler->project("AVFVERTEXTRACKENERGY_"+product,true,assembler->getDefaultBundle())->plot(true),"Vertex track energy [GeV]")->SaveAs(TString(fileStart+"AVFVERTEXTRACKENERGY.pdf").Data());
	    //makeNicePlot(assembler->project("AVFVERTEXTOTALCHISQUARED_"+product,true,assembler->getDefaultBundle())->plot(true),"Vertex total chi squared")->SaveAs((fileStart+"AVFVERTEXTOTALCHISQUARED.pdf").Data());
	    makeNicePlot(assembler->project("AVFVERTEXDISTANCETOBEAM_"+product,true,assembler->getDefaultBundle())->plot(true),"Vertex distance to beamspot [cm]")->SaveAs(TString(fileStart+"AVFVERTEXDISTANCETOBEAM.pdf").Data());
	    //makeNicePlot(assembler->project("AVFVERTEXDEGREESOFFREEDOM_"+product,true,assembler->getDefaultBundle())->plot(true),"Vertex d.o.f.")->SaveAs((fileStart+"AVFVERTEXDEGREESOFFREEDOM.pdf").Data());
	    //makeNicePlot(assembler->project("AVFVERTEXCHI2NDOF_"+product,true,assembler->getDefaultBundle())->plot(true),"Vertex chi2/ndof")->SaveAs((fileStart+"AVFVERTEXCHI2NDOF.pdf").Data());
	    //makeNicePlot(assembler->project("AVFDISTTOPV_"+product,true,assembler->getDefaultBundle())->plot(true),"Vertex distance to primary vertex [cm]")->SaveAs((fileStart+"AVFDISTTOPV.pdf").Data());
	    makeNicePlot(assembler->project("AVFBEAMSPOTRECOILPT_"+product,true,assembler->getDefaultBundle())->plot(true),"Vertex 2d recoil [GeV]")->SaveAs(TString(fileStart+"AVFBEAMSPOTRECOILPT.pdf").Data());
	    makeNicePlot(assembler->project("AVFBEAMSPOTDELTAPHI_"+product,true,assembler->getDefaultBundle())->plot(true),"Vertex 2d delta phi")->SaveAs(TString(fileStart+"AVFBEAMSPOTDELTAPHI.pdf").Data());
	    makeNicePlot(assembler->project("NCLEANMATCHEDTRACKS_"+product,true,assembler->getDefaultBundle())->plot(true),"Number of cleaned matched tracks")->SaveAs(TString(fileStart+"NCLEANEDMATCHEDTRACKS.pdf").Data());
	    makeNicePlot(assembler->project("MISSHITSAFTERVERTPERTRACK_"+product,true,assembler->getDefaultBundle())->plot(true),"Number of missing hits per track after vertex")->SaveAs(TString(fileStart+"MISSHITSAFTERVERTPERTRACK.pdf").Data());
	    makeNicePlot(assembler->project("ASSOCIATEDRATIO_"+product,true,assembler->getDefaultBundle())->plot(true),"ratio of vertex tracks in jet")->SaveAs(TString(fileStart+"ASSOCIATEDRATIO.pdf").Data());
	    makeNicePlot(assembler->project("AVFASSOCAPLANARITY_"+product,true,assembler->getDefaultBundle())->plot(true),"vertex aplanarity")->SaveAs(TString(fileStart+"AVFASSOCAPLANARITY.pdf").Data());
	    makeNicePlot(assembler->project("AVFASSOCSPHERICITY_"+product,true,assembler->getDefaultBundle())->plot(true),"vertex sphericity")->SaveAs(TString(fileStart+"AVFASSOCSPHERICITY.pdf").Data());
	    makeNicePlot(assembler->project("AVFASSOCTHRUSTMAJOR_"+product,true,assembler->getDefaultBundle())->plot(true),"vertex thrust major")->SaveAs(TString(fileStart+"AVFASSOCTHRUSTMAJOR.pdf").Data());
	    makeNicePlot(assembler->project("AVFASSOCTHRUSTMINOR_"+product,true,assembler->getDefaultBundle())->plot(true),"vertex thrust minor")->SaveAs(TString(fileStart+"AVFASSOCTHRUSTMINOR.pdf").Data());
	    
	  }

	}

}

void makePlotsZ(Assembler* assembler, TString fileStart, TString product, int step)
{
	makeNicePlot(assembler->project("PTOSSF",true,assembler->getDefaultBundle())->plot(true),"OSSF p_{T} [GeV]")->SaveAs((fileStart+"PTOSSF.pdf").Data());
	makeNicePlot(assembler->project("MLL",true,assembler->getDefaultBundle())->plot(true),"M_{LL} [GeV]")->SaveAs((fileStart+"MLL.pdf").Data());

}

void makePlotsW(Assembler* assembler, TString fileStart, TString product, int step)
{
	makeNicePlot(assembler->project("WPT",true,assembler->getDefaultBundle())->plot(true),"W p_{T} [GeV]")->SaveAs((fileStart+"WPT.pdf").Data());
	makeNicePlot(assembler->project("MT",true,assembler->getDefaultBundle())->plot(true),"M_{T} [GeV]")->SaveAs((fileStart+"MT.pdf").Data());

}
