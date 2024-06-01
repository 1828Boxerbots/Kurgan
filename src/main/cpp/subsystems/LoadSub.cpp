// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LoadSub.h"

LoadSub::LoadSub() = default;

// This method will be called once per scheduler run
void LoadSub::Periodic() {}

void LoadSub::Init()
{
    //Nothing.
}

void LoadSub::LoadIn(double speed)
{
    m_loaderMotor.Set(speed);
}
