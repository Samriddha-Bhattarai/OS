#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 3, x = 0;

void wait()
{
--mutex;
}

void signal()
{
++mutex;
}

void producer()
{
wait();
++full;
--empty;
x++;

printf("Producer has produced: Item %d\n", x);

signal();
}

void consumer()
{
wait();
--full;
++empty;

printf("Consumer has consumed: Item %d\n", x);

x--;
signal();
}

void main()
{
int n;

while (1)
{
printf("\nEnter 1.Producer 2.Consumer 3.Exit\n");
printf("Enter your choice:\n");
scanf("%d", &n);

switch (n)
{
case 1:
if ((mutex == 1) && (empty != 0))
producer();
else
printf("Buffer is full!\n");
break;

case 2:
if ((mutex == 1) && (full != 0))
consumer();
else
printf("Buffer is empty!\n");
break;

case 3:
exit(0);

default:
printf("Invalid choice!\n");
}
}

getch();
}
