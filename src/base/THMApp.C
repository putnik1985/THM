#include "THMApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
THMApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

THMApp::THMApp(const InputParameters & parameters) : MooseApp(parameters)
{
  THMApp::registerAll(_factory, _action_factory, _syntax);
}

THMApp::~THMApp() {}

void
THMApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<THMApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"THMApp"});
  Registry::registerActionsTo(af, {"THMApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
THMApp::registerApps()
{
  registerApp(THMApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
THMApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  THMApp::registerAll(f, af, s);
}
extern "C" void
THMApp__registerApps()
{
  THMApp::registerApps();
}
