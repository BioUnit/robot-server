# robot-server overview
This program controls Banana Pi M2 Zero GPIO (Armbian) over TCP connection from "robot-control-gui" app 
C++ language version

# How to use
- clone repo
- compile
- run "robot-server"
- change IP address in "robot-control-gui" sources (see README at "robot-control-gui")
- run "robot-control-gui"
- press buttons on gui

# Dependencies
- apt install libgpiod-dev
- apt install build-essentials
- apt install libboost-all-dev

# how to compile
g++ main.cpp robotgpio.cpp -lgpiodcxx

# how to run
sudo ./a.out
