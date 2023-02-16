// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright
// holders. All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.
///
/// \brief This task contains the individual steps that are to be taken
///        in the first part of the tutorial. These are 6 steps, and at the end,
///        the participant is expected to have a pT resolution histogram
///        as a function of transverse momentum.
/// \author
/// \since

#include "Framework/runDataProcessing.h"
#include "Framework/AnalysisTask.h"
#include "Framework/HistogramRegistry.h"
#include "PWGHF/DataModel/CandidateReconstructionTables.h"
#include "PWGHF/DataModel/CandidateSelectionTables.h"

using namespace o2;
using namespace o2::framework;
using namespace o2::framework::expressions;

// STEP 4
// This is the same as STEP 3, but now we read the derived table from the derived AO2D.root written on disk

//<- starting point, define the derived table to be stored
// this can be done in a separated header file, but for semplicity we do it in
// the same file here

namespace o2::aod
{
namespace mytable
{
DECLARE_SOA_COLUMN(InvMassD0, invMassD0, float);           //!
DECLARE_SOA_COLUMN(InvMassD0bar, invMassD0bar, float);     //!
DECLARE_SOA_COLUMN(Pt, pt, float);                         //!
DECLARE_SOA_COLUMN(CosinePointing, cosinePointing, float); //!
DECLARE_SOA_INDEX_COLUMN(Collision, collision);            //!
} // namespace mytable

DECLARE_SOA_TABLE(MyTable, "AOD", "MYTABLE", //!
                  mytable::InvMassD0,
                  mytable::InvMassD0bar,
                  mytable::Pt,
                  mytable::CosinePointing,
                  mytable::CollisionId)

} // namespace o2::aod

struct ReadDerivedTable { //<- workflow that reads derived table and fill
                          // histograms

  HistogramRegistry registry{"registry",
                             {{"hMassD0", ";#it{M}(K#pi) (GeV/#it{c}^{2});counts", {HistType::kTH1F, {{300, 1.75, 2.05}}}},
                              {"hMassD0bar", ";#it{M}(#piK) (GeV/#it{c}^{2});counts", {HistType::kTH1F, {{300, 1.75, 2.05}}}},
                              {"hPt", ";#it{p}_{T} (GeV/#it{c});counts", {HistType::kTH1F, {{50, 0., 50.}}}},
                              {"hCosp", ";cos(#vartheta_{P}) ;counts", {HistType::kTH1F, {{100, 0.8, 1.}}}}}};

  void process(aod::MyTable const& cand2Prongs)
  {

    // loop over 2-prong candidates
    for (auto& cand : cand2Prongs) {
      registry.fill(HIST("hMassD0"), cand.invMassD0());
      registry.fill(HIST("hMassD0bar"), cand.invMassD0bar());
      registry.fill(HIST("hPt"), cand.pt());
      registry.fill(HIST("hCosp"), cand.cosinePointing());
    }
  }
};

WorkflowSpec defineDataProcessing(ConfigContext const& cfgc)
{
  return WorkflowSpec{adaptAnalysisTask<ReadDerivedTable>(cfgc)};
}

