#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct simpul
{
	char nama[25];
	int nrp;
    struct simpul *before;
	struct simpul *next;

};

struct simpul *baru=NULL, *head, *tail;

struct simpul* alokasi_memori()
{
    struct simpul * pertama;
    pertama=(struct simpul*)malloc(sizeof(struct simpul));

    if (pertama==NULL)
        return NULL;
    else
    {
        pertama->next=NULL;
        pertama->before=NULL;
        return pertama;
    }
}
void mengisi();
void tampilLIFO();
void tampilLIFO();
struct simpul *cari (int nrpcari);
void hapus();
void tambahakhir();
void tambahstl();
void tambahsbl();

main()
{
    int pil,nrpcari;
    struct simpul *hslcari;
    char jawab[2];
    while(1)
    {
        printf("Menu: \n");
        printf("1. Membuat Double Linked List.\n");
        printf("2. Menampilkan FIFO.\n");
        printf("3. Menampilkan LIFO.\n");
        printf("4. Mencari.\n");
        printf("5. Menghapus.\n");
        printf("6. Menambah di akhir. \n");
        printf("7. Menambah setelah simpul. \n");
        printf("8. Menambah sebelum simpul. \n");
        printf("\nMasukkan Pilihan : ");
        scanf("%d", &pil);
        switch (pil){
            case 1:
                mengisi();
                break;
            case 2:
                tampilFIFO();
                break;
            case 3:
                tampilLIFO();
                break;
            case 4:
                printf("Masukkan nrp yang dicari : ");
                scanf("%d", &nrpcari);
                hslcari=cari(nrpcari);
                printf("%s %d\n", hslcari->nama, hslcari->nrp);
                break;
            case 5:
                hapus();
                break;
            case 6:
                tambahakhir();
                break;
            case 7:
                tambahstl();
                break;
            case 8:
                tambahsbl();
                break;
        }
    }
}

void mengisi()
{
    int j=0;
    char jawab[2];
    while (1)
    {
        baru=alokasi_memori();
        if (baru==NULL)
            printf("Data Kosong\n");
        else
        {
            printf("Nama   : ");
            scanf("%s", &baru->nama);
            printf("NRP    : ");
            scanf("%d", &baru->nrp);
            if (j==0)
            {
                head=baru;
                tail=baru;
            }
            else
            {
                tail->next=baru;
                baru->before=tail;
                tail=baru;
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

void tampilFIFO()
{
    struct simpul *bacaFIFO;

    bacaFIFO = head;
    while (bacaFIFO!=NULL)
    {
        printf("%s\t", bacaFIFO->nama);
        printf("%d\n", bacaFIFO->nrp);
        bacaFIFO = bacaFIFO->next;
    }
}

void tampilLIFO()
{
    struct simpul *bacaLIFO;

    bacaLIFO = tail;
    while (bacaLIFO!=NULL)
    {
        printf("%s\t", bacaLIFO->nama);
        printf("%d\n", bacaLIFO->nrp);
        bacaLIFO =  bacaLIFO->before;
    }
}

struct simpul *cari(int nrpcari)
{
    struct simpul *cr;

    cr=head;
    while(cr->nrp!=nrpcari)
        cr=cr->next;

    return cr;
}

void hapus()
{
    int nrphapus;
    struct simpul *hps;

    printf("Masukkan nrp yang mau di hapus : ");
    scanf("%d", &nrphapus);

    hps=head;
    if (head->nrp==nrphapus)
    {
        head=head->next;
        head->before=NULL;
        free(hps);
    }
     else{
        while(hps->nrp!=nrphapus)
            hps = hps->next;
        if (tail->nrp==nrphapus)
        {
            tail=tail->before;
            tail->next=NULL;
            free(hps);
        }
        else
        {
            hps->before->next=hps->next;
            hps->next->before=hps->before;
            free(hps);
        }
     }
     tampilFIFO();
}

void tambahakhir()
{
    struct simpul *baru, *cari;

    baru=alokasi_memori();
    printf("Masukkan Nama baru : ");
    scanf("%s", &baru->nama);
    printf("Masukkan NRP baru : ");
    scanf("%d", &baru->nrp);

    tail->next=baru;
    baru->before=tail;
    tail=baru;

    tampilFIFO();
}

void tambahstl()
{
    int nrpcari;
    struct simpul *stl, *baru;

    printf("Masukkan nrp yang setelahnya ditambah : ");
    scanf("%d", &nrpcari);
    stl=cari(nrpcari);

    baru=alokasi_memori();
    printf("Masukkan nama baru : ");
    scanf("%s", &baru->nama);
    printf("Masukkan nrp baru : ");
    scanf("%s", &baru->nrp);
    if(stl==tail)
    {
        tail->next=baru;
        baru->before=tail;
        tail=baru;
    }
    else
    {
        baru->next=stl->next;
        baru->before=stl;
        stl->next->before=baru;
        stl->next=baru;
    }
    tampilFIFO();
}

void tambahsbl()
{
    int nrpcari;
    struct simpul *stl, *cari, *baru;

    printf("Masukkan nrp yang sebelumnya ditambah : ");
    scanf("%d", &nrpcari);

    baru=alokasi_memori();
    printf("Masukkan nama baru : ");
    scanf("%s", &baru->nama);
    printf("Masukkkan nrp baru : ");
    scanf("%d", &baru->nrp);

    cari=head;
    while(cari->nrp!=nrpcari)
        cari=cari->next;

    if (cari==head)
    {
        cari->next=cari;
        cari->before=baru;
        head=baru;
    }
    else
    {
        baru->next=cari;
        baru->before=cari->before;
        cari->before->next=baru;
        cari->before=baru;
    }
    tampilFIFO();
}



