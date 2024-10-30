#include "Commands/SpitOutCmd.hpp"

namespace Kurgan
{
    SpitOutCmd::SpitOutCmd(float speed, LoaderSubsystem* pLoaderSub)
    {
        m_Speed = speed;
        m_pLoaderSub = pLoaderSub;

        AddRequirements(m_pLoaderSub);
    }

    SpitOutCmd::~SpitOutCmd()
    {
        // NOTE: Currently does nothing
    }

    void SpitOutCmd::Initialize()
    {
        // NOTE: Currently does nothing
    }

    void SpitOutCmd::Execute()
    {
        m_pLoaderSub->Load(-m_Speed);
    }

    void SpitOutCmd::End(bool interrupted)
    {
        m_pLoaderSub->Load(0.0);
    }
}