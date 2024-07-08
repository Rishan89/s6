#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NODES 4
#define INF INT_MAX

void printDistanceVector(int dist[NODES][NODES]) {
    for (int i = 0; i < NODES; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < NODES; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

void distanceVectorRouting(int graph[NODES][NODES]) {
    int dist[NODES][NODES];
    
    // Initialize the distance vector with the initial graph values
    for (int i = 0; i < NODES; i++) {
        for (int j = 0; j < NODES; j++) {
            if (graph[i][j] == 0)
                dist[i][j] = INF;
            else
                dist[i][j] = graph[i][j];
        }
        dist[i][i] = 0; // Distance to itself is always zero
    }
    
    // Print initial distance vector
    printf("Initial distance vector:\n");
    printDistanceVector(dist);
    printf("\n");

    int updated;
    do {
        updated = 0;
        // Update the distance vector based on neighbors' information
        for (int i = 0; i < NODES; i++) {
            for (int j = 0; j < NODES; j++) {
                for (int k = 0; k < NODES; k++) {
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        updated = 1;
                    }
                }
            }
        }
    } while (updated);

    // Print final distance vector
    printf("Final distance vector:\n");
    printDistanceVector(dist);
}

int main() {
    // Example graph with 4 nodes
    // The graph is represented as an adjacency matrix
    int graph[NODES][NODES] = {
        {0, 1, 4, INF},
        {1, 0, 2, 6},
        {4, 2, 0, 3},
        {INF, 6, 3, 0}
    };

    distanceVectorRouting(graph);

    return 0;
}
