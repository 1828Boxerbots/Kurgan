#include "Commands/ShootCmd.hpp"

namespace Kurgan
{
    ShootCmd::ShootCmd(float speed, ShooterSubsystem* pShooterSub)
    {
        m_pShooterSub = pShooterSub;
        m_Speed = speed;

        AddRequirements(m_pShooterSub);
    }

    ShootCmd::~ShootCmd()
    {
        // NOTE: Currently does nothing
    }

    void ShootCmd::Initialize()
    {
        // NOTE: Currently does nothing
    }

    void ShootCmd::Execute()
    {
        m_pShooterSub->Shoot(-m_Speed);
    }

    void ShootCmd::End(bool interrupted)
    {
        m_pShooterSub->Shoot(0.0);
    }
}