#ifndef __CW3801_H__
#define __CW3801_H__

#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * @details  Interrupt Number Definition. The maximum of 32 Specific Interrupts are possible.
	 */
	typedef enum IRQn
	{
		/******  Cortex-M0 Processor Exceptions Numbers *****************************************/

		NonMaskableInt_IRQn   = -14,    /*!< 2 Non Maskable Interrupt                           */
		HardFault_IRQn        = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                   */
		SVCall_IRQn           = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                     */
		PendSV_IRQn           = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                     */
		SysTick_IRQn          = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                 */

		/******  Nano1x2 specific Interrupt Numbers ***********************************************/
		WDT_IRQn              	= 0, //0X40
		TIMER0_IRQn             = 1, //0X44
		TIMER1_IRQn            	= 2, //0X48
		GPIO_IRQn            	= 3, //0X4C
		GPIO_WAKEUP_IRQn        = 4, //0X50
		SOUND_IRQn            	= 5, //0X54
		UART0_IRQn             	= 7, //0X5C
		CMP_OUT_FALL_IRQn       = 10,//0X68
		CMP_OUT_RISE_IRQn       = 11,//0X6C
		SPI_IRQn            	= 12,//0X70
		I2C_IRQn             	= 13,//0X74
		RTC_IRQn             	= 15,//0X7C
		ADC_IRQn             	= 16,//0X80
		ADC_INT_FAIL_IRQn       = 17,//0X84
		ADC_INT_RISE_IRQn       = 18,//0X88
		I2C_RX_FULL_IRQn       	= 19,//0X8C
		I2C_TypeDefX_EMPTY_IRQn       = 20,//0X90
		UART1_IRQn              = 27,//0XAC
		BOD_IRQn                = 28,//0XB0
	}
	IRQn_Type;

	/*
	 * ==========================================================================
	 * ----------- Processor and Core Peripheral Section ------------------------
	 * ==========================================================================
	 */

	/* Configuration of the Cortex-M0 Processor and Core Peripherals */
#define __CM0_REV                0x0201    /*!< Core Revision r2p1                               */
#define __NVIC_PRIO_BITS         2         /*!< Number of Bits used for Priority Levels          */
#define __Vendor_SysTickConfig   0         /*!< Set to 1 if different SysTick Config is used     */
#define __MPU_PRESENT            0         /*!< MPU present or not                               */
#define __FPU_PRESENT            0         /*!< FPU present or not                               */

#include "core_cm0.h"                       /* Cortex-M0 processor and core peripherals           */
#include "system_DT5M1x26.h"
#include <stdint.h>
#include <stdio.h>

	/******************************************************************************/
	/*                Device Specific Peripheral registers structures             */
	/******************************************************************************/

#if defined ( __CC_ARM  )
#pragma anon_unions
#endif

	typedef struct
	{
		__IO 	uint32_t  	DC1;
		__IO 	uint32_t  	DC2;
		__IO 	uint32_t  	DC3;
		__IO  	uint32_t  	DC4;
		__IO 	uint32_t  	DC5;
		__IO 	uint32_t  	DC6;
		__IO 	uint32_t  	MC1;
		__IO  	uint32_t    MC2;
		__IO 	uint32_t  	MC3;
		__IO  	uint32_t    MC4;
		__IO 	uint32_t  	MC5;
		__IO  	uint32_t  	MC6;
		__IO  	uint32_t  	CR;
	} PWM_TypeDef;

#define PWM_CR_PWM1_EN_Pos                   0
#define PWM_CR_PWM1_EN_Msk                   (0x1ul << PWM_CR_PWM1_EN_Pos)
#define PWM_CR_PWM2_EN_Pos                   1
#define PWM_CR_PWM2_EN_Msk                   (0x1ul << PWM_CR_PWM2_EN_Pos)
#define PWM_CR_PWM3_EN_Pos                   2
#define PWM_CR_PWM3_EN_Msk                   (0x1ul << PWM_CR_PWM3_EN_Pos)
#define PWM_CR_PWM4_EN_Pos                   3
#define PWM_CR_PWM4_EN_Msk                   (0x1ul << PWM_CR_PWM4_EN_Pos)
#define PWM_CR_PWM5_EN_Pos                   4
#define PWM_CR_PWM5_EN_Msk                   (0x1ul << PWM_CR_PWM5_EN_Pos)
#define PWM_CR_PWM6_EN_Pos                   5
#define PWM_CR_PWM6_EN_Msk                   (0x1ul << PWM_CR_PWM6_EN_Pos)
#define PWM_CR_PAIR12_EN_Pos                 6
#define PWM_CR_PAIR12_EN_Msk                 (0x1ul << PWM_CR_PAIR12_EN_Pos)
#define PWM_CR_PAIR34_EN_Pos                 7
#define PWM_CR_PAIR34_EN_Msk                 (0x1ul << PWM_CR_PAIR34_EN_Pos)
#define PWM_CR_PAIR56_EN_Pos                 8
#define PWM_CR_PAIR56_EN_Msk                 (0x1ul << PWM_CR_PAIR56_EN_Pos)
	
#define PWM_CR_DEAD_ZONE1_EN_Pos             6
#define PWM_CR_DEAD_ZONE1_EN_Msk             (0x1ul << PWM_CR_DEAD_ZONE1_EN_Pos)
#define PWM_CR_DEAD_ZONE2_EN_Pos             7
#define PWM_CR_DEAD_ZONE2_EN_Msk             (0x1ul << PWM_CR_DEAD_ZONE2_EN_Pos)
#define PWM_CR_DEAD_ZONE3_EN_Pos             8
#define PWM_CR_DEAD_ZONE3_EN_Msk             (0x1ul << PWM_CR_DEAD_ZONE3_EN_Pos)

	typedef struct
	{
		__O 	uint32_t  	FIFO0;
		__O 	uint32_t  	FIFO1;
		__O 	uint32_t  	CR;
		__I  	uint32_t  	SR;
		__O  	uint32_t  	EOFI;
		__O  	uint32_t  	PSV;
	} SOUND_TypeDef;

#define SOUND_CR_ADPCM_EN_Pos                   14
#define SOUND_CR_ADPCM_EN_Msk                   (0x1ul << SOUND_CR_ADPCM_EN_Pos)
#define SOUND_CR_USIGH_EN_Pos                 	15
#define SOUND_CR_USIGH_EN_Msk                 	(0x1ul << SOUND_CR_USIGH_EN_Pos)

#define SOUND_SR_FIFO_POINTER_Pos               0
#define SOUND_SR_FIFO_POINTER_Msk               (0x1ul << SOUND_SR_FIFO_POINTER_Pos)
#define SOUND_SR_SOUND_INT_Pos                 	3
#define SOUND_SR_SOUND_INT_Msk                 	(0x1ul << SOUND_SR_SOUND_INT_Pos)

	typedef struct
	{
		__IO uint32_t  	LC;
		__I  uint32_t  	CV;
		__IO uint32_t  	CR;
		__I  uint32_t  	EOI;
		__I  uint32_t  	IS;
	} TIMER_TypeDef;

#define TIMER_CR_ENABLE_Pos                   	0
#define TIMER_CR_ENABLE_Msk                   	(0x1ul << TIMER_CR_ENABLE_Pos)
#define TIMER_CR_TIMER_MODE_Pos                 1
#define TIMER_CR_TIMER_MODE_Msk                 (0x1ul << TIMER_CR_TIMER_MODE_Pos)
#define TIMER_CR_INT_MASK_Pos                   2
#define TIMER_CR_INT_MASK_Msk                   (0x1ul << TIMER_CR_INT_MASK_Pos)
#define TIMER_CR_CAPTURE_ENABLE_Pos             3
#define TIMER_CR_CAPTURE_ENABLE_Msk             (0x1ul << TIMER_CR_CAPTURE_ENABLE_Pos)
#define TIMER_CR_EXTCLK_ENABLE_Pos              4
#define TIMER_CR_EXTCLK_ENABLE_Msk              (0x1ul << TIMER_CR_EXTCLK_ENABLE_Pos)
#define TIMER_EXT_CLK_DIV1                      0
#define TIMER_EXT_CLK_DIV4                      (0x1 << 5)
#define TIMER_EXT_CLK_DIV8                      (0x2 << 5)
#define TIMER_EXT_CLK_DIV16                     (0x3 << 5)

	/*------------- General Purpose I/O (GPIO) -----------------------------*/
	typedef struct
	{
		__IO uint32_t  DATA;
		uint32_t  RESERVED0;
		uint32_t  RESERVED1;
		uint32_t  RESERVED2;
		__IO uint32_t  DIR;
		uint32_t  RESERVED3;
		uint32_t  RESERVED4;
		uint32_t  RESERVED5;
		__IO uint32_t  MODE;
	} GPIO_TypeDef;

	typedef struct
	{
		__IO uint32_t  ISR;			//0x30
		__IO uint32_t  IER;			//0x34
		__IO uint32_t  IMR;			//0x38
		uint32_t  RESERVED0;
		__IO uint32_t  CR;			//0x40
		__IO uint32_t  WKE;			//0x44
		uint32_t  RESERVED1;
		uint32_t  RESERVED2;
		__IO uint32_t  PUE;			//0x50
		__IO uint32_t  PUE2;		//0x54
		uint32_t  RESERVED4;
		uint32_t  RESERVED5;
		struct {
			__IO uint32_t  ADCIOEN:15;		
			__IO uint32_t  CMPINNEN:1;		
			__IO uint32_t  CMPINPEN:1;		
			__IO uint32_t  RESERVES:15;		
		}Analog_reg;           //0x60
	} GPIO_MISC_TypeDef;

	/*------------- I2C Serial Interface Controller (Master/Slave) (I2C) -----------------------------*/
	typedef struct
	{
		__IO uint32_t  CON;				//0x00
		__IO uint32_t  TAR;				//0x04
		__IO uint32_t  SAR;				//0x08
		__IO uint32_t  HS_MADDR;		//0x0c
		__IO uint32_t  DATA_CMD;		//0x10
		__IO uint32_t  SS_SCL_HCNT;		//0x14
		__IO uint32_t  SS_SCL_LCNT;		//0x18
		__IO uint32_t  FS_SCL_HCNT;		//0x1c
		__IO uint32_t  FS_SCL_LCNT;		//0x20
		__IO uint32_t  HS_SCL_HCNT;		//0x24
		__IO uint32_t  HS_SCL_LCNT;		//0x28
		__I  uint32_t  INTR_STAT;		//0x2c
		__IO uint32_t  INTR_MASK;		//0x30
		__IO uint32_t  RAW_INTR_STAT;	//0x34
		__IO uint32_t  RX_TL;			//0x38
		__IO uint32_t  TX_TL;			//0x3c
		__IO uint32_t  CLR_INTR;		//0x40
		__I  uint32_t  CLR_RX_UNDER;	//0x44
		__I  uint32_t  CLR_RX_OVER;		//0x48
		__I  uint32_t  CLR_TX_OVER;		//0x4c
		__I  uint32_t  CLR_RD_REQ;		//0x50
		__I  uint32_t  CLR_TX_ABORT;	//0x54
		__I  uint32_t  CLR_RX_DONE;		//0x58
		__I  uint32_t  CLR_ACTIVITY;	//0x5C
		__I  uint32_t  CLR_STOP_DET;	//0x60
		__I  uint32_t  CLR_START_DET;	//0x64
		__I  uint32_t  CLR_GEN_CALL;	//0x68
		__IO uint32_t  EN;				//0x6C
		__I  uint32_t  STATUS;			//0x70
		__I  uint32_t  TXFLR;			//0x74
		__I  uint32_t  RXFLR;			//0x78
		uint32_t  RESERVE0;				//0x7C
		__IO uint32_t  TX_ABORD_SOURCE;	//0x80
		uint32_t  RESERVE1;				//0x84
		__IO uint32_t  DMA_CR;			//0x88
		__IO uint32_t  DMA_TDLR;		//0x8C
		__IO uint32_t  DMA_RDLR;		//0x90
	} I2C_TypeDef;

	/* I2C CON Bit Field Definitions */
#define I2C_CON_MASTER_MODE_Pos                   	0
#define I2C_CON_MASTER_MODE_Msk                   	(0x1ul << I2C_CON_MASTER_MODE_Pos)
#define I2C_CON_SPEED_Pos                 			1
#define I2C_CON_SPEED_Msk                 			(0x3ul << I2C_CON_SPEED_Pos)
#define I2C_CON_SLAVE_ADDR_10BIT_Pos                3
#define I2C_CON_SLAVE_ADDR_10BIT_Msk                (0x1ul << I2C_CON_SLAVE_ADDR_10BIT_Pos)
#define I2C_CON_MASTER_ADDR_10BIT_Pos               4
#define I2C_CON_MASTER_ADDR_10BIT_Msk               (0x1ul << I2C_CON_MASTER_ADDR_10BIT_Pos)
#define I2C_CON_RESTART_EN_Pos                     	5
#define I2C_CON_RESTART_EN_Msk                     	(0x1ul << I2C_CON_RESTART_EN_Pos)
#define I2C_CON_SLAVE_DISABLE_Pos                   6
#define I2C_CON_SLAVE_DISABLE_Msk                   (0x1ul << I2C_CON_SLAVE_DISABLE_Pos)

	/* I2C INTSTS Bit Field Definitions */
#define I2C_SR_ACTIVITY_Pos      	0
#define I2C_SR_ACTIVITY_Msk      	(0x1ul << I2C_SR_ACTIVITY_Pos)
#define I2C_SR_TFNF_Pos             1
#define I2C_SR_TFNF_Msk             (0x1ul << I2C_SR_TFNF_Pos)
#define I2C_SR_TFE_Pos              2
#define I2C_SR_TFE_Msk              (0x1ul << I2C_SR_TFE_Pos)
#define I2C_SR_RFNE_Pos             3
#define I2C_SR_RFNE_Msk             (0x1ul << I2C_SR_RFNE_Pos)
#define I2C_SR_RFF_Pos             	4
#define I2C_SR_RFF_Msk             	(0x1ul << I2C_SR_RFF_Pos)

#define RAW_INTR_STAT_RX_UNDER_Pos 			0
#define RAW_INTR_STAT_RX_UNDER_Msk			(0x1ul << RAW_INTR_STAT_RX_UNDER_Pos)
#define RAW_INTR_STAT_RX_OVER_Pos   		1
#define RAW_INTR_STAT_RX_OVER_Msk				(0x1ul << RAW_INTR_STAT_RX_OVER_Pos)
#define RAW_INTR_STAT_RX_FULL_Pos       2
#define RAW_INTR_STAT_RX_FULL_Msk				(0x1ul << RAW_INTR_STAT_RX_FULL_Pos)
#define RAW_INTR_STAT_TX_OVER_Pos   		3
#define RAW_INTR_STAT_TX_OVER_Msk				(0x1ul << RAW_INTR_STAT_TX_OVER_Pos)
#define RAW_INTR_STAT_TX_EMPTY_Pos   		4
#define RAW_INTR_STAT_TX_EMPTY_Msk			(0x1ul << RAW_INTR_STAT_TX_EMPTY_Pos)
#define RAW_INTR_STAT_RD_REQ_Pos     		5
#define RAW_INTR_STAT_RD_REQ_Msk				(0x1ul << RAW_INTR_STAT_RD_REQ_Pos)
#define RAW_INTR_STAT_TX_ABRT_Pos     	6
#define RAW_INTR_STAT_TX_ABRT_Msk				(0x1ul << RAW_INTR_STAT_TX_ABRT_Pos)
#define RAW_INTR_STAT_RX_DONE_Pos       7
#define RAW_INTR_STAT_RX_DONE_Msk				(0x1ul << RAW_INTR_STAT_RX_DONE_Pos)
#define RAW_INTR_STAT_ACTIVITY_Pos      8
#define RAW_INTR_STAT_ACTIVITY_Msk			(0x1ul << RAW_INTR_STAT_ACTIVITY_Pos)
#define RAW_INTR_STAT_STOP_DET_Pos      9
#define RAW_INTR_STAT_STOP_DET_Msk			(0x1ul << RAW_INTR_STAT_STOP_DET_Pos)
#define RAW_INTR_STAT_START_DET_Pos     10
#define RAW_INTR_STAT_START_DET_Msk			(0x1ul << RAW_INTR_STAT_START_DET_Pos)
#define RAW_INTR_STAT_GEN_CALL_Pos      11
#define RAW_INTR_STAT_GEN_CALL_Msk			(0x1ul << RAW_INTR_STAT_GEN_CALL_Pos)

	/* I2C Transmit Abort source Bit Field Definitions */
#define ABRT_7B_ADDR_NOACK  		0								 /*!< 1 = Master is in 7-bit addressing mode and the address sent was not acknowledged by any slave. */
#define ABRT_10ADDR1_NOACK  		0x01ul << 1      /*!< 1 = Master is in 10-bit address mode and  the first 10-bit address byte was not acknowledged by any slave. */
#define ABRT_10ADDR2_NOACK  		0x01ul << 2			 /*!< 1 = Master is in 10-bit address mode and the 2nd address byte of the 10-bit address was not acknowledged by any slave. */										
#define ABRT_TXDATA_NOACK   		0x01ul << 3			 /*!< 1 = Master has received an acknowledgement for  the address,but when it sent data byte(s) following the address, 
																										it did not receive an acknowledge from the remote slave(s). */
#define ABRT_GCALL_NOACK    		0x01ul << 4			 /*!< 1 = Master sent a general call and no slave on the bus responded with an ack.*/
#define ABRT_GCALL_READ					0x01ul << 5			 /*!< 1 = Master sent a general call but the user programmed the byte following the G.CALL to be a read from the bus (9th bit is set to 1)*/
#define ABRT_HS_ACKDET					0x01ul << 6			 /*!< 1 = Master is in High Speed mode and the High Speed Master code was acknowledged (wrong behavior).  */
#define ABRT_SBYTE_ACKDET				0x01ul << 7			 /*!< 1 = Master has sent a Start Byte and the Start Byte was acknowledged (wrong behavior). */
#define ABRT_HS_NORSTRT					0x01ul << 8			 /*!< 1 = The restart is disabled (IC_RESTART_EN bit(ic_con[5]) = 0) and the user is trying to use the master to send data in High Speed mode.*/
#define ABRT_SBYTE_NORSTRT			0x01ul << 9			/*!<	1 = The restart is disabled (IC_RESTART_EN bit(ic_con[5]) = 0) and the user is trying to send a Start Byte. */
#define ABRT_10B_RD_NORSTRT			0x01ul << 10		 /*!< 1 = The restart is disabled (IC_RESTART_EN bit(ic_con[5])= 0) and the Master sends a read command in 10-bit addressing mode.*/
#define ARB_MASTER_DIS					0x01ul << 11	   /*!< 1 = User attempted to use disabled Master. */
#define ARB_LOST                0x01ul << 12		 /*!< 1 = Master has lost arbitration, or if TX_ABRT_SRC[14] is also set, then the slave transmitter has lost arbitration. */
#define ABRT_SLVFLUSH_TXFIFO		0x01ul << 13		 /*!< 1 = Slave has received a read command and some data exists in the tx_fifo so the slave issues a TX_ABRT to flush old data in tx_fifo.*/ 
#define ABRT_SLV_ARBLOST				0x01ul << 14		 /*!< 1 = Slave lost the bus while it is transmitting data to a remote master. IC_TX_ABRT[12] will be set at the same time.*/
#define ABRT_SLVRD_INTX					0x01ul << 15		 /*!< 1 = Slave requesting data to TX and the user wrote a read command into the tx_fifo (9th bit is a 1). */


	/*----------------------------- Watch Dog Timer Controller -------------------------------*/
	typedef struct
	{
		__I  uint32_t  CCVR;        //0x00
		__IO uint32_t  CMR;        //0x04
		__IO uint32_t  CLR;        //0x05
		__IO uint32_t  CCR;        //0x0c
		__I  uint32_t  STAT;        //0x10
		__I  uint32_t  RSTAT;       //0x14
		__I  uint32_t  EOI;         //0x18
	} WDT_TypeDef;

#define WDT_CCR_IEN_Pos   	0
#define WDT_CCR_IEN_Msk   	(1ul << WDT_CCR_IEN_Pos)
#define WDT_CCR_MASK_Pos   	1
#define WDT_CCR_MASK_Msk   	(1ul << WDT_CCR_MASK_Pos)

	/*----------------------------- Real Time Clock Controller -------------------------------*/
	typedef struct
	{
		__I  uint32_t  CCVR;        //0x00
		__IO uint32_t  CMR;        //0x04
		__IO uint32_t  CLR;        //0x05
		__IO uint32_t  CCR;        //0x0c
		__I  uint32_t  STAT;        //0x10
		__I  uint32_t  RSTAT;       //0x14
		__I  uint32_t  EOI;         //0x18
	} RTC_TypeDef;

#define RTC_CCR_IEN_Pos   	0
#define RTC_CCR_IEN_Msk   	(1ul << RTC_CCR_IEN_Pos)
#define RTC_CCR_MASK_Pos   	1
#define RTC_CCR_MASK_Msk   	(1ul << RTC_CCR_MASK_Pos)


	/*-------------------- Serial Peripheral Interface (SPI) ----------------------*/
	typedef struct
	{
		__IO uint32_t  CTRLR0;  //0x00
		__IO uint32_t  CTRLR1;	//0x04
		__IO uint32_t  SSIENR; 	//0x08
		__IO uint32_t MWCR;		//0x0c
		__IO uint32_t SER;		//0x10
		__IO uint32_t  BAUDR;	//0x14
		__IO uint32_t TXFTLR;	//0x18
		__IO uint32_t RXFTLR;	//0x1c
		__IO uint32_t TXFLR;	//0x20
		__IO uint32_t RXFLR;	//0x24
		__I  uint32_t  SR;		//0x28
		__IO uint32_t  IMR;		//0x2C
		__I  uint32_t  ISR;		//0x30
		__I  uint32_t  RISR;	//0x34
		__I  uint32_t  TXOICR;	//0x38
		__I  uint32_t  RXOICR;	//0x3C
		__I  uint32_t  RXUICR;	//0x40
		__I  uint32_t  MSTICR;	//0x44
		__I  uint32_t  ICR;		//0x48
		__IO uint32_t  DMACR;	//0x4C
		__IO uint32_t  DMATDLR;	//0x50
		__IO uint32_t  DMARDLR;	//0x54
		uint32_t  RESERVE[2];
		__IO  uint16_t  DR;		//0x60
	} SPI_TypeDef;

	/* SPI_CTL Bit Field Definitions */
#define SPI_CTRLR0_CTRLR0_Pos       0                                   /*!< SPI CTL: CTRLR0 Position */
#define SPI_CTRLR0_CTRLR0_Msk       (0xful << SPI_CTRLR0_CTRLR0_Pos)        /*!< SPI CTRLR0: CTRLR0 Mask */
#define SPI_CTRLR0_RFR_Pos        	4                                   /*!< SPI CTRLR0: RFR Position */
#define SPI_CTRLR0_RFR_Msk        	(3ul << SPI_CTRLR0_RFR_Pos)         /*!< SPI CTRLR0: RFR Mask */
#define SPI_CTRLR0_SCPH_Pos        	6                                   /*!< SPI CTRLR0: SCPH Position */
#define SPI_CTRLR0_SCPH_Msk        (1ul << SPI_CTRLR0_SCPH_Pos)         /*!< SPI CTRLR0: SCPH Mask */
#define SPI_CTRLR0_SCPOL_Pos    	7                                   /*!< SPI CTRLR0: SCPOL Position */
#define SPI_CTRLR0_SCPOL_Msk    	(1ul << SPI_CTRLR0_SCPOL_Pos)  /*!< SPI CTRLR0: SCPOL Mask */
#define SPI_CTRLR0_TMOD_Pos         8                                  /*!< SPI CTRLR0: TMOD Position */
#define SPI_CTRLR0_TMOD_Msk         (3ul << SPI_CTRLR0_TMOD_Pos)            /*!< SPI CTRLR0: TMOD Mask */
#define SPI_CTRLR0_CFS_Pos          12                                  /*!< SPI CTRLR0: CFS Position */
#define SPI_CTRLR0_CFS_Msk          (0x1ful << SPI_CTRLR0_CFS_Pos)           /*!< SPI CTRLR0: CFS Mask */

	/* SPI_STATUS Bit Field Definitions */
#define SPI_SR_BUSY_Pos            	0                                   /*!< SPI SR: BUSY Position */
#define SPI_SR_BUSY_Msk            	(1ul << SPI_SR_BUSY_Pos)            /*!< SPI SR: BUSY Mask */
#define SPI_SR_TFNF_Pos             1                                   /*!< SPI SR: TFNF Position */
#define SPI_SR_TFNF_Msk             (1ul << SPI_SR_TFNF_Pos)            /*!< SPI SR: TFNF Mask */
#define SPI_SR_TFE_Pos            	2                                   /*!< SPI SR: TFE Position */
#define SPI_SR_TFE_Msk            	(1ul << SPI_SR_TFE_Pos)             /*!< SPI SR: TFE Mask */
#define SPI_SR_RFNE_Pos             3                                   /*!< SPI SR: RFNE Position */
#define SPI_SR_RFNE_Msk             (1ul << SPI_SR_RFNE_Pos)            /*!< SPI SR: RFNE Mask */
#define SPI_SR_RFF_Pos    			4                                   /*!< SPI SR: RFF Position */
#define SPI_SR_RFF_Msk    			(1ul << SPI_SR_RFF_Pos)   			/*!< SPI SR: RFF Mask */

	/*------------- UART -----------------------------*/
	typedef struct
	{
		union
		{
			__I  uint32_t  RBR;      /*!< Offset: 0x0000   UART Receive Buffer Register               */
			__O  uint32_t  THR;      /*!< Offset: 0x0000   UART Transmit Holding Register             */
			__IO uint32_t  DLL;      /*!< Offset: 0x0000   Lower 8 bits of a 16-bit Divisor Latch register*/
		};
		union
		{
			__IO uint32_t  DLH;      /*!< Offset: 0x0004    Higher 8 bits of a 16-bit Divisor Latch register*/
			__IO uint32_t  IER;      /*!< Offset: 0x0004    Interrupt Enable Register                       */
		};
		union
		{
			__I  uint32_t  IIR;      /*!< Offset: 0x0008    Interrupt Identity Register                     */
			__O  uint32_t  FCR;      /*!< Offset: 0x0008    FIFO Control Register                           */
		};
		__IO uint32_t  LCR;        /*!< Offset: 0x000C    UART Control State Register                */
		uint32_t  RESERVED0;
		__IO uint32_t  LSR;        /*!< Offset: 0x0014    UART Control State Register                */
		uint32_t RESERVES[64];
		__I	uint32_t   USR;
	} UART_TypeDef;

	/* UART CTL Bit Field Definitions */
#define UART_LCR_DLS_Pos      	0
#define UART_LCR_DLS_Msk      	(0x3ul << UART_LCR_DLS_Pos)
#define UART_LCR_STOP_Pos      	2
#define UART_LCR_STOP_Msk      	(0x1ul << UART_LCR_STOP_Pos)
#define UART_LCR_PEN_Pos      	3
#define UART_LCR_PEN_Msk      	(0x1ul << UART_LCR_PEN_Pos)
#define UART_LCR_EPS_Pos      	4
#define UART_LCR_EPS_Msk      	(0x1ul << UART_LCR_EPS_Pos)
#define UART_LCR_BC_Pos 		6
#define UART_LCR_BC_Msk 	  	(0x1ul << UART_LCR_BC_Pos)
#define UART_LCR_DLAB_Pos 		7
#define UART_LCR_DLAB_Msk 	  	(0x1ul << UART_LCR_DLAB_Pos)


	/* UART LSR Bit Field Definitions */
#define UART_LSR_DR_Pos  		0
#define UART_LSR_DR_Msk  		(0x1ul << UART_LSR_DR_Pos)
#define UART_LSR_OE_Pos       	1
#define UART_LSR_OE_Msk       	(0x1ul << UART_LSR_OE_Pos)
#define UART_LSR_PE_Pos       	2
#define UART_LSR_PE_Msk       	(0x1ul << UART_LSR_PE_Pos)
#define UART_LSR_FE_Pos       	3
#define UART_LSR_FE_Msk       	(0x1ul << UART_LSR_FE_Pos)
#define UART_LSR_BI_Pos       	4
#define UART_LSR_BI_Msk       	(0x1ul << UART_LSR_BI_Pos)
#define UART_LSR_THRE_Pos       5
#define UART_LSR_THRE_Msk       (0x1ul << UART_LSR_THRE_Pos)
#define UART_LSR_TEMT_Pos     	6
#define UART_LSR_TEMT_Msk     	(0x1ul << UART_LSR_TEMT_Pos)
#define UART_LSR_RFE_Pos   		7
#define UART_LSR_RFE_Msk   		(0x1ul << UART_LSR_RFE_Pos)

	/* UART IER Bit Field Definitions */
#define UART_IER_ERBFI_Pos     	0
#define UART_IER_ERBFI_Msk     	(0x1ul << UART_IER_ERBFI_Pos)
#define UART_IER_ETBEI_Pos    	1
#define UART_IER_ETBEI_Msk    	(0x1ul << UART_IER_ETBEI_Pos)
#define UART_IER_ELSI_Pos     	2
#define UART_IER_ELSI_Msk     	(0x1ul << UART_IER_ELSI_Pos)
#define UART_IER_EDSSI_Pos   	3
#define UART_IER_EDSSI_Msk   	(0x1ul << UART_IER_EDSSI_Pos)
#define UART_IER_PTIME_Pos     	7
#define UART_IER_PTIME_Msk     	(0x3ul << UART_IER_PTIME_Pos)

	/* UART ISR Bit Field Definitions */
#define UART_IIR_IID_Pos     	0
#define UART_IIR_IID_Msk     	(0xful << UART_IIR_IID_Pos)
#define UART_IIR_FIFOSE_Pos    	6
#define UART_IIR_FIFOSE_Msk    	(0x3ul << UART_IIR_FIFOSE_Pos)

#define UART_USR_BUSY_Pos		0
#define UART_USR_BUSY_Msk		(0x1ul << UART_USR_BUSY_Pos)
#define UART_USR_TFNF_Pos		1
#define UART_USR_TFNF_Msk		(0x1ul << UART_USR_TFNF_Pos)
#define UART_USR_TFE_Pos		2
#define UART_USR_TFE_Msk		(0x1ul << UART_USR_TFE_Pos)
#define UART_USR_RFNE_Pos		3
#define UART_USR_RFNE_Msk		(0x1ul << UART_USR_RFNE_Pos)
#define UART_USR_RFF_Pos		4
#define UART_USR_RFF_Msk		(0x1ul << UART_USR_RFF_Pos)
	/*------------- RCC -----------------------------*/
typedef struct
{
	__IO 	uint16_t  	CR0;			//0x00
	__IO 	uint16_t  	PWM_DIV;		//0x02
	__IO 	uint16_t  	SIO_DIV;		//0x04
	__IO  	uint16_t  	TIM_DIV;		//0x06
	__IO  	uint16_t  	APB_DIV;		//0x08
	__IO  	uint16_t  	LCD_DIV;		//0x0a
	__IO  	uint16_t  	AHB_DIV;		//0x0c
	__IO  	uint16_t  	SOUND_DIV;		//0x1e
	__IO  	uint16_t  	CP_DIV;			//0x10
	union{
		__O  	uint16_t  	all;			//0x12  ����оƬ������ƣ�ֻ��д���ܶ���Ĭ��ֵ0x103f
		struct{
			__O  	uint16_t softreset_en:1;     /*!< 0:Start SoftWare Reset  */
			__O  	uint16_t rtcreset_en:1;		 /*!< SoftWare Reset RTC */
			__O  	uint16_t reserve0:2;		
			__O  	uint16_t sleep_en:1;		 /*!< Enable MCU Sleep */
			__O  	uint16_t rtcclk_slt:1;		 /*!< RTC Clock Select 0:32k clock;1:pre division clock*/
			__O  	uint16_t reserve1:1;		
			__O  	uint16_t clk32k_slt:1;		 /*!< 32k Clock Switch 0:32k  1:8k */
			__O  	uint16_t wakeuptime:3;       /*!< Wake Up Time Select  000:22ms  001:11ms  010:6ms 011:3ms  100:1.5ms  101:700us 110:350us  111:65us*/
			__O  	uint16_t crystal_sleep_en:1; /*!< Crystal sleep Enable 0:sleep*/
			__O  	uint16_t ldostandby_en:1;	 /*!< Enable LDO Standby while MCU sleep   1:Enable */
			__O  	uint16_t wdtreseten:1;       /*!< WDT Reset Enable*/
			__O  	uint16_t reserve3:2;
		}bit;
	}CR1;
	__IO  	uint16_t  	ADC_DIV;			//0x14
	__IO  	uint16_t  	RTC_DIV;			//0x16
}RCC_TypeDef;

#define RCC_CR1_SOFTRESET_EN_Pos          0
#define RCC_CR1_SOFTRESET_EN_Msk          (0x0ul << RCC_CR1_SOFTRESET_EN_Pos)
#define RCC_CR1_RTC_SOFTRESET_EN_Pos      1
#define RCC_CR1_RTC_SOFTRESET_EN_Msk      (0x1ul << RCC_CR1_RTC_SOFTRESET_EN_Pos)
#define RCC_CR1_SLEEP_EN_Pos          	  4
#define RCC_CR1_SLEEP_EN_Msk              (0x1ul << RCC_CR1_SLEEP_EN_Pos)
#define RCC_CR1_SLEEP_EN_Pos          	  4
#define RCC_CR1_SLEEP_EN_Msk              (0x1ul << RCC_CR1_SLEEP_EN_Pos)
#define RCC_CR1_RTCCLK_SELECT_Pos         5
#define RCC_CR1_RTCCLK_SELECT_Msk         (0x1ul << RCC_CR1_SLEEP_EN_Pos)
#define RCC_CR1_32KCLK_SWITCH_Pos          7
#define RCC_CR1_32KCLK_SWITCH_Msk         (0x1ul << RCC_CR1_32KCLK_SWITCH_Pos)
#define RCC_CR1_SLEEP_EN_Pos          	  4
#define RCC_CR1_SLEEP_EN_Msk              (0x1ul << RCC_CR1_SLEEP_EN_Pos)

typedef struct{
	union {
		__IO 	uint32_t    all;
		struct {
			__IO  	uint32_t pd:1;		   /*!< ADC power down*/
			__IO  	uint32_t rst:1;        /*!< ADC reset*/
			__IO  	uint32_t reserve1:1;   
			__IO  	uint32_t cs:1;		   /*!< ADC active set*/
			__IO  	uint32_t channel:4;    /*!< ADC channel select*/
			__IO  	uint32_t ts:3;         /*!< ADC sample clock high level time*/
			__IO  	uint32_t reserve2:1;
			__IO  	uint32_t tc:5;         /*!< ADC convers time*/
			__IO  	uint32_t reserve3:15;
		}bit;
	}ADC_CON1;
	__I 	uint32_t    RESERVE1[9];
	union{
		__IO 	uint32_t    all;
		struct {
			__IO  	uint32_t start:1;      /*!< ADC start*/
			__IO  	uint32_t reserve4:3;
			__IO  	uint32_t done:1;       /*!< ADC done flag*/
			__IO  	uint32_t reserve5:27;
		}bit;
	}ADC_CON2;
	union {
		__I 	uint32_t    all;
		struct {
			__I 	uint32_t data:12;
			__I 	uint32_t reserve:20;    /*!< ADC result*/
		}bit;
	}ADC_CON3;
}ADC_TypeDef;

typedef struct{
	__IO  	uint32_t PWD:1;             /*!<Power Down Enable*/
	__IO  	uint32_t VREF_SWT:1;        /*!<1:Switch INN input signal 0: from pad 1:1.0V*/
	__IO  	uint32_t PROG:1;
	__IO  	uint32_t SPEED:1;
	__IO  	uint32_t RESULT:1;
	__IO  	uint32_t RESERVE:27;
}CMP_CR_TypeDef;

typedef struct{
	struct{
		__IO  	uint32_t key1;       /*!<KEY 31-0*/
		__IO  	uint32_t key2;       /*!<KEY 63-32*/
		__IO  	uint32_t key3;       /*!<KEY 95-64*/
		__IO  	uint32_t key4;       /*!<KEY 127-96*/
		__IO  	uint32_t key5;       /*!<KEY 159-128*/
		__IO  	uint32_t key6;       /*!<KEY 191-160*/
		__IO  	uint32_t key7;       /*!<KEY 223-192*/
		__IO  	uint32_t key8;       /*!<KEY 255-224*/
	}AES_KEY;
	struct{
		__IO  	uint32_t text1;      /*!<bit31~0*/
		__IO  	uint32_t text2;	     /*!<bit63~32*/
		__IO  	uint32_t text3;      /*!<bit95~64*/
		__IO  	uint32_t text4;      /*!<bit127~96*/
	}AES_PLAINTEXT;
	__IO  	uint32_t aes_mem_clock_en; /*!<bit 31 AES memory clock enable*/
	__IO  	uint32_t key_len;
	__IO  	uint32_t RESERVE[2];
	struct{
		__IO  	uint32_t constant1;  
		__IO  	uint32_t constant2;
		__IO  	uint32_t constant3;
	}AES_ROUNDCONST;
}AES_Typedef;


#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

	/*!<Peripheral memory map */
#define AES_BASE              ((vu32)0x01000000UL)    ///< AES register base address
#define RCC_BASE              ((vu32)0x10000000UL)    ///< CLK register base address
#define GPIOA_BASE            ((vu32)0x10000100UL)    ///< GPIO port A register base address
#define GPIOB_BASE            ((vu32)0x10000104UL)    ///< GPIO port B register base address
#define GPIO_MISC_BASE        ((vu32)0x10000130UL)    ///< GPIO Misc register base address
#define SPI_BASE              ((vu32)0x10000300UL)    ///< SPI register base address
#define I2C_BASE              ((vu32)0x10000400UL)    ///< I2C register base address
#define RTC_BASE              ((vu32)0x10000500UL)    ///< RTC register base address
#define WDT_BASE              ((vu32)0x10000700UL)    ///< WDT register base address
#define TIMER0_BASE           ((vu32)0x10000900UL)    ///< TIMER0 register base address
#define TIMER1_BASE           ((vu32)0x10000914UL)    ///< TIMER1 register base address
#define UART0_BASE            ((vu32)0x10000A00UL)    ///< UART0 register base address
#define UART1_BASE            ((vu32)0x10000B00UL)    ///< UART1 register base address
#define CMP_CR_BASE           ((vu32)0x04000004UL)    ///< CMP control register base address
#define ADC_BASE              ((vu32)0x04000010UL)	  ///< ADC register base address
#define PWM_BASE              ((vu32)0x05000000UL)    ///< PWM register base address
#define SOUND_BASE			  ((vu32)0x06000000UL)	  ///< SOUND register base address

	/*@}*/ /* end of group NANO1X2_PERIPHERAL_MEM_MAP */


	/** @addtogroup NANO1X2_PERIPHERAL_DECLARATION NANO1X2 Peripheral Declaration
	  The Declaration of NANO1X2 Series Peripheral
	  @{
	 */


#define WDT                   ((WDT_TypeDef *) WDT_BASE)              ///< Pointer to WDT register structure
#define RTC                   ((RTC_TypeDef *) RTC_BASE)              ///< Pointer to RTC register structure
#define TIMER0                ((TIMER_TypeDef *) TIMER0_BASE)         ///< Pointer to TIMER0 register structure
#define TIMER1                ((TIMER_TypeDef *) TIMER1_BASE)         ///< Pointer to TIMER1 register structure
#define I2C                   ((I2C_TypeDef *) I2C_BASE)             ///< Pointer to I2C0 register structure
#define SPI                   ((SPI_TypeDef *) SPI_BASE)             ///< Pointer to SPI0 register structure
#define PWM                   ((PWM_TypeDef *) PWM_BASE)             ///< Pointer to PWM0 register structure
#define UART0                 ((UART_TypeDef *) UART0_BASE)           ///< Pointer to UART0 register structure
#define UART1                 ((UART_TypeDef *) UART1_BASE)           ///< Pointer to UART1 register structure
#define ADC                   ((ADC_TypeDef *) ADC_BASE)              ///< Pointer to ADC register structure
#define SYS                   ((GCR_TypeDef *) GCR_BASE)
#define RCC                   ((RCC_TypeDef *) RCC_BASE)
#define SOUND                 ((SOUND_TypeDef *) SOUND_BASE)
#define GPIOA                 ((GPIO_TypeDef *) GPIOA_BASE)           ///< Pointer to GPIO port A register structure
#define GPIOB                 ((GPIO_TypeDef *) GPIOB_BASE)           ///< Pointer to GPIO port B register structure
#define GPIO_MISC			  ((GPIO_MISC_TypeDef *) GPIO_MISC_BASE)
#define AES                   ((AES_Typedef *) AES_BASE)
#define CMP                   ((CMP_CR_TypeDef *)CMP_CR_BASE)

	typedef volatile unsigned char  	vu8;        ///< Define 8-bit unsigned volatile data type
	typedef volatile unsigned short 	vu16;       ///< Define 16-bit unsigned volatile data type
	typedef volatile unsigned long  	vu32;       ///< Define 32-bit unsigned volatile data type
	typedef volatile signed char  		vs8;        ///< Define 8-bit unsigned volatile data type
	typedef volatile signed short 		vs16;       ///< Define 16-bit unsigned volatile data type
	typedef volatile signed long  		vs32;       ///< Define 32-bit unsigned volatile data type
	/**
	  * @brief Get a 8-bit unsigned value from specified address
	  * @param[in] addr Address to get 8-bit data from
	  * @return  8-bit unsigned value stored in specified address
	  */
#define M8(addr)  (*((vu8  *) (addr)))

	/**
	  * @brief Get a 16-bit unsigned value from specified address
	  * @param[in] addr Address to get 16-bit data from
	  * @return  16-bit unsigned value stored in specified address
	  * @note The input address must be 16-bit aligned
	  */
#define M16(addr) (*((vu16 *) (addr)))

	/**
	  * @brief Get a 32-bit unsigned value from specified address
	  * @param[in] addr Address to get 32-bit data from
	  * @return  32-bit unsigned value stored in specified address
	  * @note The input address must be 32-bit aligned
	  */
#define M32(addr) (*((vu32 *) (addr)))

	/**
	  * @brief Set a 32-bit unsigned value to specified I/O port
	  * @param[in] port Port address to set 32-bit data
	  * @param[in] value Value to write to I/O port
	  * @return  None
	  * @note The output port must be 32-bit aligned
	  */
#define outpw(port,value)     *((volatile unsigned int *)(port)) = value

	/**
	  * @brief Get a 32-bit unsigned value from specified I/O port
	  * @param[in] port Port address to get 32-bit data from
	  * @return  32-bit unsigned value stored in specified I/O port
	  * @note The input port must be 32-bit aligned
	  */
#define inpw(port)            (*((volatile unsigned int *)(port)))

	/**
	  * @brief Set a 16-bit unsigned value to specified I/O port
	  * @param[in] port Port address to set 16-bit data
	  * @param[in] value Value to write to I/O port
	  * @return  None
	  * @note The output port must be 16-bit aligned
	  */
#define outps(port,value)     *((volatile unsigned short *)(port)) = value

	/**
	  * @brief Get a 16-bit unsigned value from specified I/O port
	  * @param[in] port Port address to get 16-bit data from
	  * @return  16-bit unsigned value stored in specified I/O port
	  * @note The input port must be 16-bit aligned
	  */
#define inps(port)            (*((volatile unsigned short *)(port)))

	/**
	  * @brief Set a 8-bit unsigned value to specified I/O port
	  * @param[in] port Port address to set 8-bit data
	  * @param[in] value Value to write to I/O port
	  * @return  None
	  */
#define outpb(port,value)     *((volatile unsigned char *)(port)) = value

	/**
	  * @brief Get a 8-bit unsigned value from specified I/O port
	  * @param[in] port Port address to get 8-bit data from
	  * @return  8-bit unsigned value stored in specified I/O port
	  */
#define inpb(port)            (*((volatile unsigned char *)(port)))

	/**
	  * @brief Set a 32-bit unsigned value to specified I/O port
	  * @param[in] port Port address to set 32-bit data
	  * @param[in] value Value to write to I/O port
	  * @return  None
	  * @note The output port must be 32-bit aligned
	  */
#define outp32(port,value)    *((volatile unsigned int *)(port)) = value

	/**
	  * @brief Get a 32-bit unsigned value from specified I/O port
	  * @param[in] port Port address to get 32-bit data from
	  * @return  32-bit unsigned value stored in specified I/O port
	  * @note The input port must be 32-bit aligned
	  */
#define inp32(port)           (*((volatile unsigned int *)(port)))

	/**
	  * @brief Set a 16-bit unsigned value to specified I/O port
	  * @param[in] port Port address to set 16-bit data
	  * @param[in] value Value to write to I/O port
	  * @return  None
	  * @note The output port must be 16-bit aligned
	  */
#define outp16(port,value)    *((volatile unsigned short *)(port)) = value

	/**
	  * @brief Get a 16-bit unsigned value from specified I/O port
	  * @param[in] port Port address to get 16-bit data from
	  * @return  16-bit unsigned value stored in specified I/O port
	  * @note The input port must be 16-bit aligned
	  */
#define inp16(port)           (*((volatile unsigned short *)(port)))

	/**
	  * @brief Set a 8-bit unsigned value to specified I/O port
	  * @param[in] port Port address to set 8-bit data
	  * @param[in] value Value to write to I/O port
	  * @return  None
	  */
#define outp8(port,value)     *((volatile unsigned char *)(port)) = value

	/**
	  * @brief Get a 8-bit unsigned value from specified I/O port
	  * @param[in] port Port address to get 8-bit data from
	  * @return  8-bit unsigned value stored in specified I/O port
	  */
#define inp8(port)            (*((volatile unsigned char *)(port)))

	/******************************************************************************/
	/*                Legacy Constants                                            */
	/******************************************************************************/

#ifndef NULL
#define NULL           (0)      ///< NULL pointer
#endif

#define SET            (1)      ///< Boolean true
#define RESET          (0)      ///< Boolean false

#define TRUE           (1)      ///< Boolean true, define to use in API parameters or return value
#define FALSE          (0)      ///< Boolean false, define to use in API parameters or return value

#define ENABLE         (1)      ///< Enable, define to use in API parameters
#define DISABLE        (0)      ///< Disable, define to use in API parameters

#define DT_OK          (1)
#define DT_ERROR       (0)
	/* Define one bit mask */
#define BIT0     (0x00000001)       ///< Bit 0 mask of an 32 bit integer
#define BIT1     (0x00000002)       ///< Bit 1 mask of an 32 bit integer
#define BIT2     (0x00000004)       ///< Bit 2 mask of an 32 bit integer
#define BIT3     (0x00000008)       ///< Bit 3 mask of an 32 bit integer
#define BIT4     (0x00000010)       ///< Bit 4 mask of an 32 bit integer
#define BIT5     (0x00000020)       ///< Bit 5 mask of an 32 bit integer
#define BIT6     (0x00000040)       ///< Bit 6 mask of an 32 bit integer
#define BIT7     (0x00000080)       ///< Bit 7 mask of an 32 bit integer
#define BIT8     (0x00000100)       ///< Bit 8 mask of an 32 bit integer
#define BIT9     (0x00000200)       ///< Bit 9 mask of an 32 bit integer
#define BIT10    (0x00000400)       ///< Bit 10 mask of an 32 bit integer
#define BIT11    (0x00000800)       ///< Bit 11 mask of an 32 bit integer
#define BIT12    (0x00001000)       ///< Bit 12 mask of an 32 bit integer
#define BIT13    (0x00002000)       ///< Bit 13 mask of an 32 bit integer
#define BIT14    (0x00004000)       ///< Bit 14 mask of an 32 bit integer
#define BIT15    (0x00008000)       ///< Bit 15 mask of an 32 bit integer
#define BIT16    (0x00010000)       ///< Bit 16 mask of an 32 bit integer
#define BIT17    (0x00020000)       ///< Bit 17 mask of an 32 bit integer
#define BIT18    (0x00040000)       ///< Bit 18 mask of an 32 bit integer
#define BIT19    (0x00080000)       ///< Bit 19 mask of an 32 bit integer
#define BIT20    (0x00100000)       ///< Bit 20 mask of an 32 bit integer
#define BIT21    (0x00200000)       ///< Bit 21 mask of an 32 bit integer
#define BIT22    (0x00400000)       ///< Bit 22 mask of an 32 bit integer
#define BIT23    (0x00800000)       ///< Bit 23 mask of an 32 bit integer
#define BIT24    (0x01000000)       ///< Bit 24 mask of an 32 bit integer
#define BIT25    (0x02000000)       ///< Bit 25 mask of an 32 bit integer
#define BIT26    (0x04000000)       ///< Bit 26 mask of an 32 bit integer
#define BIT27    (0x08000000)       ///< Bit 27 mask of an 32 bit integer
#define BIT28    (0x10000000)       ///< Bit 28 mask of an 32 bit integer
#define BIT29    (0x20000000)       ///< Bit 29 mask of an 32 bit integer
#define BIT30    (0x40000000)       ///< Bit 30 mask of an 32 bit integer
#define BIT31    (0x80000000)       ///< Bit 31 mask of an 32 bit integer

	/* Byte Mask Definitions */
#define BYTE0_Msk              (0x000000FF)         ///< Mask to get bit0~bit7 from a 32 bit integer
#define BYTE1_Msk              (0x0000FF00)         ///< Mask to get bit8~bit15 from a 32 bit integer
#define BYTE2_Msk              (0x00FF0000)         ///< Mask to get bit16~bit23 from a 32 bit integer
#define BYTE3_Msk              (0xFF000000)         ///< Mask to get bit24~bit31 from a 32 bit integer

#define GET_BYTE0(u32Param)    ((u32Param & BYTE0_Msk)      )  /*!< Extract Byte 0 (Bit  0~ 7) from parameter u32Param */
#define GET_BYTE1(u32Param)    ((u32Param & BYTE1_Msk) >>  8)  /*!< Extract Byte 1 (Bit  8~15) from parameter u32Param */
#define GET_BYTE2(u32Param)    ((u32Param & BYTE2_Msk) >> 16)  /*!< Extract Byte 2 (Bit 16~23) from parameter u32Param */
#define GET_BYTE3(u32Param)    ((u32Param & BYTE3_Msk) >> 24)  /*!< Extract Byte 3 (Bit 24~31) from parameter u32Param */

#ifdef __cplusplus
}
#endif


/******************************************************************************/
/*                         Peripheral header files                            */
/******************************************************************************/
#include "dt5m1x26_rcc.h"
#include "dt5m1x26_gpio.h"
#include "dt5m1x26_i2c.h"
#include "dt5m1x26_pwm.h"
#include "dt5m1x26_rtc.h"
#include "dt5m1x26_spi.h"
#include "dt5m1x26_timer.h"
#include "dt5m1x26_uart.h"
#include "dt5m1x26_wdt.h"
#include "dt5m1x26_audio.h"
#include "dt5m1x26_systick.h"
#include "dt5m1x26_adc.h"
#include "dt5m1x26_flash.h"
#include "dt5m1x26_cmp.h"
#include "dt5m1x26_aes.h"
/* Exported macro ------------------------------------------------------------*/
#ifdef  USE_FULL_ASSERT

/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function which reports 
  *         the name of the source file and the source line number of the call 
  *         that failed. If expr is true, it returns no value.
  * @retval None
  */
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
  void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */

#endif
	
