/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <DoubleSolenoid.h>
#include <IterativeRobot.h>
#include <Joystick.h>
#include <Solenoid.h>

using namespace frc;

/**
 * This is a sample program showing the use of the solenoid classes during
 *   operator control.
 * Three buttons from a joystick will be used to control two solenoids:
 *   One button to control the position of a single solenoid and the other
 *   two buttons to control a double solenoid.
 * Single solenoids can either be on or off, such that the air diverted through
 *   them goes through either one channel or the other.
 * Double solenoids have three states: Off, Forward, and Reverse. Forward and
 *   Reverse divert the air through the two channels and correspond to the
 *   on and off of a single solenoid, but a double solenoid can also be "off",
 *   where both channels are diverted to exhaust such that there is no pressure
 *   in either channel.
 * Additionally, double solenoids take up two channels on your PCM whereas
 *   single solenoids only take a single channel.
 */
class Robot : public frc::IterativeRobot {
public:
	void TeleopPeriodic() override {
		/* The output of GetRawButton is true/false depending on whether
		 * the button is pressed; Set takes a boolean for for whether to
		 * use the default (false) channel or the other (true).
		 */
		m_singleSolenoid.Set(m_stick.GetRawButton(kSingleSolenoidButton));

		/* In order to set the double solenoid, we will say that if neither
		 * button is pressed, it is off, if just one button is pressed,
		 * set the solenoid to correspond to that button, and if both
		 * are pressed, set the solenoid to Forwards.
		 */
		if (m_stick.GetRawButton(kDoubleSolenoidForwardButton))
		{
			m_doubleSolenoid.Set(DoubleSolenoid::kForward);

		} else if (m_stick.GetRawButton(kDoubleSolenoidReverseButton)) {

			m_doubleSolenoid.Set(DoubleSolenoid::kReverse);

		} else
		{
			m_doubleSolenoid.Set(DoubleSolenoid::kOff);
		}
	}

private:
	static constexpr int kStick = 0;

	static constexpr int kSingleSolenoidChannel = 0;
	static constexpr int kSingleSolenoidButton = 1;

	static constexpr int kDoubleSolenoidChannelForward = 1;
	static constexpr int kDoubleSolenoidChannelReverse = 2;
	static constexpr int kDoubleSolenoidForwardButton = 2;
	static constexpr int kDoubleSolenoidReverseButton = 3;

	Joystick m_stick{kStick};

	Solenoid m_singleSolenoid{kSingleSolenoidChannel};
	DoubleSolenoid m_doubleSolenoid{kDoubleSolenoidChannelForward, kDoubleSolenoidChannelReverse};
};

START_ROBOT_CLASS(Robot)
