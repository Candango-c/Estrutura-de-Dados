#ifndef COUNTRY
#define COUNTRY

typedef struct Country Country;

Country *create_country(char *name, int gold, int silver, int bronze);

Country *update_medals(Country *c, int gold, int silver, int bronze);

int total_medals(Country *c);

char *name_country(Country *c);

int gold_country(Country *c);

int silver_country(Country *c);

int bronze_country(Country *c);

void free_country(Country *c);

void print_country(Country *c, FILE *arq);

#endif