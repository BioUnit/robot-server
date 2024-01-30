#include "robotgpio.hpp"
#include <iostream>

void RobotGpio::init(void){
   my_chip.open("gpiochip0",gpiod::chip::OPEN_LOOKUP);
   if(!my_chip){
      std::cout << "Bad chip" << std::endl;
   }

   line_20 = my_chip.get_line(20);
   line_21 = my_chip.get_line(21);
   line_10 = my_chip.get_line(10);
   line_17 = my_chip.get_line(17);

   line_20.request({"bio_unit_gpio", gpiod::line_request::DIRECTION_OUTPUT, 0}, 0);
   line_21.request({"bio_unit_gpio", gpiod::line_request::DIRECTION_OUTPUT, 0}, 0);
   line_10.request({"bio_unit_gpio", gpiod::line_request::DIRECTION_OUTPUT, 0}, 0);
   line_17.request({"bio_unit_gpio", gpiod::line_request::DIRECTION_OUTPUT, 0}, 0);
}

void RobotGpio::release_lines(void){
   line_20.release();
   line_21.release();
   line_10.release();
   line_17.release();
}

void RobotGpio::move_left(void){
   line_10.set_value(1);
}

void RobotGpio::move_right(void){
   line_20.set_value(1);
}

void RobotGpio::move_forward(void){
   line_10.set_value(1);
   line_20.set_value(1);
}

void RobotGpio::move_backward(void){
   line_21.set_value(1);
   line_17.set_value(1);
}

void RobotGpio::stop(void){
   line_20.set_value(0);
   line_21.set_value(0);
   line_10.set_value(0);
   line_17.set_value(0);
}
