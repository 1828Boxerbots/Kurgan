// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Victor.h>
#include "Constants.h"

class LoadSub : public frc2::SubsystemBase 
{
 public:
  LoadSub();
  void Periodic() override;

  void Init();

  void LoadIn(double speed);

 private:
 frc::Victor m_loaderMotor{Loader::kLoader_PWM};
};
