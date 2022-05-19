# Computation of logarithm for complex numbers

The project introduces the computation of the complex number's natural logarithm based on the fast algorithm for CORDIC.

## Building process

To build the application, run the following commands:

```bash
$ mkdir build && cd build
$ cmake -DCMAKE_BUILD_TYPE=Release ..
$ make
```

## Usage

To use the application, run the following :

```bash
$ ./logz <parameter>=<value> ...
```

### Parameters

* `Re` : the real part of the complex number
* `Im` : the imaginary part of the complex number
* `Kc` : scale factor of the algorithm

## Bibliography

* H.Chen, Z.Yu, Y.Zhang, Zh.Lu, Y.Fu, L.Li. (2021). Low-Complexity High-Precision Method and Architecture for Computing the Logarithm of Complex Numbers
