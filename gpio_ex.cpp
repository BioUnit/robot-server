#include <gpiod.hpp>
#include <iostream>
#include <unistd.h>

int main(int argv, char** argc){
   ::gpiod::chip chip("gpiochip0");
   auto line_20 = chip.get_line(20);
   line_20.request({"bio_unit_gpio", gpiod::line_request::DIRECTION_OUTPUT, 0}, 0);
   
   for(int i=0; i<2; i++){
      line_20.set_value(1);
      sleep(1);
      line_20.set_value(0);
      sleep(1);
   }
   line_20.release();
   return 0;
}
