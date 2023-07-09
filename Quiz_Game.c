#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void rules();
void menu();
void readfile(int n);
void start(int c);
int quiz(int c1);
void time_delay(int t);
void animation(int x);
void score(int c, int c1);
void show_record(int counter);
char playername[][30];
int s[20];

int main()
{
    system("cls");
    system("color 0A");
    int n, c1 = 0;

mainhome:
    system("cls");
    menu();
    printf("Enter your choice: ");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        rules();
        int x;
        printf("\nPress 1 to go back to home ...\n");
        scanf("%d", &x);
        if (x == 1)
        {
            goto mainhome;
        }
        break;

    case 2:
        animation(1);
        system("cls");
        start(c1);
        int flag;
        flag = quiz(c1);
        c1++;
        int y;
        if (flag == 1)
        {
            animation(2);
            goto mainhome;
        }
        else if (flag == 0)
        {
            printf("\nPress 1 to go back to home ...\n");
            scanf("%d", &y);
        }
        if (y == 1)
        {
            animation(2);
            goto mainhome;
        }
        break;

    case 3:
        show_record(c1);
        int temp;
        printf("\nPress 1 to go back to home ...\n");
        scanf("%d", &temp);
        if (temp == 1)
        {
            goto mainhome;
        }
        break;

    case 4:
        animation(3);
        exit(1);
        break;

    default:
        printf(">> Invalid input!\n>> Please enter again\n");
        time_delay(750);
        goto mainhome;
    }
    return 0;
}
void rules()
{
    system("cls");
    printf("\n");
    printf("\n|======================================================================================|");
    printf("\n|......................................................................................|");
    printf("\n|................................... Quiz Game Rules ..................................|");
    printf("\n|......................................................................................|");
    printf("\n|>> In this quiz, there are 10 question each carrying 10 score.                        |");
    printf("\n|>> In each question there will be 4 options and only 1 option will be correct.        |");
    printf("\n|>> For moving onto next question you have to give correct answer of previous question.|");
    printf("\n|>> Wrong answer will end the quiz.                                                    |");
    printf("\n|>> You will be asked questions continuously if you keep giving the right answers.     |");
    printf("\n|>> There will be no negative scoring for wrong answer.                                |");
    printf("\n|......................................................................................|");
    printf("\n|..................................... Instruction ....................................|");
    printf("\n|......................................................................................|");
    printf("\n|>> More than one player can play the quiz one by one.                                 |");
    printf("\n|>> Everyone has to register their name before starting the quiz.                      |");
    printf("\n|>> In the case of more than 1 player, the player/s who has/have higher score will win.|");
    printf("\n|......................................................................................|");
    printf("\n|.................................... ALL THE BEST ....................................|");
    printf("\n|......................................................................................|");
    printf("\n|======================================================================================|");
    printf("\n\n\n");
}

void readfile(int n)
{
    FILE *fpointer;
    fpointer = fopen("Question.txt", "r");
    char singleline[2048];
    int c = 0;
    while (!feof(fpointer))
    {
        fgets(singleline, 2048, fpointer);
        if (c == n || c == n + 1 || c == n + 2 || c == n + 3 || c == n + 4)
        {
            puts(singleline);
        }
        c++;
    }
    fclose(fpointer);
}
void start(int c)
{
    printf("\n\nResister your name to play quiz: ");
    getchar();
    gets(playername[c]);
}
int quiz(int c1)
{
    system("cls");
    time_t t;
    srand((unsigned)time(&t));
    int count = 0;
    for (int i = 1; i < 11; i++)
    {
        int a;
        printf("\nAre you ready for question %d \n(press 1 for to quit quiz / press any other number to continue ): ", i);
        scanf("%d", &a);
        while ((getchar()) != '\n')
            ;

        if (a == 1)
        {
            return 1;
        }
        else
        {
            system("cls");
            printf("|=====================|\n");
            if (i <= 9)
                printf("|>>>  Question: %d  <<<|\n", i);
            else if (i >= 10)
                printf("|>>>  Question: %d <<<|\n", i);
            printf("|=====================|\n\n");
            printf("=====================================================================================\n");

            int n = 0;
            n = rand() % 25 + (i - 1) * 25;
            n = n * 6 + 1;
            readfile(n);
            char x[1];
            printf("=====================================================================================\n\n");
            printf("Choose your Option(A/B/C/D): ");
            scanf("%s", x);
            char y[9] = "aAbBcCdD";
            printf("\n");
            printf("|================================|\n");
            if (i == 1 && (x[0] == y[6] || x[0] == y[7]))
            {
                printf("|>>>  Your answer is Correct  <<<|\n");
                count++;
            }
            else if (i == 1)
            {
                printf("|>>>     Incoorect Answer!    <<<|\n");
                printf("|>>>  The Correct answer is %c <<<|\n", y[6]);

                score(count, c1);
                printf("|================================|\n");
                break;
            }
            if (i == 2 && (x[0] == y[0] || x[0] == y[1]))
            {
                printf("|>>>  Your answer is Correct  <<<|\n");
                count++;
            }
            else if (i == 2)
            {
                printf("|>>>     Incoorect Answer!    <<<|\n");
                printf("|>>>  The Correct answer is %c <<<|\n", y[0]);

                score(count, c1);
                printf("|================================|\n");
                break;
            }
            if (i == 3 && (x[0] == y[4] || x[0] == y[5]))
            {
                printf("|>>>  Your answer is Correct  <<<|\n");
                count++;
            }
            else if (i == 3)
            {
                printf("|>>>     Incoorect Answer!    <<<|\n");
                printf("|>>>  The Correct answer is %c <<<|\n", y[4]);

                score(count, c1);
                printf("|================================|\n");
                break;
            }
            if (i == 4 && (x[0] == y[6] || x[0] == y[7]))
            {
                printf("|>>>  Your answer is Correct  <<<|\n");
                count++;
            }
            else if (i == 4)
            {
                printf("|>>>     Incoorect Answer!    <<<|\n");
                printf("|>>>  The Correct answer is %c <<<|\n", y[6]);

                score(count, c1);
                printf("|================================|\n");
                break;
            }
            if (i == 5 && (x[0] == y[2] || x[0] == y[3]))
            {
                printf("|>>>  Your answer is Correct  <<<|\n");
                count++;
            }
            else if (i == 5)
            {
                printf("|>>>     Incoorect Answer!    <<<|\n");
                printf("|>>>  The Correct answer is %c <<<|\n", y[2]);

                score(count, c1);
                printf("|================================|\n");
                break;
            }
            if (i == 6 && (x[0] == y[4] || x[0] == y[5]))
            {
                printf("|>>>  Your answer is Correct  <<<|\n");
                count++;
            }
            else if (i == 6)
            {
                printf("|>>>     Incoorect Answer!    <<<|\n");
                printf("|>>>  The Correct answer is %c <<<|\n", y[4]);

                score(count, c1);
                printf("|================================|\n");
                break;
            }
            if (i == 7 && (x[0] == y[0] || x[0] == y[1]))
            {
                printf("|>>>  Your answer is Correct  <<<|\n");
                count++;
            }
            else if (i == 7)
            {
                printf("|>>>     Incoorect Answer!    <<<|\n");
                printf("|>>>  The Correct answer is %c <<<|\n", y[0]);

                score(count, c1);
                printf("|================================|\n");
                break;
            }
            if (i == 8 && (x[0] == y[6] || x[0] == y[7]))
            {
                printf("|>>>  Your answer is Correct  <<<|\n");
                count++;
            }
            else if (i == 8)
            {
                printf("|>>>     Incoorect Answer!    <<<|\n");
                printf("|>>>  The Correct answer is %c <<<|\n", y[6]);

                score(count, c1);
                printf("|================================|\n");
                break;
            }
            if (i == 9 && (x[0] == y[4] || x[0] == y[5]))
            {
                printf("|>>>  Your answer is Correct  <<<|\n");
                count++;
            }
            else if (i == 9)
            {
                printf("|>>>     Incoorect Answer!    <<<|\n");
                printf("|>>>  The Correct answer is %c <<<|\n", y[4]);

                score(count, c1);
                printf("|================================|\n");
                break;
            }
            if (i == 10 && (x[0] == y[2] || x[0] == y[3]))
            {
                printf("|>>>  Your answer is Correct  <<<|\n");
                count++;
            }
            else if (i == 10)
            {
                printf("|>>>     Incoorect Answer!    <<<|\n");
                printf("|>>>  The Correct answer is %c <<<|\n", y[2]);
                score(count, c1);
                printf("|================================|\n");
                break;
            }
        }
        score(count, c1);
        printf("|================================|\n");
        if (i == 10)
        {
            return 0;
        }
    }
}

void score(int c, int c1)
{
    s[c1] = c * 10;
    if (s[c1] == 0)
        printf("|>>>     Total score = %d      <<<|\n", s[c1]);
    else if (s[c1] == 100)
        printf("|>>>     Total score = %d    <<<|\n", s[c1]);
    else
        printf("|>>>     Total score = %d     <<<|\n", s[c1]);
}

void show_record(int counter)
{
    system("cls");
    if (counter == 0)
    {
        printf("\nNo one has register yet!\n");
        return;
    }
    int Index_winner[20];
    int j = 0;
    int temp = -1;
    printf("\n|===============================================|");
    printf("\n| Sr.NO |          Player Name          | Score |");
    printf("\n|===============================================|");
    for (int i = 0; i < counter; i++)
    {
        if (s[i] == temp)
        {
            temp = s[i];
            Index_winner[j++] = i;
        }
        else if (s[i] > temp)
        {
            j = 0;
            temp = s[i];
            Index_winner[j++] = i;
        }
        printf("\n|");
        printf("%7d|", i + 1);
        printf("%31s|", playername[i]);
        printf("%7d|", s[i]);
    }
    printf("\n|===============================================|\n\n");
    if (counter > 1)
    {
        if (j > 1)
            printf("Winners are : \n");
        else
            printf("Winner is : \n");
        for (int k = 0; k < j; k++)
        {
            printf("%s\n", playername[Index_winner[k]]);
        }
    }
}
void time_delay(int t)
{
    int milli_seconds = t;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}
void animation(int x)
{
    if (x == 1)
    {
        system("cls");
        printf("Loading.");
        printf("\n\n========================================\n");
        printf(">>>>>>>>");
        char *ptr = " ";
        printf("%32s", ptr);
        printf(" # 20%%");
        printf("\n========================================\n");
        time_delay(750);
        system("cls");
        printf("Loading...");
        printf("\n\n========================================\n");
        printf(">>>>>>>>>>>>>>>>>>>>");
        char *ptr1 = " ";
        printf("%20s", ptr1);
        printf(" # 50%%");
        printf("\n========================================\n");
        time_delay(750);
        system("cls");
        printf("Loading.....");
        printf("\n\n========================================\n");
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
        printf(" # 100%%");
        printf("\n========================================\n");
        time_delay(750);
        system("cls");
        printf("Loaded.\n");
    }
    else if (x == 2)
    {
        system("cls");
        printf("Saving.");
        printf("\n\n========================================\n");
        printf(">>>>>>>>");
        char *ptr = " ";
        printf("%32s", ptr);
        printf(" # 20%%");
        printf("\n========================================\n");
        time_delay(750);
        system("cls");
        printf("Saving...");
        printf("\n\n========================================\n");
        printf(">>>>>>>>>>>>>>>>>>>>");
        char *ptr1 = " ";
        printf("%20s", ptr1);
        printf(" # 50%%");
        printf("\n========================================\n");
        time_delay(750);
        system("cls");
        printf("Saving.....");
        printf("\n\n========================================\n");
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
        printf(" # 100%%");
        printf("\n========================================\n");
        time_delay(750);
        system("cls");
        printf("Saved.\n\n\n");
    }
    else if (x == 3)
    {
        system("cls");
        printf("Program Ending.");
        printf("\n\n========================================\n");
        printf(">>>>>>");
        char *ptr = " ";
        printf("%34s", ptr);
        printf(" # 10%%");
        printf("\n========================================\n");
        time_delay(400);

        system("cls");
        printf("Program Ending..");
        printf("\n\n========================================\n");
        printf(">>>>>>>>>>>>>>");
        char *ptr0 = " ";
        printf("%26s", ptr0);
        printf(" # 30%%");
        printf("\n========================================\n");
        time_delay(400);

        system("cls");
        printf("Program Ending...");
        printf("\n\n========================================\n");
        printf(">>>>>>>>>>>>>>>>>>>>>>>");
        char *ptr1 = " ";
        printf("%17s", ptr1);
        printf(" # 65%%");
        printf("\n========================================\n");
        time_delay(400);
        system("cls");
        printf("Program Ending.....");
        printf("\n\n========================================\n");
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
        printf(" # 100%%");
        printf("\n========================================\n");
        time_delay(400);
        system("cls");
        printf("Program Ended.\n\n\n");
    }
}

void menu()
{
    printf("|==============================|\n");
    printf("|..............................|\n");
    printf("|>> Enter 1 to see rules       |\n");
    printf("|>> Enter 2 to play quiz       |\n");
    printf("|>> Enter 3 to see Scorecard   |\n");
    printf("|>> Enter 4 to quit            |\n");
    printf("|..............................|\n");
    printf("|==============================|\n\n");
}