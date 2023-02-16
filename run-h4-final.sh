#This is the skimming.
#For the simple reading, it should suffice to do:
#o2-analysistutorial-h4-4-skimming --aod-file AO2D.root
#...with the resulting file!
export OPT="-b --configuration json://dpl-config-skimming.json --resources-monitoring 2 --aod-memory-rate-limit 1000000000 --shm-segment-size 7500000000"
o2-analysis-timestamp ${OPT} | \
o2-analysis-event-selection ${OPT} | \
o2-analysis-multiplicity-table ${OPT} | \
o2-analysis-track-propagation ${OPT} | \
o2-analysis-trackselection ${OPT} | \
o2-analysis-hf-track-index-skim-creator ${OPT} | \
o2-analysis-hf-candidate-creator-2prong ${OPT} | \
o2-analysis-collision-converter ${OPT} | \
o2-analysistutorial-h4-final ${OPT} --aod-writer-json OutputDirector.json --fairmq-ipc-prefix .
