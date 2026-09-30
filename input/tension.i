[Mesh]
 [rectange]
  type = GeneratedMeshGenerator
  xmin = 0.
  xmax = 3.
  ymin = 0.
  ymax = 1.
  nx = 300
  ny = 100
  dim = 2
 []
[]

[Variables]
  [ux]
  []
  [uy]
  []
[]

[Kernels]
 [momentum]
  type = Equilibrium_2D 
  variable = u 
 []
[]

[BCs]

  [./bottom] # arbitrary user-chosen name
    type = NeumannBC
    variable = T
    boundary = bottom # This must match a named boundary in the mesh file
    value = 0.
  [../]

  [./top] # arbitrary user-chosen name
    type = NeumannBC
    variable = T
    boundary = top # This must match a named boundary in the mesh file
    value = 0.
  [../]

  [./left] # arbitrary user-chosen name
    type = DirichletBC
    variable = T
    boundary = left
    value = 278.15
  [../]

  [./right] # arbitrary user-chosen name
    type = NeumannBC
    variable = T
    boundary = right
    value = 0.
  [../]
[]

[Executioner]
  type = Transient
  solve_type = 'PJFNK'

  start_time = 0.0
   num_steps = 50
          dt = 0.0001
[]

[Outputs]
  exodus = true
[]
