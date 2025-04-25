#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// escrevi partes em ingles pra acostumar com a prática
// i wrote some comments english to get used with
int main(int argc, char const *argv[]) {
  int count = 1;
  char proxLetra = 0;
  char letra;
  if (argc < 2)
  {
    fprintf(stdout, "wzip: file1 [file2 ...]\n");
    exit(1);
  }
  for(int j = 1; j < argc; j++)
  {
    FILE *arq = fopen(argv[j], "r");
    if(arq == NULL)
    {
      printf("wzip: cannot reach file\n");
      exit(1);
    }

    while (fread(&letra, sizeof(char), 1, arq) == 1)
    {
      if (proxLetra == 0) // da 1° vez é diferente, depois checa igualdade
      {
        proxLetra = letra;
        count = 1;
      }
      else if (letra == proxLetra) //equals to letra
      {
        count++;
      } else
      //proxLetra is different to letra
      //if (proxLetra == letra), the result never gets printed
      {
        fwrite(&count, sizeof(int), 1, stdout);
        fwrite(&proxLetra, sizeof(char), 1, stdout);
        proxLetra = letra;
        count = 1;
      }
    }
  }
  // while (fread) == 0, but letra still have a value
  if (letra != '\0')
  {
    fwrite(&count, sizeof(int), 1, stdout);
    fwrite(&proxLetra, sizeof(char), 1, stdout);
  }
  return 0;
}
