#include "bfs.h"
#include <queue>
#include <cstddef> // Para size_t
#include <limits>  // Para std::numeric_limits

int encontrarCaminhoMaisCurto(const Grafo& grafo, 
                             const std::vector<int>& abrigosOrigem, 
                             const std::vector<int>& abrigosDestino) {
    
    size_t numVertices = grafo.obterNumVertices();
    
    // Usando um valor especial para indicar que o vértice não foi visitado
    // Em vez de -1, usamos std::numeric_limits<int>::max() que é positivo
    std::vector<int> distancia(numVertices, std::numeric_limits<int>::max());
    
    std::queue<int> fila;
    
    // Verifica se algum abrigo está em ambos os conjuntos
    for (int origem : abrigosOrigem) {
        for (int destino : abrigosDestino) {
            if (origem == destino) {
                return 0; // Já estão no mesmo abrigo
            }
        }
    }
    
    // Adiciona todos os abrigos de origem como pontos de partida
    for (int abrigo : abrigosOrigem) {
        if (abrigo >= 0 && static_cast<size_t>(abrigo) < numVertices) {
            distancia[static_cast<size_t>(abrigo)] = 0;
            fila.push(abrigo);
        }
    }
    
    // BFS para encontrar o caminho mais curto
    while (!fila.empty()) {
        int atual = fila.front();
        fila.pop();
        
        // Verifica se chegamos a um abrigo de destino
        for (int abrigoDestino : abrigosDestino) {
            if (atual == abrigoDestino) {
                return distancia[static_cast<size_t>(atual)]; // Encontramos um caminho!
            }
        }
        
        // Processa vizinhos
        for (int vizinho : grafo.obterVizinhos(atual)) {
            size_t vizinhoIdx = static_cast<size_t>(vizinho);
            if (distancia[vizinhoIdx] == std::numeric_limits<int>::max()) {
                distancia[vizinhoIdx] = distancia[static_cast<size_t>(atual)] + 1;
                fila.push(vizinho);
            }
        }
    }
    
    return -1; // Não há caminho
}