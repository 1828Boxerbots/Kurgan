// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/LoadCmd.h"

LoadCmd::LoadCmd(LoadSub *pLoadSub, frc::XboxController *pController, double speed) 
{
  m_pLoadSub = pLoadSub;
  m_pController = pController;
  m_speed = speed;
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_pLoadSub);
}

// Called when the command is initially scheduled.
void LoadCmd::Initialize() 
{
  m_pLoadSub->Init();
}

// Called repeatedly when this Command is scheduled to run
void LoadCmd::Execute() 
{
  if (m_pLoadSub != nullptr or m_pController != nullptr)
  {
    return;
  }

  if(m_pController->GetLeftBumper() == true)
  {
    m_pLoadSub->LoadIn(-m_speed);
  }
  else
  {
    m_pLoadSub->LoadIn(m_speed);
  }
}

// Called once the command ends or is interrupted.
void LoadCmd::End(bool interrupted) 
{
  m_pLoadSub->LoadIn(0.0);
}

// Returns true when the command should end.
bool LoadCmd::IsFinished() 
{
  return m_isFinished;
}
