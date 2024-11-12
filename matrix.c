#include <stdio.h>

void accept_matrix(int original[20][20], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &original[i][j]);
        }
    }
}

void display_matrix(int original[20][20], int m, int n)
{
    printf("\nThe matrix is: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", original[i][j]);
        }
        printf("\n");
    }
}

void convert_compact(int original[20][20], int compact[20][3], int m, int n)
{
    int k = 1; // used for two purposes - counting non-zero elements  and to keep track of the row number in the compact matrix

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (original[r][c] != 0)
            {
                compact[k][0] = r;
                compact[k][1] = c;
                compact[k][2] = original[r][c];
                k++;
            }
        }
    }
    compact[0][0] = m;
    compact[0][1] = n;
    compact[0][2] = k - 1;
}

void display_compact_matrix(int compact[20][3])
{
    for (int i = 0; i < compact[0][2] + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", compact[i][j]);
        }
        printf("\n");
    }
}

void simple_transpose(int compact[20][3], int transpose[20][3])
{
    transpose[0][0] = compact[0][1];
    transpose[0][1] = compact[0][0];
    transpose[0][2] = compact[0][2];
    int k = 1;
    for (int i = 0; i < compact[0][1]; i++) // this loop is to start from 0 then 1 then 2 etc
    {
        for (int j = 1; j <= compact[0][2]; j++) // this loop traverse the column indexes
        {
            if (compact[j][1] == i) // check if the column index is equal to 0/1/2 etc
            {
                transpose[k][0] = compact[j][1];
                transpose[k][1] = compact[j][0];
                transpose[k][2] = compact[j][2];
                k++;
            }
        }
    }
}

void fast_transpose(int compact[20][3], int transpose[20][3])
{
    int total[compact[0][1]];
    int index[compact[0][1] + 1];
    int col_no, loc;
    for (int i = 0; i < compact[0][1]; i++)
    {
        total[i] = 0;
    }
    for (int i = 1; i <= compact[0][2]; i++)
    {
        col_no = compact[i][1];
        total[col_no]++;
    }
    index[0] = 1;
    for (int i = 1; i <= compact[0][1]; i++)
    {
        index[i] = index[i - 1] + total[i - 1];
    }
    transpose[0][0] = compact[0][1];
    transpose[0][1] = compact[0][0];
    transpose[0][2] = compact[0][2];
    for (int i = 1; i <= compact[0][2]; i++)
    {
        col_no = compact[i][1];
        loc = index[col_no];
        transpose[loc][0] = compact[i][1];
        transpose[loc][1] = compact[i][0];
        transpose[loc][2] = compact[i][2];
        index[col_no]++;
    }
}

void addition(int compact[20][3], int compact2[20][3], int result[20][3])
{
    int i = 1, j = 1, k = 1;
    result[0][0] = compact[0][0];
    result[0][1] = compact[0][1];
    while (i <= compact[0][2] && j <= compact2[0][2])
    {
        if (compact[i][0] == compact2[j][0])
        {
            if (compact[i][1] == compact2[j][1])
            {
                result[k][0] = compact[i][0];
                result[k][1] = compact[i][1];
                result[k][2] = compact[i][2] + compact2[j][2];
                i++;
                j++;
                k++;
            }
            else
            {
                if (compact[i][1] < compact2[j][1])
                {
                    result[k][0] = compact[i][0];
                    result[k][1] = compact[i][1];
                    result[k][2] = compact[i][2];
                    i++;
                    k++;
                }
                else
                {
                    if (compact[i][1] > compact2[j][1])
                    {
                        result[k][0] = compact2[j][0];
                        result[k][1] = compact2[j][1];
                        result[k][2] = compact2[j][2];
                        j++;
                        k++;
                    }
                }
            }
        }
        else
        {
            if (compact[i][0] < compact2[j][0])
            {
                result[k][0] = compact[i][0];
                result[k][1] = compact[i][1];
                result[k][2] = compact[i][2];
                i++;
                k++;
            }
            else
            {
                if (compact[i][0] > compact2[j][0])
                {
                    result[k][0] = compact2[j][0];
                    result[k][1] = compact2[j][1];
                    result[k][2] = compact2[j][2];
                    j++;
                    k++;
                }
            }
        }
    }
    while ( (i>=compact[0][2]) && (j<=compact2[0][2]))
    {
        result[k][0]=compact2[j][0];
        result[k][1]=compact2[j][1];
        result[k][2]=compact2[j][2];
        j++;
        k++;
    }
    while ( (j>=compact2[0][2]) && (i<=compact[0][2]))
    {
        result[k][0]=compact[i][0];
        result[k][1]=compact[i][1];
        result[k][2]=compact[i][2];
        i++;
        k++;
    }
    result[0][2]=k-1;
}

//using switch
// void addition(int compact[20][3], int compact2[20][3], int result[20][3])
// {
//     int i = 1, j = 1, k = 1;
//     result[0][0] = compact[0][0];
//     result[0][1] = compact[0][1];

//     while (i <= compact[0][2] && j <= compact2[0][2]) {
//         int case_id;
        
//         if (compact[i][0] < compact2[j][0]) 
//             case_id = 1;
//         else if (compact[i][0] > compact2[j][0])
//             case_id = 2;
//         else if (compact[i][1] < compact2[j][1])
//             case_id = 1;
//         else if (compact[i][1] > compact2[j][1])
//             case_id = 2;
//         else 
//             case_id = 3;
        
//         switch (case_id) {
//             case 1: // Copy from compact to result
//                 result[k][0] = compact[i][0];
//                 result[k][1] = compact[i][1];
//                 result[k][2] = compact[i][2];
//                 i++;
//                 break;
            
//             case 2: // Copy from compact2 to result
//                 result[k][0] = compact2[j][0];
//                 result[k][1] = compact2[j][1];
//                 result[k][2] = compact2[j][2];
//                 j++;
//                 break;
                
//             case 3: // Sum elements and add to result
//                 result[k][0] = compact[i][0];
//                 result[k][1] = compact[i][1];
//                 result[k][2] = compact[i][2] + compact2[j][2];
//                 i++;
//                 j++;
//                 break;
//         }
//         k++;
//     }

//     while ( (i>=compact[0][2]) && (j<=compact2[0][2]))
    // {
    //     result[k][0]=compact2[j][0];
    //     result[k][1]=compact2[j][1];
    //     result[k][2]=compact2[j][2];
    //     j++;
    //     k++;
    // }
    // while ( (j>=compact2[0][2]) && (i<=compact[0][2]))
    // {
    //     result[k][0]=compact[i][0];
    //     result[k][1]=compact[i][1];
    //     result[k][2]=compact[i][2];
    //     i++;
    //     k++;
    // }
    // result[0][2]=k-1;
// }


int main()
{
    int original[20][20], compact[20][3], transpose[20][3],original2[20][20],compact2[20][3],result[20][3];
    int m, n, choice;
    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);
    accept_matrix(original, m, n);
    display_matrix(original, m, n);
    convert_compact(original, compact, m, n);
    printf("The compact matrix is: \n");
    display_compact_matrix(compact);
    printf("Enter which transpose you want to perform: \n1.Simple Transpose\n2.Fast transpose");
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        simple_transpose(compact, transpose);
    }
    else if (choice == 2)
    {
        fast_transpose(compact, transpose);
    }
    printf("The transposed matrix is: \n");
    display_compact_matrix(transpose);
    printf("\nEnter details of 2nd matrix: \n");
    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);
    accept_matrix(original2, m, n);
    display_matrix(original2, m, n);
    convert_compact(original2, compact2, m, n);
    printf("\nThe 2nd compact matrix is: \n");
    display_compact_matrix(compact2);
    printf("\nAddition of the 2 compact matrices is: \n");
    addition(compact, compact2, result);
    display_compact_matrix(result);
    return 0;
}