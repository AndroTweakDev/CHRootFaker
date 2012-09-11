#!/bin/sh

srcdir=${srcdir:-.}
. $srcdir/common.inc

prepare 2

fakedir=`cd testtree; pwd -P`

for chroot in chroot fakechroot; do

    if [ $chroot = "chroot" ] && ! is_root; then
        skip $(( $tap_plan / 2 )) "not root"
    else

        mkdir testtree/testdir-$chroot
        t=`$srcdir/$chroot.sh testtree test-statfs /testdir-$chroot 2>&1`
        if echo "$t" | grep "[^0-9]" >/dev/null; then not; fi
        ok "$chroot statfs returns" $t

    fi
done

cleanup
