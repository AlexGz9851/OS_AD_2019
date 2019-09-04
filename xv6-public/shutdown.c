#include "types.h"
#include "stat.h"
#include "user.h"

int main(){
    // requerimos una funcion que compile a una interrupcion, para ejecutar el kernel
    // y el kernel apague.
    shutdown();
    exit();

}