typedef struct
{
	char nombre[64];
	int hp;
} engendro;

FILE *database;

int batalla();
int verbichos(int, engendro*);
int instrucciones();
int creditos();
int masbichos(int*, engendro**);
int modbichos(int*, engendro**);
