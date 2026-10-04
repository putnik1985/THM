young_modulus = 2.e+11

[Mesh]
 [line]
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
   family = MONOMIAL_VEC
 []
 [sxx]
   order = FIRST
   family = MONOMIAL
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

 [sxx_kernel]
  type = VectorVariableComponentAux
  component = x
  variable = sxx
  vector_variable = stress
  execute_on = timestep_end
 []
[]

[BCs]
  [./left] 
    type = DirichletBC
    variable = u 
    boundary = right
    value = 0.
  [../]

  [./right] 
    type = StressBC
    variable = u 
    boundary = left

    sigma = 10000.
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
    type = ElementValueSampler
    variable = sxx
    sort_by = x
  []
[]

[Outputs]
     [exodus]
       type = Exodus
       execute_on = timestep_end
     []

     [gpl]
       type = Gnuplot
       extension = gpl
       execute_on = timestep_end
     []

     [csv]
       type = CSV
       execute_on = timestep_end
     []
[]
