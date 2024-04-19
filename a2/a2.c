#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include <tclDecls.h>
#include "a2.h"
#include <ctype.h>
// YOUR CODE GOES HERE

// Print the string <first> <middle> <last>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben Ivan Bitdiddle".
//
//  If the middle name is NULL, then print:
//  "Ben Bitdiddle"
//
//  name: a pointer to a Name


void Big(Name *name) {
//    char arr[100];
//    arr[0] = '\0';
//
    if (name !=NULL){
//        toupper(name->first[0]);

        printf("%c", toupper(name ->first[0]));
        for (int i = 1; name->first[i] !='\0' ; ++i) {
            printf("%c", tolower(name->first[i]));
        }
        printf(" ");
//        printf("%s ",name ->first);

        if (name->middle!=NULL){
            printf("%c", toupper(name->middle[0]));
            for (int i = 1; name->middle[i] !='\0' ; ++i) {
                printf("%c", tolower(name->middle[i]));
            }
            printf(" ");
        }

        printf("%c", toupper(name->last[0]));
        for (int i = 1; name->last[i] !='\0'; ++i) {
            printf("%c", tolower(name->last[i]));
        }
    }else{
        printf("Input of *name is NULL");
    }

}


// Print the string <last>, <first>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Bitdiddle, Ben".
//
// name: a pointer to a Name
void Last(Name *name) {
    printf("%c", toupper(name->last[0]));
    for (int i = 1; name->last[i] !='\0'; ++i) {
        printf("%c", tolower(name->last[i]));
    }

    printf(", ");

    printf("%c", toupper(name ->first[0]));
    for (int i = 1; name->first[i] !='\0' ; ++i) {
        printf("%c", tolower(name->first[i]));
    }

}

// Print the string <first> <last>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben Bitdiddle".
//
// name: a pointer to a Name
void Reg(Name *name) {
    printf("%c", toupper(name ->first[0]));
    for (int i = 1; name->first[i] !='\0' ; ++i) {
        printf("%c", tolower(name->first[i]));
    }

    printf(" ");

    printf("%c", toupper(name->last[0]));
    for (int i = 1; name->last[i] !='\0'; ++i) {
        printf("%c", tolower(name->last[i]));
    }

}

// Print the string <first> <middle-initial>. <last>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben I. Bitdiddle".
//
// If middle name is NULL, print:
// "Ben Bitdiddle"
//
// name: a pointer to a Name
void Mid(Name *name) {
    if (name->middle != NULL) {
        printf("%c", toupper(name->first[0]));
        for (int i = 1; name->first[i] != '\0'; ++i) {
            printf("%c", tolower(name->first[i]));
        }

        printf(" ");

        printf("%c. ", toupper(name->middle[0]));

        printf("%c", toupper(name->last[0]));
        for (int i = 1; name->last[i] != '\0'; ++i) {
            printf("%c", tolower(name->last[i]));
        }
    } else {

        printf("%c", toupper(name->first[0]));
        for (int i = 1; name->first[i] != '\0'; ++i) {
            printf("%c", tolower(name->first[i]));
        }

        printf(" ");

        printf("%c", toupper(name->last[0]));
        for (int i = 1; name->last[i] != '\0'; ++i) {
            printf("%c", tolower(name->last[i]));

        }
    }
}




////        printf("%s %c. %s",name->first,(name->middle)[0],name->last);
//    }else{
//        printf("%s %s",name->first,name->last);
//    }
//}

// Print the first name only.
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben".
//
// name: a pointer to a Name
void Small(Name *name){

    printf("%c", toupper(name->first[0]));
    for (int i = 1; name->first[i] != '\0'; ++i) {
        printf("%c", tolower(name->first[i]));
    }

//    printf("%s",name->first);

}

// Given a format char, print the given
// name in the format specified by char.
// The mapping is shown below:
// B -> 'big' format
// L -> 'last' format
// R -> 'reg' format
// M -> 'mid' format
// S -> 'small' format
//
// name: a pointer to a Name
// format: a char indicating the format to use (case doesn't matter)
void FormatName(Name *name, char format){
    if (format == 'B' || format =='b'){
        Big(name);
    }else if (format == 'L'|| format=='l') {
        Last(name);
    }else if (format =='R'|| format=='r'){
        Reg(name);
    }else if (format == 'M'|| format=='m'){
        Mid(name);
    }else if(format == 'S'|| format=='s'){
        Small(name);
    }

}

// Given a name, a format and a destination array,
// put the properly formatted name in the destination
// array, not printing anything on the screen.
//
// The mapping is shown below:
// B -> 'big' format
// L -> 'last' format
// R -> 'reg' format
// M -> 'mid' format
// S -> 'small' format
//
// name: a pointer to a Name
// format: a char indicating the format to use (case doesn't matter)
// dest: a pointer to an array that is guaranteed to be big enough
// to hold the formatted name
void FillName(Name *name, char format, char *dest) {
    dest[0] ='\0';
    if (format == 'B' || format =='b') {
        if (name->middle != NULL) {
            dest[0]=toupper((unsigned char)name->first[0]);
//            strcat(dest, (char[]){toupper((unsigned char)name->first[0])});
            for (int i = 1; name->first[i] !='\0' ; ++i) {
                dest[i] = tolower((unsigned )name->first[i]);
//                strcat(dest, (char[]){tolower((unsigned char)name->first[i])});
            }
            char space[] = " ";
            strcat(dest,space);

//            strcat(dest, name->middle);
            dest[strlen(dest)] = toupper((unsigned char)name->middle[0]);
//            strcat(dest, (char[]){toupper((unsigned char)name->middle[0])});
            for (int i = 1; name->middle[i] !='\0' ; ++i) {
//                strcat(dest, (char[]){tolower((unsigned char)name->middle[i])});
                dest[strlen(dest)] = tolower((unsigned char )name->middle[i]);
            }

            strcat(dest,space);
//            strcat(dest, name->last);

//            strcat(dest, (char[]){toupper((unsigned char)name->last[0])});
            dest[strlen(dest)] = toupper((unsigned char)name->last[0]);
            for (int i = 1; name->last[i] !='\0' ; ++i) {
//                strcat(dest, (char[]){tolower((unsigned char)name->last[i])});
                dest[strlen(dest)] = tolower((unsigned char )name->last[i]);
            }
        } else {
//            strcat(dest, name->first);
            dest[0]=toupper((unsigned char)name->first[0]);
//            strcat(dest, (char[]){toupper((unsigned char)name->first[0])});
            for (int i = 1; name->first[i] !='\0' ; ++i) {
                dest[i] = tolower((unsigned )name->first[i]);
//                strcat(dest, (char[]){tolower((unsigned char)name->first[i])});
            }
            char space[] = " ";
            strcat(dest,space);

//            strcat(dest, name->last);
            dest[strlen(dest)] = toupper((unsigned char)name->last[0]);
            for (int i = 1; name->last[i] !='\0' ; ++i) {
//                strcat(dest, (char[]){tolower((unsigned char)name->last[i])});
                dest[strlen(dest)] = tolower((unsigned char )name->last[i]);
            }
        }
    }else if (format == 'L'|| format=='l') {
        /* Print the string <last>, <first>
          e.g. if first = "Ben", middle = "Ivan",
          and last = "Bitdiddle, then print:
          "Bitdiddle, Ben".

         name: a pointer to a Nam*/

//        strcat(dest,name->last);
//        char comma[] = ", ";
//        strcat(dest,comma);
//        strcat(dest, name->first);
        dest[strlen(dest)] = toupper((unsigned char)name->last[0]);
        for (int i = 1; name->last[i] !='\0' ; ++i) {
//                strcat(dest, (char[]){tolower((unsigned char)name->last[i])});
            dest[strlen(dest)] = tolower((unsigned char )name->last[i]);
        }
        char comma[] = ", ";
        strcat(dest,comma);

        dest[strlen(dest)]=toupper((unsigned char)name->first[0]);
//            strcat(dest, (char[]){toupper((unsigned char)name->first[0])});
        for (int i = 1; name->first[i] !='\0' ; ++i) {
            dest[strlen(dest)] = tolower((unsigned )name->first[i]);
//                strcat(dest, (char[]){tolower((unsigned char)name->first[i])});
        }

    }else if (format =='R'|| format=='r') {
//        strcat(dest,name->first);
//        strcat(dest,name->last);

        dest[0]=toupper((unsigned char)name->first[0]);
//            strcat(dest, (char[]){toupper((unsigned char)name->first[0])});
        for (int i = 1; name->first[i] !='\0' ; ++i) {
            dest[i] = tolower((unsigned )name->first[i]);
//                strcat(dest, (char[]){tolower((unsigned char)name->first[i])});
        }
        char space[] = " ";

        strcat(dest,space);

        dest[strlen(dest)] = toupper((unsigned char)name->last[0]);
        for (int i = 1; name->last[i] !='\0' ; ++i) {
//                strcat(dest, (char[]){tolower((unsigned char)name->last[i])});
            dest[strlen(dest)] = tolower((unsigned char )name->last[i]);
        }


    }else if (format == 'M'|| format=='m'){
        if (name->middle!=NULL){
//            strcat(dest,name->first);
            dest[0]=toupper((unsigned char)name->first[0]);
//            strcat(dest, (char[]){toupper((unsigned char)name->first[0])});
            for (int i = 1; name->first[i] !='\0' ; ++i) {
                dest[i] = tolower((unsigned )name->first[i]);
//                strcat(dest, (char[]){tolower((unsigned char)name->first[i])});
            }

            char space[]=" ";
            strcat(dest, space);


//            strncat(dest,name->middle,1);

            dest[strlen(dest)] = toupper((unsigned char)name->middle[0]);

            char comma[100]=". \0";
            strcat(dest, comma);

//            strcat(dest, name->last);

            dest[strlen(dest)] = toupper((unsigned char)name->last[0]);
            for (int i = 1; name->last[i] !='\0' ; ++i) {
//                strcat(dest, (char[]){tolower((unsigned char)name->last[i])});
                dest[strlen(dest)] = tolower((unsigned char )name->last[i]);
            }

        } else{
//            strcat(dest,name->first);
            dest[0]=toupper((unsigned char)name->first[0]);
//            strcat(dest, (char[]){toupper((unsigned char)name->first[0])});
            for (int i = 1; name->first[i] !='\0' ; ++i) {
                dest[i] = tolower((unsigned )name->first[i]);
//                strcat(dest, (char[]){tolower((unsigned char)name->first[i])});
            }

//            strcat(dest,name->last);
            dest[strlen(dest)] = toupper((unsigned char)name->last[0]);
            for (int i = 1; name->last[i] !='\0' ; ++i) {
//                strcat(dest, (char[]){tolower((unsigned char)name->last[i])});
                dest[strlen(dest)] = tolower((unsigned char )name->last[i]);
            }
        }
    }else if(format == 'S'|| format=='s'){
        strcat(dest,name->first);
    }
}

/*
int main(){
    Name n2;
    n2.first = "BeN";
    n2.middle = "ivan";
    n2.last = "bitDiDdle";
    n2.age = 32;
    char arr[1000];
    arr[0]='\0';
    FillName(&n2,'m',arr);
    printf("%s",arr);
}
*/



