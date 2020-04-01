
#include "Employee.h"

Employee* employee_new()
{
    Employee* aux= (Employee*)malloc(sizeof(Employee));
    if(aux != NULL)
    {
        aux->id = 0;
        strcpy(aux->nombre," ");
        aux->horasTrabajadas = 0;
        aux->sueldo = 0;
    }
    return aux;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevo=NULL;
    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        nuevo = employee_new();

        if(nuevo != NULL)
        {
            if((!employee_setId(nuevo,atoi(idStr)))
                    || (!employee_setNombre(nuevo,nombreStr))
                    || (!employee_setHorasTrabajadas(nuevo,atoi(horasTrabajadasStr)))
                    || (!employee_setSueldo(nuevo,atoi(sueldoStr))))
            {
               free(nuevo);
               nuevo = NULL;

            }
        }
    }

    return nuevo;

}
void employee_delete(LinkedList* this)
{
    if(this != NULL)
    {
        free(this);
    }

}

int employee_setId(Employee* this,int id)
{
    int flag = 0;
    static int idMaximo = 0;

    if(this != NULL)
    {
        if(id < 1)
        {
            idMaximo++;
            this->id = idMaximo;
        }
        else if(id > idMaximo)
        {
            this->id = id;
            idMaximo = id;
        }

        flag = 1;
    }


    return flag;
}
int employee_getId(Employee* this,int* id)
{
    *id = -1;
    if(this != NULL)
    {
        *id = this->id;
    }
    return *id;
}
int employee_setNombre(Employee* this,char* nombre)
{
    int flag = 0;
    if(this != NULL && nombre != NULL && strlen(nombre) >=1)
    {
        strcpy(this->nombre, nombre);
        flag = 1;
    }
    return flag;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int flag = 0;
    if(this != NULL)
    {
        strcpy(nombre,this->nombre);
        flag = 1;
    }
    return flag;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int flag = 0;
    if(this !=NULL && horasTrabajadas >= 1)
    {
        this->horasTrabajadas = horasTrabajadas;
        flag = 1;
    }
    return flag;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    *horasTrabajadas = -1;
    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
    }
    return *horasTrabajadas;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    int flag = 0;
    if(this !=NULL && sueldo >=1)
    {
        this->sueldo = sueldo;
        flag = 1;
    }
    return flag;

}
int employee_getSueldo(Employee* this,int* sueldo)
{
    *sueldo = -1;
    if(this != NULL)
    {
        *sueldo = this->sueldo;
    }
    return *sueldo;
}
int printEmployee(Employee* this)
{
    printf("%d   %s  %d   %d\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);

    return 1;
}
int printEmployees(LinkedList* pArrayListEmployee)
{
    int flag=0;
    if(pArrayListEmployee != NULL)
    {
        printf("id   nombre  horas sueldo\n");
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            if(flag==100)
            {
                system("pause");
                flag=0;
            }
            flag++;
            printEmployee((Employee*)ll_get(pArrayListEmployee,i));

        }

    }
    return 1;
}

int ordenarPorNombre(void* empleado, void* empleado2)
{
    int criterio;
    Employee* employee = (Employee*) empleado;
    Employee* employee2 = (Employee*) empleado2;

    if(strcmp(employee->nombre,employee2->nombre )> 0)
    {
        criterio = 1;
    }
    else if( strcmp(employee->nombre,employee2->nombre )<0)
    {
        criterio = -1;
    }
    else
    {
        criterio = 0;
    }

    return criterio;
}

int ordenarPorId(void* empleado,void* empleado2)
{
    int criterio;
    Employee* empleadoAux = (Employee*)empleado;
    Employee* empleadoAux2 = (Employee*)empleado2;

    if(empleadoAux->id > empleadoAux2->id)
    {
        criterio = 1;
    }
    else
    {
        if(empleadoAux->id < empleadoAux2->id)
        {
            criterio = -1;
        }
        else
        {
            criterio = 0;
        }
    }
    return criterio;
}
