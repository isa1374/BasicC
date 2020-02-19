#include <stdio.h>
#include <string.h>



typedef struct {
	char calleNum[30];
	char codigoP[10];
	char colonia[20];
	char ciudad[20];
	char telefono[15];
} domicilio;



typedef struct {
	long numCuenta;
	char nombre[25];
	domicilio dom;
	long saldo;
} cliente;




void ingresarCliente(int posicion);
int deposito(long numCuenta, long saldo);
int retiro(long numCuenta, long saldo);



cliente CLI[100];
int cont;



int main() {
	char c, c2;
	int flag = 0;
	cont = 0;
	long numCuenta, saldo;


	printf("Desea ingresar un cliente nuevo (1 = Si/0 No)? ");
	c = getchar();
	while (c == '1') {
		getchar(); 
		ingresarCliente(cont);
		cont++;
		printf("\nDesea ingresar un otro cliente(1 = Si/0 No)? ");
		c = getchar();
	}

	printf("Lista de clientes: \n");
	for (int i = 0; i < cont; i++) {
		puts(CLI[i].nombre);
	}



	do {
		numCuenta = 0;
		saldo = 0;
		getchar();

		printf("\nSeleccione una opcion del Menu\n");
		printf("1. Deposito\n2. Retiro\n3. Salir\nOpcion: ");
		c2 = getchar();

		switch (c2) {
		case '1':
			printf("\nIngrese numero de cuenta: ");
			scanf("%ld", &numCuenta);
			printf("Ingrese saldo a depositar: ");
			scanf("%ld", &saldo);
			flag = deposito(numCuenta, saldo);
			if (flag == 1) {
				printf("El numero de cuenta ingresado es incorrecto.\n");
			}
			else {
				printf("Se ha depositado %ld a la cuenta %ld.\n", saldo, numCuenta);
			}
			break;
		case '2':
			printf("\nIngrese numero de cuenta: ");
			scanf("%ld", &numCuenta);
			printf("Ingrese saldo a depositar: ");
			scanf("%ld", &saldo);
			flag = retiro(numCuenta, saldo);
			if (flag == 1) {
				printf("El numero de cuenta ingresado es incorrecto.\n");
			}
			else if (flag == 2) {
				printf("Saldo insuficiente.\n", saldo, numCuenta);
			}
			else {
				printf("Se ha retirado %ld satisfactoriamente.\n", saldo);
			}
			break;
		case '3':
			printf("\nAdios.");
			break;
		default:
			printf("Esa opcion no se encuentra en el menu.\n");
			break;
		}
	} while (c2 != '3');



	return 0;
}



void ingresarCliente(int posicion) {
	domicilio dm;
	cliente cl;

	fflush(stdin);
	printf("Ingrese numero de cuenta: ");
	gets(cl.numCuenta);

	printf("Ingrese nombre de cliente: ");
	fflush(stdin);
	gets(cl.nombre);

	printf("Ingrese calle y numero: ");
	fflush(stdin);
	gets(cl.dom.calleNum);

	printf("Ingrese codigo postal: ");
	fflush(stdin);
	gets(cl.dom.codigoP);

	printf("Ingrese ciudad: ");
	fflush(stdin);
	gets(cl.dom.ciudad);

	printf("Ingrese telefono: ");
	fflush(stdin);
	gets(cl.dom.telefono);



	printf("Saldo inicial: 0"); // todos los clientes empiezan con saldo = 0
	cl.saldo = 0;



	CLI[posicion] = cl;
	printf("Cliente registrado en el sistema.\n");




}



int retiro(long numC, long sal) {
	int flag = 1;



	for (int i = 0; i < cont; i++) {
		if (CLI[i].numCuenta == numC) {
			if (CLI[i].saldo >= sal) {
				CLI[i].saldo = CLI[i].saldo - sal;
				flag = 0;
				printf("\n\tSu saldo ahora es de: %ld\n ", CLI[i].saldo);
			}
			else {
				flag = 2;
			}

			break;
		}
	}
	return flag;
}



int deposito(long numC, long sal) {
	int flag = 1;

	for (int i = 0; i < cont; i++) {
		printf("if %ld == %ld\n", CLI[i].numCuenta, numC);
		if (CLI[i].numCuenta == numC) {
			CLI[i].saldo = sal;
			flag = 0;
			printf("\n\tSu saldo ahora es de: %ld\n ", CLI[i].saldo);
			break;
		}
	}
	return flag;
}