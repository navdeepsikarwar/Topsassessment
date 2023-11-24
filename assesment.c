#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void reverseString(char str[]);
void concatenateStrings(char str1[], char str2[]);
int isPalindrome(char str[]);
void copyString(char str[]);
int getStringLength(char str[]);
int countCharacterFrequency(char str[], char ch);
void countVowelsConsonants(char str[], int *vowels, int *consonants);
void countSpacesDigits(char str[], int *spaces, int *digits);

int main() {
    char input_str[100];
    char str1[50], str2[50];
    char char_choice;
    int choice, frequency, length, vowels, consonants, spaces, digits;
    char continue_option[3];

    do {
        printf("\nString Operations Menu:\n");
        printf("1. Reverse a string\n");
        printf("2. Concatenate strings\n");
        printf("3. Check palindrome\n");
        printf("4. Copy a string\n");
        printf("5. Get length of a string\n");
        printf("6. Count character frequency\n");
        printf("7. Count vowels and consonants\n");
        printf("8. Count spaces and digits\n");
        printf("9. Exit\n");

        printf("Enter your choice (1-9): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                scanf("%s", input_str);
                reverseString(input_str);
                printf("Reversed string: %s\n", input_str);
                break;
            case 2:
                printf("Enter the first string: ");
                scanf("%s", str1);
                printf("Enter the second string: ");
                scanf("%s", str2);
                concatenateStrings(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;
            case 3:
                printf("Enter a string: ");
                scanf("%s", input_str);
                if (isPalindrome(input_str)) {
                    printf("The string is a palindrome.\n");
                } else {
                    printf("The string is not a palindrome.\n");
                }
                break;
            case 4:
                printf("Enter a string: ");
                scanf("%s", input_str);
                copyString(input_str);
                printf("Copied string: %s\n", input_str);
                break;
            case 5:
                printf("Enter a string: ");
                scanf("%s", input_str);
                length = getStringLength(input_str);
                printf("Length of the string: %d\n", length);
                break;
            case 6:
                printf("Enter a string: ");
                scanf("%s", input_str);
                printf("Enter a character: ");
                scanf(" %c", &char_choice);
                frequency = countCharacterFrequency(input_str, char_choice);
                printf("Frequency of '%c' in the string: %d\n", char_choice, frequency);
                break;
            case 7:
                printf("Enter a string: ");
                scanf("%s", input_str);
                countVowelsConsonants(input_str, &vowels, &consonants);
                printf("Number of vowels: %d\n", vowels);
                printf("Number of consonants: %d\n", consonants);
                break;
            case 8:
                printf("Enter a string: ");
                scanf("%s", input_str);
                countSpacesDigits(input_str, &spaces, &digits);
                printf("Number of blank spaces: %d\n", spaces);
                printf("Number of digits: %d\n", digits);
                break;
            case 9:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 9.\n");
        }

        printf("Do you want to continue? (yes/no): ");
        scanf("%s", continue_option);

    } while (strcmp(continue_option, "yes") == 0 || strcmp(continue_option, "Yes") == 0);

    return 0;
}

// Function to reverse a string
void reverseString(char str[]) {
    int length = strlen(str);
    int i, j;
    char temp;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to concatenate two strings
void concatenateStrings(char str1[], char str2[]) {
    strcat(str1, str2);
}

// Function to check if a string is palindrome
int isPalindrome(char str[]) {
    int length = strlen(str);
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome
}

// Function to copy a string
void copyString(char str[]) {
    // No need for a separate function, strcpy can be used directly
    strcpy(str, str);
}

// Function to get the length of a string
int getStringLength(char str[]) {
    return strlen(str);
}

// Function to count the frequency of a character in a string
int countCharacterFrequency(char str[], char ch) {
    int frequency = 0;
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == ch) {
            frequency++;
        }
    }
    return frequency;
}

// Function to count vowels and consonants in a string
void countVowelsConsonants(char str[], int *vowels, int *consonants) {
    *vowels = 0;
    *consonants = 0;
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) {
            char lowercaseChar = tolower(str[i]);
            if (lowercaseChar == 'a' || lowercaseChar == 'e' || lowercaseChar == 'i' ||
                lowercaseChar == 'o' || lowercaseChar == 'u') {
                (*vowels)++;
            } else {
                (*consonants)++;
            }
        }
    }
}

// Function to count blank spaces and digits in a string
void countSpacesDigits(char str[], int *spaces, int *digits) {
    *spaces = 0;
    *digits = 0;
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (isspace(str[i])) {
            (*spaces)++;
        } else if (isdigit(str[i])) {
            (*digits)++;
        }
    }
}
