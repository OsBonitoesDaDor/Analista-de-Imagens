#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH "C:\\Temp\\10.ppm"
#define FORMATO "P6"
#define ERRO -1
#define FALSE 0
#define TRUE 1
#define FUNDO '0'
#define NAO_FUNDO ' '
int init_val(unsigned char * * matriz, int * width, int * height) {
	int i = 0, j, k, wdt, hgt, num_linhas = 0, max_cor, pos_pxl = 0, lin = 0, col = 0;
	FILE * fp = NULL;
	char linha[200], r_fundo, b_fundo, g_fundo, r_teste, g_teste, b_teste;
	//unsigned char  * * matriz;
	char * bora;

	unsigned char c;

	fp = fopen(PATH, "rb");

	if (fp == NULL) {
		printf("DEU BO");
		return 0;
	}
	do {
		c = (unsigned char)fgetc(fp);
		if (c != '\n') {
			linha[i] = c;
			i++;
		}
		else {
			linha[i] = '\0';
			switch (num_linhas) {
			case 0:
				if (strcmp(FORMATO, linha) != 0) {
					printf("DEU BO NO FORMATO");
					return ERRO;
				}
				break;
			case 1:
				hgt = atoi(strtok(linha, " "));
				wdt = atoi(strtok(NULL, " "));
				matriz = (unsigned char * *)malloc(sizeof(unsigned char *) *  wdt);
				for (i = 0; i < wdt; i++)
					matriz[i] = (unsigned char *)malloc(sizeof(unsigned char) * hgt);
				break;
			case 2:
				max_cor = atoi(linha);
				break;
			}
			num_linhas++;
			i = 0;
		}
	} while (num_linhas < 3);

	printf("A imagem eh %d %d \n", wdt, hgt);

	for (lin = 0; lin < wdt; lin++) {
		for (col = 0; col < hgt; col++) {
			if ((lin == 0) && (col == 0)) {
				fscanf(fp, "%c%c%c", &r_fundo, &g_fundo, &b_fundo);
				matriz[0][0] = FUNDO;
			}
			else
				fscanf(fp, "%c%c%c", &r_teste, &g_teste, &b_teste);

			if ((r_fundo != r_teste) || (g_fundo != g_teste) || (b_fundo != b_teste))
				matriz[lin][col] = NAO_FUNDO;
			else
				matriz[lin][col] = FUNDO;
		}
	}
	matriz[0][0] = FUNDO;

	

	//mat_res = matriz;
	*width = wdt;
	*height = hgt;
}

int main() {
	unsigned char * * matriz = NULL;
	int wdt, hgt, lin, col;
	init_val(matriz, &wdt, &hgt);

	printf("aaaa %d %d \n", wdt, hgt);

	for (lin = 0; lin < wdt; lin++) {
		for (col = 0; col < hgt; col++) {
			printf("%c", matriz[lin][col]);
		}
		printf("\n");
	}

	system("PAUSE");
	return 0;
}
