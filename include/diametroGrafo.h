#ifndef DIAMETROGRAFO_H
#define DIAMETROGRAFO_H

#include <cstddef> // Para size_t
#include "grafo.h"

// Calcula o diâmetro do grafo usando o algoritmo de Floyd-Warshall
int calcularDiametro(const Grafo& grafo);

#endif // DIAMETROGRAFO_H