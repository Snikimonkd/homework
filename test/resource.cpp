#include "gtest/gtest.h"

extern "C" {
#include "resource.h"
}

TEST(resource_lib_test, read_from_stream_test_1) {
    FILE *istream = fopen("../test/read_from_stream_test1", "r");
    EXPECT_EQ(NULL, !istream);
    char *str = read_from_stream(istream);
    EXPECT_STREQ(str, "test");
    free(str);
    fclose(istream);
}

TEST(resource_lib_test, read_from_stream_test_2) {
    FILE *istream = fopen("../test/read_from_stream_test2", "r");
    EXPECT_EQ(NULL, !istream);
    char *str = read_from_stream(istream);
    EXPECT_EQ(NULL, str);
    fclose(istream);
}

TEST(resource_lib_test, create_resource_test_1) {
    FILE *istream = fopen("../test/create_resource_test1", "r");
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

TEST(resource_lib_test, create_resource_test_2) {
    FILE *istream = fopen("../test/create_resource_test2", "r");
    EXPECT_EQ(NULL, !istream);
    resource *new_resource = create_resource(istream);
    EXPECT_EQ(NULL, new_resource);
    fclose(istream);
}

TEST(resource_lib_test, create_resource_test_3) {
    FILE *istream = fopen("../test/create_resource_test3", "r");
    EXPECT_EQ(NULL, !istream);
    resource *new_resource = create_resource(istream);
    EXPECT_EQ(NULL, new_resource);
    fclose(istream);
}

TEST(resource_lib_test, create_resource_test_4) {
    FILE *istream = fopen("../test/create_resource_test4", "r");
    EXPECT_EQ(NULL, !istream);
    resource *new_resource = create_resource(istream);
    EXPECT_EQ(NULL, new_resource);
    fclose(istream);
}

TEST(resource_lib_test, create_resource_test_5) {
    FILE *istream = fopen("../test/create_resource_test5", "r");
    EXPECT_EQ(NULL, !istream);
    resource *new_resource = create_resource(istream);
    EXPECT_EQ(NULL, new_resource);
    fclose(istream);
}

TEST(resource_lib_test, create_resource_test_6) {
    FILE *istream = fopen("../test/create_resource_test5", "r");
    EXPECT_EQ(NULL, !istream);
    resource *new_resource = create_resource(istream);
    EXPECT_EQ(NULL, new_resource);
    fclose(istream);
}

TEST(resource_lib_test, dynamic_strcpy_test_1) {
    char *const src = {"test"};
    char *dst = NULL;
    int er = dynamic_strcpy(&dst, &src);
    EXPECT_EQ(0, er);
    EXPECT_EQ(NULL, !dst);
    EXPECT_STREQ(dst, src);
    free(dst);
}

TEST(resource_lib_test, dynamic_strcpy_test_2) {
    char *const src = NULL;
    char *dst = NULL;
    int er = dynamic_strcpy(&dst, &src);
    EXPECT_EQ(-1, er);
    EXPECT_EQ(NULL, dst);
}

TEST(resource_lib_test, copy_resource_test_1) {
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

TEST(resource_lib_test, copy_resource_test_2) {
    resource *src = new (resource);
    src->chiper = {"chiper"};
    src->name = {"name"};
    src->amount = {"amount"};
    src->units = {"units"};
    src->materials = NULL;
    resource *dst = new (resource);
    int er = copy_resource(dst, src);
    EXPECT_EQ(er, -1);
    delete (src);
    delete (dst);
}

TEST(resource_lib_test, copy_resource_test_3) {
    resource *src = new (resource);
    src->chiper = {"chiper"};
    src->name = {"name"};
    src->amount = {"amount"};
    src->units = NULL;
    src->materials = NULL;
    resource *dst = new (resource);
    int er = copy_resource(dst, src);
    EXPECT_EQ(er, -1);
    delete (src);
    delete (dst);
}

TEST(resource_lib_test, copy_resource_test_4) {
    resource *src = new (resource);
    src->chiper = {"chiper"};
    src->name = {"name"};
    src->amount = NULL;
    src->units = NULL;
    src->materials = NULL;
    resource *dst = new (resource);
    int er = copy_resource(dst, src);
    EXPECT_EQ(er, -1);
    delete (src);
    delete (dst);
}

TEST(resource_lib_test, copy_resource_test_5) {
    resource *src = new (resource);
    src->chiper = {"chiper"};
    src->name = NULL;
    src->amount = NULL;
    src->units = NULL;
    src->materials = NULL;
    resource *dst = new (resource);
    int er = copy_resource(dst, src);
    EXPECT_EQ(er, -1);
    delete (src);
    delete (dst);
}

TEST(resource_lib_test, copy_resource_test_6) {
    resource *src = new (resource);
    src->chiper = NULL;
    src->name = NULL;
    src->amount = NULL;
    src->units = NULL;
    src->materials = NULL;
    resource *dst = new (resource);
    int er = copy_resource(dst, src);
    EXPECT_EQ(er, -1);
    delete (src);
    delete (dst);
}

TEST(resource_lib_test, copy_resource_test_7) {
    resource *src = NULL;
    resource *dst = new (resource);
    int er = copy_resource(dst, src);
    EXPECT_EQ(er, -1);
    delete (src);
    delete (dst);
}

TEST(resource_lib_test, copy_resource_test_8) {
    resource *src = new (resource);
    resource *dst = NULL;
    int er = copy_resource(dst, src);
    EXPECT_EQ(er, -1);
    delete (src);
    delete (dst);
}