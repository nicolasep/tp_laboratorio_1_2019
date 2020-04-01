#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int cant;
    char buffer[4][30];
    Employee* aux;

    while( !feof(pFile) )
    {
        cant =  fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        if( cant < 4)
        {
            break;
        }
        else
        {
            aux = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

            if(aux != NULL)
            {
                ll_add(pArrayListEmployee,aux);
            }
        }
    }
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int cant = 0;
    Employee* aux;

    while(!feof(pFile) )
    {
        aux=employee_new();
        cant = fread(aux,sizeof(Employee),1,pFile);
        if( cant < 1)
        {
            break;
        }
        else
        {
            if(aux != NULL)
            {
                ll_add(pArrayListEmployee,aux);
            }
        }
    }

    return 1;
}
