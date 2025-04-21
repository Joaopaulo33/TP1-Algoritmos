#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <cstddef> // Para size_t
#include "abrigo.h"

// Classe para representar o grafo
class Grafo {
private:
    size_t numVertices;
    std::vector<std::vector<int>> listaAdj;

public:
    // Construtor que inicializa o grafo com n vértices
    explicit Grafo(size_t n);
    
    // Adiciona uma aresta não direcionada entre u e v
    void adicionarAresta(int u, int v);
    
    // Retorna os vizinhos de um vértice
    const std::vector<int>& obterVizinhos(int v) const;
    
    // Retorna o número de vértices
    size_t obterNumVertices() const;
    
    // Retorna a lista de adjacência completa
    const std::vector<std::vector<int>>& obterListaAdj() const;
};

// Constrói um grafo a partir de uma lista de abrigos
Grafo construirGrafo(const std::vector<Abrigo>& abrigos);

#endif // GRAFO_H