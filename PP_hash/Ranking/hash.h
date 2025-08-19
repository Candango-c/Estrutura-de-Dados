#ifndef HASH
#define HASH


#include "country.h"


typedef struct Hash Hash;

Hash *create_hash();

Hash *insert_country_hash(Hash *tab, Country *c);

void print_hash(Hash *tab, FILE *arq);

void free_hash(Hash *tab);

#endif