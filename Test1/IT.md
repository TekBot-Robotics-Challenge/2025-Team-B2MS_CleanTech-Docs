# 📄 Documentation du Projet – Système de Gestion de Robots

## 👤 Team-B2MS_CleanTec

## 🧠 1. Contexte et Objectif du Projet

L’objectif de ce projet est de mettre en pratique les principes de la **programmation orientée objet (POO)** en **C++** à travers la conception d’un système de gestion de différents types de robots.

Ce système permet de :

- Créer plusieurs types de robots avec des comportements spécifiques.
- Simuler leurs mouvements.
- Implémenter des fonctionnalités génériques (héritage, polymorphisme, surcharge, encapsulation, etc.).
- Appliquer les bonnes pratiques de conception logicielle.

---

## ⚙️ 2. Architecture Générale du Projet

Le système est composé de trois classes principales :

### a. `robot` (classe mère)

Classe générique représentant un robot.

**Attributs communs :**

- ID du robot
- Position 2D (x, y)
- État (ON / OFF)

**Fonctionnalités :**

- Constructeurs / destructeurs
- Méthodes de déplacement (virtuelles)
- Calcul de la distance à l’origine
- Méthodes d’affichage

### b. `deliveryRobot` (classe fille)

Robot de livraison dérivé de `robot`.

**Fonctionnalités spécifiques :**

- Livrer des entités vers des zones prédéfinies (`zone1`, `zone2`)
- Gère le nombre d'entités à livrer
- Implémente un déplacement basé sur la zone

### c. `travellingRobot` (classe fille)

Robot de déplacement libre dérivé de `robot`.

**Fonctionnalités spécifiques :**

- Se déplace dans une direction donnée (`avant`, `arrière`, `gauche`, `droite`)
- Direction modifiable dynamiquement

---

## 🧱 3. Détails de l’Implémentation

### a. Fichiers du projet

- `robot.hpp` / `robot.cpp` : classe de base `robot`
- `deliveryRobot.hpp` / `deliveryRobot.cpp` : classe `deliveryRobot`
- `travellingRobot.hpp` / `travellingRobot.cpp` : classe `travellingRobot`
- `main.cpp` : fichier de test principal
- `vect2D.hpp` : structure représentant un point 2D
- `enums.hpp` : définitions des énumérations (zone, state, direction)

### b. Concepts de POO utilisés

- **Encapsulation** : Attributs privés, accès par getters/setters
- **Héritage** : Les classes `deliveryRobot` et `travellingRobot` héritent de `robot`
- **Polymorphisme** : Méthodes virtuelles (`move`, `getNameOfRobot`)
- **Surcharge** : Constructeurs et opérateurs d’affectation

---

## 📐 4. Diagramme UML Simplifié
![WhatsApp Image 2025-06-12 à 17 12 55_9bec65ae](https://github.com/user-attachments/assets/9f2ddd81-a3cf-40c8-962b-950bc6706b68)

---

## 🧪 5. Tests Réalisés

- Création d’objets de chaque classe
- Simulation des déplacements (changement de zone / direction)
- Vérification des distances depuis l’origine
- Test du polymorphisme avec des pointeurs de type `robot*`

---

## 💡 6. Résultats Obtenus

- Chaque type de robot fonctionne indépendamment
- Les mouvements sont simulés correctement selon la logique métier
- Le code est bien structuré, modulaire, réutilisable et extensible
- Les bonnes pratiques C++ sont respectées (gestion mémoire, encapsulation, etc.)

---

## 🧩 7. Limites et Perspectives

### Limitations :

- Les déplacements sont simulés mais pas visualisés graphiquement
- Le système ne gère pas d’environnement réel ou physique

### Améliorations possibles :

- Ajout d’une interface graphique (SFML, Qt)
- Implémentation de logs ou de fichiers de tracking
- Extension à d’autres types de robots (volants, marins, etc.)
- Gestion d’obstacles, de cartes ou de missions

---

## ✅ 8. Conclusion

Ce projet nous a permis de :

- Appliquer les concepts fondamentaux de la programmation orientée objet
- Comprendre l’importance de la conception logicielle modulaire
- Développer un système cohérent, évolutif et structuré en C++

Il constitue une base solide pour des projets plus complexes, comme des systèmes embarqués dans des robots réels ou des simulations d’intelligence artificielle mobile.

---

## 📁 9. Annexes

### Contenu du projet :

- `robot.hpp` / `robot.cpp`
- `deliveryRobot.hpp` / `deliveryRobot.cpp`
- `travellingRobot.hpp` / `travellingRobot.cpp`
- `main.cpp` (facultatif pour la démonstration)
- `enums.hpp`, `vect2D.hpp`

