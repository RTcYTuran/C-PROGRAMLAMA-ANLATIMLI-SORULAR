#include<stdio.h>
#include<conio.h>
#include<string.h>



int main(){
	
	char cumle[100]; // tutacaðýmýz cümle deðiþkenini tanýmladýk
	int cumle_boyutu = 0; // girilen cimlenin boyutu için deðiþken tanýmladýk.
	int j=0;
	printf("TERS CEVIRILECEK CUMLEYI GIRINIZ !!! \n"); //ekrana bilgi yazdýk
	gets(cumle); // kullanýcýdan cümle girdisini aldýk ---- 2.adým
	
	printf("KULLANICININ GIRDIGI CUMLE !!!  \n"); //ekrana bilgi yazdýk
	printf("---- %s \n",cumle); // kullanýcýnýn girdiði cümleyi ekrana yazdýrdýk
	
	/*---- CÜMLE BOYUTUNU BULMA ----*/
	for(int i=1;cumle[i]!=NULL;i++){  
		cumle_boyutu++; // ---- 3.adým
	}
	
	/*---- CÜMLEYÝ TERSTEN CUMLE TERS DÝZÝSÝNE ATAMA ----*/
	char cumle_ters[cumle_boyutu];
	for(int i=cumle_boyutu;i>=0;i--){ // ---- 4.adým
		cumle_ters[j] = cumle[i];
		j++;
	}
	
	printf("CUMLENIN TERSTEN YAZIMI !!! \n\n"); //ekrana bilgi yazdýk
	
	for(int i=0;i<cumle_boyutu+1;i++){
		printf("%c",cumle_ters[i]); // ---- 5.adým
	}
	
	getch();
	return 0;
}


// THIS CODES BELONG RTcY SOFTWARE
