; *------- <<< Use Configuration Wizard in Context Menu >>> ------------------


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000600

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000600

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors

__Vectors       DCD     __initial_sp              ;0x00      Top of Stack            
                DCD     Reset_Handler             ;0x04      Reset Handler           
                DCD     NMI_Handler               ;0x08      NMI Handler             
                DCD     HardFault_Handler         ;0x0c      Hard Fault Handler      
                DCD     0                         ;0x10      Reserved                
                DCD     0                         ;0x14      Reserved                
                DCD     0                         ;0x18      Reserved                
                DCD     0                         ;0x1c      Reserved                
                DCD     0                         ;0x20      Reserved                
                DCD     0                         ;0x24      Reserved                
                DCD     0                         ;0x28      Reserved                
                DCD     SVC_Handler               ;0x2c      SVCall Handler          
                DCD     0                         ;0x30      Reserved                
                DCD     0                         ;0x34      Reserved                
                DCD     PendSV_Handler            ;0x38      PendSV Handler          
                DCD     SysTick_Handler           ;0x3c      SysTick Handler         
                                                       
                ; External Interrupts                  
                                                       
                DCD     WDT_Int_Handler           ;0x40      WDT                      
                DCD     Timer0_Int_Handler        ;0x44      Timer0                   
                DCD     Timer1_Int_Handler        ;0x48      Timer1                   
                DCD     GPIO_Int_Handler          ;0x4c      GPIO                     
                DCD     GPIO_WakeUp_Int_Handler   ;0x50      GPIO Wakeup              
                DCD     Sound_Int_Handler         ;0x54      Sound                    
                DCD     0                         ;0x58                               
                DCD     Uart0_Int_Handler         ;0x5c      UART                     
                DCD     0                         ;0x60                               
                DCD     0                         ;0x64                               
                DCD     CMP_LOW_Int_Handler       ;0x68                               
                DCD     CMP_HIGH_Int_Handler      ;0x6c                               
                DCD     SPI_Int_Handler           ;0x70      SPI                      
                DCD     I2C_Int_Handler           ;0x74      I2C                      
                DCD     0                         ;0x78                               
                DCD     RTC_Int_Handler           ;0x7c      RTC                      
                DCD     ADC_Int_Handler           ;0x80      ADC                      
                DCD     ADC_Fall_Int_Handler      ;0x84      ADC_int_fail             
                DCD     ADC_Rise_Int_Handler      ;0x88      ADC_int_raise            
                DCD     I2C_rx_full_Int_Handler   ;0x8C                               
                DCD     I2C_TX_EMPTY_Int_Handler  ;0x90                               
                DCD     0                         ;0x94                               
                DCD     0                         ;0x98                               
                DCD     0                         ;0x9C                               
                DCD     0                         ;0xA0                               
                DCD     0                         ;0xA4                               
                DCD     0                         ;0xA8                               
                DCD     Uart1_Int_Handler         ;0xAC      UART1                    
                DCD     BOD_Int_Handler           ;0xB0      BOD                      
                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit                
                IMPORT  __main

				LDR R0, =0x00000020
WaitPLL	
				SUBS R0,R0,#1
				BNE WaitPLL

				NOP
				NOP
				NOP	
				
				;LDR     R0, =SystemInit
				;BLX     R0
				LDR     R0, =__main
				BX      R0
				
				ENDP


; Dummy Exception Handlers (infinite loops which can be modified)                

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]

                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC
				EXPORT  WDT_Int_Handler             	  	[WEAK]
				EXPORT  Timer0_Int_Handler             	  	[WEAK]
				EXPORT  Timer1_Int_Handler             	  	[WEAK]
				EXPORT  GPIO_Int_Handler             	  	[WEAK]
				EXPORT  GPIO_WakeUp_Int_Handler           	[WEAK]	
				EXPORT  Sound_Int_Handler             		[WEAK]
				EXPORT  Uart0_Int_Handler					[WEAK]
				EXPORT  CMP_LOW_Int_Handler                 [WEAK]
				EXPORT  CMP_HIGH_Int_Handler                [WEAK]
				EXPORT  SPI_Int_Handler             	  	[WEAK]
				EXPORT  I2C_Int_Handler             	  	[WEAK]
				EXPORT  RTC_Int_Handler             	  	[WEAK]
				EXPORT  ADC_Int_Handler             	  	[WEAK]
				EXPORT  ADC_Fall_Int_Handler             	[WEAK]
				EXPORT  ADC_Rise_Int_Handler             	[WEAK]
				EXPORT  I2C_rx_full_Int_Handler            	[WEAK]
				EXPORT  I2C_TX_EMPTY_Int_Handler           	[WEAK]
				EXPORT  Uart1_Int_Handler					[WEAK]
				EXPORT  BOD_Int_Handler				     	[WEAK]
WDT_Int_Handler
Timer0_Int_Handler
Timer1_Int_Handler
GPIO_Int_Handler
GPIO_WakeUp_Int_Handler
Sound_Int_Handler					
Uart0_Int_Handler
CMP_LOW_Int_Handler
CMP_HIGH_Int_Handler
SPI_Int_Handler
I2C_Int_Handler
RTC_Int_Handler
ADC_Int_Handler
ADC_Fall_Int_Handler
ADC_Rise_Int_Handler
I2C_rx_full_Int_Handler
I2C_TX_EMPTY_Int_Handler
Uart1_Int_Handler
BOD_Int_Handler
                B       .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB
                
                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit
                
                ELSE
                
                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, = (Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF



                END
