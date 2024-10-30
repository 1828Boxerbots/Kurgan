#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "Subsystems/LoaderSubsystem.hpp"

namespace Kurgan
{
    class SpitOutCmd : public frc2::CommandHelper<frc2::Command, SpitOutCmd>
    {
    public:
        SpitOutCmd(float speed, LoaderSubsystem* pLoaderSub);
        ~SpitOutCmd();

        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override { return m_IsFinished; }

    protected:
    private:
        float m_Speed;
        LoaderSubsystem* m_pLoaderSub;

        bool m_IsFinished = false;
    };
}