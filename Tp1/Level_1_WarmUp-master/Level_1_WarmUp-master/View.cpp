/**
 * @brief Implements an orbital simulation view
 * @author Marc S. Ressl
 * Alumnos: Quiroga, Ignacio ; Riverós, Santiago A. ; Solar Grillo, Lucas.
 * Materia: Estructuras de Datos y Algoritmos (25.03).
 * @copyright Copyright (c) 2022-2023
 */

#include <time.h>
#include <vector>
#include "View.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define MAX_DISTANCE 30.0

#define CUERPOS_TOTALES sim->cantidadCuerpos;

 /**
  * @brief Converts a timestamp (number of seconds since 1/1/2022)
  *        to an ISO date ("YYYY-MM-DD")
  *
  * @param timestamp the timestamp
  * @return The ISO date (a raylib string)
  */
const char* getISODate(float timestamp)
{
	// Timestamp epoch: 1/1/2022
	struct tm unichEpochTM = { 0, 0, 0, 1, 0, 122 };

	// Convert timestamp to UNIX timestamp (number of seconds since 1/1/1970)
	time_t unixEpoch = mktime(&unichEpochTM);
	time_t unixTimestamp = unixEpoch + (time_t)timestamp;

	// Returns ISO date
	struct tm* localTM = localtime(&unixTimestamp);
	return TextFormat("%04d-%02d-%02d",
		1900 + localTM->tm_year, localTM->tm_mon + 1, localTM->tm_mday);
}

/**
 * @brief Constructs an orbital simulation view
 *
 * @param fps Frames per second for the view
 * @return The view
 */
View* constructView(int fps)
{
	View* view = new View();

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "EDA Orbital Simulation");
	SetTargetFPS(fps);
	DisableCursor();

	view->camera.position = { 10.0f, 10.0f, 10.0f };
	view->camera.target = { 0.0f, 0.0f, 0.0f };
	view->camera.up = { 0.0f, 1.0f, 0.0f };
	view->camera.fovy = 45.0f;
	view->camera.projection = CAMERA_PERSPECTIVE;

	return view;
}

/**
 * @brief Destroys an orbital simulation view
 *
 * @param view The view
 */
void destroyView(View* view)
{
	CloseWindow();

	delete view;
}

/**
 * @brief Should the view still render?
 *
 * @return Should rendering continue?
 */
bool isViewRendering(View* view)
{
	return !WindowShouldClose();
}

/**
 * Renders an orbital simulation
 *
 * @param view The view
 * @param sim The orbital sim
 */
void renderView(View* view, OrbitalSim* sim)
{
	UpdateCamera(&view->camera, CAMERA_FREE);

	BeginDrawing();

	ClearBackground(BLACK);
	BeginMode3D(view->camera);

	// Fill in your 3D drawing code here:

	//Inicializo variables a utilizar y arreglos

	const int cantAstros = CANT_NO_ASTEROIDES + CANT_ASTEROIDES;
	const int VectorDim = CANT_NO_ASTEROIDES + CANT_ASTEROIDES;
	const float LogFactor = 0.005F;
	const float scaleFactor = 1E-11f;
	int i;
	Vector3 position;
	Vector3 scaled_positions[cantAstros]; 
	std::vector<float> scaled_radius(cantAstros); 

	for (i = 0; i < cantAstros; ++i)
	{
		scaled_radius[i] = LogFactor * logf(sim->cuerpos[i].radio);
		scaled_positions[i].x = scaleFactor * sim->cuerpos[i].posicion.x;
		scaled_positions[i].y = scaleFactor * sim->cuerpos[i].posicion.y;
		scaled_positions[i].z = scaleFactor * sim->cuerpos[i].posicion.z;
	}


	//Renderizado de los objectos 3D:

	DrawGrid(10, 10.0f);
	for (i = 0; i < cantAstros; i++)
	{
		position = scaled_positions[i];
		float distance = Vector3Distance(view->camera.position, scaled_positions[i]); //Obtengo la posición de la camara
		//y calculo la distancia de entre esta y todos los objetos a renderizar

		if (i < cantAstros - CANT_ASTEROIDES)
		{
			if (distance <= MAX_DISTANCE)	//Si estan cerca, se renderizan como esfera los astros
			{
				DrawSphere(position, scaled_radius[i], sim->cuerpos[i].color);
			}
			else //Caso contrario, para optimizar recursos se renderizan como puntos
			{
				DrawPoint3D(scaled_positions[i], sim->cuerpos[i].color);
			}
		}

		else
		{
			DrawPoint3D(scaled_positions[i], sim->cuerpos[i].color);
		}
	}
	EndMode3D();

	sim->LapseTime += sim->timeStep;
	float myTimestamp = sim->LapseTime;
	const char* isoDate = getISODate(myTimestamp);
	DrawFPS(10, 10);
	DrawText(isoDate, 10, 30, 20, GREEN);



	EndDrawing();
}
