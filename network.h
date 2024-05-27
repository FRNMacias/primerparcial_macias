#pragma once
#include <stdio.h>
#include <stdint.h>
#include <cstdio>
#include <iostream>
struct red{
    uint32_t ID;
    uint32_t type;
    uint32_t inf;
    uint32_t lower;
    uint16_t *upper;
};
int bits(FILE *f);
void showIDs(FILE *f);
int countDevices(FILE *f);
void llenado(FILE *f,struct red *v);
struct red* resize(struct red *v, int vec_size);

