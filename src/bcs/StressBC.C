//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "StressBC.h"

registerMooseObject("THMApp", StressBC);

InputParameters
StressBC::validParams()
{
  InputParameters params = IntegratedBC::validParams();

  // Specify input parameters that we want users to be able to set:
  params.addRequiredParam<Real>("sigma", "sigma");
  return params;
}

StressBC::StressBC(const InputParameters & parameters)
  : IntegratedBC(parameters),
    sigma(getParam<Real>("sigma"))
{
}

Real
StressBC::computeQpResidual()
{
  // For this Neumann BC E * grad(u)= sigma on the boundary.
  return -_test[_i][_qp] * sigma;
}
