# 📄 Documentation du Projet – Système de Gestion de Robots

## 👤 Team-B2MS_CleanTec

## 🧠 1. Contexte et Objectif du Projet

L’objectif de ce projet est de mettre en pratique les principes de la programmation orientée objet (POO) en C++ à travers la conception d’un système de gestion de différents types de robots.

Ce système permet de :

- Créer plusieurs types de robots avec des comportements spécifiques.
- Simuler leurs mouvements.
- Implémenter des fonctionnalités génériques (héritage, polymorphisme, surcharge, encapsulation, etc.).
- Appliquer les bonnes pratiques de conception logicielle.

---

## ⚙️ 2. Architecture Générale du Projet

Le système est composé de **quatre classes principales** :

### a. `robot` (classe mère)
Classe générique représentant un robot.

**Attributs** :
- ID du robot
- Position 2D (x, y)
- État (ON / OFF)

**Fonctionnalités principales** :
- Constructeurs / destructeurs
- Méthodes de déplacement (virtuelles pures)
- Calcul de la distance à l’origine
- Méthodes d’affichage (nom, ID)

---

### b. `deliveryRobot` (classe fille)
Robot de livraison, dérivé de `robot`.

**Fonctionnalités spécifiques** :
- Livraison d'entités vers des zones prédéfinies (`zone1`, `zone2`)
- Gestion du nombre d'entités à livrer
- Déplacement automatique selon la zone

---

### c. `travellingRobot` (classe fille)
Robot de déplacement libre, dérivé de `robot`.

**Fonctionnalités spécifiques** :
- Se déplace dans une direction donnée (`avant`, `arrière`, `gauche`, `droite`)
- Direction modifiable dynamiquement

---

### d. `armRobot` (nouvelle classe fille)
Robot à un degré de liberté, dérivé de `robot`.

**Fonctionnalités spécifiques** :
- Ne se déplace pas dans l’espace
- Effectue une rotation de son bras dans une direction (`clockwise`, `anticlockwise`)
- Angle modifiable dynamiquement

---

## 🧱 3. Détails de l’Implémentation

### a. Fichiers du projet

| Fichier                         | Rôle                                                   |
|--------------------------------|---------------------------------------------------------|
| `robot.hpp / robot.cpp`        | Classe de base `robot`                                 |
| `deliveryRobot.hpp / .cpp`     | Classe `deliveryRobot`                                 |
| `travellingRobot.hpp / .cpp`   | Classe `travellingRobot`                               |
| `armRobot.hpp / .cpp`          | Classe `armRobot`                                      |
| `main.cpp`                     | Fichier principal de test                              |
| `vect2D.hpp`                   | Structure représentant une position (x, y)             |
| `enums.hpp`                    | Enumérations des états, zones, directions, rotations   |

---

### b. Concepts de POO utilisés

- ✅ **Encapsulation** : Attributs privés, getters/setters.
- ✅ **Héritage** : Les classes filles héritent de `robot`.
- ✅ **Polymorphisme** : Surcharge des méthodes virtuelles (`move()`, `getNameOfRobot()`).
- ✅ **Surcharge** : Surcharge des constructeurs et opérateurs d’affectation.

---

## 📐 4. Diagramme UML Simplifié


![WhatsApp Image 2025-06-12 à 17 12 55_9bec65ae](https://github.com/user-attachments/assets/9f2ddd81-a3cf-40c8-962b-950bc6706b68)

---


---

## 🧪 5. Tests Réalisés

- Création d’objets de chaque classe.
- Simulation des déplacements (zones ou direction).
- Rotation du bras pour `armRobot`.
- Vérification des distances depuis l’origine.
- Test du polymorphisme avec des pointeurs de type `robot*`.

---

## 💡 6. Résultats Obtenus

- Chaque type de robot fonctionne indépendamment.
- Les mouvements sont simulés correctement selon la logique métier.
- Le code est bien structuré, modulaire, réutilisable et extensible.
- Les bonnes pratiques C++ sont respectées (encapsulation, initialisation, gestion mémoire).

---

## 🧩 7. Limites et Perspectives

### Limitations actuelles :

- Déplacements simulés uniquement (pas d'affichage graphique).
- Système non intégré à un environnement réel ou embarqué.

### Améliorations possibles :

- Ajout d’une interface graphique (SFML, Qt...).
- Enregistrement des logs de déplacement.
- Intégration à des cartes ou gestion d’obstacles.
- Extension à d’autres types de robots (volants, marins, collaboratifs...).

---

## ✅ 8. Conclusion

Ce projet nous a permis de :

- Appliquer les concepts fondamentaux de la programmation orientée objet.
- Comprendre l’importance de la conception logicielle modulaire et évolutive.
- Développer un système complet et structuré en C++.

Il constitue une base solide pour des projets plus complexes, notamment dans les domaines de la robotique embarquée ou de la simulation.

---

## 📁 9. Annexes

### a. Contenu du projet :
- `robot.hpp / robot.cpp`
- `deliveryRobot.hpp / deliveryRobot.cpp`
- `travellingRobot.hpp / travellingRobot.cpp`
- `armRobot.hpp / armRobot.cpp`
- `main.cpp` (facultatif pour la démonstration)
- `enums.hpp`
- `vect2D.hpp`

