#include <stdlib.h>

#include "resource.h"
#include "resource_sheet.h"

int main() {
    FILE *istream = stdin;
    if (istream == NULL) {
        return -1;
    }

    FILE *ostream = stdout;

    resource_sheet *new_resource_sheet = create_resource_sheet(istream);
    if (new_resource_sheet == NULL) {
        fclose(ostream);
        fclose(istream);
        return -1;
    }

    resource_sheet *sorted_resource_sheet =
        resource_sheet_sort(new_resource_sheet, istream);
    if (sorted_resource_sheet == NULL) {
        free_resource_sheet(new_resource_sheet);
        free(new_resource_sheet);
        fclose(ostream);
        fclose(istream);
        return -1;
    }

    if (printf_resource_sheet(new_resource_sheet, ostream) == -1) {
        free_resource_sheet(new_resource_sheet);
        free_resource_sheet(sorted_resource_sheet);
        fclose(ostream);
        fclose(istream);
        return -1;
    }

    if (printf_resource_sheet(sorted_resource_sheet, ostream) == -1) {
        free_resource_sheet(new_resource_sheet);
        free_resource_sheet(sorted_resource_sheet);
        fclose(ostream);
        fclose(istream);
        return -1;
    }

    free_resource_sheet(new_resource_sheet);
    free_resource_sheet(sorted_resource_sheet);
    fclose(ostream);
    fclose(istream);
    return 0;
}
