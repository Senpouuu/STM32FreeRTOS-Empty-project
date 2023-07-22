/* User includes. */
#include "stm32f10x.h"                  // Device header
#include "Serial.h"

/* Standard includes. */
#include <stdio.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"




static void prvSetupHardware(void)
{
	Serial_Init();
}



void Task1Function(void * param)
{
	while (1)
	{
		printf("Hello World!");
	}
}


int main(void)
{
	prvSetupHardware();

	xTaskCreate(Task1Function, "Task1", 100, NULL, 1, NULL);

	vTaskStartScheduler();

	return 0;
	

}

