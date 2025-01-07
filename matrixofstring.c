#include <stdio.h>
#include <string.h>
#define MAX_STRING_LEN 50
int main()
{
    int row, col;
    printf("Enter number of rows:");
    scanf("%d", &row);
    if(row < 1 || row > 10) {
        printf("Row size should be between 1 to 10 \n");
        return 1;
    }
    printf("Enter number of columns:");
    scanf("%d", &col);
    if(col < 1 || col > 101) {
        printf("Column size should be between 1 to 101 \n");
        return 1;
    }
    getchar();  
    char name_matrix[row][col][MAX_STRING_LEN];
    printf("Enter the names:\n");
    getchar();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter name at (%d, %d): ", i, j);
            scanf("%[^\n]", name_matrix[i][j]);
            getchar();
        }
    }
    printf("The 2D array of names is:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%s ", name_matrix[i][j]);
        }
        printf("\n");
    }
    int vowel_count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (name_matrix[i][j][0] == 'a' || name_matrix[i][j][0] == 'e' ||
                name_matrix[i][j][0] == 'i' || name_matrix[i][j][0] == 'o' ||
                name_matrix[i][j][0] == 'u' || name_matrix[i][j][0] == 'A' ||
                name_matrix[i][j][0] == 'E' || name_matrix[i][j][0] == 'I' ||
                name_matrix[i][j][0] == 'O' || name_matrix[i][j][0] == 'U')
            {
                vowel_count += 1;
            }
        }
    }
    printf("Number of names starting with a vowel: %d\n", vowel_count);
    int longest_name_length = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (strlen(name_matrix[i][j]) > longest_name_length)
            {
                longest_name_length = strlen(name_matrix[i][j]);
            }
        }
    }
    char longest_names_array[row*col][MAX_STRING_LEN];
    int word_count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (strlen(name_matrix[i][j]) == longest_name_length)
            {
                strcpy(longest_names_array[word_count], name_matrix[i][j]);
                word_count++;
            }
        }
    }
    printf("longest name :\n");
    for (int i = 0; i < word_count; i++)
    {
        printf("%s\n", longest_names_array[i]);
    }
    return 0;
}