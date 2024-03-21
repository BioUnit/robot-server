#include "robotgpio.hpp"   //GPIO controls for robot
#include "myvideo.h"
#include <iostream>
#include <unistd.h>
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;

std::string tcp_read(tcp::socket& socket) {
   boost::asio::streambuf buf;
   boost::asio::read_until(socket, buf, "\0");
   std::string data = boost::asio::buffer_cast<const char*>(buf.data());
   return data;
}

int main(int argv, char** argc){
   /* Initialize GPIO for robot */
   RobotGpio my_robot;
   my_robot.init();

   /* Socket initialization */
   boost::asio::io_service my_service;
   tcp::acceptor my_acceptor(my_service, tcp::endpoint(tcp::v4(), 1000));
   tcp::socket my_socket(my_service);
   my_acceptor.accept(my_socket);

   /* Video stream initialization and start */
   if(create_video_pipeline() == -1){
      std::cout << "Pipeline creation failed!\n" << std::endl;
   } else {
      start_video_pipeline();
   }

   /* Simple TCP message parcer */
   while(1){
      std::string message = tcp_read(my_socket);

      if(!message.empty()) {
          if(message.compare("LP") == 0){
             std::cout << "command:LP\r\n" << std::endl;
             my_robot.move_left();
             message.clear();
          }
          if(message.compare("RP") == 0){
             std::cout << "command:RP\r\n" << std::endl;
             my_robot.move_right();
             message.clear();
          }
          if(message.compare("FP") == 0){
             std::cout << "command:FP\r\n" << std::endl;
             my_robot.move_forward();
             message.clear();
          }
          if(message.compare("BP") == 0){
             std::cout << "command:BP\r\n" << std::endl;
             my_robot.move_backward();
             message.clear();
          }
          if(message.compare("RR") == 0){
             std::cout << "command:RR\r\n" << std::endl;
             my_robot.stop();
             message.clear();
          }
          message.clear();
      }
   }
   /* release GPIO control */
   my_robot.release_lines();

   return 0;
}
