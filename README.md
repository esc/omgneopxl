OMGNEOPXL
=========

About
-----

This is an Onion Omega 2 project to use the Arduino expansion to control a
strip of neopixels wirelessly.

High-level overview
-------------------

Essentially this project uses an Onion Omega 2 to run a Python based webserver
that can send commands to the arduino via serial console (UART). The Arduino
runs a little C program to drive the pixels and can accept a limited set of
commands to change color, speed and direction. The pattern that the neopixels
display is called "Theater Chase".

Getting Started
---------------

#. Setup your Onion Omega
#. Setup Arduino IDE
#. Install the NeoPixel library
#. Flash the Arduino wirelessly
#. Copy the files `bottle.py`, `server.py`, `interface.html` and `run.sh` to
the Omega.
#. Install `run.sh` to start automatically


Licence
-------

Copyright 2018 Valentin "Emergency Self-Construct" Haenel <valentin@haenel.co>

See LICENCE file for details.
