#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* leLinha(){

    char temp[100];

    scanf(" %99[^\n]", temp);

    char* str = strdup(temp);

    return str;

}