/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Header of the elf function and struct
*/

#if !defined(_ELF_READER_H)
#define _ELF_READER_H

#include <elf.h>
#include "argument_parser.h"
#include "execution.h"

#define STR_SEC ((char *)header + shdr[header->e_shstrndx].sh_offset)
#define STR_SYMB ((char *)header + shdr[symtab->sh_link].sh_offset)

/* No flags.  */
#define BFD_NO_FLAGS 0x00
#define BFD_NO_FLAGS_STR "BFD_NO_FLAGS"

/* BFD contains relocation entries.  */
#define HAS_RELOC 0x01
#define HAS_RELOC_STR "HAS_RELOC"

/* BFD is directly executable.  */
#define EXEC_P 0x02
#define EXEC_P_STR "EXEC_P"

/* BFD has line number information (basically used for F_LNNO in a
   COFF header).  */
#define HAS_LINENO 0x04
#define HAS_LINENO_STR "HAS_LINENO"

/* BFD has debugging information.  */
#define HAS_DEBUG 0x08
#define HAS_DEBUG_STR "HAS_DEBUG"

/* BFD has symbols.  */
#define HAS_SYMS 0x10
#define HAS_SYMS_STR "HAS_SYMS"

/* BFD has local symbols (basically used for F_LSYMS in a COFF
   header).  */
#define HAS_LOCALS 0x20
#define HAS_LOCALS_STR "HAS_LOCALS"

/* BFD is a dynamic object.  */
#define DYNAMIC 0x40
#define DYNAMIC_STR "DYNAMIC"

/* Text section is write protected (if D_PAGED is not set, this is
   like an a.out NMAGIC file) (the linker sets this by default, but
   clears it for -r or -N).  */
#define WP_TEXT 0x80
#define WP_TEXT_STR "WP_TEXT"

/* BFD is dynamically paged (this is like an a.out ZMAGIC file) (the
   linker sets this by default, but clears it for -r or -n or -N).  */
#define D_PAGED 0x100
#define D_PAGED_STR "D_PAGED"

struct flags_objdump_s {
    int type;
    char *value;
};

typedef struct flags_objdump_s flags_objdump_t;

enum arch_elf_file_e {
    ARCH_NOT_FOUND,
    ARCH_32,
    ARCH_64
};

typedef enum arch_elf_file_e arch_elf_file_t;

struct symbol_list_s {
    Elf64_Sym *sym;
    char *name;
    char type;
    unsigned int value;
};

typedef struct symbol_list_s symbol_list_t;

struct elf_info_s {
    bool static_lib;
    arch_elf_file_t arch;
    char *path;
    Elf64_Ehdr *header;
    Elf64_Shdr *shdr;
    Elf64_Shdr *symtab;
    size_t size;
    symbol_list_t *symbol_list;
};

typedef struct elf_info_s elf_info_t;

void read_elf(argument_parser_t *args, execution_information_t *exec);
elf_info_t *get_info_file(void *file, int fd, char *path, size_t size);
bool is_magic_valid(Elf64_Ehdr *header);
void get_address_symbol(elf_info_t *elf, execution_information_t *exec);
void exec_elf_64(argument_parser_t *args, execution_information_t *exec,
    elf_info_t *elf_info);
void exec_elf_32(argument_parser_t *args, execution_information_t *exec,
    elf_info_t *elf);
char guess_type_64(Elf64_Ehdr *header, Elf64_Shdr *shdr, Elf64_Sym *sym);
char guess_type_32(Elf32_Ehdr *header, Elf32_Shdr *shdr, Elf32_Sym *sym);
void display_symbol(argument_parser_t *args, execution_information_t *exec,
    elf_info_t *elf, unsigned int nb_symbol);
void order_symbol_list(argument_parser_t *args, elf_info_t *elf,
    unsigned int nb_symbol);
char *arch_string_64(Elf64_Ehdr *header);
void display_flags_64(Elf64_Ehdr *header, int flag);
void display_flags_32(Elf32_Ehdr *header, int flag);
void display_value_in_hexa(void *data, unsigned int size);
char *arch_string_32(Elf32_Ehdr *header);

#endif // _ELF_READER_H
