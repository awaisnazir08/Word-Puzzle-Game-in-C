#include<stdio.h>

void user_words(int x, char user[][15]);
void comp_words(int x, char fix[][15]);

int main()
{
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
    return 0;
}

//pre_defined words are stored in this function
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

//words entered by the user are stored in this function
void user_words(int x, char user[x][15])
{
    printf("\nEnter the word(s): ");
    for (int i = 0; i < x; i++)
    {
        scanf("%s", user[i]);
    }
}