#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 25000

int main(int argc, char **argv) {

  int ret;
  FILE *fp;

  if (argc < 2) {
    printf("usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  char buf[BUFFSIZE];
  ret = fread(buf, sizeof(char), BUFFSIZE, fp);
  fclose(fp);

  if (ret > 0) {
    printf("got %d bytes:\n", ret);
  } else {
    printf("\n!!read failed!!\n");
  }

  return 0;
}
