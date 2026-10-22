#include <iostream>
#include <climits>
using namespace std;

const int N = 4;

void prim(int graph[N][N]) {
    int parent[N];
    int key[N];
    bool mst[N] = {false};

    for (int i = 0; i < N; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < N; count++) {
        int u = -1;

        for (int v = 0; v < N; v++) {
            if (!mst[v] &&
                (u == -1 || key[v] < key[u]))
                u = v;
        }

        if (u == -1 || key[u] == INT_MAX) {
            cout << "Graph is disconnected.\n";
            return;
        }

        mst[u] = true;

        for (int v = 0; v < N; v++) {
            if (graph[u][v] != 0 && !mst[v] &&
                graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;
    cout << "Road\tCost\n";

    for (int i = 1; i < N; i++) {
        cout << parent[i] + 1 << " - " << i + 1
             << "\t" << key[i] << endl;
        total += key[i];
    }

    cout << "Minimum total cost = " << total << endl;
}

int main() {
    int graph[N][N] = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}
    };

    prim(graph);
    return 0;
}
