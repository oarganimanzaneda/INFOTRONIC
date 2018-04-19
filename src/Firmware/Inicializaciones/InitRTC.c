#include <Aplicacion.h>

#define RTC_SET_TIME 0

void initRTC()
{
	if(LPC_RTC->RTC_AUX.OSCF)			// RTC Oscillator Fail detect flag.
	{
		LPC_RTC->RTC_AUX.OSCF = 1;		// clear flag
		PCONP->RTC = 1;					// power control periferic rtc
//		LPC_RTC->CCR_.CLKEN = 0;		// The time counters are disabled so that they may be initialized.
//		LPC_RTC->CCR_.CTCRST = 1;		// the elements in the internal oscillator divider are reset
//		LPC_RTC->CCR_.CCALEN = 1;		// The calibration counter is disabled and reset to zero
		LPC_RTC->CCR = 0b10010;
		LPC_RTC->CALIBRATION = 0x0;
		LPC_RTC->CCR_.CTCRST = 0;		// remain reset until CCR[1] is changed to zero -> lo pongo a 0
		LPC_RTC->CCR_.CLKEN = 1;		// The time counters are enabled
		LPC_RTC->RTC_AUXEN.OSCFEN = 1;	// the RTC Oscillator Fail detect interrupt is enabled
	}
#if RTC_SET_TIME

	LPC_RTC->YEAR = 2018;
	LPC_RTC->MONTH = 4;
	LPC_RTC->DOY = 101;
	LPC_RTC->DOM = 11;
	LPC_RTC->DOW = 3;
	LPC_RTC->HOUR = 22;
	LPC_RTC->MIN = 15;
	LPC_RTC->SEC = 0;

	LPC_RTC->GPREG0 = 20180411;
	LPC_RTC->GPREG1 = 221500;
	LPC_RTC->GPREG2 = 0;
	LPC_RTC->GPREG3 = 0;
	LPC_RTC->GPREG4 = 0;

#endif

}
