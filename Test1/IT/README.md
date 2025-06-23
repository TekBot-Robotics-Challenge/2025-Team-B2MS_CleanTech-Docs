# Test1Robot – Tekbot Robotics Challenge 2024

## 🚀 Description

Ce projet est une démonstration de programmation orientée objet (POO) en C++ réalisée dans le cadre du **Tekbot Robotics Challenge 2024**.  
Il met en œuvre les concepts fondamentaux de la POO comme :

- L’encapsulation
- L’héritage
- Le polymorphisme

Le but est de modéliser une hiérarchie de robots avec des comportements spécifiques via une méthode polymorphe `move()`.

## 🧠 Architecture

Le projet comprend :

- Une **classe de base `Robot`** contenant des attributs communs (nom, couleur, taille, vitesse, précision).
- Deux **sous-classes** dérivées :
  - `MobileRobot`
  - `ArmRobotic`
- Une **méthode virtuelle `move()`** redéfinie dans chaque sous-classe.
- Une démonstration de **polymorphisme** dans la fonction `main()`.
