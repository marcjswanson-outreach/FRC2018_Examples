/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Drive/DifferentialDrive.h>
#include <IterativeRobot.h>
#include <Joystick.h>
#include <LiveWindow/LiveWindow.h>
#include <Spark.h>
#include <Timer.h>

using namespace frc;

class Robot : public IterativeRobot {

public:
	Robot()
	{
		m_Robot.SetExpiration(0.1);
		m_Timer.Start();
	}

	void RobotInit() override
	{

		m_LiveWindow = LiveWindow::GetInstance();
	}

	void AutonomousInit() override {
		m_Timer.Reset();
		m_Timer.Start();
	}

	void AutonomousPeriodic() override {
		// Drive for 2 seconds
		if (m_Timer.Get() < 2.0) {
			// Drive forwards half speed
			m_Robot.ArcadeDrive(-0.5, 0.0);
		} else {
			// Stop robot
			m_Robot.ArcadeDrive(0.0, 0.0);
		}
	}

	void TeleopInit() override {}

	void TeleopPeriodic() override {
		// Drive with arcade style (use right stick)
		m_Robot.ArcadeDrive(m_Stick.GetY(), m_Stick.GetX());
	}

	void TestPeriodic() override {}

private:
	static constexpr int kLeftChannel = 1;
	static constexpr int kRightChannel = 2;
	static constexpr int kJoystick = 0;

	Spark m_LeftMotor{kLeftChannel};
	Spark m_RightMotor{kRightChannel};
	DifferentialDrive m_Robot{m_LeftMotor, m_RightMotor};
	Joystick m_Stick{kJoystick};
	LiveWindow* m_LiveWindow{NULL};
	int m_AutoLoopCounter{0};
	Timer m_Timer;
};

START_ROBOT_CLASS(Robot)
