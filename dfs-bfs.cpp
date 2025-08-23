#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Número de nodos en el grafo
const int N = 4;

// Lista de adyacencia
vector<int> grafo[N];

// Agrega una arista no dirigida
void agregarArista(int u, int v) {
    grafo[u].push_back(v);
    grafo[v].push_back(u); // Porque es no dirigido
}

// DFS recursivo. Busqueda profundidad
void dfs(int nodo, vector<bool>& visitado) {
    visitado[nodo] = true;
    cout << nodo << " ";

    for (int vecino : grafo[nodo]) {
        if (!visitado[vecino]) {
            dfs(vecino, visitado);
        }
    }
}

// BFS iterativo. Busqueda por niveles
void bfs(int inicio) {
    vector<bool> visitado(N, false);
    queue<int> cola;

    cola.push(inicio);
    visitado[inicio] = true;

    while (!cola.empty()) {
        int nodo = cola.front();
        cola.pop();
        cout << nodo << " ";

        for (int vecino : grafo[nodo]) {
            if (!visitado[vecino]) {
                visitado[vecino] = true;
                cola.push(vecino);
            }
        }
    }
}

int main() {
    // Crear el grafo
    agregarArista(0, 1);
    agregarArista(0, 2);
    agregarArista(2, 3);

    cout << "Recorrido DFS desde el nodo 0: ";
    vector<bool> visitadoDFS(N, false);
    dfs(0, visitadoDFS);

    cout << "\nRecorrido BFS desde el nodo 0: ";
    bfs(0);

    return 0;
}
