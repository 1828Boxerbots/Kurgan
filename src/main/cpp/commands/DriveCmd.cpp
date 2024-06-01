// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveCmd.h"

DriveCmd::DriveCmd(DriveSub *pDriveSub, frc::XboxController *pController, double scale) 
{
  m_pDriveSub = pDriveSub;
  m_pController = pController;
  m_scale = scale;
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_pDriveSub);
}

// Called when the command is initially scheduled.
void DriveCmd::Initialize() 
{
  m_pDriveSub->Init();
}

// Called repeatedly when this Command is scheduled to run
void DriveCmd::Execute() 
{
  if (m_pDriveSub != nullptr or m_pController != nullptr)
  {
    return;
  }

  m_leftX = m_pController->GetLeftX();
  m_leftY = -m_pController->GetLeftY();
  m_rightX = m_pController->GetRightX();
  m_rightY = -m_pController->GetRightY();

  //m_pDriveSub->TankDrive(m_leftY*m_scale, m_rightY*m_scale);
  m_pDriveSub->RCDrive(m_leftY*m_scale, m_rightX*m_scale);
}

// Called once the command ends or is interrupted.
void DriveCmd::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveCmd::IsFinished() 
{
  return m_isFinished;
}
