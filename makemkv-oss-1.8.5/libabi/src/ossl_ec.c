/*
    libMakeMKV - MKV multiplexer library

    Copyright (C) 2007-2013 GuinpinSoft inc <libmkv@makemkv.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

*/
#include <lgpl/osslabi.h>
#include <openssl/opensslconf.h>

#ifndef OPENSSL_NO_EC
#include <openssl/ec.h>
#include <openssl/ecdsa.h>
#else
#include <pssl/ec.h>
#include <pssl/ecdsa.h>
#endif

/* BN */

OSSL_BIGNUM *OSSL_BN_new(void)
{
    return (OSSL_BIGNUM*)BN_new();
}

void OSSL_BN_free(OSSL_BIGNUM *a)
{
    BN_free((BIGNUM*)a);
}

OSSL_BIGNUM *OSSL_BN_bin2bn(const unsigned char *s,int len,OSSL_BIGNUM *ret)
{
    return (OSSL_BIGNUM*)BN_bin2bn(s,len,(BIGNUM*)ret);
}

int OSSL_BN_bn2bin(const OSSL_BIGNUM *a, unsigned char *to)
{
    return BN_bn2bin((const BIGNUM*)a,to);
}

int OSSL_BN_dec2bn(OSSL_BIGNUM **a, const char *str)
{
    return BN_dec2bn((BIGNUM**)a,str);
}

int OSSL_BN_ucmp(const OSSL_BIGNUM *a, const OSSL_BIGNUM *b)
{
    return BN_ucmp((const BIGNUM*)a,(const BIGNUM*)b);
}

int OSSL_BN_is_zero(const OSSL_BIGNUM *a)
{
    return BN_is_zero((const BIGNUM*)a);
}

int OSSL_BN_set_word(OSSL_BIGNUM *a, uint32_t w)
{
    return BN_set_word((BIGNUM*)a,w);
}

int OSSL_BN_nnmod(OSSL_BIGNUM *r, const OSSL_BIGNUM *m, const OSSL_BIGNUM *d, OSSL_BN_CTX *ctx)
{
    return BN_nnmod((BIGNUM*)r,(const BIGNUM*)m,(const BIGNUM*)d,(BN_CTX*)ctx);
}

OSSL_BIGNUM *OSSL_BN_mod_inverse(OSSL_BIGNUM *ret, const OSSL_BIGNUM *a, const OSSL_BIGNUM *n,OSSL_BN_CTX *ctx)
{
    return (OSSL_BIGNUM *)BN_mod_inverse((BIGNUM*)ret,(const BIGNUM*)a,(const BIGNUM*)n,(BN_CTX*)ctx);
}

OSSL_BN_CTX *OSSL_BN_CTX_new(void)
{
    return (OSSL_BN_CTX *)BN_CTX_new();
}

void OSSL_BN_CTX_free(OSSL_BN_CTX *c)
{
    BN_CTX_free((BN_CTX*)c);
}

/* EC */

const OSSL_EC_POINT *OSSL_EC_GROUP_get0_generator(const OSSL_EC_GROUP *grp)
{
    return (const OSSL_EC_POINT *)EC_GROUP_get0_generator((const EC_GROUP *)grp);
}

int OSSL_EC_GROUP_set_generator(OSSL_EC_GROUP *grp, const OSSL_EC_POINT *generator, const OSSL_BIGNUM *order, const OSSL_BIGNUM *cofactor)
{
    return EC_GROUP_set_generator((EC_GROUP *)grp,(const EC_POINT *)generator, (const BIGNUM *)order, (const BIGNUM *)cofactor);
}

int OSSL_EC_GROUP_get_order(const OSSL_EC_GROUP *grp, OSSL_BIGNUM *order, OSSL_BN_CTX *ctx)
{
    return EC_GROUP_get_order((const EC_GROUP *)grp, (BIGNUM *)order, (BN_CTX *)ctx);
}

OSSL_EC_GROUP *OSSL_EC_GROUP_new_curve_GFp(const OSSL_BIGNUM *p, const OSSL_BIGNUM *a, const OSSL_BIGNUM *b, OSSL_BN_CTX *ctx)
{
    return (OSSL_EC_GROUP *) EC_GROUP_new_curve_GFp((const BIGNUM *)p, (const BIGNUM *)a, (const BIGNUM *)b, (BN_CTX *)ctx);
}

OSSL_EC_POINT *OSSL_EC_POINT_new(const OSSL_EC_GROUP *grp)
{
    return (OSSL_EC_POINT *) EC_POINT_new((const EC_GROUP *)grp);
}

void OSSL_EC_POINT_free(OSSL_EC_POINT *point)
{
    EC_POINT_free((EC_POINT *)point);
}

int OSSL_EC_POINT_mul(const OSSL_EC_GROUP *grp, OSSL_EC_POINT *r, const OSSL_BIGNUM *a, const OSSL_EC_POINT *b, const OSSL_BIGNUM *c, OSSL_BN_CTX *ctx)
{
    return EC_POINT_mul((const EC_GROUP *)grp, (EC_POINT *)r, (const BIGNUM *)a, (const EC_POINT *)b, (const BIGNUM *)c, (BN_CTX *)ctx);
}

int OSSL_EC_POINT_set_affine_coordinates_GFp(const OSSL_EC_GROUP *grp, OSSL_EC_POINT *point,
    const OSSL_BIGNUM *x, const OSSL_BIGNUM *y, OSSL_BN_CTX *ctx)
{
    return EC_POINT_set_affine_coordinates_GFp((const EC_GROUP *)grp, (EC_POINT *)point,
        (const BIGNUM *)x, (const BIGNUM *)y, (BN_CTX *)ctx);
}

int OSSL_EC_POINT_get_affine_coordinates_GFp(const OSSL_EC_GROUP *grp, const OSSL_EC_POINT *point,
    OSSL_BIGNUM *x, OSSL_BIGNUM *y, OSSL_BN_CTX *ctx)
{
    return EC_POINT_get_affine_coordinates_GFp((const EC_GROUP *)grp, (const EC_POINT *)point,
        (BIGNUM *)x, (BIGNUM *)y, (BN_CTX *)ctx);
}

OSSL_EC_KEY *OSSL_EC_KEY_new(void)
{
    return (OSSL_EC_KEY *)EC_KEY_new();
}

void OSSL_EC_KEY_free(OSSL_EC_KEY *key)
{
    EC_KEY_free((EC_KEY *)key);
}

const OSSL_EC_GROUP *OSSL_EC_KEY_get0_group(const OSSL_EC_KEY *key)
{
    return (const OSSL_EC_GROUP *)EC_KEY_get0_group((const EC_KEY *)key);
}

int OSSL_EC_KEY_set_group(OSSL_EC_KEY *key, const OSSL_EC_GROUP *grp)
{
    return EC_KEY_set_group((EC_KEY *)key, (const EC_GROUP *)grp);
}

int OSSL_EC_KEY_set_public_key(OSSL_EC_KEY *key, const OSSL_EC_POINT *point)
{
    return EC_KEY_set_public_key((EC_KEY *)key, (const EC_POINT *)point);
}

int OSSL_EC_KEY_set_private_key(OSSL_EC_KEY *key, const OSSL_BIGNUM *a)
{
    return EC_KEY_set_private_key((EC_KEY *)key, (const BIGNUM *)a);
}

/* ECDSA */

int OSSL_ECDSA_do_verify_rs(const unsigned char *dgst, int dgst_len,const OSSL_BIGNUM *sig_r,const OSSL_BIGNUM *sig_s,OSSL_EC_KEY* eckey)
{
    ECDSA_SIG sig;
    sig.r = (BIGNUM *)sig_r;
    sig.s = (BIGNUM *)sig_s;
    return ECDSA_do_verify(dgst,dgst_len,&sig,(EC_KEY*) eckey);
}

int OSSL_ECDSA_sign_setup(OSSL_EC_KEY *eckey, OSSL_BIGNUM **kinv, OSSL_BIGNUM **rp)
{
    return ECDSA_sign_setup( (EC_KEY *)eckey , NULL, (BIGNUM**) kinv, (BIGNUM**) rp);
}

OSSL_ECDSA_SIG *OSSL_ECDSA_do_sign_ex(const unsigned char *dgst, int dgstlen,const OSSL_BIGNUM *kinv, const OSSL_BIGNUM *rp, OSSL_EC_KEY *eckey)
{
    return (OSSL_ECDSA_SIG *)ECDSA_do_sign_ex(dgst,dgstlen,(const BIGNUM *)kinv, (const BIGNUM *)rp, (EC_KEY *)eckey);
}

const OSSL_BIGNUM* OSSL_ecdsa_sig_get_r(const OSSL_ECDSA_SIG* sig)
{
    return (const OSSL_BIGNUM*) ((const ECDSA_SIG*)sig)->r;
}

const OSSL_BIGNUM* OSSL_ecdsa_sig_get_s(const OSSL_ECDSA_SIG* sig)
{
    return (const OSSL_BIGNUM*) ((const ECDSA_SIG*)sig)->s;
}

void OSSL_ECDSA_SIG_free(OSSL_ECDSA_SIG *a)
{
    ECDSA_SIG_free((ECDSA_SIG *)a);
}

