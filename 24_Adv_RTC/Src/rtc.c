/*
 * rtc.c
 *
 *  Created on: 23-Jan-2026
 *      Author: mathe
 */
#include "rtc.h"


void rtc_init(void)
{
	/*Enable Power Clock*/
	/*Enable Backup Access to configure RTC */
	/*Enable LOW SPEED INTERNAL (LSI)*/ //Why lsi and why not others
	/*Wait for LSI to be ready*/
	/*Force Backup Domain to reset*/ // why reset and what if not reset
	/*Release backup domain reset*/
	/*Set RTC clock source to LSI*/
	/*Enable the RTC*/
	/*Disable RTC Registers write Protection*/ // why
	/*Enter the Initilization Mode*/
	/*Set Desired Date*/
	/*Set Desired Time*/
	/*Set Hour Format*/
	/*Set Async Prescaler*/ // what is async and sync
	/*Set sync Prescaler*/
	/*Exit Initilization Mode*/
	/*Enable RTC registers write protection*/ // what is this and why
}

