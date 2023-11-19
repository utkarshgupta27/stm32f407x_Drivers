#include "inc/stm32f407xx_spi_driver.h"
/*
 * Peripheral clock setup 
*/
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
}

/*
 * Init and De-init 
*/
void SPI_Init(SPI_RegDef_t *pSPIHandle){}
void SPI_DeInit (SPI_RegDef_t *pSPIx){}
/*
 * Data send and recieve
*/
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len){}

void SPI_RecieveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len){}
/*
 * IRQ configuration and ISR handling 
*/
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi){}
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority){}
void SPI_IRQHandling(SPI_Handle_t *pHandle){}
/*