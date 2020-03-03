#include <stdio.h>

int string_size = 256;

int string_len(char a[])
{
    int len = 0;
    int i = 0;
    while (1)
    {
        if (a[i] == '\0')
        {
            break;
        }
        else
        {
            len++;
        }
        i++;
    }
    return len - 1;
}

int main()
{
    while (1)
    {
        printf("Choose Operation:\n1. Reversing String\n2. Replace Substring\n3. Correct Capitalization\n4. Add suffix\n5. Trim suffix\n6. Break\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            char str[string_size];
            printf("Enter String: ");
            fgets(str, string_size, stdin);
            fgets(str, string_size, stdin);
            int len = string_len(str);
            printf("%d\n", len);
            int i;
            for (i = 0; i < len / 2; i++)
            {
                char tem = str[len - i - 1];
                str[len - i - 1] = str[i];
                str[i] = tem;
            }

            printf("%s\n\n", str);
        }

        else if (choice == 2)
        {
            char str[string_size];
            char search[string_size];
            char replace[string_size];

            printf("Enter String: ");
            fgets(str, string_size, stdin);
            fgets(str, string_size, stdin);
            printf("Find subString: ");
            fgets(search, string_size, stdin);

            int len = string_len(str);
            int subLen = string_len(search);

            int index = -1;
            for (int i = 0; i < len; i++)
            {
                int flag = 1;
                for (int j = 0; j < subLen; j++)
                {
                    if (search[j] != str[i + j])
                    {
                        flag = 0;
                    }
                }

                if (flag == 1)
                {
                    index = i;
                    break;
                }
            }
            if (index == -1)
            {
                printf("No subString found\n");
                continue;
            }
            printf("Enter replacement: ");
            fgets(replace, string_size, stdin);

            int len2 = string_len(replace);

            char temp[string_size];

            for (int i = 0; i < index; i++)
            {
                temp[i] = str[i];
            }

            for (int j = 0; j < len2; j++)
            {
                temp[index + j] = replace[j];
            }
            char str2[string_size];

            int j = 0;
            for (int i = index + subLen; i <= len; i++)
            {
                str2[j++] = str[i];
            }

            int str_len = string_len(str2);

            char final[2 * string_size];

            for (int i = 0; i < index + len2; i++)
            {
                final[i] = temp[i];
            }

            for (int i = 0; i <= str_len; i++)
            {
                final[index + len2 + i] = str2[i];
            }
            final[index + len2 + str_len] = '\0';
            printf("%s\n", final);
        }

        else if (choice == 3)
        {
            char str[string_size];
            fgets(str, string_size, stdin);
            fgets(str, string_size, stdin);

            int len = string_len(str);
            int flag = -1;
            for (int i = 0; i < len; i++)
            {
                if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
                {
                    str[i] = str[i] - 32;
                }
                else if (str[i] == '.')
                {
                    flag = 1;
                }
                else if (flag == 1 && str[i] >= 'a' && str[i] <= 'z')
                {
                    flag = -1;
                    str[i] = str[i] - 32;
                }
                else if (flag == 1 && str[i] >= 'A' && str[i] <= 'Z')
                {
                    flag = -1;
                }
                else
                {
                    //
                }
            }
            printf("%s\n", str);
        }
        else if (choice == 4)
        {
            char str[string_size];
            char suffix[string_size];

            printf("Enter String: ");
            fgets(str, string_size, stdin);
            fgets(str, string_size, stdin);
            printf("Find subString: ");
            fgets(suffix, string_size, stdin);

            int len1 = string_len(str);
            int len2 = string_len(suffix);

            char final[256];

            for (int i = 0; i < len1; i++)
            {
                final[i] = str[i];
            }

            for (int i = 0; i < len2; i++)
            {
                final[len1 + i] = suffix[i];
            }
            final[len1 + len2] = '\0';
            printf("%s\n", final);
        }

        else if (choice == 5)
        {
            char str[string_size];
            char suffix[string_size];

            printf("Enter String: ");
            fgets(str, string_size, stdin);
            fgets(str, string_size, stdin);
            printf("Find suffix: ");
            fgets(suffix, string_size, stdin);

            int len = string_len(str);
            int subLen = string_len(suffix);

            int index = -1;
            for (int i = len - subLen - 1; i < len; i++)
            {
                int flag = 1;
                for (int j = 0; j < subLen; j++)
                {
                    if (suffix[j] != str[i + j])
                    {
                        flag = 0;
                    }
                }

                if (flag == 1)
                {
                    index = i;
                    break;
                }
            }
            if (index == -1)
            {
                printf("No suffix found\n");
                continue;
            }

            char final[string_size];

            for (int i = 0; i < index; i++)
            {
                final[i] = str[i];
            }

            final[index+1] = '\0' ;

            printf("%s\n", final);
        }

        else
        {
            break;
        }
    }

    return 0;
}