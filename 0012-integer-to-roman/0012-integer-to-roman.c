char* intToRoman(int num){
    int values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char* symbols[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    char* result=malloc(20);
    int i=0,pos=0;
    while(num>0){
        while(num>=values[i]){
            strcpy(result+pos,symbols[i]);
            pos+=strlen(symbols[i]);
            num-=values[i];
        }
        i++;
    }
    result[pos]='\0';
    return result;
}