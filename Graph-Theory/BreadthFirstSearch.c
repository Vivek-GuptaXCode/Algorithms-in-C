#include <stdio.h>
#include <stdlib.h>

#define MaxVertices 100

// Function prototype
void BreadthFirstSearch(int adjacency[MaxVertices][MaxVertices], int visited[MaxVertices], int vertices, int startVertex);

int main()
{
    int vertices, i, j;
    char ch;
    
    // Number of vertices in the graph
    printf("Enter the number of vertices : ");
    scanf("%d", &vertices);
    
    int adjacency[vertices][vertices], visited[vertices];
    
    // Initializing the visited array
    for (i = 0; i < vertices; i++)
        visited[i] = 0;
    
    // Creating adjacency matrix
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            printf("Is there any edge between %d and %d (y/n) : ", i, j);
            scanf(" %c", &ch); // added space before %c to consume newline
            adjacency[i][j] = (ch == 'y') ? 1 : 0;
        }
    }
    
    // Performing Breadth First search from each vertex
    for (i = 0; i < vertices; i++) {
        if (!visited[i]) {
            BreadthFirstSearch(adjacency, visited, vertices, i);
        }
    }

    return 0;
}

// Breadth-First Search function
void BreadthFirstSearch(int adjacency[MaxVertices][MaxVertices], int visited[MaxVertices], int vertices, int startVertex)
{
    int queue[MaxVertices], front = 0, rear = -1;
    
    // Enqueue the starting vertex
    queue[++rear] = startVertex;
    visited[startVertex] = 1;
    
    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("Visited Vertex: %d\n", currentVertex);
        
        // Explore adjacent vertices
        for (int i = 0; i < vertices; i++) {
            if (adjacency[currentVertex][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}
