/* Q2. Create 3 real time tasks each with periodicity T1=1000ms, T2=2000ms, T3=5000ms. Also create use oneshot software timer to trigger a callback function from T3 after 1000ms*/

#include<stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<freertos/timers.h>
#include<freertos/queue.h>

TaskHandle_t xTask1,xTask2,xTask3;

TimerHandle_t Task3_timer_handle;


void app_main()
{
	
	BaseType_t result1,result2,result3;
	printf("Hello DESD\n");
	result1=xTaskCreate(Task1,"Task1",1024,NULL,5,&xTask1);
	result2=xTaskCreate(Task2,"Task2",1024,NULL,6,&xTask2);
	result3=xTaskCreate(Task3,"Task3",1024,NULL,7,&xTask3);
	
	
	if(result1==pdPASS)
	{
		printf("Task1 created successfully\n");	
	}

	if(result2==pdPASS)
	{
		printf("Task2 created successfully\n");		
	}
	
	if(result3==pdPASS)
	{
		printf("Task3 created successfully\n");		
	}

	Task3_timer_handle=xTimerCreate("Callback_trigger_Task3",pdMS_TO_TICKS(1000),pdTRUE,NULL,Task3);
	xTimerStart(Task3_timer_handle,0);

}


	void Task1(void *pvParameters)
	{
		printf("Tas1 is under execution\n");
		vTaskDelay(1000 / portTICK_PERIOD_MS);


		vTaskDelete(Task1);
	}

	void Task2(void *pvParameters)
	{
		printf("Tas2 is under execution\n");
		vTaskDelay(2000 / portTICK_PERIOD_MS);

		vTaskDelete(Task2);
	}

	void Task3(void *pvParameters)
	{	
		int count=0;
		printf("Tas3 is under execution\n");
		vTaskDelay(5000 / portTICK_PERIOD_MS);

		
		xTimerStop(Task3_timer_handle,0);

		vTaskDelete(Task3);
	}














