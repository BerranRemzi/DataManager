#include "DataManager.h"
#include <string.h>
#define BLOCK_ALOCATED 0x55u
#define BLOCK_FREE     0xAAu

typedef struct Block {
	uint8_t status;
	uint8_t size;
	uint16_t id;
} Block_t;


bool IsBlockValid(Block_t* block);

void DM_Write(uint8_t size, uint16_t id, uint8_t* dataPtr)
{
	uint8_t temp[sizeof(Block_t)];
	Block_t* block = (Block_t*)temp;
	uint16_t address = 0;
	bool isDone = false;

	while (false == isDone) {
		Eeprom_Read(temp, address, sizeof(temp));

		switch (block->status) {
		case BLOCK_ALOCATED:
			if (block->id == id) {
				block->status = BLOCK_FREE;
				Eeprom_Write(temp, address, sizeof(temp));
			}
			address += sizeof(Block_t) + block->size;
			break;
		case BLOCK_FREE:
			address += sizeof(Block_t) + block->size;
			break;
		default:
			block->status = BLOCK_ALOCATED;
			block->size = size;
			block->id = id;

			Eeprom_Write(temp, address, sizeof(temp));
			address += sizeof(temp);
			Eeprom_Write(dataPtr, address, size);

			isDone = true;
			break;
		}
	}
}

void DM_Free(uint16_t id)
{
}

void DM_Defragment(void)
{

}

bool DM_Read(uint16_t id, uint8_t* dataPtr, uint8_t* sizePtr)
{
	uint8_t temp[sizeof(Block_t)];
	Block_t* block = (Block_t*)temp;
	uint16_t address = 0;

	dataPtr[0] = '\0';
	bool isDataAvailable = Eeprom_Read(temp, address, sizeof(Block_t));;

	while (isDataAvailable) {
		if ((block->id == id) && (block->status == BLOCK_ALOCATED)) {
			address += sizeof(temp);
			isDataAvailable = Eeprom_Read(dataPtr, address, block->size);
			break;
		}
		else {
			address += sizeof(temp) + block->size;
			isDataAvailable = Eeprom_Read(temp, address, sizeof(temp));
		}
	};

	return false;
}



bool IsBlockValid(Block_t* block) {
	bool returnValue;

	switch (block->status)
	{
	case BLOCK_ALOCATED:
		returnValue = true;
		break;
	case BLOCK_FREE:
		returnValue = true;
		break;
	default:
		returnValue = false;
		break;
	}
	return returnValue;
}

uint16_t GetAvailableMemory(uint8_t* dataPtr) {
	//return (uint16_t)((memory + sizeof(memory)) - dataPtr);
	return 0;
}

static uint8_t memory[128];

bool Eeprom_Read(uint8_t* _dest, uint16_t _address, uint16_t _size) {
	bool returnValue = false;
	if ((_address + _size) < sizeof(memory)) {
		memcpy(_dest, &memory[_address], _size);
		returnValue = true;
	}
	return returnValue;
}
bool Eeprom_Write(const uint8_t* _src, uint16_t _address, uint16_t _size) {
	bool returnValue = false;
	if ((_address + _size) < sizeof(memory)) {
		memcpy(&memory[_address], _src, _size);
		returnValue = true;
	}
	return returnValue;
}
uint16_t Eeprom_GetUsedSize(void) {
	return 0;
}

#if 0
void Print(void) {
	for (uint8_t i = 0; i < sizeof(memory); i++) {
		(void)printf("%02X ", memory[i]);
	}
	printf("\n");
	for (uint8_t i = 0; i < sizeof(memory); i++) {
		char temp = memory[i];
		(void)printf("%2C ", isprint(temp) ? temp : '.');
	}
	(void)printf("\n");
}
#else
void Print(void) {
	uint8_t temp[sizeof(Block_t)];
	Block_t* block = (Block_t*)temp;
	uint16_t address = 0;
	bool isDone = false;

	while (false == isDone) {
		Eeprom_Read(temp, address, sizeof(temp));

		switch (block->status) {
		case BLOCK_ALOCATED:
			//break;
		case BLOCK_FREE:
			for (uint8_t i = 0; i < sizeof(temp); i++) {
				uint8_t ch = temp[i];
				printf("%02X ", ch);
			}
			address += sizeof(Block_t);
			for (uint8_t i = 0; i < block->size; i++) {
				uint8_t ch;
				Eeprom_Read(&ch, address + i, 1);
				printf("%C ", isprint(ch) ? ch : '.');
			}
			address += block->size;
			printf("\n");
			break;
		default:
			isDone = true;
			break;
		}
	}
}
#endif