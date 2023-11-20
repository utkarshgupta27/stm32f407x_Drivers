
#ifndef INC_STM32F407XX_SPI_DRIVER_H_
#define INC_STM32F407XX_SPI_DRIVER_H_
#include "stm32f407xx.h"
#include <cstdint>
/*
configuration structure for SPIx Peripheral
*/
typedef struct
{
    uint8_t SPI_DeviceMode;
    uint8_t SPI_BusConfig;
    uint8_t SPI_SclkSpeed;
    uint8_t SPI_DFF;
    uint8_t SPI_CPHA;
    uint8_t SPI_CPOL;
    uint8_t SPI_SSM;
    
} SPI_Config_t;

/*
Handle strcutre for SPIx peripheral
*/
typedef struct{
    SPI_RegDef_t *pSPIx; // hold base address of SPIx (x:0,1,2) peripheral
    SPI_Config_t SPIConfig;
} SPI_Handle_t;

/*
 *@SPI_DeviceMode 
*/
#define SPI_DEVICE_MODE_MASTER 1
#define SPI_DEVICE_MODE_SLAVE 0
/*
 * SPI_BusConfig
*/
#define SPI_BUSCONFIG_FD 1
#define SPI_BUSCONFIG_HD 2
#define SPI_BUSCONFIG_SIMPLEX_RXONLY 3

/*
 *@SPI_SclkSpeed 
*/
#define SPI_SCLKSPEED_DIV2 0
#define SPI_SCLKSPEED_DIV4 1
#define SPI_SCLKSPEED_DIV8 2
#define SPI_SCLKSPEED_DIV16 3
#define SPI_SCLKSPEED_DIV32 4
#define SPI_SCLKSPEED_DIV64 5
#define SPI_SCLKSPEED_DIV128 6
#define SPI_SCLKSPEED_DIV256 7
/*
 *@SPI_DFF 
*/
#define SPI_DFF_8BITS 0
#define SPI_DFF_16BITS 1

/*
 *CPHA
*/
#define SPI_CPHA_HIGH 1
#define SPI_CPHA_LOW 0
/*
 *@CPOL
 */
#define SPI_CPOL_HIGH 1
#define SPI_CPOL_LOW 0

/*
* @SPI_SSM
*/
#define SPI_SSM_EN 1
#define SPI_SSM_DI 0
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
void SPI_Init(SPI_Handle_t *pSPIHandle);
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
