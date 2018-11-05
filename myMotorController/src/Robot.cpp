/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <IterativeRobot.h>
#include <Joystick.h>
#include <Spark.h>

using namespace frc;

/**
 * This sample program shows how to control a motor using a joystick. In the
 * operator control part of the program, the joystick is read and the value is
 * written to the motor.
 *
 * Joystick analog values range from -1 to 1 and speed controller inputs as
 * range from -1 to 1 making it easy to work together.
 */
class Robot : public IterativeRobot {
public:
	void TeleopPeriodic() override { m_motor.Set(m_stick.GetY()); }

private:
	static constexpr int kStick = 0;
	static constexpr int kMotor = 0;

	Joystick m_stick{kStick};
	Spark m_motor{kMotor};
};

START_ROBOT_CLASS(Robot)
