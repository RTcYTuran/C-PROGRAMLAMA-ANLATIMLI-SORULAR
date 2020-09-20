#include<stdio.h>
#include<conio.h>


int main(){
	
	int a , b , buyuk_sayi , kucuk_sayi , adet;
	
	printf("ASAL SAYILARIN ARANACAGI SINIRLARI GIRINIZ !!! \n"); //ekrana bilgi yazdýk
	printf("SINIR GIRME ORNEGI = 5-25 VEYA 25-5 \n"); //ekrana bilgi yazdýk
	
	printf("A SAYISINI GIRINIZ = "); //ekrana bilgi yazdýk
	scanf("%d",&a); //A SAYISINI ALDIK ---- 2.adým
	
	printf("B SAYISINI GIRINIZ = "); //ekrana bilgi yazdýk
	scanf("%d",&b); // b sayýsýný aldýk ---- 3.adým

/*---- BÜYÜK KÜÇÜK SAYI KONTROLÜ ----*/ 
	if(a > b){ // a sayýsý büyükse ---- 4.adým
		buyuk_sayi = a;	
		kucuk_sayi = b;
	}
	else{
		if(a<b){ // b sayýsý büyükse ---- 4.adým
		buyuk_sayi = b;
		kucuk_sayi = a;
	}
	}
/*---- ASAL SAYILARI BULMA ----*/
	for(int i=kucuk_sayi;i<buyuk_sayi;i++){// sýnýrlar arasýnda döngü oluþturduk. ---- 5.adým
		int sayac = 0;// sayinin bölünüp bölünmediðini kontrol eden deðiþken.
		for(int j=2;j<i;j++){// seçili sayýnýn kendisine kadar olan sayýlarý barýndýran döngü
			if(i%j==0){// sayinin kendisinde baþka bir sayiya bölünp bölünmediðini kontrol eden þart ---- 6.adým
			sayac++;
			}
		}
		if(sayac == 0){
		printf("---- %d \n",i);// asal sayýlarý ekrana yazdýrdýk. ---- 7.adým
			adet++;//  kaç adet asal sayý olduðunu tutan deðiþken
		}
	}
	
	
	printf("GIRILEN SINIRLAR ARASINDA %d ADET ASAL SAYI BULUNMAKTADIR.",adet);// asal sayý adaetini ekrana yazdýrdýk.
	
	
	getch();
	return 0;
}


// THIS CODES BELONG RTcY SOFTWARE
