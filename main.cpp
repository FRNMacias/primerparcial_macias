//#pragma once
#include <stdio.h>
#include <stdint.h>
#include <cstdio>
int main(){
    FILE *f = fopen("network_structure.dat","rb");
    if(f == NULL){
        printf("\nNo es posible abrir el archivo de datos");
        return -1;
    }
    uint64_t header,aux;
    fread(&header,sizeof(uint64_t),1,f);
    uint32_t h1, h2, aux1;
    aux = header << 32;
    h1 = aux >> 32;
    aux = header >> 32;
    h2 = aux;
    uint32_t upper, info,type,lower,ID,sensor,actuador;
    aux1 = h1 << 16;
    upper = aux1 >> 16;
    aux1 = h1 >> 24;
    type = aux1 &0x03;

    aux1 = h1 << 8;
    info = h1 >> 24;
    actuador = info >> 7;
    aux1 = info << 2;
    sensor = aux1 >> 6; //sensor
     
    ID = h2 >> 16;
    aux1 = h2 << 16;
    lower = aux >> 16;

    printf("\nUpper: %u",upper);
    printf("\nType: %u",type);
    printf("\nActudor: %u",actuador);
    printf("\nSensor: %u",sensor);
    printf("\nID: %u",ID);
    printf("\nLower: %u",lower);

    fclose(f);
    return 0;
}