#include<stdio.h>
#include<conio.h>



/*---- RECURSIVE "ÖZYÝNELEMELÝ" ÜST ALAN FONKSÝYONUMUZ ----*/
int Ozyinelemeli_Ust_Alma(int sayi,int ust){

	if(ust>0) // eðer girilen üst 0 dan büyükse ---- 4.adým
	return (sayi*(Ozyinelemeli_Ust_Alma(sayi,ust-1))); // girilen sayý ile tekrar fonksiyonumuzun çaðýrýlmasýnýn çarpýmý.
	
	else // eðer üst 0 dan küçük veya sýfýr ise  ---- 5.adým
	return 1; // 1 döndürdük.
}



int main(){
	
	int sayi , ust , sonuc; // deððiþkenleri tanýmladýk.
	
	printf("SAYI GIRINIZ = "); //ekrana bilgi yazdýk
	scanf("%d",&sayi); // kullanýcýdan sayýyý aldýk ---- 2.adým
	
	printf("UST GIRINIZ = "); //ekrana bilgi yazdýk
	scanf("%d",&ust); // kullanýcýdan ust aldýk ---- 2.adým
	
	sonuc = Ozyinelemeli_Ust_Alma(sayi,ust); // özyinelemeli "recursive" fonksiyonumuzu çaðýrdýk. ---- 3 ve 6. adýmlar
	printf("SONUC = %d",sonuc); // ekrana ust almanýn sonucunu yazdýrdýk. ---- 7.adým
	
	
	getch();
	return 0;
} 



