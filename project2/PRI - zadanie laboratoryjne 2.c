#include <stdio.h>
#include <string.h>
typedef struct{
    unsigned pozycja;
    int dystans;
    double czas;
    char nazwisko[30], imie[15];
} zawodnik;
zawodnik lista[100];
zawodnik pomocnicza;
typedef struct{
    char nazwisko[30], imie[15];
} dane;
dane usun_edytuj;
unsigned zamiana2;
int numer=1, n=0, k=0, i=0, blad=1, min=0, m=0, petla1, petla2, zamiana, komenda;
int sortuj_dane (zawodnik z1, zawodnik z2)
{
    if ((strcmp ((z1.nazwisko), (z2.nazwisko)))<0) return 0;
    else
    {
        if ((strcmp((z1.nazwisko), (z2.nazwisko)))>0) return 1;
        else
        {
            if ((strcmp((z1.nazwisko), (z2.nazwisko)))==0)
            {
                if ((strcmp ((z1.imie), (z2.imie)))<0) return 0;
                else return 1;
            }
        }
    }
}
int sortuj_czasy(zawodnik z1, zawodnik z2)
{
    if((z1.czas)>(z2.czas)) return 1;
    else
    {
        if((z1.czas)<(z2.czas)) return 0;
        else
        {
            if((z1.czas)==(z2.czas)) return sortuj_dane(z1, z2);
        }
    }
}
int sortuj_t(zawodnik z1, zawodnik z2)
{
    if((z1.dystans)>(z2.dystans)) return 1;
    else
    {
        if((z1.dystans)<(z2.dystans)) return 0;
        else
        {
            if((z1.dystans)==(z2.dystans)) return sortuj_czasy(z1, z2);
        }
    }
}
int main()
{
    puts("Program sortuje podana przez uzytkownika liste sprinterow i danych o nich\nwedlug nazwisk lub uzyskanych czasow z uwzglednieniem dystansu\n");
    puts(" 0 - dane nowego zawodnika | 1 - sortowanie po nazwiskach |\n 2 - sortowanie po czasach | 3 - edycja wybranych danych |\n 4 - usun wybrane dane | 5 - koniec\n");
    while(1)
    {
        k=1;
        while(k==1)
        {
            if(scanf("%d", &komenda)==1)
            {
                if(getchar()!='\n')
                {
                    while(getchar()!='\n');
                    puts(" 0 - dane nowego zawodnika | 1 - sortowanie po nazwiskach |\n 2 - sortowanie po czasach | 3 - edycja wybranych danych |\n 4 - usun wybrane dane | 5 - koniec\n");
                }
                else k=0;
            }
            else
            {
                while(getchar()!='\n');
                puts(" 0 - dane nowego zawodnika | 1 - sortowanie po nazwiskach |\n 2 - sortowanie po czasach | 3 - edycja wybranych danych |\n 4 - usun wybrane dane | 5 - koniec\n");
            }
        }
        if(komenda==0)
        {
            if(n<100)
            {
                lista[n].pozycja=numer;
                puts("Podaj nazwisko");
                scanf("%28s", &lista[n].nazwisko);
                while(getchar()!='\n');
                puts("Podaj imie");
                scanf("%13s", &lista[n].imie);
                while(getchar()!='\n');
                puts("Podaj dystans w metrach");
                k=1;
                while(k==1)
                {
                    if(scanf("%d", &lista[n].dystans)==1)
                    {
                        if(getchar()!='\n')
                        {
                            printf("Blad danych. Jeszcze raz\n");
                            while(getchar()!='\n');
                        }
                        else k=0;
                    }
                    else
                    {
                        printf("Blad danych. Jeszcze raz\n");
                        while(getchar()!='\n');
                    }
                }
                puts("Podaj czas w sekundach");
                k=1;
                while(k==1)
                {
                    if(scanf("%lf", &lista[n].czas)==1)
                    {
                        if(getchar()!='\n')
                        {
                            printf("Blad danych. Jeszcze raz\n");
                            while(getchar()!='\n');
                        }
                        else k=0;
                    }
                    else
                    {
                        printf("Blad danych. Jeszcze raz\n");
                        while(getchar()!='\n');
                    }
                }
                for(k=0; k<n; k++)
                {
                    if((strcmp((lista[n].nazwisko), (lista[k].nazwisko)))==0)
                    {
                        if((strcmp((lista[n].imie), (lista[k].imie)))==0)
                        {
                                blad=0;
                                printf("Blad - w rejestrze znajduje sie juz taka osoba\n");
                        }
                    }
                }
                if(blad==1)
                {
                    n++;
                    numer++;
                    puts(" 0 - dane nowego zawodnika | 1 - sortowanie po nazwiskach |\n 2 - sortowanie po czasach | 3 - edycja wybranych danych |\n 4 - usun wybrane dane | 5 - koniec\n");
                }
                else
                {
                    blad=1;
                    puts(" 0 - dane nowego zawodnika | 1 - sortowanie po nazwiskach |\n 2 - sortowanie po czasach | 3 - edycja wybranych danych |\n 4 - usun wybrane dane | 5 - koniec\n");
                }
            }
            else
            {
                puts("Tablica zapelniona\n");
                puts(" 0 - dane nowego zawodnika | 1 - sortowanie po nazwiskach |\n 2 - sortowanie po czasach | 3 - edycja wybranych danych |\n 4 - usun wybrane dane | 5 - koniec\n");
            }
        }
        else
        {
            if(komenda==2)
            {
                petla1=n-1;
                for(k=0;k<petla1;k++)
                {
                    min=k;
                    petla2=k+1;
                    for(m=petla2; m<n; m++)
                    {
                        if(sortuj_t(lista[min], lista[m])) min=m;
                    }
                    if(min!=k)
                    {
                        pomocnicza=lista[k];
                        lista[k]=lista[min];
                        lista[min]=pomocnicza;
                    }
                }
                for(k=0;k<n;k++)
                {
                    lista[k].pozycja=k+1;
                }
                puts("Dane w kolejnosci: pozycja, nazwisko, imie, dystans, czas\n");
                for(k=0;k<n;k++)
                {
                    printf("%u | %s | %s | %u | %lf\n", lista[k].pozycja, lista[k].nazwisko, lista[k].imie, lista[k].dystans, lista[k].czas);
                }
                puts("\n 0 - dane nowego zawodnika | 1 - sortowanie po nazwiskach |\n 2 - sortowanie po czasach | 3 - edycja wybranych danych |\n 4 - usun wybrane dane | 5 - koniec\n");
            }
            else
            {
                if(komenda==1)
                {
                    petla1=n-1;
                    for(k=0;k<petla1;k++)
                    {
                        min=k;
                        petla2=k+1;
                        for(m=petla2; m<n; m++)
                        {
                            if(sortuj_dane(lista[min], lista[m])) min=m;
                        }
                        if(min!=k)
                        {
                            pomocnicza=lista[k];
                            lista[k]=lista[min];
                            lista[min]=pomocnicza;
                        }
                    }
                    for(k=0;k<n;k++)
                    {
                        lista[k].pozycja=k+1;
                    }
                    puts("Dane w kolejnosci: pozycja, nazwisko, imie, dystans, czas\n");
                    for(k=0;k<n;k++)
                    {
                        printf("%u | %s | %s | %u | %lf\n", lista[k].pozycja, lista[k].nazwisko, lista[k].imie, lista[k].dystans, lista[k].czas);
                    }
                    puts("\n 0 - dane nowego zawodnika | 1 - sortowanie po nazwiskach |\n 2 - sortowanie po czasach | 3 - edycja wybranych danych |\n 4 - usun wybrane dane | 5 - koniec\n");
                }
                else
                {
                    if(komenda==3)
                    {
                        puts("Wpisz nazwisko osoby, ktorej dane chcesz edytowac");
                        scanf("%28s", &usun_edytuj.nazwisko);
                        while(getchar()!='\n');
                        puts("Wpisz imie osoby, ktorej dane chcesz edytowac");
                        scanf("%13s", &usun_edytuj.imie);
                        while(getchar()!='\n');
                        for(k=0;k<n;k++)
                        {
                            if((strcmp((usun_edytuj.nazwisko), (lista[k].nazwisko)))==0)
                            {
                                if((strcmp((usun_edytuj.imie), (lista[k].imie)))==0)
                                {
                                    puts("Podaj nazwisko");
                                    scanf("%28s", &pomocnicza.nazwisko);
                                    while(getchar()!='\n');
                                    puts("Podaj imie");
                                    scanf("%13s", &pomocnicza.imie);
                                    while(getchar()!='\n');
                                    puts("Podaj dystans w metrach");
                                    m=1;
                                    while(m==1)
                                    {
                                        if(scanf("%d", &pomocnicza.dystans)==1)
                                        {
                                            if(getchar()!='\n')
                                            {
                                                printf("Blad danych. Jeszcze raz\n");
                                                while(getchar()!='\n');
                                            }
                                            else m=0;
                                        }
                                        else
                                        {
                                            printf("Blad danych. Jeszcze raz\n");
                                            while(getchar()!='\n');
                                        }
                                    }
                                    puts("Podaj czas w sekundach");
                                    m=1;
                                    while(m==1)
                                    {
                                        if(scanf("%lf", &lista[n].czas)==1)
                                        {
                                            if(getchar()!='\n')
                                            {
                                                printf("Blad danych. Jeszcze raz\n");
                                                while(getchar()!='\n');
                                            }
                                            else m=0;
                                        }
                                        else
                                        {
                                            printf("Blad danych. Jeszcze raz\n");
                                            while(getchar()!='\n');
                                        }
                                    }
                                    for(i=0;i<k;i++)
                                    {
                                        if((strcmp((lista[i].nazwisko), (pomocnicza.nazwisko)))==0)
                                        {
                                            if((strcmp((lista[i].imie), (pomocnicza.imie)))==0)
                                            {
                                                blad=0;
                                                printf("Blad - w rejestrze znajduje sie juz taka osoba. Zmiany nie zostaly zapisane.\n");
                                                break;
                                            }
                                        }
                                    }
                                    petla2=k+1;
                                    for(i=petla2;i<n;i++)
                                    {
                                        if(blad==1)
                                        {
                                            if((strcmp((lista[i].nazwisko), (pomocnicza.nazwisko)))==0)
                                            {
                                                if((strcmp((lista[i].imie), (pomocnicza.imie)))==0)
                                                {
                                                    blad=0;
                                                    printf("Blad - w rejestrze znajduje sie juz taka osoba. Zmiany nie zostaly zapisane.\n");
                                                    break;
                                                }
                                            }
                                        }
                                        else break;
                                    }
                                    if(blad==1)
                                    {
                                        if(k==petla1)
                                        {
                                            petla1=n-1;
                                            lista[k]=pomocnicza;
                                            puts(" 0 - dane nowego zawodnika | 1 - sortowanie po nazwiskach |\n 2 - sortowanie po czasach | 3 - edycja wybranych danych |\n 4 - usun wybrane dane | 5 - koniec\n");
                                        }
                                    }
                                    else
                                    {
                                        blad=1;
                                        puts(" 0 - dane nowego zawodnika | 1 - sortowanie po nazwiskach |\n 2 - sortowanie po czasach | 3 - edycja wybranych danych |\n 4 - usun wybrane dane | 5 - koniec\n");
                                        break;
                                    }
                                }
                                else
                                {
                                    petla1=n-1;
                                    if(k==petla1)
                                    {
                                        printf("Nie ma takiej osoby!\n");
                                        puts(" 0 - dane nowego zawodnika | 1 - sortowanie po nazwiskach |\n 2 - sortowanie po czasach | 3 - edycja wybranych danych |\n 4 - usun wybrane dane | 5 - koniec\n");
                                    }
                                }
                            }
                            else
                            {
                                petla1=n-1;
                                if(k==petla1)
                                {
                                    printf("Nie ma takiej osoby!\n");
                                    puts(" 0 - dane nowego zawodnika | 1 - sortowanie po nazwiskach |\n 2 - sortowanie po czasach | 3 - edycja wybranych danych |\n 4 - usun wybrane dane | 5 - koniec\n");
                                }
                            }
                        }
                    }
                    else
                    {
                        if(komenda==4)
                        {
                            puts("Wpisz nazwisko osoby, ktorej dane chcesz usunac");
                            scanf("%28s", &usun_edytuj.nazwisko);
                            while(getchar()!='\n');
                            puts("Wpisz imie osoby, ktorej dane chcesz usunac");
                            scanf("%13s", &usun_edytuj.imie);
                            while(getchar()!='\n');
                            for(k=0;k<n;k++)
                            {
                                if((strcmp((usun_edytuj.nazwisko), (lista[k].nazwisko)))==0)
                                {
                                    if((strcmp((usun_edytuj.imie), (lista[k].imie)))==0)
                                    {
                                       if(k==99)
                                       {
                                           n--;
                                           numer--;
                                           puts(" 0 - dane nowego zawodnika | 1 - sortowanie po nazwiskach |\n 2 - sortowanie po czasach | 3 - edycja wybranych danych |\n 4 - usun wybrane dane | 5 - koniec\n");
                                       }
                                       else
                                       {
                                           petla1=n-1;
                                           while(k<petla1)
                                           {
                                               zamiana=k+1;
                                               zamiana2=lista[k].pozycja;
                                               lista[k]=lista[zamiana];
                                               lista[k].pozycja=zamiana2;
                                               k++;
                                           }
                                           n--;
                                           numer--;
                                           puts(" 0 - dane nowego zawodnika | 1 - sortowanie po nazwiskach |\n 2 - sortowanie po czasach | 3 - edycja wybranych danych |\n 4 - usun wybrane dane | 5 - koniec\n");
                                       }
                                    }
                                    else
                                    {
                                        petla1=n-1;
                                        if(k==petla1)
                                        {
                                            printf("Nie ma takiej osoby!\n");
                                            puts(" 0 - dane nowego zawodnika | 1 - sortowanie po nazwiskach |\n 2 - sortowanie po czasach | 3 - edycja wybranych danych |\n 4 - usun wybrane dane | 5 - koniec\n");
                                        }
                                    }
                                }
                                else
                                {
                                    petla1=n-1;
                                    if(k==petla1)
                                    {
                                        printf("Nie ma takiej osoby!\n");
                                        puts(" 0 - dane nowego zawodnika | 1 - sortowanie po nazwiskach |\n 2 - sortowanie po czasach | 3 - edycja wybranych danych |\n 4 - usun wybrane dane | 5 - koniec\n");
                                    }
                                }
                            }
                        }
                        else
                        {
                            if(komenda==5)
                            {
                                return 0;
                            }
                            else
                            {
                                puts(" 0 - dane nowego zawodnika | 1 - sortowanie po nazwiskach |\n 2 - sortowanie po czasach | 3 - edycja wybranych danych |\n 4 - usun wybrane dane | 5 - koniec\n");
                            }
                        }
                    }
                }
            }
        }
    }
}
