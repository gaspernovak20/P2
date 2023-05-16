
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga1.h"

VO **opravili(Student **studentje, int stStudentov, char *predmet, int *stVO)
{

    VO **student_ocena = malloc(1001 * sizeof(*student_ocena));
    if (student_ocena == NULL)
        exit(1);

    int st_VO = 0;

    // skozi vse studente
    for (int i = 0; i < stStudentov; i++)
    {
        Student *student = studentje[i];

        // skozi vse predmete studenta
        for (int j = 0; j < student->stPO; j++)
        {

            // previrjamo ali je pravilen predmet
            if (strcmp(student->po[j].predmet, predmet) == 0)
            {
                // dodamo VO v tabelo
                VO *new_vo = malloc(sizeof *new_vo);

                new_vo->vpisna = student->vpisna;
                new_vo->ocena = student->po[j].ocena;

                student_ocena[st_VO] = new_vo;
                // povecamo velikost "student_ocena" tabele
                st_VO++;
            }
        }
    }

    *stVO = st_VO;

    return student_ocena;
}

#ifndef test

void izvedi(Student **studentje, int stStudentov, char *predmet)
{
    int stVO = 0;
    VO **vvo = opravili(studentje, stStudentov, predmet, &stVO);
    printf("[");
    for (int i = 0; i < stVO; i++)
    {
        VO *vo = vvo[i];
        if (i > 0)
        {
            printf(", ");
        }
        printf("%d/%d", vo->vpisna, vo->ocena);
    }
    printf("]\n");
}

int main()
{
    // koda za ro"cno testiranje (po "zelji)
    Student *studentje[] = {
        (Student[]){
            888,
            (PO[]){{"FIZ", 10}, {"P1", 7}, {"P2", 8}, {"OMA", 5}, {"ODV", 9}},
            5},
        (Student[]){
            333,
            (PO[]){{"", 0}},
            0},
        (Student[]){
            555,
            (PO[]){{"FIZ", 6}, {"P2", 8}, {"ARS", 5}, {"ODV", 9}},
            4},
        (Student[]){
            111,
            (PO[]){{"P1", 7}, {"ARS", 6}},
            2},
        (Student[]){
            777,
            (PO[]){{"P1", 10}, {"FIZ", 7}, {"ODV", 8}},
            3},
    };
    int stStudentov = sizeof(studentje) / sizeof(studentje[0]);

    izvedi(studentje, stStudentov, "FIZ");

    return 0;
}

#endif
