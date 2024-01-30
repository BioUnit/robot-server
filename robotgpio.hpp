#include <gpiod.hpp>

class RobotGpio{
public:
   /*
   RobotGpio(){
      gpiod::chip my_chip("gpiochip0");
   }
   */
   void init(void);
   void release_lines(void);
   void move_left(void);
   void move_right(void);
   void move_forward(void);
   void move_backward(void);
   void stop(void);

private:
   gpiod::line line_20, line_21, line_10, line_17;
   gpiod::chip my_chip;
};
