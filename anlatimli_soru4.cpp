#include<stdio.h>
#include<conio.h>
#include<string.h>


int main(){
	
	char metin[100] , degisen_metin[100];
	int metin_boyutu = 0;
	
	printf("DEGISTIRILECEK OLAN METNI GIRINIZ !!! \n");  //ekrana bilgi yazdýk
	gets(metin); // kullanýcýdan metin aldýK  ---- 2.adým
	
	printf("KULLANICININ GIRDIGI METIN = %s \n\n",metin);  //ekrana bilgi yazdýk
	
/*---- GIRILEN METNIN BOYUTUNU BULMA ----*/
	for(int i=0;metin[i]!=NULL;i++){ // ---- 3.adým
		metin_boyutu++;
	}
	
	/*---- GIRILEN METINDEKI HARFLERI DEGISTIRME ----*/
	for(int i=0;i<=metin_boyutu;i++){ // ---- 4.adým
		
		if(metin[i]>=65 && metin[i]<=90){ // harf degiþikliði þartý ---- 5.adým
			degisen_metin[i] = metin[i]+32; // harf deðiþtirerek yeni diziye atadýk ---- 5.adým
		}
		else{
			degisen_metin[i] = metin[i]-32; // harf deðiþtirerek yeni diziye atadýk
		}
	}
	
	
	printf("DUZENLENMIS METIN !!! \n"); //ekrana bilgi yazdýk
	for(int i=0;i<metin_boyutu;i++){
		printf("%c",degisen_metin[i]); // degýsmýs dýzýyý yazdýrdýk
	}
	
	
	
	getch();
	return 0;
}
