#include<stdio.h>
#define MaxVertices 100

// Function prototype
void DepthFirstSearch(int adjacency[MaxVertices][MaxVertices], int visited[MaxVertices], int vertices, int vertex);

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
    // Performing Depth First search from each vertex
    for (i = 0; i < vertices; i++) {
        if (!visited[i]) {
            printf("\nDFS starting from vertex %d\n", i);
            DepthFirstSearch(adjacency, visited, vertices, i);
        }
    }

    return 0;
}

// Depth-First Search function
void DepthFirstSearch(int adjacency[MaxVertices][MaxVertices], int visited[MaxVertices], int vertices, int vertex)
{
    printf("Visited Vertex : %d\n", vertex);
    visited[vertex] = 1;
    for (int i = 0; i < vertices; i++)
    {
        if (adjacency[vertex][i] == 1 && visited[i] == 0)
        {
            DepthFirstSearch(adjacency, visited, vertices, i);
        }
    }
}