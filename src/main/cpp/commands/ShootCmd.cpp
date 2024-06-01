// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ShootCmd.h"

ShootCmd::ShootCmd(ShootSub *pShootSub, frc::XboxController *pController, double scale) 
{
  m_pShootSub = pShootSub;
  m_pController = pController;
  m_scale = scale;
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_pShootSub);
}

// Called when the command is initially scheduled.
void ShootCmd::Initialize() 
{
  m_pShootSub->Init();
}

// Called repeatedly when this Command is scheduled to run
void ShootCmd::Execute() 
{
  if (m_pShootSub != nullptr or m_pController != nullptr)
  {
    return;
  }

  double speed = m_pController->GetRightTriggerAxis()*m_scale;

  if(m_pController->GetLeftBumper() == true)
  {
    m_pShootSub->Shoot(-speed);
  }
  else
  {
    m_pShootSub->Shoot(speed);
  }
}

// Called once the command ends or is interrupted.
void ShootCmd::End(bool interrupted) 
{
    m_pShootSub->Shoot(0.0);
}

// Returns true when the command should end.
bool ShootCmd::IsFinished() 
{
  return m_isFinished;
}
