/**
 * @brief Orbital simulation main module
 * @author Marc S. Ressl
 * Alumnos: Quiroga, Ignacio ; Riverós, Santiago A. ; Solar Grillo, Lucas.
 * Materia: Estructuras de Datos y Algoritmos (25.03).
 * @copyright Copyright (c) 2022-2023
 */

#include "View.h"
#include "OrbitalSim.h"
#define SECONDS_PER_DAY 86400

int main()
{
	int fps = 60;                                 // Frames per second
	float timeMultiplier = 100 * SECONDS_PER_DAY; // Simulation speed: 100 days per simulation second
	float timeStep = timeMultiplier / fps;

	OrbitalSim* sim = constructOrbitalSim(timeStep);
	View* view = constructView(fps);

	while (isViewRendering(view))
	{
		updateOrbitalSim(sim);

		renderView(view, sim);
	}

	destroyView(view);
	destroyOrbitalSim(sim);

	return 0;
}
