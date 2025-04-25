#include <stdio.h>
#include <stdlib.h>

#define STRINGSIZE 200 //"Buffer size" (quantidade de caracteres lidos por vez//tamanho da string)

int main(int argc, char const *argv[]) {
  FILE *arq;
  char string[STRINGSIZE];

  for(int i = 1; i < argc; i++){
    if((arq = fopen(argv[i], "r")) == NULL){
      printf("wcat: cannot open file\n"); //Depurando o erro no 6
      exit(1);
    }
    else{
      fgets(string, STRINGSIZE, arq);

      while(!feof(arq)){
        printf("%s", string);
        fgets(string, STRINGSIZE, arq);
      }
      fclose(arq);
    }

  }
  return 0;
}
