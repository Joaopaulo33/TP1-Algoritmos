#include "abrigo.h"
#include <cmath>

Abrigo::Abrigo(int r, int x, int y) : raio(r), x(x), y(y) {}

bool circulosSeIntersectam(const Abrigo& a1, const Abrigo& a2) {
    double distancia = std::sqrt(std::pow(a1.x - a2.x, 2) + std::pow(a1.y - a2.y, 2));
    return distancia <= static_cast<double>(a1.raio + a2.raio);
}

bool pontoNoAbrigo(int x, int y, const Abrigo& abrigo) {
    double distancia = std::sqrt(std::pow(x - abrigo.x, 2) + std::pow(y - abrigo.y, 2));
    return distancia <= static_cast<double>(abrigo.raio);
}

std::vector<int> encontrarAbrigosContendoPonto(int x, int y, const std::vector<Abrigo>& abrigos) {
    std::vector<int> abrigosContendoPonto;
    
    // Usando size_t para indexação
    for (size_t i = 0; i < abrigos.size(); i++) {
        if (pontoNoAbrigo(x, y, abrigos[i])) {
            abrigosContendoPonto.push_back(static_cast<int>(i));
        }
    }
    
    return abrigosContendoPonto;
}