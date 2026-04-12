
<h1>Run 1 Sun April 12th </h1>

Ion Beam Simulator 1.0.6dev (89c1280, Thu Oct 26 17:14:45 2023 +0300)
Constructing Geometry from stream
  Warning: loading of STLSolid not implemented
  Warning: loading of STLSolid not implemented
  Warning: loading of STLSolid not implemented
Calculating efield
Solving problem
  dof = 16957183
  Using BiCGSTAB-ILU0 solver (imax = 10000, eps = 0.0001)
    168         9.627154e-05  
  error estimate = 9.62715e-05
  iterations = 168
  time used = 177.446 s (183.976 s realtime)
Calculating efield
Calculating particle trajectories
  Using solid collision model
  Using non-relativistic iterator
  1000 / 1000 Done
  Finalizing space charge density map (PIC method)
  Particle histories (1000 total):
    flown = 984
    time limited = 0
    step count limited = 16
    bad definitions = 0
    beam to boundary 1 = 0.000528 A (264 particles)
    beam to boundary 2 = 0.000242 A (121 particles)
    beam to boundary 3 = 0.000404 A (202 particles)
    beam to boundary 4 = 0.000388 A (194 particles)
    beam to boundary 5 = 2.2e-05 A (11 particles)
    beam to boundary 6 = 0.000384 A (192 particles)
    beam to boundary 7 = 0 A (0 particles)
    beam to boundary 8 = 0 A (0 particles)
    beam to boundary 9 = 0 A (0 particles)
    total steps = 92895
    steps per particle (ave) = 92.895
  time used = 0.265818 s (0.28767 s realtime)
Plotting to PNG-file "trajdens_xz_1000.png"
Plotting to PNG-file "-1_xz_final_1000.png"
Ending simulation
  time used = 179.216 s (185.78 s realtime)

  <h1> Review</h1>
  - Used wrong cathode potential polarity (sent all the particles to the wall)
  - Other than that very good
