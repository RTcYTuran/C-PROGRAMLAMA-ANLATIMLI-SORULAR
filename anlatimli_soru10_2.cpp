#include<stdio.h>
#include<conio.h>
#include<stdlib.h> // dosyaya yazma için gerekli kütüphane
#include<time.h> // random sayý için gerekli olan kütüpahen



FILE *dosya , *dosya1; // dosyalama için gerekli olan pointerlarýmýzý (iþaretçiler) tanýmladýk.



/*--- ASAL SAYI BULAN FONKSÝYONUMUZ ---*/
void Find_Prime(int value); // fonksiyonlarýn farklý çeþitle tanýmlamasýdýr. bu þekilde üstte tanýmlayýp daha sonra farklý yerde detaylý yazabiliriz.



/*--- DOSYADAN VERÝ OKUYAN FONKSÝYONUMUZ ---*/
void File_Read(){
	
	int read; // okunan sayýyý tutmasý için deðiþken tanýmladýk.
	dosya = fopen("sayilar.txt","r+"); // dosyayý okuma modunda açtýk.
	if(dosya==NULL) // dosya pointerý nullsa yani dosya yoksa.
	printf("DOSYA MEVCUT DEGÝL"); // ekrana bilgi yazdýk.
	while(!feof(dosya)){ // dosyanýn sonuna kadar giden döngü tanýmladýk. ---- 3. adým.
	fscanf(dosya,"%d",&read); // dosyadan sýralý olarak sayýlarý okuduk. ---- 4. adým.
	Find_Prime(read); // asal sayýyý bulmasý için fonksiyonumuzu çaðýrdýk. ---- 4. adým.
	}
	
}	



/*--- DOSYAYA VERÝ YAZAN FONKSÝYONUMUZ ---*/
void File_Write(int write){
	
	dosya1 = fopen("sayilar2.txt","a+"); // dosyayý yazma modunda açtýk.
	if(dosya==NULL) // dosya pointerý nullsa yani dosya yoksa.
	printf("DOSYA MEVCUT DEGÝL"); // ekrana bilgi yazdýk.
	fprintf(dosya1,"%d\n",write); // dosyaya sayýlarý yazdýk. ---- 6. adým.
	printf(" --- %d \n",write);
	fclose(dosya1);	// dosyayý kapattýk.

}



/*--- ASAL SAYI BULAN FONKSÝYONUMUZ ---*/
void Find_Prime(int value){
	
	int flag=0; // asal sayý kontrolü yapan deðiþkenimizi tanýmladýk.
	for(int i=2;i<value;i++){ // 2 den baþlayýp gelen sayýya kadar dönen döngü oluþturduk. 
		if(value%i==0){ // eðer sayý mod i sýfýrsa.
			flag++; // kontrol deðiþkenimizi arttýrdýk.
			break; // döngüyü kýrdýk.
		}
		if(flag==0){ // eðer kontrol deðiþkeni sýfýrsa.
			File_Write(value); // dosyaya yazan yonksiyonumuzu çaðýrdýk. ---- 5. adým.
			break; // döngüyü kýrdýk.
		}
	}
}



/*--- ANA FONKSÝYONUMUZ ---*/
int main(){

	printf("ASAL SAYILAR ARANIYOR!!!\n"); // ekrana bilgi yazdýk.
	
	File_Read(); // dosyadan okuma yapan fonksiyonumuzu çaðýrdýk. ---- 2. adým.
	
	printf("ASAL SAYILAR SAYILAR2 DOSYASINA YAZILDI. CIKIS ICIN ENTER A BASIN!!!"); // ekrana bilgi yazdýk.
	

	getch();
	return 0;
}



// BU KODLAR RIZA TURANCAN YILMAZ'A AÝTTÝR.
// KOPYALANMASI VEYA ÇOÐALTILMASI YASAKTIR.
