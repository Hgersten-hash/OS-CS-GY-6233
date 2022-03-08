#include "types.h"
#include "stat.h"
#include "user.h"



char buf[512];

void uniq(int fd, char *uniq){
    int sizeCurr =1;
    char *curr = malloc(sizeCurr);
    char *prev = malloc(sizeCurr);

    int i,n, pos=0;
    while((n = read(fd, buf, sizeof(buf))) > 0){
        for(i =0; i<n; i+=1){
            if(buf[i]!='\n'){
                curr[pos] = buf[i];
                pos+=1;
                if(pos == sizeCurr){
                    char* newSizeCurr = malloc(2*sizeCurr);
                    
                    for(int t=0; t< sizeCurr; t+=1){
                        newSizeCurr[t] = curr[t];
                        }
                    free(curr);
                    curr = newSizeCurr;
                    char* newSizePrev = malloc(2*sizeCurr);
                    sizeCurr *=2;
                    for(int t=0; t< sizeCurr; t+=1){
                        newSizePrev[t] = prev[t];
                        }
                    free(prev);
                    prev = newSizePrev;
                }
            }
            else if(buf[i]=='\n'){
                curr[pos] = '\0';
                if(strcmp(prev, curr)){
                    printf(1,"%s\n", curr);
                    strcpy(prev, curr);
                    pos =0;
                }
                else{
                    pos=0;
                }
            }
        }
    }
    free(prev);
    free(curr);
}

void uniqc(int fd, char *uniq){
    int sizeCurr =1;
    char *curr=malloc(sizeCurr);
    char *prev = malloc(sizeCurr);

    int i,n, pos=0, countCur =1, lineCount =0;
    while((n = read(fd, buf, sizeof(buf))) > 0){
        for(i =0; i<n; i+=1){
            if(buf[i]!='\n'){
                curr[pos] = buf[i];
                pos+=1;
                if(pos == sizeCurr){
                    char* newSizeCurr = malloc(2*sizeCurr);
                    
                    for(int t=0; t< sizeCurr; t+=1){
                        newSizeCurr[t] = curr[t];
                        }
                    free(curr);
                    curr = newSizeCurr;
                    char* newSizePrev = malloc(2*sizeCurr);
                    sizeCurr *=2;
                    for(int t=0; t< sizeCurr; t+=1){
                        newSizePrev[t] = prev[t];
                        }
                    free(prev);
                    prev = newSizePrev;
                }
            }
            else if(buf[i]=='\n'){
                lineCount +=1;
                curr[pos] = '\0';
                if(lineCount==1){
                    strcpy(prev, curr);
                    pos =0;
                    countCur = 1;
                }
                else if(strcmp(prev, curr)){
                    printf(1, "%d %s\n", countCur, prev);
                    strcpy(prev, curr);
                    pos =0;
                    countCur = 1;
                }
                else{
                    pos=0;
                    countCur +=1;
                }
            }
        }
    }
    printf(1, "%d %s\n", countCur, prev);
    free(prev);
    free(curr);
}

void uniqd(int fd, char *uniq){
    int sizeCurr =1;
    char *curr=malloc(sizeCurr);
    char *prev = malloc(sizeCurr);

    
    int i,n, pos=0, lineCount =0, countCur =0;
    while((n = read(fd, buf, sizeof(buf))) > 0){
        for(i =0; i<n; i+=1){
            if(buf[i]!='\n'){
                curr[pos] = buf[i];
                pos+=1;
                if(pos == sizeCurr){
                    char* newSizeCurr = malloc(2*sizeCurr);
                    
                    for(int t=0; t< sizeCurr; t+=1){
                        newSizeCurr[t] = curr[t];
                        }
                    free(curr);
                    curr = newSizeCurr;
                    char* newSizePrev = malloc(2*sizeCurr);
                    sizeCurr *=2;
                    for(int t=0; t< sizeCurr; t+=1){
                        newSizePrev[t] = prev[t];
                        }
                    free(prev);
                    prev = newSizePrev;
                }
            }
            else if(buf[i]=='\n'){
                lineCount +=1;
                curr[pos] = '\0';
                if(lineCount==1){
                    strcpy(prev, curr);
                    pos =0;
                    countCur = 1;
                }
                else if(strcmp(prev, curr)){
                    strcpy(prev, curr);
                    pos =0;
                    countCur = 1;
                }
                else{
                    if(countCur==1){
                        printf(1, "%s\n", prev);
                    }
                    pos=0;
                    countCur +=1;
                }
            }
        }
    }
    free(prev);
    free(curr);
}
void uniqi(int fd, char *uniq){
    int sizeCurr =1;
    char *curr=malloc(sizeCurr);
    char *prev = malloc(sizeCurr);

    int i,n, pos=0;

    while((n = read(fd, buf, sizeof(buf))) > 0){
        for(i =0; i<n; i+=1){
            if(buf[i]!='\n'){
                curr[pos] = buf[i];
                pos+=1;
                if(pos == sizeCurr){
                    char* newSizeCurr = malloc(2*sizeCurr);
                    
                    for(int t=0; t< sizeCurr; t+=1){
                        newSizeCurr[t] = curr[t];
                        }
                    free(curr);
                    curr = newSizeCurr;
                    char* newSizePrev = malloc(2*sizeCurr);
                    sizeCurr *=2;
                    for(int t=0; t< sizeCurr; t+=1){
                        newSizePrev[t] = prev[t];
                        }
                    free(prev);
                    prev = newSizePrev;
                }
            }
            else if(buf[i]=='\n'){
                curr[pos] = '\0';
                int isSame =1;
                if(strlen(curr)!= strlen(prev)){
                    isSame =0;
                }
                else{
                    int h=0;
                    while(h < strlen(prev)){
                        if((prev[h]>='A' && prev[h]<='Z') && (curr[h]>='a' && curr[h]<='z')){
                            if(prev[h]+32 != curr[h]){
                                isSame = 0;
                                break;
                            }
                        }
                        else if((prev[h]>='a' && prev[h]<='z') && (curr[h]>='A' && curr[h]<='Z')){
                            if(prev[h]-32 != curr[h]){
                                isSame = 0;
                                break;
                            }
                        }
                        else{
                            if(prev[h]!= curr[h]){
                                isSame = 0;
                                break;
                            }
                        }
                        h+=1;
                    }
                }
                
                if(!isSame){
                    printf(1,"%s\n", curr);
                    strcpy(prev, curr);
                    pos =0;
                }
                else{
                    pos=0;
                }
            }
        }
    }
    free(prev);
    free(curr);
}
void uniqic(int fd, char* uniq){
    int sizeCurr =1;
    char *curr=malloc(sizeCurr);
    char *prev = malloc(sizeCurr);

    int i,n, pos=0, countCur =0, lineCount=0;

    while((n = read(fd, buf, sizeof(buf))) > 0){
        for(i =0; i<n; i+=1){
            if(buf[i]!='\n'){
                curr[pos] = buf[i];
                pos+=1;
                if(pos == sizeCurr){
                    char* newSizeCurr = malloc(2*sizeCurr);
                    
                    for(int t=0; t< sizeCurr; t+=1){
                        newSizeCurr[t] = curr[t];
                        }
                    free(curr);
                    curr = newSizeCurr;
                    char* newSizePrev = malloc(2*sizeCurr);
                    sizeCurr *=2;
                    for(int t=0; t< sizeCurr; t+=1){
                        newSizePrev[t] = prev[t];
                        }
                    free(prev);
                    prev = newSizePrev;
                }
            }
            else if(buf[i]=='\n'){
                curr[pos] = '\0';
                lineCount +=1;
                int isSame =1;
                if(lineCount==1){
                    strcpy(prev, curr);
                }
                if(strlen(curr)!= strlen(prev)){
                    isSame =0;
                }
                else{
                    int h=0;
                    while(h < strlen(prev)){
                        if((prev[h]>='A' && prev[h]<='Z') && (curr[h]>='a' && curr[h]<='z')){
                            if(prev[h]+32 != curr[h]){
                                isSame = 0;
                                break;
                            }
                        }
                        else if((prev[h]>='a' && prev[h]<='z') && (curr[h]>='A' && curr[h]<='Z')){
                            if(prev[h]-32 != curr[h]){
                                isSame = 0;
                                break;
                            }
                        }
                        else{
                            if(prev[h]!= curr[h]){
                                isSame = 0;
                                break;
                            }
                        }
                        h+=1;
                    }
                }
                
                if(!isSame){
                    printf(1,"%d %s\n", countCur, prev);
                    strcpy(prev, curr);
                    pos =0;
                    countCur =1;
                }
                else{
                    countCur +=1;
                    pos=0;
                }
            }
        }
    }
    printf(1, "%d %s\n", countCur, prev);
    free(prev);
    free(curr);
}

void uniqid(int fd, char* uniq){
    int sizeCurr =1;
    char *curr=malloc(sizeCurr);
    char *prev = malloc(sizeCurr);

    
    int i,n, pos=0, lineCount =0, countCur =0;
    while((n = read(fd, buf, sizeof(buf))) > 0){
        for(i =0; i<n; i+=1){
            if(buf[i]!='\n'){
                curr[pos] = buf[i];
                pos+=1;
                if(pos == sizeCurr){
                    char* newSizeCurr = malloc(2*sizeCurr);
                    
                    for(int t=0; t< sizeCurr; t+=1){
                        newSizeCurr[t] = curr[t];
                        }
                    free(curr);
                    curr = newSizeCurr;
                    char* newSizePrev = malloc(2*sizeCurr);
                    sizeCurr *=2;
                    for(int t=0; t< sizeCurr; t+=1){
                        newSizePrev[t] = prev[t];
                        }
                    free(prev);
                    prev = newSizePrev;
                }
            }
            else if(buf[i]=='\n'){
                lineCount +=1;
                curr[pos] = '\0';
                int isSame =1;
                if(lineCount==1){
                    strcpy(prev, curr);
                    pos =0; 
                    countCur=1;
                }
                 
                else{
                    if(strlen(curr)!= strlen(prev)){
                    isSame =0;
                    }
                    else{
                    int h=0;
                    while(h < strlen(prev)){
                        if((prev[h]>='A' && prev[h]<='Z') && (curr[h]>='a' && curr[h]<='z')){
                            if(prev[h]+32 != curr[h]){
                                isSame = 0;
                                break;
                            }
                        }
                        else if((prev[h]>='a' && prev[h]<='z') && (curr[h]>='A' && curr[h]<='Z')){
                            if(prev[h]-32 != curr[h]){
                                isSame = 0;
                                break;
                            }
                        }
                        else{
                            if(prev[h]!= curr[h]){
                                isSame = 0;
                                break;
                            }
                        }
                        h+=1;
                    }
                    }
                if(!isSame){
                    strcpy(prev, curr);
                    pos =0;
                    countCur = 1;
                }
                else{
                    if(countCur==1){
                        printf(1, "%s\n", prev);
                    }
                    pos=0;
                    countCur +=1;
                }
                } 
            }
        }
    }
    free(prev);
    free(curr);
}


void uniqDriver(int fd, int argc, char* argv[], int isC, int isD, int isI){
    if(isC && isI){
        uniqic(fd, argv[argc-1]);
    }
    else if(isI && isD){
        uniqid(fd, argv[argc-1]);
    }
    else if(isC){
        uniqc(fd, argv[argc-1]);
    }
    else if(isD){
        uniqd(fd, argv[argc-1]);
    }
    else if(isI){
        uniqi(fd, argv[argc-1]);
    }
    else{
        uniq(fd, argv[argc-1]);
    }
}

int main(int argc, char* argv[]){
    int i=0;
    int fd;
    int isC=0, isD=0, isI=0;

    if (argc <= 1) {
        uniq(0, "");
        exit();
    }
    
    while(i<argc){
        if(!strcmp(argv[i], "-c")){
            isC=1;
        }
        else if(!strcmp(argv[i], "-d")){
            isD =1;
        }
        else if(!strcmp(argv[i], "-i")){
            isI =1;
        }
        i+=1;
    }
    if ((fd = open(argv[argc-1], 0)) < 0) {
        if(isC || isD || isI){
            uniqDriver(0, argc, argv, isC, isD, isI);
        }
        else{
            printf(1, "uniq: cannot open %s\n", argv[i]);
            exit();
        }
        }
    else{
        uniqDriver(fd, argc, argv, isC, isD, isI);
    }
    close(fd);
    exit();
}
