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
#define LSIZ 128 
#define RSIZ 10
struct node 
{
    char HospName [150];
    char AdNurse [150];
    char DocSeen [150];
    char Diagnosis [150];
    char PatfName[150]; 
    char PatlName[150];
    char InsurName[150];
    int Triage;
    float Cost;
    int InsurNumber;
	struct node* next;
};
struct node *start, *current, *last, *actual, *tail;
struct node * GenerateLinkedList();
void FillStructData(struct node *current);
struct node * LoadPrev();
struct node * LoadPrev2();
void LoadData(struct node *current);
void LoadData2(struct node *current);

struct node *move;
struct node *temp;
struct node tmp;
char chr;
int count_lines;
int count = 0, flag = 0;

    //global variables test
    int ifn = 0; //i First name 
    int iln = 0; // i Last name
    int iin = 0; // i Insurance Name
    int iinr = 0; // i Insurance Number
    int ihn = 0; // i Hospital Name
    int inn = 0; // i Nurse Name
    int ids = 0; // i Doc Seen
    int idg = 0; // i Diagnosis
    int itg = 0;// i Triage
    int ict = 0; // i Cost
    int iii = 0;
    int newCounter = 0;


int main()
{
    topmenu();
}
topmenu()
{
    //Main funcrion only greeds the user and makes him selec between 2 options.
    
    int option;
    system("clear");
    puts("\t\t\t\t HOSPITAL DATABASE");
    puts("\t\t\t\t CREATED BY: FELIPE S GIL");
    printf("\nWhat would you like to do?\n");
    printf("\n[1] Load Previusly Stored Data  \n");
    printf("\n[2] Start With New Data   \n");
    scanf("%d",&option);
    if(option == 1)
    {
        LoadPrev2();
        menus();
    }
    else if (option == 2)
    {
        start = GenerateLinkedList();
        menus();
    }
    
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

        puts("[I] Go Back to Main Menu\n");

      
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
            Edit();
            break;

            case 'c':
            case 'C':
            Delldata();
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
            Sort();
            break; 

            case'h':
            case'H':
            Tally();
            break; 
            
            case'i':
            case'I':
            topmenu();
            break; 

            default:
            break;
            }

}

struct node *GenerateLinkedList()
{
        
        char choose = 'y';
        int ch;
        system("clear");
        if (flag != 0)
        {
            current = start;

            while (current != NULL)
            {
                current = current->next;
            }
        }

        
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
            system("clear");
            puts("All Done!");
            puts("Enter New Patient? [y/n] ");
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
    char ch;

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
            printf("Cost $: %.2f\n", move->Cost); 
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
            printf("Cost $: %.2f\n", move->Cost); 
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
    char ch;
    move = start;
    while(move->next !=NULL)
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
        printf("Cost $: %.2f\n", move->Cost); 

        move = move->next;
    }
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
    printf("Cost $: %.2f\n", move->Cost); 
    puts("\n----------------------------------!\n");
    
    puts("\nPress any key to go back to menu!\n");
    while ( ( ch = getchar() ) != '\n' && ch != EOF ); 
    getchar();
    menus();

}
struct node *LoadPrev()
{
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
            system("clear");
            puts("All Done!");
            puts("To go bach to menu press [Y] ");
            scanf("%c", &choose);
            while ( ( ch = getchar() ) != '\n' && ch !=EOF );
            
            
        }
        return start;
        
}
struct node *LoadPrev2()
{
    int ch;
    system("clear");
    int limit= 0;
    int iss = 0;
    counter();
    printf("%d\n", count_lines);
    limit = ((count_lines)/10);   
    printf("%d\n",limit);

    while (iss != limit)
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
            LoadData2(current);
            count++;
            newCounter++;
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
            LoadData2(current);
            current->next = 0;
            last->next = current;
            last = current;
            count++;
            newCounter++;

            system("clear");          
        }
        iss++;
    }    
    return 0;
    count = 0;
}
void LoadData2(struct node *current)
{
    char line[RSIZ][LSIZ];
    int ch;
    int def = 0;
    int tot = 0;

    f1=fopen("patient1.txt","r");
    strtok("patient1.txt", "\n");
    int c = fgetc(f1);
    ch = getc(f1); 
    
    if (newCounter == 0)
    {  
        while(fgets(line[iii], LSIZ, f1)) 
        {
        line[iii][strlen(line[iii]) - 1] = '\0';
        iii++;
        }
    }
    //Name reading and saving
    if (newCounter == 0)
    {   
        ifn = 0;
        strcpy(current->PatfName, line[ifn]); 
        printf("First name: %s\n",current->PatfName);
    }
    else
    {   
        ifn = ifn + 10;
        strcpy(current->PatfName, line[ifn]); 
        printf("First name: %s\n",current->PatfName);
    }
    //Last Name reading and saving (%s)    
    if (newCounter == 0)
    {   
        iln = 1;
        strcpy(current->PatlName, line[iln]); 
        printf("Last name: %s\n",current->PatlName);
    }
    else
    {
        iln = iln + 10;
        strcpy(current->PatlName, line[iln]); 
        printf("Last name: %s\n",current->PatlName);
    }
    //Insur Name reading and saving (%s)
    if (newCounter == 0)
    {   
        iin = 2;
        strcpy(current->InsurName, line[iin]); 
        printf("Insurance name: %s\n",current->InsurName);
    }
    else
    {
        iin = iin + 10;
        strcpy(current->InsurName, line[iin]); 
        printf("Insurance name: %s\n",current->InsurName);
    }
    //Insur Number reading and saving (%d) 
    if (newCounter == 0)
    {   
        iinr = 3;
        current->InsurNumber = atoi(line[iinr]); 
        printf("Insurance Number: %d\n",current->InsurNumber);
    }
    else
    {
        iinr = iinr + 10;
        current->InsurNumber = atoi(line[iinr]);  
        printf("Insurance Number: %d\n",current->InsurNumber);
    }
    //Hospital Name reading and saving (%s)   
    if (newCounter == 0)
    {   
        ihn = 4;
        strcpy(current->HospName, line[ihn]); 
        printf("Hospital name: %s\n",current->HospName); 
    }
    else
    {
        ihn = ihn + 10;
        strcpy(current->HospName, line[ihn]); 
        printf("Hospital name: %s\n",current->HospName);
    }
    //Nurse Name reading and saving (%s)    
    if (newCounter == 0)
    {   
        inn = 5;
        strcpy(current->AdNurse, line[inn]); 
        printf("Nurse name: %s\n",current->AdNurse);
    }
    else
    {
        inn = inn + 10;
        strcpy(current->AdNurse, line[inn]); 
        printf("Nurse name: %s\n",current->AdNurse);
    }
    //Doctor's Name reading and saving (%s)
    if (newCounter == 0)
    {   
        ids = 6;
        strcpy(current->DocSeen, line[ids]); 
        printf("Doctor name: %s\n",current->DocSeen);
    }
    else
    {
        ids = ids + 10;
        strcpy(current->DocSeen, line[ids]); 
        printf("Doctor name: %s\n",current->DocSeen);
    }
    //Diagnosis reading and saving (%s)
    if (newCounter == 0)
    {   
        idg = 7;
        strcpy(current->Diagnosis, line[idg]); 
        printf("Diagnosis: %s\n",current->Diagnosis);   
    }
    else
    {
        idg = idg + 10;
        strcpy(current->Diagnosis, line[idg]); 
        printf("Diagnosis: %s\n",current->Diagnosis);
    }
    //Triage reading and saving (%d)
    if (newCounter == 0)
    {   
        itg = 8;
        current->Triage = atoi(line[itg]); 
        printf("Triage: %d\n",current->Triage);  
    }
    else
    {
        itg = itg + 10;
        current->Triage = atoi(line[itg]); 
        printf("Triage: %d\n",current->Triage);
    }
    //Cost reading and saving (%f)
    if (newCounter == 0)
    {   
        ict = 9;
        current->Cost = strtod(line[ict], &tmp);
        printf("Cost: %f\n",current->Cost);
    }
    else
    {
        ict = ict + 10;
        current->Cost = strtod(line[ict], &tmp); 
        printf("Cost: %f\n",current->Cost);
    }

    fclose(f1);
       
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
        for (i=0; i<count_lines; i = i+10)
        {   
            strcpy(current->PatfName, line[i]); 
            printf("First name: %s\n",current->PatfName);
        }    

        //Last Name reading and saving (%s)
        for (i=1; i<count_lines; i = i+10)
        {   
            strcpy(current->PatlName, line[i]); 
            printf("Last name: %s\n",current->PatlName);
        }   

        //Insur Name reading and saving (%s)
        for (i=2; i<count_lines; i = i+10)
        {
            strcpy(current->InsurName, line[i]); 
            printf("Insurance Name: %s\n",current->InsurName);
        }  

        //Insur Number reading and saving (%d)
        for (i=3; i<count_lines; i = i+10)
        {
            current->InsurNumber = atoi(line[i]); 
            printf("Insurance Number: %d\n",current->InsurNumber);
        } 

        //Hospital Name reading and saving (%s)
        for (i=4; i<count_lines; i = i+10)
        {
            strcpy(current->HospName, line[i]); 
            printf("Hospital Name: %s\n",current->HospName);
        } 
   
        //Nurse Name reading and saving (%s)
        for (i=5; i<count_lines; i = i+10)
        {
            strcpy(current->AdNurse, line[i]); 
            printf("Admiting Nurse: %s\n",current->AdNurse);
        } 
 
        //Doctor's Name reading and saving (%s)
        for (i=6; i<count_lines; i = i+10)
        {
            strcpy(current->DocSeen, line[i]); 
            printf("Doctor Seen: %s\n",current->DocSeen);
        } 

        //Diagnosis reading and saving (%s)
        for (i=7; i<count_lines; i = i+10)
        {
            strcpy(current->Diagnosis, line[i]); 
            printf("Diagnosis: %s\n",current->Diagnosis);
        } 
        
        //Triage reading and saving (%d)
        for (i=8; i<count_lines; i = i+10)
        {
            current->Triage = atoi(line[i]); 
            printf("Triage: %d\n",current->Triage);
        } 
  
        //Cost reading and saving (%f)
        for (i=9; i<count_lines; i = i+10)
        {
            current->Cost = strtod(line[i], &tmp);
            printf("Price $: %f\n",current->Cost);
        } 

    fclose(f1);
}

counter()
{
    char ch;
    f1 = fopen("patient1.txt", "r");
   //extract character from file and store in chr
    while(!feof(f1))
    {
        ch = fgetc(f1);
        if(ch == '\n')
        {
            count_lines++;
        }
    }
    fclose(f1);

    return 0;
}
Edit()
{
    char search[100];
    int result=0, ccount=0, temp =0;
    char Choice;
    char ch;
    

    puts("\nPATIENT EDIT AREA!\n");
    puts("\nPlease, inform the FIRST name of the patient\n");
    scanf("%s", &search);
    
    move = start;
        while(move->next !=NULL)
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
            printf("----------------------------------- ");
            printf("\nWhat field would like to EDIT?\n");
            printf("[A] First Name\n");
            printf("[B] Last Name\n");
            printf("[C] Insurance Company Name\n");
            printf("[D] Insurance Number\n");
            printf("[E] Hospital Name\n");
            printf("[F] Admiting Nurse\n");
            printf("[G] Doctor Seen\n");
            printf("[H] Diagnosis\n");
            printf("[I] Triage Ranking\n");
            printf("[J] Cost\n");
            printf("Choice : ");
            scanf("%s", &Choice);

            while(Choice !='a' && Choice != 'A' && Choice != 'b' && Choice != 'B' && Choice != 'c' 
            && Choice != 'C' && Choice != 'd' && Choice != 'D' && Choice != 'e' && Choice != 'E'
            && Choice != 'f' && Choice != 'F' && Choice != 'g' && Choice != 'G'&& Choice != 'h' 
            && Choice != 'H' && Choice != 'i' && Choice != 'I'&& Choice != 'j' && Choice != 'J')
            {
                puts("\n INVALID INPUT TRY AGAIN!");
                printf("\n Choice :  ");
                scanf("%c", &Choice);
            }

            switch (Choice)
            {
                //First Name
                case 'a':
                case 'A':
                printf("New First Name: ");
                scanf("%s", move->PatfName);
                break;
                //Last Name
                case 'b':
                case 'B':
                printf("New Last Name: ");
                scanf("%s", move->PatlName);  
                break;
                //Insur Comp Name
                case 'c':
                case 'C':
                printf("New Insurance Company Name: ");
                scanf("%s", move->InsurName);  
                break;
                //Insur Number
                case 'd': 
                case'D':
                printf("New Insurance Number: ");
                scanf("%d", &move->InsurNumber);  
                break;
                //Hosp Name
                case'e':
                case'E':
                printf("New Hospital Name: ");
                scanf("%s", move->HospName);  
                break; 
                //Nurse Name
                case'f':
                case'F':
                printf("New Admiting Nurse: ");
                scanf("%s", move->AdNurse);  
                break; 
                //Doc Seen
                case'g':
                case'G':
                printf("New Doctor Seen: ");
                scanf("%s", move->DocSeen); 
                break; 
                //Diagnosis
                case'h':
                case'H':
                printf("New Diagnosis: ");
                scanf("%s", move->Diagnosis); 
                break; 
                //Tiage Ranking
                case'i':
                case'I':
                printf("New Triage Ranking: ");
                scanf("%d", &move->Triage); 
                break; 
                //Cost
                case'j':
                case'J':
                printf("New Cost: ");
                scanf("%f", &move->Cost); 
                break; 

                default:
                break;
            }
  
            ccount = 1;
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
            printf("----------------------------------- ");
            printf("\nWhat field would like to EDIT?\n");
            printf("[A] First Name\n");
            printf("[B] Last Name\n");
            printf("[C] Insurance Company Name\n");
            printf("[D] Insurance Number\n");
            printf("[E] Hospital Name\n");
            printf("[F] Admiting Nurse\n");
            printf("[G] Doctor Seen\n");
            printf("[H] Diagnosis\n");
            printf("[I] Triage Ranking\n");
            printf("[J] Cost\n");
            printf("Choice : ");
            scanf("%s", &Choice);

            while(Choice !='a' && Choice != 'A' && Choice != 'b' && Choice != 'B' && Choice != 'c' 
            && Choice != 'C' && Choice != 'd' && Choice != 'D' && Choice != 'e' && Choice != 'E'
            && Choice != 'f' && Choice != 'F' && Choice != 'g' && Choice != 'G'&& Choice != 'h' 
            && Choice != 'H' && Choice != 'i' && Choice != 'I'&& Choice != 'j' && Choice != 'J')
            {
                puts("\n INVALID INPUT TRY AGAIN!");
                printf("\n Choice :  ");
                scanf("%c", &Choice);
            }

            switch (Choice)
            {
                //First Name
                case 'a':
                case 'A':
                printf("New First Name: ");
                scanf("%s", move->PatfName);
                break;
                //Last Name
                case 'b':
                case 'B':
                printf("New Last Name: ");
                scanf("%s", move->PatlName);  
                break;
                //Insur Comp Name
                case 'c':
                case 'C':
                printf("New Insurance Company Name: ");
                scanf("%s", move->InsurName);  
                break;
                //Insur Number
                case 'd': 
                case'D':
                printf("New Insurance Number: ");
                scanf("%d", &move->InsurNumber);  
                break;
                //Hosp Name
                case'e':
                case'E':
                printf("New Hospital Name: ");
                scanf("%s", move->HospName);  
                break; 
                //Nurse Name
                case'f':
                case'F':
                printf("New Admiting Nurse: ");
                scanf("%s", move->AdNurse);  
                break; 
                //Doc Seen
                case'g':
                case'G':
                printf("New Doctor Seen: ");
                scanf("%s", move->DocSeen); 
                break; 
                //Diagnosis
                case'h':
                case'H':
                printf("New Diagnosis: ");
                scanf("%s", move->Diagnosis); 
                break; 
                //Tiage Ranking
                case'i':
                case'I':
                printf("New Triage Ranking: ");
                scanf("%d", &move->Triage); 
                break; 
                //Cost
                case'j':
                case'J':
                printf("New Cost: ");
                scanf("%f", &move->Cost); 
                break; 

                default:
                break;
            }
  
            ccount = 1;
        }
        if (ccount == 0)
        {
            puts("\nSorry, patient not found.\n");
            while ( ( ch = getchar() ) != '\n' && ch != EOF ); 
            puts("\nPress any key to go back to menu.");
            getchar();
            menus();
        }
        else
        {
            puts("\nPress any key to go back to menu!\n");
            while ( ( ch = getchar() ) != '\n' && ch != EOF ); 
            getchar();
            menus();
        }   
    return 0;  
}
Sort()
{
    char ch;
    move = start;
    while(move->next !=0)
    {
       
        if (move->Triage == 1)
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
        }
        move = move->next;
      
    }
    if (move->next == 0 && move->Triage ==1)
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
    }
    move = start;
    while(move->next !=0)
    {

        if (move->Triage == 2)
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
        }
        move = move->next;

    }
    if (move->next == 0 && move->Triage ==2)
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
    }
    move = start;
    while(move->next !=0)
    {
       
        if (move->Triage == 3)
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
        }
        move = move->next;   
    }
    if (move->next == 0 && move->Triage ==3)
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
    }
    move = start;
    while(move->next !=0)
    {
       

        if (move->Triage == 4)
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
        }
         move = move->next;
    }
    if (move->next == 0 && move->Triage ==4)
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
    }
    move = start;
    
    while(move->next !=0)
    {
       
        if (move->Triage == 5)
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
        }
        move = move->next;
    }
    if (move->next == 0 && move->Triage ==5)
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
    }

    
    puts("\nPress any key to go back to menu!\n");
    while ( ( ch = getchar() ) != '\n' && ch != EOF ); 
    getchar();
    menus();

}
Tally()
{
    char ch;
    double sum;
    puts("\nTALLY UP MONTH EARNINGS!\n");

    move = start;
    while(move->next !=0)
    {
        sum = sum + move->Cost; 
        move = move->next;
    }       
    sum = sum + move->Cost; 

    printf("The total is  $: %.2f\n", sum); 
    while ( ( ch = getchar() ) != '\n' && ch != EOF ); 
    puts("\nPress any key to go back to menu!\n");
    getchar();
    menus();
    return 0;      
}
Delldata()
{
    char ch;
    char choose[100];
    actual = start;
    tail = start->next;
    puts("DELETE PATIENT");
    puts("whats the FIRST NAME of the patient to be DELETED?");
    scanf("%s", &choose);
    // First case 
    // The data that should be deleted is the first node
    if(strcmp(actual->PatfName, choose)==0)
    {
        start = tail;
        free(actual);
    }
    else
    {
        // Seccond case
        // The data that should be deleted is the middle node 
        while(strcmp(tail->PatfName, choose) != 0)
        {
            tail = tail->next;
            actual = actual->next;
            flag++;
        }

        // Third case 
        // The data that should be deleted is the last node

        if (tail->next == NULL)
        {
            actual->next = NULL;
            free(tail);
            flag++;
        }

        else
        {
            actual->next = tail->next;
            free(tail);
            flag++;
        }
        
    }
    puts("Job Done");
    while ( ( ch = getchar() ) != '\n' && ch != EOF ); 
    puts("\nPress any key to go back to menu!\n");
    getchar();
    menus();
    return 0;

}
