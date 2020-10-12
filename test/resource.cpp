#include "gtest/gtest.h"

extern "C" {
#include "resource.h"
}

TEST(resource_lib_test, read_from_stream_test) {
    FILE *istream = fopen("../test/read_from_stream_test", "r");
    EXPECT_EQ(NULL, !istream);
    char *str = read_from_stream(istream);
    EXPECT_STREQ(str, "test");
    free(str);
    fclose(istream);
}

TEST(resource_lib_test, create_resource_test) {
    FILE *istream = fopen("../test/create_resource_test", "r");
    EXPECT_EQ(NULL, !istream);
    resource *new_resource = create_resource(istream);
    EXPECT_STREQ(new_resource->chiper, "chiper");
    EXPECT_STREQ(new_resource->name, "name");
    EXPECT_STREQ(new_resource->amount, "amount");
    EXPECT_STREQ(new_resource->units, "units");
    EXPECT_STREQ(new_resource->materials, "materials");
    free_resource(new_resource);
    free(new_resource);
    fclose(istream);
}

TEST(resource_lib_test, dynamic_strcpy_test) {
    char *const src = {"test"};
    char *dst = NULL;
    int er = dynamic_strcpy(&dst, &src);
    EXPECT_EQ(0, er);
    EXPECT_EQ(NULL, !dst);
    EXPECT_STREQ(dst, src);
    free(dst);
}

TEST(resource_lib_test, copy_resource_test) {
    resource *src = new (resource);
    src->chiper = {"chiper"};
    src->name = {"name"};
    src->amount = {"amount"};
    src->units = {"units"};
    src->materials = {"materials"};
    resource *dst = new (resource);
    int er = copy_resource(dst, src);
    EXPECT_EQ(er, 0);
    EXPECT_STREQ(dst->chiper, "chiper");
    EXPECT_STREQ(dst->name, "name");
    EXPECT_STREQ(dst->amount, "amount");
    EXPECT_STREQ(dst->units, "units");
    EXPECT_STREQ(dst->materials, "materials");
    free_resource(dst);
    delete (src);
    delete (dst);
}
