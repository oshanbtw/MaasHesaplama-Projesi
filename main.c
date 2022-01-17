#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>


float ToplamNet (float maas [], int kisi);
float ToplamVergi (float vergi[], int kisi);
float OrtalamaBrut (float brut [], int kisi);
float OrtalamaNet (float net[], int kisi);
int AzMaas (float net[], int kisi);
int EvliBekar (char medeni[], int kisi);


int main()
{
	system("color 03"); //Arkaplan rengini deðiþtirmek için.
    int calisanSayisi;
    do{
        printf("Kac Calisan Icin Islem Yapilacak (Cikmak Icin 0):");
        scanf("%d", &calisanSayisi);
    }while(calisanSayisi<0);
    if(calisanSayisi == 0){
        printf("Calisan Bulunmamaktadir.\n");
        exit(1);
    }
    int i, sayac = 0, calisanCocuk[calisanSayisi], calisanKCocuk[calisanSayisi], calisanBCocuk[calisanSayisi], calisanEngelOran[calisanSayisi], j, temp, para, para2, bank200, temp2, bank100, bank50, bank20, bank10, bank5, bank1;
    long long int calisanTC[calisanSayisi];
    char calisanIsimSoyisim[calisanSayisi][30], calisanMedeni[calisanSayisi], calisanEs[calisanSayisi], calisanEngel[calisanSayisi], temp4[calisanSayisi][30];
    float calisanBrut[calisanSayisi], calisanTopBrut[calisanSayisi], calisanVergi[calisanSayisi], calisanNet[calisanSayisi], para3, temp3;

    for(i=0; i<calisanSayisi; i++) //Calisan Bilgilerini Girme Ekrani
        {
        printf("******************************\n");
		printf("%d. Calisanin TC No:", i+1);
        scanf("%lld", &calisanTC[i]);
        fflush(stdin);
        printf("%d. Calisanin Adi ve Soyadi:", i+1);
        gets(calisanIsimSoyisim[i]);
        printf("%d. Calisanin Aylik Brut Ucreti:", i+1);
        scanf("%f", &calisanBrut[i]);
        if(calisanBrut[i] < 1777.50){
        	calisanBrut[i] = 1777.50;
		}
        fflush(stdin);
        do{
        	printf("%d. Calisanin Medeni Durumu (E-e/B-b):", i+1);
        	scanf("%c", &calisanMedeni[i]);
        	fflush(stdin);
		}while(calisanMedeni[i] != 'E' && calisanMedeni[i] != 'e' && calisanMedeni[i] != 'B' && calisanMedeni[i] != 'b');
		if(calisanMedeni[i] == 'E' || calisanMedeni[i] == 'e'){
			do{
				printf("%d. Calisanin Esi Calisiyor Mu (E-e/H-h):", i+1);
				scanf("%c", &calisanEs[i]);
				fflush(stdin);
			}while(calisanEs[i] != 'E' && calisanEs[i] != 'e' && calisanEs[i] != 'H' && calisanEs[i] != 'h');
		}
		else{
			calisanEs[i] = 'y';			//'Y' Koymamon sebebi eðer e ve h koyarsam esi olmadigi halde calisiyor ve calismiyor anlamýna gelmesi. Bundan dolayi herhangi bir harf koydum.
		}
		do{
			printf("%d. Calisanin Bakmakla Yukumlu Cocuk Sayisi:", i+1);
			scanf("%d", &calisanCocuk[i]);
			fflush(stdin);
		}while(calisanCocuk[i] < 0);
		if(calisanCocuk[i] > 0){
			do{
				printf("6 Yasindan Kucuklerin Sayisi:");
				scanf("%d", &calisanKCocuk[i]);
				fflush(stdin);
			}while(calisanKCocuk < 0);
		}
		else{
			calisanKCocuk[i] = 0;
		}
		if(calisanCocuk[i] > 0){																		//Bu kýsýmda calisanin buyuk ve kucuk couklarýný kaydettim.
			calisanBCocuk[i] = calisanCocuk[i]-calisanKCocuk[i];
		}
		else{
			calisanBCocuk[i] = 0;
		}
		do{
			printf("%d. Calisan Engelli mi (E-e/H-h):", i+1);
			scanf("%c", &calisanEngel[i]);
			fflush(stdin);
		}while(calisanEngel[i] != 'E' && calisanEngel[i] != 'e' && calisanEngel[i] != 'H' && calisanEngel[i] != 'h');
		if(calisanEngel[i] == 'E' || calisanEngel[i] == 'e'){
			do{
				printf("%d. Calisanin Engellilk Orani (Min 0):", i+1);
				scanf("%d", &calisanEngelOran[i]);
				fflush(stdin);
			}while(calisanEngelOran[i] < 0);
		}
		else{
			calisanEngelOran[i] = 0;
		}
		printf("******************************\n");
		fflush(stdin);
    }
    
    for(j=0; j<calisanSayisi; j++) // Calisan Bilgilerini ve Maas Bilgilerini Yazdirma Ekraný
    	{
    	
    	printf("\t\t\t\t****************%d. CALISAN BILGILERI***************\n", j+1);
		printf("\t\t\t\t--> %lld TC Kimlik Numrali %s\n", calisanTC[j], calisanIsimSoyisim[j]);
    	printf("\t\t\t\t--> Aylik Brut Ucret: %.2f TL \n", calisanBrut[j]);
    	if(calisanEs[j] == 'E' || calisanEs[j] == 'e' || calisanEs[j] == 'y'){
    		printf("\t\t\t\t--> Es Icin Aile Yardimi Odenegi: 0 TL \n");
		}
		else{
			printf("\t\t\t\t--> Es Icin Aile Yardimi Odenegi: 220 TL \n");
		}
		if(calisanBCocuk[j] > 0){
			printf("\t\t\t\t--> Buyuk Cocuk Icin Aile Odenegi: %d TL \n", (calisanBCocuk[j]*45));
		}
		else{
			printf("\t\t\t\t--> Buyuk Cocuk Icin Aile Odenegi: 0 TL \n");
		}
		if(calisanKCocuk[j] > 0){
			printf("\t\t\t\t--> Kucuk Cocuk Icin Aile Odenegi: %d TL \n", (calisanKCocuk[j]*25));
		}
		else{
			printf("\t\t\t\t--> Kucuk Cocuk Icin Aile Odenegi: 0 TL \n");
		}
		temp = 0;
		temp = (calisanBCocuk[j]*45) + (calisanKCocuk[j]*25);
		if(calisanEs[j] == 'H' || calisanEs[j] == 'h'){
			temp += 220;
		}
		calisanTopBrut[j] += temp;
		calisanTopBrut[j] += calisanBrut[j];
		printf("\t\t\t\t--> Aylik Toplam Brut Ucret: %.2f TL \n", calisanTopBrut[j]);
		
		if(calisanTopBrut[j] < 2000){
			calisanVergi[j] = 0;
			calisanVergi[j] = calisanTopBrut[j]*0.15;
			printf("\t\t\t\t--> Gelir Vergisi Kesintisi: %.2f TL (Yuzde 15)\n", calisanVergi[j]);
		}
		if(calisanTopBrut[j] >= 2000 && calisanTopBrut[j] < 5000){
			calisanVergi[j] = 0;
			calisanVergi[j] = calisanTopBrut[j]*0.20;
			printf("\t\t\t\t--> Gelir Vergisi Kesintisi: %.2f TL (Yuzde 20)\n", calisanVergi[j]);
		}
		if(calisanTopBrut[j] >= 5000 && calisanTopBrut[j] < 10000){
			calisanVergi[j] = 0;
			calisanVergi[j] = calisanTopBrut[j]*0.27;
			printf("\t\t\t\t--> Gelir Vergisi Kesintisi: %.2f TL (Yuzde 27)\n", calisanVergi[j]);
		}
		if(calisanTopBrut[j] > 10000){
			calisanVergi[j] = 0;
			calisanVergi[j] = calisanTopBrut[j]*0.35;
			printf("\t\t\t\t--> Gelir Vergisi Kesintisi: %.2f TL (Yuzde 35)\n", calisanVergi[j]);
		}
		
		temp = 0;
		if(calisanEngelOran[j] >= 80){
			printf("\t\t\t\t--> Engelli Vergi Indirimi: 900 TL (1. Derece Engelli)\n");
			temp = 900;
		}
		if(calisanEngelOran[j] >= 60 && calisanEngelOran[j] < 80){
			printf("\t\t\t\t--> Engelli Vergi Indirimi: 470 TL (2. Derece Engelli)\n");
			temp = 470;
		}
		if(calisanEngelOran[j] >= 40 && calisanEngelOran[j] < 60){
			printf("\t\t\t\t--> Engelli Vergi Indirimi: 210 TL (3. Derece Engelli)\n");
			temp = 210;
		}
		if(calisanEngel[j] == 'h' || calisanEngel[j] == 'H'){
			calisanNet[j] = calisanTopBrut[j] - calisanVergi[j];
			printf("\t\t\t\t--> Aylik Net Ucret: %.2f TL\n", calisanNet[j]);
		}
		else{
			calisanVergi[j] -= temp;
			if(calisanVergi[j] > 0){
				calisanNet[j] = calisanTopBrut[j] - calisanVergi[j];
				printf("\t\t\t\t--> Aylik Net Ucret: %.2f TL\n", calisanNet[j]);
			}
			else{
				calisanVergi[j] = 0;
				calisanNet[j] = calisanTopBrut[j];
				printf("\t\t\t\t--> Aylik Net Ucret: %.2f TL\n", calisanNet[j]);
			}
		}
		para = calisanNet[j];
		para2 = calisanNet[j];
		if(calisanNet[j] >= 200){
			bank200 = calisanNet[j] / 200;
			printf("\t\t\t\t--> %d Tane 200 TL\n", bank200);
			temp2 = 200 * bank200;
			para = para - temp2;
		}
		
		if(para >= 100 && para < 200){
			bank100 = para / 100;
			printf("\t\t\t\t--> %d Tane 100 TL\n", bank100);
			temp2 = 100 * bank100;
			para = para - temp2;
		}
		if(para >= 50 && para < 100){
			bank50 = para / 50;
			printf("\t\t\t\t--> %d Tane 50 TL\n", bank50);
			temp2 = 50 * bank50;
			para = para - temp2;
		}
		if(para >= 20 && para < 50){
			bank20 = para / 20;
			printf("\t\t\t\t--> %d Tane 20 TL\n", bank20);
			temp2 = 20 * bank20;
			para = para - temp2;
		}
		if(para >= 10 && para < 20){
			bank10 = para / 10;
			printf("\t\t\t\t--> %d Tane 10 TL\n", bank10);
			temp2 = 10 * bank10;
			para = para - temp2;
		}
		if(para >= 5 && para < 10){
			bank5 = para / 5;
			printf("\t\t\t\t--> %d Tane 5 TL\n", bank5);
			temp2 = 5 * bank5;
			para = para - temp2;
		}
		if(para >= 1 && para < 5){
			bank1 = para / 1;
			printf("\t\t\t\t--> %d Tane 1 TL\n", bank1);
			temp2 = 1 * bank1;
			para = para - temp2;
		}
		para3 = calisanNet[j] - para2;
		if(para3 < 1 && para3 >= 0.50){
			printf("\t\t\t\t--> 1 Tane 50 Kurus\n");
			para3 = para3 - 0.50;
		}
		if(para3 < 0.50 && para3 >= 0.25){
			printf("\t\t\t\t--> 1 Tane 25 Kurus\n");
			para3 = para3 - 0.25;
		}
		if(para3 < 0.25 && para3 >= 0.10){
			para3 = para3 - 0.10;
			if(para3 < 0.25 && para3 >= 0.10){
				printf("\t\t\t\t--> 2 Tane 10 Kurus\n");
				para3 = para3 - 0.10;
			}
			else{
				printf("\t\t\t\t--> 1 Tane 10 Kurus\n");
			}
		}
		if(para3 < 0.10 && para3 > 0){
			printf("\t\t\t\t--> %.2f Kurus\n", para3);
		}
		
		
	}
    
    printf("\t\t\t\t****************-OZET-***************\n");
	printf("\t\t\t\t--> Tum Calisanlarin Aylik Net Tutari %.2f TL\n", ToplamNet(calisanNet, calisanSayisi));
	printf("\t\t\t\t--> Devlete Aktarilan Toplam Gelir Vergisi Tutari %.2f TL\n", ToplamVergi(calisanVergi, calisanSayisi));
	printf("\t\t\t\t--> Tum Calisanlarin Aylik Toplam Brut Ucretin Ortalamasi %.2f TL\n", OrtalamaBrut(calisanTopBrut, calisanSayisi));
	printf("\t\t\t\t--> Tum Calisanlarin Aylik Toplam Net Ucretin Ortalamasi %.2f TL\n", OrtalamaNet(calisanNet, calisanSayisi));
	printf("\t\t\t\t--> Net Ucreti 2000 TL nin Altinda Olan Calisan Sayisi: %d\n", AzMaas(calisanNet, calisanSayisi));
	printf("\t\t\t\t--> Tum Calisanlarin Icinde Evli Olanlarin Yuzdesi: %d\n", EvliBekar(calisanMedeni, calisanSayisi));
	
	for(i=0; i<1; i++){
		for(j=0; j<calisanSayisi-1; j++){
			if(calisanNet[j] > calisanNet[j+1]){
				temp3 = calisanNet[j];
				calisanNet[j] = calisanNet[j+1];
				calisanNet[j+1] = temp3;
				
				temp3 = calisanTC[j];
				calisanTC[j] = calisanTC[j+1];
				calisanTC[j+1] = temp3;
				
				strcpy(temp4[j], calisanIsimSoyisim[j]);
				strcpy(calisanIsimSoyisim[j], calisanIsimSoyisim[j+1]);
				strcpy(calisanIsimSoyisim[j+1], temp4[j]);
				
				temp3 = calisanBrut[j];
				calisanBrut[j] = calisanBrut[j+1];
				calisanBrut[j+1] = temp3;
				
				temp3 = calisanVergi[j];
				calisanVergi[j] = calisanVergi[j+1];
				calisanVergi[j+1] = temp3;
			}
		}
	}
	printf("\n\t\t\t\t**************************************\n");
	printf("\t\t\t\t--> Aylik Net Tutari En Fazla Olan Calisan:\n");
	printf("\t\t\t\t--> TC: %lld\n", calisanTC[calisanSayisi-1]);
	printf("\t\t\t\t--> Ad Soyad: %s\n", calisanIsimSoyisim[calisanSayisi-1]);
	printf("\t\t\t\t--> Calisan Net Ucreti: %.2f\n", calisanNet[calisanSayisi-1]);
	printf("\t\t\t\t--> Calisan Brut Ucreti: %.2f\n", calisanBrut[calisanSayisi-1]);
	printf("\t\t\t\t--> Calisan Vergisi: %.2f\n", calisanVergi[calisanSayisi-1]);
	
	for(i=0; i<1; i++){
		for(j=0; j<calisanSayisi-1; j++){
			if(calisanBrut[j] > calisanBrut[j+1]){
				temp3 = calisanNet[j];
				calisanNet[j] = calisanNet[j+1];
				calisanNet[j+1] = temp3;
				
				temp3 = calisanTC[j];
				calisanTC[j] = calisanTC[j+1];
				calisanTC[j+1] = temp3;
				
				strcpy(temp4[j], calisanIsimSoyisim[j]);
				strcpy(calisanIsimSoyisim[j], calisanIsimSoyisim[j+1]);
				strcpy(calisanIsimSoyisim[j+1], temp4[j]);
				
				temp3 = calisanBrut[j];
				calisanBrut[j] = calisanBrut[j+1];
				calisanBrut[j+1] = temp3;
				
				temp3 = calisanVergi[j];
				calisanVergi[j] = calisanVergi[j+1];
				calisanVergi[j+1] = temp3;
			}
		}
	}
	printf("\n\t\t\t\t**************************************\n");
	printf("\t\t\t\t--> Aylik Brut Ucreti En Fazla Olan Calisan:\n");
	printf("\t\t\t\t--> TC: %lld\n", calisanTC[calisanSayisi-1]);
	printf("\t\t\t\t--> Ad Soyad: %s\n", calisanIsimSoyisim[calisanSayisi-1]);
	printf("\t\t\t\t--> Calisan Net Ucreti: %.2f\n", calisanNet[calisanSayisi-1]);
	printf("\t\t\t\t--> Calisan Brut Ucreti: %.2f\n", calisanBrut[calisanSayisi-1]);
	printf("\t\t\t\t--> Calisan Vergisi: %.2f\n", calisanVergi[calisanSayisi-1]);
	
	
	
	getch();
	return 0;
}
float ToplamNet (float maas [], int kisi){
	int i;
	float sonuc = 0;
	
	for(i=0; i<kisi; i++){
		sonuc = sonuc + maas[i];
	}
	return sonuc;
}

float ToplamVergi (float vergi [], int kisi){
	int i;
	float sonuc = 0;
	
	for(i=0; i<kisi; i++){
		sonuc = sonuc + vergi[i];
	}
	return sonuc;
}

float OrtalamaBrut (float brut[], int kisi){
	int i;
	float sonuc = 0;
	
	for(i=0; i<kisi; i++){
		sonuc = sonuc + brut[i];
	}
	return sonuc/kisi;

}

float OrtalamaNet (float net[], int kisi){
	int i;
	float sonuc = 0;
	
	for(i=0; i<kisi; i++){
		sonuc = sonuc + net[i];
	}
	return sonuc / kisi;
}

int AzMaas (float net[], int kisi){
	int i, sayac = 0;
	
	for(i=0; i<kisi; i++){
		if(net[i] < 2000){
			sayac++;
		}
	}
	return sayac;
}

int EvliBekar (char medeni[], int kisi){
	int i, evli = 0, bekar = 0, sonuc = 0;
	
	for(i=0; i<kisi; i++){
		if(medeni[i] == 'E' || medeni[i] == 'e'){
			evli++;
		}
		else{
			bekar++;
		}	
	}
	sonuc = (evli * 100) / kisi;
	return sonuc;
}

















