#include "Subsystems/LoaderSubsystem.hpp"

#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.hpp"
#include "Subsystems/DemoMode.hpp"

namespace Kurgan
{
    // Define statics
    frc::DigitalInput LoaderSubsystem::s_PhotoGate = frc::DigitalInput((int)PortManager::Instance().GetDIOPort("LoaderPhotogate"));

    LoaderSubsystem::LoaderSubsystem()
    {
        SetName("LoaderSubsystem");
    }

    LoaderSubsystem::~LoaderSubsystem()
    {
        // NOTE: Currenlty does nothing
    }

    void LoaderSubsystem::Init()
    {
        // Set motor to known state
        m_Motor.SetInverted(true);
        m_Motor.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0.0);
    }

    void LoaderSubsystem::Periodic()
    {  
        double motorTemp = m_Motor.GetTemperature();

        // ================================================================
        //                      BEGIN SAFETY CRITICAL CODE
        // ================================================================
        // Safety off
        if (m_SafetyDisabled)
        {
            if (motorTemp > MOTOR_CUTOFF_TEMP)
            {
                m_SafetyDisabled = false;
            }
        }
        // Safety on
        else
        {
            const double disengageThreshold = MOTOR_CUTOFF_TEMP - 5;

            if (motorTemp <= disengageThreshold)
            {
                m_SafetyDisabled = true;
            }
        }
        // ================================================================
        //                      END SAFETY CRITICAL CODE
        // ================================================================

        frc::SmartDashboard::PutString("LoaderMotorTempHeader", "Loader Motor Temp Readouts (20 ms):");
        frc::SmartDashboard::PutNumber("Loader Temp(C)", motorTemp);
        frc::SmartDashboard::PutBoolean("Loader Safety Engaged", !m_SafetyDisabled);
    }

    void LoaderSubsystem::Load(float speed)
    {
        // ================================================================
        //                      BEGIN SAFETY CRITICAL CODE
        // ================================================================
        if (m_SafetyDisabled)
        {
            if (DemoMode::GetDemoMode())
            {
                m_Motor.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, speed * LOADER_REDUCTION);
            }
            else
            {
                m_Motor.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, speed);
            }
        }
        // ================================================================
        //                      END SAFETY CRITICAL CODE
        // ================================================================
    }

    bool LoaderSubsystem::GetPhotoGateState()
    {
        return s_PhotoGate.Get();
    }
}