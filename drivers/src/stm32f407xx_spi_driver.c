#include "stm32f407xx_spi_driver.h"
/*
 * Peripheral clock setup 
*/
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
    if (EnorDi==ENABLE)
    {  
        if(pSPIx==SPI1)
        {
            SPI1_PCLK_EN();
        }
        else if(pSPIx==SPI2)
        {
            SPI2_PCLK_EN();
        }
        else if(pSPIx==SPI3)
        {
            SPI3_PCLK_EN();
        }
        
    }
    else
    {
        //pass
    }
}

/*
 * Init and De-init 
*/
void SPI_Init(SPI_Handle_t *pSPIHandle)
{
    uint32_t tempreg=0// configure SPI_CR1 Reg
    //1. config device mode
    tempreg = tempreg|pSPIHandle->SPIConfig.SPIDevicemode <<2;
    //2.configure the bus config
    if(pSPIHandle->SPIConfig.SPI_BusConfig==SPI_BUSCONFIG_FD)
    {   //bidi mode should be clear
        tempreg &= ~(1<<15);
        }
    else if(pSPIHandle->SPIConfig.SPI_BusConfig==SPI_BUSCONFIG_HD){
        //bidi mode should be set
        tempreg |= (1<<15);
        }
    else if (pSPIHandle->SPIConfig.SPI_BusConfig==SPI_BUSCONFIG_SIMPLEX_RXONLY)
    {
        //bidi mode should be clear, rxonly must be set
        tempreg &= ~(1<<15);
        tempreg|=(1<<10);
        }

    //3.configure the spi serial clock speed (baud rate)
    tempreg |= pSPIHandle->SPIConfig.SPI_SclkSpeed <<3;
    //4. configure the DFF
    tempreg |= pSPIHandle->SPIConfig.SPI_DFF <<11;
    //5.configure the CPOL
    tempreg |= pSPIHandle->SPIConfig.SPI_CPOL<<1;
    //6.configure the CPHA
    tempreg |=pSPIHandle->SPIConfig.SPI_CPHA <<0;

    pSPIHandle->pSPIx->CR1=tempreg;
}
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