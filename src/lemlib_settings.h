#pragma once
#include "lemlib/chassis/chassis.hpp"
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

inline lemlib::TrackingWheel left_tracking_wheel(&left_mg, lemlib::Omniwheel::NEW_275, -5.75, 450);
inline lemlib::TrackingWheel right_tracking_wheel(&right_mg, lemlib::Omniwheel::NEW_275, -5.75, 450);

inline lemlib::ControllerSettings lateral_controller(
    10,   // kP — proportional gain
    0,    // kI — integral gain
    3,    // kD — derivative gain
    3,    // anti-windup
    1,    // small error range (in)
    100,  // small error timeout (ms)
    3,    // large error range (in)
    500,  // large error timeout (ms)
    10    // slew rate limit (in/s)
);

inline lemlib::ControllerSettings angular_controller(
    2,    // kP — proportional gain
    0,    // kI — integral gain
    10,   // kD — derivative gain
    3,    // anti-windup
    1,    // small error range (deg)
    100,  // small error timeout (ms)
    3,    // large error range (deg)
    500,  // large error timeout (ms)
    0     // slew rate limit (deg/s)
);

inline lemlib::OdomSensors sensors(&left_tracking_wheel, &right_tracking_wheel, nullptr, nullptr, &imu);

inline lemlib::Chassis chassis(
    drivetrain,
    lateral_controller,
    angular_controller,
    sensors
);
