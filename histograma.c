#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ESPACIO		' '
#define SALTO_DE_LINEA 	'\n'
#define TAB		'\t'

#define N_CUADRADOS 	80
			
#define COLOR_VERDE 	"\x1b[32m"
#define RESET_COLOR 	"\x1b[0m"

/*	
 *	Funcion usada para duplicar el array i de tamano tam
 */
int* dup(int i[], int tam);


int main(){

	int tam = 2;
    	int* array = malloc(tam * sizeof(int));
	
	char c = getchar();
	bool anteriorFin = true;
	int counter = 0;
	int maxCounter = 0;
	while(c != EOF){
		bool finPalabra = (c==ESPACIO || c=='\n' || c=='\t');
		if(finPalabra && !anteriorFin){
			while(counter >= tam){
				array = dup(array,tam);
				tam *= 2;
			}
			array[counter]++;
			if(array[counter] > maxCounter){ maxCounter = array[counter]; }
			counter = 0;
		}else{
			counter ++;
		}
		anteriorFin = finPalabra;
		c = getchar();
	}
	double escala = (double) N_CUADRADOS / maxCounter;

	printf("Escala aplicada : 1 cuadrado == %f palabras\n",(1/escala));
	for(int i = 1; i < tam; i++){
		if(array[i] == 0) continue;
		if(array[i] == maxCounter) printf(COLOR_VERDE);
		printf("Palabras Longitud %2d : ",i);
		for(int j = 0; j < N_CUADRADOS; j++){
			if(escala*array[i] <= j){
				printf(" ");
			}else{
				printf("▆");
			}
		}
		printf("\t%d\n" RESET_COLOR,array[i]);
	}
	return 0;
}

int* dup(int i[], int tam) {
    int* ret = malloc(tam * 2 * sizeof(int));
    for (int j = 0; j < tam; j++) {
        ret[j] = i[j];
    }
    free(i);
    return ret;
}
