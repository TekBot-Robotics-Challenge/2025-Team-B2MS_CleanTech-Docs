# Projet Gyroscope et Accéléromètre MPU6050

## Introduction

Ce projet utilise un module **MPU6050** (gyroscope + accéléromètre) pour détecter l’orientation et afficher la direction (haut, bas, gauche, droite) ainsi que l'accélération sur un écran **LCD I2C 16x2**.  
Il permet de mieux comprendre comment lire et interpréter les données d’un **capteur inertiel** en temps réel, avec un affichage simple et pédagogique.

---

## Choix du capteur : MPU6050

Le **MPU6050** est un capteur IMU (Inertial Measurement Unit) 6 axes qui combine :
- Un **accéléromètre 3 axes**
- Un **gyroscope 3 axes**

### Caractéristiques principales :
- Interface I2C (adresse par défaut : `0x68`)
- Plage de mesure accéléromètre : ±2g, ±4g, ±8g, ±16g
- Plage de mesure gyroscope : ±250, ±500, ±1000, ±2000 °/s
- Tension d’alimentation : 3.3V – 5V
- Communication stable et rapide avec microcontrôleur

### Datasheet :
> 🔗 [Consulter la datasheet du MPU6050 (PDF)](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf)

---

## Liste des composants

- Arduino Uno  
- Module IMU MPU6050  
- Écran LCD 16x2 avec interface I2C  
- Câbles de connexion (dupont mâle-mâle)  
- Breadboard  
- Alimentation 5V  

---

## Schéma électronique

<img width="408" alt="image" src="https://github.com/user-attachments/assets/5713927e-edbf-491a-930d-1074d48480c9" />

*Le schéma montre les connexions principales :*
- SDA (LCD & MPU6050) → A4 (Arduino)  
- SCL (LCD & MPU6050) → A5 (Arduino)  
- VCC (LCD & MPU6050) → 5V (Arduino)  
- GND (LCD & MPU6050) → GND (Arduino)  

---

## Explication du code

Le code (sketch.ino) réalise les étapes suivantes :

Initialise la communication I2C avec le capteur MPU6050 et l’écran LCD.

Configure les plages de mesure du gyroscope et de l’accéléromètre.

Lit les données d’accélération sur les 3 axes (X, Y, Z).

Calcule les angles d’inclinaison (pitch et roll).

Détecte le mouvement selon l’orientation : droite, gauche, avant, arrière ou stable.

Affiche les informations sur l’écran LCD 16x2.

Affiche aussi les données dans le moniteur série (pour debug). 

---

## Photos ou captures d’écran

**Start**  
![Start](https://github.com/user-attachments/assets/9d2e749a-d353-4479-93dd-5cab8e7c77d6)

**Working**  
![Working1](https://github.com/user-attachments/assets/73b5fa34-8397-4766-9c18-858dda9c1cdb)  
![Working2](https://github.com/user-attachments/assets/cc679bfa-6355-4a55-bc95-7ef6c44f8b9a)  
![Working3](https://github.com/user-attachments/assets/048a04b7-573b-472b-a7b6-d8bf74f95b42)

---

## Vidéos de démonstration

- [🎬 Premier essai](https://youtube.com/shorts/durMujPbixI?si=PIUfneER4diqM4VX)  
- [🎬 Essai final réussi](https://youtube.com/shorts/d7HRCWKiFtE?si=rqMBNyRJBchXtX6A)  
- [🎬 Accélération en mouvement](https://youtube.com/shorts/WYKy4-q5Adw?si=LnA5E9QnaUxR04ia)  

---

##  Comment utiliser le projet

### 1. Installation matérielle
- Connecter le module MPU6050 sur SDA/SCL (A4/A5) de l’Arduino.  
- Connecter l’écran LCD I2C sur les mêmes lignes.  
- Alimenter le tout avec le 5V et GND de l’Arduino.  

### 2. Installation logicielle
- Installer l’IDE Arduino.  
- Ajouter les bibliothèques :  
  - `Wire.h`  
  - `LiquidCrystal_I2C.h`  
  - `MPU6050.h` ou `Adafruit_MPU6050.h` (selon usage)  
- Ouvrir `sketch.ino`.

### 3. Téléversement
- Sélectionner la carte Arduino Uno.  
- Connecter l’Arduino en USB.  
- Compiler et téléverser le programme.

### 4. Utilisation
- Une fois allumé, l’écran affiche les directions en temps réel.  
- En bougeant le capteur, observer l’évolution des valeurs.

---

## Remarques

- Pour une lecture plus fluide, on peut intégrer un **filtre complémentaire** ou un **filtre de Kalman**.  
- Ce projet constitue une base idéale pour des systèmes comme des manettes, des robots équilibrés, ou de la stabilisation.

---

**Fait avec ❤️ par notre équipe.**
