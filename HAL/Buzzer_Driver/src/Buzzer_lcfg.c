/*
 * HR_sensor_lcdg.c
 *
 *  Created on: May 9, 2021
 *      Author: Toaa & Ghada
 */

#include "Buzzer_cfg.h"
#include "Buzzer_lcfg.h"
#include "Buzzer.h"

#include "GPIO.h"
#include "GPIO_Lcfg.h"

void Buzzer_Cycle_Complete_Callback(void)
{
	//GPIO_WriteOutputPin(BLUE_LED,1);

	static uint8_t counter = 0;

	counter ++;

	if(counter == 1)
	{
		Buzzer_Req(  2 ,  1 ,  1 ,   MEDIUM_POWER);
	}
	else if(counter == 2)
	{
		Buzzer_Req(  2,  1 ,  1 ,   MAXIMUM_POWER);
	}

}

Buzzer_Config_t Buzzer_ConfigArray[NUMBER_OF_CONFIGURED_BUZZER] =
{
		{ BUZZER1_PREPH_ID , BUZZER1_CH_ID , Buzzer_Cycle_Complete_Callback}
};
