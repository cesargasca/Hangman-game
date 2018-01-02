#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*void imprimeMONO(char **m){

  for(f=0; f<3; f++)
	{
	for(c=0; c<3; c++)
		{
		printf(" %c", m[f][c]);
		printf("\n");
		}
	}
}*/


void dibuja(int n){
  int f,c;
  char mono[3][3];
  mono[0][0] = ' ';
  mono[0][2] = ' ';
  if(n == 5){
    mono[0][1] = 'o';
    mono[1][0] = ' ';
    mono[1][1] = ' ';
    mono[1][2] = ' ';
    mono[2][0] = ' ';
    mono[2][2] = ' ';
    //imprimeMONO(mono);
  }
  if(n == 4){
    mono[0][1] = 'o';
    mono[1][0] = '-';
    mono[1][1] = ' ';
    mono[1][2] = ' ';
    mono[2][0] = ' ';
    mono[2][2] = ' ';
    //imprimeMONO(mono);
  }
  if(n == 3){
    mono[0][1] = 'o';
    mono[1][0] = '-';
    mono[1][1] = '|';
    mono[1][2] = ' ';
    mono[2][0] = ' ';
    mono[2][2] = ' ';
    //imprimeMONO(mono);
  }
  if(n == 2){
    mono[0][1] = 'o';
    mono[1][0] = '-';
    mono[1][1] = '|';
    mono[1][2] = '-';
    mono[2][0] = ' ';
    mono[2][2] = ' ';
    //imprimeMONO(mono);
  }
  if(n == 1){
    mono[0][1] = 'o';
    mono[1][0] = '-';
    mono[1][1] = '|';
    mono[1][2] = '-';
    mono[2][0] = '/';
    mono[2][2] = ' ';
    //imprimeMONO(mono);
  }
  if(n == 0){
    mono[0][1] = 'o';
    mono[1][0] = '-';
    mono[1][1] = '|';
    mono[1][2] = '-';
    mono[2][0] = '/';
    mono[2][2] = 92;
    //imprimeMONO(mono);
  }
  for(f=0; f<3; f++)
  {
  for(c=0; c<3; c++)
    {
    printf(" %c", mono[f][c]);
    }
    printf("\n");
  }
}
void cambiaPorAsteriscos(char *a,char *new){
  int i;
  for(i = 0 ; i < strlen(a) ; i++){
    new[i] = '*';
    printf("*");
  }
  new[strlen(a)] = '\0';
  printf("\n");
}


void LeeLetra(char letra,char *a){
  int i;
  for(i = 0 ; i < strlen(a) ; i++){
    if(a[i] == letra){
      printf(" %c",a[i]);
    }
    else{
      printf("*");
    }
  }
  printf("\n");
}

int juega(char *a,char *aconastericos,int intentos){
  int i;
  char letra;
  int bandera = 0;

  if(intentos < 6){
            printf("\ndame una letra: ");
            scanf("%s", &letra);
            printf("\ningresaste la letra: %c\n",letra);
            for(i = 0 ; i < strlen(a) ; i++){
              if(a[i] == letra){
                aconastericos[i] = letra;
                bandera = 1;
                if(intentos > 0){
                dibuja(6-intentos);
                }
              }
            }
            if(bandera == 0){
              intentos++;
              printf("te quedan %d\n", (6-(intentos)) );
              dibuja(6-intentos);
            }
  }
  else{
    printf("\nPerdiste bruh!\n");
    return 0;
  }
  if(strcmp(a,aconastericos) == 0){
    printf("YA GANASTE, PERRO\n");
    return 0;
  }
  printf("asi nomas quedo  %s",aconastericos);
  return juega(a,aconastericos,intentos);
}

int main(){
  int intentos = 0;
  int r = rand() % 3;
  char a[10][10];
  char aconastericos[strlen(a[0])];
  char letra;
  strcpy(a[0], "cesar");
  strcpy(a[1], "eduardo");
  strcpy(a[2], "gasca");
  strcpy(a[3], "sanchez");
  strcpy(a[4], "spanky");

  cambiaPorAsteriscos(a[4],aconastericos);
  printf("m------> %s",aconastericos),
  juega(a[4],aconastericos,intentos);
  return 0;
}
