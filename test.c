#include <stdio.h>
#include <string.h>

void read_input() {
    char user_input[100];  // Assuming input won't exceed 99 characters

    while (1) {
        printf("Enter something (type 'exit' to quit): ");
        fgets(user_input, sizeof(user_input), stdin);
        user_input[strcspn(user_input, "\n")] = '\0';  // Remove trailing newline character

        if (strcmp(user_input, "exit") == 0 || strcmp(user_input, "quit") == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("You entered: %s\n", user_input);
        }
    }
}

int main() {
    read_input();
    return 0;
}