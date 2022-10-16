
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME (150)
#define MAX_FILE_NAME (128)
#define MAX_LINE (50)


void StringToWords(char string[MAX_LINE], char *word1, char *word2, char *word3) {
	int redBrRj = 0, i = 0, j = 0, k = 0;
	while (string[i]!='\0') {
		
		if (string[i] == ' ' || string[i] == '\0') {
			
			redBrRj++;
			j = 0;
		}
		else {

			if (redBrRj == 0)
				word1[j] = string[i];
			if (redBrRj == 1)
				word2[j] = string[i];
			if (redBrRj == 2)
				word3[j] = string[i];
			j++;
		}
		i++;

	};
	i = 0;
	j = 0;
};



struct _Student;
typedef struct _Student{
	char imeStudenta[MAX_NAME];
	char prezimeStudenta[MAX_NAME];
	int brBodova;

}Student;
int main() {

	Student* Studenti;

	int x = 1;
	int i = 0;
	int j = 0;
	int k = 0;
	int brBod;
	char* ptr;
	char rijec1[MAX_NAME] = "";
	char rijec2[MAX_NAME] = "";
	char rijec3[MAX_NAME] = "";
	char Buffer[MAX_NAME];
	char fileName[MAX_FILE_NAME];
	int brojStudenata = 0;


	FILE* File;
	strcpy(fileName, "lista studenata.txt");
	File = fopen(fileName, "r");

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

	printf("Broj studenata u dokumentu je : %i .", brojStudenata);


	Studenti = malloc(brojStudenata * sizeof(Student));

	while (!feof(File)) {
		fgets(Buffer, MAX_LINE, File);
		x = strcmp(Buffer, "\n");

		strcpy(rijec1, "");
		strcpy(rijec2, "");
		strcpy(rijec3, "");

		if (x != 0) {


			StringToWords(Buffer, &rijec1, &rijec2, &rijec3);

			//printf("\n\n %s,%s,%s\n\n", rijec1, rijec2, rijec3);


			strcpy((Studenti + k)->imeStudenta, rijec1);
			printf("\n %s ", (Studenti + k)->imeStudenta);

			strcpy((Studenti + k)->prezimeStudenta, rijec2);
			printf(" %s ", (Studenti + k)->prezimeStudenta);

			(Studenti + k)->brBodova = strtol(rijec3, &ptr, 10);
			brBod = Studenti[k].brBodova;
			printf(" %i ", brBod);
			printf("aps: %f", (float)Studenti[0].brBodova / 1009);
			printf("\n");
			memset(rijec1, 0, MAX_NAME);
			memset(rijec2, 0, MAX_NAME);
			memset(rijec3, 0, MAX_NAME);

		};
		k++;

	};
	free(Studenti);
	fclose(File);
	return 0;
};