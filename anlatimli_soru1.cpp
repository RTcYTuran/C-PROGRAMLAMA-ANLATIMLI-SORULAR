#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int main(){
	
	int ogr_numara , ogr_vize , ogr_final , ogr_ortalama; //gerekli olan deðiþkenleri tanýmladýk.
	char ogr_ad[50] , ogr_soyad[50];
	
	
	printf("OGRENI NUMARARANIZI GIRINIZ = "); //ekrana bilgi yazdýk
	scanf("%d",&ogr_numara); //oðrencinin numarasýný aldýk ---- 2.adým
	
	printf("ADINIZI BOSLUKSUZ SEKILDE GIRINIZ ="); //ekrana bilgi yazdýk
	scanf("%s",ogr_ad); //öðrencinin adýný aldýk ---- 3.adým
	
	printf("SOYADINIZI BOSLUKSUZ SEKILDE GIRINIZ ="); //ekrana bilgi yazdýk
	scanf("%s",ogr_soyad); //öðrencinin soyadýný aldýk. ---- 3.adým
			
	printf("VIZE NOTUNU GIRINIZ = "); //ekrana bilgi yazdýk
	scanf("%d",&ogr_vize); //öðrencinin vize notunu aldýk ---- 4.adým
	
	printf("FINAL NOTUNU GIRINIZ = "); //ekrana bilgi yazdýk
	scanf("%d",&ogr_final); //öðrencinin final notunu aldýk. ---- 5.adým
	
	ogr_ortalama = ((ogr_vize*30)/100) + ((ogr_final*70)/100); // öðrencinin ortalamasýný hesaplayýp deðiþkene atadýk ---- 6.adým
	
	printf("OGRENCI NO = %d , OGRENCI ORTALAMA = %d ",ogr_numara,ogr_ortalama);// öðrencinin numarasýný ve ortalamasýný ekrana yazdýrdýk. ---- 7.adým
	
	
	
	
	getch();
	return 0;
}



// THIS CODES BELONG RTcY SOFTWARE
