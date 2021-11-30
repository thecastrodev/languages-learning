#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"

char** mapa;
int colunas;
int linhas;

void liberamapa() {
  for (int i = 0; i < linhas; i++) {
    free(mapa[i]);
  }
  free(mapa);
}

void alocamapa() {
  mapa = malloc(sizeof(char*) * linhas);
  for (int i = 0; i < linhas; i++) {
    mapa[i] = malloc(sizeof(char) * (colunas + 1));
  }
}

void lemapa() {
  FILE* f;
  f = fopen("mapa.txt", "r");
  if (f == 0) {
    printf("Erro na leitura do mapa\n");
    exit(1);
  }

  fscanf(f, "%d %d", &linhas, &colunas);

  alocamapa();

  for (int i = 0; i < linhas; i++) {
    fscanf(f, "%s", mapa[i]);
  }

  fclose(f);
}

int acabou() {
  return 0;
}

void imprimemapa() {
  for (int i = 0; i < linhas; i++) {
    printf("%s\n", mapa[i]);
  }
}

void move (char direcao) {
  int x, y;

  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      if (mapa[i][j] == '@') {
        x = i;
        y = j;
        break;
      }   
    }
    
    switch (direcao) {
    case 'a':
      mapa[x][y-1] = '@';
      break;
    case 'w':
      mapa[x-1][y] = '@';
      break;
    case 'd':
      mapa[x][y+1] = '@';
      break;
    case 's':
      mapa[x+1][y] = '@';
      break;
    }

    mapa[x][y] = '.';

    printf("%c %c\n", x, y);
  }
}

int main() {
  lemapa();

  do {
    imprimemapa();

    char comando;
    scanf(" %c", &comando);
    move(comando);

  } while ( !(acabou()) );

  liberamapa();
  
  // system("pause");
  return 0;
}