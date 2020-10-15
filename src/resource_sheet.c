#include "resource_sheet.h"
#include "resource.h"
#include <stdlib.h>
#include <string.h>

resource_sheet *create_resource_sheet(FILE *istream) {
    size_t i;
    if (fscanf(istream, "%zu\n", &i) == -1) {
        return NULL;
    }

    resource_sheet *new_resource_sheet =
        (resource_sheet *)malloc(sizeof(resource_sheet));
    if (new_resource_sheet == NULL) {
        return NULL;
    }

    new_resource_sheet->resources_array =
        (resource *)malloc(i * sizeof(resource));
    if (new_resource_sheet->resources_array == NULL) {
        free(new_resource_sheet);
        return NULL;
    }

    size_t j = 0;

    while (j < i) {
        resource *new_resource = create_resource(istream);
        if (new_resource == NULL) {
            free(new_resource_sheet->resources_array);
            free(new_resource_sheet);
            return NULL;
        }

        if (copy_resource(new_resource_sheet->resources_array + j,
                          new_resource) == -1) {
            free_resource_sheet(new_resource_sheet);
            free_resource(new_resource);
            free(new_resource);
            return NULL;
        }
        free_resource(new_resource);
        free(new_resource);
        ++j;
    }
    new_resource_sheet->quantity = i;
    return new_resource_sheet;
}

void free_resource_sheet(resource_sheet *resource_sheet) {
    for (size_t i = 0; i < resource_sheet->quantity; i++) {
        free_resource(resource_sheet->resources_array + i);
    }
    free(resource_sheet->resources_array);
    free(resource_sheet);
}

resource_sheet *
resource_sheet_sort(resource_sheet *const unsorted_resource_sheet,
                    FILE *istream) {
    char *criterion = read_from_stream(istream);
    if (criterion == NULL) {
        return NULL;
    }

    resource_sheet *new_resource_sheet =
        (resource_sheet *)malloc(sizeof(resource_sheet));
    if (new_resource_sheet == NULL) {
        free(criterion);
        return NULL;
    }

    new_resource_sheet->resources_array = (resource *)malloc(
        unsorted_resource_sheet->quantity * sizeof(resource));
    if (new_resource_sheet->resources_array == NULL) {
        free(criterion);
        free(new_resource_sheet);
        return NULL;
    }

    size_t quantity = 0;

    size_t i = 0;

    while (i < unsorted_resource_sheet->quantity) {
        if (!strcmp(criterion,
                    ((unsorted_resource_sheet->resources_array) + i)->units)) {
            if (copy_resource(
                    new_resource_sheet->resources_array + (quantity++),
                    unsorted_resource_sheet->resources_array + i) == -1) {
                free_resource_sheet(new_resource_sheet);
                free(criterion);
                return NULL;
            }
        }
        ++i;
    }
    new_resource_sheet->quantity = quantity;
    free(criterion);
    return new_resource_sheet;
}

int printf_resource_sheet(const resource_sheet *resource_sheet, FILE *ostream) {
    for (size_t i = 0; i < resource_sheet->quantity; ++i) {
        if (printf_resource(resource_sheet->resources_array + i, ostream) ==
            -1) {
            return -1;
        }
    }
    return 0;
}
