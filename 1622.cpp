constexpr int MOD = 1e9 + 7;

int64_t pow_mod(int64_t b, int64_t p) {
    b %= MOD, p %= MOD;
    int64_t res = 1;
    while (p) {
        if (p & 1) res = res * b % MOD;
        b = b * b % MOD, p /= 2;
    }
    return res;
}

vector<int64_t> get_mult_invs() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int64_t> mult_invs = {1, 1};
    for (int p = 2; p <= 100; ++p) {
        mult_invs.push_back(pow_mod(p, MOD - 2));
    }
    return move(mult_invs);
}

const vector<int64_t> mult_invs = get_mult_invs();

class Fancy {
public:
    Fancy() {
    }

    void append(int val) {
        val -= add;
        val = val * mult_inv % MOD;
        vs.push_back(val);
    }
    
    void addAll(int inc) {
        add += inc;   
    }
    
    void multAll(int m) {
        mult = mult * m % MOD;
        mult_inv = mult_inv * mult_invs[m] % MOD;
        add = add * m % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= vs.size()) {
            return -1;
        }
        return ((vs[idx] * mult % MOD + add) % MOD + MOD) % MOD;
    }

    vector<int64_t> vs;
    int64_t mult = 1, mult_inv = 1;
    int64_t add = 0;
};

