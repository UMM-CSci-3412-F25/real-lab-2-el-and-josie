#include <stdio.h>
#include <stdlib.h>

#include "disemvowel.h"

int main(int argc, char *argv[]) {
  char *line;
  char *answer;
  size_t size;
  
  size = 100;
  line = (char*) calloc ((size + 1), sizeof(char));

  while (getline(&line, &size, stdin) > 0) {
    answer = disemvowel(line);
    printf("%s\n", answer);
    free(answer);
  }

  free(line);
}
