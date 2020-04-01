#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{

    LinkedList* listaEmpleados = ll_newLinkedList();

    int option;
    int validaCargaTexto=0;
    int validaCargaBinario=0;
    int validaCargaManual=0;
    int validaGuardarTexto=0;
    int validaGuardarBinario=0;

    do
    {
        option = menuPrincipal();
        switch(option)
        {
        case 1:
            if(validaCargaTexto == 1)
            {
                printf("El archivo ya fue cargado\n");
            }
            else
            {
                if(validaCargaBinario == 1)
                {
                    printf("El archivo ya fue cargado en modo binario\n");
                }
                else
                {
                    if(controller_loadFromText("data.csv",listaEmpleados))
                    {
                        printf("Archivo cargado\n");
                        validaCargaTexto = 1;

                    }
                }
            }

            break;
        case 2:
            if(validaCargaBinario == 1)
            {
                printf("El archivo ya fue cargado\n");
            }
            else
            {
                if(validaCargaTexto == 1)
                {
                    printf("El archivo ya fue cargado en modo texto\n");
                }
                else
                {
                    if(controller_loadFromBinary("data.bin",listaEmpleados))
                    {
                        printf("Archivo cargado\n");
                        validaCargaBinario = 1;
                    }

                }
            }

            break;
        case 3:
            if(controller_addEmployee(listaEmpleados))
            {
                validaCargaManual = 1;
                validaGuardarBinario = 0;
                validaGuardarTexto = 0;
            }
            break;
        case 4:
            if(validaCargaBinario == 1 || validaCargaManual == 1 || validaCargaTexto == 1)
            {
                if(controller_editEmployee(listaEmpleados))
                {
                    validaGuardarBinario = 0;
                    validaGuardarTexto = 0;
                }
            }
            else
            {
                printf("No hay empleados cargados\n");
            }

            break;
        case 5:
            if(validaCargaBinario == 1 || validaCargaManual == 1 || validaCargaTexto == 1)
            {
                if(controller_removeEmployee(listaEmpleados))
                {
                    validaGuardarBinario = 0;
                    validaGuardarTexto = 0;
                }
            }
            else
            {
                printf("No hay empleados cargados\n");
            }
            break;
        case 6:
            if(validaCargaBinario == 1 || validaCargaManual == 1 || validaCargaTexto == 1)
            {
                printEmployees(listaEmpleados);
            }
            else
            {
                printf("No hay empleados cargados\n");
            }
            break;
        case 7:
            if(validaCargaBinario == 1 || validaCargaManual == 1 || validaCargaTexto == 1)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay empleados cargados\n");
            }
            break;
        case 8:
            if(validaGuardarTexto == 0)
            {
                if(validaCargaBinario == 1 || validaCargaManual == 1 || validaCargaTexto == 1)
                {
                    if(controller_saveAsText("data.csv",listaEmpleados))
                    {
                        printf("Los datos fueron guardados con exito\n");
                        validaGuardarTexto = 1;
                    }
                }

                else
                {
                    printf("No hay empleados cargados\n");
                }
            }
            else
            {
                printf("Los datos ya fueron guardados anteriormente\n");
            }

            break;
        case 9:
            if(validaGuardarBinario == 0)
            {
                if(validaCargaBinario == 1 || validaCargaManual == 1 || validaCargaTexto == 1)
                {
                    if(controller_saveAsBinary("data.bin",listaEmpleados))
                    {
                        printf("Los datos fueron guardados con exito\n");
                        validaGuardarBinario = 1;
                    }
                }

                else
                {
                    printf("No hay empleados cargados\n");
                }
            }
            else
            {
                printf("Los datos ya fueron guardados anteriormente\n");
            }

            break;
        case 10:
            break;
        default:
            printf("Opcion incorrecta");

        }

        system("pause");
        system("cls");
    }
    while(option != 10);

    return 0;
}
