#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <VortexMath/RotationalStress.h>

TEST_CASE("Basic stress calculation", "[core]") {
    auto result = VortexMath::RotationalStressCalculator::calculateIsotropicStress(
        1000.0,  // 1000 rad/s (~9550 RPM)
        7850.0,  // Acier
        200e9,
        0.3,
        0.05,    // 5 cm
        0.15     // 15 cm
    );
    
    REQUIRE(result.radial_stress == Approx(1.23e6).margin(0.1e6));
    REQUIRE(result.von_mises_stress > result.radial_stress);
}