//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "THMTestApp.h"
#include "THMApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
THMTestApp::validParams()
{
  InputParameters params = THMApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

THMTestApp::THMTestApp(const InputParameters & parameters) : MooseApp(parameters)
{
  THMTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

THMTestApp::~THMTestApp() {}

void
THMTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  THMApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"THMTestApp"});
    Registry::registerActionsTo(af, {"THMTestApp"});
  }
}

void
THMTestApp::registerApps()
{
  registerApp(THMApp);
  registerApp(THMTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
THMTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  THMTestApp::registerAll(f, af, s);
}
extern "C" void
THMTestApp__registerApps()
{
  THMTestApp::registerApps();
}
