#include "algorithm.h"
#include <queue>
#include <climits>
#include <unordered_set>

const vector<pair<int, int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
//se utiliza para crear unordered_set para verificar que los puntos esten en el conjunto
struct pair_hash {
    template <class T1, class T2>
    size_t operator() (const std::pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};


void floodFillDistance(const vector<vector<char>>& matrix, int startX,
    int startY, vector<vector<int>>& distances, vector<vector<pair<int, int>>>& predecessors, const unordered_set<pair<int, int>, pair_hash>& pointsSet) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Inicializamos la matriz de distancias con un valor alto (infinito)
    distances = vector<vector<int>>(rows, vector<int>(cols, INT_MAX));
    predecessors = vector<vector<pair<int, int>>>(rows, vector<pair<int, int>>(cols, { -1, -1 }));
    
    // Creo la cola
    queue<pair<int, int>> q;
    q.push({ startX, startY });
    distances[startX][startY] = 0;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        int x = current.first;
        int y = current.second;
        q.pop();

        for (const auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;

            // Verificar límites, accesibilidad 
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols &&
                matrix[newX][newY] != '+' &&
                (matrix[newX][newY] != '#' || pointsSet.find({ newX, newY }) != pointsSet.end()) &&
                distances[newX][newY] == INT_MAX ) {

                distances[newX][newY] = distances[x][y] + 1;
                predecessors[newX][newY] = { x, y };
                q.push({ newX, newY });
            }
        }
    }
}


vector<pair<int, int>> reconstructPath(const vector<vector<pair<int, int>>>& predecessors, pair<int, int> end) {
    vector<pair<int, int>> path;
    for (pair<int, int> at = end; at != make_pair(-1, -1); at = predecessors[at.first][at.second]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path;
}

void findShortestPath(vector<vector<char>>& matrix, const vector<pair<int, int>>& points) {
    vector<pair<int, int>> fullPath;
    unordered_set<pair<int, int>, pair_hash> pointsSet(points.begin(), points.end());

    for (size_t i = 0; i < points.size() - 1; ++i) {
        vector<vector<int>> distances;
        vector<vector<pair<int, int>>> predecessors;
        floodFillDistance(matrix, points[i].first, points[i].second, distances, predecessors, pointsSet);

        if (distances[points[i + 1].first][points[i + 1].second] == INT_MAX) {
            // No hay camino entre points[i] y points[i+1]
            return;
        }

        vector<pair<int, int>> pathSegment = reconstructPath(predecessors, points[i + 1]);
        if (i > 0) {
            pathSegment.erase(pathSegment.begin()); // Evitar duplicar el punto de conexión
        }
        fullPath.insert(fullPath.end(), pathSegment.begin(), pathSegment.end());
    }

    // Marcar el camino en la matriz con +
    for (const auto& p : fullPath) {
        if (pointsSet.find(p) == pointsSet.end()) { // No sobrescribir los puntos de interés
            matrix[p.first][p.second] = '+';
        }
    }

    return;
}