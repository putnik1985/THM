//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "Equilibrium_1D.h"

registerMooseObject("THMApp", Equilibrium_1D);

InputParameters
Equilibrium_1D::validParams()
{
  auto params = ADKernelGrad::validParams();
  params.addClassDescription("Same as `Diffusion` in terms of physics/residual, but the Jacobian "
                             "is computed using forward automatic differentiation");

  params.addRequiredParam<Real>("E", "Young Modulus");
  return params;
}

Equilibrium_1D::Equilibrium_1D(const InputParameters & parameters) : 
ADKernelGrad(parameters),
E(getParam<Real>("E"))
{}

ADRealVectorValue
Equilibrium_1D::precomputeQpResidual()
{
  return E * _grad_u[_qp];
}
