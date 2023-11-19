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

#endif
