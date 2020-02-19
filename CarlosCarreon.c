#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGHT 1000
int alumno[MAX_LENGHT][3];
int cont, size;
void capturar();
void listar();
int modificar();
void clasificar();

int main() {
	int mat = 0, x;
	float promedio;
	char go = '1';
	int grado;

	cont = -1;
	size = 0;

	while (go == '1') {
		system("cls");
		
		printf("\n1. Captura\n2. Listar\n3. Modificar\n4. Clasificar\n5. Salir\n");
		printf("Seleccione una opcion del menu: ");
		scanf("%c", &go);
		getchar();
		switch (go) {
			case '1':
				capturar();
				break;
			case '2':
				listar();
				system("pause");
				go = '1';
				break;
			case '3':
				
				x = modificar();
				if (x == 1) {
					printf("Matricula incorrecta");
				}
				go = '1';
				break;
			case '4':
				clasificar();
				go = '1';
				break;
			case '5':
				printf("Adios.");
				system("pause");
				break;
			default:
				printf("Opcion invalida.\n");
				go = '1';
				break;

		}
		
	
	}
	
	return 0;
}
void capturar() {
	int seguir = 1;
	char num = '0';
	int matricula;
	int grado;
	int promedio;
	do {
		printf("Desea ingresar un alumno nuevo (1 = Si / 0 = No)? ");
		if(scanf("%d", &seguir) != 1){
            printf("Dato ingresado incorrecto.\n");
            seguir = 1; 
            getchar();
        }else{
            if (seguir == 1 || seguir == 0) {
                getchar();
                if (seguir == 1) {
                    cont++;
                    size++;
                    do {
                        printf("Ingresa la matricula: ");
                        if (scanf("%d", &matricula) != 1) {
                            printf("El dato ingresado no es correcto.\n");
                            num = '0';
                        }
                        else {
                            alumno[cont][0] = matricula;
                            num = '1';
                        }
                        getchar();
                    } while (num != '1');
                    num = '0';
                    do {
                        printf("Inserte grado: ");
                        if (scanf("%d", &grado) != 1) {
                            printf("El dato ingresado no es correcto.\n");
                            num = '0';
                        }
                        else {
                            if (grado == 1 || grado == 2 || grado == 3) {
                                alumno[cont][1] = grado;
                                num = '1';
                            }
                            else {
                                printf("El grado ingresado no es correcto.\n");
                                num = '0';
                            }
                        }
                        getchar();
                    } while (num != '1');
                    num = '0';
                    do {
                        printf("Inserte el promedio: ");
                        if (scanf("%d", &promedio) != 1) {
                            printf("El dato ingresado no es correcto.\n");
                            num = '0';
                        }
                        else {
                            if (promedio < 0 || promedio > 100) {
                                printf("El promedio ingresado no es correcto. \n");
                                num = '0';
                            }
                            else {
                                alumno[cont][2] = promedio;
                                num = '1';
                            }
                        }
                        getchar();
                    } while (num != '1');
                }
            }
            else {
                printf("Valor incorrecto.\n");
                seguir = 1;
                getchar();
            }
        }
	} while (seguir == 1);
	//system("pause");
}

void listar() {
	system("cls");
	if (size == 0) {
		printf("No hay alumnos agregados\n");
	}
	else {
		printf("Matricula\tPromedio\tGrado\n");
		for (int i = 0; i < size; i++) {
			printf("%d\t\t%d\t\t%d\n", alumno[i][0], alumno[i][2], alumno[i][1]);
		}
	}
	printf("\n");
}

int modificar() {
	int flag = 1, promedio=0, grado=0;
	int mat = 0, go = 0;
	char num = '0';

	if (size == 0) {
		printf("No hay alumnos agregados\n");
	}
	else {
		do {
			printf("Inserte matricula por modificar: ");
			if (scanf("%d", &mat) != 1) {
				printf("El dato ingresado no es correcto.\n");
			}
			else {
				for (int i = 0; i < size; i++) {
					if (alumno[i][0] == mat) {
						do {
							printf("Inserte nuevo grado: ");
							if (scanf("%d", &grado) != 1) {
								printf("El dato ingresado no es correcto.\n");
								num = '0';
							}
							else {
								if (grado == 1 || grado == 2 || grado == 3) {
									alumno[i][1] = grado;
									num = '1';
								}
								else {
									printf("El grado ingresado no es correcto.\n");
									num = '0';
								}
							}
							getchar();
						} while (num != '1');

						num = '0';
						do {
							printf("Inserte nuevo promedio: ");
							if (scanf("%d", &promedio) != 1) {
								printf("El dato ingresado no es correcto.\n");
								num = '0';
							}
							else {
								if (promedio < 0 || promedio > 100) {
									printf("El promedio ingresado no es correcto. \n");
									num = '0';
								}
								else {
									alumno[cont][2] = promedio;
									num = '1';
								}
							}
							getchar();
						} while (num != '1');


						flag = 0;
						go = 1;
						break;
					}


					else {
						printf("La matricula ingresada no existe");
					}
				}

	

			}
		} while (go == 0);
	}

	return flag;
}

void clasificar() {
	int grado1 = 0;
	int grado2 = 0;
	int grado3 = 0;
	for (int i = 0; i < size; i++) {
		if (alumno[i][1] == 1) {
			grado1++;
		}
		else if (alumno[i][1] == 2) {
			grado2++;
		}
		else if (alumno[i][1] == 3) {
			grado3++;
		}
	}
	printf("\n Alumnos en grado 1: %d \n Alumnos en grado 2: %d \n Alumnos en grado 3: %d \n", grado1, grado2, grado3);
    system("pause"); 
}