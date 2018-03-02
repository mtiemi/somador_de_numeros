/* Mariane Tiemi Iguti 
EA876
Lab 01 Somador de numeros */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    char entrada[10];
    float soma = 0, numeroc = 0, fatorial = 0;
    int i = 0, j = 0, k = 0;
    char numero[5];
    int flag = 0; // indica se na string auxiliar numero tem algum valor
    
    scanf("%[^\n]s", entrada);
  
    while(entrada[i] != '\0')
    {
        if(entrada[i] > 47 && entrada[i] < 58)
        {
        
            if(i == 0)
            {
                while((entrada[i] > 47 && entrada[i] < 58 )|| entrada[i] == 46) // copia algum numero todo numa string auxiliar
                {
                    numero[j] = entrada[i];
                    i++;
                    j++;
                    flag = 1;
                }
                numero[j] = '\0';
                
            }else if(i != 0)
            {
               
                if(entrada[i - 1] == 32) // verifica se tem espaco antes de numero
                {
                    while((entrada[i] > 47 && entrada[i] < 58) || entrada[i] == 46) // copia algum numero todo numa string auxiliar
                    {
                        numero[j] = entrada[i];
                        i++;
                        j++;
                        flag = 1;
                    }
                    numero[j] = '\0';
                }
            }
        }else if(entrada[i] == 46) // encontra numero que comeca com parte omitida antes do .
        {
            numero[j] = '0';
            i++;
            if(i == 0)
            {
                while((entrada[i] > 47 && entrada[i] < 58 )) // copia algum numero todo numa string auxiliar
                {
                    numero[j] = entrada[i];
                    i++;
                    j++;
                    flag = 1;
                }
                numero[j] = '\0';
            }else if(i != 0)
            {
               
                if(entrada[i - 2] == 32) // verifica se tem espaco antes de numero float
                {
                    while((entrada[i] > 47 && entrada[i] < 58)) // copia algum numero todo numa string auxiliar
                    {
                        numero[j] = entrada[i];
                        i++;
                        j++;
                        flag = 1;
                    }
                    numero[j] = '\0';
                }
            }
        }
                       
        if((entrada[i] == 32 || entrada[i] == '\n' || entrada[i] == '\0') && flag == 1) // verifica se depois numero tem espaco ou fim de linha ou fim de arquivo
        {
            numeroc = atof(numero); // converte a string para numero 
            soma = soma + numeroc;
            flag = 0;
            j = 0;           
            numero[j] = '\0';
            
        }else if(entrada[i] == 33 && (entrada[i + 1] == 32 || entrada[i + 1] == '\n' || entrada[i + 1] == '\0') && flag == 1) //numero fatorial
        {
            numeroc = atof(numero);
            
            k = 1;
            fatorial = 1;
            while(k <= numeroc)
            {
                fatorial = fatorial * k;
                k++;
            }
            
            soma = soma + fatorial;
            flag = 0;
            j = 0;
            
            numero[j] = '\0'; 
            
        }else if(flag == 1) //numero invalido
        {
            flag = 0;
            j = 0;
            numero[j] = '\0';
        }
        
        i++;   
    }
    
    
    printf("%0.2f\n", soma);
    
    return 0;
}
