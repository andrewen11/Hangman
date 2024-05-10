#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// structura pentru lista SIMPLU INLANTUITA folosita
typedef struct element
{
    char litera;
    struct element *urmator;
} nod;

// functie de extragere aleatorie a cuvantului de ghicit din lista de cuvinte
void extrag_cuvant(char word_hangman[], int *dimensiune)
{
    FILE *fisier_text;
    int index_cuvant_exp; //marcheaza randul in care e afla cuvantul propus de ghicit
    fisier_text = fopen("cuvinte.txt", "rt");
    if (fisier_text == NULL) // se verifica daca se poate efectua citirea din fisierul de cuvinte
    {
        printf("ERROR! THE WORD LIST FILE COULD NOT BE READ!");
        return;
    }
    else
    {
        srand(time(0)); // Se asigura ca la fiecare utilizare / timp de executie se alege cu cuvant diferit din cadrul generatorului de cuvinte
        index_cuvant_exp = rand() % 10;

        for (int indice = 1; indice < index_cuvant_exp; indice++)
        {
            fgets(word_hangman, 100, fisier_text);
        }

        fgets(word_hangman, 100, fisier_text);
        word_hangman[strcspn(word_hangman, "\n")] = '\0'; // inlocuieste caracterul '\n' cu terminatorul de sir ('\0')
        *dimensiune = strlen(word_hangman);
        fclose(fisier_text);
    }
}

// funnctie de adaugare caracter cuvant in lista simplu inlantuita (creare lista)
void adaug_in_lista(char word_hangman[], int dimensiune, nod **inceput)
{
    nod *intermediar = NULL;

    for (int indice = 0; indice < dimensiune; indice++)
    {
        if (*inceput == NULL)
        {
            (*inceput) = malloc(sizeof(nod));
            (*inceput)->litera = word_hangman[0];
            (*inceput)->urmator = NULL;
            intermediar = (*inceput);
        }
        else
        {
            intermediar->urmator = malloc(sizeof(nod));
            intermediar = intermediar->urmator;
            intermediar->litera = word_hangman[indice];
            intermediar->urmator = NULL;
        }
    }
}

void afisare_element_lista_CODIFICAT(nod *inceput)
{
    nod *curent;
    for (curent = inceput; curent != NULL; curent = curent->urmator)
    {
        if (curent->litera == ' ')
        {
            printf(" | ");
        }
        else
        {
            if (curent->litera > 'Z')
                printf("%c", curent->litera);
            else
                printf("%c", (curent->litera) + 32);
        }
    }
}

void modificare(nod **inceput2)
{
    nod *curent;
    for (curent = (*inceput2); curent != NULL; curent = curent->urmator)
    {
        if (curent->litera != ' ')
        {
            curent->litera = '_';
        }
    }
}

void modificare2(nod **inceput2, nod *inceput, char caracter, int *ghicit, int *nr_litere_ghicite)
{
    nod *curent, *curent2;
    for (curent = inceput, curent2 = *inceput2; curent != NULL && curent2 != NULL; curent = curent->urmator, curent2 = curent2->urmator)
    {
        if (curent->litera == caracter || curent->litera == caracter + 32)
        {
            curent2->litera = caracter;
            *ghicit = 1;
            (*nr_litere_ghicite)++;
        }
    }
}

char *extrag_intrebare(char intrebari_hangman[], int *index, char raspunsuri[5][100])
{
    FILE *fisier_text;
    int index_intrebare_exp; // marcheaza randul in care se afla intrebarea
    fisier_text = fopen("Intrebari.txt.txt", "rt+");
    if (fisier_text == NULL) // se verifica daca se poate efectua citirea din fisierul de cuvinte
    {
        printf("EROARE! NU SE POATE CITI FIȘIERUL CU ÎNTREBĂRI!");
        exit(EXIT_FAILURE); // Ieșirea din program dacă citirea fișierului eșuează
    }
    else
    {
        srand(time(0)); // Asigurarea alegerii unui cuvânt diferit la fiecare utilizare/timp de execuție
        index_intrebare_exp = rand() % 20;

        for (int indice = 1; indice < index_intrebare_exp; indice++)
        {
            fgets(intrebari_hangman, 1000, fisier_text);
        }

        fgets(intrebari_hangman, 1000, fisier_text);
        fclose(fisier_text);
        *index = index_intrebare_exp;

        // Tokenizarea șirului de intrare pe baza virgulelor
        char *token = strtok(intrebari_hangman, ",");

        // Primul token reprezintă întrebarea în sine
        strcpy(raspunsuri[0], token);

        // Procesarea variantelor de răspuns
        int r = 1; // Începând de la indexul 1 pentru variantele de răspuns
        while ((token = strtok(NULL, ",")) != NULL && r < 5)
        {
            // Se sare peste tokenul "A&B&C" sau dacă este un singur caracter
            if (strcmp(token, "A&B&C") == 0 || strlen(token) == 1)
                continue;

            // Eliminarea spațiilor de la începutul și sfârșitul răspunsului extras
            char *trimmed_answer = token;
            while (*trimmed_answer == ' ' || *trimmed_answer == '\t' || *trimmed_answer == '\n')
                trimmed_answer++;
            int len = strlen(trimmed_answer);
            while (len > 0 && (trimmed_answer[len - 1] == ' ' || trimmed_answer[len - 1] == '\t' || trimmed_answer[len - 1] == '\n'))
                trimmed_answer[--len] = '\0';

            // Găsirea literei corespunzătoare (A, B, C, D)
            char letter = 'A' + (r - 1); // Ajustare pentru a începe de la 'A'

            // Concatenarea literei cu răspunsul
            snprintf(raspunsuri[r], sizeof(raspunsuri[r]), "%c. %s", letter, trimmed_answer);

            r++;
        }

        return intrebari_hangman;
    }
}

void ghicire(nod *inceput, nod *inceput2, int dimensiune, int nr_sanse, char word_hangman[])
{
    char caracter;
    int nr_greseli = 0, ghicit, nr_litere_ghicite = 0;
    nod *curent;
    char caractere_introduse[26] = {0}; // Vector pentru a stoca caracterele introduse (A-Z)

    while (nr_greseli < nr_sanse && nr_litere_ghicite < dimensiune - 1)
    {
        ghicit = 0;
        printf("\nCHOOSE A LETTER & GUESS!\n");
        scanf(" %c", &caracter);

        // Verificare dacă caracterul a fost deja introdus
        if (caractere_introduse[caracter - 'A'] == 1)
        {
            printf("\nYou have already guessed this letter. Please choose another one.\n");
            continue; // Săritura la următoarea iterație a buclei
        }

        // Marcarea caracterului ca fiind introdus
        caractere_introduse[caracter - 'A'] = 1;

        // Actualizare modificare2
        modificare2(&inceput2, inceput, caracter, &ghicit, &nr_litere_ghicite);
        afisare_element_lista_CODIFICAT(inceput2);

        if (ghicit == 1)
        {
            printf("\n\nYou guessed: %c\n-----------------\n", caracter);
        }
        else
        {
            printf("\n\nWrong guess! TRY AGAIN!\n--------------------------\n");
            nr_greseli++;
        }
    }

    if (nr_greseli >= nr_sanse)
    {
        printf("GAME OVER! The word/expression you had to guess was: %s", word_hangman);
        char intrebari_hangman[1000];
        int index_intrebare;
        char raspunsuri[5][100];
        char option = 'x';
        if (option == 'X' || option == 'x')
            extrag_intrebare(intrebari_hangman, &index_intrebare, raspunsuri);

        for (int r = 0; r < 5; r++)
            printf("\n %s", raspunsuri[r]);

        char answer[20];
        printf("\nEnter your answer : ");
        scanf(" %s", answer);
        nr_sanse = 7;
    }
    else if (nr_greseli < nr_sanse && nr_litere_ghicite == dimensiune - 1)
    {
        printf("CONGRATULATIONS! YOU GUESSED CORRECTLY THE ENTIRE WORD: %s", word_hangman);
    }
}

int main()
{
    char cuvant_hangman[100], caracter, intrebari_hangman[1000];
    int dimensiune;
    nod *inceput = NULL, *inceput2 = NULL;
    extrag_cuvant(cuvant_hangman, &dimensiune);
    adaug_in_lista(cuvant_hangman, dimensiune, &inceput);
    adaug_in_lista(cuvant_hangman, dimensiune, &inceput2);

    modificare(&inceput2);
    printf("\nELEMENTUL CODIFICAT DIN LISTA ESTE: ");
    afisare_element_lista_CODIFICAT(inceput2);

    int nr_sanse = 2; // predefinit;

    ghicire(inceput, inceput2, dimensiune, nr_sanse, cuvant_hangman);
    return 0;
}