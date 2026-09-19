/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** letterCombinations(char* digits,int* returnSize){
    char* map[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int n=strlen(digits);
    *returnSize=1;
    for(int i=0;i<n;i++) *returnSize*=strlen(map[digits[i]-'0']);
    char** result=malloc((*returnSize)*sizeof(char*));
    for(int i=0;i<*returnSize;i++){
        result[i]=malloc((n+1)*sizeof(char));
        int x=i;
        for(int j=n-1;j>=0;j--){
            char* letters=map[digits[j]-'0'];
            int len=strlen(letters);
            result[i][j]=letters[x%len];
            x/=len;
        }
        result[i][n]='\0';
    }
    return result;
}