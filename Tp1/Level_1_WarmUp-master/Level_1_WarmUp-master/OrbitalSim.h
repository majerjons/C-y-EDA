/**
 * @brief Orbital simulation
 * @author Marc S. Ressl
 * Alumnos: Quiroga, Ignacio ; Riverós, Santiago A. ; Solar Grillo, Lucas.
 * Materia: Estructuras de Datos y Algoritmos (25.03).
 * @copyright Copyright (c) 2022-2023
 */

#ifndef ORBITALSIM_H
#define ORBITALSIM_H

#define GRAVITATIONAL_CONSTANT 6.6743E-11F
#define ASTEROIDS_MEAN_RADIUS 4E11F
#define NUMERO_AUREO  1.6180339

 // Bonus: Asteroides
#define ASTEROIDES
#ifdef ASTEROIDES
#define CANT_ASTEROIDES 500     // Colocar cantidad de asteroides a simular
#else 
#define CANT_ASTEROIDES 0
#endif 

// Bonus: Alfa Centauri
//#define ALPHA_CENTAURI


// Easter Egg: Número Aureo
//#define EASTER_EGG


#ifdef ALPHA_CENTAURI
#define CANT_NO_ASTEROIDES 2
#else
#ifdef AGUJERO_NEGRO
#define CANT_NO_ASTEROIDES 10
#else
#define CANT_NO_ASTEROIDES 9
#endif
#endif

/**
 * @brief Orbital body definition
 */

#include "raylib.h"
#include "raymath.h"
struct OrbitalBody
{
	const char* nombre;
	float masa;
	float radio;
	Color color;
	Vector3 posicion;
	Vector3 velocidad;
	Vector3 aceleracion;
};

/**
 * @brief Orbital simulation definition
 */
struct OrbitalSim
{
	float timeStep;
	float LapseTime;
	unsigned int cantidadCuerpos;
	OrbitalBody* cuerpos;
};

OrbitalSim* constructOrbitalSim(float timeStep);

void destroyOrbitalSim(OrbitalSim* sim);

void updateOrbitalSim(OrbitalSim* sim);

#endif
