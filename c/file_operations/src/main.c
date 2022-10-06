// #include "main.h"
#include <stdio.h>

/* file modes
**
**  r    opens existed file for reading
**  w    for writing if file not exist create new
**  a    for appending if file not exists create new
**  r+   for both reading and writing
**  w+   for both reading and writing if file exists
**       \ truncates to zero lenght if not create new
**  a+   for both reading and appending if file not exist create new
*/

int read_file_fgetc() {
  // int fgetc(FILE * fp);
  FILE *fp;
  fp = fopen("/tmp/test.txt", "r");
  if (fp == NULL)
    return 0;

  do {
    // Taking input single character at a time
    char c = fgetc(fp);

    // Checking for end of file
    if (feof(fp))
      break;

    printf("%c", c);
  } while (1);

  fclose(fp);
  return 0;
}

int write_file() {
  FILE *fp;

  fp = fopen("/tmp/test.txt", "w+");
  fprintf(fp, "This is testing for fprintf...\n");
  fputs("This is testing for fputs...\n", fp);
  fclose(fp);

  return 0;
}

int read_file() {
  FILE *fp;
  char buff[255];

  fp = fopen("/tmp/test.txt", "r");

  fscanf(fp, "%s", buff);
  printf("1: %s\n", buff);

  // char *fgets( char *buf, int n, FILE *fp );
  // fgets reads up to n-1 characters from file \
  // \ to buff array and appending null character
  // \ to terminate string
  //
  fgets(buff, 255, (FILE *)fp);
  printf("2: %s\n", buff);

  fgets(buff, 255, (FILE *)fp);
  printf("3: %s\n", buff);
  fclose(fp);

  return 0;
}
int main(int argc, char *argv[]) {

  printf("file write\n");
  write_file();
  printf("file read\n");
  read_file();
  printf("file read with fgetc\n");
  read_file_fgetc();
  return 0;
}
