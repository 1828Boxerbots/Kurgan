// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace DriveTrain
{
    inline constexpr int kLeftMotorOne = 2; //PWM
    inline constexpr int kLeftMotorTwo = 1; //PWM
    inline constexpr int kRightMotorOne = 3; //PWM
    inline constexpr int kRightMotorTwo = 4; //PWM


constexpr int PWM_LOADER_KURGAN         = 0;
constexpr int DIO_PHOTOGATE_KURGAN      = 0;
}

namespace Shooter
{
    inline constexpr int kLeftMotorOne_PWM = 6; //PWM
    inline constexpr int kLeftMotorTwo_PWM = 7; //PWM
    inline constexpr int kRightMotorOne = 5; //PWM
    inline constexpr int kRightMotorTwo = 8 ;//PWM
}

namespace Loader
{

}