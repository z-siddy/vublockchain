# VU Blockchain Hash

![enter image description here](https://blog.mozilla.org/webdev/files/2012/06/wonka-md5-300x300.jpg)


# Short intro
Link to the task can be found [here](https://github.com/blockchain-group/Blockchain-technologijos/blob/master/pratybos/1uzduotis-Hashavimas.md).
Main purpose of this program is to execute custom-made hashing algorithm.

# Hashing benchmark
## One different letter in separate files
**z.txt**

`
HASHED FILE OUTPUT:
 A3EF1bcEada172fEDFb4c0BaBBCdcfEdcE998Ea4A18Ce8dB078CcFecFbBFfACe
 File hashing process took: 0 s
`

**s.txt**

`
HASHED FILE OUTPUT:
c8DdBFf9F49130eFBd67a6BCa3EfAF9dcdd5bC3FD5DCbceFFf83dEdFA1Abde8A
File hashing process took: 0 s
`

## Two different 10000 char files
**10000a.txt**

`HASHED FILE OUTPUT:
 E5BDCCbf86A2c47cCCA3318c3DaFc91a4CFb25A0FFcb9F9BFdA1B6CF1F5fDfDE
 File hashing process took: 0.0009961 s
`

**10000b.txt**

`HASHED FILE OUTPUT:
 4DaFa262DAAA19D1e68ec40D3AdaecCeAb7Bcc10aC7d960454BaCBeddDbc8c4E
 File hashing process took: 0 s
`

## Two same 10000 char files that differ only by one char

**long1.txt**

`HASHED FILE OUTPUT:
 4abc42df0CEfba1BD764e4Fffec8D4ae6Da4ff9294cDbdDF9f992dEFcBC13Aaf
 File hashing process took: 0.0009981 s
`

**long2.txt**

`HASHED FILE OUTPUT:
 0eB79ED5DAff9FAaB4ABeEDafFA2aE65cCebCaF80FebB6eEb8ec6D823be7aa7b
 File hashing process took: 0.0009985 s
`

## An empty file

**empty.txt**

`HASHED FILE OUTPUT:
 4DaFa262DAAA19D1e68ec40D3AdaecCeAb7Bcc10aC7d960454BaCBeddDbc8c4E
 File hashing process took: 0 s
`

## konstitucija.txt

`HASHED FILE OUTPUT:
 aEF6efbf7BcE7AdC4ec5faD2faACaB0DAd63a435a7AFCab4d5E7CA971cEdCaCb
 File hashing process took: 0.0029906 s
`

## Collision count in 1 000 000 random pairs of 5-char strings 
`Generation and hashing process took: 69.3673 s`

`Number of collisions: 109`

## Collision count in 1 000 000 random pairs of 5-char strings that differ only by one char 
`Generation and hashing process took: 54.3357 s`

`Number of collisions: 0`