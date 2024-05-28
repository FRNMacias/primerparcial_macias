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
    cant = countDevices(f);  
    printf("\nCantidad de dispositivos en la red: %d",cant);
    int band,pos;
    uint32_t ID_user;
    printf("\nIngrese ID: ");
    scanf("%u",&ID_user);
    getRegister(ID_user,vec,cant);
    //printf("\nIngrese ID para ver secuencia: ");
    fclose(f);
    return 0;
}
