void start_print()
{
    printf("***********************************************************************************************************************\n");
    printf("                  数据结构实验一                         \n");
    printf("          一元多项式的表示、相加和乘法                   \n");
    printf("                 中国海洋大学                            \n");
    printf("***********************************************************************************************************************\n");
}
void Creathelp_print(int & m)
{
    printf("**请输入多项式的项数**\n");
    scanf("%d",&m);
    printf("**请输入多项式的系数和指数**\n");
}
void menu1_print()
{
    printf("***********************************************************************************************************************\n");
    printf("        请选择  1.建立多项式(重新输入） A   2.建立多项式(重新输入） B   3.对多项式进行操作    0.退出                \n");
    printf("***********************************************************************************************************************\n");
}
void menu2_print()
{
    printf("***********************************************************************************************************************\n");
    printf("        请选择  1.打印 A+B   2.打印 AXB    3.对多项式进行操作    0.退出                \n");
    printf("***********************************************************************************************************************\n");
}
void output_tip_print(char a)
{
    printf("多项式%c: ",a);
}
void over_print()
{
    system("CLS");
    printf("      *******  *               *           \n");
    printf("         *     *               *           \n");
    printf("         *     ***  ***   ***  * *   **    \n");
    printf("         *     * *  * *   * *  **    *     \n");
    printf("         *     * *  ****  * *  * *  **     \n");
}