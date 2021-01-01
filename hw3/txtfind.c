#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE 256
#define WORD 30
#define MAXLINES 250
#define BUFFERSIZE LINE*WORD*MAXLINES

int getLine(char s[LINE]);
int getword(char w[WORD]);
int substring(char *str1, char *str2);
char* HeyWord(char *str);
char* HeyLine(char *str);
int checkMyWords(char *str, char* word);
void print_lines(char *str, char *word);
void print_similar_words(char * str, char *word);
void takeTeChoice(char *line, char *word, char *choice);
void tryingSomthing(char* str);
void print_similar_words2(char* str, char *word);



int main(){
    char *word;
    char* choice;
    char *line = NULL;
    size_t size;
    if (getline(&line, &size, stdin) == -1) {
        printf("no input\n");
        return 0;
    } else {
        while(*line == ' '||*line == '\t'|| *line == '\0'){
            line++;
        }

        word = HeyWord(line);
        line = line + getword(word);
        while(*line == ' '||*line == '\t'|| *line == '\0'){
            line++;
        }
        choice = HeyWord(line);
    }
    //***************************************************
    *line = NULL;
    if(*choice == 'b'){
        size_t size1;
        while (getline(&line, &size1, stdin) != -1) {
            print_similar_words2(line, word);
            char *line = NULL;
            size_t size1;
        }
    }//**************************************************
    else if(*choice =='a'){
        size_t size1;
        while (getline(&line, &size1, stdin) != -1) {
            print_lines(line, word);
            char *line = NULL;
            size_t size1;
        }
    } else{
        printf("not cool//");
    }
    return 0;
}

int getLine(char s[LINE])
{
    char *ptr = &s[0];
    int count = 0;
    while (*ptr != '\n')
    {
        count = count + 1;
        ptr = ptr + 1;
    }
    return count;
}
int getword(char w[WORD])
{
    int count = 0;
    char *ptr = &w[0];
    while(*ptr != ' '&& *ptr != '\n' && *ptr != '\t' &&  *ptr != '\0')
    {
        count = count + 1;
        ptr = ptr + 1;
    }
    return count;
}
//return 1 if str2 is in str1, else return 0
int substring(char *str1, char *str2)
{
    while (*str1 != ' ' && *str1 != '\t' && *str1 != '\n' && *str1 != '\0')
    {
        if (*str2 == ' ' || *str2 == '\t' || *str2 == '\n' || *str2 == '\0')
        {
            return 1;
        }
        if (*str1 == *str2)
        {
            str2 = str2 + 1;
        }
        str1 = str1 + 1;
    }
    //edge case
    if (*str2 == ' ' || *str2 == '\t' || *str2 == '\n' || *str2 == '\0'||*str2 == "")
    {
        return 1;
    }
    return 0;
}
char* HeyWord(char *str){
    char word [WORD] = {0};
    int index = 0;
    while(*str != '\n' && *str != '\t' && *str != ' ' && *str != '\0')
    {
        word[index] = *str;
        str = str + 1;
        index = index + 1;
    }
    int a = getword(word);
    char *str2 = malloc(a+1);
    for (int j = 0; j < a; j++)
    {
        str2[j] = word[j];
    }
    str2[a] = '\0';
    return str2;
}
//mabye should add one more statment
char* HeyLine(char *str){
    char line [LINE]  = {0};
    int index = 0;
    while(*str != '\n'){
        line[index] = *str;
        str = str + 1;
        index = index + 1;
    }
    line[index] = '\n';
    int a = getLine(line);
    char *str2 = malloc(a+1);
    for (int i = 0; i < a; i++)
    {
        str2[i] = line[i];
    }
    str2[a] = '\n';
    return str2;
}
int checkMyWords(char *str, char *word){
    int index = 0;
    while ( *str != '\n'&&index<LINE+1)
    {
        if(*str == '\t' || *str == ' ' || *str == '\0'){
            str = str + 1;
        }else{
            char* wordInStr = HeyWord(str);
            if(substring(wordInStr, word )> 0){
                return 1;
            }
            str = str + strlen(wordInStr);
            index = index + getword(wordInStr) - 1;
        }
        index++;
    }
    return 0;
}
//option a
void print_lines(char *str, char *word) {
    char *s = HeyLine(str);
    if (checkMyWords(str, word) > 0) {
        for (int i = 0; i < strlen(s); i++) {
            printf("%c", *str);
            str = str + 1;
        }
    } else {
        str = str + strlen(s);
    }
}

void print_similar_words2(char* str, char *word){

    int index = 0;
    while ( *str != '\n'&&index<LINE+1)
    {
        if(*str == '\t' || *str == ' ' || *str == '\0'){
            str = str + 1;
        }else{
            char* wordInStr = HeyWord(str);
            if(substring(wordInStr, word )> 0){
                printf("%s\n", wordInStr);
            }
            str = str + strlen(wordInStr);
            index = index + getword(wordInStr) - 1;
        }
        index++;
    }
}
