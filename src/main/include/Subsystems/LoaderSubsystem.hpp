#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DigitalInput.h>

#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>

#include "PortManager.hpp"

namespace Kurgan
{
    class LoaderSubsystem : public frc2::SubsystemBase
    {
        public:

            LoaderSubsystem();
            ~LoaderSubsystem();

            void Init();

            void Periodic() override;

            void Load(float speed);

            /// @brief Retreive the current state of the loader photogate.
            /// @return True if the photogate is NOT tripped, false otherwise
            static bool GetPhotoGateState();

        protected:
        private:

            // Motor Controller(s)
            ctre::phoenix::motorcontrol::can::VictorSPX m_Motor { (int)PortManager::Instance().GetCanID("LoaderMotor") };

            // DIO(s)
            static frc::DigitalInput m_PhotoGate;

            // ================================================================
            //                      BEGIN SAFETY CRITICAL CODE
            // ================================================================
            bool m_SafetyDisabled = true;
            // ================================================================
            //                       END SAFETY CRITICAL CODE
            // ================================================================
    };
}