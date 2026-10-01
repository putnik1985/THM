//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "Stress.h"

registerMooseObject("THMApp", Stress);

InputParameters
Stress::validParams()
{
  InputParameters params = AuxKernel::validParams();
  params.addRequiredParam<Real>("E", "E");
  params.addRequiredCoupledVar("displacement", "Displacement");

  return params;
}

Stress::Stress(const InputParameters & parameters)
  : AuxKernel(parameters),
    grad_u(coupledGradient("displacement")),
    young_modulus(getParam<Real>("E"))
{
}

Real
Stress::computeValue()
{
  return young_modulus * grad_u[_qp](0);
}
