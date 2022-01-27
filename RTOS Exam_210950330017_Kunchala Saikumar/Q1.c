/* Q1. Create 3 real time tasks each with periodicity T1=1000ms, T2=2000ms, T3=5000ms. Also create two additional tasks T4 and T5 where T4 sends integer data to T5 using message queues.

Task priorities:  T1,T2,T3,T4,T5 have priorities 5,6,7,8,9 respectively*/

#include<stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<freertos/timers.h>
#include<freertos/queue.h>

TaskHandle_t xTask1,xTask2,xTask3,xTask4,xTask5;
QueueHandle_t Task4_Queue,Task5_Queue;

void app_main()
{
	
	BaseType_t result1,result2,result3,result4,result5;
	printf("Hello DESD\n");
	result1=xTaskCreate(Task1,"Task1",1024,NULL,5,&xTask1);
	result2=xTaskCreate(Task2,"Task2",1024,NULL,6,&xTask2);
	result3=xTaskCreate(Task3,"Task3",1024,NULL,7,&xTask3);
	result4=xTaskCreate(Task4,"Task4",1024,NULL,8,&xTask4);
	result5=xTaskCreate(Task5,"Task5",1024,NULL,9,&xTask5);
	
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

	if(result4==pdPASS)
	{
		printf("Task4 created successfully\n");		
	}

	if(result5==pdPASS)
	{
		printf("Task5 created successfully\n");		
	}

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
		printf("Tas3 is under execution\n");
		vTaskDelay(5000 / portTICK_PERIOD_MS);

		vTaskDelete(Task3);
	}

	void Task4(void *pvParameters)
	{
		int send_data=10;
		printf("Tas4 is under execution\n");	
		
	while(1)
	{
		send_data++;
		xQueueSend(Task4_Queue,&send_data,portMAX_DELAY);
		printf("Tas4 data sent : %d\n",send_data);
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}

		vTaskDelete(Task4);
	}

	void Task5(void *pvParameters)
	{
		int receive_data=0;
		printf("Tas5 is under execution\n");
	while(1)
	{
		xQueueReceive(Task5_Queue,&receive_data,portMAX_DELAY);
		printf("Tas5 data received : %d\n",receive_data);
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}

		vTaskDelete(Task5);
	}













