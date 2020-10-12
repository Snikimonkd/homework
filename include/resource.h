#ifndef INCLUDE_RESOURCE_H_
#define INCLUDE_RESOURCE_H_

#include <stddef.h>
#include <stdio.h>

typedef struct resource {
    char *chiper;
    char *name;
    char *units;
    char *materials;
    char *amount;
} resource;

resource *create_resource(FILE *istream);
void free_resource(resource *resource);

char *read_from_stream(FILE *istream);

int printf_resource(const resource *resource, FILE *ostream);

int copy_resource(resource *new_resource, const resource *old_resource);

int dynamic_strcpy(char **dst, char *const *src);

#endif  //  INCLUDE_RESOURCE_H_
