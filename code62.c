#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10000

bool isValid(char* s) {
    char stack[MAX];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {

        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        }
        else {
            if (top == -1) {
                return false;  
            }

            char topChar = stack[top--];

            if ((s[i] == ')' && topChar != '(') ||
                (s[i] == '}' && topChar != '{') ||
                (s[i] == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    return top == -1;
}

int main() {
    char s[MAX];

    printf("Enter string: ");
    scanf("%s", s);

    if (isValid(s)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}