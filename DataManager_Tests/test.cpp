#include "pch.h"
#include "DataManager.h"
#include "DataManager.c"

#define STR_EQUAL 0
#define MY_URL 'U'
#define MY_NAME 'N'
#define MY_PASSWORD 'P'


TEST(Malloc, 0x0001_Name1) {
    uint8_t read[8];
    uint8_t write[] = "Name1";

    DM_Write(sizeof(write), 0x0001, write);
    DM_Read(0x0001, read, NULL);
    //Print();
    //EXPECT_EQ(1, 1);
    EXPECT_TRUE(strcmp((char*)write, (char*)read) == STR_EQUAL);
}
TEST(Malloc, 0x0002_Name2) {
    uint8_t read[8];
    uint8_t write[] = "Name2";

    DM_Write(sizeof(write), 0x0002, write);
    DM_Read(0x0002, read, NULL);
    //Print();

    //EXPECT_EQ(1, 1);
    EXPECT_TRUE(strcmp((char*)write, (char*)read) == STR_EQUAL);
}
#if 1
TEST(Malloc, 0x0101_Password1) {
    uint8_t read[16];
    uint8_t write[] = "Password1";

    DM_Write(sizeof(write), 0x0101, write);
    DM_Read(0x0101, read, NULL);
    //Print();

    //EXPECT_EQ(1, 1);
    EXPECT_TRUE(strcmp((char*)write, (char*)read) == STR_EQUAL);
}
TEST(Malloc, 0x0102_Password2) {
    uint8_t read[16];
    uint8_t write[] = "Password2";

    DM_Write(sizeof(write), 0x0102, write);
    DM_Read(0x0102, read, NULL);
    //Print();

    //EXPECT_EQ(1, 1);
    EXPECT_TRUE(strcmp((char*)write, (char*)read) == STR_EQUAL);
}
TEST(Malloc, 0x0102_Hello) {
    uint8_t read[16];
    uint8_t write[] = "Hello";

    DM_Write(sizeof(write), 0x0102, write);
    DM_Read(0x0102, read, NULL);
    //Print();

    //EXPECT_EQ(1, 1);
    EXPECT_TRUE(strcmp((char*)write, (char*)read) == STR_EQUAL);
}
#endif

TEST(Read, 0x0000_Null) {
    uint8_t read[16];
    uint8_t write[16] = "";

    //MyMalloc(sizeof(write), 0x0102, write);
    DM_Read(0x0000, read, NULL);
    //Print();

    //EXPECT_EQ(1, 1);
    EXPECT_TRUE(strcmp((char*)write, (char*)read) == STR_EQUAL);
}
TEST(Read, 0x0001_Name1) {
    uint8_t read[16];
    uint8_t write[] = "Name1";

    //MyMalloc(sizeof(write), 0x0102, write);
    DM_Read(0x0001, read, NULL);
    //Print();

    //EXPECT_EQ(1, 1);
    EXPECT_TRUE(strcmp((char*)write, (char*)read) == STR_EQUAL);
}

TEST(Defragment, Defragment) {
    printf("Before:\n");
    Print();

    DM_Defragment();

    printf("\nAfter:\n");
    Print();

    EXPECT_EQ(1, 1);
}
