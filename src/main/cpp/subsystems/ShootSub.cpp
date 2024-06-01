// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ShootSub.h"

ShootSub::ShootSub() = default;

void ShootSub::Periodic() {}

void ShootSub::Init()
{
    //SetInverted:
    m_rightMotorOne.SetInverted(true); //Check.
    m_rightMotorTwo.SetInverted(true); //Check.
}

void ShootSub::Shoot(double speed)
{
    m_leftMotorOne.Set(speed);
    m_leftMotorTwo.Set(speed);
    m_rightMotorOne.Set(speed);
    m_rightMotorTwo.Set(speed);
}
