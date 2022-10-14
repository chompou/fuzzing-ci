#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replaceCharV2(char *message, char searchFor, char *replaceWith) {
  int length = (int)strlen(message);
  int replaceLength = (int)strlen(replaceWith);

  int numReplacements = 0;
  for (int i = 0; i < length; i++) {
    if (message[i] == searchFor) {
      numReplacements++;
    }
  }

  char *outString = malloc(length + (replaceLength - 1) * numReplacements);

  int index = 0;
  for (int i = 0; i < length; i++) {
    if (message[i] == searchFor) {
      for (int j = 0; j < replaceLength; j++) {
        outString[index] = replaceWith[j];
        index++;
      }
    } else {
      outString[index] = message[i];
      index++;
    }
  }
  return outString;
}

char *charEncode(char *message) {
  char *v1 = replaceCharV2(message, '&', "&amp");
  char *v2 = replaceCharV2(v1, '<', "&lt");
  char *v3 = replaceCharV2(v2, '>', "&gt");
  char *out = NULL;
  out = malloc((int)strlen(v3));
  strcpy(out, v3);
  return out;
}
