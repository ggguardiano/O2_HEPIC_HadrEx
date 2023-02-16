export OPT="-b --configuration json://dpl-config-jets.json"
o2-analysistutorial-jetspectra-task-skim-analyser ${OPT} | \
o2-analysistutorial-jet-task-skim-provider ${OPT} | \
o2-analysis-collision-converter ${OPT} | \
o2-analysis-timestamp ${OPT} | \
o2-analysis-track-propagation ${OPT} | \
o2-analysis-je-jet-finder ${OPT} | \
o2-analysis-trackselection ${OPT} | \
o2-analysis-event-selection ${OPT}

