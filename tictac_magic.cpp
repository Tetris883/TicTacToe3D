#include<stdio.h>
#include<stdlib.h>
/*
struct tictac{
    public:

        int board[9] = {2,7,6,9,5,1,4,3,8};
        int x_pos[9] = {0};
        int o_pos[9] = {0};

    void print_board
};
*/
int winner_flag;
int board[9] = {2,7,6,9,5,1,4,3,8};
int x_pos[9] = {0};
int o_pos[9] = {0};

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
int containsN(int arr[9], int n)
{
    for(int i=0;i<9;i++)
    {
        if(arr[i]==n)
            return 1;
    }

    return 0;
}

int winningPos(int arr[9])
{
    int flag = 0;
    for (int i = 0; i < 8; i++) {
       
        for (int j = i + 1; j < 9; j++) {
            int x = 15 - (arr[i] + arr[j]);
            
            if(containsN(o_pos,x)==0 && containsN(x_pos,x)==0)
            {
                return x;
                flag=1;
            }
            
            else
                continue;
        }
    }

    if(flag==1)
    {
        winner_flag=1;
        exit(1);
    }
}
/*
int checkWinner(int arr[9])
{
    //find a triad with a certain sum
    
    for(int i=0;i<7;i++)
    {
        for(int j=i+1;i<8;j++)
        {
            for(int k=j+1;k<9;k++)
            {
                printf("\n%d\n", arr[i]+arr[j]+arr[k]);
                if(arr[i]+arr[j]+arr[k]==15)
                {
                    return 1;
                }

                else
                    continue;
            }
        }
    }

    return 0;
}
*/
void displayBoard()
{
    printf("\n\n");
    for(int i=0; i<9; i++)
    {
        int flag = 1;
        for(int j=0;j<9;j++)
        {
            if(board[i]==x_pos[j])
            {
                printf("| X |");
                flag = 0;
                break;
            }

            else if(board[i]==o_pos[j])
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

int main()
{
    

    x_pos[0] = 5, x_pos[1] = 2;
    o_pos[0] = 6, o_pos[1] = 8;
    
    displayBoard();
    
    if(winner_flag==1)
    {
        printf("\n\n We've got a winner!!!");
        
    }

    o_pos[2] = winningPos(o_pos);
    displayBoard();
    
    if(winner_flag==0)
    {
        printf("\n\n We've got a winner!!!");
        
    }
       
    
}