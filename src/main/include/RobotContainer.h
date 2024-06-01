// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>
#include "commands/NullAutoCmdGroup.h"
#include "subsystems/DriveSub.h"
#include "subsystems/LoadSub.h"
#include "subsystems/ShootSub.h"
#include "Constants.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer 
{
 public:
  RobotContainer();
  frc2::CommandPtr GetAutonomousCommand();

  void Init();

  int DPDTSwitch();

 private:
// Controller:
  frc2::CommandXboxController m_driveControl{XboxControl::kPort};
  void ConfigureBindings();

// Subsystems:
  DriveSub m_driveSub;
  LoadSub m_loadSub;
  ShootSub m_shootSub;
};
