#ifndef BFS_H
#define BFS_H

#include <vector>
#include <cstddef> // Para size_t
#include "grafo.h"

// Encontra o caminho mais curto entre dois conjuntos de vértices usando BFS
int encontrarCaminhoMaisCurto(const Grafo& grafo, 
                             const std::vector<int>& abrigosOrigem, 
                             const std::vector<int>& abrigosDestino);

#endif // BFS_H