#!/bin/bash
RUN=$1
mkdir -p ${RUN}/plots
sed -i "s/string run = \"run[0-9]*/string run = \"${RUN}/" fusorsim.cpp
sed -i "s/run = 'run[0-9]*/run = '${RUN}/" traj_distribution.py
sed -i "s/run = 'run[0-9]*/run = '${RUN}/" pot_radial_allaxes.py