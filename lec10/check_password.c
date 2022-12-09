# include <stdio.h>
# include <string.h>

#define SIZE 25

int length(char pwd1[], char pwd2[]);

int compare(char pwd1[], char pwd2[]);

int content(char pwd1[]);

int main()
{
    char password1[SIZE];
    char password2[SIZE];
    
    // Enter the password
    scanf("%s", password1);
    // Enter the password again
    scanf("%s", password2);
    
    // Check Password
    // First: Check length
    if(length(password1, password2) == 1) {
        printf("Length does not match the requirements");
    }
    else {
        // Second: Check for consistency
        if(compare(password1, password2) == 1) {
            printf("Not the same password");
        }
        else {
            // Third: Check for compliance
            if(content(password1) == 1) {
                printf("Do not satisfy the conditions");
            }
            else {
                printf("Everything is good");
            }
        }
    }

    return 0;
}

//

int length(char pwd1[], char pwd2[]) {
    int len1 = strlen(pwd1);
    int len2 = strlen(pwd2);
    return !(6 <= len1 && len1 <= 16 && 6 <= len2 && len2 <= 16);
}

int compare(char pwd1[], char pwd2[]) {
    int len = strlen(pwd1);
    if (len != strlen(pwd2)) {
        return 1;
    }
    for (int i = 0;i < len;i++) {
        if (pwd1[i] != pwd2[i]) {
            return 1;
        }
    }
    return 0;
}

int content(char pwd1[]) {
    int cap = 0, low = 0, digit = 0;
    int len = strlen(pwd1);
    for (int i = 0;i < len;i++) {
        if ('a' <= pwd1[i] && pwd1[i] <= 'z') {
            low = 1;
        } else if ('A' <= pwd1[i] && pwd1[i] <= 'Z') {
            cap = 1;
        } else if ('0' <= pwd1[i] && pwd1[i] <= '9') {
            digit = 1;
        }
    }
    return !(cap & low & digit);
}