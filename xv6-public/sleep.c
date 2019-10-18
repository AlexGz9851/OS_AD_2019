#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
  if(argc < 2){
    printf(2, "usage: sleep N seconds...\n");
    exit();
}
  int time = atoi(argv[1]);
  if (time > 0){
        printf(2, "sleeping %d seconds...\n", time);
		sleep(time*100);
	} else {
		printf(2, "El argumento del comando sleep debe ser positivo %s\n", argv[1]);
	}
  exit();
}