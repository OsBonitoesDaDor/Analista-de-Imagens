#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH "C:\\Users\\pastre-windows\\Dropbox\\PUCPR\\2017\\Segundo Semestre\\Estrutura de Dados\\Ima\\PacoteImagens1\\07.ppm"
#define FORMATO "P6"
#define ERRO -1
#define FALSE 0
#define TRUE 1
#define FUNDO '0'
#define NAO_FUNDO ' '
#define VISITADO 1


void push(NODE * , int[]);

typedef struct node_{
    int pos[2];
    struct * node next;
} NODE;


void push(NODE  * , int[]) ;
void pop(NODE * );

unsigned char * * init_val( int * width, int * height) {
	int i = 0, j, k, wdt, hgt, num_linhas = 0, max_cor, pos_pxl = 0, lin = 0, col = 0;
	FILE * fp = NULL;
	char linha[200], r_fundo, b_fundo, g_fundo, r_teste, g_teste, b_teste;
	unsigned char * * matriz;
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

	*width = wdt;
	*height = hgt;
	return matriz;
}

void conta_imagens(unsigned char * * matriz, int wdt, int hgt, NODE * pilha){

}

int main() {
	unsigned char * * matriz = NULL;
	int wdt, hgt, lin, col;
	matriz = init_val(&wdt, &hgt);
	for (lin = 0; lin < wdt; lin++) {
		for (col = 0; col < hgt; col++) {
			printf("%c", matriz[lin][col]);
		}
		printf("\n");
	}

	NODE * topo =  NULL;

    system("PAUSE");
	return 0;
}



void push(NODE* topo, int val[]) {
    NODE * novo  = (NODE * )malloc(sizeof(NODE *));
    
    novo ->pos[0] = val[0];
    novo ->pos[1] = val[1];
    novo -> next = topo;
    topo = novo; 
}

int pop(NODE * topo)[]{
    int ret[2];
    NODE * to_free;
    if(topo == NULL)return ERRO;
    to_free = topo;
    ret[0] = to_free ->pos[0]
    ret[1] = to_free->pos
    topo = topo ->next;
    free(to_free);
    return ret;
}




