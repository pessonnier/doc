#pragma once

namespace VortexMath {

struct Material {
    double density;        // kg/m³
    double young_modulus;  // Pa
    double poisson_ratio;
    double yield_strength; // Pa
};

class MaterialLibrary {
public:
    static Material getMaterial(const std::string& name);
};

} // namespace VortexMath