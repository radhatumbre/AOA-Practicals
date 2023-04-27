#include <bits/stdc++.h>

using namespace std;

int minKey(int key[], bool mstSet[], int vert) {
	int min = INT_MAX, min_index;

	for (int v = 0; v < vert; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void printMST(int parent[], int graph[][100], int vert) {
	cout << endl << "Edge\t\tWeight" << endl;
	int mst_wt = 0;
	for (int i = 1; i < vert; i++) {
		cout << parent[i] << " - " << i << "\t\t" << graph[i][parent[i]] << endl;
		mst_wt += graph[i][parent[i]];
    }
	cout << endl << "Weight of MST: " << mst_wt << endl;
}

void primMST(int graph[][100], int vert) {
	int parent[vert], key[vert];
	bool mstSet[vert];

	for (int i = 0; i < vert; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < vert - 1; count++) {
		int u = minKey(key, mstSet, vert);
		mstSet[u] = true;
		for (int v = 0; v < vert; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
				parent[v] = u, key[v] = graph[u][v];
            }
	}

	printMST(parent, graph, vert);
}

int main() {
	int vert, graph[100][100];

    cout << endl << "Enter number of vertices in the graph: ";
    cin >> vert;

    cout << endl << "Enter graph:" << endl << endl;
    for (int i = 0; i < vert; i++) {
        for (int j = 0; j < vert; j++) {
            cin >> graph[i][j];
        }
    }

	primMST(graph, vert);

	cout << endl;

	return 0;
}
