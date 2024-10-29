#include "Subsystems/DriveSubsystem.hpp"

namespace Kurgan
{
    DriveSubsystem::DriveSubsystem()
    {
        // NOTE: Currently does nothing
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
    }

    void DriveSubsystem::Periodic()
    {
        // NOTE: Currently does nothing
    }

    void DriveSubsystem::Drive(float left, float right)
    {
        m_DriveMotor0.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, left);
        m_DriveMotor2.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, left);
    }
}