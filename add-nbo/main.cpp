
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <string>
#include <netinet/in.h>

int main(int argc, char* argv[]){
    int num1 = 0;
    int num2 = 0;

    FILE *fp1 = fopen(argv[1], "rb");
    if(fp1 == NULL){
        printf("There is no file.\n");
        return 0;
    }
    else{
        fread(&num1, sizeof(int), 1, fp1);
        num1 = ntohl(num1);
        fclose(fp1);
    }

    FILE *fp2 = fopen(argv[2], "rb");
    if(fp2 == NULL){
        printf("There is no file.\n");
        return 0;
    }
    else{
        fread(&num2, sizeof(int), 1, fp2);
        num2 = ntohl(num2);
        fclose(fp2);
    }

    int result = num1 + num2;

    printf("%d(%#x) + %d(%#x) = %d(%#x)", num1, num1, num2, num2, result, result);
}
