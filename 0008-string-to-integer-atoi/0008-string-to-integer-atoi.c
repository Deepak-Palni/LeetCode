int myAtoi(char* s){
    int i=0,sign=1;
    long long num=0;
    while(s[i]==' ') i++;
    if(s[i]=='-'||s[i]=='+'){
        if(s[i]=='-') sign=-1;
        i++;
    }
    while(s[i]>='0'&&s[i]<='9'){
        num=num*10+(s[i]-'0');
        if(sign==1&&num>2147483647) return 2147483647;
        if(sign==-1&&-num<-2147483648) return -2147483648;
        i++;
    }
    return (int)(sign*num);
}