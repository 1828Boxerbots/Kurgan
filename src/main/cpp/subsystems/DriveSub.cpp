// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSub.h"

DriveSub::DriveSub() = default;

void DriveSub::Periodic() {}

void DriveSub::Init()
{
    m_rightMotorOne.SetInverted(true);
    m_rightMotorTwo.SetInverted(true);
}

void DriveSub::TankDrive(double left, double right)
{
    //Left:
    m_leftMotorOne.Set(left);
    m_leftMotorTwo.Set(left);

    //Right:
    m_rightMotorOne.Set(right);
    m_rightMotorTwo.Set(right);
}

void DriveSub::RCDrive(double vertical, double horizontal)
{
    TankDrive(vertical+horizontal, vertical-horizontal);
}


