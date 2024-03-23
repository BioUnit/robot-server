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

# Youtube tutorial commits bindings
To be able to see exact source code please use : 
- git checkout COMMIT_NUMBER_YOU_NEED

Youtube tutorials bindings:
- How to use GPIO in C and C++ applications on Banana Pi (Armbian) -> git checkout 37b72a640607d54128e420fb349d336eee941d58
