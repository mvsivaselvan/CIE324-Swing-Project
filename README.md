# CIE 324 Swing Project
CIE 324 - Introduction to Structural design is a 3-credit junior-level class in the Civil Engineering program at the University at Buffalo.

The swing project is an introductory exercise in structural design. 
The project is accompanied by a physical swing set instrumented to measure swing orientation, angular velocity and acceleration
as well as tension in the swing chain and bending moment in the top bar of the swing-set frame.

This repository contains documentation on this swing set, Arduino code for the measurements,
and MATLAB code for data acquisition and postprocessing.

## Installing the HX711-multi library for load cell measurement
The HX711-multi library is used, that shares the clocks across multiple HX711 amplifiers.
There is timing issue in the code in the master branch, so we use the code in pull request #2.
In Windows Powershell (assuming Git for Windows, and ideally posh-git, have already been installed),
1. In the Documents\Ardunio\libraries directory, excute `git clone https://github.com/compugician/HX711-multi.git`
2. `cd HX711-multi`
3. `git fetch origin pull/2/head:pr2`
4. `git checkout pr2`

