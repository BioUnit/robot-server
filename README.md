# robot-server overview
This program controls Banana Pi M2 Zero GPIO (Armbian) over TCP connection from "robot-control-gui" app and streams video from connected camera
C++ language version

# How to use
- clone repo
- change IP address in "myvideo.c"
- compile
- run "robot-server"
- change IP address in "robot-control-gui" sources (see README at "robot-control-gui")
- run "robot-control-gui"
- press buttons on gui
- observe everything through camera

# Dependencies
- apt install libgpiod-dev
- apt install build-essentials
- apt install libboost-all-dev
- Gstreamer (use instruction from here to install: https://gstreamer.freedesktop.org/documentation/installing/on-linux.html?gi-language=c )

# How to compile
Add paths to environment variables:
- export CPATH=/usr/include/gstreamer-1.0/:/usr/include/glib-2.0/:/usr/lib/arm-linux-gnueabihf/glib-2.0/include/
- export LIBRARY_PATH=/usr/lib/arm-linux-gnueabihf/:/usr/lib/arm-linux-gnueabihf/gstreamer1.0/:/usr/lib/arm-linux-gnueabihf/pkgconfig/
Compile:
- g++ -g main.cpp robotgpio.cpp myvideo.c -lgstreamer-1.0 -lglib-2.0 -lgobject-2.0 -lgpiodcxx

# How to run
sudo ./a.out

# Youtube tutorial commits bindings
To be able to see exact source code please use : 
- git checkout COMMIT_NUMBER_YOU_NEED

Youtube tutorials bindings:
- How to use GPIO in C and C++ applications on Banana Pi (Armbian) -> git checkout 37b72a640607d54128e420fb349d336eee941d58
- How to TCP on Embedded Linux -> git checkout 37b72a640607d54128e420fb349d336eee941d58
