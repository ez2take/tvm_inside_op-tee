#include <tvm/fix_crt.h>
#include <stdint.h>

//------------------------strtol--------------------------------------------
long int strtol(char * s,
			char ** endptr, int base){
    int isnegative = 0;           // 0(default):+ , 1:+, -1:-
    long int ret = 0;
    int readplus = 0;
    while(isspace(*s) || *s == '+' || *s == '-') {
        if( *s == '-'){
            if(!readplus && isnegative == 0) isnegative = 1;
            else break;
        }else if( *s == '+'){
            if(readplus || isnegative == 1) break;
            readplus = 1;
        }
        ++s;
    }
    if(*s == '0'){
        ++s;
        if( ((*s)|0x20) == 'x' && (base == 0||base == 16)){
            ++s;
            base = 16;
        }else if(base == 0){
            base = 8;
        }
    }else if(base == 0)
        base = 10;
    
    for(int c = ((*s)|0x20); ('0' <= c && c <= '9')||('a' <= c && c <~ 'z'); c = ((*++s)|0x20)){
        int digit = ('0' <= c && c <= '9')? c - '0': c - 'a' + 10;
        if(digit >= base) break;
        if(isnegative > 0 && ret > (INT32_MAX + isnegative - digit) / base){
            ret = INT32_MAX + isnegative;
            break;
        }
        ret = ret*base + digit;
    } 
    if(endptr) *endptr = s;
    if(isnegative == 1) ret = -ret;
    return ret;
}



// ------------------ expf --------------------------------------------------------
double fma(double x, double y, double z){
    return (x * y) + z;
}
void memcpy_proto(void* dst, void* src,int siz){
    char* pdst = dst + siz -1;
    char* psrc = src + siz -1;
    while(--siz >= 0){
        *pdst-- = *psrc--;
    }
}
double bit_cast_from_uint64_to_double(uint64_t from){
    double to;
    memcpy_proto(&to, &from, sizeof(uint64_t));
    return to;
}
uint64_t   bit_cast_from_double_to_uint64(double from){
    uint64_t to;
    memcpy_proto(&to, &from, sizeof(double));
    return to;
}
double expm1_taylor3( double t1 ) {
    const double C2 = 1.0 / 2.0;
    const double C3 = 1.0 / 6.0;
    const double s1 = fma( C3, t1, C2 );
    const double t2 = t1 * t1;
    return fma( s1, t2, t1 );
}

double exp_table( uint64_t s ) {
    const double b1table[32]  = {
        0x1.0000000000000p+0,
        0x1.059b0d3158574p+0,
        0x1.0b5586cf9890fp+0,
        0x1.11301d0125b51p+0,
        0x1.172b83c7d517bp+0,
        0x1.1d4873168b9aap+0,
        0x1.2387a6e756238p+0,
        0x1.29e9df51fdee1p+0,
        0x1.306fe0a31b715p+0,
        0x1.371a7373aa9cbp+0,
        0x1.3dea64c123422p+0,
        0x1.44e086061892dp+0,
        0x1.4bfdad5362a27p+0,
        0x1.5342b569d4f82p+0,
        0x1.5ab07dd485429p+0,
        0x1.6247eb03a5585p+0,
        0x1.6a09e667f3bcdp+0,
        0x1.71f75e8ec5f74p+0,
        0x1.7a11473eb0187p+0,
        0x1.82589994cce13p+0,
        0x1.8ace5422aa0dbp+0,
        0x1.93737b0cdc5e5p+0,
        0x1.9c49182a3f090p+0,
        0x1.a5503b23e255dp+0,
        0x1.ae89f995ad3adp+0,
        0x1.b7f76f2fb5e47p+0,
        0x1.c199bdd85529cp+0,
        0x1.cb720dcef9069p+0,
        0x1.d5818dcfba487p+0,
        0x1.dfc97337b9b5fp+0,
        0x1.ea4afa2a490dap+0,
        0x1.f50765b6e4540p+0,
    };

    const double b2table[32] = {
        0x1.0000000000000p+0,
        0x1.002c605e2e8cfp+0,
        0x1.0058c86da1c0ap+0,
        0x1.0085382faef83p+0,
        0x1.00b1afa5abcbfp+0,
        0x1.00de2ed0ee0f5p+0,
        0x1.010ab5b2cbd11p+0,
        0x1.0137444c9b5b5p+0,
        0x1.0163da9fb3335p+0,
        0x1.019078ad6a19fp+0,
        0x1.01bd1e77170b4p+0,
        0x1.01e9cbfe113efp+0,
        0x1.02168143b0281p+0,
        0x1.02433e494b755p+0,
        0x1.027003103b10ep+0,
        0x1.029ccf99d720ap+0,
        0x1.02c9a3e778061p+0,
        0x1.02f67ffa765e6p+0,
        0x1.032363d42b027p+0,
        0x1.03504f75ef071p+0,
        0x1.037d42e11bbccp+0,
        0x1.03aa3e170aafep+0,
        0x1.03d7411915a8ap+0,
        0x1.04044be896ab6p+0,
        0x1.04315e86e7f85p+0,
        0x1.045e78f5640b9p+0,
        0x1.048b9b35659d8p+0,
        0x1.04b8c54847a28p+0,
        0x1.04e5f72f654b1p+0,
        0x1.051330ec1a03fp+0,
        0x1.0540727fc1762p+0,
        0x1.056dbbebb786bp+0,
    };

    const double b1 = b1table[s>>5&31];
    const double b2 = b2table[s&31];
    const uint64_t exponent = (s >> 10) << 52;
    double ret = bit_cast_from_uint64_to_double( bit_cast_from_double_to_uint64( b1 * b2 ) + exponent );
    return ret;
}


#define HUGE_VALF 0x1.p+127f
float expf( float x ) {
    if( x < -104.0f ) { return 0.0f; }
    if( x > 0x1.62e42ep+6f ) { return HUGE_VALF; }

    const double R    =  0x3.p+51;
    const double iln2 =  0x1.71547652b82fep+0 * 0x1.p+10;
    const double ln2h =  0x1.62e42fefc0000p-1 / 0x1.p+10;
    const double ln2l =  0x1.c610ca86c3899p-37/ 0x1.p+10;

    const double k_R     = fma( (double)(x), iln2, R );
    const double k       = k_R - R;

    const double t       = fma( k, -ln2l, fma( k, -ln2h, (double)(x) ) );
    const double exp_s   = exp_table( bit_cast_from_double_to_uint64(k_R) );
    const double expm1_t = expm1_taylor3( t );
    const double exp_x   = fma( exp_s, expm1_t, exp_s );
    return (float)( exp_x );
}

