export OPT="-b --configuration json://dpl-config-h3-final.json"
o2-analysistutorial-h3-final ${OPT} | \
o2-analysis-timestamp ${OPT} | \
o2-analysis-track-propagation ${OPT} | \
o2-analysis-event-selection ${OPT} | \
o2-analysis-collision-converter ${OPT} | \
#o2-analysis-lf-lambdakzerobuilder ${OPT} | \
o2-analysis-lf-lambdakzerolabelbuilder ${OPT} | \
o2-analysis-pid-tpc ${OPT} | \
o2-analysis-pid-tpc-base ${OPT}

