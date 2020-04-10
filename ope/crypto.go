package ope


/*
#cgo CFLAGS: -I.
#cgo LDFLAGS: -lntl -lgmp -lcrypto -lstdc++
#cgo LDFLAGS: -L../lib -lope -lstdc++
#include "../lib/cwrap.h"
*/
import "C"
import (
	"unsafe"
)

func NewOPE(key string) {
	k := C.CString(key)
	C.NewOPE((*C.char)(unsafe.Pointer(k)))
}

func Encrypt(num int) uint64 {
	cipherText := C.EncryptInt(C.int32_t(num))
	return uint64(cipherText)
}

func Decrypt(cipherText uint64) int {
	plainText := C.DecryptInt(C.uint64_t(cipherText))
	return int(plainText)
}
