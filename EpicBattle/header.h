typedef struct
{
	char nombre[64];
} engendro;

FILE *database;

int batalla();
int verbichos(int, engendro*);
int instrucciones();
int creditos();
int masbichos(int*, engendro**);
