#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void user_words(int x, char user[][15]);
void comp_words(int x, char fix[][15]);
void GenerateGrid(int row, int col, char grid[row][col]);
void DisplayGrid(int row, int col, char grid[][col]);
void PlaceWords(int r_row, int r_col, int direction, char r_word_pass[15], int row, int col, char grid[row][col]);
int random_row(int row, int i, char r_word_pass[i]);
int random_column(int col, int i, char r_word_pass[i]);
int CheckWordWillFit(int direction, int r_row, int r_col, int i, char r_word_pass[i], int row, int col, char grid[row][col]);
void GridRandomFill(int row, int col, char grid[row][col], char letters[26]);
int main()
{
    int row, col, i = 0, to_not_overlap;
    int position_store[20] = { 98 }, k = 0;
    int choice = 0, x;
    int r_word_position;
    int direction;
    int r_row, r_col;
    char r_word_pass[15];
    char letters[26] = "abcdefghijklmnopqrstuvwxyz";
    srand(time(0));
label:
    printf("\nPress 1 to enter the words yourself into the puzzle or 2 for using pre-defined words: ");
    scanf("%d", &choice);
    // FUNCTIONALITY FOR USER ENTERED WORDS
    if (choice == 1)
    {
        printf("\nEnter the number of words that you want to enter: ");
        scanf("%d", &x);
        char words[x][15];
        user_words(x, words);

        printf("\nPlease give the dimensions for the word puzzle..\nNote that if the height and width of the puzzle is less then the size of any word(s) you have entered; this would cause an undefined behaviour and the program may not work!!");
        printf("\nPlease enter the row size for the puzzle: ");
        scanf("%d", &row);
        printf("\nPlease enter the column size for the puzzle: ");
        scanf("%d", &col);
        char grid[row][col];
        GenerateGrid(row, col, grid);


        for (int loop = 0;loop < x;loop++)
        {
            for (int res_arr = 0;res_arr < 15;res_arr++)
            {
                r_word_pass[res_arr] = '\0';
            }
        choose_again:
            r_word_position = rand() % x;
            for (int z = 0;z < k;z++)
            {
                if (position_store[z] == r_word_position)
                {
                    goto choose_again;
                }
            }
            position_store[k] = r_word_position;
            k += 1;
            for (i = 0; i < strlen(words[r_word_position]); i++)
            {
                r_word_pass[i] = words[r_word_position][i];
            }

        rand_choose_again:
            direction = rand() % 3;
            r_row = random_row(row, i, r_word_pass);
            r_col = random_column(col, i, r_word_pass);
            to_not_overlap = CheckWordWillFit(direction, r_row, r_col, i, r_word_pass, row, col, grid);
            if (to_not_overlap == 5)
            {
                goto rand_choose_again;
            }
            PlaceWords(r_row, r_col, direction, r_word_pass, row, col, grid);
        }

        GridRandomFill(row, col, grid, letters);

    }
    // FUNCTIONALITY FOR COMPUTER-DEFINED WORDS
    else if (choice == 2)
    {
        x = 6;
        char words[x][15];
        comp_words(x, words);

    correct_dimensions:
        printf("\nPlease enter the row size for the puzzle (minimum 12): ");
        scanf("%d", &row);
        printf("\nPlease enter the column size for the puzzle (minimum 12): ");
        scanf("%d", &col);
        if (row < 12 || col < 12)
        {
            printf("\nYou have entered invalid dimensions for the Puzzle!\nPlease re-enter! ");
            goto correct_dimensions;
        }
        char grid[row][col];
        GenerateGrid(row, col, grid);
        for (int loop = 0;loop < 6;loop++)
        {
            for (int res_arr = 0;res_arr < 15;res_arr++)
            {
                r_word_pass[res_arr] = '\0';
            }
        choose_again2:
            r_word_position = rand() % x;
            for (int z = 0;z < k;z++)
            {
                if (position_store[z] == r_word_position)
                {
                    goto choose_again2;
                }
            }
            position_store[k] = r_word_position;
            k += 1;
            for (i = 0; i < strlen(words[r_word_position]); i++)
            {
                r_word_pass[i] = words[r_word_position][i];
            }

        rand_choose_again2:
            direction = rand() % 3;
            r_row = random_row(row, i, r_word_pass);
            r_col = random_column(col, i, r_word_pass);
            to_not_overlap = CheckWordWillFit(direction, r_row, r_col, i, r_word_pass, row, col, grid);
            if (to_not_overlap == 5)
            {
                goto rand_choose_again2;
            }
            PlaceWords(r_row, r_col, direction, r_word_pass, row, col, grid);
        }

        GridRandomFill(row, col, grid, letters);


    }
    else
    {
        printf("\nYou have entered a wrong choice..!!");
        goto label;
    }

    return 0;
}

// COMPUTER-DEFINED WORDS
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

// STORING WORDS ENTERED BY THE USER
void user_words(int x, char user[x][15])
{
    printf("\nEnter the word(s): ");
    for (int i = 0; i < x; i++)
    {
        scanf("%s", user[i]);
    }
}


//CREATES THE PUZZLE
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
//DISPLAYS THE PUZZLE
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
//PLACES WORDS ON THE PUZZLE
void PlaceWords(int r_row, int r_col, int direction, char r_word_pass[15], int row, int col, char grid[row][col])
{
    if (direction == 0)
    {
        for (int p = 0;p < strlen(r_word_pass);p++)
        {
            grid[r_row][r_col] = r_word_pass[p];
            r_row += 1;
        }
    }
    else if (direction == 1)
    {
        for (int p = 0;p < strlen(r_word_pass);p++)
        {
            grid[r_row][r_col] = r_word_pass[p];
            if (p < strlen(r_word_pass) - 1)
            {
                r_row -= 1;
            }
        }
    }
    else
    {
        for (int p = 0;p < strlen(r_word_pass);p++)
        {
            grid[r_row][r_col] = r_word_pass[p];
            r_col += 1;
        }
    }
}
//CHOOSES A RANDOM ROW
int random_row(int row, int i, char r_word_pass[i])
{
    int fits_in_row, r_row;
    do
    {
        r_row = rand() % row;
        fits_in_row = strlen(r_word_pass) + r_row;
    } while (fits_in_row > row);
    return r_row;
}
// CHOOSES A RANDOM COLUMN
int random_column(int col, int i, char r_word_pass[i])
{
    int fits_in_col, r_col;

    do
    {
        r_col = rand() % col;
        fits_in_col = strlen(r_word_pass) + r_col;
    } while (fits_in_col > col);
    return r_col;
}
// CHECKS IF THE WORDS FILL CORRECTLY ON THE PUZZLE WITHOUT OVERLAPPING ON ONE ANOTHER
int CheckWordWillFit(int direction, int r_row, int r_col, int i, char r_word_pass[i], int row, int col, char grid[row][col])
{
    for (int p = 0;p < strlen(r_word_pass);p++)
    {
        if (direction == 0)
        {
            if (grid[r_row][r_col] != '-')
            {
                return 5;
            }
            r_row += 1;
        }
        else if (direction == 1)
        {
            if (grid[r_row][r_col] != '-')
            {
                return 5;
            }
            r_row -= 1;
        }
        else if (direction == 2)
        {
            if (grid[r_row][r_col] != '-')
            {
                return 5;
            }
            r_col += 1;
        }
    }
    return 8;
}
//FILLS THE PUZZLE RANDOMLY IN THE PLACES THAT ARE EMPTY
void GridRandomFill(int row, int col, char grid[row][col], char letters[26])
{
    for (int i = 0; i < row;i++)
    {
        for (int j = 0; j < col;j++)
        {
            if (grid[i][j] == '-')
            {
                grid[i][j] = letters[rand() % 26];
            }
        }
    }
}