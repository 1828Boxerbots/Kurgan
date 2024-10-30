// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>

#include "PortManager.hpp"

#include "Subsystems/DriveSubsystem.hpp"
#include "Subsystems/ShooterSubsystem.hpp"
#include "Subsystems/LoaderSubsystem.hpp"
#include "Subsystems/DemoMode.hpp"

class RobotContainer {
 public:
  RobotContainer();

  void Init();

  frc2::CommandPtr GetAutonomousCommand();

 private:
  void ConfigureBindings();

  frc2::CommandXboxController m_DriveController { (int)Kurgan::PortManager::Instance().GetUSBPort("DriveController") };

  Kurgan::DriveSubsystem m_Drive;
  Kurgan::ShooterSubsystem m_Shooter;
  Kurgan::LoaderSubsystem m_Loader;
  Kurgan::DemoMode m_DemoMode;
};
