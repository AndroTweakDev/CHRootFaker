#!/bin/sh

srcdir=${srcdir:-.}
. $srcdir/common.inc

prepare 1

ok "$chroot dummy test that always succeeds"

cleanup

