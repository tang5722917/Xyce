//-------------------------------------------------------------------------
//   Copyright 2002-2019 National Technology & Engineering Solutions of
//   Sandia, LLC (NTESS).  Under the terms of Contract DE-NA0003525 with
//   NTESS, the U.S. Government retains certain rights in this software.
//
//   This file is part of the Xyce(TM) Parallel Electrical Simulator.
//
//   Xyce(TM) is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
//   Xyce(TM) is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with Xyce(TM).
//   If not, see <http://www.gnu.org/licenses/>.
//-------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//
// Purpose        : Solver Factory for PCE 
//
// Special Notes  :
//
// Creator        : Eric Keiter, SNL
//
// Creation Date  : 6/27/2019
//
//
//
//
//-----------------------------------------------------------------------------

#ifndef Xyce_N_LAS_PCESolverFactory_h
#define Xyce_N_LAS_PCESolverFactory_h

// ---------- Standard Includes ----------

#include <string>

#include <N_LOA_fwd.h>
#include <N_LAS_fwd.h>

#include <N_LAS_SolverFactory.h>
#include <N_ERH_ErrorMgr.h>
#include <N_UTL_OptionBlock.h>

#include <Teuchos_RCP.hpp>

// ----------  Fwd Declares  -------------

namespace Xyce {
namespace Linear {

//-----------------------------------------------------------------------------
// Class         : PCESolverFactory
// Purpose       : 
// Special Notes :
// Creator       : Heidi Thornquist, SNL, Electrical & Microsystem Modeling
// Creation Date : 11/11/08
//-----------------------------------------------------------------------------
class PCESolverFactory : public SolverFactory
{
public:
  // Basic Constructor, sets solver factory options.
  PCESolverFactory( Linear::Builder &builder );

  // Destructor
  virtual ~PCESolverFactory() {} 

  // Creates a new solver.
  Solver * create( Util::OptionBlock & options, Problem & problem, const IO::CmdParse & command_line) const;

#if 0
  // Set the time step(s) being used in the PCE analysis.
  // NOTE:  This is only useful for FD solution techniques.
  void setTimeSteps( const std::vector<double> & timeSteps )
    { timeSteps_ = timeSteps; }

  void setESFreqs( const std::vector<double> & freqs )
    { freqs_ = freqs; }

  // Set the fast times being used in the ES analysis.
  void setFastTimes( const std::vector<double> & times )
    { times_ = times; }

  void setESOsc( const bool osc )
    { hbOsc_ = osc; }
#endif

  // Register the application system loader
  void registerPCELoader( const Teuchos::RCP<Loader::PCELoader>& pceLoaderPtr ) 
    { pceLoaderPtr_ = pceLoaderPtr; }

  // Register the PCE builder 
  void registerPCEBuilder( const Teuchos::RCP<PCEBuilder>& pceBuilder ) 
    { pceBuilderPtr_ = pceBuilder; }

private:
#if 0
  bool                          hbOsc_;
#endif
  Builder &                     builder_;
#if 0
  std::vector<double>    times_, timeSteps_, freqs_;
#endif
  Teuchos::RCP<Loader::PCELoader> pceLoaderPtr_;
  Teuchos::RCP<PCEBuilder> pceBuilderPtr_;
  Teuchos::RCP<Util::OptionBlock> optionBlock_;

  // Copy constructor.
  PCESolverFactory( const PCESolverFactory& pf );
};

} // namespace Linear
} // namespace Xyce

#endif
