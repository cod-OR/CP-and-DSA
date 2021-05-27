
const int A = 1000000;
int spf[A+1];   // Smallest prime factor 
vector<int> primes;
void pre(){
  spf[1]=1;
  for (int i=2; i<=A; ++i) {
      if (spf[i] == 0) {
          spf[i] = i;
          primes.push_back (i);
      }
      for (int j=0; j<(int)primes.size() && primes[j]<=spf[i] && i*primes[j]<=A; ++j)
          spf[i * primes[j]] = primes[j];
  }
}
