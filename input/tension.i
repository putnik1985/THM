young_modulus = 2.e+11

[Mesh]
 [rectangle]
  type = GeneratedMeshGenerator
  xmin = 0.
  xmax = 3.
  nx = 300
  dim = 1
 []
[]

[Variables]
  [u]
    order = FIRST
    family = LAGRANGE
  []
[]

[Kernels]
 [u_kernel]
  type = Equilibrium_1D 
  variable = u 

  E = ${young_modulus}
 []
[]

[AuxVariables]
 [stress]
   order = FIRST
   family = LAGRANGE
 []
[]

[AuxKernels]
 [stress_kernel]
   type = Stress
   variable = stress
   displacement = u
   
   E = ${young_modulus}
   execute_on = timestep_end
 [] 
[]

[BCs]
  [./left] 
    type = DirichletBC
    variable = u 
    boundary = left
    value = 0.
  [../]
  [./right] 
    type = DirichletBC
    variable = u 
    boundary = right
    value = 3.
  [../]
[]

[Executioner]
  type = Steady
  solve_type = 'PJFNK'
[]

[VectorPostprocessors]
  [deflection]
    type = NodalValueSampler
    variable = u
    sort_by = x
  []
  [sigma]
    type = NodalValueSampler
    variable = stress
    sort_by = x
  []
[]

[Outputs]
     [csv]
       type = CSV
       execute_on = timestep_end
     []
[]
