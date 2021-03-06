
#pragma once

#include "car_msgs/chassis.h"
#include "car_msgs/localization.h"
#include "car_msgs/trajectory.h"
#include "car_msgs/trajectory_point.h"
#include "planning/coordinate/car_state_sl.h"
#include "planning/tool/analytic_polynomial.h"
#include "yaml-cpp/yaml.h"

namespace planning {
// 数据帧
class Frame {
 public:
  Frame();
  ~Frame();
  void Init();

  // refrenceline
  const car_msgs::trajectory& refrenceline() { return refrenceline_; };
  car_msgs::trajectory* mutable_refrenceline() { return &refrenceline_; };
  const car_msgs::trajectory& raw_refrenceline() { return raw_refrenceline_; };
  car_msgs::trajectory* mutable_raw_refrenceline() {
    return &raw_refrenceline_;
  };
  const AnalyticPolynomial& analytic_refrenceline() {
    return analytic_refrenceline_;
  };
  AnalyticPolynomial* mutable_analytic_refrenceline() {
    return &analytic_refrenceline_;
  };
  // car state
  const car_msgs::trajectory_point& car_state() { return car_state_; };
  car_msgs::trajectory_point* mutable_car_state() { return &car_state_; };

  const CarStateSL& car_state_sl() { return car_state_sl_; };
  CarStateSL* mutable_car_state_sl() { return &car_state_sl_; };

  const car_msgs::localization& car_localization() {
    return car_localization_;
  };
  car_msgs::localization* mutable_car_localization() {
    return &car_localization_;
  };

  const car_msgs::chassis& car_chassis() { return car_chassis_; };
  car_msgs::chassis* mutable_car_chassis() { return &car_chassis_; };
  // planning traj
  const CarStateSL& planning_start_point() { return planning_start_point_; };
  CarStateSL* mutable_planning_start_point() { return &planning_start_point_; };
  const car_msgs::trajectory& trajectory_out() { return trajectory_out_; };
  car_msgs::trajectory* mutable_trajectory_out() { return &trajectory_out_; };
  const std::vector<CarStateSL>& trajectory_sl() { return trajectory_sl_; };
  std::vector<CarStateSL>* mutable_trajectory_sl() { return &trajectory_sl_; };
  // flags
  bool refrenceline_is_ready() { return refrenceline_is_ready_; };
  void set_refrenceline_is_ready(bool b) { refrenceline_is_ready_ = b; };
  bool trajectory_out_is_ready() { return trajectory_out_is_ready_; };
  void set_trajectory_out_is_ready(bool b) { trajectory_out_is_ready_ = b; };

 private:
  // refrenceline
  car_msgs::trajectory refrenceline_;
  car_msgs::trajectory raw_refrenceline_;
  AnalyticPolynomial analytic_refrenceline_;
  // car state
  car_msgs::trajectory_point car_state_;
  CarStateSL car_state_sl_;
  car_msgs::localization car_localization_;
  car_msgs::chassis car_chassis_;
  // planning traj
  CarStateSL planning_start_point_;
  car_msgs::trajectory trajectory_out_;
  std::vector<CarStateSL> trajectory_sl_;
  // obstacle list
  // flags
  bool refrenceline_is_ready_ = 0;
  bool trajectory_out_is_ready_ = 0;
};

}  // namespace planning