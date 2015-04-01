/**
 * \file phbalReg_RpiSpi.h
 * \author Donatien Garnier
 */

#ifndef PHBALREG_RPISPI_H
#define PHBALREG_RPISPI_H

#include <ph_Status.h>


/** \defgroup phbalReg_RpiSpi Component : Raspberry Pi SPI
* \brief Raspberry Pi SPI BAL
*
* Implements SPI BAL interface for the Raspberry Pi.\n
* @{
*/
#define PHBAL_REG_RPISPI_ID         0x0DU       /**< ID for Raspberry Pi SPI component */

/**
* \brief Raspbrry Pi SPI BAL parameter structure
*/
typedef struct
{
    uint16_t    wId;                    /**< Layer ID for this BAL component, NEVER MODIFY! */
    uint8_t     bHalType;               /**< HAL HW type (Rc523, Rc663, ... ) */
    int			iFd;					/**< Unix file descriptor of the SPI port */
    void (*callback)(void*);
    void* pUserData;
} phbalReg_RpiSpi_DataParams_t;

/**
* \brief Initialise the Raspberry Pi SPI BAL component.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
phStatus_t phbalReg_RpiSpi_Init(
                                        phbalReg_RpiSpi_DataParams_t * pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
                                        uint16_t wSizeOfDataParams                            /**< [In] Specifies the size of the data parameter structure. */
                                   );

phStatus_t phbalReg_RpiSpi_GetPortList(
    phbalReg_RpiSpi_DataParams_t * pDataParams,
    uint16_t wPortBufSize,
    uint8_t * pPortNames,
    uint16_t * pNumOfPorts
    );

phStatus_t phbalReg_RpiSpi_SetPort(
                            phbalReg_RpiSpi_DataParams_t * pDataParams,
                            uint8_t * pPortName
                            );

phStatus_t phbalReg_RpiSpi_OpenPort(
                                  phbalReg_RpiSpi_DataParams_t * pDataParams
                                  );

phStatus_t phbalReg_RpiSpi_ClosePort(
                                   phbalReg_RpiSpi_DataParams_t * pDataParams
                                   );

phStatus_t phbalReg_RpiSpi_Exchange(
                                  phbalReg_RpiSpi_DataParams_t * pDataParams,
                                  uint8_t * pTxBuffer,
                                  uint16_t wTxLength,
                                  uint16_t wRxBufSize,
                                  uint8_t * pRxBuffer,
                                  uint16_t * pRxLength
                                  );

phStatus_t phbalReg_RpiSpi_SetConfig(
                                   phbalReg_RpiSpi_DataParams_t * pDataParams,
                                   uint16_t wConfig,
                                   uint16_t wValue
                                   );

phStatus_t phbalReg_RpiSpi_GetConfig(
                                   phbalReg_RpiSpi_DataParams_t * pDataParams,
                                   uint16_t wConfig,
                                   uint16_t * pValue
                                   );


phStatus_t phbalReg_RpiSpi_SetInterruptCallback(
												phbalReg_RpiSpi_DataParams_t * pDataParams,
												void (*callback)(void*),
												void* pUserData
											);



#endif /* PHBALREG_RPISPI_H */
