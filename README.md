# O2_HEPIC_HadrEx
Unicamp+USP taskforce  for the ALICE O2 framework

usefull links:
- O2 documentation: https://aliceo2group.github.io/analysis-framework/docs/
- O2 Tutorial: https://indico.cern.ch/event/1200252/timetable/
- O2 Tutorial (new): https://indico.cern.ch/event/1326201/timetable/

"Recipe" for working with your task:
1) Create your task (.cxx)
2) add your task to the CMakeList.txt
3) Compile your task:
   - go to the path: alice/sw/BUILD/O2Physics-latest/O2Physics
   - execute: ninja install PATH_TO_FOLDER/all
   - where PATH_TO_FOLDER is the path to the directory where is your task
   - Ex.: ninja install Tutorials/all
4) Execute your task with any input AO2D.root just to generate a dpl-config.json
   - execute: o2-componentname-taskname
   - where taskname and componentname are the choosen executable and COMPONENT_NAME indicated in the CMakeList.txt where is your taks
   - Ex.: o2-analysistutorial-mytask --aod-file AO2D.root
5) Rename and edit your dpl-config.json
6) Create an exec file (.sh) with all the workflow and options (helper tasks)
   - make it an executable with: chmod +x <exec_name>.sh
7) Run and have fun!
