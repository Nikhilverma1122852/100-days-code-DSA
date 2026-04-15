#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Enter number of votes: ");
    scanf("%d", &n);

    char names[n][100];

    printf("Enter candidate names:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    int maxVotes = 0;
    char winner[100] = "";

    for (int i = 0; i < n; i++) {
        int count = 0;

        // Count frequency of names[i]
        for (int j = 0; j < n; j++) {
            if (strcmp(names[i], names[j]) == 0) {
                count++;
            }
        }

        // Update winner
        if (count > maxVotes) {
            maxVotes = count;
            strcpy(winner, names[i]);
        } 
        else if (count == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}