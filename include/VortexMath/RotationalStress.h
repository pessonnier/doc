#pragma once
#include <Eigen/Dense>

namespace VortexMath {

struct StressResult {
    double radial_stress;
    double tangential_stress;
    double von_mises_stress;
};

class RotationalStressCalculator {
public:
    // Calcul des contraintes pour un matériau isotrope
    static StressResult calculateIsotropicStress(
        double angular_velocity,    // [rad/s]
        double density,             // [kg/m³]
        double young_modulus,       // [Pa]
        double poisson_ratio,
        double inner_radius,        // [m]
        double outer_radius         // [m]
    );

    // Version pour matériaux composites (couches)
    static StressResult calculateCompositeStress(
        const Eigen::MatrixXd& material_layers, // [densité, E, ν, épaisseur]
        double angular_velocity
    );
};

} // namespace VortexMath