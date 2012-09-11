/*
    libfakechroot -- fake chroot environment
    Copyright (c) 2010 Piotr Roszatycki <dexter@debian.org>

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
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*/


#include <config.h>

#ifdef HAVE_CANONICALIZE_FILE_NAME

#include <stdlib.h>
#include "libfakechroot.h"

#ifdef HAVE___REALPATH_CHK
# include "__realpath_chk.h"
#endif


wrapper(canonicalize_file_name, char *, (const char * name))
{
    char *resolved = malloc(FAKECHROOT_PATH_MAX * 2);
    debug("canonicalize_file_name(\"%s\")", name);
#ifdef HAVE___REALPATH_CHK
    return __realpath_chk(name, resolved, FAKECHROOT_PATH_MAX * 2);
#else
    return realpath(name, resolved);
#endif
}

#endif
