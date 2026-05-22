class RollingHash {
public:
    const long long p = 31;
    const long long mod = 1e9 + 7;
    vector<long long> power;
    vector<long long> pref;
    RollingHash(vector<int> &temp) {
        int n = temp.size();
        power.resize(n + 1);
        pref.resize(n + 1);
        power[0] = 1;
        for(int i = 1; i <= n; i++) {
            power[i] = (power[i-1] * p) % mod;
        }
        pref[0] = 0;
        for(int i = 0; i < n; i++) {
            pref[i+1] =(pref[i] + temp[i] * power[i]) % mod;
        }
    }
    long long getHash(int l, int r) {
        long long hash =(pref[r+1] - pref[l] + mod) % mod;
        hash =(hash * modInverse(power[l])) % mod;
        return hash;
    }
    long long modExpo(long long a, long long b) {
        long long res = 1;
        while(b) {
            if(b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    long long modInverse(long long x) {
        return modExpo(x, mod - 2);
    }
};
