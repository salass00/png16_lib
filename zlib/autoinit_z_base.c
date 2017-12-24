/*
 * AmigaOS shared library implementation of libpng 1.6.x
 *
 * Copyright (C) 2017 Fredrik Wikstrom <fredrik@a500.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS `AS IS'
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <libraries/z.h>

#include <interfaces/z.h>
#include <proto/exec.h>
#include <assert.h>

/****************************************************************************/

struct Library * ZBase = NULL;
static struct Library * __ZBase;

/****************************************************************************/

void _INIT_5_ZBase(void)
{
    if (ZBase != NULL)
    {
        return; /* Someone was quicker, e.g. an interface constructor */
    }
    __ZBase = ZBase = IExec->OpenLibrary("z.library", 53L);
    assert(ZBase != NULL);
    assert(LIB_IS_AT_LEAST(ZBase, 53, 9));
}
__attribute__((section(".ctors.zzzz"))) static void
(*z_base_constructor_ptr)(void) USED = _INIT_5_ZBase;

/****************************************************************************/

void _EXIT_5_ZBase(void)
{
    if (__ZBase)
    {
        IExec->CloseLibrary(__ZBase);
    }
}
__attribute__((section(".dtors.zzzz"))) static void
(*z_base_destructor_ptr)(void) USED = _EXIT_5_ZBase;

/****************************************************************************/

