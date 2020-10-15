#include "gtest/gtest.h"

extern "C" {
#include "resource_sheet.h"
}

TEST(resource_lib_test, create_resource_sheet_test_1) {
    FILE *istream = fopen("file", "w+t");
    fprintf(istream, "%s", "1\n");
    fprintf(istream, "%s", "chiper\n");
    fprintf(istream, "%s", "name\n");
    fprintf(istream, "%s", "amount\n");
    fprintf(istream, "%s", "units\n");
    fprintf(istream, "%s", "materials\n");
    fseek(istream, 0, 0);
    resource_sheet *new_resource_sheet = create_resource_sheet(istream);
    EXPECT_STREQ(new_resource_sheet->resources_array->chiper, "chiper");
    EXPECT_STREQ(new_resource_sheet->resources_array->name, "name");
    EXPECT_STREQ(new_resource_sheet->resources_array->amount, "amount");
    EXPECT_STREQ(new_resource_sheet->resources_array->units, "units");
    EXPECT_STREQ(new_resource_sheet->resources_array->materials, "materials");
    free_resource_sheet(new_resource_sheet);
    fclose(istream);
}

TEST(resource_lib_test, create_resource_sheet_test_2) {
    FILE *istream = fopen("file", "w+t");
    EXPECT_EQ(create_resource_sheet(istream), nullptr);
    fclose(istream);
}

TEST(resource_lib_test, create_resource_sheet_test_3) {
    FILE *istream = fopen("file", "w+t");
    fprintf(istream, "%s", "1\n");
    fseek(istream, 0, 0);
    EXPECT_EQ(create_resource_sheet(istream), nullptr);
    fclose(istream);
}

TEST(resource_lib_test, resource_sheet_sort_test_1) {
    FILE *istream = fopen("file1", "w+t");
    fprintf(istream, "%s", "1\n");
    fprintf(istream, "%s", "chiper\n");
    fprintf(istream, "%s", "name\n");
    fprintf(istream, "%s", "amount\n");
    fprintf(istream, "%s", "units\n");
    fprintf(istream, "%s", "materials\n");
    fprintf(istream, "%s", "units\n");
    fseek(istream, 0, 0);
    resource_sheet *new_resource_sheet = create_resource_sheet(istream);
    resource_sheet *sorted_resource_sheet =
        resource_sheet_sort(new_resource_sheet, istream);
    EXPECT_STREQ(new_resource_sheet->resources_array->chiper, "chiper");
    EXPECT_STREQ(new_resource_sheet->resources_array->name, "name");
    EXPECT_STREQ(new_resource_sheet->resources_array->amount, "amount");
    EXPECT_STREQ(new_resource_sheet->resources_array->units, "units");
    EXPECT_STREQ(new_resource_sheet->resources_array->materials, "materials");
    free_resource_sheet(sorted_resource_sheet);
    free_resource_sheet(new_resource_sheet);
    fclose(istream);
}

TEST(resource_lib_test, resource_sheet_sort_test_2) {
    FILE *istream = fopen("file1", "w+t");
    fprintf(istream, "%s", "1\n");
    fprintf(istream, "%s", "chiper\n");
    fprintf(istream, "%s", "name\n");
    fprintf(istream, "%s", "amount\n");
    fprintf(istream, "%s", "units\n");
    fprintf(istream, "%s", "materials\n");
    fseek(istream, 0, 0);
    resource_sheet *new_resource_sheet = create_resource_sheet(istream);
    EXPECT_EQ(resource_sheet_sort(new_resource_sheet, istream), nullptr);
    free_resource_sheet(new_resource_sheet);
    fclose(istream);
}
