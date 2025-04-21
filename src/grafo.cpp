#include "grafo.h"

Grafo::Grafo(size_t n) : numVertices(n) {
    listaAdj.resize(n);
}

void Grafo::adicionarAresta(int u, int v) {
    listaAdj[static_cast<size_t>(u)].push_back(v);
    listaAdj[static_cast<size_t>(v)].push_back(u);
}

const std::vector<int>& Grafo::obterVizinhos(int v) const {
    return listaAdj[static_cast<size_t>(v)];
}

size_t Grafo::obterNumVertices() const {
    return numVertices;
}

const std::vector<std::vector<int>>& Grafo::obterListaAdj() const {
    return listaAdj;
}

Grafo construirGrafo(const std::vector<Abrigo>& abrigos) {
    size_t n = abrigos.size();
    Grafo grafo(n);
    
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (circulosSeIntersectam(abrigos[i], abrigos[j])) {
                grafo.adicionarAresta(static_cast<int>(i), static_cast<int>(j));
            }
        }
    }
    
    return grafo;
}