#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wunzip(FILE *file);

int main(int argc, char const *argv[]) {
  if (argc < 2)
  {
    printf("wunzip: file1 [file2 ...]\n");
    exit(1);
  }
  for (int i = 1; i < argc; i++)
  {
    // Opening archive
    char *file_name = (char *)argv[i];
    FILE *f = fopen(file_name, "rb");
    if (!f)
    {
      printf("File name error");
      exit(1);
    }

    // Reading archive bytes
    wunzip(f);
  }
  return 0;
}

int wunzip(FILE *file)
{
  int i = 1;
  int integer, zero_character = 1;
  char charact;
  // will run everytime
  while(zero_character != 0)
  {
    zero_character = fread(&integer, sizeof(int), 1, file);
    //if char is not EOF, then prints
    fread(&charact, sizeof(char), 1, file);
    if(zero_character == 0)
    {
      return i*(sizeof(char)+sizeof(int));
    }
    // printing the character, integer times
    for (int k = 0; k < integer; k++)
    {
      printf("%c", charact);
    }
  }
  // returning total of size in bytes
  return i*(sizeof(char)+sizeof(int));
}
