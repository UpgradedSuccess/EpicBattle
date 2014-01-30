#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "header.h"

int main()
{
	int sel, numeng;
	engendro *ptrengendro = NULL;
	setlocale(LC_CTYPE, "Spanish");
	database = fopen("database.dat", "rb");

	if (database == NULL)
	{
		printf("No se ha encontrado el archivo de datos.\n");
		getch();
		exit(0);
	}
	else
	{
		fseek(database, 0, SEEK_END);
		numeng = ftell(database) / sizeof(engendro);
		ptrengendro = (engendro*)calloc(numeng, sizeof(engendro));

		if (ptrengendro == NULL)
		{
			printf("\nNo se pudo asignar memoria suficiente para la base de datos. No se puede iniciar, saliendo...\n\n");
			exit(0);
		}
		fseek(database, 0, SEEK_SET);
		fread(ptrengendro, sizeof(engendro), numeng, database);
		fclose(database);
	}

	do
	{
		system("cls");
		printf("\n\n\t\tBienvenido al programa de lucha de engendros! (Ver. 0.1).\n\n");
		printf("Seleccione una opcion:\n");
		printf("1-Comenzar.\n");
		printf("2-Ver engendros.\n");
		printf("3-Añadir engendros.\n");
		printf("4-Instrucciones.\n");
		printf("5-Créditos.\n");
		printf("6-Salir.\n");

		sel = getch();
		switch (sel)
		{
			case '1':
				batalla();
				break;
			case '2':
				verbichos(numeng, ptrengendro);
				break;
			case '3':
				masbichos(&numeng, &ptrengendro);
				break;
			case '4':
				instrucciones();
				break;
			case '5':
				creditos();
				break;
			case '6':
				exit(0);
			default:
				system("cls");
				printf("Opción no correcta.");
				getch();
				break;
		}
	} while (1);

	database = fopen("database.dat", "rb");
	fwrite(ptrengendro, sizeof(engendro), numeng, database);
	fclose(database);
	return 0;
}