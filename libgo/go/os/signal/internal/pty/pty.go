// Copyright 2017 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

// +build darwin dragonfly freebsd linux,!android netbsd openbsd

// Package pty is a simple pseudo-terminal package for Unix systems,
// implemented by calling C functions via cgo.
// This is only used for testing the os/signal package.
package pty

import (
	"fmt"
	"os"
	"syscall"
	"unsafe"
)

//extern posix_openpt
func posix_openpt(int32) int32

//extern grantpt
func grantpt(int32) int32

//extern unlockpt
func unlockpt(int32) int32

//extern ptsname
func ptsname(int32) *byte

//extern close
func close(int32) int32

const _O_RDWR = 2

// Open returns a master pty and the name of the linked slave tty.
func Open() (master *os.File, slave string, err error) {
	m := posix_openpt(_O_RDWR)
	if m < 0 {
		return nil, "", fmt.Errorf("posix_openpt: %v", syscall.GetErrno())
	}
	if grantpt(m) < 0 {
		errno := syscall.GetErrno()
		close(m)
		return nil, "", fmt.Errorf("grantpt: %v", errno)
	}
	if unlockpt(m) < 0 {
		errno := syscall.GetErrno()
		close(m)
		return nil, "", fmt.Errorf("unlockpt: %v", errno)
	}
	p := ptsname(m)
	s := (*[32000]byte)(unsafe.Pointer(p))[:]
	for i, v := range s {
		if v == 0 {
			s = s[:i:i]
			break
		}
	}
	slave = string(s)
	return os.NewFile(uintptr(m), "pty-master"), slave, nil
}
