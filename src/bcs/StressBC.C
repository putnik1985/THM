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
  params.addRequiredParam<Real>("E", "young modulus");
  params.addRequiredParam<Real>("sigma", "sigma");
  return params;
}

StressBC::StressBC(const InputParameters & parameters)
  : IntegratedBC(parameters),
    E(getParam<Real>("E")),
    sigma(getParam<Real>("sigma"))
{
}

Real
StressBC::computeQpResidual()
{
  // For this Neumann BC grad(u)= value / E on the boundary.
  return -_test[_i][_qp] * sigma / E;
}
