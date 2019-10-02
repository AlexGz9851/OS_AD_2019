#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>

int noEsCero=3;
void  signalHandler(int signalNumber){
    noEsCero=0;
    printf("Signal recieved %d\n", signalNumber);
}

int main(){
    int pid;
    signal(10 ,signalHandler);
    pid = fork();
    if(pid==0){
        printf("Yo soy el hijo\n");
        while(noEsCero){
            printf("dentro del infinito\n");
            sleep(1);
        };
        printf("Ya sali\n");
    } else{
        printf("Yo soy el padre\n");
        sleep(1);
        kill(pid,10);
        for(;;);
    }
}