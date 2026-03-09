#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Function to insert element
void insert(int value)
{
    int i;

    if(size == MAX)
    {
        printf("Queue Overflow\n");
        return;
    }

    i = size - 1;

    // Shift elements to maintain priority
    while(i >= 0 && pq[i] > value)
    {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = value;
    size++;
}

// Function to delete highest priority element
int delete()
{
    if(size == 0)
        return -1;

    int value = pq[0];

    for(int i = 0; i < size - 1; i++)
        pq[i] = pq[i + 1];

    size--;

    return value;
}

// Function to peek highest priority element
int peek()
{
    if(size == 0)
        return -1;

    return pq[0];
}

int main()
{
    int n, x;
    char op[10];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(op[0] == 'i')   // insert
        {
            scanf("%d", &x);
            insert(x);
        }
        else if(op[0] == 'd')  // delete
        {
            printf("%d\n", delete());
        }
        else if(op[0] == 'p')  // peek
        {
            printf("%d\n", peek());
        }
    }

    return 0;
}