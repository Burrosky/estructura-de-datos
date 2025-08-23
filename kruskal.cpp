#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar una arista
struct Edge {
    int u, v, weight;

    // Para ordenar por peso
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Estructura de Disjoint Set Union (Union-Find)
struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        // Inicializar cada nodo como su propio padre
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // Encuentra la raíz con compresión de caminos
    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Une dos conjuntos por rango
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return false; // Ya están conectados

        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        return true;
    }

    // Función para imprimir parent y rank
    void dump(int step = -1) {
        if (step >= 0)
            cout << "\n--- Estado después del paso " << step << " ---\n";
        else
            cout << "\n--- Estado del DSU ---\n";

        cout << "parent: ";
        for (int i = 0; i < parent.size(); ++i)
            cout << parent[i] << " ";
        cout << "\nrank:   ";
        for (int i = 0; i < rank.size(); ++i)
            cout << rank[i] << " ";
        cout << "\n";
    }
};

// Función de Kruskal
int kruskal(int n, vector<Edge>& edges, vector<Edge>& mst) {
    sort(edges.begin(), edges.end()); // Ordenar por peso
    DSU dsu(n);

    int totalCost = 0;
    int step = 1;

    for (const Edge& edge : edges) {
        cout << "\n== Paso " << step << ": Intentando unir "
            << char('A' + edge.u) << " - " << char('A' + edge.v)
            << " (peso: " << edge.weight << ") ==" << endl;

        if (dsu.unite(edge.u, edge.v)) {
            cout << "✔ Arista añadida al árbol." << endl;
            mst.push_back(edge);
            totalCost += edge.weight;
        }
        else {
            cout << "✘ Arista descartada (ciclo detectado)." << endl;
        }

        dsu.dump(step);
        ++step;
    }

    return totalCost;
}

int main() {
    int n = 6; // Número de nodos (A-F)
    vector<Edge> edges = {
        {0, 1, 4}, // A-B
        {0, 2, 1}, // A-C
        {1, 2, 3}, // B-C
        {1, 3, 2}, // B-D
        {2, 3, 4}, // C-D
        {3, 4, 2}, // D-E
        {4, 5, 3}, // E-F
        {3, 5, 5}  // D-F
    };

    vector<Edge> mst;
    int cost = kruskal(n, edges, mst);

    cout << "\nAristas del Árbol de Expansión Mínima:\n";
    for (const Edge& e : mst)
        cout << char('A' + e.u) << " - " << char('A' + e.v) << " : " << e.weight << endl;

    cout << "Costo total: " << cost << endl;

    return 0;
}
