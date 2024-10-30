#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "Subsystems/ShooterSubsystem.hpp"

namespace Kurgan
{
    class ShootCmd : public frc2::CommandHelper<frc2::Command, ShootCmd>
    {
    public:
        ShootCmd(float speed, ShooterSubsystem* pShootSub);
        ~ShootCmd();

        void Initialize() override;
        void Execute() override;
        void End(bool interrupited) override;
        bool IsFinished() override { return m_IsFinished; }

    protected:
    private:
        ShooterSubsystem* m_pShooterSub;
        float m_Speed;

        bool m_IsFinished = false;
    };
}