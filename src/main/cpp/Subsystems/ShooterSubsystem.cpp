#include "Subsystems/ShooterSubsystem.hpp"

#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.hpp"
#include "Subsystems/DemoMode.hpp"

namespace Kurgan
{
    ShooterSubsystem::ShooterSubsystem()
    {
        SetName("ShooterSubsystem");
    }

    ShooterSubsystem::~ShooterSubsystem()
    {
        // NOTE: Currently does nothing
    }

    void ShooterSubsystem::Init()
    {
        // Configure left side
        m_ShooterMotor1.SetInverted(true);
        m_ShooterMotor2.Follow(m_ShooterMotor1);

        // Configure right side
        m_ShooterMotor3.SetInverted(false);
        m_ShooterMotor4.Follow(m_ShooterMotor3);

        m_ShooterMotor1.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0.0);
        m_ShooterMotor3.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0.0);
    }

    void ShooterSubsystem::Periodic()
    {
        // double shooter1Temp = m_ShooterMotor1.GetTemperature();
        // double shooter2Temp = m_ShooterMotor2.GetTemperature();
        // double shooter3Temp = m_ShooterMotor3.GetTemperature();
        // double shooter4Temp = m_ShooterMotor4.GetTemperature();

        // // ================================================================
        // //                      BEGIN SAFETY CRITICAL CODE
        // // ================================================================
        // // Safety off
        // if (m_SafetyDisabled)
        // {
        //     if (shooter1Temp > MOTOR_CUTOFF_TEMP || shooter2Temp > MOTOR_CUTOFF_TEMP || shooter3Temp > MOTOR_CUTOFF_TEMP || shooter4Temp > MOTOR_CUTOFF_TEMP)
        //     {
        //         m_SafetyDisabled = false;
        //     }
        // }
        // // Safety on
        // else
        // {
        //     const double disengageThreshold = MOTOR_CUTOFF_TEMP - 5;

        //     if (shooter1Temp <= disengageThreshold && shooter2Temp <= disengageThreshold && shooter3Temp <= disengageThreshold && shooter4Temp <= disengageThreshold)
        //     {
        //         m_SafetyDisabled = true;
        //     }
        // }
        // // ================================================================
        // //                      END SAFETY CRITICAL CODE
        // // ================================================================

        // frc::SmartDashboard::PutString("ShooterMotoerTempHeader", "Shooter Motor Temp Readouts (20 ms):");
        // frc::SmartDashboard::PutNumber("Shooter1 Temp(C)", shooter1Temp);
        // frc::SmartDashboard::PutNumber("Shooter2 Temp(C)", shooter2Temp);
        // frc::SmartDashboard::PutNumber("Shooter3 Temp(C)", shooter3Temp);
        // frc::SmartDashboard::PutNumber("Shooter4 Temp(C)", shooter4Temp);
        // frc::SmartDashboard::PutBoolean("Shooter Safety Engaged", !m_SafetyDisabled);
    }

    void ShooterSubsystem::Shoot(float speed)
    {
        // ================================================================
        //                      BEGIN SAFETY CRITICAL CODE
        // ================================================================
        if (m_SafetyDisabled)
        {
            if (DemoMode::GetDemoMode())
            {
                m_ShooterMotor1.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, -speed * SHOOTER_REDUCTION);
                m_ShooterMotor3.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, -speed * SHOOTER_REDUCTION);
            }
            else
            {
                m_ShooterMotor1.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, -speed);
                
                const float scaleFactor = 0.8;
                m_ShooterMotor3.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, -speed * scaleFactor);
            }
        }
        // ================================================================
        //                      END SAFETY CRITICAL CODE
        // ================================================================
    }
}