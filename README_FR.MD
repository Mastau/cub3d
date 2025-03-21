# Documentation du Projet Cub3D

## Table des Matières
1. [Introduction](#introduction)
2. [Structure du Projet](#structure-du-projet)
3. [Module Principal](#module-principal)
4. [Algorithmes](#algorithmes)
5. [Interface Utilisateur](#interface-utilisateur)
6. [Rendu](#rendu)
7. [Utilitaires](#utilitaires)
8. [Flux de Travail](#flux-de-travail)
9. [Contributeurs](#contributeurs)

## Introduction

Cub3D est un moteur de raycasting inspiré du jeu classique Wolfenstein 3D. Le programme crée une perspective 3D dans une carte 2D, permettant aux joueurs de se déplacer dans un labyrinthe rendu avec des murs texturés.

## Structure du Projet

Le projet est organisé en plusieurs modules clés :

- **Principal** : Le point d'entrée de l'application
- **Algorithmes** : Fonctions pour le raycasting et les calculs de position du joueur
- **Macro** : Gestion des entrées et mouvements du joueur
- **Rendu** : Visualisation 3D et gestion des textures
- **Utilitaires** : Fonctions auxiliaires pour diverses tâches

## Module Principal

### main.c

- **main()** : Point d'entrée du programme. Initialise les données du jeu, configure le joueur et démarre le processus de rendu 3D. Gère le nettoyage à la sortie.

## Algorithmes

### init_player.c
- **initialize_player()** : Configure la position initiale du joueur et le vecteur de direction en fonction des données de la carte.

### degree_to_radian.c
- **degree_to_radian()** : Convertit les mesures d'angle de degrés en radians pour les calculs trigonométriques.

### ray_cast.c
- **ray_cast()** : La fonction principale de raycasting. Envoie des rayons depuis la position du joueur et détecte les intersections avec les murs. Renvoie les informations d'impact et les coordonnées.

### init_ray_steps.c
- **init_ray_data()** : Initialise la structure de données pour un seul rayon avec l'angle approprié en fonction de la position à l'écran.
- **init_ray_steps()** : Calcule les valeurs d'étape pour l'algorithme DDA (Digital Differential Analysis) utilisé dans le raycasting.

### calculate_intersection.c
- **calculate_intersection()** : Détermine où un rayon croise un mur, en calculant les coordonnées exactes.

### get_player_orientation.c
- **get_player_orientation()** : Extrait l'orientation initiale du joueur (N, S, E, W) à partir des données de la carte.
- **get_base_angle()** : Convertit l'orientation en caractère en un angle numérique en degrés.

### wall_calculations.c
- Fonctions pour calculer les distances des murs et les propriétés pour le rendu.

## Interface Utilisateur

### hook.c
- **window_hook()** : Gère les événements de la fenêtre, particulièrement la fermeture de la fenêtre.
- **key_press_hook()** : Traite les appuis de touches du clavier pour les mouvements et les actions du joueur.
- **key_release_hook()** : Gère les événements de relâchement de touches pour arrêter les actions du joueur.

### moves.c
- **move_player_forward()** : Déplace le joueur vers l'avant en fonction du vecteur de direction actuel.
- **move_player_backward()** : Déplace le joueur vers l'arrière, à l'opposé du vecteur de direction actuel.
- **move_player_left()** : Déplace latéralement le joueur vers la gauche (perpendiculairement au vecteur de direction).
- **move_player_right()** : Déplace latéralement le joueur vers la droite (perpendiculairement au vecteur de direction).

### rotates.c
- **rotate_player_left()** : Fait pivoter la vue du joueur vers la gauche.
- **rotate_player_right()** : Fait pivoter la vue du joueur vers la droite.

## Rendu

### rendering.c
- **init_3d_rendering()** : Configure l'environnement de rendu 3D, initialisant la fenêtre, les textures et les gestionnaires d'événements.
- **render()** : Fonction principale de rendu qui efface la fenêtre et affiche la vue 3D.
- **update_3d_view()** : Fonction de boucle de jeu qui gère les mouvements du joueur et les mises à jour de la vue.

### render_3d_view.c
- **render_3d_view()** : Lance des rayons sur toute la largeur de l'écran et affiche les murs résultants.
- **calculate_distance()** : Calcule la distance aux intersections des murs et applique la correction de l'effet œil-de-poisson.
- **process_ray()** : Traite un seul rayon, calculant son intersection et l'orientation du mur.

### draw_vertical_line.c
- **draw_vertical_line()** : Dessine une seule tranche verticale d'un mur avec la texture appropriée.
- **get_wall_texture()** : Renvoie la texture correcte en fonction de l'orientation du mur.
- **draw_ceiling()** : Dessine le plafond pour une tranche verticale.
- **draw_floor()** : Dessine le sol pour une tranche verticale.
- **draw_wall()** : Dessine le mur texturé pour une tranche verticale.

### determine_wall_orientation.c
- **determine_wall_orientation_part1/2/3()** : Détermine quel côté d'un mur (Nord, Sud, Est, Ouest) le rayon a touché en fonction des coordonnées d'intersection.

### init.c / init2.c
- **init_window_info()** : Configure les paramètres de création de la fenêtre.
- **init_keys_3d()** : Initialise l'état des entrées clavier.
- **init_render_params()** : Configure les paramètres nécessaires pour le rendu d'une tranche verticale.
- **init_line_data_part1/2/3()** : Initialise différents aspects des données de dessin de ligne.
- **init_colors()** : Configure les couleurs du plafond et du sol à partir de la configuration.

### load_textures.c
- **load_textures()** : Charge les textures des murs à partir des fichiers image.

## Utilitaires

### convert_rgb_str_to_color.c
- **convert_rgb_str_to_color()** : Convertit la représentation en chaîne RGB en une valeur de couleur.

## Flux de Travail

Le programme suit ce flux de travail général :

1. Initialisation des données du jeu, de la position du joueur et de l'environnement de rendu
2. Boucle principale du jeu :
   - Traitement des entrées utilisateur
   - Mise à jour de la position et de l'orientation du joueur
   - Lancement de rayons pour chaque tranche verticale de l'écran
   - Calcul des distances des murs et des orientations
   - Application des textures en fonction de l'orientation du mur
   - Rendu de la scène avec les couleurs appropriées pour le plafond et le sol
3. Nettoyage et sortie lorsque l'utilisateur ferme la fenêtre

L'algorithme de raycasting fonctionne en lançant des rayons depuis la position du joueur à différents angles à travers le champ de vision. Pour chaque rayon :
1. Calculer la direction du rayon
2. Parcourir la grille de la carte à l'aide de l'algorithme DDA (Digital Differential Analysis)
3. Détecter les collisions avec les murs
4. Calculer la distance jusqu'au mur (avec correction de l'effet œil-de-poisson)
5. Déterminer la hauteur et l'orientation du mur
6. Appliquer la texture appropriée en fonction de l'orientation du mur
7. Dessiner la tranche du mur avec la bonne portion de la texture

Cela crée l'illusion d'un environnement 3D tout en maintenant des performances rapides même sur du matériel moins puissant.

## Contributeurs

- [Mastau](https://github.com/Mastau)
- [Wormav](https://github.com/Wormav)
