**TEST3**

# 🛠️ **Test Mécanique – Niveau Avancé **

## 🧪 TRC2K25 – Évaluation CAO SolidWorks

### 📋 Objectif

Le test de niveau avancé aura pour objectif l’évaluation des participants à la 
conception d’une pièce complexe et d’une solution mécanique complète afin de résoudre 
un problème concret. Il met en avant l’utilisation des compétences acquises lors des tests 
précédents dans le design d’une solution mécanique à assembler. L’objectif de ce test est 
d’évaluer le rapport des participants à la complexité et leur créativité mais aussi leurs 
capacités à concevoir une solution fonctionnele en gérant correctement les erreurs. 

**Nous devons, dans ce 3ème test, Modéliser des pièces complexes en respectant les consignes géométriques, les matériaux et les unités, puis déterminer leurs **masses****.

### 📐 Contraintes :  
* **Système d’unités** : MMGS (millimètre, gramme, seconde)  
* **Précision** : 2 décimales  
* **Tous les trous sont débouchants sauf indication contraire**  
* **Matériau** : 1060 Aloy Aluminium ; Densité : 2700 Kg/m^3.  
* **Rayon des 12 filets = 10 mm sauf indication contraire.**    
  
# **Conception des pièces**  
### 🧩 Pièces à réaliser :  
<img width="250" alt="{3D7918D9-A10B-4301-B96D-C81EF5C70CE8}" src="https://github.com/user-attachments/assets/04459faa-0962-4558-af02-6363f1ad983e" />


## 🔩 Pièce 1A  

*a) A = 193 mm ; B = 88 mm ; W = B/2 mm ; X = A/4 mm ; Y = B+5.5 mm ; Z = B+15 
mm ;*
 ### Étape 1 : Définition des équations globales  
On commence par définir des équations en tant que variables globales nommées **A**, **B**, **w**, **X**, **y**, et **z**, afin de paramétrer la conception de la pièce.    
<img width="597" alt="1" src="https://github.com/user-attachments/assets/7b56e27e-987e-4928-8d0c-de5b50e5a4ef" />  

 ### Étape 2 : Création de l’esquisse principale   
Ensuite, on dessine l’esquisse de base en se référant aux dimensions définies par les variables globales précédemment créées.  
<img width="559" alt="2" src="https://github.com/user-attachments/assets/de34f3c1-a1ba-4368-a528-9d5232b7f82e" />  

 ### Étape 3 : Création de la pièce en commençant par le bloc gauche    
Nous complètons l'esquisse gauche en respectant toutes les contraintes pour gérer le compartiement gauche  
 <img width="533" alt="3" src="https://github.com/user-attachments/assets/bcb0eef0-05e2-478e-bbe4-127ef6a33348" />

 ### Étape 4 : Création du compartiment gauche    
On fait appelle à la fonction **Bossage/base extrudé** pour dimensionner la profondeur et on abtient notre 'Parallélépipède creux'    

<img width="287" alt="4" src="https://github.com/user-attachments/assets/21e718a1-2409-49a7-a206-c9cd136fa6c6" />  

### Étape 5 :Nouvelle esquisse    
On réalise une nouvelle esquisse comme montrée dans l’image suivante.  
<img width="271" alt="5" src="https://github.com/user-attachments/assets/b50f6db5-b2b3-4bf6-928a-833715d18c91" />  

 ### Étape 6 :Création des petits rayons  
On fait appelle à la fonction **Congé** dans solidwork ensuite pour les rayons de 10mm comme le montre l'image suivante  

<img width="395" alt="6" src="https://github.com/user-attachments/assets/66369111-779c-4fba-ae79-4b8b55982b3f" />  

### Étape 7 : Création du compartiment droite
on dessine l’esquisse de base pour le bloc gauche en se référant aux dimensions définies par les variables globales précédemments créées **A** et **Y**. Ensuite grace à la fonction **enlèv. de matière extrudé** on obtient le compatiment droit comme le montre les deux images suivantes.  
<img width="469" alt="8" src="https://github.com/user-attachments/assets/b3c51aba-4db2-4671-94ae-80a8066648d8" />  
<img width="448" alt="{AAACF8B8-F2BF-45CC-9900-62C3029A6860}" src="https://github.com/user-attachments/assets/18bfc590-7304-4d95-b43d-d0e6fa9042bb" />  

### Étape 8: Support de liaison   

Nous allons faire une nouvelle esquisse entre les deux compartiments pour créer le support de liaison entre les deux bolcs en respectant toutes les mesures et en applicants aussi des congés d'esquisses pour bien gérer les rayons de liaisons.
<img width="449" alt="9" src="https://github.com/user-attachments/assets/e1184d6e-a061-48f0-870b-3181a53584d3" />  

### Étape 9: Création du Support de liaison   
En applicant ensuite la fonction **Bossage/base extrudé** on a notre support de liaison 
<img width="466" alt="{47949EEF-09B1-4845-BC39-809A84B24AEC}" src="https://github.com/user-attachments/assets/c85d44ab-e252-49b3-ae3f-9aad9fa760ef" />  

### Étape 10:  Création de la partie en haut du Support de liaison   
Nous allons faire une nouvelle esquisse en hatu du support de liaison en respectant toutes les mesures et en applicants aussi la fonction **Bossage/base extrudé**.  
<img width="457" alt="10" src="https://github.com/user-attachments/assets/62e39287-4f14-4928-bd65-8cffa6e0a6d2" />  

### Étape 11: complément de la création de la partie en haut du Support de liaison   
On crée une nouvelle esquisse et en application les fonction **enlèv. de matière extrudé**, **Congé** et des **congés d'esquisses** on obtient notre pièces complète  

<img width="459" alt="{A5872484-B046-4FAD-98DA-4D40EAB7A77A}" src="https://github.com/user-attachments/assets/4d76eebe-8a6e-4a48-9f4e-9ef7c20a7a59" />  
<img width="459" alt="{A5872484-B046-4FAD-98DA-4D40EAB7A77A}" src="https://github.com/user-attachments/assets/2530abaf-db91-4bd3-993d-0f719cd37f7e" />  

### Pièces complète   
On botient ainsi notre pièce complète qu'on peut modifier la couleur et évaluer la masse bien sûr en applicant le matériau en lui donnant le **1060 Aloy Aluminium**  

### Evaluation de la masse de notre pièce
On peut évaluer maintenant la masse  

<img width="250" alt="11masse1" src="https://github.com/user-attachments/assets/d790a5ad-38e2-4956-a236-365dd9bf8b70" />  

On trouve une masse de 1373,85 grammes.

### Étape 1 : Modification des variables et évaluation de la masse  
Dans cette étape, on modifie les valeurs des variables globales **A**, **B** et **w** ,**X**, **Y** et **Z** pour obtenir des pièces avec les paramètres de b°) et c°) Après avoir mis à jour la géométrie, on effectue une nouvelle évaluation de la masse de la pièce.  

Apès avoir fait les mêmes choses on évalue les masses.  
 *pour b) A = 205 mm ; B = 100mm ; W = B/2 mm ; X = A/4 mm ; Y = B+5.5 mm ; Z = B+15 
mm ;*  

On trouve une masse de 
<img width="189" alt="12masse 2" src="https://github.com/user-attachments/assets/3734e301-fecb-4861-871f-4dbe8dc38baa" />  

On trouve une masse de 1634.80 grammes  

*pour c) A = 210 mm ; B = 105 mm ; W = B/2 mm ; X = A/4 mm ; Y = B+5.5 mm ; Z = B+15 
mm ;*  

<img width="208" alt="13masse3" src="https://github.com/user-attachments/assets/40410cee-81d0-4fcd-8939-18723757013d" />  

On trouve une masse de 1807.29 grammes 


