#include "pico/stdlib.h"
#include <stdio.h>
#include <stdlib.h>

#define LED4 5
#define LED3 3
#define LED2 6
#define LED1 8

#define btn1 18
#define btn2 22
#define btn3 27
#define btn4 28

void triggerLed(int button, int led){
    if(gpio_get(button) != 1){  
            gpio_put(led,1);
        }
    else{
            gpio_put(led,0);
    }
}

void print_bin(unsigned char value)
{
    for (int i = sizeof(char) * 7; i >= 0; i--)
        printf("%d", (value & (1 << i)) >> i );
    putc('\n', stdout);
}

void blink_led(int led, int time_interval){
    gpio_put(led,1);
    //printf("Hello, world!\n");
    sleep_ms(time_interval);
    gpio_put(led,0);
    sleep_ms(time_interval);
}

int* populate_array(int array_size){

    int *myArr = (int*)malloc(sizeof(int)*array_size); //dynamically allocating an array due to increasing array size
    for(int i = 0; i < array_size; i++){
        myArr[i] = rand() % 4;
    }
    return myArr;
}

void choose_led(int rand_num, int time_space){
    switch(rand_num){
        case 0:{
            blink_led(LED1, time_space);
        }
        case 1:{
            blink_led(LED2, time_space);
        }
        case 2:{
            blink_led(LED3, time_space);
        }
        case 3:{
            blink_led(LED4, time_space);
        }
    }
}

void detect_sequence(){
    while(1){
        
    }
}

int main(){
    
    stdio_init_all();

    gpio_init(LED1);
    gpio_set_dir(LED1, GPIO_OUT);
    gpio_init(LED2);
    gpio_set_dir(LED2, GPIO_OUT);
    gpio_init(LED3);
    gpio_set_dir(LED3, GPIO_OUT);
    gpio_init(LED4);
    gpio_set_dir(LED4, GPIO_OUT);

    gpio_init(btn1);
    gpio_set_dir(btn1, GPIO_IN);
    gpio_pull_up(btn1);
    gpio_init(btn2);
    gpio_set_dir(btn2, GPIO_IN);
    gpio_pull_up(btn2);
    gpio_init(btn3);
    gpio_set_dir(btn3, GPIO_IN);
    gpio_pull_up(btn3);
    gpio_init(btn4);
    gpio_set_dir(btn4, GPIO_IN);
    gpio_pull_up(btn4);


    int rand_num; //seed a random number from 0-3
    int *rand_array;
    int temp_array_elements = 1; //we want to start with 1 element
    int time_space = 1000;
    int MyGPIO;

    while(1){
    
        rand_array = populate_array(temp_array_elements);

        for(int i = 0; i < 8; i++){
            choose_led(rand_array[i], time_space);
        }

        detect_sequence(*rand_array); //comparing btn pushes with LED lighting sequence

        free(rand_array);
        temp_array_elements++;
    }
}

