#include <iostream>
#include "include/Graph.h"

using namespace std;
using namespace DataStructures;

int main() 
{
    // Crear un grafo ponderado con 6 vértices (0 a 5)
    WeightedGraph g(6);

    // Agregar aristas: addEdge(u, v, peso)
    g.addEdge(0, 1, 7);
    g.addEdge(0, 2, 9);
    g.addEdge(0, 5, 14);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 11);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, 6);
    g.addEdge(4, 5, 9);

    // Imprimir el grafo
    cout << "Lista de adyacencia del grafo ponderado:" << endl;
    g.printGraph();

    // Aplicar Dijkstra desde el vértice 0
    cout << "\nAplicando Dijkstra desde el vértice 0:" << endl;
    vector<int> dist = g.dijkstra(0);
    for (int i = 0; i < dist.size(); i++) 
    {
        cout << "Distancia mínima a vértice " << i << ": ";
        if(dist[i] == std::numeric_limits<int>::max())
        {
            cout << "INF";
        }
        else
        {
            cout << dist[i];
        }
        cout << endl;
    }

    return 0;
}