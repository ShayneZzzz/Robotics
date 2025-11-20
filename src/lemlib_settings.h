#pragma once
#include "lemlib/chassis/trackingWheel.hpp"
#include "main.h"
#include "lemlib/api.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/optical.hpp"

inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline pros::MotorGroup left_mg({1, -2, 3});
inline pros::MotorGroup right_mg({-4, 5, -6});

inline pros::IMU imu(13);
inline pros::optical col_en(10);

inline lemlib::Drivetrain drivetrain(&left_mg,&right_mg,
11.5,
lemlib::Omniwheel::NEW_275,
450,
2
);
