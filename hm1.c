#include <stdio.h>

#include <string.h>

 

int longitud(char cad[20]);

 

int main()

{

    char c, cad[20], cadMayor[20];

    int i, iMayor = -1;

    

    printf("Desea ingresar una cadena de caracteres (S/N)? "); 

    scanf("%c", &c);
    
    while (c == 'S') { 
	getchar();  

        printf("\nIngrese la cadena de caracteres: "); 

        fflush(stdin); 

        gets(cad); 


        i = longitud(cad);

        if (iMayor < i){

            iMayor = i;

            strcpy(cad, cadMayor); 

        }

    

        printf("\nDesea ingresar otra cadena de caracteres (S/N)? "); 

        c = getchar(); 

        

    }

        

        printf("\nLa cadena con mayor longitud es: ");

        puts(cadMayor);

    return 0;

}

 

int longitud(char cadena[20]) { 

    int c = 0; 

    while (!cadena[c] == '\0') 

    c++; 

    

    return (c); 

}