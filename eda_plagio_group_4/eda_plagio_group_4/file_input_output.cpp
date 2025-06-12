#include "file_input_output.h"
#include <fstream>
#include <sstream>
#include <iostream>

void input_file(const string& file_name, Matriz& matriz, GruposCoordenadas& grupos) {
    ifstream archivo(file_name);   // Abro el archivo en modo lectura
    string linea; 
    bool enMatriz = true;

    while (getline(archivo, linea)) 
    {

        if (linea.empty()) 
        {
            enMatriz = false;
            grupos.push_back(vector<Coordenada>());   
            continue;
        }
        if (enMatriz)
        {
            matriz.push_back(vector<char>(linea.begin(), linea.end()));  
        }
        else
        {
            int x, y;
            char comma;
            stringstream ss(linea); // Uso stringstream para agarrar los datos de mi línea como si fuera entrada de flujo y salida.
            if (ss >> x >> comma >> y && comma == ',') // Me aseguro que la las coordenadas las pasen con x,y. Asi solo extraigo las coordenadas x e y.
            {
                Coordenada coord = make_pair(y, x); // Invertir x e y para convertir a coordenadas matriciales.
                grupos.back().push_back(coord);
            }
            else
            {
                cerr << "Error al leer coordenadas de la línea: " << linea << endl;
            }
        }
    }
}

void printMatrix(const vector<vector<char>>& matrix) {
    for (const auto& row : matrix) 
    {
        for (const auto& cell : row) 
        {
            cout << cell << " ";
        }
        cout << endl;
    }
}