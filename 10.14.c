#include <stdio.h>
#include <string.h>
#include <time.h>
#define N 100
typedef struct node
{
    int firstNumber;
    int secondNumber;
    int thirdNumber;
    int m,n;
    int sum;
    char fuhao1;
    char fuhao2;
}shizi;
//�ṹ�����
shizi formula[N];
//��������
void menu();
void randomNumber(int n);
int add(int m,int n);
int jianfa(int m,int n);
int chengfa(int m,int n);
int divide(int m,int n);
int main()
{
    int i,j,n,m;
    int count = 0;
    int sum1[N];
    float score;
    menu();
    printf("��������Ŀ������:\n");
    scanf("%d",&n);
    randomNumber(n);
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(formula[i].m >= 2 && formula[i].n <2)
        {
            switch(formula[i].m)
            {
            case 2:
                sum1[i] = chengfa(formula[i].firstNumber,formula[i].secondNumber);
                break;
            case 3:
                sum1[i] = divide(formula[i].firstNumber,formula[i].secondNumber);
                break;
            }
            switch(formula[i].n)
            {
            case 0:
                formula[i].sum = add(sum1[i],formula[i].thirdNumber);
                break;
            case 1:
                formula[i].sum = jianfa(sum1[i],formula[i].thirdNumber);
                break;
            }
        }
        else if(formula[i].n >= 2 && formula[i].m <2)
        {
            switch(formula[i].n)
            {
            case 2:
                sum1[i] = chengfa(formula[i].secondNumber,formula[i].thirdNumber);
                break;
            case 3:
                sum1[i] = divide(formula[i].secondNumber,formula[i].thirdNumber);
                break;
            }
            switch(formula[i].m)
            {
            case 0:
                formula[i].sum = add(formula[i].firstNumber,sum1[i]);
                break;
            case 1:
                formula[i].sum = jianfa(formula[i].firstNumber,sum1[i]);
                break;
            }
        }
        else
        {
            switch(formula[i].m)
            {
            case 0:
                sum1[i] = add(formula[i].firstNumber,formula[i].secondNumber);
                break;
            case 1:
                sum1[i] = jianfa(formula[i].firstNumber,formula[i].secondNumber);
                break;
            case 2:
                sum1[i] = chengfa(formula[i].firstNumber,formula[i].secondNumber);
                break;
            case 3:
                sum1[i] = divide(formula[i].firstNumber,formula[i].secondNumber);
                break;
            }
            switch(formula[i].n)
            {
            case 0:
                formula[i].sum = add(sum1[i],formula[i].thirdNumber);
                break;
            case 1:
                formula[i].sum = jianfa(sum1[i],formula[i].thirdNumber);
                break;
            case 2:
                formula[i].sum = chengfa(sum1[i],formula[i].thirdNumber);
                break;
            case 3:
                formula[i].sum = divide(sum1[i],formula[i].thirdNumber);
                break;
            }
        }

    }
        printf("\n");
    for(j=0;j<n;j++)
    {
        printf("%d %c %d %c %d = ",formula[j].firstNumber,formula[j].fuhao1,formula[j].secondNumber,formula[j].fuhao2,formula[j].thirdNumber);
        scanf("%d",&m);
        if(m == formula[j].sum)
        {
            printf("����ȷ������\n");
            count++;
        }
        else
        {
            printf("�𰸴��󣡣�����ȷ��Ϊ:%d\n",formula[j].sum);
        }
    }
    score = (100/n)*count;
    printf("�ܹ������:%d\t�ܷ���Ϊ:%f",count,score);
}
void menu()
{
    printf("\n\n");
    printf("\t\t|--------------Сѧ����������-------------|\n\n\n");

}
void randomNumber(int n)
{
    int i;
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        formula[i].firstNumber = rand()%100 + 1;
        formula[i].secondNumber = rand()%100 + 1;
        formula[i].thirdNumber = rand()%100 + 1;
        formula[i].m = rand()%4;
        switch(formula[i].m)
        {
        case 0:
            formula[i].fuhao1 = '+';
            break;
        case 1:
            formula[i].fuhao1 = '-';
            break;
        case 2:
            formula[i].fuhao1 = '*';
            break;
        case 3:
            formula[i].fuhao1 = '/';
            break;
        }
        formula[i].n = rand()%4;
        switch(formula[i].n)
        {
        case 0:
            formula[i].fuhao2 = '+';
            break;
        case 1:
            formula[i].fuhao2 = '-';
            break;
        case 2:
            formula[i].fuhao2 = '*';
            break;
        case 3:
            formula[i].fuhao2 = '/';
            break;
        }
    }
}
int add(int m,int n)
{
    int sum = 0;
    sum = m + n;
    return sum;
}
int jianfa(int m,int n)
{
    int sum = 0;
    sum = m - n;
    return sum;
}
int chengfa(int m,int n)
{
    int sum = 0;
    sum = m * n;
    return sum;
}
int divide(int m,int n)
{
    int sum = 0;
    sum = m / n;
    return sum;
}
