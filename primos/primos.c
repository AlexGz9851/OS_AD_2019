#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main(){
    char curr=0;
    int prime = 0;
    int primeObtained = 0;
    int currNum = 0;
    while(-1 != (curr = getchar())){
        if(curr != ' '){
            if(!primeObtained){
                prime = prime * 10 + (curr - '0');
            }
            else{
                currNum = currNum * 10 + (curr - '0');
            }
        }
        else {
            if(!primeObtained){
                primeObtained = 1;
                fprintf(stderr, "%d, ", prime);
            }
            else {
                if(currNum % prime != 0){
                    printf("%d ", currNum);
                }
                currNum = 0;
            }
        }
    };
    return 0;
}