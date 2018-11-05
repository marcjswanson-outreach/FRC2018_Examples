/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Drive/DifferentialDrive.h>
#include <IterativeRobot.h>
#include <Joystick.h>
#include <Spark.h>

using namespace frc;

/**
 * This is a demo program showing the use of the DifferentialDrive class.
 * Runs the motors with arcade steering.
 */
class Robot : public IterativeRobot {

public:
	void TeleopPeriodic() {

		// drive with arcade style
		m_robotDrive.ArcadeDrive(m_stick.GetY(), m_stick.GetX());
	}

private:
	static constexpr int kLeftChannel = 0;
	static constexpr int kRightChannel = 0;
	static constexpr int kStick = 0;

	Spark m_leftMotor{kLeftChannel};
	Spark m_rightMotor{kRightChannel};
	DifferentialDrive m_robotDrive{m_leftMotor, m_rightMotor};
	Joystick m_stick{kStick};
};

START_ROBOT_CLASS(Robot)
