#include "stm32f407xx.h"
#include <cstdint>
#ifndef INC_STM32F407XX_SPI_DRIVER_H_
#define INC_STM32F407XX_SPI_DRIVER_H_
/*
configuration structure for SPIx Peripheral
*/
typedef struct
{
    uint8_t SPI_DeviceMode;
    uint8_t SPI_BusConfig;
    uint8_t SPI_DFF;
    uint8_t SPI_CPHA;
    uint8_t SPI_CPOL;
    uint8_t SPI_SSM;
    uint8_t SPI_speed;
} SPI_Config_t;

/*
Handle strcutre for SPIx peripheral
*/
typedef struct{
    SPI_RegDef_t *pSPIx; // hold base address of SPIx (x:0,1,2) peripheral
    SPI_Config_t SPIConfig;
} SPI_Handle_t;

/*********************************************************************
 * Api Supported by this driver
 * *******************************************************************/
/*
 * Peripheral clock setup 
*/
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

/*
 * Init and De-init 
*/
void SPI_Init(SPI_RegDef_t *pSPIHandle);
void SPI_DeInit (SPI_RegDef_t *pSPIx);
/*
 * Data send and recieve
*/
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len);

void SPI_RecieveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len);
/*
 * IRQ configuration and ISR handling 
*/
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pHandle);
/*
 * Other peripheral control APIS 
*/
#endif
