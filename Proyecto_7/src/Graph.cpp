#include "../include/Graph.h"

namespace DataStructures {

    WeightedGraph::WeightedGraph(int V) : V(V), adj(V) { }

    void WeightedGraph::addEdge(int u, int v, int w) {
        // Aseguramos que el peso sea positivo
        if (w > 0)
            adj[u].push_back(Edge(v, w));
        else
            std::cerr << "Error: El peso debe ser mayor a 0." << std::endl;
    }

    void WeightedGraph::printGraph() const 
    {
        for (int i = 0; i < V; i++) 
        {
            std::cout << "Vértice " << i << ": ";
            for (const auto &edge : adj[i])
            {
                std::cout << "(dest: " << edge.dest << ", peso: " << edge.weight << ") ";
            }
            std::cout << std::endl;
        }
    }

    std::vector<int> WeightedGraph::dijkstra(int src) const 
    {
        // Inicializar las distancias a infinito
        const int INF = std::numeric_limits<int>::max();
        std::vector<int> dist(V, INF);
        dist[src] = 0;

        // Priority queue: par (distancia, vértice)
        typedef std::pair<int, int> Pair;
        std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
        pq.push({0, src});

        while (!pq.empty()) 
        {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u])
            {
                continue; // ya se encontró un camino más corto
            }

            // Recorrer vecinos de u usando auto
            for (const auto &edge : adj[u]) 
            {
                int v = edge.dest;
                int weight = edge.weight;
                if (dist[u] != INF && dist[u] + weight < dist[v]) 
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

} // namespace DataStructures