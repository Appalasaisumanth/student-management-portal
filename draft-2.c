#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define CANDIDATE_COUNT 16
#define BREAKFAST1 "Dosa"
#define BREAKFAST2 "Idli"
#define BREAKFAST3 "Upma"
#define BREAKFAST4 "Puri"
#define lunch1 "Sambar"
#define lunch2 "dahi brinjal"
#define lunch3 "ragmaa"
#define lunch4 "Mix vegcurry"
#define snacks1 "Pav Bhaji"
#define snacks2 "Vada pav"
#define snacks3 "Pani puri"
#define snacks4 "Millets"
#define dinner1 "chicken,paneer"
#define dinner2 "Chicken,mushroom"
#define dinner3 "fish,paneer"
#define dinner4 "Fish,mushroom"
int arr[4][4], brr[4][4], h[4][4];
typedef struct voting
{
    int rolno, rolll;
} voting;
typedef struct student
{
    int rno;
    char name[20];
    char pass[20], iss[500], iss1[500];
    int su1, su2, su3, su4, su5, su6, at1, at2, at3, at4, att;
    float cg;
} student;
void line()
{
    int q;
    for (q = 0; q < 50; q++)
        printf("-");
    printf("\n");
}
void zero()
{
    voting *v;
    int i, j,n=1;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            arr[i][j] = 0;
        }
    }
    FILE *fp,*fp1;
    fp = fopen("su.txt", "w");
    fp1=fopen("vo.txt","w");
    for(i=0;i<n;i++)
    {
       v[i].rolno = 0;
        fflush(stdin);
        v[i].rolll = 0;
        fwrite(&v[i], sizeof(voting), 1, fp1); 
    }
    
    fwrite(arr, sizeof(int), 16, fp);
    fclose(fp);
    fclose(fp1);
}
void votla(int roll)
{
    voting *v;
    int n = 1, i;
    FILE *fp;
    v = (voting *)calloc(n, sizeof(voting));
    fp = fopen("vo.txt", "a");
    for (i = 0; i < n; i++)
    {
        v[i].rolno = roll;
        v[i].rolll = roll;
        fwrite(&v[i], sizeof(voting), 1, fp);
    }
    fclose(fp);
}
void menu()
{
    FILE *fp;
int i,j;
fp=fopen("su.txt","r");
fread(arr,sizeof(int),16,fp);
    int a, b, t;

    for (a = 0; a < 4; a++)
    {
        for (b = 0; b < 4; b++)
        { 
            brr[a][b] = arr[a][b];
        }
 
    }
 
    for (b = 0; b < 4; b++)
    {
        for (a = 0; a < 3; a++)
        {
            if (brr[b][a] > brr[b][a + 1])
            {
                t = brr[b][a + 1];
                brr[b][a + 1] = brr[b][a];
                brr[b][a] = t;
            }
        }
    }
     line();
    printf(ANSI_COLOR_RED "Your breakfast for tomorrow is \n");
    if (arr[0][0] == brr[0][3])
    {
        printf("%s %d\n", BREAKFAST1, brr[0][3]);
    }
    else if (arr[0][1] == brr[0][3])
    {
        printf("%s %d\n", BREAKFAST2, brr[0][3]);
    }
    else if (arr[0][2] == brr[0][3])
    {
        printf("%s %d\n", BREAKFAST3, brr[0][3]);
    }
    else if (arr[0][3] == brr[0][3])
    {
        printf("%s %d\n", BREAKFAST4, brr[0][3]);
    }
    printf(" Your lunch  for tomorrow is \n");
    if (arr[1][0] == brr[1][3])
    {
        printf("%s %d\n", lunch1, brr[1][3]);
    }
    else if (arr[1][1] == brr[1][3])
    {
        printf("%s %d\n", lunch2, brr[1][3]);
    }
    else if (arr[1][2] == brr[1][3])
    {
        printf("%s %d\n", lunch3, brr[1][3]);
    }
    else if (arr[1][3] == brr[1][3])
    {
        printf("%s %d\n", lunch4, brr[1][3]);
    }
    printf(" Your snacks for tomorrow is \n");
    if (arr[2][0] == brr[2][3])
    {
        printf("%s %d\n", snacks1, brr[2][3]);
    }
    else if (arr[2][1] == brr[2][3])
    {
        printf("%s %d\n", snacks2, brr[2][3]);
    }
    else if (arr[2][2] == brr[2][3])
    {
        printf("%s %d\n", snacks3, brr[2][3]);
    }
    else if (arr[2][3] == brr[2][3])
    {
        printf("%s %d\n", snacks4, brr[2][3]);
    }
    printf(" Your dinner is\n");
    if (arr[3][0] == brr[3][3])
    {
        printf("%s %d\n", dinner1, brr[3][3]);
    }
    else if (arr[3][1] == brr[3][3])
    {
        printf("%s %d\n", dinner2, brr[3][3]);
    }
    else if (arr[3][2] == brr[3][3])
    {
        printf("%s %d\n", dinner3, brr[3][3]);
    }
    else if (arr[3][3] == brr[3][3])
    {
        printf("%s %d" ANSI_COLOR_RESET"\n", dinner4, brr[3][3]);
    }
    fclose(fp);
}
void votesCount()
{
    FILE *fp;
    fp=fopen("su.txt","r");
fwrite(arr,sizeof(int),16,fp);
    printf(ANSI_COLOR_YELLOW"\n\n ##### Voting Statics ####");
    printf("\n %s - %d ", BREAKFAST1, arr[0][0]);
    printf("\n %s - %d ", BREAKFAST2, arr[0][1]);
    printf("\n %s - %d ", BREAKFAST3, arr[0][2]);
    printf("\n %s - %d "ANSI_COLOR_RESET, BREAKFAST4, arr[0][3]);
    printf(ANSI_COLOR_GREEN"\n %s - %d ", lunch1, arr[1][0]);
    printf("\n %s - %d ", lunch2, arr[1][1]);
    printf("\n %s - %d ", lunch3, arr[1][2]);
    printf("\n %s - %d "ANSI_COLOR_RESET, lunch4, arr[1][3]);
    printf(ANSI_COLOR_CYAN"\n %s - %d ", snacks1, arr[2][0]);
    printf("\n %s - %d ", snacks2, arr[2][1]);
    printf("\n %s - %d ", snacks3, arr[2][2]);
    printf("\n %s - %d "ANSI_COLOR_RESET, snacks4, arr[2][3]);
    printf(ANSI_COLOR_MAGENTA"\n %s - %d ", dinner1, arr[3][0]);
    printf("\n %s - %d ", dinner2, arr[3][1]);
    printf("\n %s - %d ", dinner3, arr[3][2]);
    printf("\n %s - %d "ANSI_COLOR_RESET, dinner4, arr[3][3]);
    printf("\n");
    fclose(fp);
}
void castvote(int roll)
{

    int choice1,
        choice2,
        choice3,
        choice4;
    
    printf("\n\n ### Please choose your menu ###\n");

    printf(ANSI_COLOR_YELLOW"\n 1. %s", BREAKFAST1);

    printf("\n 2. %s", BREAKFAST2);

    printf("\n 3. %s", BREAKFAST3);

    printf("\n 4. %s"ANSI_COLOR_RESET, BREAKFAST4);
    printf(ANSI_COLOR_GREEN"\n 5. %s", lunch1);
    printf("\n 6. %s", lunch2);
    printf("\n 7. %s", lunch3);
    printf("\n 8. %s"ANSI_COLOR_RESET, lunch4);
    printf(ANSI_COLOR_BLUE"\n 9. %s", snacks1);
    printf("\n 10. %s", snacks2);
    printf("\n 11. %s", snacks3);
    printf("\n 12. %s"ANSI_COLOR_RESET, snacks4);
    printf(ANSI_COLOR_MAGENTA"\n 13. %s", dinner1);
    printf("\n 14. %s", dinner2);
    printf("\n 15. %s", dinner3);
    printf("\n 16. %s\n"ANSI_COLOR_RESET, dinner4);
    line();
    printf(ANSI_COLOR_CYAN"\n\n Input your choice (1 - 4) : "ANSI_COLOR_RESET);
    scanf("%d", &choice1);
    while (choice1 > 4 || choice1 < 1)
    {
        printf(ANSI_COLOR_RED"Enter the choice given in the range :"ANSI_COLOR_RESET);
        scanf("%d", &choice1);
    }
    printf(ANSI_COLOR_MAGENTA"\n\n Input your choice (5 - 8) : "ANSI_COLOR_RESET);
    scanf("%d", &choice2);
    while (choice2 > 8 || choice2 < 5)
    {
        printf(ANSI_COLOR_RED"Enter the choice given in the range :"ANSI_COLOR_RESET);
        scanf("%d", &choice2);
    }
    printf(ANSI_COLOR_YELLOW"\n\n Input your choice (9 - 12) : "ANSI_COLOR_RESET);
    scanf("%d", &choice3);
    while (choice3 > 12 || choice3 < 8)
    {
        printf(ANSI_COLOR_RED"Enter the choice given in the range :"ANSI_COLOR_RESET);
        scanf("%d", &choice3);
    }
    printf(ANSI_COLOR_GREEN"\n\n Input your choice (13 - 16) : "ANSI_COLOR_RESET);
    scanf("%d", &choice4);
    while (choice4 > 16 || choice4 < 13)
    {
        printf(ANSI_COLOR_RED"Enter the choice given in the range :"ANSI_COLOR_RESET);
        scanf("%d", &choice4);
    }
    
FILE *fp;
fp=fopen("su.txt","r");
fwrite(arr,sizeof(int),16,fp);
    switch (choice1)
    {
    case 1:
        arr[0][0]++;
        break;
    case 2:
        arr[0][1]++;
        break;
    case 3:
        arr[0][2]++;
        break;
    case 4:
        arr[0][3]++;
        break;

    default:
        printf(ANSI_COLOR_RED"\n Error: Wrong Choice !! Please retry");

        getchar();
    }
    switch (choice2)
    {
    case 5:
        arr[1][0]++;
        break;
    case 6:
        arr[1][1]++;
        break;
    case 7:
        arr[1][2]++;
        break;
    case 8:
        arr[1][3]++;
        break;

    default:
        printf("\n Error: Wrong Choice !! Please retry");

        getchar();
    }
    switch (choice3)
    {
    case 9:
        arr[2][0]++;
        break;
    case 10:
        arr[2][1]++;
        break;
    case 11:
        arr[2][2]++;
        break;
    case 12:
        arr[2][3]++;
        break;

    default:
        printf("\n Error: Wrong Choice !! Please retry");

        getchar();
    }
    switch (choice4)
    {
    case 13:
        arr[3][0]++;
        break;
    case 14:
        arr[3][1]++;
        break;
    case 15:
        arr[3][2]++;
        break;
    case 16:
        arr[3][3]++;
        break;
fclose(fp);
    default:
        printf("\n Error: Wrong Choice !! Please retry"ANSI_COLOR_RESET);

        getchar();
    }

    printf(ANSI_COLOR_GREEN"\n thanks for vote !!"ANSI_COLOR_RESET);
fp=fopen("su.txt","w");
fwrite(arr,sizeof(int),16,fp);
fclose(fp);

    votla(roll);
}
void votver(int roll)
{
    voting v1;
    FILE *fp;
    int f = 1;
    fp = fopen("vo.txt", "r");
    while (fread(&v1, sizeof(voting), 1, fp))
    {
        if (roll == v1.rolll)
        {
            f = 0;
        }
    }
    if (f == 1)
        castvote(roll);
    else
        printf(ANSI_COLOR_RED"You have already casted your vote"ANSI_COLOR_RESET);
}
int input(int roll)
{
    int i;
    student s1;
    FILE *fp;
    int f = 0, n, j;
    char ps[20];
    fp = fopen("abc.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (roll == s1.rno)
        {
            f = 1;
        }
    }
    printf("\n");
    fclose(fp);
    if (f == 0)
    {
        printf(ANSI_COLOR_RED"\nNo such student found "ANSI_COLOR_RESET);
        return 0;
    }
    else
    {
        return 1;
    }
}
int input1(int roll)
{
    int i;
    student s1;
    FILE *fp;
    int f = 0, n, j;
    char ps[20];
    fp = fopen("abc.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (roll == s1.rno)
        {
            f = 1;
        }
    }
    printf("\n");
    fclose(fp);
    if (f == 0)
    {
        printf(ANSI_COLOR_RED"\nNo such student found "ANSI_COLOR_RESET);
        return 0;
    }
    else
    {
        return 1;
    }
}
int input2(int roll)
{
    int i;
    student s1;
    FILE *fp;
    int f = 0, n, j;
    char ps[20];
    fp = fopen("abc.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (roll == s1.rno)
        {
            f = 1;
        }
    }
    printf("\n");
    fclose(fp);
    if (f == 0)
    {
        printf(ANSI_COLOR_RED"\nNo such student found "ANSI_COLOR_RESET);
        return 0;
    }
    else
    {
        return 1;
    }
}
void changepass(int roll,char na[])
{
{
    student s1;
    FILE *fp, *fp1;
    char name;
    int f = 0;
    fp = fopen("abc.txt", "r");
    fp1 = fopen("t.txt", "w");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (s1.rno == roll)
        {
            f = 1;
            fflush(stdin);
            strcpy(s1.name,na);
            printf(ANSI_COLOR_CYAN"enter the  new password :");
            scanf("%s", s1.pass);
        }
        fwrite(&s1, sizeof(student), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);
    if (f)
    {
        fp1 = fopen("t.txt", "r");
        fp = fopen("abc.txt", "w");
        while (fread(&s1, sizeof(student), 1, fp1))
        {
            fwrite(&s1, sizeof(student), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf(ANSI_COLOR_YELLOW"\n record not found ");
}
}
void displaysm(int roll)
{
    int i;
    student s1;
    FILE *fp;
    int f = 0, a;
    char ps[20];
    fp = fopen("abcd.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (roll == s1.rno)
        {
            f = 1;
            if((s1.su1<5)||(s1.su2<5)||(s1.su3<5)||(s1.su4<5)||(s1.su5<5)||(s1.su6<5))
            printf(ANSI_COLOR_RED"You have failed.Better luck next time\n"ANSI_COLOR_RED);
            printf(ANSI_COLOR_GREEN"MA1L001:%d\n"ANSI_COLOR_RESET ANSI_COLOR_CYAN"CS1L001:%d\n"ANSI_COLOR_BLUE"ME1L001:%d\n "ANSI_COLOR_YELLOW"CY1L001:%d\n"ANSI_COLOR_GREEN"CS1P001:%d\n"ANSI_COLOR_YELLOW"PH1P001:%d\n "ANSI_COLOR_RESET"CG:%f\n", s1.su1, s1.su2, s1.su3, s1.su4, s1.su5, s1.su6, s1.cg);
        }
    }
    if ((f == 0))
    {
        printf(ANSI_COLOR_RED"Your marks are not updated"ANSI_COLOR_RESET);
    }
    

}
void displaysa(int roll)
{
    int i;
    student s1;
    FILE *fp;
    int f = 0, a;
    char ps[20];
    fp = fopen("abcc.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (roll == s1.rno)
        {
            f = 1;
            printf(ANSI_COLOR_BLUE"Your attendance for mess");
            printf(ANSI_COLOR_YELLOW"1.Breakfast: %d\n"ANSI_COLOR_GREEN"2.Lunch: %d\n"ANSI_COLOR_CYAN"3.Snacks: %d\n"ANSI_COLOR_MAGENTA"4.Dinner: %d\n"ANSI_COLOR_BLUE"5.Refunded amount: %d"ANSI_COLOR_RESET, s1.at1, s1.at2, s1.at3, s1.at4, (6600 - s1.att));
            printf("\n");
        }
    }
    if (f == 0)
    {
        printf(ANSI_COLOR_RED"No attendance update\n"ANSI_COLOR_RESET);
    }
}
void displaysi(int roll)
{
    student s1;
    FILE *fp;
    int o = 1;

    fp = fopen("iss.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (roll == s1.rno)
        {
           // printf("\n%d    ", s1.rno);
            printf(ANSI_COLOR_RED"%d. %s\n"ANSI_COLOR_RESET, o, s1.iss);
            o++;
        }
    }
}
void displaym()
{
    student s1;
    FILE *fp;
    int j;
    fp = fopen("abcd.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        printf(ANSI_COLOR_YELLOW"Roll no: %d\n"ANSI_COLOR_RESET, s1.rno);
        printf(ANSI_COLOR_GREEN"MA1L001:%d\n"ANSI_COLOR_YELLOW"CS1L001:%d\n"ANSI_COLOR_BLUE"ME1L001:%d\n"ANSI_COLOR_GREEN"CY1L001:%d\n"ANSI_COLOR_RED"CS1P001:%d\n" ANSI_COLOR_MAGENTA "PH1P001:%d\n"ANSI_COLOR_CYAN"CG:%f\n"ANSI_COLOR_RESET, s1.su1, s1.su2, s1.su3, s1.su4, s1.su5, s1.su6, s1.cg);
        printf("\n");
        line();
    }
    printf("\n");
    fclose(fp);
}
void displaya()
{
    student s1;
    FILE *fp;
    int j;
    fp = fopen("abcc.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        printf(ANSI_COLOR_BLUE"roll no: %d\n"ANSI_COLOR_RESET, s1.rno);
        printf(ANSI_COLOR_CYAN"Your attendance for mess"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_MAGENTA"1.Breakfast: %d\n"ANSI_COLOR_BLUE"2.Lunch: %d\n"ANSI_COLOR_YELLOW"3.Snacks: %d\n"ANSI_COLOR_GREEN
        "4.Dinner: %d\n" ANSI_COLOR_RED" 5.Refunded amount = %d"ANSI_COLOR_GREEN, s1.at1, s1.at2, s1.at3, s1.at4, (6600 - s1.att));
        printf("\n");
        line();
    }
    printf("\n");
    fclose(fp);
}
void displayi()
{
    student s1;
    FILE *fp;
    int j;

    fp = fopen("iss.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        printf("\n%d    ", s1.rno);
        printf("%s\n", s1.iss);
    }
    fclose(fp);
}
void login1()
{
    int i;
    student s1;
    FILE *fp;
    int roll, a, f = 0;
    char ps[20];
    fp = fopen("abc.txt", "r");
    printf(ANSI_COLOR_GREEN"Enter your id\n");
    scanf("%d", &roll);
    printf("Enter your password\n"ANSI_COLOR_RESET);
    char df;
    int vb = 0;
    while ((df = _getch()) != 13)
    {
        ps[vb] = df;
        vb++;
        printf("*");
    }
    printf("\n");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (roll == s1.rno && (0 == strcmp(s1.pass, ps)))
        {
            f = 1;
            printf(ANSI_COLOR_CYAN"\n1.Rollno: %-d\n"ANSI_COLOR_MAGENTA"2.Name: %-s\n"ANSI_COLOR_BLUE"3.Password: %-s\n"ANSI_COLOR_RESET, s1.rno, s1.name, s1.pass);
            do
            {
                printf(ANSI_COLOR_MAGENTA"\n1.Display marks");
                printf(ANSI_COLOR_BLUE"\n2.Mess fee");
                printf(ANSI_COLOR_YELLOW"\n3.Cast vote");
                printf(ANSI_COLOR_GREEN"\n4.Issue slips and due date");
                printf(ANSI_COLOR_MAGENTA"\n5.Change Password");
                printf(ANSI_COLOR_RED"\n0.Exit");
                printf(ANSI_COLOR_CYAN"\nEnter your choice\n"ANSI_COLOR_RESET);
                scanf("%d", &a);
                if (a == 1)
                    displaysm(roll);
                else if (a == 2)
                    displaysa(roll);
                else if (a == 3)
                    votver(roll);
                    else if(a==4)
                    displaysi(roll);
                    else if(a==5)
                    changepass(roll,s1.name);
            } while (a != 0);
            printf(ANSI_COLOR_RED"Logout successfully\n"ANSI_COLOR_RESET);
        }
    }
    printf(ANSI_COLOR_RED"Wrong entry of roll id or password"ANSI_COLOR_RESET);

    printf("\n");
    fclose(fp);
    if (f == 0)
    {
        printf(ANSI_COLOR_RED"\nRecord not found\n "ANSI_COLOR_RESET);
    }
}
void create()
{
    student *s;
    int n, i, j;
    FILE *fp;
    printf(ANSI_COLOR_GREEN"Number of students :"ANSI_COLOR_RESET);
    scanf("%d", &n);
    s = (student *)calloc(n, sizeof(student));
    fp = fopen("abc.txt", "w");
    for (i = 0; i < n; i++)
    {
        printf(ANSI_COLOR_MAGENTA"Enter roll no :");
        scanf("%d", &s[i]);
        fflush(stdin);
        printf(ANSI_COLOR_BLUE"Enter name :");
        scanf("%[^\n]s", s[i].name);
        printf(ANSI_COLOR_YELLOW"Enter the password :"ANSI_COLOR_RESET);
        scanf("%s", s[i].pass);
        fwrite(&s[i], sizeof(student), 1, fp);
    }
    fclose(fp);
}
void display()
{
    student s1;
    FILE *fp;
    int j;
    fp = fopen("abc.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        printf(ANSI_COLOR_YELLOW"\n1.Rollno: %-d\n"ANSI_COLOR_GREEN"2.Name: %-s\n"ANSI_COLOR_BLUE"3.Password: %-s"ANSI_COLOR_RESET, s1.rno, s1.name, s1.pass);
        // printf("\n%-5d%-15s%-15s", s1.rno, s1.name, s1.pass);
        // printf("%d\n%d\n%d\n%d\n%d\n%d\n%d",s1.su1,s1.su2,s1.su3,s1.su4,s1.su5,s1.su6,s1.cg);
        printf("\n");
        line();
    }
    printf("\n");
    fclose(fp);
    displaym();
    displaya();
    displayi();
}
void add()
{
    student *s;
    int n, i, j;
    FILE *fp;
    printf(ANSI_COLOR_BLUE"Number of students :"ANSI_COLOR_RESET);
    scanf("%d", &n);
    s = (student *)calloc(n, sizeof(student));
    fp = fopen("abc.txt", "a");
    for (i = 0; i < n; i++)
    {
        printf(ANSI_COLOR_CYAN"Enter roll no :"ANSI_COLOR_RESET);
        scanf("%d", &s[i]);
        fflush(stdin);
        printf(ANSI_COLOR_MAGENTA"Enter name :"ANSI_COLOR_RESET);
        scanf("%[^\n]s", s[i].name);
        printf(ANSI_COLOR_BLUE"Enter the password :"ANSI_COLOR_RESET);
        scanf("%s", s[i].pass);
        fwrite(&s[i], sizeof(student), 1, fp);
    }
    fclose(fp);
}
void edit()
{
    student s1;
    FILE *fp, *fp1;

    int f = 0, rno;
    fp = fopen("abc.txt", "r");
    fp1 = fopen("t.txt", "w");
    printf(ANSI_COLOR_GREEN"Enter the roll no to update :"ANSI_COLOR_RESET);
    scanf("%d", &rno);
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (s1.rno == rno)
        {
            f = 1;
            fflush(stdin);
            printf(ANSI_COLOR_BLUE"Enter  new name :"ANSI_COLOR_RESET);
            scanf("%[^\n]s", s1.name);
            printf(ANSI_COLOR_YELLOW"Enter the  new password :"ANSI_COLOR_RESET);
            scanf("%s", s1.pass);
        }
        fwrite(&s1, sizeof(student), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);
    if (f)
    {
        fp1 = fopen("t.txt", "r");
        fp = fopen("abc.txt", "w");
        while (fread(&s1, sizeof(student), 1, fp1))
        {
            fwrite(&s1, sizeof(student), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf(ANSI_COLOR_RED"\n Record not found "ANSI_COLOR_RESET);
}
void delete()
{

    student s1;
    FILE *fp, *fp1;

    int f = 0, rno;
    fp = fopen("abc.txt", "r");
    fp1 = fopen("temp.txt", "w");
    printf(ANSI_COLOR_RED"Enter the roll no to delete :"ANSI_COLOR_RESET);
    scanf("%d", &rno);
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (s1.rno == rno)
        {
            f = 1;
        }
        else

            fwrite(&s1, sizeof(student), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);
    if (f)
    {
        fp1 = fopen("temp.txt", "r");
        fp = fopen("abc.txt", "w");
        while (fread(&s1, sizeof(student), 1, fp1))
        {
            fwrite(&s1, sizeof(student), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf(ANSI_COLOR_RED"\n Record not found "ANSI_COLOR_RESET);
}
void search()
{
    int i;
    student s1;
    FILE *fp;
    int roll, f = 0;
    char ps[20];
    fp = fopen("abc.txt", "r");
    printf("enter your id :\n");
    scanf("%d", &roll);
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (roll == s1.rno)
        {
            f = 1;
            printf(ANSI_COLOR_GREEN"\n1.Rollno: %-d\n"ANSI_COLOR_YELLOW"2.Name: %-s\n"ANSI_COLOR_BLUE"3.Password: %-s"ANSI_COLOR_RESET, s1.rno, s1.name, s1.pass);
            line();
            displaysm(roll);
            printf("\n");
            line();
            displaysa(roll);
        }
        // return f;
    }
    printf("\n");
    fclose(fp);
    if (f == 0)
    {
        printf(ANSI_COLOR_RED"\nRecord not found "ANSI_COLOR_RESET);
    }
}
void marks()
{

    student *s;
    int n, i, j;
    FILE *fp;
    printf(ANSI_COLOR_CYAN"Number of students"ANSI_COLOR_RESET);
    scanf("%d", &n);
    s = (student *)calloc(n, sizeof(student));
    fp = fopen("abcd.txt", "w");
    for (i = 0; i < n; i++)
    {
        printf(ANSI_COLOR_MAGENTA"Enter roll no :"ANSI_COLOR_RESET);
        scanf("%d", &s[i]);
        fflush(stdin);
        printf(ANSI_COLOR_RED"Enter subject grades \n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_MAGENTA"Enter MA1L001 :"ANSI_COLOR_RESET);
        scanf("%d", &s[i].su1);
        printf("\n");
        printf(ANSI_COLOR_BLUE"Enter CS1L001 :"ANSI_COLOR_RESET);
        scanf("%d", &s[i].su2);
        printf("\n");
        printf(ANSI_COLOR_YELLOW"Enter ME1L001 :"ANSI_COLOR_RESET);
        scanf("%d", &s[i].su3);
        printf("\n");
        printf(ANSI_COLOR_GREEN"Enter CY1L001 :"ANSI_COLOR_RESET);
        scanf("%d", &s[i].su4);
        printf("\n");
        printf(ANSI_COLOR_RED"Enter CS1P001 :"ANSI_COLOR_RESET);
        scanf("%d", &s[i].su5);
        printf("\n");
        printf(ANSI_COLOR_CYAN"Enter PH1P001 :"ANSI_COLOR_RESET);
        scanf("%d", &s[i].su6);
        printf("\n");
        s[i].cg = ((s[i].su1) * 4 + (s[i].su2) * 4 + (s[i].su3) * 4 + (s[i].su4) * 4 + (s[i].su5) * 2 + (s[i].su6) * 2) / 20.0;
        printf(ANSI_COLOR_MAGENTA"CG=%f\n"ANSI_COLOR_RESET, s[i].cg);
        fwrite(&s[i], sizeof(student), 1, fp);
    }
    // return f;

    printf("\n");
    fclose(fp);
}
void addm()
{
    student *s;
    int n, i, j;
    FILE *fp;
    printf(ANSI_COLOR_CYAN"Number of students :"ANSI_COLOR_RESET);
    scanf("%d", &n);
    s = (student *)calloc(n, sizeof(student));
    fp = fopen("abcd.txt", "a");
    for (i = 0; i < n; i++)
    {
        printf(ANSI_COLOR_MAGENTA"Enter roll no :"ANSI_COLOR_RESET);
        scanf("%d", &s[i]);
        if (input(s[i].rno))
        {
            printf(ANSI_COLOR_CYAN"Enter subject grades\n");
            printf("enter MA1L001 :");
            scanf("%d", &s[i].su1);
            printf("\n");
            printf(ANSI_COLOR_MAGENTA"Enter CS1L001 :");
            scanf("%d", &s[i].su2);
            printf("\n");
            printf(ANSI_COLOR_BLUE"Enter ME1L001 :");
            scanf("%d", &s[i].su3);
            printf("\n");
            printf(ANSI_COLOR_YELLOW"Enter CY1L001 :");
            scanf("%d", &s[i].su4);
            printf("\n");
            printf(ANSI_COLOR_GREEN"Enter CS1P001 :");
            scanf("%d", &s[i].su5);
            printf("\n");
            printf("Enter PH1P001 :");
            scanf("%d", &s[i].su6);
            printf("\n");
            s[i].cg = ((s[i].su1) * 4 + (s[i].su2) * 4 + (s[i].su3) * 4 + (s[i].su4) * 4 + (s[i].su5) * 2 + (s[i].su6) * 2) / 20.0;
            printf(ANSI_COLOR_RED"CG=%f\n"ANSI_COLOR_RESET, s[i].cg);

            fwrite(&s[i], sizeof(student), 1, fp);
        }
    }
    fclose(fp);
}
void attend()
{
    student *s;
    int n, i, j;
    FILE *fp;
    printf(ANSI_COLOR_CYAN"Number of students :");
    scanf("%d", &n);
    s = (student *)calloc(n, sizeof(student));
    fp = fopen("abcc.txt", "w");
    for (i = 0; i < n; i++)
    {
        printf(ANSI_COLOR_BLUE"Enter roll no :"ANSI_COLOR_RESET);
        scanf("%d", &s[i]);
        if (input1(s[i].rno))
        {
            fflush(stdin);
            printf(ANSI_COLOR_CYAN"Enter the attendance of the student\n");
            printf(ANSI_COLOR_MAGENTA"Enter the no.of days present on\n");
            printf(ANSI_COLOR_BLUE"1.Breakfast :");
            scanf("%d", &s[i].at1);
            printf("\n");
            printf(ANSI_COLOR_YELLOW"2.Lunch :");
            scanf("%d", &s[i].at2);
            printf("\n");
            printf(ANSI_COLOR_GREEN"3.Snacks :");
            scanf("%d", &s[i].at3);
            printf("\n");
            printf(ANSI_COLOR_RED"4.Dinner :");
            scanf("%d", &s[i].at4);
            printf("\n");
            s[i].att = ((s[i]).at1) * 40 + ((s[i]).at2) * 90 + ((s[i]).at3) * 30 + ((s[i]).at4) * 60;
            printf(ANSI_COLOR_CYAN"TOTAL AMOUNT = %d"ANSI_COLOR_RESET, s[i].att);
            fwrite(&s[i], sizeof(student), 1, fp);
        }
    }
    // return f;

    printf("\n");
    fclose(fp);
}
void issue()
{
    student *s;
    FILE *fp;
    int n = 1, roll, i;
    s = (student *)calloc(n, sizeof(student));
    fp = fopen("iss.txt", "w+");
    for (i = 0; i < n; i++)
    {

        printf(ANSI_COLOR_MAGENTA"Enter rollno");
        scanf("%d", &s[i]);
        fflush(stdin);
        printf(ANSI_COLOR_GREEN"Enter the issue regardings and due date"ANSI_COLOR_RESET);
        scanf("%[^\n]s", s[i].iss);
        fwrite(&s[i], sizeof(student), 1, fp);
    }
    fclose(fp);
}
void adda()
{
    student *s;
    int n, i, j;
    FILE *fp;
    printf(ANSI_COLOR_BLUE"Number of students :");
    scanf("%d", &n);
    s = (student *)calloc(n, sizeof(student));
    fp = fopen("abcc.txt", "a");
    for (i = 0; i < n; i++)
    {
        printf(ANSI_COLOR_GREEN"Enter roll no :"ANSI_COLOR_RESET);
        scanf("%d", &s[i]);
        if (input1(s[i].rno))
        {
            printf(ANSI_COLOR_RED"Enter the attendance of the student\n");
            printf(ANSI_COLOR_YELLOW"Enter the no.of days present on\n");
            printf(ANSI_COLOR_MAGENTA"1.Breakfast :");
            scanf("%d", &s[i].at1);
            printf("\n");
            printf(ANSI_COLOR_BLUE"2.Lunch :");
            scanf("%d", &s[i].at2);
            printf("\n");
            printf(ANSI_COLOR_GREEN"3.Snacks :");
            scanf("%d", &s[i].at3);
            printf("\n");
            printf(ANSI_COLOR_RED"4.Dinner :");
            scanf("%d", &s[i].at4);
            printf("\n");
            s[i].att = ((s[i]).at1) * 40 + ((s[i]).at2) * 90 + ((s[i]).at3) * 30 + ((s[i]).at4) * 60;
            printf(ANSI_COLOR_CYAN"TOTAL AMOUNT = %d"ANSI_COLOR_RESET, s[i].att);
            fwrite(&s[i], sizeof(student), 1, fp);
        }
    }
    // return f;

    printf("\n");
    fclose(fp);
}
void addi()
{
    student *s;
    FILE *fp;
    int n = 1, roll, i;
    s = (student *)calloc(n, sizeof(student));
    fp = fopen("iss.txt", "a");
    for (i = 0; i < n; i++)
    {
        printf(ANSI_COLOR_MAGENTA"Enter rollno :");
        scanf("%d", &s[i]);
        fflush(stdin);
        if (input2(s[i].rno))
        {
            printf(ANSI_COLOR_YELLOW"Enter the issue regardings and due date :\n"ANSI_COLOR_RESET);
            scanf("%[^\n]s", s[i].iss);
            fwrite(&s[i], sizeof(student), 1, fp);
        }
    }
    fclose(fp);
}
int main()
{
    int ch, p, f, q;
    do
    {
        line();
        printf(ANSI_COLOR_MAGENTA"WELCOME TO STUDENT AND ADMINISTRATOR PORTAL\n");
        line();
        printf(ANSI_COLOR_BLUE"\n1.Administartor login");
        printf(ANSI_COLOR_YELLOW"\n2.Student login");
        printf(ANSI_COLOR_RED"\n0.Exit");
        printf(ANSI_COLOR_GREEN"\nEnter your choice :"ANSI_COLOR_RESET);
        scanf("%d", &p);
        if (p == 1)
        {
             char id[20];
    printf(ANSI_COLOR_GREEN"Enter your id :\n");
    scanf("%s", id);
    printf(ANSI_COLOR_YELLOW"Enter your password :\n"ANSI_COLOR_RESET);
    char q,ps[20],h[20]="admin1",i[20]="!@#$";
    int w = 0,f=0;
    while ((q = _getch()) != 13)
    {
        ps[w] = q;
        w++;
        printf("*");
    }
    printf("\n");
    
    
        if ((0==strcmp(id,h)) && (0 == strcmp(ps,i)))
        { f=1;
            

            {
                
                {   printf("\n");
                    line();
                    printf(ANSI_COLOR_CYAN"\n1.Create");
                    printf(ANSI_COLOR_RED"\n2.Display");
                    printf(ANSI_COLOR_GREEN"\n3.Add");
                    printf(ANSI_COLOR_CYAN"\n4.Edit");
                    printf(ANSI_COLOR_MAGENTA"\n5.Search");
                    printf(ANSI_COLOR_BLUE"\n6.Delete");
                    printf(ANSI_COLOR_YELLOW"\n7.More");
                    printf(ANSI_COLOR_GREEN"\n0.Logout");
                    printf(ANSI_COLOR_RED"\nEnter your choice :"ANSI_COLOR_RESET);
                    scanf("%d", &ch);
                    if (ch == 1)
                        create();
                    else if (ch == 2)
                        display();
                    else if (ch == 3)
                        add();
                    else if (ch == 4)
                        edit();
                    else if (ch == 5)
                        search();
                    else if (ch == 6)
                        delete ();
                    else if (ch == 7)
                    {
                        do
                        {   
                            printf("\n");
                            line();
				            printf(ANSI_COLOR_BLUE"1.Create marks entry\n");
                            printf(ANSI_COLOR_BLUE"2.Create mess attendance entry\n");
                            printf(ANSI_COLOR_YELLOW"3.Create issue slip entry\n");
                            printf(ANSI_COLOR_GREEN"4.Enter of marks of the students\n");
                            printf(ANSI_COLOR_BLUE"5.Enter mess attendance\n");
                            printf(ANSI_COLOR_GREEN"6.Voting result\n");
                            printf(ANSI_COLOR_GREEN"7.Tomorrow menu\n");
                            printf(ANSI_COLOR_RED"8.Add issue slip\n");
                            printf(ANSI_COLOR_GREEN"9.Start Voting\n");
                            printf(ANSI_COLOR_YELLOW"0.Exit\n");
                            printf(ANSI_COLOR_GREEN"Enter your choice :\n");
                            scanf("%d", &q);
                            if (q == 1)
                                marks();
                            else if (q == 2)
                                attend();
                            else if (q == 3)
                                issue();
                            else if (q == 4)
                                addm();
                            else if (q == 5)
                                adda();
                            else if (q == 6)
                                votesCount();
                            else if (q == 7)
                                menu();
                            else if (q == 8)
                                addi();
                            else if (q == 9)
                                zero();
                        } while (q != 0);
                    }

                } while (ch != 0);
                printf(ANSI_COLOR_GREEN"Logout successfully\n"ANSI_COLOR_RESET);
                line();
            }
        }
        if(f==0)
        {
            printf(ANSI_COLOR_RED"Wrong entry of user id or password\n"ANSI_COLOR_RESET);
        }
        }
        else if (p == 2)
        {
            login1();
        }
    } while (p != 0);

    return 0;
}
