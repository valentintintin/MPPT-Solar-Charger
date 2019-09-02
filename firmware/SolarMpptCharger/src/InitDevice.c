//=========================================================
// src/InitDevice.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================

// USER INCLUDES
#include <SI_EFM8SB1_Register_Enums.h>
#include "InitDevice.h"

//=============================================================================
// Automatically generated line:
//   PCA0PWM &= ~PCA0PWM_ARSEL__BMASK;
// must be deleted in the three subroutines
//   PCACH_0_enter_DefaultMode_from_RESET (twice)
//   PCACH_1_enter_DefaultMode_from_RESET (twice)
//   PCACH_2_enter_DefaultMode_from_RESET
// to enable 10-bit PWM (they are erroneously included by the configurator)
//=============================================================================

// USER PROTOTYPES
// USER FUNCTIONS

// $[Library Includes]
// [Library Includes]$

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void enter_DefaultMode_from_RESET(void) {
	// $[Config Calls]
	// Save the SFRPAGE
	uint8_t SFRPAGE_save = SFRPAGE;
	PCA_0_enter_DefaultMode_from_RESET();
	PCACH_0_enter_DefaultMode_from_RESET();
	PCACH_1_enter_DefaultMode_from_RESET();
	PCACH_2_enter_DefaultMode_from_RESET();
	VREG_0_enter_DefaultMode_from_RESET();
	PORTS_0_enter_DefaultMode_from_RESET();
	PORTS_1_enter_DefaultMode_from_RESET();
	PBCFG_0_enter_DefaultMode_from_RESET();
	RSTSRC_0_enter_DefaultMode_from_RESET();
	HFOSC_0_enter_DefaultMode_from_RESET();
	CLOCK_0_enter_DefaultMode_from_RESET();
	FLASH_0_enter_DefaultMode_from_RESET();
	TIMER01_0_enter_DefaultMode_from_RESET();
	TIMER16_2_enter_DefaultMode_from_RESET();
	TIMER_SETUP_0_enter_DefaultMode_from_RESET();
	ADC_0_enter_DefaultMode_from_RESET();
	VREF_0_enter_DefaultMode_from_RESET();
	SMBUS_0_enter_DefaultMode_from_RESET();
	INTERRUPT_0_enter_DefaultMode_from_RESET();
	// Restore the SFRPAGE
	SFRPAGE = SFRPAGE_save;
	// [Config Calls]$

}

extern void PCA_0_enter_DefaultMode_from_RESET(void) {
	// $[PCA0MD - PCA Mode]
	/***********************************************************************
	 - Disable Watchdog Timer
	 - System clock
	 - PCA continues to function normally while the system controller is in
	 Idle Mode
	 - Disable the CF interrupt
	 - Disable Watchdog Timer
	 - Watchdog Timer Enable unlocked
	 ***********************************************************************/
	SFRPAGE = 0x00;
	PCA0MD &= ~PCA0MD_WDTE__BMASK;
	PCA0MD = PCA0MD_CPS__SYSCLK | PCA0MD_CIDL__NORMAL
			| PCA0MD_ECF__OVF_INT_DISABLED | PCA0MD_WDTE__DISABLED
			| PCA0MD_WDLCK__UNLOCKED;
	// [PCA0MD - PCA Mode]$

	// $[PCA0H - PCA Counter/Timer High Byte]
	// [PCA0H - PCA Counter/Timer High Byte]$

	// $[PCA0L - PCA Counter/Timer Low Byte]
	// [PCA0L - PCA Counter/Timer Low Byte]$

	// $[PCA0PWM - PCA PWM Configuration]
	/***********************************************************************
	 - 10 bits
	 ***********************************************************************/
	PCA0PWM &= ~PCA0PWM_CLSEL__FMASK;
	PCA0PWM |= PCA0PWM_CLSEL__10_BITS;
	// [PCA0PWM - PCA PWM Configuration]$

	// $[PCA0CN0 - PCA Control 0]
	/***********************************************************************
	 - Start the PCA Counter/Timer running
	 ***********************************************************************/
	PCA0CN0 |= PCA0CN0_CR__RUN;
	// [PCA0CN0 - PCA Control 0]$

}

extern void PCACH_2_enter_DefaultMode_from_RESET(void) {
	// $[PCA0 Settings Save]
	// Select Capture/Compare register)
	//PCA0PWM &= ~PCA0PWM_ARSEL__BMASK;
	// [PCA0 Settings Save]$

	// $[PCA0CPM2 - PCA Channel 2 Capture/Compare Mode]
	/***********************************************************************
	 - Disable negative edge capture
	 - Disable CCF2 interrupts
	 - Enable match function
	 - 8 to 11-bit PWM selected
	 - Disable positive edge capture
	 - Disable comparator function
	 - Disable PWM function
	 - Disable toggle function
	 ***********************************************************************/
	PCA0CPM2 = PCA0CPM2_CAPN__DISABLED | PCA0CPM2_ECCF__DISABLED
			| PCA0CPM2_MAT__ENABLED | PCA0CPM2_PWM16__8_BIT
			| PCA0CPM2_CAPP__DISABLED | PCA0CPM2_ECOM__DISABLED
			| PCA0CPM2_PWM__DISABLED | PCA0CPM2_TOG__DISABLED;
	// [PCA0CPM2 - PCA Channel 2 Capture/Compare Mode]$

	// $[PCA0CPL2 - PCA Channel 2 Capture Module Low Byte]
	// [PCA0CPL2 - PCA Channel 2 Capture Module Low Byte]$

	// $[PCA0CPH2 - PCA Channel 2 Capture Module High Byte]
	// [PCA0CPH2 - PCA Channel 2 Capture Module High Byte]$

	// $[Auto-reload]
	// [Auto-reload]$

	// $[PCA0 Settings Restore]
	// [PCA0 Settings Restore]$

}

extern void PORTS_0_enter_DefaultMode_from_RESET(void) {
	// $[P0 - Port 0 Pin Latch]
	/***********************************************************************
	 - P0.0 is high. Set P0.0 to drive or float high
	 - P0.1 is high. Set P0.1 to drive or float high
	 - P0.2 is high. Set P0.2 to drive or float high
	 - P0.3 is high. Set P0.3 to drive or float high
	 - P0.4 is high. Set P0.4 to drive or float high
	 - P0.5 is high. Set P0.5 to drive or float high
	 - P0.6 is low. Set P0.6 to drive low
	 - P0.7 is high. Set P0.7 to drive or float high
	 ***********************************************************************/
	P0 = P0_B0__HIGH | P0_B1__HIGH | P0_B2__HIGH | P0_B3__HIGH | P0_B4__HIGH
			| P0_B5__HIGH | P0_B6__LOW | P0_B7__HIGH;
	// [P0 - Port 0 Pin Latch]$

	// $[P0MDOUT - Port 0 Output Mode]
	/***********************************************************************
	 - P0.0 output is open-drain
	 - P0.1 output is open-drain
	 - P0.2 output is open-drain
	 - P0.3 output is open-drain
	 - P0.4 output is open-drain
	 - P0.5 output is open-drain
	 - P0.6 output is push-pull
	 - P0.7 output is push-pull
	 ***********************************************************************/
	P0MDOUT = P0MDOUT_B0__OPEN_DRAIN | P0MDOUT_B1__OPEN_DRAIN
			| P0MDOUT_B2__OPEN_DRAIN | P0MDOUT_B3__OPEN_DRAIN
			| P0MDOUT_B4__OPEN_DRAIN | P0MDOUT_B5__OPEN_DRAIN
			| P0MDOUT_B6__PUSH_PULL | P0MDOUT_B7__PUSH_PULL;
	// [P0MDOUT - Port 0 Output Mode]$

	// $[P0MDIN - Port 0 Input Mode]
	/***********************************************************************
	 - P0.0 pin is configured for digital mode
	 - P0.1 pin is configured for analog mode
	 - P0.2 pin is configured for analog mode
	 - P0.3 pin is configured for analog mode
	 - P0.4 pin is configured for analog mode
	 - P0.5 pin is configured for analog mode
	 - P0.6 pin is configured for digital mode
	 - P0.7 pin is configured for digital mode
	 ***********************************************************************/
	P0MDIN = P0MDIN_B0__DIGITAL | P0MDIN_B1__ANALOG | P0MDIN_B2__ANALOG
			| P0MDIN_B3__ANALOG | P0MDIN_B4__ANALOG | P0MDIN_B5__ANALOG
			| P0MDIN_B6__DIGITAL | P0MDIN_B7__DIGITAL;
	// [P0MDIN - Port 0 Input Mode]$

	// $[P0SKIP - Port 0 Skip]
	/***********************************************************************
	 - P0.0 pin is skipped by the crossbar
	 - P0.1 pin is skipped by the crossbar
	 - P0.2 pin is skipped by the crossbar
	 - P0.3 pin is skipped by the crossbar
	 - P0.4 pin is skipped by the crossbar
	 - P0.5 pin is skipped by the crossbar
	 - P0.6 pin is skipped by the crossbar
	 - P0.7 pin is skipped by the crossbar
	 ***********************************************************************/
	P0SKIP = P0SKIP_B0__SKIPPED | P0SKIP_B1__SKIPPED | P0SKIP_B2__SKIPPED
			| P0SKIP_B3__SKIPPED | P0SKIP_B4__SKIPPED | P0SKIP_B5__SKIPPED
			| P0SKIP_B6__SKIPPED | P0SKIP_B7__SKIPPED;
	// [P0SKIP - Port 0 Skip]$

	// $[P0MASK - Port 0 Mask]
	// [P0MASK - Port 0 Mask]$

	// $[P0MAT - Port 0 Match]
	// [P0MAT - Port 0 Match]$

	// $[P0DRV - Port 0 Drive Strength]
	/***********************************************************************
	 - P0.0 output has low output drive strength
	 - P0.1 output has low output drive strength
	 - P0.2 output has low output drive strength
	 - P0.3 output has low output drive strength
	 - P0.4 output has low output drive strength
	 - P0.5 output has low output drive strength
	 - P0.6 output has high output drive strength
	 - P0.7 output has high output drive strength
	 ***********************************************************************/
	SFRPAGE = 0x0F;
	P0DRV = P0DRV_B0__LOW_DRIVE | P0DRV_B1__LOW_DRIVE | P0DRV_B2__LOW_DRIVE
			| P0DRV_B3__LOW_DRIVE | P0DRV_B4__LOW_DRIVE | P0DRV_B5__LOW_DRIVE
			| P0DRV_B6__HIGH_DRIVE | P0DRV_B7__HIGH_DRIVE;
	// [P0DRV - Port 0 Drive Strength]$

}

extern void PORTS_1_enter_DefaultMode_from_RESET(void) {
	// $[P1 - Port 1 Pin Latch]
	/***********************************************************************
	 - P1.0 is low. Set P1.0 to drive low
	 - P1.1 is high. Set P1.1 to drive or float high
	 - P1.2 is high. Set P1.2 to drive or float high
	 - P1.3 is high. Set P1.3 to drive or float high
	 - P1.4 is high. Set P1.4 to drive or float high
	 - P1.5 is high. Set P1.5 to drive or float high
	 - P1.6 is low. Set P1.6 to drive low
	 - P1.7 is low. Set P1.7 to drive low
	 ***********************************************************************/
	SFRPAGE = 0x00;
	P1 = P1_B0__LOW | P1_B1__HIGH | P1_B2__HIGH | P1_B3__HIGH | P1_B4__HIGH
			| P1_B5__HIGH | P1_B6__LOW | P1_B7__LOW;
	// [P1 - Port 1 Pin Latch]$

	// $[P1MDOUT - Port 1 Output Mode]
	/***********************************************************************
	 - P1.0 output is push-pull
	 - P1.1 output is open-drain
	 - P1.2 output is open-drain
	 - P1.3 output is push-pull
	 - P1.4 output is push-pull
	 - P1.5 output is open-drain
	 - P1.6 output is push-pull
	 - P1.7 output is push-pull
	 ***********************************************************************/
	P1MDOUT = P1MDOUT_B0__PUSH_PULL | P1MDOUT_B1__OPEN_DRAIN
			| P1MDOUT_B2__OPEN_DRAIN | P1MDOUT_B3__PUSH_PULL
			| P1MDOUT_B4__PUSH_PULL | P1MDOUT_B5__OPEN_DRAIN
			| P1MDOUT_B6__PUSH_PULL | P1MDOUT_B7__PUSH_PULL;
	// [P1MDOUT - Port 1 Output Mode]$

	// $[P1MDIN - Port 1 Input Mode]
	// [P1MDIN - Port 1 Input Mode]$

	// $[P1SKIP - Port 1 Skip]
	/***********************************************************************
	 - P1.0 pin is skipped by the crossbar
	 - P1.1 pin is not skipped by the crossbar
	 - P1.2 pin is not skipped by the crossbar
	 - P1.3 pin is not skipped by the crossbar
	 - P1.4 pin is not skipped by the crossbar
	 - P1.5 pin is not skipped by the crossbar
	 - P1.6 pin is not skipped by the crossbar
	 - P1.7 pin is not skipped by the crossbar
	 ***********************************************************************/
	P1SKIP = P1SKIP_B0__SKIPPED | P1SKIP_B1__NOT_SKIPPED
			| P1SKIP_B2__NOT_SKIPPED | P1SKIP_B3__NOT_SKIPPED
			| P1SKIP_B4__NOT_SKIPPED | P1SKIP_B5__NOT_SKIPPED
			| P1SKIP_B6__NOT_SKIPPED | P1SKIP_B7__NOT_SKIPPED;
	// [P1SKIP - Port 1 Skip]$

	// $[Missing Pin Skip]
	// [Missing Pin Skip]$

	// $[P1MASK - Port 1 Mask]
	// [P1MASK - Port 1 Mask]$

	// $[P1MAT - Port 1 Match]
	// [P1MAT - Port 1 Match]$

	// $[P1DRV - Port 1 Drive Strength]
	/***********************************************************************
	 - P1.0 output has high output drive strength
	 - P1.1 output has low output drive strength
	 - P1.2 output has low output drive strength
	 - P1.3 output has high output drive strength
	 - P1.4 output has high output drive strength
	 - P1.5 output has low output drive strength
	 - P1.6 output has low output drive strength
	 - P1.7 output has low output drive strength
	 ***********************************************************************/
	SFRPAGE = 0x0F;
	P1DRV = P1DRV_B0__HIGH_DRIVE | P1DRV_B1__LOW_DRIVE | P1DRV_B2__LOW_DRIVE
			| P1DRV_B3__HIGH_DRIVE | P1DRV_B4__HIGH_DRIVE | P1DRV_B5__LOW_DRIVE
			| P1DRV_B6__LOW_DRIVE | P1DRV_B7__LOW_DRIVE;
	// [P1DRV - Port 1 Drive Strength]$

}

extern void PBCFG_0_enter_DefaultMode_from_RESET(void) {
	// $[XBR2 - Port I/O Crossbar 2]
	/***********************************************************************
	 - Weak Pullups enabled 
	 - Crossbar enabled
	 ***********************************************************************/
	SFRPAGE = 0x00;
	XBR2 = XBR2_WEAKPUD__PULL_UPS_ENABLED | XBR2_XBARE__ENABLED;
	// [XBR2 - Port I/O Crossbar 2]$

	// $[XBR0 - Port I/O Crossbar 0]
	/***********************************************************************
	 - UART I/O unavailable at Port pin
	 - SPI I/O unavailable at Port pins
	 - SMBus 0 I/O routed to Port pins
	 - CP0 unavailable at Port pin
	 - Asynchronous CP0 unavailable at Port pin
	 - SYSCLK unavailable at Port pin
	 ***********************************************************************/
	XBR0 = XBR0_URT0E__DISABLED | XBR0_SPI0E__DISABLED | XBR0_SMB0E__ENABLED
			| XBR0_CP0E__DISABLED | XBR0_CP0AE__DISABLED
			| XBR0_SYSCKE__DISABLED;
	// [XBR0 - Port I/O Crossbar 0]$

	// $[XBR1 - Port I/O Crossbar 1]
	/***********************************************************************
	 - CEX0, CEX1 routed to Port pins
	 - ECI unavailable at Port pin
	 - T0 unavailable at Port pin
	 - T1 unavailable at Port pin
	 ***********************************************************************/
	XBR1 = XBR1_PCA0ME__CEX0_CEX1 | XBR1_ECIE__DISABLED | XBR1_T0E__DISABLED
			| XBR1_T1E__DISABLED;
	// [XBR1 - Port I/O Crossbar 1]$

}

extern void ADC_0_enter_DefaultMode_from_RESET(void) {
	// $[ADC0MX - ADC0 Multiplexer Selection]
	/***********************************************************************
	 - Select channel ADC0.5
	 ***********************************************************************/
	ADC0MX = ADC0MX_ADC0MX__ADC0P5;
	// [ADC0MX - ADC0 Multiplexer Selection]$

	// $[ADC0AC - ADC0 Accumulator Configuration]
	/***********************************************************************
	 - Perform and Accumulate 4 conversions 
	 - Enable 12-bit mode
	 - ADC0H:ADC0L contain the result of the latest conversion when Burst
	 Mode is disabled
	 - Right justified. No shifting applied
	 ***********************************************************************/
	ADC0AC = ADC0AC_ADRPT__ACC_4 | ADC0AC_AD12BE__12_BIT_ENABLED
			| ADC0AC_ADAE__ACC_DISABLED | ADC0AC_ADSJST__RIGHT_NO_SHIFT;
	// [ADC0AC - ADC0 Accumulator Configuration]$

	// $[ADC0TK - ADC0 Burst Mode Track Time]
	// [ADC0TK - ADC0 Burst Mode Track Time]$

	// $[ADC0PWR - ADC0 Power Control]
	/***********************************************************************
	 - Burst Mode Power Up Time = 0x02
	 - Disable low power mode
	 ***********************************************************************/
	ADC0PWR = (0x02 << ADC0PWR_ADPWR__SHIFT)
			| ADC0PWR_ADLPM__LOW_POWER_DISABLED;
	// [ADC0PWR - ADC0 Power Control]$

	// $[ADC0CF - ADC0 Configuration]
	/***********************************************************************
	 - ADC0 operates in 10-bit or 12-bit mode 
	 - The on-chip PGA gain is 1
	 - SAR Clock Divider = 0x02
	 - Delayed Track Mode
	 ***********************************************************************/
	ADC0CF = ADC0CF_AD8BE__NORMAL | ADC0CF_ADGN__GAIN_1
			| (0x02 << ADC0CF_ADSC__SHIFT) | ADC0CF_ADTM__TRACK_DELAYED;
	// [ADC0CF - ADC0 Configuration]$

	// $[ADC0GTH - ADC0 Greater-Than High Byte]
	/***********************************************************************
	 - Greater-Than High Byte = 0x00
	 ***********************************************************************/
	ADC0GTH = (0x00 << ADC0GTH_ADC0GTH__SHIFT);
	// [ADC0GTH - ADC0 Greater-Than High Byte]$

	// $[ADC0GTL - ADC0 Greater-Than Low Byte]
	/***********************************************************************
	 - Greater-Than Low Byte = 0x00
	 ***********************************************************************/
	ADC0GTL = (0x00 << ADC0GTL_ADC0GTL__SHIFT);
	// [ADC0GTL - ADC0 Greater-Than Low Byte]$

	// $[ADC0LTH - ADC0 Less-Than High Byte]
	// [ADC0LTH - ADC0 Less-Than High Byte]$

	// $[ADC0LTL - ADC0 Less-Than Low Byte]
	// [ADC0LTL - ADC0 Less-Than Low Byte]$

	// $[ADC0CN0 - ADC0 Control 0]
	/***********************************************************************
	 - Enable ADC0 
	 - Enable ADC0 burst mode
	 ***********************************************************************/
	ADC0CN0 |= ADC0CN0_ADEN__ENABLED | ADC0CN0_ADBMEN__BURST_ENABLED;
	// [ADC0CN0 - ADC0 Control 0]$

}

extern void PCACH_0_enter_DefaultMode_from_RESET(void) {
	// $[PCA0 Settings Save]
	// Select Capture/Compare register)
	//PCA0PWM &= ~PCA0PWM_ARSEL__BMASK;
	// [PCA0 Settings Save]$

	// $[PCA0CPM0 - PCA Channel 0 Capture/Compare Mode]
	/***********************************************************************
	 - Disable negative edge capture
	 - Disable CCF0 interrupts
	 - Disable match function
	 - 8 to 11-bit PWM selected
	 - Disable positive edge capture
	 - Enable comparator function
	 - Enable PWM function
	 - Disable toggle function
	 ***********************************************************************/
	PCA0CPM0 = PCA0CPM0_CAPN__DISABLED | PCA0CPM0_ECCF__DISABLED
			| PCA0CPM0_MAT__DISABLED | PCA0CPM0_PWM16__8_BIT
			| PCA0CPM0_CAPP__DISABLED | PCA0CPM0_ECOM__ENABLED
			| PCA0CPM0_PWM__ENABLED | PCA0CPM0_TOG__DISABLED;
	// [PCA0CPM0 - PCA Channel 0 Capture/Compare Mode]$

	// $[PCA0CPL0 - PCA Channel 0 Capture Module Low Byte]
	// [PCA0CPL0 - PCA Channel 0 Capture Module Low Byte]$

	// $[PCA0CPH0 - PCA Channel 0 Capture Module High Byte]
	// [PCA0CPH0 - PCA Channel 0 Capture Module High Byte]$

	// $[Auto-reload]
	PCA0PWM |= PCA0PWM_ARSEL__AUTORELOAD;

	//PCA0PWM &= ~PCA0PWM_ARSEL__BMASK;
	// [Auto-reload]$

	// $[PCA0 Settings Restore]
	// [PCA0 Settings Restore]$

}

extern void PCACH_1_enter_DefaultMode_from_RESET(void) {
	// $[PCA0 Settings Save]
	// Select Capture/Compare register)
	//PCA0PWM &= ~PCA0PWM_ARSEL__BMASK;
	// [PCA0 Settings Save]$

	// $[PCA0CPM1 - PCA Channel 1 Capture/Compare Mode]
	/***********************************************************************
	 - Disable negative edge capture
	 - Disable CCF1 interrupts
	 - Disable match function
	 - 8 to 11-bit PWM selected
	 - Disable positive edge capture
	 - Enable comparator function
	 - Enable PWM function
	 - Disable toggle function
	 ***********************************************************************/
	PCA0CPM1 = PCA0CPM1_CAPN__DISABLED | PCA0CPM1_ECCF__DISABLED
			| PCA0CPM1_MAT__DISABLED | PCA0CPM1_PWM16__8_BIT
			| PCA0CPM1_CAPP__DISABLED | PCA0CPM1_ECOM__ENABLED
			| PCA0CPM1_PWM__ENABLED | PCA0CPM1_TOG__DISABLED;
	// [PCA0CPM1 - PCA Channel 1 Capture/Compare Mode]$

	// $[PCA0CPL1 - PCA Channel 1 Capture Module Low Byte]
	// [PCA0CPL1 - PCA Channel 1 Capture Module Low Byte]$

	// $[PCA0CPH1 - PCA Channel 1 Capture Module High Byte]
	// [PCA0CPH1 - PCA Channel 1 Capture Module High Byte]$

	// $[Auto-reload]
	PCA0PWM |= PCA0PWM_ARSEL__AUTORELOAD;

	//PCA0PWM &= ~PCA0PWM_ARSEL__BMASK;
	// [Auto-reload]$

	// $[PCA0 Settings Restore]
	// [PCA0 Settings Restore]$

}

extern void VREG_0_enter_DefaultMode_from_RESET(void) {
	// $[REG0CN - Voltage Regulator Control]
	/***********************************************************************
	 - Enable the precision High Frequency Oscillator bias
	 ***********************************************************************/
	REG0CN = REG0CN_OSCBIAS__ENABLED;
	// [REG0CN - Voltage Regulator Control]$

}

extern void RSTSRC_0_enter_DefaultMode_from_RESET(void) {
	// $[RSTSRC - Reset Source]
	/***********************************************************************
	 - A power-on or supply monitor reset occurred
	 - A missing clock detector reset did not occur
	 - A Comparator 0 reset did not occur
	 - A RTC alarm or oscillator fail reset did not occur
	 ***********************************************************************/
	RSTSRC = RSTSRC_PORSF__SET | RSTSRC_MCDRSF__NOT_SET | RSTSRC_C0RSEF__NOT_SET
			| RSTSRC_RTC0RE__NOT_SET;
	// [RSTSRC - Reset Source]$

}

extern void HFOSC_0_enter_DefaultMode_from_RESET(void) {
	// $[HFO#CAL - High Frequency Oscillator Calibration]
	// [HFO#CAL - High Frequency Oscillator Calibration]$

	// $[HFO#CN - High Frequency Oscillator Control]
	/***********************************************************************
	 - High Frequency Oscillator enabled
	 ***********************************************************************/
	HFO0CN |= HFO0CN_IOSCEN__ENABLED;
	// [HFO#CN - High Frequency Oscillator Control]$

	// $[Oscillator Ready]
	while ((HFO0CN & HFO0CN_IFRDY__BMASK) == HFO0CN_IFRDY__NOT_SET)
		;
	// [Oscillator Ready]$

}

extern void CLOCK_0_enter_DefaultMode_from_RESET(void) {
	// $[CLKSEL - Clock Select]
	/***********************************************************************
	 - SYSCLK is equal to selected clock source divided by 1
	 - Clock derived from the internal precision High-Frequency Oscillator
	 ***********************************************************************/
	CLKSEL = CLKSEL_CLKDIV__SYSCLK_DIV_1 | CLKSEL_CLKSL__HFOSC;
	// Wait for the clock to be ready
	while ((CLKSEL & CLKSEL_CLKRDY__BMASK) != CLKSEL_CLKRDY__SET)
		;
	// [CLKSEL - Clock Select]$

}

extern void TIMER01_0_enter_DefaultMode_from_RESET(void) {
	// $[Timer Initialization]
	//Save Timer Configuration
	uint8_t TCON_save;
	TCON_save = TCON;
	//Stop Timers
	TCON &= ~TCON_TR0__BMASK & ~TCON_TR1__BMASK;

	// [Timer Initialization]$

	// $[TH0 - Timer 0 High Byte]
	/***********************************************************************
	 - Timer 0 High Byte = 0x80
	 ***********************************************************************/
	TH0 = (0x80 << TH0_TH0__SHIFT);
	// [TH0 - Timer 0 High Byte]$

	// $[TL0 - Timer 0 Low Byte]
	// [TL0 - Timer 0 Low Byte]$

	// $[TH1 - Timer 1 High Byte]
	// [TH1 - Timer 1 High Byte]$

	// $[TL1 - Timer 1 Low Byte]
	// [TL1 - Timer 1 Low Byte]$

	// $[Timer Restoration]
	//Restore Timer Configuration
	TCON |= (TCON_save & TCON_TR0__BMASK) | (TCON_save & TCON_TR1__BMASK);

	// [Timer Restoration]$

}

extern void TIMER16_2_enter_DefaultMode_from_RESET(void) {
	// $[Timer Initialization]
	// Save Timer Configuration
	uint8_t TMR2CN0_TR2_save;
	TMR2CN0_TR2_save = TMR2CN0 & TMR2CN0_TR2__BMASK;
	// Stop Timer
	TMR2CN0 &= ~(TMR2CN0_TR2__BMASK);
	// [Timer Initialization]$

	// $[TMR2CN0 - Timer 2 Control]
	// [TMR2CN0 - Timer 2 Control]$

	// $[TMR2H - Timer 2 High Byte]
	/***********************************************************************
	 - Timer 2 High Byte = 0xB0
	 ***********************************************************************/
	TMR2H = (0xB0 << TMR2H_TMR2H__SHIFT);
	// [TMR2H - Timer 2 High Byte]$

	// $[TMR2L - Timer 2 Low Byte]
	/***********************************************************************
	 - Timer 2 Low Byte = 0x3F
	 ***********************************************************************/
	TMR2L = (0x3F << TMR2L_TMR2L__SHIFT);
	// [TMR2L - Timer 2 Low Byte]$

	// $[TMR2RLH - Timer 2 Reload High Byte]
	/***********************************************************************
	 - Timer 2 Reload High Byte = 0xB0
	 ***********************************************************************/
	TMR2RLH = (0xB0 << TMR2RLH_TMR2RLH__SHIFT);
	// [TMR2RLH - Timer 2 Reload High Byte]$

	// $[TMR2RLL - Timer 2 Reload Low Byte]
	/***********************************************************************
	 - Timer 2 Reload Low Byte = 0x3F
	 ***********************************************************************/
	TMR2RLL = (0x3F << TMR2RLL_TMR2RLL__SHIFT);
	// [TMR2RLL - Timer 2 Reload Low Byte]$

	// $[TMR2CN0]
	/***********************************************************************
	 - Start Timer 2 running
	 ***********************************************************************/
	TMR2CN0 |= TMR2CN0_TR2__RUN;
	// [TMR2CN0]$

	// $[Timer Restoration]
	// Restore Timer Configuration
	TMR2CN0 |= TMR2CN0_TR2_save;
	// [Timer Restoration]$

}

extern void TIMER_SETUP_0_enter_DefaultMode_from_RESET(void) {
	// $[CKCON0 - Clock Control 0]
	/***********************************************************************
	 - System clock divided by 48
	 - Counter/Timer 0 uses the clock defined by the prescale field, SCA
	 - Timer 2 high byte uses the clock defined by T2XCLK in TMR2CN0
	 - Timer 2 low byte uses the clock defined by T2XCLK in TMR2CN0
	 - Timer 3 high byte uses the clock defined by T3XCLK in TMR3CN0
	 - Timer 3 low byte uses the clock defined by T3XCLK in TMR3CN0
	 - Timer 1 uses the clock defined by the prescale field, SCA
	 ***********************************************************************/
	CKCON0 = CKCON0_SCA__SYSCLK_DIV_48 | CKCON0_T0M__PRESCALE
			| CKCON0_T2MH__EXTERNAL_CLOCK | CKCON0_T2ML__EXTERNAL_CLOCK
			| CKCON0_T3MH__EXTERNAL_CLOCK | CKCON0_T3ML__EXTERNAL_CLOCK
			| CKCON0_T1M__PRESCALE;
	// [CKCON0 - Clock Control 0]$

	// $[TMOD - Timer 0/1 Mode]
	/***********************************************************************
	 - Mode 2, 8-bit Counter/Timer with Auto-Reload
	 - Mode 0, 13-bit Counter/Timer
	 - Timer Mode
	 - Timer 0 enabled when TR0 = 1 irrespective of INT0 logic level
	 - Timer Mode
	 - Timer 1 enabled when TR1 = 1 irrespective of INT1 logic level
	 ***********************************************************************/
	TMOD = TMOD_T0M__MODE2 | TMOD_T1M__MODE0 | TMOD_CT0__TIMER
			| TMOD_GATE0__DISABLED | TMOD_CT1__TIMER | TMOD_GATE1__DISABLED;
	// [TMOD - Timer 0/1 Mode]$

	// $[TCON - Timer 0/1 Control]
	// [TCON - Timer 0/1 Control]$

}

extern void VREF_0_enter_DefaultMode_from_RESET(void) {
	// $[REF0CN - Voltage Reference Control]
	/***********************************************************************
	 - Enable the Temperature Sensor
	 - The ADC0 ground reference is the GND pin
	 - The ADC0 voltage reference is the internal 1.65 V high speed voltage
	 reference
	 ***********************************************************************/
	REF0CN = REF0CN_TEMPE__TEMP_ENABLED | REF0CN_GNDSL__GND_PIN
			| REF0CN_REFSL__HIGH_SPEED_VREF;
	// [REF0CN - Voltage Reference Control]$

}

extern void SMBUS_0_enter_DefaultMode_from_RESET(void) {
	// $[SMB0ADR - SMBus 0 Slave Address]
	/***********************************************************************
	 - General Call Address is ignored
	 - SMBus Hardware Slave Address = 0x12
	 ***********************************************************************/
	SMB0ADR = SMB0ADR_GC__IGNORED | (0x12 << SMB0ADR_SLV__SHIFT);
	// [SMB0ADR - SMBus 0 Slave Address]$

	// $[SMB0ADM - SMBus 0 Slave Address Mask]
	/***********************************************************************
	 - Automatic slave address recognition and hardware acknowledge is
	 enabled
	 - SMBus Slave Address Mask = 0x7F
	 ***********************************************************************/
	SMB0ADM = SMB0ADM_EHACK__ADR_ACK_AUTOMATIC | (0x7F << SMB0ADM_SLVM__SHIFT);
	// [SMB0ADM - SMBus 0 Slave Address Mask]$

	// $[SMB0CF - SMBus 0 Configuration]
	/***********************************************************************
	 - Timer 1 Overflow
	 - Enable the SMBus module
	 ***********************************************************************/
	SMB0CF &= ~SMB0CF_SMBCS__FMASK;
	SMB0CF |= SMB0CF_SMBCS__TIMER1 | SMB0CF_ENSMB__ENABLED;
	// [SMB0CF - SMBus 0 Configuration]$

}

extern void INTERRUPT_0_enter_DefaultMode_from_RESET(void) {
	// $[EIE1 - Extended Interrupt Enable 1]
	/***********************************************************************
	 - Disable ADC0 Conversion Complete interrupt
	 - Disable ADC0 Window Comparison interrupt
	 - Disable CP0 interrupts
	 - Disable all PCA0 interrupts
	 - Disable RTC Alarm interrupts
	 - Enable interrupt requests generated by SMB0
	 - Disable Timer 3 interrupts
	 ***********************************************************************/
	EIE1 = EIE1_EADC0__DISABLED | EIE1_EWADC0__DISABLED | EIE1_ECP0__DISABLED
			| EIE1_EPCA0__DISABLED | EIE1_ERTC0A__DISABLED | EIE1_ESMB0__ENABLED
			| EIE1_ET3__DISABLED;
	// [EIE1 - Extended Interrupt Enable 1]$

	// $[EIP1 - Extended Interrupt Priority 1]
	/***********************************************************************
	 - ADC0 Conversion Complete interrupt set to low priority level
	 - ADC0 Window interrupt set to low priority level
	 - CP0 interrupt set to low priority level
	 - PCA0 interrupt set to low priority level
	 - RTC Alarm interrupt set to low priority level
	 - SMB0 interrupt set to high priority level
	 - Timer 3 interrupts set to low priority level
	 ***********************************************************************/
	EIP1 = EIP1_PADC0__LOW | EIP1_PWADC0__LOW | EIP1_PCP0__LOW | EIP1_PPCA0__LOW
			| EIP1_PRTC0A__LOW | EIP1_PSMB0__HIGH | EIP1_PT3__LOW;
	// [EIP1 - Extended Interrupt Priority 1]$

	// $[IE - Interrupt Enable]
	/***********************************************************************
	 - Enable each interrupt according to its individual mask setting
	 - Disable external interrupt 0
	 - Disable external interrupt 1
	 - Disable all SPI0 interrupts
	 - Enable interrupt requests generated by the TF0 flag
	 - Disable all Timer 1 interrupt
	 - Enable interrupt requests generated by the TF2L or TF2H flags
	 - Disable UART0 interrupt
	 ***********************************************************************/
	IE = IE_EA__ENABLED | IE_EX0__DISABLED | IE_EX1__DISABLED
			| IE_ESPI0__DISABLED | IE_ET0__ENABLED | IE_ET1__DISABLED
			| IE_ET2__ENABLED | IE_ES0__DISABLED;
	// [IE - Interrupt Enable]$

	// $[IP - Interrupt Priority]
	// [IP - Interrupt Priority]$

	// $[EIE2 - Extended Interrupt Enable 2]
	// [EIE2 - Extended Interrupt Enable 2]$

	// $[EIP2 - Extended Interrupt Priority 2]
	// [EIP2 - Extended Interrupt Priority 2]$

}

extern void FLASH_0_enter_DefaultMode_from_RESET(void) {
	// $[FLSCL - Flash Scale]
	/***********************************************************************
	 - The system clock determines the flash read time
	 ***********************************************************************/
	FLSCL = FLSCL_BYPASS__SYSCLK;
	// [FLSCL - Flash Scale]$

}
