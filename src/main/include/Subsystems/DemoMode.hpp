#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/DigitalInput.h>

#include "PortManager.hpp"

namespace Kurgan
{
    class DemoMode : public frc2::SubsystemBase
    {
    public:
        DemoMode();
        ~DemoMode();

        void Init();

        void Periodic() override;

        /// @brief Gets the current state of the demo mode switch.
        /// @return True means demo mode enabled, False otherwise.
        static bool GetDemoMode() { return s_DemoModeEnabled; }

    protected:
    private:
        
        frc::DigitalInput m_DemoSwitch { (int)PortManager::Instance().GetDIOPort("DemoModeSwitch") };
        static bool s_DemoModeEnabled;
    };
}