#include "articulacao.h"

DetectorPontosArticulacao::DetectorPontosArticulacao(const Grafo& g) : grafo(g) {
    size_t numVertices = g.obterNumVertices();
    visitado.resize(numVertices, false);
    descoberta.resize(numVertices);
    menor.resize(numVertices);
    ehPontoArticulacao.resize(numVertices, false);
    tempo = 0;
}

void DetectorPontosArticulacao::dfs(int u, int pai) {
    // Marca o vértice atual como visitado
    visitado[static_cast<size_t>(u)] = true;
    
    // Inicializa tempo de descoberta e valor baixo
    descoberta[static_cast<size_t>(u)] = menor[static_cast<size_t>(u)] = ++tempo;
    
    int filhos = 0; // Contador de filhos na árvore DFS
    
    // Visita todos os vizinhos
    for (int v : grafo.obterVizinhos(u)) {
        // Se v é o pai de u, ignora
        if (v == pai) continue;
        
        // Se v não foi visitado
        if (!visitado[static_cast<size_t>(v)]) {
            filhos++;
            dfs(v, u);
            
            // Verifica se a subárvore enraizada em v tem uma conexão
            // para um ancestral de u
            menor[static_cast<size_t>(u)] = std::min(
                menor[static_cast<size_t>(u)], 
                menor[static_cast<size_t>(v)]
            );
            
            // u é um ponto de articulação nos seguintes casos:
            // (1) u é raiz da árvore DFS e tem mais de um filho
            if (pai == -1 && filhos > 1) {
                ehPontoArticulacao[static_cast<size_t>(u)] = true;
            }
            
            // (2) u não é raiz e o valor baixo de um de seus filhos é maior ou igual
            // ao tempo de descoberta de u
            if (pai != -1 && menor[static_cast<size_t>(v)] >= descoberta[static_cast<size_t>(u)]) {
                ehPontoArticulacao[static_cast<size_t>(u)] = true;
            }
        }
        // Atualiza o valor baixo de u para vértices já visitados
        else if (v != pai) {
            menor[static_cast<size_t>(u)] = std::min(
                menor[static_cast<size_t>(u)], 
                descoberta[static_cast<size_t>(v)]
            );
        }
    }
}

std::vector<int> DetectorPontosArticulacao::encontrarPontosArticulacao() {
    size_t numVertices = grafo.obterNumVertices();
    
    // Para cada componente conexo do grafo
    for (size_t i = 0; i < numVertices; i++) {
        if (!visitado[i]) {
            dfs(static_cast<int>(i), -1); // -1 indica sem pai
        }
    }
    
    // Coleta os índices dos pontos de articulação
    std::vector<int> pontosArticulacao;
    for (size_t i = 0; i < numVertices; i++) {
        if (ehPontoArticulacao[i]) {
            pontosArticulacao.push_back(static_cast<int>(i));
        }
    }
    
    return pontosArticulacao;
}