#include<stdio.h>
#include<conio.h>



int gecici = 1; // global deðiþkenleri tanýmladýk.


/*---- RECURSIVE EKOK BULAN FONKSÝYON ----*/
int EKOK(int sayi1 , int sayi2){
	
	if(gecici % sayi1 == 0 && gecici % sayi2 == 0) // ---- 4.adým
	return gecici;
	
	else{ // ---- 5.adým
		gecici++;
		return EKOK(sayi1,sayi2);
	}
	
}



/*---- ANA FONKSÝYON ----*/
int main(){
	
	int sayi1 , sayi2 , sonuc; // deðiþkenleri tanýmladýk.
	
	printf(" ---- Birinci Sayiyi Giriniz = "); // ekrana bilgi yazdýrdýk.
	scanf("%d",&sayi1); // birinci sayýyý aldýk. ---- 2.adým
	
	printf(" ---- Ikinci Sayiyi Giriniz = "); // ekrana bilgi yazdýrdýk.
	scanf("%d",&sayi2); // birinci sayýyý aldýk. ---- 2.adým
	
	sonuc = EKOK(sayi1,sayi2); // recursive fonksiyonu çaðýrdýk. ---- 3. adým
	
	printf(" ---- EKOK(%d,%d) = %d",sayi1,sayi2,sonuc); // ekrana bilgi yazdýrdýk. ---- 6.adým
	
	
	getch();
	return 0;
}



// THIS CODES BLONG TO RTcY SoftWare
