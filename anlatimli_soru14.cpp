#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>



int edmund[100]; // içresinde random sayý bulunduran 100 elemanlý diziyi tanýmladýk.
int tek_indis[50] , cift_indis[50]; //tek ve çift indise göre sayýlarý ayýrýp atayacaðýmýz diziler. 



/*---- 0-1000 ARASINDA 100 ADET RANDOM SAYI ÜRETÝP DÝZÝYE ATAYAN FONKSÝYON ----*/
void Random_Value(){
	
	int random_value = 0;
	srand(time(NULL)); 
	
	for(int i=0;i<100;i++){ // 100 adet random sayý oluþturmamýzý saðlayan döngü
		random_value = rand()%1000; // random deðer oluþturduk
		edmund[i] = random_value; // deðeri diziye atadýk.
	}
}




/*---- DÝZÝ ELEMANLARINI SIRALIYACAK OLAN SELECTÝON SORT FONKSÝYONU ----*/
void Selection_Sort(){

	int gecici;
	for(int i=0;i<50-1;i++){ // ilk döngümüz 
		for(int j=i+1;j<50;j++){ // ikinci döngümüz
			if(tek_indis[j]<tek_indis[i]){ // eðer ilk eleman ikinci elemandan büyükse.
				gecici = tek_indis[i]; // yer deðiþtirme iþlemleri yaptýk
				tek_indis[i] = tek_indis[j];
				tek_indis[j] = gecici;
			}
		}
	}
}



/*---- DÝZÝ ELEMANLARINI SIRALIYACAK OLAN INSERTION SORT FONKSÝYONU ----*/
void Insertion_Sort(){

int gecici , j;
	
	for(int i=0;i<50;i++){ // ilk döngümüz 
		gecici = cift_indis[i];
		j = i-1;
		while(j>-1 && cift_indis[j] < gecici ){ // eðer j indisli eleman geçiciden küçükse 
			cift_indis[j+1] = cift_indis[j]; // yer deðiþtirme iþlemleri yaptýk.
			j--;
			cift_indis[j+1] = gecici;
		}
	}

}



/*---- INDIS KONTROLÜ YAPAN ve INDISLERE GÖRE 2 AYRI DÝZÝYE ATAYAN FONKSÝYON ----*/
void Indis_Kontrol(){
	int c_indis = 0 , t_indis = 0;
	
	for(int i=0;i<100;i++){
		
		if(i%2 ==0){ // eðer random sayýnýn indisi çift ise
			cift_indis[c_indis] = edmund[i]; // çift indis dizisine atadýk.
			c_indis++;
		}
		
		if(i%2 != 0){ // eðer random sayýnýn indisi tek ise 
			tek_indis[t_indis] = edmund[i]; // tek indis dizisine atadýk.
			t_indis++;
		}
	}	
}



/*---- ANA FONKSÝYONUMUZ ----*/
int main(){
	
	Random_Value(); // rastgele sayý üreten fonksiyonumuzu çaðýrdýk.
	printf("\t\t ****** RASTGELE SAYILAR OLUSTURULDU ****** \n");
	
	printf("\n");
	printf("\n");
	
	printf("****** RASTGELE SAYILARIN OLDUGU DIZI ****** \n");
	for(int i=0;i<100;i++){ // rastgele sayýlardan oluþan diziyi ekrana yazdýrdýk.
		printf("\t %d \n",edmund[i]);
	}
	
	printf("\n");
	printf("\n");	
	
	Indis_Kontrol(); // indis kontrolü yapan fonksiyonumuzu çaðýrdýk.
	printf("\t\t ****** INDIS KONTROLU YAPILDI VE INDISLERE GORE SAYILAR AYRILDI ****** \n");
	
	printf("\n");
	printf("\n");
	
	printf("****** AYRILAN TEK INDISLI DIZI ****** \n");
	for(int i=0;i<50;i++){ // tek indisli sayýlarýn olduðu diziyi ekrana yazdýrdýk.
		printf("\t %d \n",tek_indis[i]);
	}
	
	Selection_Sort();// tek indisli sayýlarýn bulunduðu dizyi sýralamasý için sýralama algoritmamýzý çaðýrdýk.
	printf("\t\t ****** TEK INDISLI DIZININ SIRALANMASI YAPILDI ****** \n");
		
	printf("\n");
	printf("\n");
	
	printf("****** SIRALANMIS TEK INDISLI DIZI ****** \n");
	for(int i=0;i<50;i++){ // sýralanmýs tek indisli sayýlarýn bulunduðu diziyi ekrana yazdýrdýk.
		printf("\t %d \n",tek_indis[i]);
	}
	
	printf("\n");
	printf("\n");
	
	printf("****** AYRILAN CIFT INDISLI DIZI ****** \n");
	for(int i=0;i<50;i++){ // çift indisli sayýlarýn olduðu diziyi ekrana yazdýrdýk.
		printf("\t %d \n",cift_indis[i]);
	}
	
	Insertion_Sort(); // çift indisli sayýlarýn olduðu diziyi sýralamasý için sýralama algoritmamýzý çaðýrdýk.
	printf("\t\t ****** CIFT INDISLI DIZININ SIRALANMASI YAPILDI ****** \n");
	
	printf("\n");
	printf("\n");

	printf("****** SIRALANMIS CIFT INDISLI DIZI ****** \n");
	for(int i=0;i<50;i++){ // sýralanmýs çift indisli sayýlarýn bulunduðu diziyi ekrana yazdýrdýk.
		printf("\t %d \n",cift_indis[i]);
	}
	
	printf("\n");
	printf("\n");	
	
	printf("****** PROGRAMIN CALISMASI BITMISTIR! ****** \n");
	printf("****** CIKIS ICIN LUTFEN 'ENTER' TUSUNA BASINIZ! ****** \n");
	
	
	getch();
	return 0;
}



// BU KODLAR RIZA TURANCAN YILMAZ'A AÝTTÝR.
// KOPYALANMASI VEYA ÇOÐALTILMASI YASAKTIR.
