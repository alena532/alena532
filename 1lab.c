#include <stdio.h>
int Sum(int result)
{
    int count=0,sum=0;
    if(result<0){
    result=-result;
    }
    while(count!=3){
       sum+=result%10;
       result=result/10;
       count++;
    }
    return sum;
}
int main(int argc, const char * argv[]) {
    double number;
    int result;
    while(!scanf("%lf",&number)){
        printf("try again");
        while(getchar()!='\n');
    }
    number=number*1000;
    result=(int)number;
    int sum;
    sum=Sum(result);
    printf("%d",sum);
    return 0;
}
