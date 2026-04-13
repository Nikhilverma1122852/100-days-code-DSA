#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int visited[26] = {0};

    // Input string
    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if (visited[index] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }

        visited[index] = 1;
    }

    // If no repeated character found
    printf("-1\n");

    return 0;
}