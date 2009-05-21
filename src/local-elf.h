/*
 * Copyright © 2009 Guillem Jover
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef LIBBSD_LOCAL_ELF_H
#define LIBBSD_LOCAL_ELF_H

#include <elf.h>

#define IS_ELF(ehdr) \
	((ehdr).e_ident[EI_MAG0] == ELFMAG0 && \
	 (ehdr).e_ident[EI_MAG1] == ELFMAG1 && \
	 (ehdr).e_ident[EI_MAG2] == ELFMAG2 && \
	 (ehdr).e_ident[EI_MAG3] == ELFMAG3)

#define ELF_TARG_VER	EV_CURRENT

#if defined(__alpha__)

#define ELF_TARG_MACH	EM_ALPHA
#define ELF_TARG_CLASS	ELFCLASS64
#define ELF_TARG_DATA	ELFDATA2LSB

#elif defined(__amd64__)

#define ELF_TARG_MACH	EM_X86_64
#define ELF_TARG_CLASS	ELFCLASS64
#define ELF_TARG_DATA	ELFDATA2LSB

#elif defined(__arm__)

#define ELF_TARG_MACH	EM_ARM
#define ELF_TARG_CLASS	ELFCLASS32
#if defined(__ARMEB__)
#define ELF_TARG_DATA	ELFDATA2MSB
#else
#define ELF_TARG_DATA	ELFDATA2LSB
#endif

#elif defined(__avr32__)

#ifndef EM_AVR32
#define EM_AVR32	0x18ad
#endif
#define ELF_TARG_MACH	EM_AVR32
#define ELF_TARG_CLASS	ELFCLASS32
#if define(__LITTLE_ENDIAN__)
#define ELF_TARG_DATA	ELFDATA2LSB
#elif defined(__BIG_ENDIAN__)
#define ELF_TARG_DATA	ELFDATA2LMSB
#else
#error Unknown AVR32 endianness
#endif

#elif defined(__hppa__)

#define ELF_TARG_MACH	EM_PARISC
#define ELF_TARG_CLASS	ELFCLASS32
#define ELF_TARG_DATA	ELFDATA2MSB

#elif defined(__i386__)

#define ELF_TARG_MACH	EM_386
#define ELF_TARG_CLASS	ELFCLASS32
#define ELF_TARG_DATA	ELFDATA2LSB

#elif defined(__ia64__)

#define ELF_TARG_MACH	EM_IA_64
#define ELF_TARG_CLASS	ELFCLASS64
#define ELF_TARG_DATA	ELFDATA2LSB

#elif defined(__m32r__)

#define ELF_TARG_MACH	EM_M32R
#define ELF_TARG_CLASS	ELFCLASS32
#if defined(__LITTLE_ENDIAN__)
#define ELF_DATA	ELFDATA2LSB
#elif defined(__BIG_ENDIAN__)
#define ELF_DATA	ELFDATA2MSB
#else
#error Unknown M32R endianness
#endif

#elif defined(__m68k__)

#define ELF_TARG_MACH	EM_68K
#define ELF_TARG_CLASS	ELFCLASS32
#define ELF_TARG_DATA	ELFDATA2MSB

#elif defined(__mips__)

#define ELF_TARG_MACH	EM_MIPS
#define ELF_TARG_CLASS	ELFCLASS32
#if defined(__MIPSEB__)
#define ELF_TARG_DATA	ELFDATA2MSB
#else
#define ELF_TARG_DATA	ELFDATA2LSB
#endif

#elif defined(__powerpc__)

#define ELF_TARG_MACH	EM_PPC
#define ELF_TARG_CLASS	ELFCLASS32
#define ELF_TARG_DATA	ELFDATA2MSB

#elif defined(__powerpc64__)

#define ELF_TARG_MACH	EM_PPC64
#define ELF_TARG_CLASS	ELFCLASS64
#define ELF_TARG_DATA	ELFDATA2MSB

#elif defined(__sparc__)

#if defined(__arch64__)
#define ELF_TARG_MACH	EM_SPARCV9
#define ELF_TARG_CLASS	ELFCLASS64
#else
#define ELF_TARG_MACH	EM_SPARC
#define ELF_TARG_CLASS	ELFCLASS32
#endif
#define ELF_TARG_DATA	ELFDATA2MSB

#elif defined(__sh__)

#define ELF_TARG_MACH	EM_SH
#define ELF_TARG_CLASS	ELFCLASS32
#if define(__LITTLE_ENDIAN__)
#define ELF_TARG_DATA	ELFDATA2LSB
#elif defined(__BIG_ENDIAN__)
#define ELF_TARG_DATA	ELFDATA2LMSB
#else
#error Unknown SH endianness
#endif

#elif defined(__s390__)

#define ELF_TARG_MACH	EM_S390
#if defined(__s390x__)
#define ELF_TARG_CLASS	ELFCLASS64
#else
#define ELF_TARG_CLASS	ELFCLASS32
#endif
#define ELF_TARG_DATA	ELFDATA2MSB

#else

#error Unknown ELF machine type

#endif

#if ELF_TARG_CLASS == ELFCLASS32
#define ELF_ST_BIND	ELF32_ST_BIND
#define ELF_ST_TYPE	ELF32_ST_TYPE
#define Elf_Word	Elf32_Word
#define Elf_Sword	Elf32_Sword
#define Elf_Sym		Elf32_Sym
#define Elf_Off		Elf32_Off
#define Elf_Shdr	Elf32_Shdr
#define Elf_Ehdr	Elf32_Ehdr
#elif ELF_TARG_CLASS == ELFCLASS64
#define ELF_ST_BIND	ELF64_ST_BIND
#define ELF_ST_TYPE	ELF64_ST_TYPE
#define Elf_Word	Elf64_Word
#define Elf_Sword	Elf64_Sword
#define Elf_Sym		Elf64_Sym
#define Elf_Off		Elf64_Off
#define Elf_Shdr	Elf64_Shdr
#define Elf_Ehdr	Elf64_Ehdr
#else
#error Unknown ELF class
#endif

#endif

