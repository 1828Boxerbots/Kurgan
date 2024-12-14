#pragma once

namespace Kurgan
{
    // Demo Mode Reduction factors (NOTE: 1.0 means no reduction, and 0.8 would be a 20% reduction)
    inline constexpr float DRIVE_REDUCTION = 0.6;
    inline constexpr float SHOOTER_REDUCTION = 0.4;
    inline constexpr float LOADER_REDUCTION = 1.0;

    // ========================================================================
    //                    BEGIN SAFETY CRITICAL CODE
    // ========================================================================
    inline constexpr double MOTOR_CUTOFF_TEMP = 50.0;   // Degrees Celsius
    // ========================================================================
    //                     END SAFETY CRITICAL CODE
    // ========================================================================
}