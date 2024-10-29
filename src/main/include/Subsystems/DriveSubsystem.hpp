#pragma once

#include <frc2/command/SubsystemBase.h>

#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>

#include "../PortManager.hpp"

namespace Kurgan
{
    class DriveSubsystem : public frc2::SubsystemBase
    {
        public:

            DriveSubsystem();
            ~DriveSubsystem();

            void Init();

            void Periodic() override;

            /// @brief Directly sets the corresponding sides of the drive train to the desired speeds.
            /// @param left The left speed (Should be -1.0 to 1.0)
            /// @param right The right speed (Should be -1.0 to 1.0)
            void Drive(float left, float right);

        protected:
        private:
            
            // Left Drive Train
            ctre::phoenix::motorcontrol::can::VictorSPX m_DriveMotor0 { (int)PortManager::Instance().GetCanID("DriveMotor0") };
            ctre::phoenix::motorcontrol::can::VictorSPX m_DriveMotor1 { (int)PortManager::Instance().GetCanID("DriveMotor1") };

            // Right Drive Train
            ctre::phoenix::motorcontrol::can::VictorSPX m_DriveMotor2 { (int)PortManager::Instance().GetCanID("DriveMotor2") };
            ctre::phoenix::motorcontrol::can::VictorSPX m_DriveMotor3 { (int)PortManager::Instance().GetCanID("DriveMotor3") };
    };
}