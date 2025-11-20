#include "lemlib_settings.h"
#include "main.h"
#include "main.cpp"

void initialize(){
    chassis.calibrate();
    chassis.setPose(0,0,0);
}

void autonomous() {
    chassis.moveToPoint(1200, 1200, 1000);
    chassis.turnToHeading(25,24);
    chassis.moveToPoint(1500,1500,1500);

    pros::delay(1000);

    

}
