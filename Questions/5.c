#include <stdio.h> 
#include <string.h> 
  

void convert(char s[]) 
{ 
    int n = strlen(s); 
    int i = 0;
    for (i = 0; i < n; i++) 
    {
        if(s[i]>=48 && s[i]<=57)
        {
            printf("%d",s[i] -48);
        }
    }
} 
  
int main() 
{ 
    char s[] = "+233123"; 
    convert(s); 
    return 0; 
} 