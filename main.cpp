#include"Base.h"
#include"LinkList.h"
#include"Polynomial.h"
#include"Print.h"
int main()
{
    system("color F4");
    start_print();
    system("pause");
    system("CLS");
    polynomial A,B;
    int a,m;// a进行输入控制
    do
    {
        system("CLS");
        do
        {
            menu1_print();
            scanf("%d",&a);
            if(a==1)
            {
                Creathelp_print(m);
                CreatPolyn(A,m);
            }
            else if(a==2)
            {
                Creathelp_print(m);
                CreatPolyn(B,m);
            }
            else if(a==0)
            {
                over_print();
                return 0;
            }

        }
        while(a!=3);
        do
        {
            menu2_print();
            scanf("%d",&a);
            if(a==1)
            {
                output_tip_print('A');
                PrintPolyn(A);
                output_tip_print('B');
                PrintPolyn(B);
                AddPolyn(A, B);
                printf("A+B: ");
                PrintPolyn(A);
                system("pause");
                break;
            }
            else if(a==2)
            {
                output_tip_print('A');
                PrintPolyn(A);
                output_tip_print('B');
                PrintPolyn(B);
                MultiplyPolyn(A,B);
                printf("AXB: ");
                PrintPolyn(A);
                system("pause");
                break;
            }

            else if(a==0)
            {
                over_print();
                return 0;
            }
        }
        while(a!=3);
    }
    while(1);
}
