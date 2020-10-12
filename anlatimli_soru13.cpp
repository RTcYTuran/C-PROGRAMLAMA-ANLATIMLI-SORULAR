#include<stdio.h>
#include<conio.h>


FILE *arsene_lupen; // tanýmladýðýmýz dosya pointerlar'ý

int dosyadaki_sayilar[100]; // dosyadan okunan verileri sýralamak için atadýðýmýz dizi


/*--- DÝZÝYE OKUNAN SAYILARI EKLEYEN FONKSÝYON ---*/
void Diziye_Ekle(int eklenecek);


/*---- DOSYADAN SIRLI ÞEKÝLDE OKUMA YAPAN FONKSÝYON ----*/
void File_Read(){
	
	int read;
	arsene_lupen = fopen("sayilar.txt","r+"); // sayýlar dosyasýný okuma modunda açtýk.
	int dizi_index = 0;
	
	if(arsene_lupen == NULL) // eðer dosya  açýlmadýysa veya dosya yoksa.
	printf("DOSYA MEVCUT DEGÝL");
	
	while(!feof(arsene_lupen)){ // dosyanýn sonuna kadar giden döngü oluþturduk
	fscanf(arsene_lupen,"%d",&read); // dosyadan sýralý þekilde sayýlarý okuduk
	printf("\t %d \n",read); // dosyadan okunan sayýlarý ekrana bastýk.
	Diziye_Ekle(read); // dosyadan okunan sayýlarý diziye eklemek için yolladýk. ---- 3.adým
	}
	fclose(arsene_lupen); // dosyayý kapattýk.
}	




/*--- HIZLI SIRALAMA YAPAN (QUICK SORT) FONKSÝYONUMUZ  ---*/
void Hizli_Siralama(int dizi[100] , int sol , int sag){
	
	int i=sol,j=sag,gecici,pivot=dizi[(sol+sag)/2]; // gerekli olan deðiþkenler
	
	while(i<=j){
		while(dizi[i]>pivot)
		i++;
		while(dizi[j]<pivot)
		j--;
		if(i<=j){
			gecici = dizi[i];
			dizi[i] = dizi[j];
			dizi[j] = gecici;
			i++;
			j--;
		}
	}
	
	if(sol<j)
	Hizli_Siralama(dizi,sol,j);
	if(i<sag)
	Hizli_Siralama(dizi,i,sag);
}




/*--- DÝZÝYE OKUNAN SAYILARI EKLEYEN FONKSÝYON ---*/
void Diziye_Ekle(int eklenecek){
	
	for(int i=0;i<100;i++){ // 100 defa dönen döngü
		if(dosyadaki_sayilar[i] == NULL){ // eðer dizinin i. elemaný boþ ise
			dosyadaki_sayilar[i] = eklenecek; // dizinin boþ olan elemanýna sayýyý atadýk.
			break; // döngüden çýktýk.
		}
		
	}
}




/*--- ANA FONKSÝYONUMUZ ---*/
int main(){
	
	printf("\t DOSYADA BULUNAN SAYILAR OKUNUYOR !!! \n\n "); // ekrana bilgi yazdýrdýk.
	File_Read(); // doyadan okuma yapan fonksiyonumuzu çaðýrdýk. ---- 2.adým
	
	printf("\t SAYILAR DIZIYE AKTARILDI !!! \n\n"); // ekrana bilgi yazdýrdýk.
	
	
	printf("\t SAYILAR BUYUKTEN KUCUGE SIRALANIYOR !!! \n\n "); // ekrana bilgi yazdýrdýk.
	Hizli_Siralama(dosyadaki_sayilar,0,100-1); // hýzlý sýralama (quick sort) yapan fonksiyonumuzu çaðýrdýk. ---- 4.adým
	
	
	printf("\t SAYILARIN SIRALANMIS HALI !!! \n\n"); // ekrana bilgi yazdýrdýk.
	
	for(int i=0;i<100;i++){ // sýralanmýþ diziyi ekrana yazdýrdý. ---- 5.adým
		printf("\t %d \n",dosyadaki_sayilar[i]);
	}
	
	
	getch();
	return 0;
}




// BU KODLAR RIZA TURANCAN YILMAZ'A AÝTTÝR.
// KOPYALANMASI VEYA ÇOÐALTILMASI YASAKTIR.
