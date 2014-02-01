#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
			if (info > numeng || info < 0)
			{
				system("cls");
				printf("La cifra introducida no es correcta.");
				getch();
				fflush(stdin);
				continue;
			}
			printf("Nombre: %s\n", ptrengendro[info-1].nombre);
			printf("HP: %d\n", ptrengendro[info - 1].hp);
			printf("(Por el momento no hay más información.)\n\n\n");
			printf("¿Desea buscar otro engendro más? (S/N)\n");
			cont = getch();
			if (cont == 'n' || cont == 'N')
				return 0;
			system("cls");
		}
	} while (numeng != 0 && cont == 's');
	getch();
	return 0;
}

int masbichos(int *numeng, engendro **ptrengendro)
{
	engendro auxengendro;
	char cont = 's';
	system("cls");
	printf("Ha elegido: Añadir engendros.\n");
	do
	{
		fflush(stdin);
		printf("\nIntroduzca el nombre del engendro a crear (0 para salir): ");
		scanf("%[^\n]s", auxengendro.nombre);
		if (auxengendro.nombre[0] == '0')
			return 0;
		printf("Introduzca los hp del engendro: ");
		scanf("%d", &auxengendro.hp);
		(*numeng)++;
		*ptrengendro = (engendro*)realloc(*ptrengendro, *numeng * sizeof(engendro));
		strcpy((*ptrengendro)[(*numeng) - 1].nombre, auxengendro.nombre);
		(*ptrengendro)[(*numeng) - 1].hp = auxengendro.hp;
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

int modbichos(int *numeng, engendro **ptrengendro)
{
	int k, sel, mod;
	char sel1;

	do
	{
		system("cls");
		printf("Ha elegido: Modificar engendros.\n\n");
		for (k = 0; k < (*numeng); k++)
			printf("%d-%s\n", k + 1, (*ptrengendro)[k].nombre);
		printf("\nIntroduzca el número del engendro que desee modificar (0 para salir): ");
		scanf("%d", &mod);
		if (mod == 0)
			return 0;
		if (mod > (*numeng) || mod < 0)
		{
			system("cls");
			printf("La cifra introducida no es correcta.");
			getch();
			fflush(stdin);
			continue;
		}
		system("cls");
		printf("Seleccionado: %s\n\n", (*ptrengendro)[mod-1].nombre);
		printf("Elija una opción:\n\n");
		printf("1-Modificar nombre.\n");
		printf("2-Modificar HP.\n");
		printf("3-Eliminar engendro.\n");
		printf("4-Volver.");
		sel = getch();
		switch (sel)
		{
			case '1':
				system("cls");
				printf("Introduzca el nuevo nombre para '%s': ", (*ptrengendro)[mod - 1].nombre);
				fflush(stdin);
				scanf("%[^\n]s", (*ptrengendro)[mod - 1].nombre);
				printf("\n¿Desea modificar otro engendro? (S/N):");
				sel1 = getch();
				if (sel1 == 's' || sel1 == 'S')
					continue;
				else
					return 0;
			case '2':
				system("cls");
				printf("Introduzca el nuevo HP para '%s': ", (*ptrengendro)[mod - 1].nombre);
				fflush(stdin);
				scanf("%d", &(*ptrengendro)[mod-1].hp);
				printf("\n¿Desea modificar otro engendro? (S/N):");
				sel1 = getch();
				if (sel1 == 's' || sel1 == 'S')
					continue;
				else
					return 0;
			case '3':
				system("cls");
				strcpy((*ptrengendro)[mod - 1].nombre, (*ptrengendro)[(*numeng) - 1].nombre);
				(*ptrengendro)[mod - 1].hp = (*ptrengendro)[(*numeng) - 1].hp;
				(*numeng)--;
				printf("Eliminado.");
				getch();
			case '4':
				continue;
			default:
				continue;
		}
	} while (1);
}