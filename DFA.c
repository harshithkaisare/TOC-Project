#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int dfa = 0;
void q0(char c){
    if(c == 'a')
        dfa = 1;
    else if(c == 'b')
        dfa = 0;
    else
        dfa = -1;
}
void q1(char c){
    if(c == 'a')
        dfa = 1;
    else if(c == 'b')
        dfa = 2;
    else
        dfa = -1;
}
void q2(char c){
    if(c == 'a')
        dfa = 3;
    else if(c == 'b')
        dfa = 0;
    else
        dfa = -1;
}
void q3(char c){
    if(c == 'a')
        dfa = 1;
    else if(c == 'b')
        dfa = 2;
    else
        dfa = -1;
}
int isAccepted(char str[]){  
    int i, len = strlen(str); 
    for (i = 0; i < len; i++){ 
        if (dfa == 0) 
            q0(str[i]); 
        else if (dfa == 1) 
            q1(str[i]); 
        else if (dfa == 2) 
            q2(str[i]); 
        else if (dfa == 3) 
            q3(str[i]); 
        else
            return 0; 
    } 
    if(dfa == 3) 
        return 1; 
    else
        return 0; 
}
int main(){ 
    char *str;
    int size, option;
    printf("Automata To Accept Strings Ending With aba\n\n");
    while(1){
        printf("1. Check New String\n2. Exit\n");
        printf("Enter Option\n");
        scanf("%d", &option);
        switch(option){
            case 1:{
                printf("\nEnter Size of String:\n");
                scanf("%d", &size);
                str = (char*)malloc(sizeof(char));
                printf("Enter String:\n");
                scanf("%s", str);
                if(isAccepted(str))
                    printf("ACCEPTED\n");
                else
                    printf("NOT ACCEPTED\n");
                free(str);
                break;
            }
            case 2:{
                exit(0);
            }
            default:{}
        }
    }
    return 0; 
} 