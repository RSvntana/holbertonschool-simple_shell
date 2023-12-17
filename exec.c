#include "main.h"

/**
 * display_prompt - displays the shells prompt
 * Return: Success (0)
*/

void display_prompt(void)
{
    char user_input[100];  // Assuming input won't exceed 99 characters

    while (1) {
        printf("Simple Shell $ ");
        fgets(user_input, sizeof(user_input), stdin);
        user_input[strcspn(user_input, "\n")] = '\0';  // Remove trailing newline character

        if (strcmp(user_input, "exit") == 0 || strcmp(user_input, "quit") == 0) {
            printf("Exiting the program... Goodbye!\n"); // Exit or quit program options
            break;
    }
}
}
void parse_input(const char *input, ParsedInput *parsed) 
{
   
    strcpy(parsed->command, "");
    parsed->num_args = 0; // Initialize the structure

    
    char *token = strtok((char *)input, " ");// Tokenize the input based on spaces
    
    if (token != NULL) {
        strcpy(parsed->command, token);// Extract the comman
    }


    while (token != NULL) {
        token = strtok(NULL, " ");
        if (token != NULL) {
            strcpy(parsed->arguments[parsed->num_args], token);
            parsed->num_args++;
        }// Extract the arguments
    }
}


 int main()
 {
	 char user_input[MAX_INPUT_LENGTH];
    ParsedInput parsed;
	display_prompt();
	parse_input(user_input, &parsed);
	return (0);
 }