#include "Subsystems/DriveSubsystem.hpp"

#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.hpp"

namespace Kurgan
{
    DriveSubsystem::DriveSubsystem()
    {
        // NOTE: Currently does nothing
        SetName("DriveSubsystem");
    }

    DriveSubsystem::~DriveSubsystem()
    {
        // NOTE: Currently does nothing
    }

    void DriveSubsystem::Init()
    {
        // Configure left side
        m_DriveMotor0.SetInverted(true);
        m_DriveMotor1.Follow(m_DriveMotor0);

        // Configure right side
        m_DriveMotor2.SetInverted(false);
        m_DriveMotor3.Follow(m_DriveMotor2);

        m_DriveMotor0.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0.0);
        m_DriveMotor2.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0.0);
    }

    void DriveSubsystem::Periodic()
    {
        double drive0Temp = m_DriveMotor0.GetTemperature();
        double drive1Temp = m_DriveMotor1.GetTemperature();
        double drive2Temp = m_DriveMotor2.GetTemperature();
        double drive3Temp = m_DriveMotor3.GetTemperature();

        // ================================================================
        //                      BEGIN SAFETY CRITICAL CODE
        // ================================================================
        // Safety off
        if (m_SafetyDisabled)
        {
            if (drive0Temp > MOTOR_CUTOFF_TEMP || drive1Temp > MOTOR_CUTOFF_TEMP || drive2Temp > MOTOR_CUTOFF_TEMP || drive3Temp > MOTOR_CUTOFF_TEMP)
            {
                m_SafetyDisabled = false;
            }
        }
        // Safety on
        else
        {
            const double disengageThreshold = MOTOR_CUTOFF_TEMP - 5;

            if (drive0Temp <= disengageThreshold && drive1Temp <= disengageThreshold && drive2Temp <= disengageThreshold && drive3Temp <= disengageThreshold)
            {
                m_SafetyDisabled = true;
            }
        }
        // ================================================================
        //                      END SAFETY CRITICAL CODE
        // ================================================================

        frc::SmartDashboard::PutString("MotorTempHeader", "Drive Motor Temp Readouts (20 ms):");
        frc::SmartDashboard::PutNumber("Drive0 Temp(C)", drive0Temp);
        frc::SmartDashboard::PutNumber("Drive1 Temp(C)", drive1Temp);
        frc::SmartDashboard::PutNumber("Drive2 Temp(C)", drive2Temp);
        frc::SmartDashboard::PutNumber("Drive3 Temp(C)", drive3Temp);
        frc::SmartDashboard::PutBoolean("Drive Safety Engaged", !m_SafetyDisabled);
    }

    void DriveSubsystem::Drive(float left, float right)
    {
        // ================================================================
        //                      BEGIN SAFETY CRITICAL CODE
        // ================================================================
        if (m_SafetyDisabled)
        {
            m_DriveMotor0.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, left);
            
            const float scaleFactor = 0.8;
            m_DriveMotor2.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, right * scaleFactor);
        }
        // ================================================================
        //                      END SAFETY CRITICAL CODE
        // ================================================================
    }
}