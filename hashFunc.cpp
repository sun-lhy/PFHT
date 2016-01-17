/********************************************************************* 
*                          常用hash函数 
*                          (c)copyright
*                         All Right Reserved 
**********************************************************************/  
//加法hash
int additiveHash(char key, int prime)
 {
  int hash, i,length;
  for (hash = key.length(), i = 0; i < key.length(); i++)
   hash += key.charAt(i);
  return (hash % prime);
 }
//乘法hash
 int bernstein(char key)
 {
   int hash = 0;
   int i;
   for (i=0; i<key.length(); ++i) 
	   hash = 33*hash + key.charAt(i);
   return hash;
 }
//数组hash
 int hashcode(const int *v)
{
int hash = 0,k,prime;
for(int i=0; i<k; i++)
hash=((hash<<2)+(v[i]>>4))^(v[i]<<10);
hash = hash % prime;
hash = hash < 0 ? hash + prime : hash;
return hash;
}

void main()
{
    char  key="hello" ;
	int prime=7;
	int v[5]={1,2,3,4,5};
	additiveHash(key,prime);
	bernstein(key);
	hashcode(*v[5]);
}





