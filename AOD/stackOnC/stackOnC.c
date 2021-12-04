#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//Тип(запись)
struct StackItem
{
  char info[80];
  struct StackItem *pred;
};

//Объявление переменных
int answer;
_Bool isProgramActive = true;
struct StackItem *SP;
struct StackItem *pTemp;

int main()
{
  SP = NULL;
  //Зацикливание меню
  do{Menu();}while(isProgramActive);
}

//Функция вызова диалогового меню
int Menu()
{
  printf("1.Добавить элемент \n2.Удалить элемент \n3.Вывести стек \n4.Выйти \n");
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

//Функция добавления элемента в стек
int Add()
{
  pTemp = malloc(sizeof(struct StackItem));
  pTemp -> pred = SP;
  printf("Введите число: \n");
  scanf("%s", pTemp -> info);
  SP = pTemp;
}

//Функция удаления элементов из стека 
int Del()
{
  if (SP != NULL){
    pTemp = SP;
    SP = SP -> pred;
    free(pTemp);
  }else{
    printf("Стек пустой \n");
  }
}

//Функция вывода стека
int Display()
{
  printf("*** \n");
  pTemp = SP;
  while(pTemp != NULL){
    printf("%s\n", pTemp -> info);
    pTemp = pTemp -> pred;
  }
  printf("*** \n");
}

//Функция освобождения памяти и уничтожения стека
int Destroy()
{
  isProgramActive = false;
  while(SP != NULL){
    pTemp = SP;
    SP = SP -> pred;
    free(pTemp);
  }
}
