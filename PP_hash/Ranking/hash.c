#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

struct Hash{

    int n;
    int dim; //dimensao da tabela

    Country **countries;

};

Hash *create_hash(){

    Hash *tab = (Hash*) malloc(sizeof(Hash));
    tab->n = 0;
    tab->dim = 7;
    tab->countries = (Country**)malloc(tab->dim * sizeof(Country*));
    for(int i=0; i <tab->dim; i++){
        tab->countries[i] = NULL;
    }

    return tab;

}

static int hash(Hash *tab, char *name){

    int id = 0;

    for (int i = 0; name[i] != '\0'; i++) {
        id += name[i];
    }

    return (id % tab->dim);

}

static void resize(Hash *tab){

    int max_past = tab ->dim;
    Country **past = tab->countries;
    tab->n =0;
    tab->dim *= 1.947;
    tab->countries =(Country**)malloc(tab->dim * sizeof(Country*));

    for(int i=0; i < tab->dim; i++){

        tab->countries[i] = NULL;

    }

    for(int i=0; i < max_past; i++){

        if(past[i] !=NULL){
            insert_country_hash(tab, past[i]);
        }

    }

    free(past);

}

Country *hash_busca(Hash *tab, Country *c){

    int h = hash(tab, name_country(c));

    while(tab->countries[h] != NULL){

        if (strcmp(name_country(tab->countries[h]), name_country(c)) == 0) {
            return tab->countries[h]; // pais encontrado
        }
        h = (h + 1) % tab->dim;
    }

    return NULL;

}

Hash *insert_country_hash(Hash *tab, Country *c){

    if(hash_busca(tab, c)==NULL){

        if(tab->n > 0.75 * tab->dim){
            resize(tab);
        }

        int h = hash(tab, name_country(c));

        while(tab->countries[h] != NULL){
            h = (h+1) % tab->dim;
        }
        tab->countries[h] = c;

        tab->n++;

        return tab;
    } else {

        update_medals(hash_busca(tab, c), gold_country(c), silver_country(c), bronze_country(c));

        free_country(c);

        return tab;
    }

}


void print_hash(Hash *tab, FILE *arq){

    for(int i=0; i <tab->dim; i++){

        if(tab->countries[i] != NULL){
            print_country(tab->countries[i], arq);
        }

    }

}

void free_hash(Hash *tab){

    if(tab==NULL){

        return;
    }

    for(int i=0; i <tab->dim; i++){

        if(tab->countries[i] != NULL){

            free_country(tab->countries[i]);

        }

    }
    free(tab->countries);
    free(tab);
}