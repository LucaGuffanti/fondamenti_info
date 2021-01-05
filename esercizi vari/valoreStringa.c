int valoreCorrispondente(char*);

int valoreCorrispondente(char* str){
 int i;
 int num;

 for(i = 0, num = 0; str[i] != '\0'; i++){
   num = num*10 + (str[i] - '0');
 }
 return num;
}