// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Victor.h>
#include "Constants.h"

class ShootSub : public frc2::SubsystemBase 
{
 public:
  ShootSub();
  void Periodic() override;

  void Init();

  void Shoot(double speed);

 private:
  frc::Victor m_leftMotorOne{Shooter::kLeftMotorOne_PWM};
  frc::Victor m_leftMotorTwo{Shooter::kLeftMotorTwo_PWM};
  frc::Victor m_rightMotorOne{Shooter::kRightMotorOne_PWM};
  frc::Victor m_rightMotorTwo{Shooter::kRightMotorTwo_PWM};
};
