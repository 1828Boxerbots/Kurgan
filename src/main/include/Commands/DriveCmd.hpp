#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <frc/XboxController.h>

#include "Subsystems/DriveSubsystem.hpp"

namespace Kurgan
{
    class DriveCmd : public frc2::CommandHelper<frc2::Command, DriveCmd>
    {
    public:
        DriveCmd(DriveSubsystem* pDriveSub, frc::XboxController* pController);
        ~DriveCmd();

        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override { return m_IsFinished; }

    protected:
    private:

        DriveSubsystem* m_pDriveSub = nullptr;
        frc::XboxController* m_pController = nullptr;
        
        bool m_IsFinished = false;
    };
}