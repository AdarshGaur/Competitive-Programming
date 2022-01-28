// Algorithm for fast exponentiation with modulo
const int mod = 1e9 +7;
int modpow(int a, int b){
  a%=mod;
  int r =1;
  while(b){
    if(b&1){
      r = (r*a)%mod;
    }
    a = (a*a)%mod;
    b >>=1;
  }
  return r;
}