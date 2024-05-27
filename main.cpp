#include "network.h"

int main(){
    FILE *f = fopen("network_structure.dat","rb");
    if(f == NULL){
        printf("\nNo es posible abrir el archivo de datos");
        return -1;
    }
    showIDs(f);
    struct red *vec;
    llenado(f,vec);  
    int cant;
    cant = countDevices(f); //devuelve cantidad de dispositivos en la red,es igual al tamaño del vector struct red. 
    
    fclose(f);
    return 0;
}
