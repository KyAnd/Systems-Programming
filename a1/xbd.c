/*************************************************************
 Name: Jan Domingo
 username: CSSC0463
 Project: CS530 Assignment 1
 File: xbd.c
 Notes: Output should match that as the unix command "xxd <filename>"
 Date Due: February 18, 2019
 Assignment Instructions:
    Develop, test and deliver a basic hexadecimal file dump 'xbd'
    The basic hexdump program will open a regular type file (containing binary or text/ASCII content),
    read every byte in the file and write both the ASCII hex value for that byte as well as it’s printable
    (human-readable) character (characters, digits, symbols) to standard output.
    For bytes forming non-printable characters, print a ‘.’ character (a dot/period character, i.e. hex value 2E).
*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TODO: Step 0: Figure out how to make methods in C
//TODO: Step 1: ---DONE---Read in the file, don't worry about terminal input yet
//TODO: Step 1.1: ---DONE---Figure out how to display in hex and binary
//TODO: Step 1.12: Print out the actual text chars after printing out the hex or bin numbers
//TODO: Step 1.2: Create a the fileOpen function
//TODO: Step 2: Figure out how to output the file contents into both hex and binary
//TODO: Step 3: Figure out how to run in terminal with user argument parameters
//TODO: Step 4: When done, clean up header comments, move Assignment Instructions to README file
//Make sure that main does not have a  lot of contents

int printHex();
int printBin();
char filename[100];

int main (int argc,char *argv[]) {


    //printf("Enter the filename: \n");
    //scanf("%s", filename);
    printHex();
    printBin();
}


/*************************************************************
function: FileOpen
Notes: A sample of how to use embedded comments
I/O: input parameters: the file name and file mode
     output: the file pointer to the file openned
*************************************************************/
int printHex() {
    //*******OPENS FILE*******
    FILE *fp;
    fp = fopen("helloworld.txt", "r");
    int ch = 0; //ch holds each character of the string as it iterates through the file
    int index = 0;  //Index is the value that is displayed in the leftmost column on the output
    char textPrint[16];
    int i = 0;


    //*******PRINTS HEXADECIMAL VALUE*******
    while (!feof(fp)) {
        ch = fgetc(fp);
        if (index % 16 == 0 || feof(fp)) {  //Print the address every 16 bytes, create a new line
            if (index != 0) {   //Prevents uninitialized array from being outputted in the beginning of the program
                printf("\t%s", textPrint);
            }
            printf("\n");
            printf("%08x: ", index);    //Appends 0's in front of the address and prints in hex
            i = 0;
        }

        textPrint[i] = ch;
        printf("%x", ch);        //Prints the hexadecimal character of each character in a string
        index++;
        i++;
        if (index % 2 == 0) {   //After every 2 characters, print a space
            printf(" ");
        }

    }
}

int printBin() {
    //*******PRINTS BINARY VALUE*******
    printf("\n-------------------------------------------------\n");
    FILE *fp;
    fp = fopen("helloworld.txt", "r");  //TODO: DELETE THIS LINE LATER AND MAKE FILEOPEN ITS OWN FUNCTION
    int ch = 0;
    int index = 0;
    int chInt;
    int c,k;
    char textPrint[5];
    int i = 0;

    while(!feof(fp)) {  //TODO: Place this and the next line into its own function
        ch = fgetc(fp);
        if (index % 6 == 0 || feof(fp)) {   //Prints every 6 octets
            printf("\t%s", textPrint);
            printf("\n");
            printf("%08x: ", index);    //Appends 0's in front of the address and prints in octal
            i = 0;
        }

        //*******Converts integer value into Binary using bitwise shift*******
        chInt = (int)ch;  //chInt stands for Char Integer and will store the integer value of the character
        for (c = 7; c >= 0; c--)
        {
            k = chInt >> c;
            if (k & 1)
                printf("1");
            else
                printf("0");
        }
        textPrint[i] = ch;
        index++;
        i++;
        printf(" ") ;   //After each char, print a space

    }
    fclose(fp);
}