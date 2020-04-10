# Golang OPE from CryptDB

This is the Order-preserving encryption (OPE) lib extracted from the CryptoDB (http://css.csail.mit.edu/cryptdb/).  we just want OPE lib, so this it is not necessary to compile the whole CryptDB to use the OPE lib.

Then, use C function to wrap C++ class method. At last, use CGO to promise Golang code call. 

### requirenments

- GO
- g++
- make
- OpenSSL
- NTL

### Install

```
make install
```

```
go run main.go
```

### Usage

```go
ope.NewOPE("this is a key")
input := []int{10, 20, 30, 33, 56, 78, 90, 138, 245, 678}
for _, in := range input {
        cipherText := ope.Encrypt(in)
	plainText := ope.Decrypt(cipherText)
	fmt.Printf("num:%d cipherText=%d plainText=%d\n", in, cipherText, plainText)
}
```

```go
num:0 cipherText=3198016286 plainText=0
num:10 cipherText=49732388173 plainText=10
num:20 cipherText=102598871581 plainText=20
num:30 cipherText=149743672874 plainText=30
num:33 cipherText=156633669267 plainText=33
num:56 cipherText=245525400720 plainText=56
num:78 cipherText=349751403748 plainText=78
num:90 cipherText=408944270601 plainText=90
num:138 cipherText=617561141893 plainText=138
```

Enjoy it!
