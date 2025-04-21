#ifndef ABRIGO_H
#define ABRIGO_H

#include <vector>

// Estrutura para representar um abrigo
struct Abrigo {
    int raio;
    int x, y;
    
    Abrigo(int r, int x, int y);
};

// Verifica se dois círculos (abrigos) se intersectam ou são tangentes
bool circulosSeIntersectam(const Abrigo& a1, const Abrigo& a2);

// Verifica se um ponto (x,y) está dentro de um abrigo
bool pontoNoAbrigo(int x, int y, const Abrigo& abrigo);

// Encontra todos os abrigos que contêm um determinado ponto
std::vector<int> encontrarAbrigosContendoPonto(int x, int y, const std::vector<Abrigo>& abrigos);

#endif // ABRIGO_H