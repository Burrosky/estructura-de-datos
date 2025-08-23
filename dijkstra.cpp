#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
#include <algorithm> // para reverse

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int origen, const vector<vector<pair<int, int>>>& grafo, vector<int>& distancias, vector<int>& previo) {
    int n = grafo.size();
    distancias.assign(n, INF);
    previo.assign(n, -1); // ← Inicializa el vector de padres
    distancias[origen] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, origen });

    while (!pq.empty()) {
        int distancia_actual = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (distancia_actual > distancias[u]) continue;

        for (const auto& vecino : grafo[u]) {
            int v = vecino.first;
            int peso = vecino.second;

            if (distancias[u] + peso < distancias[v]) {
                distancias[v] = distancias[u] + peso;
                previo[v] = u; // ← Guardamos de dónde venimos
                pq.push({ distancias[v], v });
            }
        }
    }
}

// Función para reconstruir el camino desde origen hasta destino
vector<int> reconstruir_camino(int destino, const vector<int>& previo) {
    vector<int> camino;
    for (int at = destino; at != -1; at = previo[at]) {
        camino.push_back(at);
    }
    reverse(camino.begin(), camino.end());
    return camino;
}

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> grafo(n);

    grafo[0].push_back({ 1, 10 });
    grafo[0].push_back({ 2, 3 });
    grafo[1].push_back({ 2, 1 });
    grafo[1].push_back({ 3, 2 });
    grafo[2].push_back({ 1, 4 });
    grafo[2].push_back({ 3, 8 });
    grafo[2].push_back({ 4, 2 });
    grafo[3].push_back({ 4, 7 });
    grafo[4].push_back({ 3, 9 });

    vector<int> distancias, previo;
    int origen = 0;
    dijkstra(origen, grafo, distancias, previo);

    cout << "Distancias desde el nodo " << origen << ":\n";
    for (int i = 0; i < distancias.size(); ++i) {
        cout << "Nodo " << i << ": ";
        if (distancias[i] == INF) cout << "INF";
        else cout << distancias[i];
        cout << "\n";
    }

    // 🔁 Ejemplo de reconstrucción del camino al nodo 4
    int destino = 3;
    if (distancias[destino] == INF) {
        cout << "No hay camino al nodo " << destino << ".\n";
    }
    else {
        vector<int> camino = reconstruir_camino(destino, previo);
        cout << "Camino mas corto desde " << origen << " hasta " << destino << ": ";
        for (int nodo : camino) {
            cout << nodo << " ";
        }
        cout << "\n";
    }

    return 0;
}
