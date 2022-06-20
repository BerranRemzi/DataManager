#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H
#include <stdint.h>
#include <stdbool.h>

void DM_Write(uint8_t size, uint16_t id, uint8_t* dataPtr);
void DM_Free(uint16_t id);
void DM_Defragment(void);
bool DM_Read(uint16_t id, uint8_t* dataPtr, uint8_t *sizePtr);

bool Eeprom_Read(uint8_t* _dest, uint16_t _address, uint16_t _size);
bool Eeprom_Write(const uint8_t* _src, uint16_t _address, uint16_t _size);

void Print(void);
#endif /* DATA_MANAGER_H */