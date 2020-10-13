#include "resource.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_from_stream(FILE *istream) {
    char *line = NULL;
    if (fscanf(istream, "%ms", &line) == -1) {
        return NULL;
    }

    return line;
}

resource *create_resource(FILE *istream) {
    resource *new_resource = malloc(sizeof(resource));
    if (new_resource == NULL) {
        free(new_resource);
        return NULL;
    }

    new_resource->chiper = NULL;
    new_resource->name = NULL;
    new_resource->amount = NULL;
    new_resource->units = NULL;
    new_resource->materials = NULL;

    if ((new_resource->chiper = read_from_stream(istream)) == NULL) {
        free_resource(new_resource);
        free(new_resource);
        return NULL;
    }

    if ((new_resource->name = read_from_stream(istream)) == NULL) {
        free_resource(new_resource);
        free(new_resource);
        return NULL;
    }

    if ((new_resource->amount = read_from_stream(istream)) == NULL) {
        free_resource(new_resource);
        free(new_resource);
        return NULL;
    }

    if ((new_resource->units = read_from_stream(istream)) == NULL) {
        free_resource(new_resource);
        free(new_resource);
        return NULL;
    }

    if ((new_resource->materials = read_from_stream(istream)) == NULL) {
        free_resource(new_resource);
        free(new_resource);
        return NULL;
    }

    return new_resource;
}

int copy_resource(resource *new_resource, const resource *old_resource) {
    if (old_resource == NULL) {
        return -1;
    }
    if (new_resource == NULL) {
        return -1;
    }
    new_resource->chiper = NULL;
    new_resource->name = NULL;
    new_resource->amount = NULL;
    new_resource->materials = NULL;
    new_resource->units = NULL;

    if (dynamic_strcpy(&new_resource->chiper, &old_resource->chiper) == -1) {
        return -1;
    }

    if (dynamic_strcpy(&new_resource->amount, &old_resource->amount) == -1) {
        free_resource(new_resource);
        return -1;
    }

    if (dynamic_strcpy(&new_resource->name, &old_resource->name) == -1) {
        free_resource(new_resource);
        return -1;
    }

    if (dynamic_strcpy(&new_resource->units, &old_resource->units) == -1) {
        free_resource(new_resource);
        return -1;
    }

    if (dynamic_strcpy(&new_resource->materials, &old_resource->materials) ==
        -1) {
        free_resource(new_resource);
        return -1;
    }

    return 0;
}

int printf_resource(const resource *resource, FILE *ostream) {
    puts("-------------");
    return fprintf(
        ostream, "Chiper: %s\nName: %s\nAmount: %s\nUnits: %s\nMaterials: %s\n",
        resource->chiper, resource->name, resource->amount, resource->units,
        resource->materials);
}

void free_resource(resource *resource) {
    free(resource->chiper);
    free(resource->name);
    free(resource->units);
    free(resource->materials);
    free(resource->amount);
}

int dynamic_strcpy(char **dst, char *const *src) {
    if (*src == NULL) {
        return -1;
    }
    *dst = malloc((strlen(*src) + 1) * sizeof(char));
    if (*dst == NULL) {
        return -1;
    }
    memcpy(*dst, *src, ((strlen(*src) + 1) * sizeof(char)));
    if (dst == NULL) {
        return -1;
    }
    return 0;
}
