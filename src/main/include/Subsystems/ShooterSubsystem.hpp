#pragma once

#include <frc2/command/SubsystemBase.h>

#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>

#include "PortManager.hpp"

namespace Kurgan
{
    class ShooterSubsystem : public frc2::SubsystemBase
    {
    public:
        ShooterSubsystem();
        ~ShooterSubsystem();

        void Init();

        void Periodic() override;

        void Shoot(float speed);

    protected:
    private:
        ctre::phoenix::motorcontrol::can::VictorSPX m_ShooterMotor1 { (int)PortManager::Instance().GetCanID("ShooterMotor1") };
        ctre::phoenix::motorcontrol::can::VictorSPX m_ShooterMotor2 { (int)PortManager::Instance().GetCanID("ShooterMotor2") };
        ctre::phoenix::motorcontrol::can::VictorSPX m_ShooterMotor3 { (int)PortManager::Instance().GetCanID("ShooterMotor3") };
        ctre::phoenix::motorcontrol::can::VictorSPX m_ShooterMotor4 { (int)PortManager::Instance().GetCanID("ShooterMotor4") };
    
        // ================================================================
        //                      BEGIN SAFETY CRITICAL CODE
        // ================================================================
        bool m_SafetyDisabled = true;
        // ================================================================
        //                       END SAFETY CRITICAL CODE
        // ================================================================
    };
}