#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to encrypt the message using Caesar cipher with a given shift
void caesar_encrypt(char *message, int shift)
{
    int i;
    for (i = 0; message[i] != '\0'; i++)
    {
        if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (message[i] - 'A' + shift) % 26 + 'A';
        }
        else if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (message[i] - 'a' + shift) % 26 + 'a';
        }
    }
}

// Function to decrypt the message using Caesar cipher with a given shift
void caesar_decrypt(char *message, int shift)
{
    caesar_encrypt(message, 26 - (shift % 26));  // Ensure the shift is within 0-25
}

int main()
{
    int choice, shift;
    char input_message[MAX_LEN];
    char *encoded_message, *decoded_message;

    while (1)
    {
        printf("\nCaesar Cipher Menu:\n");
        printf("1. Encode\n2. Decode\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear the newline character from the input buffer

        switch (choice)
        {
            case 1:
                printf("Enter the message to encode: ");
                fgets(input_message, MAX_LEN, stdin);
                input_message[strcspn(input_message, "\n")] = '\0';  // Remove trailing newline

                printf("Enter the shift value: ");
                scanf("%d", &shift);

                encoded_message = (char *)malloc((strlen(input_message) + 1) * sizeof(char));
                strcpy(encoded_message, input_message);
                caesar_encrypt(encoded_message, shift);

                printf("Encoded message: %s\n", encoded_message);
                free(encoded_message);  // Free allocated memory
                break;

            case 2:
                printf("Enter the message to decode: ");
                fgets(input_message, MAX_LEN, stdin);
                input_message[strcspn(input_message, "\n")] = '\0';  // Remove trailing newline

                printf("Enter the shift value: ");
                scanf("%d", &shift);

                decoded_message = (char *)malloc((strlen(input_message) + 1) * sizeof(char));
                strcpy(decoded_message, input_message);
                caesar_decrypt(decoded_message, shift);

                printf("Decoded message: %s\n", decoded_message);
                free(decoded_message);  // Free allocated memory
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
