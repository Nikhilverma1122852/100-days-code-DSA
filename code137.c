#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list node
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Structure for graph
typedef struct {
    Node* head[MAX];
} Graph;

// Structure for min heap node
typedef struct {
    int vertex;
    int dist;
} HeapNode;

// Min Heap structure
typedef struct {
    int size;
    int pos[MAX];
    HeapNode* array[MAX];
} MinHeap;

// Create new adjacency node
Node* newNode(int v, int w) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->weight = w;
    node->next = NULL;
    return node;
}

// Create graph
Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < MAX; i++)
        graph->head[i] = NULL;
    return graph;
}

// Add edge
void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* node = newNode(dest, weight);
    node->next = graph->head[src];
    graph->head[src] = node;
}

// Create min heap node
HeapNode* newHeapNode(int v, int dist) {
    HeapNode* node = (HeapNode*)malloc(sizeof(HeapNode));
    node->vertex = v;
    node->dist = dist;
    return node;
}

// Swap heap nodes
void swapHeapNode(HeapNode** a, HeapNode** b) {
    HeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify
void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->dist < heap->array[smallest]->dist)
        smallest = left;

    if (right < heap->size && heap->array[right]->dist < heap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        HeapNode* smallestNode = heap->array[smallest];
        HeapNode* idxNode = heap->array[idx];

        heap->pos[smallestNode->vertex] = idx;
        heap->pos[idxNode->vertex] = smallest;

        swapHeapNode(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

// Check if heap empty
int isEmpty(MinHeap* heap) {
    return heap->size == 0;
}

// Extract min node
HeapNode* extractMin(MinHeap* heap) {
    if (isEmpty(heap))
        return NULL;

    HeapNode* root = heap->array[0];
    HeapNode* last = heap->array[heap->size - 1];

    heap->array[0] = last;

    heap->pos[root->vertex] = heap->size - 1;
    heap->pos[last->vertex] = 0;

    heap->size--;
    minHeapify(heap, 0);

    return root;
}

// Decrease key
void decreaseKey(MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i]->dist = dist;

    while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist) {
        heap->pos[heap->array[i]->vertex] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->vertex] = i;
        swapHeapNode(&heap->array[i], &heap->array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

// Check if vertex is in heap
int isInMinHeap(MinHeap *heap, int v) {
    return heap->pos[v] < heap->size;
}

// Dijkstra algorithm
void dijkstra(Graph* graph, int V, int src) {
    int dist[MAX];

    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));

    heap->size = V;

    for (int v = 0; v < V; v++) {
        dist[v] = INT_MAX;
        heap->array[v] = newHeapNode(v, dist[v]);
        heap->pos[v] = v;
    }

    dist[src] = 0;
    decreaseKey(heap, src, 0);

    while (!isEmpty(heap)) {
        HeapNode* minNode = extractMin(heap);
        int u = minNode->vertex;

        Node* crawl = graph->head[u];
        while (crawl != NULL) {
            int v = crawl->vertex;

            if (isInMinHeap(heap, v) && dist[u] != INT_MAX &&
                crawl->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + crawl->weight;
                decreaseKey(heap, v, dist[v]);
            }
            crawl = crawl->next;
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

// Main function
int main() {
    int V = 5;
    Graph* graph = createGraph();

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 0, 7);
    addEdge(graph, 3, 2, 6);
    addEdge(graph, 4, 1, 3);
    addEdge(graph, 4, 2, 9);
    addEdge(graph, 4, 3, 2);

    dijkstra(graph, V, 0);

    return 0;
}