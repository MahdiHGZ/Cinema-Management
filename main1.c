#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct mo{
    char name[100];
    int time;
    char imdblink[200];
};
struct san {
    int ssalon;
    int ssans;
    time_t t;
    int mov;
    int b[20][20];
};
struct sal{
    int r;
    int s;
    int nsans;
    struct san ss[11];
};



int RQSort(struct san a[],int s,int e) {
    if (s >= e - 1)return 0;
    srand(time(NULL));
    int m = rand() % (e - s) + s;
    int y, z;
    struct san w;
    w = a[m];
    a[m] = a[e - 1];
    a[e - 1] = w;
    z = e - 1;
    y = e + 1;
    for (int i = s; i < e; ++i) {
        if (i == e - 1) {
            if (y < e) {
                w = a[y];
                a[y] = a[z];
                a[z] = w;
            } else {
                y = z;
            }
            break;
        }
        if (a[i].t > a[z].t && y > e) {
            y = i;
        }
        if (a[i].t < a[z].t && y < e) {
            w = a[i];
            a[i] = a[y];
            a[y] = w;
            y++;
        }
    }
    RQSort(a, s, y);
    RQSort(a, y + 1, e);
    return 0;
}
void movr(struct mo x[],int n){
    FILE *p;
    p=fopen("film.txt","r");
    for (int i = 0; i < n; ++i) {
        fscanf(p,"%s %d %s",&x[i].name,&x[i].time,&x[i].imdblink);
    }
    fclose(p);
}
void movw(struct mo x[],int n){
    FILE *p;
    p=fopen("film.txt","w");
    for (int i = 0; i < n; ++i) {
        fprintf(p,"%s %d %s\n",x[i].name,x[i].time,x[i].imdblink);
    }
    fclose(p);
}
void movkesh(struct mo x[],int n){
    for (int i = 0; i < n; ++i) {
        printf("%d:%s\n",i+1,x[i].name);
    }
}
void salonr(struct sal x[],int n) {
    FILE *p;
    p = fopen("salon.txt", "r");
    for (int i = 0; i < n; ++i) {
        fscanf(p, "%d %d %d", &x[i].r, &x[i].s, &x[i].nsans);
        for (int j = 0; j < x[i].nsans; ++j) {
            fscanf(p, "%d %d", &x[i].ss[j].t, &x[i].ss[j].mov);
            x[i].ss[j].ssans = j;
            x[i].ss[j].ssalon = i;
            for (int k = 0; k < x[i].r; ++k) {
                for (int l = 0; l < x[i].s; ++l) {
                    fscanf(p, "%d", &x[i].ss[j].b[k][l]);
                }
            }
        }
    }
    fclose(p);
}
void salonw(struct sal x[],int n){
    FILE *p;
    p=fopen("salon.txt","w");
    for (int i = 0; i < n; ++i) {
        fprintf(p,"%d %d %d\n",x[i].r,x[i].s,x[i].nsans);
        for (int j = 0; j <x[i].nsans; ++j) {
            fprintf(p,"%d %d\n",x[i].ss[j].t,x[i].ss[j].mov);
            for (int k = 0; k <x[i].r; ++k) {
                for (int l = 0; l < x[i].s; ++l) {
                    fprintf(p,"%d ",x[i].ss[j].b[k][l]);
                }
                fprintf(p,"\n");
            }
        }
    }
    fclose(p);
}
void salkesh(struct sal x,int n){
    printf("    ");
    for (int i = 0; i <x.s; ++i) {
        printf("%d ", i+1);
        if(i<9)printf(" ");
    }
    printf("\n");
    for (int j = 0; j < x.r; ++j) {
        printf("%d:",j+1);
        if(j<9)printf(" ");
        for (int i = 0; i < x.s; ++i) {
            if(x.ss[n].b[j][i]==0)printf("%c %c",192,217);
            else printf("%c%c%c",192,223,217);
        }
        printf("\n");
    }
}
int  oksans(struct sal x,time_t t,int tm, struct mo y[]) {
    int i;
    for (i = 0; x.ss[i].t < t; ++i) {
    }
    if (t + tm <= x.ss[i].t) {
        if (x.ss[i - 1].t + y[x.ss[i - 1].mov].time * 60 <= t) {
            return 1;
        }
    }
    return 0;
}
void chaptime(time_t t) {
    long int y, mon, d, h, min;
    y = t / 31104000;
    t %= 31104000;
    mon = t / 2592000;
    t %= 2592000;
    d = t / 86400;
    t %= 86400;
    h = t / 3600;
    t %= 3600;
    min = t / 60;
    printf("   Time: %02ld/%02ld/%02ld %02ld:%02ld\n\n", mon + 1, d + 1, y + 2020, h, min);
}
int addticket(struct sal x[],int n, struct mo movie[],time_t now) {
    int sum = 0, p;
    for (int i = 0; i < n; ++i) {
        sum += x[i].nsans;
    }
    int kk = 0;
    struct san a[sum];
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < x[j].nsans; ++i) {
            a[kk] = x[j].ss[i];
            kk++;
        }
    }
    RQSort(a, 0, sum);
    int gh = 0;
    for (int k = 0; k < sum; ++k) {
        if (a[k].t >= now) {
            printf("%d. Salon:%d\n   Film:%s\n", k + 1 - gh, a[k].ssalon + 1, movie[a[k].mov].name);
            chaptime(a[k].t);
        } else gh++;
    }
    printf("Shomare sans ra wared konid:");
    scanf("%d", &p);
    p += gh;
    salkesh(x[a[p - 1].ssalon], a[p - 1].ssans);
    int r, s;
    printf("Shomare Radif ra wared konid:");
    scanf("%d", &r);
    printf("Shomare Sandali ra wared konid:");
    scanf("%d", &s);
    if (x[a[p - 1].ssalon].ss[a[p - 1].ssans].b[r - 1][s - 1] == 0) {
        x[a[p - 1].ssalon].ss[a[p - 1].ssans].b[r - 1][s - 1] = 1;
        printf("Ticket Kharidari shod\n");
    } else {
        printf("ticket already token\n");
    }
}
int  addsans(struct sal x[],int nsalon ,struct mo y[],int nmovie) {
    int n, a, b, c;
    time_t t;
    for (int i = 0; i < nsalon; ++i) {
        printf("Salon%d: %dx%d\n", i + 1, x[i].r, x[i].s);
    }
    printf("Inter salon's number:");
    scanf("%d", &n);
    movkesh(y, nmovie);
    printf("Inter film's number:");
    scanf("%d", &a);
    printf("Inter time of sans(Year(>2020) Month Day Hour(24) Minute):");
    long long int ye, mo, d, h, mi;
    scanf("%d %d %d %d %d", &ye, &mo, &d, &h, &mi);
    ye -= 2020;
    mo--;
    mo += ye * 12;
    d--;
    d += 30 * mo;
    h += 24 * d;
    mi += 60 * h;
    t = mi * 60;
    t += 10;
    if (oksans(x[n - 1], t, y[a - 1].time, y)) {
        x[n - 1].ss[x[n - 1].nsans].t = t;
        x[n - 1].ss[x[n - 1].nsans].mov = a - 1;
        x[n - 1].nsans++;
        RQSort(x[n - 1].ss, 0, x[n - 1].nsans);
        printf("sans successfully added \n");
    } else {
        printf("The period is already token !!");
    }
}
/********************************************************
 *
 * Mahdi HGZ
 *
 ********************************************************/
int main() {
    int x = 1, y, m, n, q, nmov, nsalon;
    time_t now;
    time(&now);
    now -= 1577824219;
    //printf("Time=%ld\n",now);
    chaptime(now);
    FILE *p;
    p = fopen("data.txt", "r");
    fscanf(p, "%d\n%d", &nmov, &nsalon);
    fclose(p);
    struct mo movie[nmov + 10];
    movr(movie, nmov);
    struct sal salon[nsalon];
    salonr(salon, nsalon);
    //salkesh(salon[0],1);
    //movkesh(movie,nmov);
    //addsans(salon,nsalon,movie,nmov);
    //addticket(salon,nsalon,movie,now);
    while (x) {
        printf("************************************************************************************\n");
        printf("1.Add Sans\n2.Take Ticket\n3.Add Movie\n4.Add Salon\n5.Exit\n");
        printf("Shomare morede nazar ra wared konid:");
        scanf("%d", &x);
        if (x == 1)addsans(salon, nsalon, movie, nmov);
        if (x == 2)addticket(salon, nsalon, movie, now);
        if (x == 5)x = 0;
    }
    salonw(salon, nsalon);
    movw(movie, nmov);
    p = fopen("data.txt", "w");
    fprintf(p, "%d\n%d", nmov, nsalon);
    fclose(p);
    return 0;
}