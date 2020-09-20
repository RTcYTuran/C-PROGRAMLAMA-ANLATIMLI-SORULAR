#include<stdio.h>
#include<conio.h>



/*---- RECURSIVE EBOB (OBEB) BULAN FONKSÝYON ----*/
int OBEB(int sayi1 , int sayi2){

	if(sayi2==0 ){ // eðer ikinci sayý sýfýrsa ---- 4.adým
		return sayi1; // sayý biri döndür  ---- 4.adým
	}

	else{ // deðilse ---- 5.adým
		return OBEB(sayi2,sayi1%sayi2); // fonksiyonu çaðýr ve sayi2 ile sayi1 mod sayi2 deðerlerini (sayi2,sayi1%sayi2) yolla. ---- 5.adým
	}
}



/*---- ANA FONKSÝYON ----*/
int main (){
	
	int sayi1 , sayi2 , sonuc; // deðiþkenleri tanýmladýk.
	
    printf(" ---- Birinci Sayiyi Giriniz: "); // ekrana bilgi yazdýrdýk.
    scanf("%d", &sayi1); // birinci sayýyý aldýk. ---- 2.adým
   
    printf(" ---- Ikinci Sayiyi Giriniz: "); // ekrana bilgi yazdýrdýk.
    scanf("%d", &sayi2); // ikinci sayýyý aldýk. ---- 2.adým
 
    sonuc = OBEB(sayi1,sayi2); // recursive fonksiyonu çaðýrdýk. ---- 3. ve 6. adýmlar
   
    printf(" ---- OBEB(%d,%d) = %d", sayi1, sayi2, sonuc); // ekrana bilgi yazdýrdýk. ---- 7.adým
    
	
	
	
	
	getch();
	return 0;
}



// THIS CODES BLONG TO RTcY SoftWare
