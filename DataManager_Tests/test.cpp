#include "pch.h"
#include "DataManager.h"
#include "DataManager.c"

#define STR_EQUAL 0
#define MY_URL 'U'
#define MY_NAME 'N'
#define MY_PASSWORD 'P'


TEST(Malloc, Malloc_0x0001) {
    uint8_t read[8];
    uint8_t write[] = "Name1";

    DM_Write(sizeof(write), 0x0001, write);
    DM_Read(0x0001, read, NULL);
    //Print();
    //EXPECT_EQ(1, 1);
    EXPECT_TRUE(strcmp((char*)write, (char*)read) == STR_EQUAL);
}
TEST(Malloc, Malloc_0x0002) {
    uint8_t read[8];
    uint8_t write[] = "Name2";

    DM_Write(sizeof(write), 0x0002, write);
    DM_Read(0x0002, read, NULL);
    //Print();

    //EXPECT_EQ(1, 1);
    EXPECT_TRUE(strcmp((char*)write, (char*)read) == STR_EQUAL);
}
#if 1
TEST(Malloc, Malloc_0x0101) {
    uint8_t read[16];
    uint8_t write[] = "Password1";

    DM_Write(sizeof(write), 0x0101, write);
    DM_Read(0x0101, read, NULL);
    //Print();

    //EXPECT_EQ(1, 1);
    EXPECT_TRUE(strcmp((char*)write, (char*)read) == STR_EQUAL);
}
TEST(Malloc, Malloc_0x0102) {
    uint8_t read[16];
    uint8_t write[] = "Password2";

    DM_Write(sizeof(write), 0x0102, write);
    DM_Read(0x0102, read, NULL);
    //Print();

    //EXPECT_EQ(1, 1);
    EXPECT_TRUE(strcmp((char*)write, (char*)read) == STR_EQUAL);
}
TEST(Malloc, Malloc_0x0102_Hello) {
    uint8_t read[16];
    uint8_t write[] = "Hello";

    DM_Write(sizeof(write), 0x0102, write);
    DM_Read(0x0102, read, NULL);
    //Print();

    //EXPECT_EQ(1, 1);
    EXPECT_TRUE(strcmp((char*)write, (char*)read) == STR_EQUAL);
}
#endif

TEST(Read, Malloc_0x0000) {
    uint8_t read[16];
    uint8_t write[16] = "";

    //MyMalloc(sizeof(write), 0x0102, write);
    DM_Read(0x0000, read, NULL);
    //Print();

    //EXPECT_EQ(1, 1);
    EXPECT_TRUE(strcmp((char*)write, (char*)read) == STR_EQUAL);
}
TEST(Read, Malloc_0x0001) {
    uint8_t read[16];
    uint8_t write[16] = "Name1";

    //MyMalloc(sizeof(write), 0x0102, write);
    DM_Read(0x0001, read, NULL);
    //Print();

    //EXPECT_EQ(1, 1);
    EXPECT_TRUE(strcmp((char*)write, (char*)read) == STR_EQUAL);
}
