#include <iostream>
#include <vector>
#include "abrigo.h"
#include "grafo.h"
#include "bfs.h"
#include "diametroGrafo.h"
#include "articulacao.h"

int main() {
    // Leitura da entrada
    int Ax, Ay, Bx, By, N;
    std::cin >> Ax >> Ay;
    std::cin >> Bx >> By;
    std::cin >> N;
    
    std::vector<Abrigo> abrigos;
    for (int i = 0; i < N; i++) {
        int R, X, Y;
        std::cin >> R >> X >> Y;
        abrigos.emplace_back(R, X, Y);
    }
    
    // Constrói o grafo
    Grafo grafo = construirGrafo(abrigos);
    
    // Parte 1: Encontra o caminho mais curto entre Ana e Bernardo
    std::vector<int> abrigosAna = encontrarAbrigosContendoPonto(Ax, Ay, abrigos);
    std::vector<int> abrigosBernardo = encontrarAbrigosContendoPonto(Bx, By, abrigos);
    
    int caminhoMaisCurto = encontrarCaminhoMaisCurto(grafo, abrigosAna, abrigosBernardo);
    std::cout << "Parte 1: " << caminhoMaisCurto << std::endl;
    
    // Parte 2: Calcula o diâmetro do grafo
    int diametro = calcularDiametro(grafo);
    std::cout << "Parte 2: " << diametro << std::endl;
    
    // Parte 3: Encontra os pontos de articulação
    DetectorPontosArticulacao detector(grafo);
    std::vector<int> pontosArticulacao = detector.encontrarPontosArticulacao();
    
    std::cout << "Parte 3: " << pontosArticulacao.size();
    for (int ponto : pontosArticulacao) {
        std::cout << " " << (ponto + 1); // +1 porque a indexação é baseada em 1 na saída
    }
    std::cout << std::endl;
    
    return 0;
}