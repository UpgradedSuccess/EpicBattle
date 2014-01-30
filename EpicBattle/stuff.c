#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int batalla()
{
	system("cls");
	printf("Ha elegido: Batalla.\n\n");
	printf("No implementado.\n");
	getch();
	return 0;
}

int verbichos(int numeng, engendro *ptrengendro)
{
	int k, info;
	char cont = 's', cont1 = 's';

	system("cls");
	printf("Ha elegido: Ver engendros.\n\n");
	do
	{
		printf("El número de engendros actual es: %d", numeng);
		printf("\n\n");
		for (k = 0; k < numeng; k++)
			printf("%d-%s\n", k + 1, ptrengendro[k].nombre);
		if (k != 0)
		{
			printf("\n\nTeclee el número del engendro del que desea obtener información (0 para salir): ");
			scanf("%d", &info);
			if (info == 0)
				return 0;
			printf("Nombre: %s\n", ptrengendro[info-1].nombre);
			printf("(Por el momento no hay más información.)\n\n\n");
			printf("¿Desea buscar otro engendro más? (S/N)\n");
			cont = getch();
			if (cont == 'n' || cont == 'N')
				return 0;
			printf("¿Quiere que se vuelva a mostrar la lista? (S/N)");
			fflush(stdin);
			cont1 = getch();
			if (cont1 == 's' || cont1 == 'S')
			{
				system("cls");
				for (k = 0; k < numeng; k++)
					printf("%d-%s\n", k + 1, ptrengendro[k+1].nombre);
				getch();
			}
			system("cls");
		}
	} while (numeng != 0 && cont == "s");
	getch();
	return 0;
}

int masbichos(int *numeng, engendro **ptrengendro)
{
	char cont = 's';
	engendro auxengendro;
	system("cls");
	printf("Ha elegido: Añadir engendros.\n");
	do
	{
		fflush(stdin);
		printf("\nIntroduzca el nombre del engendro a crear (0 para salir): ");
		scanf("%[^\n]s", auxengendro.nombre);
		if (auxengendro.nombre[0] == '0')
			return 0;
		(*numeng)++;
		*ptrengendro = (engendro*)realloc(*ptrengendro, *numeng * sizeof(engendro));
		strcpy ((*ptrengendro)[(*numeng) - 1].nombre, auxengendro.nombre);
	} while (1);
	return 0;
}

int instrucciones()
{
	system("cls");
	printf("Ha elegido: Instrucciones.\n\n");
	printf("Este pseudo-programa se supone que hace que engendros a su elección se peguen.\n");
	printf("Como soy un mierdas, en esta versión el combate no está implementado.\n");
	printf("¿Y para qué sirve esto entonces? Pues por el momento para nada :D\n");
	printf("Hala, a morirse bien.");
	getch();
	return 0;
}

int creditos()
{
	system("cls");
	printf("Ha elegido: Créditos.\n\n");
	printf("Código: Myrkul.\n");
	printf("Idea: Intervención divina.\n");
	printf("Insultos y denuncias a: pro4myrkul@gmail.com\n");
	getch();
	return 0;
}