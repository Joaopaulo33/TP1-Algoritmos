#include "diametroGrafo.h"
#include <limits>
#include <vector>

int calcularDiametro(const Grafo& grafo) {
    size_t numVertices = grafo.obterNumVertices();
    const int INF = std::numeric_limits<int>::max() / 2; 
    
    // Inicializa a matriz de distâncias
    std::vector<std::vector<int>> dist(numVertices, std::vector<int>(numVertices, INF));
    
    // Distância de um vértice para ele mesmo é 0
    for (size_t i = 0; i < numVertices; i++) {
        dist[i][i] = 0;
    }
    
    // Distância entre vizinhos diretos é 1
    for (size_t i = 0; i < numVertices; i++) {
        for (int vizinho : grafo.obterVizinhos(static_cast<int>(i))) {
            dist[i][static_cast<size_t>(vizinho)] = 1;
        }
    }
    
    // Algoritmo de Floyd-Warshall
    for (size_t k = 0; k < numVertices; k++) {
        for (size_t i = 0; i < numVertices; i++) {
            for (size_t j = 0; j < numVertices; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    // Encontra o maior caminho mínimo (diâmetro)
    int diametro = 0;
    for (size_t i = 0; i < numVertices; i++) {
        for (size_t j = 0; j < numVertices; j++) {
            if (dist[i][j] != INF && dist[i][j] > diametro) {
                diametro = dist[i][j];
            }
        }
    }
    
    return diametro;
}