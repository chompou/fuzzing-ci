#include "utility.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *test = charEncode("lik input men der &, < og > er erstattet");
  printf("%s\n", test);
}
