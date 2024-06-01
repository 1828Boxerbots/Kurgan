// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <frc/XboxController.h>
#include "subsystems/DriveSub.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class DriveCmd : public frc2::CommandHelper<frc2::Command, DriveCmd> 
{
 public:
  DriveCmd(DriveSub *pDriveSub, frc::XboxController *pController, double scale = 1.0);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
  DriveSub* m_pDriveSub = nullptr;
  frc::XboxController* m_pController = nullptr;
  
  bool m_isFinished = false;
  double m_scale = 0.0;
  double m_leftY = 0.0;
  double m_rightY = 0.0;
  double m_leftX = 0.0;
  double m_rightX = 0.0;
};
