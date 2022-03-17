#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// Number of vertices in the graph
#define Vertices 4

/* Defining Infinite as a large enough value.This value will be used for
vertices not connected to each other */
#define INF 100000


void Print(int dist[][Vertices]);

// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall(int graph[][Vertices])
{
    /* dist[][] will be the output matrix
    that will finally have the shortest
    distances between every pair of vertices */
    int dist[Vertices][Vertices], i, j, k;

    for (i = 0; i < Vertices; i++)
        for (j = 0; j < Vertices; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < Vertices; k++)
    {
        for (i = 0; i < Vertices; i++)
        {
            for (j = 0; j < Vertices; j++) 
            {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    Print(dist);
}

void Print(int dist[][Vertices])
{
    cout << "The following matrix shows the shortest distances between every pair of vertices \n";
    for (int i = 0; i < Vertices; i++) {
        for (int j = 0; j < Vertices; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF"
                << "     ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}

int main()
{
    int graph[Vertices][Vertices] = { { 0, 5, INF, 10 },
                        { INF, 20, 3, INF},
                        { 60, INF, 0, 1},
                        { INF, INF, INF, 9},
    };

    floydWarshall(graph);
    return 0;
}