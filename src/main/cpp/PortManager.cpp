#include "PortManager.hpp"

namespace Kurgan
{
    PortManager::PortManager()
    {
        // NOTE: Currently does nothing
    }

    PortManager::~PortManager()
    {
        // NOTE: Currently does nothing
    }

    PortManager& PortManager::Instance()
    {
        static PortManager instance;
        return instance;
    }
}