#include<stdio.h>
#include<conio.h>
#include<stdlib.h>



FILE *arsene_lupen;// tanýmladýðýmýz dosya pointer'ý



/*---- BULUNAN ASAL SAYILARI DOSYAYA YAZAN FONKSÝYON ----*/
void File_Write(int write){// kendisine gelen asal sayýlarý dosyaya yazan fonksiyon	
	
	arsene_lupen = fopen("primes.txt","a+");// dosyayý açtýk
	if(arsene_lupen == NULL)// dosyanýn açýlýp açýlmadýðýný kontrol ettik.
	printf("HATA !!! DOSYA BULUNAMADI !!!");// hata mesajý gösterdik
	
	fprintf(arsene_lupen,"%d\n",write);// gelen asal sayýyý dosyaya yazdýk
	fclose(arsene_lupen); // dosyayý kapattýk
}



/*---- ASAL SAYIYI RECURSIVE BULAN FONKSÝYON ----*/
int Is_Prime(int entered_number , int previous_numbers){// previous_numbers = önceki sayýlarý kapsar, number = gelen sayý
	
	if(entered_number < 2)// sayi 2 den küçükse 0 döndürdük
	return 0;
	
	if(previous_numbers == entered_number){// eðer gelen sayi ile arttýrarak gönderdiðimiz sayý birbirine eþitse 1 döndürdük
		return 1;
	}
	
	if(entered_number % previous_numbers == 0)// eðer sayi kendisinden önceki sayilara tam bölünüyorsa 0 döndürdük
		return 0;
	
	return Is_Prime(entered_number,previous_numbers+1);// fonksiyonu tekrar çaðýrarak önceki_sayilar deðiþkenini bir atttýrdýk.
	
}
/* Yukarýda yazmýþ olduðum recursive fonksiyonun mantýðý gayet basittir.
	# Eðer sayý 2 den kuçükse 0 döndür.
	# Eðer onceki_sayilar ana sayýya eþitse 1 döndür. Bu þart sayýnýn asal olup olmadýðýný belirler.
	Yani onceki sayýnýn ana sayýya eþit olabilmesi için ana sayýnýn onceki sayýlara tam bölünmemesi gerekir.
	# Eðer ana sayý onceki sayýya tam bölünüyorsa 0 döndür. Çünki asal sayý deðildir.
	
  */



/*GIRILEN ARALIKTAKI ASAL SAYILARI BULAN FONKSIYON*/
void Find_Prime_Between_Numbers(int btw_value , int btw_value2){
	
	
	if(btw_value > btw_value2){// eðer girilen ilk sayý büyükse yani girdi 45-5 þeklinde ise
	printf("-----------BULUNAN ASAL SAYILAR----------\n");
		for(int i = btw_value2;i <= btw_value;i++){// kuçuk sayidan büyük sayýya giden döngü oluþturduk 
			
			int is_prime = Is_Prime(i,2);// sayiyi recursive asal sayý bulan fonksiyonumuza yolladýk.
				
			/*if(is_prime == 0)// eðer sonuc 0 ise
			printf("asal degil = %d\n",i);// asal deðil*/
				
			if(is_prime == 1){// eðer sonuc 1 ise ---- 4.adým
			printf("--- %d\n",i);// sayý asal ---- 6.adým
			File_Write(i);// dosyaya yazdýk ---- 5.adým
			}	
		}
		printf("ASAL SAYILAR DOSYAYA YAZILDI !!!\n");
	}
	
	
	if(btw_value2 > btw_value){// girilen ikinci sayi büyükse yani girdi 5-45 þeklinde ise
	printf("-----------BULUNAN ASAL SAYILAR----------\n");
		for(int i = btw_value;i <= btw_value2;i++){// kuçuk sayidan büyük sayýya giden döngü oluþturduk 
			
			int is_prime = Is_Prime(i,2);// sayiyi recursive asal sayý bulan fonksiyonumuza yolladýk.
				
			/*if(is_prime == 0)// eðer sonuc 0 ise
			printf("asal degil = %d\n",i);// asal deðil*/
				
			if(is_prime == 1){// eðer sonuc 1 ise ---- 4.adým
			printf("--- %d\n",i);// sayý asal ---- 6.adým
			File_Write(i);// dosyaya yazdýk ---- 5.adým
			}	
		}
		printf("ASAL SAYILAR DOSYAYA YAZILDI !!!\n");
	}
}



/*---- ANA FONKSÝYONUMUZ ----*/
int main(){
	
	int value , value2;
	
	printf("----GIRILECEK ARALIK SAYILARI BUYUK KUCUK FARKETMEK SIZIN GIRINIZ----\n");
	printf("----ORN 5-45 YA DA 45-5 SEKLINDE TEK TEK GIRINIZ ----\n");
	
	printf("ASAL SAYILARIN ARANACAGI ARALIKTAKI 1. SAYIYI GIRINIZ = ");
	scanf("%d",&value); // ---- 2.adým
	
	printf("ASAL SAYILARIN ARANACAGI ARALIKTAKI 2. SAYIYI GIRINIZ = ");
	scanf("%d",&value2); // ---- 2.adým
	
	Find_Prime_Between_Numbers(value , value2);// aralýktaki asal sayýlarý bulan fonksiyonu çaðýrdýk. ---- 3.adým
	
	
	getch();
	return 0;
}



// BU KODLAR RIZA TURANCAN YILMAZ'A AÝTTÝR.
// KOPYALANMASI VEYA ÇOÐALTILMASI YASAKTIR.
