// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <frc2/command/button/Trigger.h>
#include "commands/Autos.h"
#include "commands/DriveCmd.h"
#include "commands/LoadCmd.h"
#include "commands/ShootCmd.h"

RobotContainer::RobotContainer() 
{
  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::Init()
{
  m_driveSub.Init();
  m_loadSub.Init();
  m_shootSub.Init();

  m_driveSub.SetDefaultCommand(DriveCmd(&m_driveSub, &m_driveControl, 1.0).ToPtr()); //Check.
}

void RobotContainer::ConfigureBindings() 
{
  // Configure your trigger bindings here
  m_driveControl.X().WhileTrue(LoadCmd(&m_loadSub, &m_driveControl, -1.0).ToPtr());
  m_driveControl.Y().WhileTrue(LoadCmd(&m_loadSub, &m_driveControl, 1.0).ToPtr());
  m_driveControl.RightTrigger().WhileTrue(ShootCmd(&m_shootSub, &m_driveControl).ToPtr());
}

int RobotContainer::DPDTSwitch()
{
  //No use for it yet (2024).
  return 0;
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() 
{
  return NullAutoCmdGroup().ToPtr();
}