#include "main.h"

/**
 * main - Parent pid
 * Return - Success 0
*/

int main(void)
{
pid_t my_papapid;
my_papapid = getpid();
printf("%u\n", my_papapid);
return(0);
}