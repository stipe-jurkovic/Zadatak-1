
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME (150)
#define MAX_FILE_NAME (128)
#define MAX_LINE (50)
#define MAX_POINTS (30)

struct _Student;
typedef struct _Student{
	char imeStudenta[MAX_NAME];
	char prezimeStudenta[MAX_NAME];
	int brBodova;

}Student;

void InputFileName(char *name);
void StringToWords(char string[MAX_LINE], char *name, char *lastName, char *points);
float caclucateRelative(int points);

int main() {

	Student* Studenti;

	int x = 1;
	int k = 0;
	int brBod;
	char* ptr;
	char ime[MAX_NAME] = "";
	char prezime[MAX_NAME] = "";
	char bodovi[MAX_NAME] = "";
	char Buffer[MAX_NAME];
	char fileName[MAX_FILE_NAME];
	int brojStudenata = 0;

	InputFileName(fileName);
	FILE* File = fopen(fileName, "r");

	while (!feof(File)) {
		fgets(Buffer, MAX_LINE, File);
		x = strcmp(Buffer, "\n");
		//printf("%i \n", x);            //test 
		if (x != 0) {
			brojStudenata++;
		}
	}
	fclose(File);
	File = fopen(fileName, "r");

	printf("Broj studenata u dokumentu je: %i.\n", brojStudenata);


	Studenti = malloc(brojStudenata * sizeof(Student));
	if (Studenti == NULL) {
		printf("Nedovoljno memorije :(\n");
	}

	while (!feof(File)) {
		fgets(Buffer, MAX_LINE, File);
		x = strcmp(Buffer, "\n");

		strcpy(ime, "");
		strcpy(prezime, "");
		strcpy(bodovi, "");

		if (x != 0) {


			StringToWords(Buffer, &ime, &prezime, &bodovi);

			//printf("\n\n %s,%s,%s\n\n", ime, prezime, bodovi);

			strcpy((Studenti + k)->imeStudenta, ime);
			printf("\n%-15s", (Studenti + k)->imeStudenta);

			strcpy((Studenti + k)->prezimeStudenta, prezime);
			printf("%-15s", (Studenti + k)->prezimeStudenta);

			(Studenti + k)->brBodova = strtol(bodovi, &ptr, 10);
			brBod = Studenti[k].brBodova;
			printf("%-4i ", brBod);
			printf("aps: %5d rel: %.2f", Studenti[k].brBodova, caclucateRelative(Studenti[k].brBodova));
			printf("\n");
			memset(ime, 0, MAX_NAME);
			memset(prezime, 0, MAX_NAME);
			memset(bodovi, 0, MAX_NAME);

		};
		k++;

	}
	free(Studenti);
	fclose(File);
	return 0;
};

void InputFileName(char *name) {
	printf("Unesite ime dokumenta:\n");
	scanf("%s", name);

	FILE *doc = fopen(name, "r");
	if (doc == NULL)
	{
		printf("Greska pri otvaranju dokumenta. :( \nPokusajte opet.\n");
		fclose(doc);
		InputFileName(name);
	}

	fclose(doc);
}

void StringToWords(char string[MAX_LINE], char *name, char *lastName, char *points) {
	int redBrRj = 0, i = 0, j = 0;
	while (string[i]!='\0') {
		
		if (string[i] == ' ' || string[i] == '\0') {
			
			redBrRj++;
			j = 0;
		}
		else {

			if (redBrRj == 0)
				name[j] = string[i];
			if (redBrRj == 1)
				lastName[j] = string[i];
			if (redBrRj == 2)
				points[j] = string[i];
			j++;
		}
		i++;

	}
}

float caclucateRelative(int points) {
	return (float) 100*points/MAX_POINTS;
}