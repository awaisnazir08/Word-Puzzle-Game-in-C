#include<stdio.h>

void user_words(int x, char user[][15]);
void comp_words(int x, char fix[][15]);
void GenerateGrid(int row, int col, char grid[row][col]);
void DisplayGrid(int row, int col, char grid[][col]);

int main()
{
    int row, col;
    int choice, x;

label:
    printf("\nPress 1 to enter the words yourself into the puzzle or 2 for using pre-defined words: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("\nEnter the number of words that you want to enter: ");
        scanf("%d", &x);
        char words[x][15];
        user_words(x, words);
    }
    else if (choice == 2)
    {
        x = 6;
        char words[x][15];
        comp_words(x, words);
    }
    else
    {
        printf("\nYou have entered a wrong choice..!!");
        goto label;
    }



    printf("\nPlease enter the row size for the puzzle: ");
    scanf("%d", &row);
    printf("\nPlease enter the column size for the puzzle: ");
    scanf("%d", &col);
    char grid[row][col];
    GenerateGrid(row, col, grid);
    DisplayGrid(row, col, grid);
    return 0;
}

//stores computer defined words
void comp_words(int x, char fix[x][15])
{
    char wow[6][15] = { {'h','a','p','p','y'},
{'c','h','e','e','r','f','u','l'},
{'c','h','i','p','p','e','r'},
{'e','f','f','e','r','v','e','s','c','e','n','t'},
{'j','a','u','n','t','y'},
{'j','o','l','l','y'} };
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            fix[i][j] = wow[i][j];
        }
    }
}

//stores words entered by the user
void user_words(int x, char user[x][15])
{
    printf("\nEnter the word(s): ");
    for (int i = 0; i < x; i++)
    {
        scanf("%s", user[i]);
    }
}


//generates grid
void GenerateGrid(int row, int col, char grid[row][col])
{
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < col;j++)
        {
            grid[i][j] = '-';
        }
        printf("\n");
    }
}
//displays grid
void DisplayGrid(int row, int col, char grid[][col])
{
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < col;j++)
        {
            printf("%c  ", grid[i][j]);

        }
        printf("\n");
    }
}
