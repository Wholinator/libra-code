/*********************************************************************************
* Copyright (C) 2015-2021 Alexey V. Akimov
*
* This file is distributed under the terms of the GNU General Public License
* as published by the Free Software Foundation, either version 3 of
* the License, or (at your option) any later version.
* See the file LICENSE in the root directory of this distribution
* or <http://www.gnu.org/licenses/>.
*
*********************************************************************************/
/**
  \file Dynamics_Nuclear.h
  \brief The file describes the functions for nuclear (classical) dynamics
    
*/

#ifndef DYNAMICS_H
#define DYNAMICS_H

// External dependencies
#include "../math_linalg/liblinalg.h"
#include "../nhamiltonian/libnhamiltonian.h"
#include "../io/libio.h"
#include "thermostat/Thermostat.h"

#include "dyn_decoherence.h"
#include "dyn_control_params.h"
#include "dyn_hop_acceptance.h"
#include "dyn_hop_proposal.h"
#include "dyn_methods.h"
#include "dyn_projectors.h"
#include "dyn_variables.h"
#include "dyn_ham.h"


/// liblibra namespace
namespace liblibra{

using namespace libio;
using namespace libnhamiltonian;
namespace bp = boost::python;

/// libdyn namespace
namespace libdyn{

using namespace libthermostat;



//========== Dynamics.cpp ===================

void aux_get_transforms(CMATRIX** Uprev, nHamiltonian& ham);

/*
void update_Hamiltonian_q(dyn_control_params& prms, MATRIX& q, nHamiltonian& ham, 
                          bp::object py_funct, bp::object model_params);
void update_Hamiltonian_q(bp::dict prms, MATRIX& q, nHamiltonian& ham, 
                          bp::object py_funct, bp::object model_params);

void update_Hamiltonian_q_ethd(dyn_control_params& prms, MATRIX& q, MATRIX& p, nHamiltonian& ham, 
                          bp::object py_funct, bp::object model_params, MATRIX& invM);
void update_Hamiltonian_q_ethd(bp::dict prms, MATRIX& q, MATRIX& p, nHamiltonian& ham, 
                          bp::object py_funct, bp::object model_params, MATRIX& invM);



void update_Hamiltonian_p(dyn_control_params& prms, nHamiltonian& ham, MATRIX& p, MATRIX& invM);
void update_Hamiltonian_p(bp::dict prms, nHamiltonian& ham, MATRIX& p, MATRIX& invM);

void update_nacs(dyn_control_params& prms, nHamiltonian& ham);

*/

// Adding the NBRA flag to the functions in the header
vector<CMATRIX> compute_St(nHamiltonian& ham, int isNBRA);
vector<CMATRIX> compute_St(nHamiltonian& ham);

vector<CMATRIX> compute_St(nHamiltonian& ham, nHamiltonian& ham_prev, int isNBRA);
vector<CMATRIX> compute_St(nHamiltonian& ham, nHamiltonian& ham_prev);

//vector<CMATRIX> compute_St(nHamiltonian& ham, vector<CMATRIX>& Uprev, int isNBRA);
//vector<CMATRIX> compute_St(nHamiltonian& ham, vector<CMATRIX>& Uprev);



void compute_dynamics(MATRIX& q, MATRIX& p, MATRIX& invM, CMATRIX& C, vector<CMATRIX>& projectors, vector<int>& act_states, 
              nHamiltonian& ham, bp::object py_funct, bp::dict model_params, bp::dict dyn_params, Random& rnd);

void compute_dynamics(MATRIX& q, MATRIX& p, MATRIX& invM, CMATRIX& C, vector<CMATRIX>& projectors, vector<int>& act_states, 
              nHamiltonian& ham, bp::object py_funct, bp::dict& model_params, bp::dict& dyn_params, Random& rnd, 
              vector<Thermostat>& therm);

void compute_dynamics(MATRIX& q, MATRIX& p, MATRIX& invM, CMATRIX& C, vector<CMATRIX>& projectors, vector<int>& act_states, 
              nHamiltonian& ham, bp::object py_funct, bp::dict& model_params, bp::dict& dyn_params, Random& rnd, 
              vector<Thermostat>& therm, dyn_variables& dyn_var);

void compute_dynamics(dyn_variables& dyn_var, bp::dict dyn_params, nHamiltonian& ham, nHamiltonian& ham_aux, 
                      bp::object py_funct, bp::dict model_params, Random& rnd, vector<Thermostat>& therm);





}// namespace libdyn
}// liblibra

#endif // DYNAMICS_H

