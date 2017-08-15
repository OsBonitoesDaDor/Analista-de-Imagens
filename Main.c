#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH "C:\\Temp\\02.ppm"
#define FORMATO "P6"
#define ERRO -1
#define FALSE 0
#define TRUE 1

int init_val(){
    int i = 0, j, k, wdt , hgt, num_linhas = 0, max_cor, pos_pxl = 0, lin = 0, col = 0;
	FILE * fp = NULL;
    char linha[200], pxl_fundo[4], pxl_test[4];
	unsigned char  * * matriz;
	char * bora;

	unsigned char c;

	fp = fopen(PATH, "r");

	if(fp == NULL){
		printf("DEU BO");
		return 0;
	}

	do{
        c = (unsigned char ) fgetc(fp);
        if(num_linhas < 3){
            if(c != '\n'){
                linha[i] = c;
                i++;
            }else{
                linha[i] = '\0';
                switch(num_linhas){
                case 0:
                    if(strcmp(FORMATO, linha) != 0){
                        printf("DEU BO NO FORMATO");
                        return ERRO;
                    }
                    break;
                case 1:
                    wdt = atoi(strtok( linha, " " ) );
                    hgt = atoi(strtok( NULL, " " ) ) ;
                    matriz = (unsigned char * * ) malloc(sizeof(unsigned char *) *  wdt);
                    for(i = 0; i < wdt; i++)
                        matriz[i] = ( unsigned char * ) malloc (sizeof(unsigned char) * hgt);
                    break;
                case 2:
                    max_cor = atoi(linha);
                    break;
                }
                num_linhas++;
                i = 0;
            }
        //Concatena essa porra
        }else{
          //  printf("%s %s\n", pxl_fundo, pxl_test);
          //TODO: mUDAR PARA FSCANF("%C, %C, %C", A, B, C"; APRA LER DE 3 EM 3!!
            if(i < 3){
                pxl_fundo[i] = c;
                i++;
            }else if(j < 3){
                pxl_test[j] = c;
                j++;
            }else{
                if(strcmp(pxl_test, pxl_fundo) == 0){
                    matriz[lin][col] = 0;
                }else{
                    matriz[lin][col] = 1;
                }
                j = 0;
                if(col == hgt){
                    lin++;
                    col = 0;
                }else{
                    col++;
                }

        }
        }
        if(lin == wdt)
            break;
	}while(c != 'EOF' );

	printf("VALORES INICIADS!!\n\n");

	for(i = 0; i < wdt; i ++){
        for(j = 0; j < hgt; j++){
        //printf("%d ", matriz[i][j] -1 );
        }
        //printf("\n");
	}
}

int main(){
    init_val();
}
