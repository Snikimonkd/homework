#ifndef INCLUDE_RESOURCE_SHEET_H_
#define INCLUDE_RESOURCE_SHEET_H_

#include "resource.h"

typedef struct resource_sheet {
    resource *resources_array;
    size_t quantity;
} resource_sheet;

resource_sheet *create_resource_sheet(FILE *stream);
void free_resource_sheet(resource_sheet *resource_sheet);

resource_sheet *
resource_sheet_sort(resource_sheet *const unsorted_resource_sheet,
                    FILE *stream);

int printf_resource_sheet(const resource_sheet *resource_sheet, FILE *ostream);

#endif  // INCLUDE_RESOURCE_SHEET_H_
