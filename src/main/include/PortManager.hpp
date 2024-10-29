#pragma once

#include <string>
#include <map>

namespace Kurgan
{
    class PortManager
    {
    public:
        // Enforce singleton access
        PortManager(const PortManager& obj) = delete;
        PortManager& operator=(const PortManager& obj) = delete;

        ~PortManager();

        static PortManager& Instance();

        unsigned int GetCanID(std::string deviceName) { return m_CANPorts[deviceName]; }

        unsigned int GetDIOPort(std::string port) { return m_DIOPorts[port]; }

    protected:
    private:
        PortManager();

        std::map<std::string, unsigned int> m_CANPorts {
            {"DriveMotor0", 0},
            {"DriveMotor1", 1},
            {"DriveMotor2", 2},
            {"DriveMotor3", 3},
            {"ShooterMotor1", 4},
            {"ShooterMotor2", 5},
            {"ShooterMotor3", 6},
            {"ShooterMotor4", 7},
            {"LoaderMotor", 8}
        };

        std::map<std::string, unsigned int> m_DIOPorts {
            {"LoaderPhotogate", 1},
            {"DemoModeSwitch", 0}
        };
    };
}