#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct simpul{
    char nama[25];
    int NRP;
    struct simpul *next;
};//deklarasi simpul

struct simpul *ujung=NULL;

void bangun();
void tampil();

main()
{
    bangun();
    tampil();
}

void bangun()
{
    struct simpul *tanda, *cari, *baru, *rear;
    int j = 0;
    char jawab[2];
    while(1)
    {
        baru = (struct simpul*)malloc(sizeof(struct simpul));
        printf("Nama    : ");
        scanf("%s", &baru->nama);
        printf("NRP     : ");
        scanf("%d", &baru->NRP);
        baru->next=NULL;

        if(j==0)
        {
            ujung = baru;
            rear = baru;
        }
        else
        {
            cari=ujung;
            if(cari->next==NULL)
            {
                if(baru->NRP<cari->NRP)
                {
                    baru->next=cari;
                    ujung=baru;
                }
                else
                {
                    cari->next=baru;
                    rear=baru;
                }
            }
            else if(baru->NRP<cari->NRP)
            {
                baru->next=cari;
                ujung=baru;
            }
            else
            {
                while(baru->NRP>cari->NRP)
                {
                    tanda=cari;
                    cari=cari->next;
                }
                if(tanda==rear)
                {
                    tanda->next=baru;
                    rear=baru;
                }
                else
                {
                    tanda->next=baru;
                    baru->next=cari;
                }
            }
        }
        printf("Apakah ada data lagi (y/t) : ");
        scanf("%s", &jawab);
        if((strcmp(jawab, "Y")==0)||(strcmp(jawab, "y")==0))
        {
            j++;
            continue;
        }
        else if((strcmp(jawab, "T")==0)||(strcmp(jawab, "t")==0))
        break;
    }
}

void tampil()
{
    struct simpul *tampil;

    if(ujung==NULL)
        printf("Kosong!\n");
    else
    {
        tampil=ujung;
        while(tampil != NULL)
        {
        printf("\n%s \t%d", tampil->nama, tampil->NRP);
        tampil = tampil->next;
        }
    }
}
