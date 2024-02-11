// Hash-tables in c
//
//

// Divison method

/* treat strings as base-256 integers */
/* with digits in the range 1 to 255 */
#define BASE (256)

unsigned long
hash(const char *s, unsigned long m)
{
    unsigned long h;
    unsigned const char *us;

    /* cast s to unsigned const char * */
    /* this ensures that elements of s will be treated as having values >= 0 */
    us = (unsigned const char *) s;

    h = 0;
    while(*us != '\0') {
        h = (h * BASE + *us) % m;
        us++;
    } 

    return h;
}

// Multiplication method

#define MULTIPLIER (37)

unsigned long
hash(const char *s)
{
    unsigned long h;
    unsigned const char *us;

    /* cast s to unsigned const char * */
    /* this ensures that elements of s will be treated as having values >= 0 */
    us = (unsigned const char *) s;

    h = 0;
    while(*us != '\0') {
        h = h * MULTIPLIER + *us;
        us++;
    }

    return h;
}

// Univershal hashing

/* implements universal hashing using random bit-vectors in x */
/* assumes number of elements in x is at least BITS_PER_CHAR * MAX_STRING_SIZE */

#define BITS_PER_CHAR (8)       /* not true on all machines! */
#define MAX_STRING_SIZE (128)   /* we'll stop hashing after this many */
#define MAX_BITS (BITS_PER_CHAR * MAX_STRING_SIZE)

unsigned long
hash(const char *s, unsigned long x[])
{
    unsigned long h;
    unsigned const char *us;
    int i;
    unsigned char c;
    int shift;

    /* cast s to unsigned const char * */
    /* this ensures that elements of s will be treated as having values >= 0 */
    us = (unsigned const char *) s;

    h = 0;
    for(i = 0; *us != 0 && i < MAX_BITS; us++) {
        c = *us;
        for(shift = 0; shift < BITS_PER_CHAR; shift++, i++) {
            /* is low bit of c set? */
            if(c & 0x1) {
                h ^= x[i];
            }

            /* shift c to get new bit in lowest position */
            c >>= 1;
        }
    }

    return h;
}
