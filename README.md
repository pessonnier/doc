# VortexMath 🌀⚙️

**Librairie open source de calcul des contraintes dans les matériaux en rotation sous haute tension**

[![GitHub Actions](https://github.com/votre-org/VortexMath/actions/workflows/build.yml/badge.svg)](https://github.com/votre-org/VortexMath/actions)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Version](https://img.shields.io/badge/version-0.1.0-orange)](https://semver.org)

Une solution performante pour l'analyse des contraintes mécaniques dans les systèmes rotatifs complexes.

## 🚀 Fonctionnalités

- Calcul des contraintes radiales, tangentielles et de von Mises
- Support des matériaux isotropes et composites
- Modélisation multi-couches
- Optimisations CPU/GPU via CUDA/OpenCL (en développement)
- Interface simple avec gestion des unités automatique
- Intégration avec les principales bibliothèques scientifiques (Eigen, Boost)

## 📦 Installation

### Prérequis
- CMake 3.15+
- Compilateur C++17 (GCC 10+, Clang 12+, MSVC 2019+)
- Eigen3 (fourni en submodule)

### Étapes d'installation
```bash
git clone --recursive https://github.com/pessonnier/doc.git
cd VortexMath
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release
```

### Intégration dans votre projet
```cmake
add_subdirectory(VortexMath)
target_link_libraries(votre_projet PRIVATE VortexMathCore)
```

## 💻 Utilisation de base

```cpp
#include <VortexMath/RotationalStress.h>

int main() {
    // Configuration d'un rotor en acier
    auto result = VortexMath::RotationalStressCalculator::calculateIsotropicStress(
        1000.0,   // Vitesse angulaire (rad/s)
        7850.0,   // Densité de l'acier (kg/m³)
        200e9,    // Module d'Young (Pa)
        0.3,      // Coefficient de Poisson
        0.05,     // Rayon intérieur (m)
        0.15      // Rayon extérieur (m)
    );

    std::cout << "Contrainte radiale: " << result.radial_stress << " Pa\n";
    std::cout << "Contrainte tangentielle: " << result.tangential_stress << " Pa\n";
    std::cout << "Von Mises équivalent: " << result.von_mises_stress << " Pa\n";
    
    return 0;
}
```

## 📊 Résultats Validés

![Graphique de validation](docs/validation_graph.png)  
*Comparaison avec les résultats expérimentaux (AISI 4340 à 15,000 RPM)*

## 🤝 Contribution

Nous accueillons les contributions ! Voici comment participer :

1. Forkez le dépôt
2. Créez votre branche (`git checkout -b feature/ma-nouvelle-fonction`)
3. Committez vos changements
4. Pushez vers la branche
5. Ouvrez une Pull Request

**Domaines de contribution recherchés :**
- Développement C++/CUDA
- Intégration d'algorithmes avancés
- Optimisation des performances
- Développement de bindings Python/Julia
- Documentation technique

Consultez notre [guide de contribution](CONTRIBUTING.md) et les [issues ouvertes](https://github.com/pessonnier/doc/issues).

## 📜 Licence

Ce projet est sous licence MIT - voir le fichier [LICENSE](LICENSE) pour plus de détails.

## 📍 Roadmap

Voir le [ROADMAP.md](ROADMAP.md) pour les plans de développement à venir.

## 📚 Documentation

La documentation technique sera disponible sur [https://pessonnier.github.io/doc/](https://pessonnier.github.io/doc/) mais elle est loin d´être rédigée.

## 👥 Auteurs

...

## 🙌 Remerciements

- L'équipe d'Eigen pour leur bibliothèque exceptionnelle
- La communauté C++ pour les outils open source
- Tous nos testeurs et contributeurs bénévoles

---

**Déjà utilisé par :**  
...
