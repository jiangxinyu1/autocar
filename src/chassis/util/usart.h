#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <memory>

namespace chassis {

#define SEND_BUF_SIZE 64

#define BYTE0(dwTemp) (*(char *)(&dwTemp))
#define BYTE1(dwTemp) (*((char *)(&dwTemp) + 1))
#define BYTE2(dwTemp) (*((char *)(&dwTemp) + 2))
#define BYTE3(dwTemp) (*((char *)(&dwTemp) + 3))

//uart串口，用于与底层stm32通信。
class Usart {
 public:
  Usart(const std::string &port_name);
  ~Usart();

 private:
  bool init_port(const std::string port, const unsigned int char_size);

 public:
  void send_to_serial(const uint16_t &throttle, const uint16_t &brake,
                      const int16_t &steer);

  void reveive_from_serial(double &speed, double &ang_x, double &ang_y,
                           double &ang_z, double &acc_x, double &acc_y,
                           double &acc_z, double &ang_v_x, double &ang_v_y,
                           double &ang_v_z, char &flag);

 private:
  boost::asio::io_service ios_;
  std::unique_ptr<boost::asio::serial_port> serial_port_;
  boost::system::error_code err_code_;

  uint8_t Send_BUF[SEND_BUF_SIZE];
};

}  // namespace chassis