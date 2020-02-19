#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHARS 30

int main (void) {
	char inText [MAX_CHARS]; 
	unsigned d; 
	unsigned m; 
	unsigned a; 
	char c = 'S'; 
	char *meses[13] = {
		"0","Enero","Febrero","Marzo","Abril",
		"Mayo","Junio","Julio","Agosto",
		"Septiembre","Octubre","Noviembre","Diciembre"
	};
	int mes;
	int year;
	int dia;
	int count = 0; 	

	while(c == 'S'){
		puts("Introduce la fecha con formato dd/mm/aa: ");
		if(fgets(inText, MAX_CHARS, stdin) != NULL){
			if(sscanf(inText, "%2u/%2u/%4u", &d, &m, &a) == 3){
				year = (int) a;
				dia = (int) d; 
				mes = (int) m;  
				while(year != 0){
					year /=10;
					++count; 
				}
				if(dia < 1 || dia > 31){
					puts("El dia que ingreso no existe.");
					c = 'S'; 
				}else{
					if(count<4){
						puts("No se escribio el año de manera correcta."); 
						c = 'S';
					}else{
						if(mes == 2 && dia > 29){
							puts("Febrero no puede tener mas de 29 dias");
							c = 'S'; 
						}else{						
							if(mes > 12 || mes < 1){
								puts("El mes que ingreso no existe.");
								c = 'S'; 
							}else{
								printf("Fecha: %u de %s de %u\n", d, meses[mes], a);
								printf("¿Desea hacerlo de nuevo (S/N)? "); 
								scanf("%c", &c);
								getchar(); 
							}
						}
					}
				}
			}else{
				printf("No se escribio la fecha en el formato correcto.");
				printf("¿Desea intentarlo de nuevo (S/N)? "); 
				scanf("%c", &c); 
				getchar(); 
			}
		}else{
			printf("La fecha no se pudo procesar.");
		}
	}
}