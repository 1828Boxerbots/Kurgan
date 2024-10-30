#include "Commands/DriveCmd.hpp"

namespace Kurgan
{
    DriveCmd::DriveCmd(DriveSubsystem* pDriveSub, frc::XboxController* pController)
    {
        m_pDriveSub = pDriveSub;
        m_pController = pController;

        AddRequirements(m_pDriveSub);
    }

    DriveCmd::~DriveCmd()
    {
        // NOTE: Currently does nothing
    }

    void DriveCmd::Initialize()
    {
        // NOTE: Currently does nothing
    }

    void DriveCmd::Execute()
    {
        float deadZone = 0.05;

        double leftY = m_pController->GetLeftY();
        double rightY = m_pController->GetRightY();

        // Check deadzones
        if (leftY < deadZone && leftY > -deadZone)
        {
            leftY = 0.0;
        }

        if (rightY < deadZone && rightY > -deadZone)
        {
            rightY = 0.0;
        }

        m_pDriveSub->Drive(leftY, rightY);
    }

    void DriveCmd::End(bool interrupted)
    {
        // NOTE: Currently does nothing
    }
}