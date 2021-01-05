void calcolaDate(char*, date_t*, date_t*);

void calcolaDate(char* fn, date_t* inf, date_t* sup){
 FILE* fp;
 int year, month, day;

 fp = fopen(fn, "r");
 if(fp){
   fscanf("%d %d %d", &year, &month, &day);
   inf->year = sup->year = year;
   inf->month = sup->month = month;
   inf->day = sup->day = day;

   while(!feof(fp)){
     if((year < inf->year) || (year < inf->year && month < inf->month) || (year < inf->year && month < inf->month && day < inf->day){
       inf->year = year;
       inf->month = month;
       inf->day = day;
     }
     else if((year > sup->year) || (year > sup->year && month > sup->month) || (year > sup->year && month > sup->month && day > sup->day){
       sup->year = year;
       sup->month = month;     
       sup->day = day;
      } 
     fscanf("%d %d %d", &year, &month, &day);
   }
   fclose(fp);  
 }else{
  printf("Errore nell'apertura del file\n"9;
 }
}

int main(int argc, char* arvg[]){
 
 date_t* d1;
 date_t* d2;
 
 if(argc == 2){
  calcolaDate(argv[1], d1, d2);
  printf("Periodo dal %d-%d-%d al %d-%d-%d\n",d1->day, d1->month, d1->year, d2->day, d2->month, d2->year); 
 }else{
  prtinf("Errore negli argomenti\n"); 
 }

 return 0;
}