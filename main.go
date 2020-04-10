package main

import (
	"fmt"
	"github.com/ope-lib-golang/ope"
)

func main() {
	ope.NewOPE("this is a key")
	input := []int{10, 20, 30, 33, 56, 78, 90, 138, 245, 678}
	for _, in := range input {
		cipherText := ope.Encrypt(in)
		plainText := ope.Decrypt(cipherText)
		fmt.Printf("num:%d cipherText=%d plainText=%d\n", in, cipherText, plainText)
	}
}
