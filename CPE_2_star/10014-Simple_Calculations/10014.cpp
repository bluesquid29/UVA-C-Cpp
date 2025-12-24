#include <cstdio>

int main()
{
    int T;
    scanf("%d", &T);
    
    for (int i = 1; i <= T; i++)
    {
        int n;
        scanf("%d", &n);
        
        double a_0;
        double a_n_plus_1;
        double c;
        double sum_value = 0;
        
        scanf("%lf", &a_0);
        scanf("%lf", &a_n_plus_1);
        
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf", &c);
            sum_value += (n - i + 1) * c;
        }
        
        
        double a_1 = (n * a_0 + a_n_plus_1 - 2 * sum_value) / (n + 1);
        
        printf("%.2lf\n", a_1);
        if (i < T) printf("\n");
    }
    
    return 0;
}