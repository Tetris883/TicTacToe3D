#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
        ;
}

int board1[9] = {10,26,6,24,1,17,8,15,19};
int board2[9] = {23,3,16,7,14,21,12,25,5};
int board3[9] = {9,13,20,11,27,4,22,2,18};

int x_pos[27] = {0};
int o_pos[27] = {0};

int x_score = 0;
int o_score = 0;

/*
int xnextMove(int a, int b)
{
    for(int i=0;i<9;i++)
    {
        for(int j=i+1;i<9;i++)
        {
            if(15-(x_pos[i]+x_pos[j]))
        }
    }
}
*/
int containsN(int arr[27], int n)
{
    for(int i=0;i<27;i++)
    {
        if(arr[i]==n)
            return 1;
    }

    return 0;
}

//counts number of non-zero elements
int size(int arr[27])
{
    int s = 0;
    for(int i=0;i<27;i++)
    {
        if(arr[i]!=0)
            s++;
    }

    return s;
}

int winningPos(int arr[27])
{
    int flag = 0;
    for (int i = 0; i < 26; i++) {

        for (int j = i + 1; j < 27; j++) {
            int x = 42 - (arr[i] + arr[j]);

            if(containsN(o_pos,x)==0 && containsN(x_pos,x)==0 && x<=27)
            {
                if(x>27 || x<0)
                    continue;

                else
                {
                    return x;

                }
            }

            else
                continue;
        }
    }




    return 0;
}

int blockPos(int arr[27])
{
    int flag = 0;
    for (int i = 0; i < 26; i++) {

        for (int j = i + 1; j < 27; j++) {
            int x = 42 - (arr[i] + arr[j]);

            if(containsN(o_pos,x)==0 && containsN(x_pos,x)==0 && arr[i]!=0 && arr[j]!=0 && x<=27)
            {
                return x;
            }

            else
                continue;
        }
    }

    return 0;

}

int nextMove(int arr[27], int arr1[27])
{
    int x = 0;

    if(arr[0]==0)
    {
        if(arr1[0]!=14)
            x = 14;

        else
            x = 9;

        return x;
    }


    x = winningPos(arr);
    if(x==0)
    {
        x = blockPos(arr1);
    }

    if(x==0)
    {
        while(containsN(o_pos,x)==0 && containsN(x_pos,x)==0 && x<=27 && x>0)
            x = (rand()%27) + 1;

        printf("\n rand: %d\n", x);
    }

    return x;
}

void displayBoard()
{
    printf("\n\n");
    for(int i=0; i<9; i++)
    {
        int flag = 1;
        for(int j=0;j<27;j++)
        {
            if(board1[i]==x_pos[j])
            {
                printf("| X |");
                flag = 0;
                break;
            }

            else if(board1[i]==o_pos[j])
            {
                printf("| O |");
                flag = 0;
                break;
            }

        }

        if(flag==1)
            printf("|   |");
        if((i+1)%3==0)
            printf("\n----------------\n");
    }

    printf("\n\n");
    for(int i=0; i<9; i++)
    {
        int flag = 1;
        for(int j=0;j<27;j++)
        {
            if(board2[i]==x_pos[j])
            {
                printf("| X |");
                flag = 0;
                break;
            }

            else if(board2[i]==o_pos[j])
            {
                printf("| O |");
                flag = 0;
                break;
            }

        }

        if(flag==1)
            printf("|   |");
        if((i+1)%3==0)
            printf("\n----------------\n");
    }

    printf("\n\n");
    for(int i=0; i<9; i++)
    {
        int flag = 1;
        for(int j=0;j<27;j++)
        {
            if(board3[i]==x_pos[j])
            {
                printf("| X |");
                flag = 0;
                break;
            }

            else if(board3[i]==o_pos[j])
            {
                printf("| O |");
                flag = 0;
                break;
            }

        }

        if(flag==1)
            printf("|   |");
        if((i+1)%3==0)
            printf("\n----------------\n");
    }
}

void displayScore()
{
    printf("\n");
    printf("\n--------------------------------------------------");
    printf("\n         player1           |             computer     ");
    printf("\n--------------------------------------------------");
    printf("\n|                          |                     |");
    printf("\n|             %d            |          %d          |", o_score, x_score);
    printf("\n|                          |                     |");
    printf("\n--------------------------------------------------");

}

void printArr(int arr[27])
{
    int i = 0;

    while(arr[i]!=0)
    {
        printf(" %d ", arr[i]);
        i++;
    }
}

int choiceIn()
{

    printf("\n Please use the reference table below to decide your move");
    printf("\n\n Plane 1            Plane 2                     Plane 3    ");
    printf("\n-------------        ----------------        ----------------");
    printf("\n| 1 | 2 | 3 |        | 10 | 11 | 12 |        | 19 | 20 | 21 |");
    printf("\n-------------        ----------------        ----------------");
    printf("\n| 4 | 5 | 6 |        | 13 | 14 | 15 |        | 22 | 23 | 24 |");
    printf("\n-------------        ----------------        ----------------");
    printf("\n| 7 | 8 | 9 |        | 16 | 17 | 18 |        | 25 | 26 | 27 |");
    printf("\n-------------        ----------------        ----------------");

    int c = 0  ,x = 0;
    int flag = 0;

        printf("\n\n Please enter your choice: ");
        scanf("%d", &c);

        x = 0;

        if(c<10)
            x = board1[c-1];

        else if(c>9 && c<19)
            x = board2[c-9-1];

        else
            x = board3[c-18-1];


        if(containsN(o_pos,x)==1 || containsN(x_pos,x)==1 || c<1 || c>27)
        {
            printf("\n That node is pre-occupied OR it was an INVALID INPUT!!!\n Please enter another\n\n");
            int x = choiceIn();
        }

    else
        return x;
}

int score(int arr[27])
{
    int s = 0;
    for(int i=0;i<25;i++)
    {
        for(int j=1;j<26;j++)
        {
            for(int k=2;k<27;k++)
            {
                if(arr[i]!=0 && arr[j]!=0 && arr[k]!=0)
                {
                    if((arr[i] + arr[j] + arr[k])==42)
                        s++;
                }
            }
        }
    }

    return s;
}


int main()
{
    int k, o=0, x=0;

    printf("\n Please decide from the following: \n1. Play first turn \n2. Let the computer play first\n");
    scanf("%d", &k);

    if(k!=1 || k!=2)
    {
        while(k!=1 || k!=2)
        {
            printf("\n Please decide from the following: \n1. Play first turn \n2. Let the computer play first\n");
            scanf("%d", &k);
            if(k==1 || k==2)
                break;
        }
    }


    while((size(o_pos)+size(x_pos))<27)
    {
        printf("\n%d\n", k);
        if(k%2!=0)
        {
            o_pos[o] = choiceIn();


            printf("\n");

            displayBoard();
            delay(3);


            o++;
        }

        else
        {

            x_pos[x] = nextMove(x_pos, o_pos);

            printf("\n x_pos: ");
            printArr(x_pos);
            printf("\n o_pos: ");
            printArr(o_pos);
            printf("\n");

            displayBoard();
            delay(3);



            x++;
        }

        printf("\n x_pos: ");
        printArr(x_pos);
        printf("\n o_pos: ");
        printArr(o_pos);

        x_score = score(x_pos);
        o_score = score(o_pos);

        displayScore();

        if(x_score==10)
        {
            printf("\n\n Computer wins the game!!!")
            delay(2);
            exit(1);
        }

        if(o_score==10)
        {
            printf("\n\n player1 wins the game!!!")
            delay(2);
            exit(1);
        }

        k++;
    }





}
