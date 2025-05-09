#include <stdio.h>
#include <time.h>

char name[30];
int dip_atm, balansi = 10000, ang_no=35145;
int PSWRD = 1234;  
int custPSWRD;  

void fulis_charicxva();
void fulis_amoyeba();
void fulis_gadaricxva();
void angarishis_detalebi();
void bolo_detali();

void menu();

int main(){
    int arc;
    int error = 0;


    do {
        printf("Sheigvanet PIN kodi: ");
        scanf("%d", &custPSWRD);
        error++;
            if (custPSWRD != PSWRD) 
            printf("xelaxla daweret. \n");
        }
     while (error < 3 && (PSWRD != custPSWRD));

    if (PSWRD == custPSWRD) {
        printf("PIN kodi sworia.\n");

        printf("Sheigvanet tqveni saxeli: ");  
        scanf("%s",name);

        menu();
        printf("Romel operacias archevt: ");
        scanf("%d", &arc);

        switch (arc) {
            case 1:
                fulis_charicxva();
                break;
            case 2:
                fulis_amoyeba();
                break;
            case 3:
                fulis_gadaricxva();
                break;
            case 4:
                angarishis_detalebi();
                break;
            case 5:
                bolo_detali();
                break;
            default:
                printf("araswori archevani !!!\n");
                break;
        }
    } else {
        printf("PIN kodi arasworia da tqveni barati dablokilia.\n");
    }

    return 0;
}

void menu(){
    printf(" MTAVARI MENU\n");
    printf("1. Fulis charicxva\n");
    printf("2. Fulis amoyeba\n");
    printf("3. Fulis gadaricxva\n");
    printf("4. Angarishis detalebi\n");
    printf("5. Bolo detalebi\n");
    printf("6. Exit\n");
}

void fulis_charicxva(){
    FILE *fp;
    fp = fopen("C:\\Users\\user\\Desktop\\spartakis1.txt", "a");  
    printf(" Fulis charicxva\n");
    printf("sheiyvanet tanxa: ");
    scanf("%d", &dip_atm);
    
    balansi += dip_atm;
    printf("fuli charicxulia\n");
    printf("Mimdinare balansi: %d\n", balansi);
    
    time_t tm;
    time(&tm);  
    
    fprintf(fp, "%d-Lari Charicxulia tqven angarishze\n", dip_atm);
    fprintf(fp, "tarigi: %s\n", ctime(&tm));  
    fclose(fp);
}

void fulis_amoyeba(){
    FILE *fp;
    fp = fopen("C:\\Users\\user\\Desktop\\spartakis1.txt", "a");  
    printf(" Fulis amoyeba\n");
    printf("sheiyvanet amxarari tanxa: ");
    scanf("%d", &dip_atm);
    
    if(balansi >= dip_atm) {
        balansi -= dip_atm;
        printf("puli amoyebulia\n");
        printf("Mimdinare balansi: %d\n", balansi);
        
        time_t tm;
        time(&tm);  
        
        fprintf(fp, "%d-Lari amoyebulia tqven angarishze\n", dip_atm);
        fprintf(fp, "tarigi: %s\n", ctime(&tm)); 
    } else {
        printf("ar aris sakmarisi tanxa!\n");
    }
    fclose(fp);
}

void fulis_gadaricxva(){
    int recipient_account, gagztanxa;
    FILE *fp;

    fp = fopen("C:\\Users\\user\\Desktop\\spartakis1.txt", "a");  

    printf(" Fulis gadaricxva\n");
    printf("Sheiyvanet angarishis nomeri: ");
    scanf("%d", &recipient_account);  

    printf("Sheiyvanet tanxa (amount to send): ");
    scanf("%d", &gagztanxa);  

    if (balansi >= gagztanxa) {
        balansi -= gagztanxa;  
        printf("Puli gadaricxulia\n");
        printf("Mimdinare balansi: %d\n", balansi);

        time_t tm;
        time(&tm);  
        
        fprintf(fp, "%d-Lari gadaricxulia tqven angarishze da %d angarishis nomershi\n", gagztanxa, recipient_account);
        fprintf(fp, "tarigi: %s\n", ctime(&tm));  
    } else {
        printf("ar aris sakmarisi tanxa!\n"); 
    }

    fclose(fp);  
}

void angarishis_detalebi(){
    printf(" Angarishis Detalebi:\n");
    printf("Tqveni Angarishis nomeri: %d\n", ang_no);
    printf("Saxeli: %s\n", name);
    printf("Mimdinare balansi: %d\n", balansi);
    
    time_t tm;
    time(&tm);  
    printf("tarigi: %s\n", ctime(&tm));  
}


void bolo_detali(){
    printf(" Bolos detali:\n");
    printf("Angarishi nomeri: %d\n", ang_no);
    printf("Saxeli: %s\n", name);
    printf("Mimdinare balansi: %d\n", balansi);
    printf("Mimdinare tanxa: %d\n", dip_atm);
    
    time_t tm;
    time(&tm); 
    printf("tarigi: %s\n", ctime(&tm));  
}
