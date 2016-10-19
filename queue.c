#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>

#define OK (0)
#define ERROR (1)

#define MAXN 101/**< максимальное количество элементов в очереди (-1)*/


/** структура очереди*/
struct queue
{
	int MyQueue[MAXN]; /**< создаем массив*/
	int first_element; /**< позици¤ первого элемента в очереди*/
	int last_element; /**< позици¤ последнего элемента в очереди*/
};
/** создатель очереди*/
void init(struct queue *q)
{
	q->first_element = 1;
	q->last_element = 0;
}
/** добавление элемента x в очередь*/
int queueAdd(struct queue *q, int x)
{
	if (q->last_element< MAXN-1){
		q->last_element++;
		q->MyQueue[q->last_element] = x;
		return OK;
	}
	else {
		return ERROR;
	}
}
/** проверка пустоты очереди 1- пуста, 0 - не пуста*/
int isempty(struct queue *q)
{
	if (q->last_element<q->first_element)
	{
		return ERROR;
	}
	else
	{
		return OK;
	}
}
/** получение элемента из очереди*/
int queueGet(struct queue *q)
{
	if (!isempty(q)){
		int element; /** переменная для получения */
		element = q->MyQueue[q->first_element];
		queuePop(q);
		return element;
	}
	else {
		return NULL;
	}
}
/** Удалить элемент */
int queuePop(struct queue *q)
{
	if (!isempty(q)){
		for (int i = 0; i < q->last_element; i++){
			q->MyQueue[i] = q->MyQueue[i + 1];
		}
		q->last_element--;
		if (q->first_element > 1){
			q->first_element--;
		}
		return OK;
	}
	else
	{
		return ERROR;
	}
}
/** Очистить очередь */
void queueClear(struct queue *q)
{
	while (!isempty(q)){
		queuePop(q);
	}
}
/** описание структуры очереди закончено */

int main()
{
	setlocale(LC_ALL, "RUS");
	struct queue Q;
	int comm;
	int x;
	init(&Q);
	/** Вывод инструкций */
	printf("Введите код действия: \n");
	printf("0 - добавить элемент\n");
	printf("1 - получение элемента из очереди\n");
	printf("2 - удалить элемент из очереди\n");
	printf("3 - очистить очередь\n");
	while (1){
		scanf_s("%d", &comm);
		switch (comm)
		{
		case 0:
			printf("Введите элемент:\n");
			/** Проверяем, что введенное соответствует типу int*/
			if (scanf_s("%d", &x)){ 
				if (queueAdd(&Q, x)){ 
					printf("Очередь переполнена. Элемент не добавлен.\n");
				}
				else{
					printf("Ваш элемент в очереди.\n");
				}
			}
			else{ 
				fflush(stdin); /** необходимо для очистки стандартного ввода*/
				printf("Было введено не целое число. Добавление не выполнено.\n"); 
			}
			break;
		case 1:
			x = queueGet(&Q);
			if (x!=NULL){
				printf("%d- был первым элементом в очереди.\n", x);
			}
			else{
				printf("очередь пуста  - получение невозможно.\n");
			}
			break;
		case 2:
			if (!isempty(&Q)){
				printf("Элемент удален.\n");
			}
			else{
				printf("очередь и так пуста.\n");
			}
			queuePop(&Q);
			break;
		case 3:
			if (!isempty(&Q)){
				queueClear(&Q);
			}
			else{
				printf("Очередь пуста.\n");
			}
			break;
		default:
			printf("Код инструкции не опознан. Попробуйте еще раз.\n");
			break;
		}
	}
	return 0;
}
