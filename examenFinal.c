#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MAX_LENGHT 1000



typedef struct {
	char nombre[20];
	int area;
	int cal1;
	int cal2;
} alumno;




int main() {
	char go = '1';
	alumno alumnos[MAX_LENGHT];
	int cont = 0;
	char va = '0';
	char area;
	FILE* archivo;



	while (go == '1') {
		printf("Desea ingresar un alumno nuevo (1 = Si / 0 = No)? ");
		scanf("%c", &go);
		getchar();
		if (go == '1') {
			printf("Ingrese nombre: ");
			scanf("%s", &alumnos[cont].nombre);
			getchar();
			do {
				printf("Ingrese al area (1 = Licenciatura / 2 = Ingenieria) :");
				scanf("%c", &area);
				getchar();
				if (area == '1' || area == '2') {
					alumnos[cont].area = area - '0';
					va = '0';
				}
				else {
					printf("Area invalida.\n");
					va = '1';
				}
			} while (va != '0');

			va = '1';
			while (va != '0') {
				printf("Ingrese la primera calificacion: ");
				if (scanf("%d", &alumnos[cont].cal1) != 1) {
					printf("Calificacion no valida.\n");
					va = '1';
				}
				else {
					if (alumnos[cont].cal1 < 20 || alumnos[cont].cal1 > 100) {
						printf("Calificacion no valida.\n");
						va = '1';
					}
					else {
						va = '0';
					}
				}

				getchar();
			}
			va = '1';
			while (va != '0') {
				printf("Ingrese la segunda calificacion: ");
				if (scanf("%d", &alumnos[cont].cal2) != 1) {
					printf("Calificacion no valida.\n");
					va = '1';
				}
				else {
					if (alumnos[cont].cal2 < 20 || alumnos[cont].cal2 > 100) {
						printf("Calificacion no valida.\n");
						va = '1';
					}
					else {
						va = '0';
					}
				}



				getchar();
			}



			cont++;
			printf("Alumno ingresado.\n");
		}
		else if (go == '0') {
			archivo = fopen("salida.txt", "w");
			if ((archivo != NULL)) {
				fprintf(archivo, "Nombre\tArea\tCalificacion 1\tCalificacion 2\tResultado\n");
				for (int i = 0; i < cont; i++) {
					if (alumnos[i].cal1 > 90 || alumnos[i].cal2 > 90) {
						printf("%d", alumnos[i].area);
						fprintf(archivo, "%s\t%d\t\t%d\t\t%d\tACEPTADO\n", alumnos[i].nombre, alumnos[i].area, alumnos[i].cal1, alumnos[i].cal2);
					}
					else {
						printf("%d", alumnos[i].area);
						fprintf(archivo, "%s\t%d\t\t%d\t\t%d\tRECHAZADO\n", alumnos[i].nombre, alumnos[i].area, alumnos[i].cal1, alumnos[i].cal2);
					}



				}
				fclose(archivo);
			}
			else {
				printf("No se pueden abrir el archivo");
				fclose(archivo);



			}




		}
		else {
			printf("Opcion invalida\n");
			go = '1';
		}





	}
}