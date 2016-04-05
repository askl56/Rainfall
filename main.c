typedef int bool;
#define true 1
#define false 0

#include <stdlib.h>
#include <stdio.h>

bool validateInput(int argCount) {
  if (argCount > 100) {
    printf("Input greater than 100. Bailing.\n");
    return false;
  } else if (argCount == 0) {
    printf("Input empty. Bailing.\n");
    return false;
  }

  return true;
}

int main(int argc, char *argv[]) {
  if (!validateInput(argc)) {
    return 0;
  }

  int heightCount = argc - 1;
  int heights[heightCount];

  for (int i = 0; i < heightCount; i++) {
    heights[i] = atoi(argv[i + 1]);
  }

  int cliff = 0;
  int volume = 0;
  bool counting = false;

  for (int i = 0; i < heightCount; i++) {
    if (i == 0) {
      continue;
    }

    int previous = heights[i - 1];
    int current = heights[i];

    if (previous > current && !counting) {
      counting = true;
      cliff = previous;
    }

    if (counting) {
      if (cliff > current && i != heightCount - 1) {
        volume += cliff - current;
      } else {
        counting = false;
      }
    }
  }

  printf("%i", volume);
  return 0;
}
