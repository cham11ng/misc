
/***********************************************************
 *           STUDENT DATABASE MANAGEMENT SYSTEM            *
 *                     MINI PROJECT                        *
 *                         IN C                            *
 **********************************************************/

/***********************************************************
 *  FILE    : SDMS.C                                       *
 *  AUTHOR  : Sagar Chamling, Subodh Pradhan, Samir KC     *
 *  ROLL NO : 2069/BCT/23,    2069/BCT/34,    2069/BCT/25  *
 *  DATE    : 2013-01-17                                   *
 **********************************************************/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#define MAX 200
#define RECLEN 200
#define pfn "PASSWORD.DAT"
#define rfn "RECORD.DAT"

/** PASSWORD STRUCTURE **/
typedef struct userpass
{
    char dis[MAX];
    char user[MAX];
    char pass[MAX];
} user;

/** STUDENT RECORD STRUCTURE **/
typedef struct student
{
    char name[MAX];
    char roll[MAX];
    char address[MAX];
    char faculty[MAX];
    char course[MAX];
    char group;
    char phone[MAX];
} record;

/*** FUNCTION DECLERATION ***/
void home(FILE *);
void login(FILE *);
void adminmode(char *, FILE *);
void membmode(char *, FILE *);
void addmember();
void setpass(char *, char *, char *, char *);
void changepass(FILE *);
void reset();
int getPassWord(char *);

/** Top Five Function **/
void addrec();
void editrec();
void viewrec();
void findrec();
void delrec();

void disprec(record);
void readrec(record *);
void sort();

void gotoxy(short, short);
void textcolor(short);

FILE * pfp, * fptr, * nfp; //file pointer
int test, flag;
char choice, other, input[MAX], conpass[MAX];

/** MAIN **/
int main()
{
    system("cls");
    pfp=fopen(pfn, "rb+");
    if (pfp==NULL)
        home(pfp);
    else
        login(pfp);
    fclose(pfp);
    textcolor(15);
    gotoxy(25, 19); printf("Thanks For Using This Program \n");
    getch();
    return 0;
}

void home(FILE * pfp)
{
    user unp;
    system("cls");
    flag=1;
    textcolor(13); printf(" \n\n\t\t    *** STUDENT DATABASE MANAGEMENT SYSTEM ***");
    textcolor(15);
    gotoxy(27,5); printf(" 1 >> Set Admin Password ");
    gotoxy(27,7); printf(" I >> Information        ");
    gotoxy(27,9); printf(" 0 >> Quit               ");
    while(flag)
    {
        gotoxy(32,15); printf(" Choice? ");
        fflush(stdin); choice = getche();
        switch(choice)
        {
            case '1': // Set Admin Password
                while(1)
                {
                    system("cls");
                    textcolor(13); printf("\n\n\n\t\t\t  *** SET ADMIN PASSWORD ***");
                    setpass(unp.dis, unp.user, unp.pass, conpass);
                    textcolor(12);
                    if(strcmp("admin", unp.user) == 0)
                    {
                        if(strcmp(unp.pass, conpass) == 0)
                            break; // to break while loop
                        else
                            printf("\n\t\t\t\tPassword Not Matched :/ ");
                    }
                    else
                        printf("\n\t\t\tInvalid, Username must be \" admin \"");
                    getch();
                }
                fclose(pfp); // closing file that was opened in rb+ mode
                pfp=fopen(pfn,"wb+");
                if(fwrite( &unp, sizeof(unp), 1, pfp))
                {
                    textcolor(10);
                    printf("\n\n\t\t\tPassword Set Successfully ^_^ ");
                    getch();
                    login(pfp);
                }
                flag=0; // stoping outer while loop
                break;

            case 'I':
            case 'i':
                system("cls");
                printf("\n\n\t\t\t STUDENT DATABASE MANAGEMENT SYSTEM \n\n\t\t\t\t ALL RIGHT RESERVED");
                printf("\n\n\t\t\t\t   Developed By :");
                printf("\n\n\t\t\t Sagar Chamling Rai  (2069/BCT/23)");
                printf("\n\n\t\t\t Samir KC            (2069/BCT/25)");
                printf("\n\n\t\t\t Subodh Pradhan      (2069/BCT/34)");
                printf("\n\n\t\t\t Maha Laxmi          (2069/BCT/16)");
                getch();
                home(pfp);
                flag=0;
                break;

            case '0': // Exit
                flag=0;
                break;

            default:
                printf("\b \b\a"); // remove invalid choice and alert
                break;
        }
    }
}

void adminmode(char dname[], FILE * pfp)
{
    flag=1;
    system("cls");
    textcolor(13);
    gotoxy(15,3); printf(" -> WELCOME %s <- ", dname);
    textcolor(7);
    gotoxy(15, 5); printf(" 1 >> ADD RECORD      ");
    gotoxy(40, 5); printf(" 2 >> EDIT RECORD     ");
    gotoxy(15, 7); printf(" 3 >> VIEW RECORDS    ");
    gotoxy(40, 7); printf(" 4 >> FIND RECORD     ");
    gotoxy(15, 9); printf(" 5 >> REMOVE RECORD   ");
    gotoxy(40, 9); printf(" 6 >> ADD MEMBER      ");
    gotoxy(15,11); printf(" 7 >> RESET RECORD    ");
    gotoxy(40,11); printf(" 8 >> CHANGE PASSWORD ");
    gotoxy(29,13); printf(" 9 >> LOG OUT   ");
    gotoxy(30,15); printf(" 0 >> EXIT ");
    while(flag)
    {
        textcolor(6);
        gotoxy(31,17); printf(" Choice? ");
        choice=getche();
        switch(choice)
        {
            case '1':
                addrec(); flag=0; // stoping while loop
                break;

            case '2':
                editrec(); flag=0;
                break;

            case '3':
                viewrec(); flag=0;
                break;

            case '4':
                findrec(); flag=0;
                break;

            case '5':
                delrec(); flag=0;
                break;

            case '6':
                addmember(); flag=0;
                break;

            case '7':
                reset(); flag=0;
                break;

            case '8':
                changepass(pfp);
                flag=0;
                break;

            case '9':
                login(pfp); flag=0;
                break;

            case '0':
                flag=0;
                break;

            default:
                printf("\b \b \a"); break;

        }
    }
    if(choice != '0' && choice != '9')
        adminmode(dname, pfp);
}

void membmode(char dname[], FILE * pfp)
{
    flag=1;
    system("cls");
    textcolor(13);
    gotoxy(23,3); printf(" -> WELCOME %s <- ", dname);
    textcolor(7);
    gotoxy(30, 5); printf(" 1 >> LIST RECORD     ");
    gotoxy(30, 7); printf(" 2 >> FIND RECORD     ");
    gotoxy(30, 9); printf(" 3 >> CHANGE PASSWORD ");
    gotoxy(30,11); printf(" 4 >> LOG OUT         ");
    gotoxy(30,13); printf(" 0 >> EXIT            ");
    while(flag)
    {
        textcolor(6);
        gotoxy(32,15); printf(" CHOICE? ");
        choice=getche();
        switch(choice)
        {
            case '1':
                viewrec(); flag=0;
                break;

            case '2':
                findrec(); flag=0;
                break;

            case '3':
                system("cls");
                changepass(pfp);
                flag=0;
                break;

            case '4':
                login(pfp); flag=0;
                break;

            case '0':
                flag=0;
                break;

            default:
                printf("\b \b\a"); break;
        }
    }
    if(choice != '0' && choice != '4')
        membmode(dname, pfp);
}

/** FUNCTION TO ADD MEMBER **/
void addmember()
{
    user unp;
    flag=1;
    system("cls");
    pfp=fopen(pfn, "ab+");
    while(flag)
    {
        textcolor(13);
        gotoxy(30, 3); printf("*** NEW MEMBER ***");
        setpass(unp.dis, unp.user, unp.pass, conpass);
        if( strcmp(unp.pass, conpass) ==0 && strcmp(unp.user,"admin")!=0)
            flag=0; // stopping while loop
        else
        {
            system("cls");
            textcolor(12);
            gotoxy(13, 13); printf("Confirm Username is not admin and Password is matched :/ ");
        }
    }
    gotoxy(25, 15);
    if(fwrite( &unp, sizeof(unp), 1, pfp))
        printf("Member Added Successfully ... ^_^ ");
    getch();
    fclose(pfp);
}

/** LOG IN FUNCTION**/
void login(FILE * pfp)
{
    user unp;
    system("cls");
    char user[MAX], pass[MAX], username[]="admin";
    test=1;
    textcolor(13);
    printf("\n\n\n\n\t\t\t\t*** NEW LOG IN ***");
    textcolor(7);
    gotoxy(27, 7); printf("Enter Username : ");
    gotoxy(27, 9); printf("Enter Password : ");
    textcolor(8);
    gotoxy(44, 7); fflush(stdin); gets(user);
    gotoxy(44, 9); fflush(stdin); getPassWord(pass);
    rewind(pfp);
    while (fread(&unp, sizeof(unp), 1, pfp))
    {
        if (strcmp(pass, unp.pass)==0 && strcmp(username, user)==0)
        {
            if(strcmp(username, unp.user)==0)
            {
                adminmode(unp.dis, pfp);
                test=0;
                break;
            }
        }
        else if (strcmp(pass, unp.pass)==0 && strcmp(user, unp.user)==0)
        {
            membmode(unp.dis, pfp);
            test=0;
            break;
        }
    }
    if(test)
    {
        textcolor(12);
        printf("\n\n\t\t\t\t  Login Failed !!! \a");
        textcolor(6);
        printf("\n\n\t\t\t\tTry Again? (Y/N) : ");
        fflush(stdin);
        other=getche();
        if (other == 'y' || other == 'Y')
            login(pfp);
    }
}

void addrec()
{
    record rec;
    fptr=fopen(rfn, "ab+");
    other='y';
    while( other=='Y' || other=='y' )
    {
        system("cls");
        textcolor(13);
        printf("\n\n\t\t\t\t** NEW RECORD **");
        readrec(&rec);
        if(fwrite( &rec, sizeof( rec ), 1, fptr ))
            printf("\n\t\t\tRecord Added Successfully !!!");
        else
            printf("\n\t\t\tOpps!!! No Record Added");

        printf("\n\n\t\t\tAdd More Record (Y/N) : ");
        fflush(stdin); other=getche();
    }
    fclose(fptr);
}

void editrec()
{
    record rec;
    fptr=fopen(rfn, "rb+");
    other='y';
    while( other=='y' || other=='Y')
    {
        system("cls");
        test=1;
        textcolor(13);
        printf("\n\n\t\t\t\t** EDIT RECORD **");
        textcolor(7);
        printf("\n\n\t\t  Name of Student to EDIT : ");
        fflush(stdin); gets(input);
        while( fread( &rec, sizeof( rec ), 1, fptr ))
        {
            if(strcmp(input, rec.name) == 0)
            {
                printf("\n");
                disprec(rec);
                textcolor(6); printf("\n\t\t\tEdit This Record? (Y/N) : ");
                fflush(stdin); choice=getche();
                if(choice=='y' || choice=='Y')
                {
                    textcolor(13);
                    printf("\n\n\t\t\t\t** NEW **");
                    readrec(&rec);
                    fseek( fptr, - sizeof(rec), SEEK_CUR );
                    textcolor(10);
                    if(fwrite( &rec, sizeof( rec ), 1, fptr ))
                        printf("\n\n\t\t  %s Record Edited Successfully !!!", input);
                    test=0; // to know record was found
                    break;
                }
            }
        }
        textcolor(12);
        if(test)
            printf("\n\n\t\t\tNot Found ");
        textcolor(6);
        printf("\n\n\t\t\tEdit Another Record (Y/N) : ");
        fflush(stdin); other=getche();
        rewind(fptr);
    }
    fclose(fptr);
}

void viewrec()
{
    record rec[RECLEN];
    int i=0, n=0; // n variable stores total no. of record
    system("cls");
    textcolor(13);
    printf("\n\n\t\t\t\t** VIEW RECORD **\n");
    fptr=fopen(rfn, "rb+");
    if(fptr == NULL)
        printf("\n\n\t\t\t\tNo Records '~' :/");
    else {
        while(fread(&rec[n++], sizeof(*rec), 1, fptr))
        sort(rec, n);
        while(i < n-1)
            disprec(rec[i++]);
    }
    fclose(fptr);
    getch();
}

void findrec()
{
    record rec;
    system("cls");
    textcolor(13);
    printf("\n\n\t\t\t\t** SEARCH RECORD **");
    fptr=fopen(rfn, "rb+");
    other='y';
    while( other == 'y' || other == 'Y' ) {
        textcolor(7); printf("\n\n\t\t\tName of Student to Find : ");
        fflush(stdin); gets(input);
        test=1;
        while(fread( &rec, sizeof( rec ), 1, fptr )) {
            if( strcmp(input, rec.name) == 0 ) {
                disprec(rec);
                printf("\n");
                test=0;
            }
        }
        textcolor(12);
        if(test)
            printf("\n\t\t\tNot Found\n");
        textcolor(6); printf("\n\t\t\tSearch Again? (Y/N) : ");
        fflush(stdin);
        other=getche();
        rewind(fptr);
        system("cls");
    }
    fclose(fptr);
}

void delrec()
{
    record rec;
    other='y';
    while( other == 'y' || other == 'Y' ) {
        system("cls");
        test=1;
        textcolor(13);
        printf("\n\n\t\t\t\t** REMOVE RECORD **");
        fptr=fopen(rfn, "rb+");
        nfp=fopen("temp.dat", "wb+");
        textcolor(7);
        printf("\n\n\t\t  Name of Student to remove: ");
        fflush(stdin); gets(input);
        while(fread(&rec, sizeof( rec ), 1, fptr))
        {
            if( strcmp( input, rec.name) == 0 )
            {
                printf("\n");
                disprec(rec);
                textcolor(6);
                printf("\n\t\t\tDelete This Record? (Y/N) : ");
                fflush(stdin); choice=getche();
                if(choice=='y' || choice=='Y')
                    test=0;
                else
                    fwrite( &rec, sizeof( rec ), 1, nfp);
            }
            else
                fwrite( &rec, sizeof( rec ), 1, nfp);
        }
        fclose(nfp);
        fclose(fptr);
        if(test) // test whether record was found or not
        {
            textcolor(12); printf("\n\n\t\t\tNot Found");
            remove("temp.dat");
        }
        else if(remove(rfn)==0 && rename( "temp.dat", rfn)==0)
        {
            textcolor(10); printf("\n\n\t\t  %s Record Deleted Successfully ^_^", input);
        }
        textcolor(6);
        printf("\n\n\t\t\tDelete Another Records? (Y/N) : ");
        fflush(stdin);
        other=getche();
    }
}

void disprec(record rec)
{
    textcolor(7);
    printf("\n\t\t\tName     : ");
    printf("%1.20s", rec.name);
    printf("\n\t\t\tRoll no  : ");
    printf("%1.20s", rec.roll);
    printf("\n\t\t\tFaculty  : ");
    printf("%1.20s", rec.faculty);
    printf("\n\t\t\tAddress  : " );
    printf("%1.20s", rec.address);
    printf("\n\t\t\tCourse   : ");
    printf("%1.20s", rec.course);
    printf("\n\t\t\tGroup    : ");
    printf("%1c", rec.group);
    printf("\n\t\t\tPhone No : ");
    printf("%1.20s\n", rec.phone);
}

void readrec(record * rec)
{
    textcolor(7);
    printf("\n\n\t\t\tName     : ");
    fflush(stdin); gets(rec->name);
    printf("\t\t\tRoll no  : ");
    fflush(stdin); gets(rec->roll);
    printf("\t\t\tFaculty  : ");
    fflush(stdin); gets(rec->faculty);
    printf("\t\t\tAddress  : " );
    fflush(stdin); gets(rec->address);
    printf("\t\t\tCourse   : ");
    fflush(stdin); gets(rec->course);
    printf("\t\t\tGroup    : ");
    scanf("%c",&rec->group);
    printf("\t\t\tPhone No : ");
    fflush(stdin); gets(rec->phone);
}

void sort(record * rec, int n)
{
    int i, j;
    record temp;
    for(i=0; i < n-1; i++)
        for(j=i+1; j < n; j++)
            if(strcmp(rec[i].name, rec[j].name) > 0)
            {
                temp=rec[i];
                rec[i]=rec[j];
                rec[j]=temp;
            }
}

void setpass(char * dis, char * user, char * pass, char * conpass)
{
        textcolor(7);
        gotoxy(24, 5); printf( "   DisplayName   : " );
        gotoxy(24, 7); printf( "    UserName     : " );
        gotoxy(24, 9); printf( "    PassWord     : " );
        gotoxy(24,11); printf( "Confirm PassWord : " );
        textcolor(8);
        gotoxy( 44, 5 ); fflush(stdin); gets(dis);
        gotoxy( 44, 7 ); fflush(stdin); gets(user);
        gotoxy( 44, 9 ); fflush(stdin); getPassWord( pass );
        gotoxy( 44, 11); fflush(stdin); getPassWord( conpass );
}

void changepass(FILE * pfp)
{
    char pass[MAX], conpass[MAX];
    user unp;
    system("cls");
    fseek( pfp, - sizeof( unp ), SEEK_CUR ); // to move the cursor just before password structure
    fread(&unp, sizeof(unp), 1, pfp);
    textcolor(8);
    printf("\n\n\n\t\t\tOld Password     : ");
    fflush(stdin); getPassWord(pass);
    if(strcmp(pass, unp.pass) == 0)
    {
            textcolor(7);
            printf("\n\n\t\t\tNew Password     : ");
            fflush(stdin); getPassWord(pass);
            printf("\n\t\t\tConfirm Password : ");
            fflush(stdin); getPassWord(conpass);
            if(strcmp(conpass, pass)==0) {
                strcpy(unp.pass, pass);
                fseek(pfp, - sizeof( unp ), SEEK_CUR);
                if(fwrite(&unp, sizeof(unp), 1, pfp))
                    printf("\n\t\t\tPassword Changed Successfully ^_^");
                else
                    printf("\n\t\t\tPassword Not Changed");
            }
            else
                printf("\n\t\t\tConfirm Password Not Matched");
    }
    else
        printf("\n\n\t\t\tOld Password Not Matched");
    getch();
}

void reset()
{
    system("cls");
    textcolor(7);
    printf("\n\n\n\n\t\tCaution : All Records will be Deleted !!! ");
    printf("\n\n\n\t\tAre you Sure you want to Reset Database ? ");
    fflush(stdin);
    choice=getche();
    textcolor(10);
    if(choice=='y')
    {
        if((remove(rfn)==0))
            printf("\n\n\n\t\t\t\tRecord is Reset");
        else
            printf("\n\n\n\t\t\tNo Records or Access Denied !!! ");
    }
    else
        printf("\n\n\n\t\t\t\tRecord not Reset");
    getch();
}

/** PASSWORD FUNCTION **/
int getPassWord(char * pass)
{
    unsigned char ch;
    int count=0;
    while(1)
    {
        fflush(stdin);
        ch=getch();

        if(ch=='\r' || ch=='\n')
        {
            printf("\n");
            break;
        }

        if(ch=='\b')
        {
            if(count>0)
            {
                printf("\b \b");
                count--;
                pass--;
            }
        }
        else if(ch==224)
            ch=getch(); // to prevent 2 byte input through arrows keys

        else if(ch>=32 && ch<=126)
        {
            *pass=ch;
            printf("x");
            count++;
            pass++;
        }
    }
    *pass='\0';
    return 0;
}

void gotoxy(short col, short row)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {col, row};
	SetConsoleCursorPosition(hConsole, position);
}

void textcolor(short color_value)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color_value);
}
