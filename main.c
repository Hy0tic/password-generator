#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random password
void generatePassword(int length) {
    // Possible password characters
    const char charset[] = "abcdefghijklmnopqrstuvwxyz"
                           "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                           "0123456789"
                           "!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?";
    int charsetSize = sizeof(charset) - 1;

    // Seed for random number generator
    srand(time(NULL)); 

    // Allocate memory for password
    char *password = malloc(length + 1);

    if (password) {
        // Generate a random password
        for (int i = 0; i < length; i++) {
            int key = rand() % charsetSize;
            password[i] = charset[key];
        }

        password[length] = '\0'; // Null-terminate the password

        // Print the password
        printf("Generated Password: %s\n", password);

        // Free allocated memory
        free(password);
    } else {
        printf("Memory allocation failed!\n");
    }
}

int main() {
    int length;
    printf("Enter the desired length of the password: ");
    scanf("%d", &length);

    generatePassword(length);

    return 0;
}
