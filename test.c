#include <stdio.h>
#include <string.h>

int main() {
    const char *str = "Hello, World!";
    const char *reject = " ,!";  // Characters to reject

    size_t length = strcspn(str, reject);

    printf("Length of initial segment without characters from reject set: %zu\n", length);

    return 0;
}
