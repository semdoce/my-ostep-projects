#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char *buffer = NULL;
    size_t bufSize = 32; // buffer de 32 bytes
    FILE *arq;

    if(argc < 2)
    { //precisa ter 2 args
      printf("wgrep: searchterm [file ...]\n");
      exit(1);
    } else if(argc == 2)
      {
        while((getline(&buffer, &bufSize, stdin)) != -1)
        {
          if (strstr(buffer, argv[1]) != NULL)
          {
            printf("%s", buffer);
          }
        }
        free(buffer);
      } else
      {
        for(int i = 2; i < argc; i++)
        {
          if ((arq = fopen(argv[i], "r")) == NULL)
          {
            printf("wgrep: cannot open file\n");
            exit(1);
          }
          if(getline(&buffer, &bufSize, arq) == -1)
          {
            printf("wgrep: erro ao buscar a linha");
            exit(1);
          }
          while(!feof(arq))
          {
            if (strstr(buffer, argv[1]) != NULL)
            {

              printf("%s", buffer);
            }
            getline(&buffer, &bufSize, arq);
          }
          free(buffer);
          fclose(arq);
        }
      }

    return 0;
}
//if ((strcmp(buffer, "asdsad\n")) == 0)
//  printf("linha asdsad\n");  buffer => string da linha atual COMPLETA com \n
