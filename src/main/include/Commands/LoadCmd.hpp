#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "Subsystems/LoaderSubsystem.hpp"

namespace Kurgan
{
    class LoadCmd : public frc2::CommandHelper<frc2::Command, LoadCmd>
    {
    public:
        LoadCmd(float speed, LoaderSubsystem* pLoaderSub);
        ~LoadCmd();

        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override { return m_IsFinished; }

    protected:
    private:
        LoaderSubsystem* m_pLoaderSub;
        float m_Speed;

        bool m_IsFinished = false;
    };
}