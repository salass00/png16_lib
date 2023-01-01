/*
 * AmigaOS shared library implementation of libpng 1.6.x
 *
 * Copyright (C) 2017-2023 Fredrik Wikstrom <fredrik@a500.org>
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

#include <interfaces/png16.h>
#include <proto/exec.h>
#include <assert.h>

struct PNG16IFace * IPNG16 = NULL;
static struct Library * __PNG16Base;
static struct PNG16IFace * __IPNG16;

/****************************************************************************/

extern struct Library * PNG16Base;

/****************************************************************************/

void _INIT_5_IPNG16(void)
{
    if (PNG16Base == NULL) /* Library base is NULL, we need to open it */
    {
        /* We were called before the base constructor.
         * This means we will be called _after_ the base destructor.
         * So we cant drop the interface _after_ closing the last library base,
         * we just open the library here which ensures that.
         */
        __PNG16Base = PNG16Base = IExec->OpenLibrary("png16.library", 53L);
        assert(PNG16Base != NULL);
    }

    __IPNG16 = IPNG16 = (struct PNG16IFace *)IExec->GetInterface((struct Library *)PNG16Base, "main", 1, NULL);
    assert(IPNG16 != NULL);
}
__attribute__((section(".ctors.zzzy"))) static void
(*png16_main_constructor_ptr)(void) USED = _INIT_5_IPNG16;

/****************************************************************************/

void _EXIT_5_IPNG16(void)
{
    if (__IPNG16)
    {
        IExec->DropInterface ((struct Interface *)__IPNG16);
    }
    if (__PNG16Base)
    {
        IExec->CloseLibrary(__PNG16Base);
    }
}
__attribute__((section(".dtors.zzzy"))) static void
(*png16_main_destructor_ptr)(void) USED = _EXIT_5_IPNG16;

/****************************************************************************/

