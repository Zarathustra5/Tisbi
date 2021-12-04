#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//Тип(запись)
struct QueueItem
{
  char info[80];
  struct QueueItem *next;
};

//Объявление переменных
int answer;
_Bool isProgramActive = true;
struct QueueItem *pFirst, *pLast, *pTemp;

int main()
{
  pFirst = NULL;
  pLast = NULL;
  //Зацикливание меню
  do{Menu();}while(isProgramActive);
}

//Функция вызова диалогового меню
int Menu()
{
  printf("1.Добавить элемент \n2.Удалить элемент \n3.Вывести очередь \n4.Выйти \n");
  scanf("%d", &answer);
  switch(answer){
    case 1:
      Add(); 
      break;
    case 2:
      Del();
      break;
    case 3:
      Display();
      break;
    case 4:
      Destroy();
      break;
    default:
      printf("Неправильный ответ");
      break;
  }
}

//Функция добавления элемента 
int Add()
{
  printf("Введите число: \n");
  if (pFirst == NULL){
    pLast = malloc(sizeof(struct QueueItem));
    scanf("%s", pLast -> info);
    pLast -> next = NULL;
    pFirst = pLast;
  }else{
    pTemp = malloc(sizeof(struct QueueItem));
    scanf("%s", pTemp -> info);
    pTemp -> next = NULL;
    pLast -> next = pTemp;
    pLast = pTemp;
  }
}

//Функция удаления элементов
int Del()
{
  if (pLast != NULL){
    pTemp = pFirst;
    pFirst = pFirst -> next;
    if (pFirst == NULL){
      pLast = NULL;
    }
    free(pTemp);
  }else{
    printf("Очередь пустая \n");
  }
}

//Функция вывода 
int Display()
{
  printf("*** \n");
  pTemp = pFirst;
  while(pTemp != NULL){
    printf("%s\n", pTemp -> info);
    pTemp = pTemp -> next;
  }
  printf("*** \n");
}

//Функция освобождения памяти и уничтожения очереди
int Destroy()
{
  isProgramActive = false;
  while(pFirst != NULL){
    pTemp = pFirst;
    pFirst = pFirst -> next;
    free(pTemp);
  }
}
