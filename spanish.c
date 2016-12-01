#include<string.h>
#include <stdio.h>
#include<stdlib.h>

void searchHash(char hasht[10000][1000]);
int hash(char* key, int M);
int probes = 0;
int counter = 0;
int main() {
    int i = 0, M = 10000,value;
    char buffer[1000];
    char* english;
    char* spanish;
    char* del = "	"; 
    char hasht[M][1000];
    char eng[1000];
    char span[1000];
    int arr[101];
    int search = 0;
    int temp;
    FILE* file = fopen("Spanish.txt","r");

//Initialize hash table as empty
    for(i = 0; i < M; i++)
    {   if(i < 100)
          arr[i] = 0;
        strcpy(hasht[i],"Empty");
    }
//tokenize the english and spanish words until file is done. (delimited by tab)
//ignore '#'
    while(fgets(buffer,sizeof(buffer),file) != NULL)
    {
        if(buffer[0] != '#')
        {
            english = strtok(buffer,del);
            spanish = strtok(NULL,"\n");
            strcpy(span,spanish);
            strcpy(eng,english);

            value = hash(english,M);
            search = 0;
            if(strcmp(hasht[value],"Empty") == 0){
                search++;
            }
            else{
                while(strcmp(hasht[value],"Empty") != 0){        
                     value++;
                     if(value >= M)
                        value = 0;
                     search++;
                }
                
            }
            strcat(eng,"~");
            strcat(eng,span);
            strcpy(hasht[value],eng);
              
            printf("%s\n",hasht[value]);
            temp = arr[search];
            temp++;
            arr[search] = temp;
            counter++;
        }
    }

    for(i = 0; i <= 100; i++)
       printf("%4d| %4d\n----------\n",i,arr[i]);


   /* while(strcmp(word,"-1") != 0){
       scanf("%s",word);       
       value = hash(word,M);
       if(strcmp(word,"-1") != 0)
           printf("%s\t%s\n",word,hasht[value]);
       
    }*/
   searchHash(hasht);
    return 0;
}

int hash(char* key, int M){
    int h = 0, a = 127;
    for (; *key != '\0'; key++)
        h = (a*h + *key) % M;
    return h;
}

void searchHash(char hasht[10000][1000]){
    int value,i, M = 10000,temp,probes;
    char word[100];
    char buffer[1000];
    char* token;
    char* span;
    while(strcmp(word,"-1") != 0){
       scanf("%s",word);
      
       value = hash(word,M);
       strcpy(buffer, hasht[value]);
       token = strtok(buffer,"~");
       //printf("TEST token = %s, word = %s\n",token,word);

       probes = 1;
       if(strcmp(word,"-1") == 0)
          return; 
       else if(strcmp(token,"Empty") == 0)
          printf("%s\t--NOT FOUND\n",word); 
       else if(strcmp(token,word) != 0){
            temp = value;
            i = 0;
            while(strcmp(token,word) != 0)
            {   
                probes ++;
                temp++;
                  
                strcpy(buffer, hasht[temp]);
                token = strtok(buffer,"~");                

                if(temp >= M)
                    temp = 0;
               // printf("%d%s\n",temp,hasht[temp]);
                 
            }
       }

       if(strcmp(token,word) == 0)
       {
            span = strtok(NULL,"\n");
            printf("%s\t%s\n",word,span);
       }
       printf("\t%d probes (in table)\n",probes);
    }
    return;
}
