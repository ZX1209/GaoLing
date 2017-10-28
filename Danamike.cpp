#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
using namespace std;  
  
int n;  
int d[20005];  
int a[35];  
int main(){  
    int w;  
    scanf("%d %d", &w, &n);  
    int i, j;  
    for (i = 0; i < n; i++){  
        scanf("%d", &a[i]);  
    }  
    memset(d, 0, sizeof(d));  
    for (i = 0; i < n; i++){  
        for (j = w; j >= a[i]; j--)  
            d[j] = max(d[j], d[j - a[i]] + a[i]);  
              
    }  
    printf("%d\n", w - d[w]);  
    return 0;  
} 
