#include <iostream>

int daysCount(int month, int year)
{
    int daysOfYear = 0;
    for (int i = 1; i < month; i++)
    {
        if (i < 8)
        {
            if (i % 2 == 0)
            {
                if (i == 2)
                {
                    if (year % 4 == 0)
                    {
                        daysOfYear += 29;
                    }
                    else
                    {
                        daysOfYear += 28;
                    }
                }
                else
                {
                    daysOfYear += 30;
                }
            }
            else
            {
                daysOfYear += 31;
            }
        }
        else
        {
            if (i % 2 == 0)
            {
                daysOfYear += 31;
            }
            else
            {
                daysOfYear += 30;
            }
        }
    }

    return daysOfYear;
}

struct person
{
    std::string name;
    int day;
    int month;
    int year;
};

int main()
{
    person person1, person2, oldestPerson, youngestPerson;
    int greatestYear, smallestYear, days = 0;

    // DATOS PERSONA 1
    std::cout << "Ingrese el nombre de la persona 1: " << std::endl;
    std::cin >> person1.name;

    std::cout << "Ingrese la fecha de nacimiento de: " << person1.name << std::endl;
    std::cout << "Dia: ";
    std::cin >> person1.day;
    std::cout << "Mes: ";
    std::cin >> person1.month;
    std::cout << "Ano: ";
    std::cin >> person1.year;

    // DATOS PERSONA 2
    std::cout << "Ingrese el nombre de la persona 2: " << std::endl;
    std::cin >> person2.name;

    std::cout << "Ingrese la fecha de nacimiento de: " << person2.name << std::endl;
    std::cout << "Dia: ";
    std::cin >> person2.day;
    std::cout << "Mes: ";
    std::cin >> person2.month;
    std::cout << "Ano: ";
    std::cin >> person2.year;

    // DETERMINAR LA PERSONA MAYOR
    if (person1.year > person2.year)
    {
        greatestYear = person1.year;
        smallestYear = person2.year;
        oldestPerson = person2;
        youngestPerson = person1;
    }
    else if (person1.year < person2.year)
    {
        greatestYear = person2.year;
        smallestYear = person1.year;
        oldestPerson = person1;
        youngestPerson = person2;
    }
    else
    {
        smallestYear = person1.year;
        greatestYear = smallestYear;
        if (person1.month > person2.month)
        {
            oldestPerson = person2;
            youngestPerson = person1;
        }
        else if (person1.month < person2.month)
        {
            oldestPerson = person1;
            youngestPerson = person2;
        }
        else
        {
            if (person1.day > person2.day)
            {
                oldestPerson = person2;
                youngestPerson = person1;
            }
            else
            {
                oldestPerson = person1;
                youngestPerson = person2;
            }
        }
    }

    // DETERMINAR DÍAS ENTRE LOS AÑOS
    for (int i = smallestYear; i < greatestYear; i++)
    {
        if (i % 4 == 0)
        {
            days += 366;
        }
        else
        {
            days += 365;
        }
    };

    // ESTABLECER CUANTOS DÍAS VA DE CADA AÑO
    int daysOldestPerson, daysYoungestPerson;

    daysOldestPerson = daysCount(oldestPerson.month, oldestPerson.year) + oldestPerson.day;
    daysYoungestPerson = daysCount(youngestPerson.month, youngestPerson.year) + youngestPerson.day;

    // DETERMINAR NUMERO DE DIAS TOTALES

    days = days + daysYoungestPerson - daysOldestPerson;

    std::cout << "La diferencia de dias entre " << person1.name << " y " << person2.name << " es de " << days << " dias, siendo " << oldestPerson.name << " mayor";

    return 0;
};