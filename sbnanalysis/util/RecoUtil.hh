#ifndef __sbnanalysis_util_RecoUtil__
#define __sbnanalysis_util_RecoUtil__

// Frameworks
#include "canvas/Persistency/Common/Ptr.h" 
#include "larcore/Geometry/Geometry.h"
#include "core/ProviderManager.hh"

// LArSoft
#include "nusimdata/SimulationBase/MCParticle.h"
#include "nusimdata/SimulationBase/MCTruth.h"
#include "lardataobj/RecoBase/Hit.h"
#include "lardataobj/RecoBase/Track.h"
#include "lardataobj/Simulation/SimChannel.h"
#include "larsim/MCCheater/BackTrackerService.h"

// C++
#include <vector>
#include <map>

namespace util {


  /**
   * @brief  Returns the G4 MCParticle ID which contributes the most to a single reco hit
   *
   * @param  hit Recob::Hit
   * @param  rollup_saved_ids to prevent double-counting
   * @param  provider_manager to access BackTracker functions in SBNCode
   *
   * @return true particle ID
   *
   */
  int TrueParticleID(const art::Ptr< recob::Hit > hit, core::ProviderManager* provider_manager, bool rollup_unsaved_ids = 1);

  /**
   * @brief  Returns the G4 MCParticle ID which contributes the most reco hits
   *
   * @param  hits vector of Recob::Hits from the object
   * @param  rollup_saved_ids to prevent double-counting
   *
   * @return true particle ID
   *
   */
  int TrueParticleIDFromTotalRecoHits(const std::vector< art::Ptr< recob::Hit > >& hits, core::ProviderManager* provider_manager, bool rollup_unsaved_ids = 1);

  /**
   * @brief  Returns the G4 MCParticle ID which contributes the most energy
   *
   * @param  hit Recob::Hits from the object 
   * @param  rollup_saved_ids to prevent double-counting
   * @param  provider_manager to access BackTracker functions in SBNCode
   *
   * @return true particle ID
   *
   */
  int TrueParticleIDFromTotalTrueEnergy(const std::vector< art::Ptr< recob::Hit > >& hits, core::ProviderManager* provider_manager, bool rollup_unsaved_ids = 1);

  /**
   * @brief  Returns the G4 MCParticle ID which contributes the most reconstructed charge
   *
   * @param  hit Recob::Hits from the object 
   * @param  rollup_saved_ids to prevent double-counting
   * @param  provider_manager to access BackTracker functions in SBNCode
   *
   * @return true particle ID
   *
   */
  int TrueParticleIDFromTotalRecoCharge(const std::vector<art::Ptr<recob::Hit> >& hits, core::ProviderManager* provider_manager, bool rollup_unsaved_ids = 1);

}  // namespace util

#endif  // __sbnanalysis_util_RecoUtil__

