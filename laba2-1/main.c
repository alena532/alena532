#include <stdio.h>
#include <stdlib.h>
#include "main.h"
int weight=0;
int distance=0;
void  setWeight()
{
    printf("Введите вес груза от 50 до 300 тонн:");
    while(scanf("%d",&weight)!=1||weight<50||weight>300){
        printf("Mistake!Try again");
        while(getchar()!='\n');
    }
}
void  setDistance()
{
    printf("Введите расстояние от 1 до 4000 км:");
    while(scanf("%d",&distance)!=1||distance<1||distance>4000){
        printf("Mistake!Try again\n");
        while(getchar()!='\n');
    }
}
int analys()
{
    if(weight==0||distance==0 ){
        printf("wrong number!\n");
        return 0;
    }
    return 1;
}
int countCars(int weight)
{
    int count=weight/20;
    if(weight%20!=0){
        count++;
    }
    return count;
}
void count()
{
    int count_cars;
    int insurance_cost;
    int total_price;
    if(analys()!=1){
        printf("Number is not correct!");
        return;
    }
    count_cars=countCars(weight);
    insurance_cost=0.05*2*distance;
    total_price=1.05*2*distance;
    printf("Необходимое количество машин %d\n",count_cars);
    printf("Стоимость страховки %d\n",insurance_cost);
    printf("Общая стоимость заказа на перевозку %d\n",total_price);
}
void information()
{
    printf("Ver. 1.0.0 \n Make by Alena\n");
}
void Exit()
{
    printf("Exit\n");
    exit(0);
}
void start()
{
    while(1){
        int number;
        printf("1.Ввод веса груза (тонн)\n");
        printf("2.Ввод расстояния перевозки (км).\n");
        printf("3.Анализ данных и вывод решения о принятии заказа.\n");
        printf("4.Расчет и вывод параметров заказа\n");
        printf("5.Информация о версии и авторе программы.\n");
        printf("6.Выход из программы.\n");
        printf("Ввод:");
        while(scanf("%d",&number)!=1||getchar() != '\n'||number<=0||number>6){
            printf("Error.Try again!");
            while(getchar()!='\n');
        }
        switch(number){
            case 1:
                setWeight();
                break;
            case 2:
                setDistance();
                break;
            case 3:
                analys();
                break;
            case 4:
                count();
                break;
            case 5:
                information();
                break;
            case 6:
                Exit();
                break;
        }
    }
}
int main(int argc, const char * argv[]) {
    start();
    return 0;
}


