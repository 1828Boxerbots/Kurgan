// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/Commands.h>

#include "Commands/DriveCmd.hpp"
#include "Commands/ShootCmd.hpp"
#include "Commands/LoadCmd.hpp"
#include "Commands/SpitOutCmd.hpp"

RobotContainer::RobotContainer() {
  ConfigureBindings();
}

void RobotContainer::Init()
{
  m_Drive.Init();
  m_Drive.SetDefaultCommand(Kurgan::DriveCmd(&m_Drive, &m_DriveController));

  m_Shooter.Init();
  m_Loader.Init();
  m_DemoMode.Init();
}

void RobotContainer::ConfigureBindings() {
  // TODO: Configure bindings

  // Loader Commands
  m_DriveController.B().ToggleOnTrue(Kurgan::LoadCmd(0.8, &m_Loader).ToPtr());
  (m_DriveController.LeftBumper() && m_DriveController.B()).WhileTrue(Kurgan::SpitOutCmd(0.8, &m_Loader).ToPtr());

  // Shooter Commands
  m_DriveController.RightTrigger().WhileTrue(Kurgan::ShootCmd(1.0, &m_Shooter).ToPtr());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  return frc2::cmd::Print("No autonomous command configured");
}
