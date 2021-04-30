#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



struct students
{
    char a[9];
    char b[20];
    char c[20];
    char d[20];
    char e[10];
};

struct students total_students[100];


int get_total_lines() {
    FILE *myfile = fopen("data.csv", "r");
    char ch;
    int count = 0;
    do {
            ch = fgetc(myfile);
            if (ch == '\n') count++;
        } while (ch != EOF);
    return count;
}

void read_file(){
    FILE *myfile = fopen("data.csv", "r");
    if (myfile == NULL) {
        printf("Cannot open file.\n");
        //return 1;
    }

    else {
            int count = get_total_lines();
        rewind(myfile);

        int i;
        for (i = 0; i < count; i++) {
            fscanf(myfile, "%s %s %s %s %s\n",  total_students[i].a,  total_students[i].b,  total_students[i].c,  total_students[i].d,  total_students[i].e);
        }
    }
}

void print_file() {
   read_file();
   int i;
   int size = get_total_lines();
   printf("ID \tNom \t\tPrenom \t\tNiveau \t\tfiliere\n");
   for(i = 0; i < size; i++)
      printf("%s \t%s \t\t%s \t\t%s \t\t%s\n",  total_students[i].a,  total_students[i].b,  total_students[i].c,  total_students[i].d,  total_students[i].e);

}

void read_student(){
    FILE *myfile = fopen("data.csv", "a");
    struct students newstudent;
    char prefix[100] = "";

    for(int i=0;i<8;i++){
        newstudent.a[i]="0123456789"[rand() % 10];
    }
    newstudent.a[8] = '\0';
    
    printf("Creating Student with ID: %s \n", newstudent.a);

    printf(" Input Nom : \n");
	scanf("%s",newstudent.b);
    printf("\n");

    printf(" Input Prenom: \n");
	scanf("%s",newstudent.c);
    printf("\n");

    printf(" Input Niveau : \n");
	scanf("%s",newstudent.d);
    printf("\n");

    printf(" Input Filiere : \n");
	scanf("%s",newstudent.e);
    printf("\n");

    //sprintf(prefix,"%s: %s: %s",argv[0],cmd_argv[0],cmd_argv[1]);

    sprintf(prefix,"%s %s %s %s %s\n",  newstudent.a,  newstudent.b,  newstudent.c,  newstudent.d,  newstudent.e);
    fputs(prefix, myfile);
    fclose (myfile);

}

void delete_student(){
    read_file();
    int size = get_total_lines();
    char a[9];
    printf("Enter a string\n");
    gets(a);


    FILE *myfile = fopen("data.csv", "w");
    fclose (myfile);
    char prefix[100] = "";
    int i;

    myfile = fopen("data.csv", "a");
    for(i = 0; i < size; i++)
      {
          if(strcmp(total_students[i].a, a)) {
            sprintf(prefix,"%s %s %s %s %s\n",  total_students[i].a,  total_students[i].b,  total_students[i].c,  total_students[i].d,  total_students[i].e);
            fputs(prefix, myfile);
          }
      }


    fclose (myfile);
}

void menu() {
    printf("---------------------------------------------------------------\n");
    printf("------------------ Gestion des Etudiants ----------------------\n");
    printf("---------------------------------------------------------------\n");
    printf("****************** Choisie l'action : *************************\n");
    printf("** a ---------- Afficher la list des etudiants --------------**\n");
    printf("** b ---------- Ajouter un etudiant -------------------------**\n");
    printf("** c ---------- Supprimer un etudiants ----------------------**\n");
    printf("** x ---------- Quiter le programme -------------------------**\n");
    printf("***************************************************************\n");
    printf("---------------------------------------------------------------\n");
}

int main(void) {
    srand(time(0));
    
    char a[1];
    

    while(1) {
        menu();
        gets(a);

        if(!strcmp("x", a)) {
            break;
        }

        if(!strcmp("a", a)) {
            print_file();
        }

        if(!strcmp("b", a)) {
            read_student();
        }

        if(!strcmp("c", a)) {
            delete_student();
        }
    }
}