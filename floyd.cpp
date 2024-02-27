#include iostream
#include vector
#include climits

using namespace std;

 Função para criar uma matriz de adjacência
vectorvectorint criarMatrizAdjacencia(int numVertices) {
     Inicializar matriz com todos os elementos como infinito (sem arestas)
    vectorvectorint matriz(numVertices, vectorint(numVertices, INT_MAX));
     Inicializar diagonal com 0 (vértices para si mesmos)
    for (int i = 0; i  numVertices; ++i)
        matriz[i][i] = 0;
    return matriz;
}

 Função para adicionar uma aresta com peso entre dois vértices na matriz de adjacência
void adicionarAresta(vectorvectorint& matriz, int vertice1, int vertice2, int peso) {
    matriz[vertice1][vertice2] = peso;
}

 Função para imprimir o menor caminho entre dois vértices
void imprimirMenorCaminho(const vectorvectorint& distancias, int origem, int destino) {
    if (distancias[origem][destino] == INT_MAX) {
        cout  Não há caminho entre   origem   e   destino  endl;
        return;
    }

    cout  Menor caminho entre   origem   e   destino   ;
    cout  origem;
    while (origem != destino) {
        origem = distancias[origem][destino];
        cout   -   origem;
    }
    cout  endl;
}

void floydWarshall(vectorvectorint& matriz) {
    int numVertices = matriz.size();

     Algoritmo de Floyd-Warshall para encontrar os menores caminhos entre todos os pares de vértices
    for (int k = 0; k  numVertices; ++k) {
        for (int i = 0; i  numVertices; ++i) {
            for (int j = 0; j  numVertices; ++j) {
                if (matriz[i][k] != INT_MAX && matriz[k][j] != INT_MAX && matriz[i][k] + matriz[k][j]  matriz[i][j]) {
                    matriz[i][j] = matriz[i][k] + matriz[k][j];
                }
            }
        }
    }
}

int main() {
    int numVertices, numArestas;
    cout  Digite o número de vértices ;
    cin  numVertices;
    cout  Digite o número de arestas ;
    cin  numArestas;

    vectorvectorint matrizAdjacencia = criarMatrizAdjacencia(numVertices);

    cout  Digite as arestas no formato vertice1 vertice2 peso  endl;
    for (int i = 0; i  numArestas; ++i) {
        int vertice1, vertice2, peso;
        cin  vertice1  vertice2  peso;
        adicionarAresta(matrizAdjacencia, vertice1, vertice2, peso);
    }

     Executar o algoritmo de Floyd-Warshall
    floydWarshall(matrizAdjacencia);

     Imprimir a matriz de adjacência após a execução do algoritmo de Floyd-Warshall
    cout  Matriz de Adjacência (Menores caminhos)  endl;
    for (int i = 0; i  numVertices; ++i) {
        for (int j = 0; j  numVertices; ++j) {
            if (matrizAdjacencia[i][j] == INT_MAX)
                cout  INF ;
            else
                cout  matrizAdjacencia[i][j]   ;
        }
        cout  endl;
    }

     Exemplo de como imprimir o menor caminho entre dois vértices (0 e 2)
    imprimirMenorCaminho(matrizAdjacencia, 0, 2);

    return 0;
}