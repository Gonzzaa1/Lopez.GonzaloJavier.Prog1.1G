#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;

}Notebook;

int aplicarDescuento(int precioProducto);
int contarCaracteres(char caracteres[],char caracter);
int ordenarMarca(Notebook vec[],int tam);

int main()
{
    printf("%d\n",aplicarDescuento(100));

    int rta;
    char cadena[20]={"ana"};
    char caracter = 'a';

    rta = contarCaracteres(cadena,caracter);

    printf("%d\n",rta);


    Notebook notebooks[4] =
    {
        {1000,"64bits","intel",25000},
        {1001,"64bits","intel",15000},
        {1002,"32bits","AMD",25000},
        {1003,"32bits","AMD",15000}
    };

    ordenarMarca(notebooks, 4);

    return 0;
}
int aplicarDescuento(int precioProducto)
{
    int resultado;

    resultado = precioProducto - precioProducto * 5 / 100;

    return resultado;
}
int contarCaracteres(char caracteres[],char caracter)
{
    int contador = 0;
    for(int i = 0; i < strlen(caracteres)-1;i++)
    {
        if(strchr(caracteres,caracter))
        {
            contador++;
        }
    }

    return contador;
}
int ordenarMarca(Notebook vec[],int tam)
{
    int isOk=0;
    Notebook auxMarca;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam-1;i++)
        {
            for(int j=i+1; j<tam;j++)
            {
                if((vec[i].precio == vec[j].precio && strcmp(vec[i].marca,vec[j].marca) > 0)
                   || (vec[i].precio != vec[j].precio && (vec[i].precio > vec[j].precio)))
                {
                    auxMarca = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxMarca;
                }
            }
        }
         for(int a=0; a < tam; a++)
        {
            printf("%d  %s   %s %.2f\n",
                   vec->id,vec->procesador,vec->marca,vec->precio);
        }
        isOk = 1;
    }
    return isOk;
}
