
const int MAXN = 1e6 + 5;
const long long mod = 1e9 + 7;

//pre-compute factorial values
unsigned long long f[MAXN];
unsigned long long invf[MAXN];

//make factorials upto required before any ohter computation
void factorial(){
   //factorials % mod
   f[0]=1;
   invf[0]=invf[1]=1;
   for(int i=1; i<=MAXN; i++){
       f[i]=(f[i-1]*i)%mod;
    }
    for(int i=2; i<MAXN; ++i){
         invf[i] = (mod - mod/i) * invf[mod % i] % mod;
    }
    for(int i=1;i<MAXN; ++i){
         invf[i] = (invf[i-1] * invf[i])%mod;
    }
}


// To calculates a^x mod m in logarithmic time O(logx).
unsigned long long modPow(unsigned long long a, int x, long long int m) {
   unsigned long long res = 1;
   a=a%m;
   while(x > 0) {
      if( x & 1) {
           res = (res * a) % m;
       }
       a = (a * a) % m;
       x = x >> 1; // x=x/2;
   }
   return res;
}


/////nCr using fermat little theroem in O(1) ( yeah finding factorials and inverse factorials took the main time here as O(N)
unsigned long long nCr_using_Fermet(unsigned long long n, long long r, long long m){
   //base Case
   if(r==0){
      return 1;
   }
   if(n<r){
      return 0;
   }
   long long res = (f[n] * invf[r])%m;
   return  (res * invf[n-r])%m ;
   //return (f[n] * modInverse(f[r], m) % m * modInverse(f[n-r],m) %m) %m;
}
