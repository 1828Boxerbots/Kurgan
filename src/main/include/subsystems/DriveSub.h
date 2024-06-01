// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Victor.h>
#include "Constants.h"

class DriveSub : public frc2::SubsystemBase 
{
 public:
  DriveSub();
  void Periodic() override;

  void Init();

  void TankDrive(double left, double right);
  void RCDrive(double vertical, double horizontal);

 private:
  frc::Victor m_leftMotorOne{DriveTrain::kLeftMotorOne_PWM};
  frc::Victor m_leftMotorTwo{DriveTrain::kLeftMotorTwo_PWM};
  frc::Victor m_rightMotorOne{DriveTrain::kRightMotorOne_PWM};
  frc::Victor m_rightMotorTwo{DriveTrain::kRightMotorTwo_PWM};
};
