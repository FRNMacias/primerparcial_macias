#include "network.h"
/**
 * @brief Cantidad de bits de un archivo
 * 
 * @param f manipulador del archiv
 * @return int cant de bits
 */
int bits(FILE *f){
    fseek(f,0,SEEK_END);
    int b = ftell(f);
    rewind(f);
    return b;
}

void showIDs(FILE *f){
    int i=0;
    int b;
    b = bits(f);
    printf("\n -------   IDs   -------\n");
    uint64_t header,aux,aux1;
    uint32_t ID, lower;
    uint16_t x;
    while(i<b){
        fread(&header,sizeof(uint64_t),1,f);
        aux = header >> 48;
        ID = aux;
        aux = header << 16;
        aux1 = aux >> 48;
        lower = aux1;
        printf("\nID: %u",ID);
        for(int j=0; j<lower;j++){
            fread(&x,sizeof(uint16_t),1,f);
            printf("\nID%d: %u",j,x);
        }
        i=ftell(f);
    }
    
}

int countDevices(FILE *f){
    int i=0,b,sum=0;
    b = bits(f);
    uint64_t header,aux,aux1;
    uint32_t ID, lower;
    uint16_t x;
    while(i<b){
        fread(&header,sizeof(uint64_t),1,f);
        aux = header >> 48;
        ID = aux;
        aux = header << 16;
        aux1 = aux >> 48;
        lower = aux1;
        for(int j=0; j<lower;j++){
            fread(&x,sizeof(uint16_t),1,f);
        }
        sum++;
        i=ftell(f);
    }
    return sum;
}

struct red* resize(struct red *v, int vec_size){
    int new_size = vec_size +1;
    struct red *aux; 
    aux = new struct red[new_size];
    for(int i=0; i<vec_size; i++){
        aux[i] = v[i];
    }
    delete []v;
    return aux;
}

void llenado(FILE *f,struct red *v){
    int i=0,b,j=0;
    b = bits(f);
    uint64_t header,aux;
    uint32_t h1, h2, aux1,info;
    while(i<b){
        v = resize(v,j);
        int pos = j;
        fread(&header,sizeof(uint64_t),1,f);
        aux = header << 32;
        h1 = aux >> 32;
        aux = header >> 32;
        h2 = aux;

        aux = h2 >> 16;
        v[pos].ID = aux;
        aux1 = h1 >> 24;
        v[pos].type = aux1 & 0x03;
        aux = h2 << 16;
        v[pos].lower = aux >> 16;
        v[pos].upper = new uint16_t[v[pos].lower];
        for(int k=0; k<(v[pos].lower);k++){
            fread(&v[pos].upper[k],sizeof(uint16_t),1,f);
        }
        aux1 = h1 << 8;
        info = aux >> 24;
        if(v[pos].type == 1){ // sensor
            v[pos].inf = info & 0x30;
        }
        if(v[pos].type == 2){//actuador
            v[pos].inf = info & 0xA0;
        }
        i=ftell(f);
        j++;
    }
}