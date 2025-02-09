#include <VortexMath/RotationalStress.h>
#include <cmath>

namespace VortexMath {

StressResult RotationalStressCalculator::calculateIsotropicStress(
    double angular_velocity,
    double density,
    double young_modulus,
    double poisson_ratio,
    double r_inner,
    double r_outer)
{
    StressResult result;
    const double omega_sq = angular_velocity * angular_velocity;
    const double rho = density;
    
    // Calcul des contraintes radiales et tangentielles
    const double sigma_r = (rho * omega_sq * (3 + poisson_ratio)/8) * 
                          (r_outer*r_outer - r_inner*r_inner - (r_outer*r_inner*r_inner)/(r_outer*r_outer));
    
    const double sigma_t = (rho * omega_sq * (3 + poisson_ratio)/8) * 
                          (r_outer*r_outer + r_inner*r_inner - (r_outer*r_inner*r_inner)/(r_outer*r_outer) - (1 + 3*poisson_ratio)/(3 + poisson_ratio)*r_outer*r_outer);

    // Contrainte de von Mises équivalente
    result.von_mises_stress = std::sqrt(sigma_r*sigma_r + sigma_t*sigma_t - sigma_r*sigma_t);
    
    result.radial_stress = sigma_r;
    result.tangential_stress = sigma_t;
    
    return result;
}

// Implémentation composite à compléter...
} // namespace VortexMath