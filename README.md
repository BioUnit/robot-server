# robot-server overview
This program controls Banana Pi M2 Zero GPIO over TCP connection from "robot-control-gui" app 
C++ language version

# Dependencies
- apt install libgpiod-dev
- apt install build-essentials
- apt install libboost-all-dev

# how to build
g++ main.cpp robotgpio.cpp -lgpiodcxx

# how to run
sudo ./a.out
