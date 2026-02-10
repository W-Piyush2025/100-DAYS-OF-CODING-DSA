#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    // Read input string
    scanf("%s", str);

    int length = strlen(str);
    
    // Reverse the string in-place
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }

    // Print the mirrored output
    printf("%s\n", str);

    return 0;
}