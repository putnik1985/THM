//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "AuxKernel.h"

class Stress : public VectorAuxKernel
{
public:
  Stress(const InputParameters & parameters);
  static InputParameters validParams();

protected:
  virtual RealVectorValue computeValue() override;

private:
  const VariableGradient & grad_u;
  const Real young_modulus;
};
