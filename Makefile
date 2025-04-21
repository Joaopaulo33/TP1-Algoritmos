# Nome do executável
EXEC = tp1.out

# Diretórios
SRCDIR = ./src
INCDIR = ./include
OBJDIR = obj
BINDIR = bin

# Lista de arquivos objeto (.o) com o caminho do diretório 'obj'
OBJ = $(OBJDIR)/main.o $(OBJDIR)/abrigo.o $(OBJDIR)/grafo.o $(OBJDIR)/bfs.o $(OBJDIR)/diametroGrafo.o $(OBJDIR)/articulacao.o

# Compilador
CC = g++

# Opções de compilação
CFLAGS = -Wall -Wextra -Wpedantic -Wformat-security -Wconversion -Werror -std=c++17 -I$(INCDIR)

# Regra padrão que será chamada quando rodarmos "make"
all: $(BINDIR)/$(EXEC)

# Regra para criar o executável na pasta 'bin'
$(BINDIR)/$(EXEC): $(OBJ) | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para criar o diretório 'obj' se ele não existir
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Regra para criar o diretório 'bin' se ele não existir
$(BINDIR):
	mkdir -p $(BINDIR)

# Regra para compilar main.cpp em main.o
$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(INCDIR)/abrigo.h $(INCDIR)/grafo.h $(INCDIR)/bfs.h $(INCDIR)/diametroGrafo.h $(INCDIR)/articulacao.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para compilar abrigo.cpp em abrigo.o
$(OBJDIR)/abrigo.o: $(SRCDIR)/abrigo.cpp $(INCDIR)/abrigo.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para compilar grafo.cpp em grafo.o
$(OBJDIR)/grafo.o: $(SRCDIR)/grafo.cpp $(INCDIR)/grafo.h $(INCDIR)/abrigo.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para compilar bfs.cpp em bfs.o
$(OBJDIR)/bfs.o: $(SRCDIR)/bfs.cpp $(INCDIR)/bfs.h $(INCDIR)/grafo.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para compilar diametroGrafo.cpp em diametroGrafo.o
$(OBJDIR)/diametroGrafo.o: $(SRCDIR)/diametroGrafo.cpp $(INCDIR)/diametroGrafo.h $(INCDIR)/grafo.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para compilar articulacao.cpp em articulacao.o
$(OBJDIR)/articulacao.o: $(SRCDIR)/articulacao.cpp $(INCDIR)/articulacao.h $(INCDIR)/grafo.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra de limpeza, remove os arquivos objeto e o executável
clean:
	rm -f $(OBJ) $(BINDIR)/$(EXEC)

# Regra de limpeza completa, remove os diretórios obj e bin
cleanall:
	rm -rf $(OBJDIR) $(BINDIR)

# Regra para executar o programa
run: $(BINDIR)/$(EXEC)
	$(BINDIR)/$(EXEC)

# Regra para criar a estrutura de diretórios do projeto
setup:
	mkdir -p $(SRCDIR) $(INCDIR) $(OBJDIR) $(BINDIR)
