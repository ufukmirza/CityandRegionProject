#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sehir{

int plaka;
char isim[100];
char bolge[100];
int komsu_sayisi;
struct Sehir *next;
struct Sehir *prev;

struct Komsu{

char isim[100];
int plaka;
char bolge[100];

struct Komsu  *next;
}*komsu;


};


struct Komsu *komsudolas;
struct Sehir *sehirdolas,*sehir=NULL,*sehirdolas_2=NULL;


void Bonus(){

int min,max;
char cumle[100],*parcala;

struct Komsu *ilkkomsu;
int komsusayisi=0,karsila=0;

printf("mimumum komsu sayisi:");
scanf("%d",&min);
printf("maksimum komsu sayisi:");
scanf("%d",&max);
printf("\nsehrin bulundurmasi gereken komsulari komsu,komsu,.. seklinde  giriniz:\n");
scanf("%s",cumle);
struct Komsu *komsuekle=(struct Komsu*)malloc(sizeof(struct Komsu));
parcala=strtok(cumle,",");
komsusayisi++;
strcpy(komsuekle->isim,parcala);
ilkkomsu=komsuekle;
komsudolas=ilkkomsu;
while((parcala=strtok(NULL,","))!=NULL){

    struct Komsu *komsuekle=(struct Komsu*)malloc(sizeof(struct Komsu));
    strcpy(komsuekle->isim,parcala);
    komsudolas->next=komsuekle;
    komsuekle->next=NULL;
    komsudolas=komsuekle;
    komsusayisi++;



}


sehirdolas=sehir;
while(sehirdolas!=NULL){
    karsila=0;
    if(sehirdolas->komsu_sayisi>=min&&sehirdolas->komsu_sayisi<=max){

        komsudolas=sehirdolas->komsu;
        struct Komsu *komsudolas1;
        while(komsudolas!=NULL){
            komsudolas1=ilkkomsu;

            while(komsudolas1!=NULL){


                if(strcmp(komsudolas->isim,komsudolas1->isim)==0)
                    karsila++;

         komsudolas1=komsudolas1->next;

            }

            komsudolas=komsudolas->next;

        }

        if(karsila==komsusayisi){

        printf("\n%d,%s,%s",sehirdolas->plaka,sehirdolas->isim,sehirdolas->bolge);

        }

    }




sehirdolas=sehirdolas->next;
}

}

void komsusayisisirala(){

printf("\n\nminimum komsu sayisini giriniz(girilen sayi da dahil edilecektir):");
int komsusayisi;
scanf("%d",&komsusayisi);
sehirdolas=sehir;
while(sehirdolas!=NULL){

    if(sehirdolas->komsu_sayisi>=komsusayisi){

                printf("\n%d,%s,%s",sehirdolas->plaka,sehirdolas->isim,sehirdolas->bolge);


    }

    sehirdolas=sehirdolas->next;

}



}


void bolgesirala(){


printf("\n\nlutfen bolge giriniz:");
char bolge[10];
scanf("%s",bolge);
sehirdolas=sehir;
while(sehirdolas!=NULL){

    if(strcmp(sehirdolas->bolge,bolge)==0){

        printf("\n%d,%s:%d",sehirdolas->plaka,sehirdolas->isim,sehirdolas->komsu_sayisi);


    }
    sehirdolas=sehirdolas->next;

}

}


void SehirSirala(){
struct Sehir *gosterge1,*gosterge2,*goster1,*goster2;
struct Sehir *temp1,*temp2;

for(goster1=sehir;goster1!=NULL;goster1=goster1->next){

    for(goster2=goster1;goster2!=NULL;goster2=goster2->next){
  gosterge1=goster1;
  gosterge2=goster2;

        if(gosterge1!=sehir&&gosterge1->next==gosterge2&&gosterge1->plaka>gosterge2->plaka){


gosterge1->next=gosterge2->next;
if(gosterge2->next!=NULL)
gosterge2->next->prev=gosterge1;
gosterge2->next=gosterge1;
gosterge1->prev->next=gosterge2;
gosterge2->prev=gosterge1->prev;
gosterge1->prev=gosterge2;
goster1=gosterge2;
goster2=gosterge1;
}

else if(gosterge1!=sehir&&gosterge1->next!=gosterge2&&gosterge1->plaka>gosterge2->plaka){

temp1=gosterge1->next;
temp2=gosterge2->prev;
gosterge1->next=gosterge2->next;
if(gosterge2->next!=NULL)
gosterge2->next->prev=gosterge1;
gosterge2->next=temp1;
temp1->prev=gosterge2;
temp2->next=gosterge1;
gosterge1->prev->next=gosterge2;
gosterge2->prev=gosterge1->prev;
gosterge1->prev=temp2;
goster1=gosterge2;
goster2=gosterge1;

}

else if(gosterge1->next==gosterge2&&gosterge1==sehir&&gosterge1->plaka>gosterge2->plaka){


gosterge1->next=gosterge2->next;
gosterge2->next->prev=gosterge1;
gosterge2->next=gosterge1;
gosterge1->prev=gosterge2;
sehir=gosterge2;
goster1=gosterge2;
goster2=gosterge1;

}

else if(gosterge1==sehir&&gosterge1->next!=gosterge2&&gosterge1->plaka>gosterge2->plaka){

temp1=gosterge1->next;
temp2=gosterge2->prev;
gosterge1->next=gosterge2->next;
if(gosterge2->next!=NULL)
gosterge2->next->prev=gosterge1;
gosterge2->next=temp1;
temp2->next=gosterge1;
gosterge1->prev=temp2;
temp1->prev=gosterge2;
sehir=gosterge2;

goster1=gosterge2;
goster2=gosterge1;
}

    }


}



}


void bolgeekle(){

sehirdolas=sehir;
int i=0;
while(sehirdolas!=NULL){
    sehirdolas_2=sehir;
    komsudolas=sehirdolas->komsu;
    while(komsudolas!=NULL){

        if(strcmp(komsudolas->isim,sehirdolas_2->isim)==0){
            strcpy(komsudolas->bolge,sehirdolas_2->bolge);
        komsudolas=komsudolas->next;
        i=1;


        }
        if(i==0){
        sehirdolas_2=sehirdolas_2->next;
        }
        if(i==1){
            i=0;
        sehirdolas_2=sehir;

        }
        if(sehirdolas_2==NULL){
            komsudolas=komsudolas->next;
            sehirdolas_2=sehir;
        }
    }
    sehirdolas=sehirdolas->next;
}




}


void plakaekle(){

sehirdolas=sehir;
int i=0;
while(sehirdolas!=NULL){
    sehirdolas_2=sehir;
    komsudolas=sehirdolas->komsu;
    while(komsudolas!=NULL){

        if(strcmp(komsudolas->isim,sehirdolas_2->isim)==0){
            komsudolas->plaka=sehirdolas_2->plaka;
        komsudolas=komsudolas->next;
        i=1;


        }
        if(i==0){
        sehirdolas_2=sehirdolas_2->next;
        }
        if(i==1){
            i=0;
        sehirdolas_2=sehir;

        }
        if(sehirdolas_2==NULL){
            komsudolas=komsudolas->next;
            sehirdolas_2=sehir;
        }

    }
    sehirdolas=sehirdolas->next;
}


}



void komsusirala(){

sehirdolas=sehir;
struct Komsu *node1,*node2;
char isim[100];
int plaka;


while(sehirdolas!=NULL){

   for(node1=sehirdolas->komsu;node1!=NULL;node1=node1->next){

    for(node2=node1->next;node2!=NULL;node2=node2->next){

        if(node1->plaka>node2->plaka){

    strcpy(isim,node1->isim);
    plaka=node1->plaka;
    strcpy(node1->isim,node2->isim);
    node1->plaka=node2->plaka;
    strcpy(node2->isim,isim);
    node2->plaka=plaka;


        }



    }



   }

    sehirdolas=sehirdolas->next;
   }



}



void Sehirekle(){

int i=0,a=0;
char cumle[150];
char *parcala;
printf("\nsehir eklemek icin 1 i komsuluk eklemek icin 2 yi tiklayiniz");
scanf("%d",&i);

if(i==1){

    printf("\neklemek istediginiz sehri  \"plaka,isim,bolge,komsu,komsu..\"seklinde giriniz ");
    scanf("%s",cumle);
    struct Sehir *sehirekle=(struct Sehir*)malloc(sizeof(struct Sehir));
    parcala=strtok(cumle,",");
    sehirekle->plaka=atoi(parcala);
    parcala=strtok(NULL,",");
    strcpy(sehirekle->isim,parcala);
    parcala=strtok(NULL,",");
    strcpy(sehirekle->bolge,parcala);

        while((parcala=strtok(NULL,","))!=NULL){
            struct Komsu *komsuekle=(struct  Komsu*)malloc(sizeof(struct Komsu));
        if(sehirekle->komsu==NULL){
    strcpy(komsuekle->isim,parcala);
        komsuekle->next=NULL;
        sehirekle->komsu=komsuekle;
        komsudolas=sehirekle->komsu;
                 sehirekle->komsu_sayisi++;

        }
        else{
    strcpy(komsuekle->isim,parcala);
            komsuekle->next=NULL;
            komsudolas->next=komsuekle;
            komsudolas=komsuekle;
         sehirekle->komsu_sayisi++;


        }



}
sehirdolas=sehir;
while(sehirdolas!=NULL){
    if(strcmp(sehirekle->isim,sehirdolas->isim)==0||sehirekle->plaka==sehirdolas->plaka){

        a=1;
        printf("\nayni sehir sistemde mevcut eklenemedi");
        break;

    }
            sehirdolas=sehirdolas->next;

}
    if(a==0){

    if(sehir->plaka>sehirekle->plaka){

        sehirekle->next=sehir;
        sehir->prev=sehirekle;
        sehir=sehirekle;

    }
    else{
                     sehirdolas=sehir;
            while(sehirdolas->next!=NULL&&sehirdolas->next->plaka<sehirekle->plaka)
            sehirdolas=sehirdolas->next;
            if(sehirdolas->next==NULL){
                sehirekle->prev=sehirdolas;
                sehirdolas->next=sehirekle;
            }
            else if(sehirdolas->next!=NULL){

        sehirdolas->next->prev=sehirekle;
        sehirekle->next=sehirdolas->next;
        sehirdolas->next=sehirekle;
        sehirekle->prev=sehirdolas;
            }
    }
          plakaekle();
        komsusirala();
        bolgeekle();
    }


}

if(i==2){

    printf("komsu eklemek istediginiz sehrin plakasini giriniz");
    int plaka;
    scanf("%d",&plaka);
    sehirdolas=sehir;
    while(sehirdolas!=NULL){

    if(sehirdolas->plaka==plaka){

        komsudolas=sehirdolas->komsu;
        struct Komsu *komsuekle=(struct Komsu*)malloc(sizeof(struct Komsu));
        while(komsudolas->next!=NULL)
            komsudolas=komsudolas->next;
        printf("\n%d plaka numaraki sehre eklmek istediginiz komsuyu isim,plaka,bolge seklinde giriniz: ",sehirdolas->plaka);
        scanf("%s",cumle);
        parcala=strtok(cumle,",");
        strcpy(komsuekle->isim,parcala);
        parcala=strtok(NULL,",");
        komsuekle->plaka=atoi(parcala);
        parcala=strtok(NULL,",");
        strcpy(komsuekle->bolge,parcala);
                komsudolas=sehirdolas->komsu;

        while(komsudolas!=NULL){
            if(komsudolas->plaka==komsuekle->plaka||strcmp(komsudolas->isim,komsuekle->isim)==0){
                printf("\n eklemek istediginiz komsu zaten mevcut ekleyemezsiniz\n");
                a=2;
                goto bitir;
            }
            komsudolas=komsudolas->next;
        }
        komsudolas=sehirdolas->komsu;
        if(sehirdolas->komsu->plaka>komsuekle->plaka){
            komsuekle->next=sehirdolas->komsu;
            sehirdolas->komsu=komsuekle;
            sehirdolas->komsu_sayisi++;
        }
        else{
            while(komsudolas->next!=NULL&&komsudolas->next->plaka<komsuekle->plaka){

            komsudolas=komsudolas->next;

            }
                komsuekle->next=komsudolas->next;
                komsudolas->next=komsuekle;
                sehirdolas->komsu_sayisi++;






        }

        a=1;
        break;
    }
       sehirdolas=sehirdolas->next;

    }
bitir:

    if(a==0)
        printf("\nkomsu eklenemedi cunku girdiginiz plakayi bulunduran sehir yoktur\n");





}




}

void Sehirsirala(){

int i=0,a=0;
sehirdolas=sehir;
printf("\nsehir ozelliklerine bakmak istiyorsaniz\nplaka girmek icin 1 i isim girmek icin 2 yi tiklayiniz");
scanf("%d",&i);
if(i==1){

    printf("\n lutfen bakmak istediginiz sehrin plakasini giriniz");
    int plaka;
    scanf("%d",&plaka);
    sehirdolas=sehir;
    while(sehirdolas!=NULL){

    if(plaka==sehirdolas->plaka){
        a=1;
    printf("\n%d,%s:%d,%s",sehirdolas->plaka,sehirdolas->isim,sehirdolas->komsu_sayisi,sehirdolas->bolge);
    komsudolas=sehirdolas->komsu;
    while(komsudolas!=NULL){
        printf(",%s:%s:%d",komsudolas->isim,komsudolas->bolge,komsudolas->plaka);
     komsudolas=komsudolas->next;
    }

    }

    sehirdolas=sehirdolas->next;
    }

    if(a==0){
        printf("\ngirdiginiz plakaya ait sehir yoktur eklemek ister misiniz?(evet:E\\hayir:H)");
     char tercih;
     scanf("%s",&tercih);
     if(tercih=='E')
        Sehirekle();
    }


}
if(i==2){
printf("\nlutfen girmek istediginiz sehrin ismini giriniz");
char isim[50];
scanf("%s",isim);
sehirdolas=sehir;
while(sehirdolas!=NULL){
    if(strcmp(sehirdolas->isim,isim)==0){

              a=1;
    printf("\n%d,%s:%d,%s",sehirdolas->plaka,sehirdolas->isim,sehirdolas->komsu_sayisi,sehirdolas->bolge);
    komsudolas=sehirdolas->komsu;
    while(komsudolas!=NULL){
        printf(",%s:%s:%d",komsudolas->isim,komsudolas->bolge,komsudolas->plaka);
     komsudolas=komsudolas->next;
    }

    }
sehirdolas=sehirdolas->next;


}


    if(a==0){
        printf("\ngirdiginiz plakaya ait sehir yoktur eklemek ister misiniz?(evet:E\\hayir:H)");
     char tercih;
     scanf("%s",&tercih);
     if(tercih=='E')
        Sehirekle();
    }



}
}

void Sehirsil(){

int i,a=0;
printf("\n\nsehir silmek icin 1 i komsuluk silmek icin 2 yi tiklayiniz");
scanf("%d",&i);

sehirdolas=sehir;

if(i==1){
    int plaka;
    printf("\nlutfen silmek istediginiz sehrin plakasini giriniz: ");
    scanf("%d",&plaka);
    if(plaka==sehir->plaka){

        struct Sehir *goster;
        goster=sehir;
        sehir=sehir->next;
        free(goster);
        a=1;

    }

    else{

        while(sehirdolas!=NULL){

            if(sehirdolas->next!=NULL&&sehirdolas->plaka==plaka){
        a=1;

                struct Sehir *temp_1,*temp_2;
                temp_1=sehirdolas->prev;
                temp_2=sehirdolas->next;
                temp_1->next=temp_2;
                temp_2->prev=temp_1;
                free(sehirdolas);


            }
            else if(sehirdolas->next==NULL&&sehirdolas->plaka==plaka){
                            a=1;

                  struct Sehir *temp_1;
                  temp_1=sehirdolas->prev;
                  temp_1->next=NULL;
                 free(sehirdolas);

            }

            sehirdolas=sehirdolas->next;
        }

    }


if(a==0){
    printf("\ngirdiginiz plakaya ait sehir yoktur");
}


}

if(i==2){
        sehirdolas=sehir;
    int plaka;
    printf("\n\nkomsusunu silmek istediginiz sehrin plakasini  giriniz:");
    scanf("%d",&plaka);
    while(sehirdolas!=NULL&&sehirdolas->plaka!=plaka)
        sehirdolas=sehirdolas->next;
        if(sehirdolas!=NULL){
    printf("\n%d plakali sehirden silmek istediginiz komsunun plakasini giriniz",sehirdolas->plaka);
    scanf("%d",&plaka);
    if(sehirdolas->komsu->plaka==plaka){
                    struct Komsu *goster;

        goster=sehirdolas->komsu->next;
        free(sehirdolas->komsu);
        sehirdolas->komsu=goster;
        a=1;
      sehirdolas->komsu_sayisi--;

    }
    else{

            komsudolas=sehirdolas->komsu;
while(komsudolas->next!=NULL){


    if(komsudolas->next->next==NULL&&komsudolas->next->plaka==plaka){
                struct Komsu *goster;
                goster=komsudolas->next;
                free(goster);
                komsudolas->next=NULL;
                a=1;
                sehirdolas->komsu_sayisi--;

                            break;


    }

    else if(komsudolas->next->next!=NULL&&komsudolas->next->plaka==plaka){
                    struct Komsu *goster_1,*goster_2;
            goster_1=komsudolas->next->next;
            goster_2=komsudolas->next;
            komsudolas->next=goster_1;
            free(goster_2);
            a=1;
        sehirdolas->komsu_sayisi--;

            break;

}

komsudolas=komsudolas->next;


    }






}
        }
          if(a==0&&sehirdolas!=NULL)
            printf("\n\ngirdiginiz komsu plakasi sehirde mevcut degildir");
        if(sehirdolas==NULL)
            printf("\n\ngirdiginiz plakaya ait sehir bulunamadi");



}


}



FILE *file;
char cumle[150];
int main()
{
    int i=0;
    char *parcala;
     // printf("as\n");
    file=fopen("sehirler.txt","r");
    while(fgets(cumle,150,file)){
   struct Sehir *sehirekle=(struct  Sehir*)malloc(sizeof(struct Sehir));
if(sehir==NULL){

    parcala=strtok(cumle,",");
    sehirekle->plaka=atoi(parcala);
    parcala=strtok(NULL,",");
    strcpy(sehirekle->isim,parcala);
        parcala=strtok(NULL,",");
    strcpy(sehirekle->bolge,parcala);
    sehir=sehirekle;
    sehir->next=NULL;
    sehirdolas=sehirekle;

    while((parcala=strtok(NULL,","))!=NULL){

            struct Komsu *komsuekle=(struct  Komsu*)malloc(sizeof(struct Komsu));
        if(sehirekle->komsu==NULL){
                char *harf;
                 if((harf=strchr(parcala,'\n'))!=NULL)
                    *harf='\0';
    strcpy(komsuekle->isim,parcala);
    komsuekle->plaka=0;
        komsuekle->next=NULL;
        sehirekle->komsu=komsuekle;
        komsudolas=sehir->komsu;
         sehirekle->komsu_sayisi++;
        }
        else{
char *harf;
                 if((harf=strchr(parcala,'\n'))!=NULL)
                    *harf='\0';
    strcpy(komsuekle->isim,parcala);
        komsuekle->plaka=0;

            komsuekle->next=NULL;
            komsudolas->next=komsuekle;
            komsudolas=komsuekle;
         sehirekle->komsu_sayisi++;


        }


    }



}
else{
    parcala=strtok(cumle,",");
    sehirekle->plaka=atoi(parcala);
    parcala=strtok(NULL,",");
   strcpy(sehirekle->isim,parcala);
    parcala=strtok(NULL,",");
    strcpy(sehirekle->bolge,parcala);
        while((parcala=strtok(NULL,","))!=NULL){
            struct Komsu *komsuekle=(struct  Komsu*)malloc(sizeof(struct Komsu));
        if(sehirekle->komsu==NULL){
                char *harf;
                 if((harf=strchr(parcala,'\n'))!=NULL)
                    *harf='\0';
    strcpy(komsuekle->isim,parcala);
        komsuekle->plaka=0;

        komsuekle->next=NULL;
        sehirekle->komsu=komsuekle;
        komsudolas=sehirekle->komsu;
                 sehirekle->komsu_sayisi++;

        }
        else{
                char *harf;
                 if((harf=strchr(parcala,'\n'))!=NULL)
                    *harf='\0';
    strcpy(komsuekle->isim,parcala);
        komsuekle->plaka=0;

            komsuekle->next=NULL;
            komsudolas->next=komsuekle;
            komsudolas=komsuekle;
         sehirekle->komsu_sayisi++;


        }



}

  sehirdolas->next=sehirekle;
        sehirekle->next=NULL;
        sehirekle->prev=sehirdolas;
        sehirdolas=sehirekle;


    }



}


sehirdolas=sehir;


fclose(file);
i=0;
sehirdolas=sehir;
int a=0;
while(sehirdolas!=NULL){
    sehirdolas_2=sehir;
    komsudolas=sehirdolas->komsu;
    while(komsudolas!=NULL){

        if(strcmp(komsudolas->isim,sehirdolas_2->isim)==0){
            komsudolas->plaka=sehirdolas_2->plaka;
        komsudolas=komsudolas->next;
        i=1;


        }
        if(i==0){
        sehirdolas_2=sehirdolas_2->next;
        }
        if(i==1){
            i=0;
        sehirdolas_2=sehir;

        }
        if(sehirdolas_2==NULL){
            komsudolas=komsudolas->next;
            sehirdolas_2=sehir;
        }

    }
    sehirdolas=sehirdolas->next;
}
SehirSirala();
bolgeekle();
komsusirala();
sehirdolas=sehir;
while(sehirdolas!=NULL){

    printf("%d  %s  %s : %d ",sehirdolas->plaka,sehirdolas->isim,sehirdolas->bolge,sehirdolas->komsu_sayisi);
    komsudolas=sehirdolas->komsu;
   while(komsudolas!=NULL){

        printf("%s:%d:%s   ",komsudolas->isim,komsudolas->plaka,komsudolas->bolge);
        komsudolas=komsudolas->next;

    }
    sehirdolas=sehirdolas->next;
    printf("\n");


}

while(i!=7){

printf("\n\n1-sehir ve komsuluk ekleme\n2-sehir ozelliklerini siralama\n3-sehir\\komsuluk kaydi silme\n4-bolgedeki sehirler ve ozellikleri\n5-minimum komsu sayisina gore sehir listeleme\n6-Bonus\n7-Cikis");
printf("\n menude secmek isteginiz seyi giriniz");
scanf("%d",&i);

switch(i){

case 1:

    Sehirekle();
    break;

case 2:

    Sehirsirala();
     break;

case 3:
    Sehirsil();
    break;

case 4:
    bolgesirala();
    break;

case 5:
    komsusayisisirala();
    break;

case 6:
    Bonus();
    break;

}


}

sehirdolas=sehir;
while(sehirdolas!=NULL){

    printf("%d  %s  %s : %d ",sehirdolas->plaka,sehirdolas->isim,sehirdolas->bolge,sehirdolas->komsu_sayisi);
    komsudolas=sehirdolas->komsu;
   while(komsudolas!=NULL){

        printf("%s:%d ",komsudolas->isim,komsudolas->plaka);
        komsudolas=komsudolas->next;

    }
    sehirdolas=sehirdolas->next;
    printf("\n");


}


sehirdolas=sehir;
file=fopen("cikti.txt","w");
while(sehirdolas!=NULL){

    fprintf(file,"%d,%s:%d,%s",sehirdolas->plaka,sehirdolas->isim,sehirdolas->komsu_sayisi,sehirdolas->bolge);
    komsudolas=sehirdolas->komsu;
   while(komsudolas!=NULL){

        fprintf(file,"->%d",komsudolas->plaka);
        komsudolas=komsudolas->next;

    }
    fprintf(file,"\n");
        sehirdolas=sehirdolas->next;


}

fclose(file);


}

