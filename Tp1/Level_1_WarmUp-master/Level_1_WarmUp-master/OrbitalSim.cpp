/**
 * @brief Orbital simulation
 * @author Marc S. Ressl
 * Alumnos: Quiroga, Ignacio ; Riverós, Santiago A. ; Solar Grillo, Lucas.
 * Materia: Estructuras de Datos y Algoritmos (25.03).
 * @copyright Copyright (c) 2022-2023
 */

 // Enables M_PI #define in Windows
#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <math.h>
#include "OrbitalSim.h"
#include "ephemerides.h"


/**
 * @brief Gets a uniform random value in a range
 *
 * @param min Minimum value
 * @param max Maximum value
 * @return The random value
 */
float getRandomFloat(float min, float max)
{
	return min + (max - min) * rand() / (float)RAND_MAX;
}

/**
 * @brief Configures an asteroid
 *
 * @param body An orbital body
 * @param centerMass The mass of the most massive object in the star system
 */
void configureAsteroid(OrbitalBody* body, float centerMass)
{
	// Logit distribution
	float x = getRandomFloat(0, 1);
	float l = logf(x) - logf(1 - x) + 1;

	// https://mathworld.wolfram.com/DiskPointPicking.html
	float r = ASTEROIDS_MEAN_RADIUS * sqrtf(fabsf(l));
	float phi = getRandomFloat(0, 2.0F * (float)M_PI);

#ifdef EASTER_EGG
	phi = NUMERO_AUREO;
#endif // EASTER_EGG

	// https://en.wikipedia.org/wiki/Circular_orbit#Velocity
	float v = sqrtf(GRAVITATIONAL_CONSTANT * centerMass / r) * getRandomFloat(0.6F, 1.2F);
	float vy = getRandomFloat(-1E2F, 1E2F);

	body->color = GRAY;
	body->posicion = { r * cosf(phi), 0, r * sinf(phi) };
	body->velocidad = { -v * sinf(phi), vy, v * cosf(phi) };
}

/**
 * @brief Constructs an orbital simulation
 *
 * @param float The time step
 * @return The orbital simulation
 */
OrbitalSim* constructOrbitalSim(float timeStep)
{
	int i, j;
	OrbitalSim* sim = new OrbitalSim;
	sim->timeStep = timeStep;


#ifndef ALPHA_CENTAURI
	sim->cantidadCuerpos = SOLARSYSTEM_BODYNUM + CANT_ASTEROIDES;
	sim->cuerpos = new OrbitalBody[sim->cantidadCuerpos];

	// Inicialización del arreglo de cuerpos con el contenido de solarSystem[]
	for (i = 0; i < SOLARSYSTEM_BODYNUM; i++)
	{
		sim->cuerpos[i].nombre = solarSystem[i].name;
		sim->cuerpos[i].masa = solarSystem[i].mass;
		sim->cuerpos[i].radio = solarSystem[i].radius;
		sim->cuerpos[i].color = solarSystem[i].color;
		sim->cuerpos[i].posicion = solarSystem[i].position;
		sim->cuerpos[i].velocidad = solarSystem[i].velocity;
	}

#else 
	sim->cantidadCuerpos = ALPHACENTAURISYSTEM_BODYNUM + CANT_ASTEROIDES;
	sim->cuerpos = new OrbitalBody[sim->cantidadCuerpos];

	// Inicialización del arreglo de cuerpos con el contenido de alphaCentauriSystem[]
	for (i = 0; i < ALPHACENTAURISYSTEM_BODYNUM; i++)
	{
		sim->cuerpos[i].nombre = alphaCentauriSystem[i].name;
		sim->cuerpos[i].masa = alphaCentauriSystem[i].mass;
		sim->cuerpos[i].radio = alphaCentauriSystem[i].radius;
		sim->cuerpos[i].color = alphaCentauriSystem[i].color;
		sim->cuerpos[i].posicion = alphaCentauriSystem[i].position;
		sim->cuerpos[i].velocidad = alphaCentauriSystem[i].velocity;
	}
#endif

#ifdef ASTEROIDES
	for (i; i < sim->cantidadCuerpos; i++) //Inicializacion de asteroides
	{
		configureAsteroid(&(sim->cuerpos[i]), solarSystem[0].mass); //centro de masa del Sol 
	}
#endif

	return sim;
}

/**
 * @brief Destroys an orbital simulation
 */
void destroyOrbitalSim(OrbitalSim* sim)
{
	delete[] sim->cuerpos;
	delete sim;
}

/**
 * @brief Simulates a timestep
 *
 * @param sim The orbital simulation
 */
void updateOrbitalSim(OrbitalSim* sim)
{
	Vector3 vectorUnitario, fuerzaNetaDivididoMi = { 0,0,0 };
	float distanciaAlCuadrado, productoMjG;
	int i, j;

	for (i = 0; i < sim->cantidadCuerpos; i++)  // 1°) Cálculo de aceleraciones
	{
		for (j = 0; j < sim->cantidadCuerpos - CANT_ASTEROIDES; j++)
		{
			if ((sim->cuerpos[i].nombre) != (sim->cuerpos[j].nombre))
			{
				distanciaAlCuadrado = Vector3DistanceSqr(sim->cuerpos[i].posicion, sim->cuerpos[j].posicion);
				vectorUnitario = Vector3Normalize(Vector3Subtract(sim->cuerpos[i].posicion,
					sim->cuerpos[j].posicion));
				productoMjG = (GRAVITATIONAL_CONSTANT) * (sim->cuerpos[j].masa);
				fuerzaNetaDivididoMi = Vector3Add(fuerzaNetaDivididoMi, Vector3Negate(Vector3Scale(Vector3Scale
				(vectorUnitario, productoMjG), (1 / distanciaAlCuadrado))));
			}
		}
		sim->cuerpos[i].aceleracion = fuerzaNetaDivididoMi;
		fuerzaNetaDivididoMi = { 0,0,0 };
	}

	for (i = 0; i < sim->cantidadCuerpos; i++)  // 2°) Cálculo de velocidades y posiciones
	{
		sim->cuerpos[i].velocidad = Vector3Add(sim->cuerpos[i].velocidad,
			Vector3Scale(sim->cuerpos[i].aceleracion, sim->timeStep));
		sim->cuerpos[i].posicion = Vector3Add(sim->cuerpos[i].posicion,
			Vector3Scale(sim->cuerpos[i].velocidad, sim->timeStep));
	}
}


