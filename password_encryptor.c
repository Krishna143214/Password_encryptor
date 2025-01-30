#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Author :- Krishna Dubey
   Start date :- 19 Jan
   End date :- 30 jan
*/

int main() {
    while (1) {
        system("clear");

        FILE *ptr;
        ptr = fopen("encrypt.txt", "a+");
        if (ptr == NULL) {
            printf("\nData not stored\n\n");
            return 1; 
        }

        char pass[1000];
        char decrp[1000];
        char name[300];
        char ph_no[100];
        int kye = 0;
        int de_kye = 0;
        int ch;
        char fp;

        printf("######  Password Encryptor/Decryptor By Krishna Dubey ######\n\n\n\n");
        printf("Enter your name : ");
        scanf("%s", name);
        printf("\n\n");
        fprintf(ptr, "Name of user: %s \n\n", name);

        printf("Enter your ph_no: ");
        scanf("%s", ph_no);
        printf("\n\n");
        fprintf(ptr, "Phone no of user: %s \n\n", ph_no);

        printf("1. Encryption\n");
        printf("2. Decryption\n");
        printf("3. Read Previous Data\n");
        printf("4. Exit\n\n");

        printf("Enter your response: ");
        scanf("%d", &ch);

        if (ch == 1) {
            while (1) {
                system("clear");
                printf("\n\nYOU Selected Encryption\n\n");
                printf("1. Encryption\n2. Previous menu\n\n");
                int ch_en;
                printf("Enter your choice: ");
                scanf("%d", &ch_en);

                if (ch_en == 1) {
                    printf("\n\n\nEnter your pass for Encryption (please don't use whitespaces): ");
                    getchar();
                    fgets(pass, sizeof(pass), stdin);
                    pass[strcspn(pass, "\n")] = 0; 

                    printf("\n\nEnter the key for Encryption (numeric): ");
                    scanf("%d", &kye);

                    int len = strlen(pass);
                    for (int i = 0; i < len; i++) {
                        pass[i] = pass[i] + kye;
                    }
                    printf("Your Encrypted password: %s\n", pass);

                    fprintf(ptr, "Your Encrypted password: %s\n", pass);
                    fprintf(ptr, "Your Encryption key: %d\n", kye);
                    fprintf(ptr, "\n\n");
                } else if (ch_en == 2) {
                    break;
                } else {
                    printf("Invalid option. Returning to main menu.\n");
                    break;
                }
            }
        } else if (ch == 2) {
            while (1) {
                system("clear");
                printf("\n\nYOU Selected Decryption\n\n");
                printf("1. Decryption\n2. Previous menu\n\n");
                int ch_de;
                printf("Enter your choice: ");
                scanf("%d", &ch_de);

                if (ch_de == 1) {
                    printf("\n\n\nEnter your pass for Decryption (please don't use whitespaces): ");
                    getchar();
                    fgets(decrp, sizeof(decrp), stdin);
                    decrp[strcspn(decrp, "\n")] = 0; 

                    printf("\n\nEnter the key for decryption (numeric): ");
                    scanf("%d", &de_kye);

                    int len = strlen(decrp);
                    for (int i = 0; i < len; i++) {
                        decrp[i] = decrp[i] - de_kye;
                    }
                    printf("Your Decrypted password: %s\n", decrp);
                } else if (ch_de == 2) {
                    break;
                } else {
                    printf("Invalid option. Returning to main menu.\n");
                    break;
                }
            }
        } else if (ch == 3) {
            
            system("clear");
            printf("\n\n### Reading Previous Data ###\n\n");

            fseek(ptr, 0, SEEK_SET); 
            
            while (!feof(ptr)) {
                ch=fgetc(ptr);
                printf("%c",ch);
            }

            printf("\n\nPress any key to return to the main menu...\n");
            getchar(); 
            getchar(); 
        } else if (ch == 4) {
            fclose(ptr);
            printf("\nExiting program. Goodbye!\n");
            return 0;
        } else {
            printf("Invalid option. Please try again.\n");
        }

        fclose(ptr);
    }

    return 0;
}




