#include <cstdint>
#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#define __vo volatile
/*
* base address of peripherals which are hanging on APB1 bus
*/
#define SPI2_BASEADDR (APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR (APB1PERIPH_BASEADDR + 0x3C00)

/*
* base address of peripherals which are hanging on APB2 bus
*/
#define SPI1_BASEADDR (APB2PERIPH_BASEADDR + 0x3C00)

/*
* peripheral register def strcuture of SPI
*/
typedef struct
{
    __vo uint32_t CR1;
    __vo uint32_t CR2;
    __vo uint32_t SR;
    __vo uint32_t DR;
    __vo uint32_t CRCPR;
    __vo uint32_t RXCRCR;
    __vo uint32_t TXCRCR;
    __vo uint32_t I2SCFGR;
    __vo uint32_t I2SPR;
}SPI_RegDef_t;

/*
 * Peripheral Definitions (peripheral base addresses typecasted to xxx_RegDef_t)
 * 
*/
#define SPI1 ((SPI_RegDef_t*)SPI1_BASE)
#define SPI2 ((SPI_RegDef_t*)SPI2_BASE)
#define SPI3 ((SPI_RegDef_t*)SPI3_BASE)

/*
 * Clock enable macros for SPIx Peripherals 
*/
#define SPI1_PCLK_EN() (RCC->APB2ENR |= (1<<12))
#define SPI2_PCLK_EN() (RCC->APB1ENR |= (1<<14))
#define SPI3_PCLK_EN() (RCC->APB1ENR |= (1<<15))
#define SPI4_PCLK_EN() (RCC->APB2ENR |= (1<<13))
#endif