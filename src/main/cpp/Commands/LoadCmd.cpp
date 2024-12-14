#include "Commands/LoadCmd.hpp"

namespace Kurgan
{
    LoadCmd::LoadCmd(float speed, LoaderSubsystem* pLoaderSub, bool overridePhotoGate)
    {
        m_pLoaderSub = pLoaderSub;
        m_Speed = speed;
        m_Override = overridePhotoGate;

        AddRequirements(m_pLoaderSub);
    }

    LoadCmd::~LoadCmd()
    {
        // NOTE: Currently does nothing
    }

    void LoadCmd::Initialize()
    {
        // NOTE: Currently does nothing
    }

    void LoadCmd::Execute()
    {
        if (m_Override)
        {
            m_pLoaderSub->Load(m_Speed);
        }
        else
        {
            if (m_pLoaderSub->GetPhotoGateState())
            {
                m_IsFinished = true;
            }
    
            m_pLoaderSub->Load(m_Speed);
        }
    }

    void LoadCmd::End(bool interrupted)
    {
        m_pLoaderSub->Load(0.0);
        m_IsFinished = false;
    }
}