#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

extern int Z[64], N[64];

void init();
int* o2B(char*);
char* B2o(int*);
void loop(int*);
int* key(char*);
int* Extend(int*);
int* Sboxcompress(int*);
char* DES(int*, char*, bool);

#endif // HEADER_H_INCLUDED
