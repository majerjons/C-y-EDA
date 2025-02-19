#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <limits>
#include <queue>
#include <iostream>

namespace DataStructures 
{

    // Estructura que representa una arista ponderada.
    struct Edge 
    {
        int dest;   // Vértice destino
        int weight; // Peso de la arista (debe ser > 0)
        Edge(int d, int w) : dest(d), weight(w) {}
    };

    // Clase para representar un grafo ponderado usando una lista de adyacencia.
    class WeightedGraph 
    {
    private:
        int V; // Número de vértices
        std::vector<std::list<Edge>> adj; // Lista de adyacencia

    public:
        // Constructor: Inicializa el grafo con V vértices.
        WeightedGraph(int V);

        // Agrega una arista dirigida desde u hasta v con peso w.
        void addEdge(int u, int v, int w);

        // Imprime la lista de adyacencia del grafo.
        void printGraph() const;

        // Aplica el algoritmo de Dijkstra para hallar distancias mínimas desde un vértice fuente.
        // Devuelve un vector de distancias.
        std::vector<int> dijkstra(int src) const;
    };

} // namespace DataStructures

#endif