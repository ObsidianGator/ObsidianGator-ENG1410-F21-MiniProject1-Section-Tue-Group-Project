#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void encrypt(char argv[]){
    FILE *fp_in;
    FILE *fp_out;
    _Bool file_end = 0;
    char read[255];
    char write[511];
    
    fp_in = fopen(argv, "r");
    fp_out = fopen("lad.crp", "w");
    while(file_end==0){
        fgets(read, 255, (FILE*)fp_in);
        for(int j=0, i = 0; j<=255; j++){
            if(read[j]==0){
                file_end = 1;
                break; 
            }
            else if(read[j]==13||read[j]=='\n'){
                write[i] = read[j];
                i++;
                break;
            }
            read[j]-=16;
            if(read[j]<=32){
                read[j] = (read[j] - 32) + 128;
            }
            write[i] = (read[j]/16)+48;
            if(write[i]>=58&&write[i]<=64){
                write[i]+=7;
            }
            i++;
            write[i] = (read[j])%16+48;
            if(write[i]>=58&&write[i]<=64){
                write[i]+=7;
            }
            i++;
        }
        fputs(write, fp_out);
    }
}

void decrypt(char argv[]){
    
}

int main(int argc, char* argv[]) {
    
    if(strcmp(argv[1], "-E")==0||argc == 2){
        encrypt(argv[2]);
    }
    else if(strcmp(argv[1], "-D")==0){
        decrypt(argv[2]);
    }
    return 0;
}
