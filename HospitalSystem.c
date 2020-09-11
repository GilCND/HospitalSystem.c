/*
-------------------------------------------------------------------------------------
PROGRAM INFO:
Program: HospitalSystem.c
Date: 24/04/2020
Autor: Felipe SG
Program Details:
This program should have
A menu with options to:
Add new patients
Edit patient record
Delete patient
Display all existing patient records
Save all patients records into a file
Search for patients name
Show patients less critical to most critical
Tally up the hospital month earnings
Load precius data
-------------------------------------------------------------------------------------
Change log
-------------------------------------------------------------------------------------
|       Date        |   Programmer   |                   Changelog                   | 
    Apr-24-2020         Felipe SG                   First Version  1.0         
    Apr-27-2020         Felipe SG                   New features added on the menu section
    Apr-28-2020         Felipe SG                   Reduced number of lines
    Apr-30-2020         Felipe SG                   Implementation of the searching method
    Apr-31-2020         Felipe SG                   Revision and code improvement        
    
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <unistd.h>

FILE *f1;
struct node 
#define LSIZ 128 
#define RSIZ 10

{
    char HospName [150];
    char AdNurse [150];
    char DocSeen [150];
    char Diagnosis [150];
    char PatfName[150]; 
    char PatlName[150];
    char InsurName[150];
    int Id;
    int Triage;
    float Cost;
    int InsurNumber;    // sleep(1/2);
	struct node* next;
};
struct node * GenerateLinkedList();
void FillStructData(struct node *current);
struct node * LoadPrev();
void LoadData(struct node *current);
struct node *start;
struct node *move;
struct node tmp;
char ch, chr;
int count_lines = 0;

int main()
    {
        menus();
        //function to add nodes to a list and return the preference to the first node
        

       
    }
menus()
{
    char Choice;
    int x = 0;
    //This function displays the menu and validates data entry
    system("clear");
     puts("\n\t\t\t\t MAIN MENU\n");

        
        puts("\n[A] New Patient Record.\n");
      
        puts("[B] Edit Patient Record.\n");
     
        puts("[C] Delete Patient Record. \n");
     
        puts("[D] Display all the existing Patient records.\n");
      
        puts("[E] Save all Patient records into a file.\n");

        puts("[F] Search for a patient's name.\n");

        puts("[G] Show patients less citrical to most critical.\n");

        puts("[H] Tally up the month earnings\n");

        puts("[I] Load Data\n");

      
        printf("Choice : ");
        scanf("%s", &Choice);
      
        printf("\n\n LOADING PLEASE WAIT: \n");

        printf("\n");
        while(Choice !='a' && Choice != 'A' && Choice != 'b' && Choice != 'B' && Choice != 'c' 
        && Choice != 'C' && Choice != 'd' && Choice != 'D' && Choice != 'e' && Choice != 'E'
        && Choice != 'f' && Choice != 'F' && Choice != 'g' && Choice != 'G'&& Choice != 'h' 
        && Choice != 'H' && Choice != 'i' && Choice != 'I')
        {
        puts("\n INVALID INPUT TRY AGAIN!");
        printf("\n Choice :  ");
        scanf("%c", &Choice);
        }

            switch (Choice)
            {
            case 'a':
            case 'A':
            start = GenerateLinkedList();
            menus();
            break;

            case 'b':
            case 'B':
            menus();
            break;

            case 'c':
            case 'C':
            menus();
            break;

            case 'd': 
            case'D':
            Display();
            break;

            case'e':
            case'E':
            SaveDatabase();
            
            break; 

            case'f':
            case'F':
            SearchData();
            break; 

            case'g':
            case'G':
            menus();
            break; 

            case'h':
            case'H':
            menus();
            break; 
            
            case'i':
            case'I':
            start = LoadPrev();
            break; 

            default:
            break;
            }

}
struct node *GenerateLinkedList()
{

        struct node *start, *current, *last;
        int count = 0;
        char choose = 'y';
        int ch;
        system("clear");
        while (choose == 'y' || choose =='Y')
        {
            if (count == 0)
            {
                //set up first node. assign start
                current = (struct node *)malloc(sizeof(struct node));
                if (current == NULL)
                {
                    puts("MEMORY ALLOCATION ERROR. Node1. Exiting...");
                    exit(1);
                }
                start = current;
                count++;
                FillStructData(current);
                current->next = 0;
                last = current;
                
            }
            else
            {
                //set up next node. link to last node
                current = (struct node *)malloc(sizeof(struct node));
                if (current == NULL)
                {
                    puts("MEMORY ALLOCATION ERROR. Node1. Exiting...");
                    exit(1);
                }
                count++;
                FillStructData(current);
                current->next = 0;
                last->next = current;
                last = current;
            }

            puts("Enter new Patient? (y/n) ");
            scanf("%c", &choose);
            while ( ( ch = getchar() ) != '\n' && ch !=EOF );
            
        }
        return start;
}
void FillStructData(struct node *current)
{
    int ch;
    
    printf("\nPatient First Name: ");
    scanf("%s", current->PatfName);
    while ( ( ch = getchar() ) != '\n' && ch !=EOF );
    
    printf("\nPatient Last Name: ");
    scanf("%s", current->PatlName);
    while ( ( ch = getchar() ) != '\n' && ch !=EOF );

    printf("\nInsurance Company: ");
    scanf("%s", current->InsurName);
    while ( ( ch = getchar() ) != '\n' && ch !=EOF );

    printf("\nInsurance Number: ");
    scanf("%d", &current->InsurNumber);
    while ( ( ch = getchar() ) != '\n' && ch !=EOF );

    printf("\nHospital Name: ");
    scanf("%s", current->HospName);
    while ( ( ch = getchar() ) != '\n' && ch !=EOF );

    printf("\nAdmitting Nurse: ");
    scanf("%s", current->AdNurse);
    while ( ( ch = getchar() ) != '\n' && ch !=EOF );

    printf("\nDoctor Seen: ");
    scanf("%s", current->DocSeen);
    while ( ( ch = getchar() ) != '\n' && ch !=EOF );

    printf("\nDiagnosis: ");
    scanf("%s", current->Diagnosis); 
    while ( ( ch = getchar() ) != '\n' && ch !=EOF );
    
    printf("\nTriage Ranking: ");
    scanf("%d", &current->Triage); 
    while ( ( ch = getchar() ) != '\n' && ch !=EOF );
        
    printf("\nCost: ");
    scanf("%f", &current->Cost); 
    while ( ( ch = getchar() ) != '\n' && ch !=EOF );
    
    printf("\nID: ");
    scanf("%d", &current->Id); 
    while ( ( ch = getchar() ) != '\n' && ch !=EOF );



}
void PrintStructData()
{ 
    printf("Hospital Name : %s \n", move->HospName);
    printf("\nPatient First Name: %s", move->PatfName);
    printf("\nPatient Last Name: %s", move->PatlName);
    printf("\nInsurance Company: %s", move->InsurName);
    printf("\nInsurance Number: %d", move->InsurNumber);
    printf("\nHospital Name: %s", move->HospName);
    printf("\nAdmitting Nurse: %s", move->AdNurse);
    printf("\nDoctor Seen: %s", move->DocSeen);
    printf("\nDiagnosis: %s", move->Diagnosis);
    printf("\nTriage Ranking: %d", move->Triage);
    printf("\nCost $: %.2f", move->Cost);
    printf("\nID: %d", move->Id);
    printf("\n %p", move->next);
}
void SaveDatabase()
{
     //move throught the list and save into the database
    move = start;
    f1=fopen("patient1.txt","w");
    char ch;
    while(move->next !=0)
    {
        fprintf(f1,"%s\n", move->PatfName);
        fprintf(f1,"%s\n", move->PatlName);
        fprintf(f1,"%s\n", move->InsurName);
        fprintf(f1,"%d\n", move->InsurNumber);
        fprintf(f1,"%s\n", move->HospName);
        fprintf(f1,"%s\n", move->AdNurse);
        fprintf(f1,"%s\n", move->DocSeen);
        fprintf(f1,"%s\n", move->Diagnosis);
        fprintf(f1,"%d\n", move->Triage);
        fprintf(f1,"%f\n", move->Cost);
        fprintf(f1,"%d\n", move->Id);

        move = move->next;
        
    }

    fprintf(f1," %s\n", move->PatfName);
    fprintf(f1,"%s\n", move->PatlName);
    fprintf(f1,"%s\n", move->InsurName);
    fprintf(f1,"%d\n", move->InsurNumber);
    fprintf(f1,"%s\n", move->HospName);
    fprintf(f1,"%s\n", move->AdNurse);
    fprintf(f1,"%s\n", move->DocSeen);
    fprintf(f1,"%s\n", move->Diagnosis);
    fprintf(f1,"%d\n", move->Triage);
    fprintf(f1,"%f\n", move->Cost);
    fprintf(f1,"%d\n", move->Id);
    fclose(f1);
    puts("End of List");      
    system("clear");
    while ( ( ch = getchar() ) != '\n' && ch != EOF );    
    puts("All data saved. Press any keu to go back to menu"); 
    getchar();
    menus();

    return 0;
}
void SearchData()
{  
    char search[100];
    int result=0, count=0;

    puts("\nPATIENT SEARCH!\n");
    puts("\nPlease, inform the FIRST name of the patient\n");
    scanf("%s", &search);
    move = start;
        while(move->next !=0)
    {

        result = strcmp(move->PatfName, search);
        if (result == 0)
        {
            puts("\nPatient Found!!\n");
            printf("Patient Name: %s\n", move->PatfName); 
            printf("Patient Last Name: %s\n", move->PatlName);
            printf("Insurance Company Name: %s\n", move->InsurName);
            printf("Insurance Number: %d\n", move->InsurNumber);
            printf("Hospital Name: %s\n", move->HospName);
            printf("Admiting Nurse: %s\n", move->AdNurse);
            printf("Doctor Seen: %s\n", move->DocSeen);
            printf("Diagnosis: %s\n", move->Diagnosis);
            printf("Triage Ranking: %d\n", move->Triage);
            printf("Cost $: %f\n", move->Cost); 
            count = 1;
        }       
       move = move->next;
    }
    result = strcmp(move->PatfName, search);
        if (result == 0)
        {
            puts("\nPatient Found!!\n");
            printf("Patient Name: %s\n", move->PatfName); 
            printf("Patient Last Name: %s\n", move->PatlName);
            printf("Insurance Company Name: %s\n", move->InsurName);
            printf("Insurance Number: %d\n", move->InsurNumber);
            printf("Hospital Name: %s\n", move->HospName);
            printf("Admiting Nurse: %s\n", move->AdNurse);
            printf("Doctor Seen: %s\n", move->DocSeen);
            printf("Diagnosis: %s\n", move->Diagnosis);
            printf("Triage Ranking: %d\n", move->Triage);
            printf("Cost $: %f\n", move->Cost); 
            count = 1;
        }
        if (count == 0)
        {
            puts("\nSorry, patient not found.\n");
            while ( ( ch = getchar() ) != '\n' && ch != EOF ); 
            puts("\nPress any key to Display the Patient.");
            getchar();
        }   

    puts("\nPress any key to go back to menu!\n");
    while ( ( ch = getchar() ) != '\n' && ch != EOF ); 
    getchar();
    menus();
    return 0;      
}
void Display()
{
    move = start;
     while(move->next !=0)
    {
        puts("\n----------------------------------!\n");
        printf("Patient Name: %s\n", move->PatfName); 
        printf("Patient Last Name: %s\n", move->PatlName);
        printf("Insurance Company Name: %s\n", move->InsurName);
        printf("Insurance Number: %d\n", move->InsurNumber);
        printf("Hospital Name: %s\n", move->HospName);
        printf("Admiting Nurse: %s\n", move->AdNurse);
        printf("Doctor Seen: %s\n", move->DocSeen);
        printf("Diagnosis: %s\n", move->Diagnosis);
        printf("Triage Ranking: %d\n", move->Triage);
        printf("Cost $: %f\n", move->Cost); 

        move = move->next;
    }

    printf("Patient Name: %s\n", move->PatfName); 
    printf("Patient Last Name: %s\n", move->PatlName);
    printf("Insurance Company Name: %s\n", move->InsurName);
    printf("Insurance Number: %d\n", move->InsurNumber);
    printf("Hospital Name: %s\n", move->HospName);
    printf("Admiting Nurse: %s\n", move->AdNurse);
    printf("Doctor Seen: %s\n", move->DocSeen);
    printf("Diagnosis: %s\n", move->Diagnosis);
    printf("Triage Ranking: %d\n", move->Triage);
    printf("Cost $: %f\n", move->Cost); 
    puts("\n----------------------------------!\n");

    puts("\nPress any key to go back to menu!\n");
    while ( ( ch = getchar() ) != '\n' && ch != EOF ); 
    getchar();
    menus();

}
struct node *LoadPrev()
{
    struct node *start, *current, *last;
    int count = 0;
    
    move = start;
    while(move->next !=0)
    {
   
        if (count == 0)
        {
            //set up first node. assign start
            current = (struct node *)malloc(sizeof(struct node));
           if (count == 0)
            {
                //set up first node. assign start
                current = (struct node *)malloc(sizeof(struct node));
                if (current == NULL)
                {
                    puts("MEMORY ALLOCATION ERROR. Node1. Exiting...");
                    exit(1);
                }
                start = current;
                count++;
                LoadData(current);
                current->next = 0;
                last = current;
                
            }
            else
            {
                //set up next node. link to last node
                current = (struct node *)malloc(sizeof(struct node));
                if (current == NULL)
                {
                    puts("MEMORY ALLOCATION ERROR. Node1. Exiting...");
                    exit(1);
                }
                count++;
                LoadData(current);
                current->next = 0;
                last->next = current;
                last = current;
            }          
        }
        return start;
    }

}
void LoadData(struct node *current)
{
   
    char line[RSIZ][LSIZ];
    int ch;
    int def = 0;
    int i = 0;
    int tot = 0;
    counter();

    strtok("patient1.txt", "\n");
    f1=fopen("patient1.txt","r");
    int c = fgetc(f1);
    ch = getc(f1); 

    while(fgets(line[i], LSIZ, f1)) 
    {
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }

        //Name reading and saving
        for (i=0; i<count_lines; i = i+11)
        {   
            strcpy(current->PatfName, line[i]); 
            printf("First name: %s\n",current->PatfName);
        }    

        //Last Name reading and saving (%s)
        for (i=1; i<count_lines; i = i+11)
        {   
            strcpy(current->PatlName, line[i]); 
            printf("Last name: %s\n",current->PatlName);
        }   

        //Insur Name reading and saving (%s)
        for (i=2; i<count_lines; i = i+11)
        {
            strcpy(current->InsurName, line[i]); 
            printf("Insurance Name: %s\n",current->InsurName);
        }  
        /*
        //Insur Number reading and saving (%d)
        
        for (i=4; i != 0; i+11)
        {
            if (line [i] != EOF)
            {
            current->InsurNumber = line[i]; 
            }
            else 
            {
                i=0; 
            }

        } 

        //Hospital Name reading and saving (%s)
        
        for (i=5; i != 0; i+11)
        {
            if (line [i] != EOF)
            {
            strcpy(current->HospName, line[i]); 
            }
            else 
            {
                i=0; 
            }

        } 
        
        //Nurse Name reading and saving (%s)
        for (i=6; i != 0; i+11)
        {
            if (line [i] != EOF)
            {
            strcpy(current->AdNurse, line[i]); 
            }
            else 
            {
                i=0; 
            }

        } 

        //Doctor's Name reading and saving (%s)
        for (i=7; i != 0; i+11)
        {
            if (line [i] != EOF)
            {
            strcpy(current->DocSeen, line[i]); 
            }
            else 
            {
                i=0; 
            }

        } 

        //Diagnosis reading and saving (%s)
        for (i=8; i != 0; i+11)
        {
            if (line [i] != EOF)
            {
            strcpy(current->Diagnosis, line[i]); 
            }
            else 
            {
                i=0; 
            }

        } 

        //Triage reading and saving (%d)
        for (i=9; i != 0; i+11)
        {
            if (line [i] != EOF)
            {
            current->Triage = line[i]; 
            }
            else 
            {
                i=0; 
            }

        } 

        //Cost reading and saving (%f)
        for (i=10; i != 0; i+11)
        {
            if (line [i] != EOF)
            {
            current->Cost = strtod(line[i], &tmp);
            }
            else 
            {
                i=0; 
            }

        } 


        //Triage reading and saving (%d)
        for (i=11; i != 0; i+11)
        {
            if (line [i] != EOF)
            {
            current->Id = line[i]; 
            }
            else 
            {
                i=0; 
            }

        } 
    */
    fclose(f1);
       
    //system("clear");
    
    puts("Job Done!");   
    while ( ( ch = getchar() ) != '\n' && ch != EOF );    
    puts("All data saved. Press any key to go back to menu"); 
    getchar();
    menus();
    
}
counter()
