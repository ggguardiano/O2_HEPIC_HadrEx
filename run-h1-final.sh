export OPT="-b --configuration json://dpl-config-h1-final.json"
o2-analysistutorial-h1-final ${OPT} | \
o2-analysis-timestamp ${OPT} | \
o2-analysis-track-propagation ${OPT} | \
o2-analysis-collision-converter ${OPT}

