#ifndef ARTICULACAO_H
#define ARTICULACAO_H

#include <vector>
#include <cstddef> // Para size_t
#include "grafo.h"

class DetectorPontosArticulacao {
private:
    const Grafo& grafo;
    std::vector<bool> visitado;
    std::vector<int> descoberta;
    std::vector<int> menor;
    std::vector<bool> ehPontoArticulacao;
    int tempo;

    // Função auxiliar DFS
    void dfs(int u, int pai);

public:
    explicit DetectorPontosArticulacao(const Grafo& g);
    
    // Encontra todos os pontos de articulação no grafo
    std::vector<int> encontrarPontosArticulacao();
};

#endif // ARTICULACAO_H