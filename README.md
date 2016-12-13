# PlottingMacros
These macros make the plots for comparing simulation to data in regions of interest.

##Running these macros:
+ For 2L ONZ: `root -q -b -l makeControlPlotsZ.C`
+ For 1 electron: `root -q -b -l 'makeControlPlotsWFlavor.C("assemblerW_el.root","electron")'`
+ For 1 muon: `root -q -b -l 'makeControlPlotsWFlavor.C("assemblerW_mu.root","muon")'`

##What you have to worry about:
The input files need to be edited in helperAnalysisPresenter.C (the current paths are on hexcms, but for xrootd will work fine).

If you want to add new variables be aware that if you add a jet variable for a specific tag, the Assembler will implicitly require that the events use have at least 1 of those objects, so you won't have any contribution from zero tag events.

You can save the assembler (already done for the Z events, commented out for 1L), which will let you remake plots, as long as you don't want to change variables, binning, samples, selection, etc.

