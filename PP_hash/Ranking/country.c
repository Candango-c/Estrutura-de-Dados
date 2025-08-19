#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "country.h"

struct Country{

    char *name;

    int gold;
    int silver;
    int bronze;
    int total;

};

Country *create_country(char *name, int gold, int silver, int bronze){

    Country *c = (Country*)malloc(sizeof(Country));
    c->name = strdup(name);
    c->gold = gold;
    c->silver = silver;
    c->bronze = bronze;
    c->total = gold + silver + bronze;

    return c;

}

Country *update_medals(Country *c, int gold, int silver, int bronze){

    c->gold = gold;
    c->silver = silver;
    c->bronze = bronze;
    c->total = gold + silver + bronze;

    return c;

}

int gold_country(Country *c){

    return c->gold;
}

int silver_country(Country *c){

    return c->silver;
}

int bronze_country(Country *c){

    return c->bronze;
}

int total_medals(Country *c){

    return c->total;
}

char *name_country(Country *c){

    return c->name;
}

void free_country(Country *c){

    if(!(c==NULL)){

        free(c->name);
        free(c);

    }

}

void print_country(Country *c, FILE *arq){

    if(!(c==NULL)){

        fprintf(arq, "%s %d %d %d %d\n", c->name, c->gold, c->silver, c->bronze, c->total);

    }

}