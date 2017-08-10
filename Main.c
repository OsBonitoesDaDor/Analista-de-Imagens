#include <stdio.h>
#include <stdlib.h>


#define PATH "C:\\Temp\\05.ppm"


int main(){
	//INVERTER LARGURA POR ALTURA!!!!!
	int i, j, k, wdt = 69 , hgt = 52 *3;
	FILE * fp = NULL;
	
	unsigned char  * * matriz;
	char * bora;
	
	unsigned char c;
	
	fp = fopen(PATH, "r");
	
	if(fp == NULL){
		printf("DEU BO");
		return 0;
	}	

	//Malloca a matriz
	matriz = (unsigned char * * ) malloc(sizeof(unsigned char *) *  wdt);
	for(i = 0; i < wdt; i++){
		matriz[i] = ( unsigned char * ) malloc (sizeof(unsigned char) * hgt);
	} 
	//Passa do arquivo para oa matriz
	for(i = 0; i < wdt; i++){
		for(j = 0; j < hgt; j++){
			printf("%d ", i*wdt + j);
			matriz[i][j] = (unsigned char )fgetc(fp);
		}
	}
		printf("\n");
		printf("\n");
		
	//Printa a matrixz
	for(i = 0; i < wdt; i++){
		for(j = 0; j < hgt; j++){
			
			printf("%c ",  matriz[i][j] -1);
		}
		printf("\n");
	}


	system("PAUSE");
	return 0;

}
