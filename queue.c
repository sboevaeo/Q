#include <stdio.h> 
#include <locale.h> // для отображения русского языка в консоли
#include <stdint.h> // для типа uint32_t

#define OK		(0)
#define ERROR	(1)

#define MAXN 4 /**< максимальное количество элементов в очереди (-1)*/

#define UINT32 uint32_t
typedef UINT32 STATUS;

UINT32 element; /** переменная для получения */
/** структура очереди*/
struct queue
{
	UINT32 MyQueue[MAXN]; /**< создаем массив*/
	UINT32 first_element; /**< позиция первого элемента в очереди*/
	UINT32 last_element; /**< позиция последнего элемента в очереди*/
};
/** создатель очереди*/
void init(struct queue *q)
{
	q->first_element = 1;
	q->last_element = 0;
}
/** добавление элемента x в очередь*/
STATUS queueAdd(struct queue *q, int x)
{
	if (q->last_element< MAXN - 1){
		q->last_element++;
		q->MyQueue[q->last_element] = x;
		return OK;
	}
	else {
		return ERROR;
	}
}
/** проверка пустоты очереди 1- пуста, 0 - не пуста*/
STATUS isempty(struct queue *q)
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
STATUS queueGet(struct queue *q)
{
	if (!isempty(q)){
		element = q->MyQueue[q->first_element];
		return OK;
	}
	else {
		return ERROR;
	}
}
/** Удалить элемент */
STATUS queuePop(struct queue *q)
{
	if (!isempty(q)){
		UINT32 i;
		for (i = 0; i < q->last_element; i++){
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
	UINT32 comm;
	UINT32 x;
	init(&Q);
	/** Вывод инструкций */
	printf("введите код действия : \n");
	printf("0 - добавить элемент\n");
	printf("1 - получение элемента из очереди\n");
	printf("2 - удалить элемент из очереди\n");
	printf("3 - очистить очередь\n");
	while (1){
		if (scanf_s("%u", &comm) && (comm <= 3 && comm >= 0)){
			fflush(stdin); // необходимо для очистки стандартного ввода
			switch (comm)
			{
			case 0:
				printf("введите элемент (тип данных UINT32):\n");
				/** Проверяем, что введенное соответствует типу int*/
				if (scanf_s("%u", &x)){
					fflush(stdin); // необходимо для очистки стандартного ввода
					if (queueAdd(&Q, x)){
						printf("очередь переполнена. элемент не добавлен.\n");
					}
					else{
						printf("ваш элемент в очереди.\n");
					}
				}
				else{
					printf("было введено не число. добавление не выполнено.\n");
				}
				break;
			case 1:
				if (queueGet(&Q) != ERROR){
					printf("%d- первый элемент в очереди.\n", element);
				}
				else{
					printf("очередь пуста  - получение невозможно.\n");
				}
				break;
			case 2:
				if (!isempty(&Q)){
					printf("элемент удален.\n");
				}
				else{
					printf("очередь и так пуста.\n");
				}
				queuePop(&Q);
				break;
			case 3:
				if (!isempty(&Q)){
					queueClear(&Q);
					printf("очередь очищена.\n");
				}
				else{
					printf("очередь пуста.\n");
				}
				break;
			default:
				break;
			}
		}
		else{
			fflush(stdin); // необходимо для очистки стандартного ввода
			printf("код инструкции не опознан. попробуйте еще раз.\n");
		}
	}
	return 0;
}
