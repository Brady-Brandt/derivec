#pragma once

bool derivec_init(const char* file_name);

void derivec_terminate();

void __derivec_debug__(char* type, void* value, int indent);

#define derivec_debug(struct_type, ptr) __derivec_debug__(#struct_type, ptr, 0)

#ifdef DERIVEC_IMPLEMENTATION
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>


#define TAG_array_type               0x01
#define TAG_class_type               0x02
#define TAG_entry_point              0x03
#define TAG_enumeration_type         0x04
#define TAG_formal_parameter         0x05
#define TAG_imported_declaration     0x08
#define TAG_label                    0x0a
#define TAG_lexical_block            0x0b
#define TAG_member                   0x0d
#define TAG_pointer_type             0x0f
#define TAG_reference_type           0x10
#define TAG_compile_unit             0x11
#define TAG_string_type              0x12
#define TAG_structure_type           0x13
#define TAG_subroutine_type          0x15
#define TAG_typedef                  0x16
#define TAG_union_type               0x17
#define TAG_unspecified_parameters   0x18
#define TAG_variant                  0x19
#define TAG_common_block             0x1a
#define TAG_common_inclusion         0x1b
#define TAG_inheritance              0x1c
#define TAG_inlined_subroutine       0x1d
#define TAG_module                   0x1e
#define TAG_ptr_to_member_type       0x1f
#define TAG_set_type                 0x20
#define TAG_subrange_type            0x21
#define TAG_with_stmt                0x22
#define TAG_access_declaration       0x23
#define TAG_base_type                0x24
#define TAG_catch_block              0x25
#define TAG_const_type               0x26
#define TAG_constant                 0x27
#define TAG_enumerator               0x28
#define TAG_file_type                0x29
#define TAG_friend                   0x2a
#define TAG_namelist                 0x2b
#define TAG_namelist_item            0x2c
#define TAG_packed_type              0x2d
#define TAG_subprogram               0x2e
#define TAG_template_type_parameter  0x2f
#define TAG_template_value_parameter 0x30
#define TAG_thrown_type              0x31
#define TAG_try_block                0x32
#define TAG_variant_part             0x33
#define TAG_variable                 0x34
#define TAG_volatile_type            0x35
#define TAG_dwarf_procedure          0x36
#define TAG_restrict_type            0x37
#define TAG_interface_type           0x38
#define TAG_namespace                0x39
#define TAG_imported_module          0x3a
#define TAG_unspecified_type         0x3b
#define TAG_partial_unit             0x3c
#define TAG_imported_unit            0x3d
#define TAG_condition                0x3f
#define TAG_shared_type              0x40
#define TAG_type_unit                0x41
#define TAG_rvalue_reference_type    0x42
#define TAG_template_alias           0x43
#define TAG_coarray_type             0x44
#define TAG_generic_subrange         0x45
#define TAG_dynamic_type             0x46
#define TAG_atomic_type              0x47
#define TAG_call_site                0x48
#define TAG_call_site_parameter      0x49
#define TAG_skeleton_unit            0x4a
#define TAG_immutable_type           0x4b
#define TAG_lo_user                  0x4080
#define TAG_hi_user                  0xffff




#define AT_sibling                    0x01
#define AT_location                   0x02
#define AT_name                       0x03
#define AT_ordering                   0x09
#define AT_byte_size                  0x0b
#define AT_bit_size                   0x0d
#define AT_stmt_list                  0x10
#define AT_low_pc                     0x11
#define AT_high_pc                    0x12
#define AT_language                   0x13
#define AT_discr                      0x15
#define AT_discr_value                0x16
#define AT_visibility                 0x17
#define AT_import                     0x18
#define AT_string_length              0x19
#define AT_common_reference           0x1a
#define AT_comp_dir                   0x1b
#define AT_const_value                0x1c
#define AT_containing_type            0x1d
#define AT_default_value              0x1e
#define AT_inline                     0x20
#define AT_is_optional                0x21
#define AT_lower_bound                0x22
#define AT_producer                   0x25
#define AT_prototyped                 0x27
#define AT_return_addr                0x2a
#define AT_start_scope                0x2c
#define AT_bit_stride                 0x2e
#define AT_upper_bound                0x2f
#define AT_abstract_origin            0x31
#define AT_accessibility              0x32
#define AT_address_class              0x33
#define AT_artificial                 0x34
#define AT_base_types                 0x35
#define AT_calling_convention         0x36
#define AT_count                      0x37
#define AT_data_member_location       0x38
#define AT_decl_column                0x39
#define AT_decl_file                  0x3a
#define AT_decl_line                  0x3b
#define AT_declaration                0x3c
#define AT_discr_list                 0x3d
#define AT_encoding                   0x3e
#define AT_external                   0x3f
#define AT_frame_base                 0x40
#define AT_friend                     0x41
#define AT_identifier_case            0x42
#define AT_namelist_item              0x44
#define AT_priority                   0x45
#define AT_segment                    0x46
#define AT_specification              0x47
#define AT_static_link                0x48
#define AT_type                       0x49
#define AT_use_location               0x4a
#define AT_variable_parameter         0x4b
#define AT_virtuality                 0x4c
#define AT_vtable_elem_location       0x4d
#define AT_allocated                  0x4e
#define AT_associated                 0x4f
#define AT_data_location              0x50
#define AT_byte_stride                0x51
#define AT_entry_pc                   0x52
#define AT_use_UTF                    0x08
#define AT_extension                  0x54
#define AT_ranges                     0x55
#define AT_trampoline                 0x56
#define AT_call_column                0x57
#define AT_call_file                  0x58
#define AT_call_line                  0x59
#define AT_description                0x5a
#define AT_binary_scale               0x5b
#define AT_decimal_scale              0x5c
#define AT_small                      0x5d
#define AT_decimal_sign               0x5e
#define AT_digit_count                0x5f
#define AT_picture_string             0x60
#define AT_mutable                    0x61
#define AT_threads_scaled             0x62
#define AT_explicit                   0x63
#define AT_object_pointer             0x64
#define AT_endianity                  0x65
#define AT_elemental                  0x66
#define AT_pure                       0x67
#define AT_recursive                  0x68
#define AT_signature                  0x69
#define AT_main_subprogram            0x6a
#define AT_data_bit_offset            0x6b
#define AT_const_expr                 0x6c
#define AT_enum_class                 0x6d
#define AT_linkage_name               0x6e
#define AT_string_length_bit_size     0x6f
#define AT_string_length_byte_size    0x70
#define AT_rank                       0x71
#define AT_str_offsets_base           0x72
#define AT_addr_base                  0x73
#define AT_rnglists_base              0x74
#define AT_dwo_name                   0x76
#define AT_reference                  0x77
#define AT_rvalue_reference           0x78
#define AT_macros                     0x79
#define AT_call_all_calls             0x7a
#define AT_call_all_source_calls      0x7b
#define AT_call_all_tail_calls        0x7c
#define AT_call_return_pc             0x7d
#define AT_call_value                 0x7e
#define AT_call_origin                0x7f
#define AT_call_parameter             0x80
#define AT_call_pc                    0x81
#define AT_call_tail_call             0x82
#define AT_call_target                0x83
#define AT_call_target_clobbered      0x84
#define AT_call_data_location         0x85
#define AT_call_data_value            0x86
#define AT_noreturn                   0x87
#define AT_alignment                  0x88
#define AT_export_symbols             0x89
#define AT_deleted                    0x8a
#define AT_defaulted                  0x8b
#define AT_loclists_base              0x8c
#define AT_lo_user                    0x2000
#define AT_hi_user                    0x3fff




#define FORM_addr             0x01
#define FORM_block2           0x03
#define FORM_block4           0x04
#define FORM_data2            0x05
#define FORM_data4            0x06
#define FORM_data8            0x07
#define FORM_string           0x08
#define FORM_block            0x09
#define FORM_block1           0x0a
#define FORM_data1            0x0b
#define FORM_flag             0x0c
#define FORM_sdata            0x0d
#define FORM_strp             0x0e
#define FORM_udata            0x0f
#define FORM_ref_addr         0x10
#define FORM_ref1             0x11
#define FORM_ref2             0x12
#define FORM_ref4             0x13
#define FORM_ref8             0x14
#define FORM_ref_udata        0x15
#define FORM_indirect         0x16
#define FORM_sec_offset       0x17
#define FORM_exprloc          0x18
#define FORM_flag_present     0x19
#define FORM_strx             0x1a
#define FORM_addrx            0x1b
#define FORM_ref_sup4         0x1c
#define FORM_strp_sup         0x1d
#define FORM_data16           0x1e
#define FORM_line_strp        0x1f
#define FORM_ref_sig8         0x20
#define FORM_implicit_const   0x21
#define FORM_loclistx         0x22
#define FORM_rnglistx         0x23
#define FORM_ref_sup8         0x24
#define FORM_strx1            0x25
#define FORM_strx2            0x26
#define FORM_strx3            0x27
#define FORM_strx4            0x28
#define FORM_addrx1           0x29
#define FORM_addrx2           0x2a
#define FORM_addrx3           0x2b
#define FORM_addrx4           0x2c



#define UT_compile          0x01
#define UT_type             0x02
#define UT_partial          0x03
#define UT_skeleton         0x04
#define UT_split_compile    0x05
#define UT_split_type       0x06
#define UT_lo_user          0x80
#define UT_hi_user          0xff


#define __DERIVEC_DEBUG__

#ifdef __DERIVEC_DEBUG__
    //useful for debugging the library
    static const char* __derivec_tag_to_string__(uint64_t tag);
    static const char* __derivec_attribute_to_string__(uint64_t att);
    static const char* __derivec_form_to_string__(uint64_t form);
    static const char* __derivec_header_type_to_string__(uint64_t h);
    static void        __derivec_print_structs__();
    static void        __derivec_print_enums__();
    static void        __derivec_print_abbrevation_table__();
#endif // __DERIVEC_DEBUG__


typedef struct{
    uint32_t length;
    uint16_t version;
    uint8_t type;
    uint8_t addr_size;
    uint32_t abbrev_offset;
} __DwarfCUHeader__;


typedef struct{
   void* data;
   uint64_t size;
   uint64_t capacity;
} __Derivec_ArrayList__;


#define __derivec_array_list_create_cap__(list, type, cap) \
do { \
    list.size = 0; \
    list.capacity = cap; \
    list.data = malloc(sizeof(type) * list.capacity); \
    memset(list.data, 0, sizeof(type) * list.capacity); \
} while(0)


#define __derivec_array_list_reserve__(list, type, size) \
do { \
    if(size > list.capacity){\
        list.capacity = size; \
        list.data = realloc(list.data, sizeof(type) * list.capacity); \
    }\
} while(0)



#define __derivec_array_list_append__(list, type, value) \
    do { \
        if(list.size == list.capacity){ \
            list.capacity *= 2; \
            list.data = realloc(list.data, sizeof(type) * list.capacity); \
        } \
        type* temp = (type*)list.data; \
        temp[list.size] = value; \
        list.size++; \
    } while(0)

#define __derivec_array_list_get__(list, type, index)((type*)list.data)[index]

#define __derivec_array_list_delete__(list) \
    do { \
        if(list.data != NULL) {  \
            if(list.capacity != 0) free(list.data); \
        } \
    } while(0)




typedef struct {
    uint8_t ident[16];
    uint16_t file_type;
    uint16_t machine_type;
    uint32_t version;
    uint64_t entry;
    uint64_t program_header_offset;
    uint64_t section_header_offset;
    uint32_t flags;
    uint16_t header_size;
    uint16_t program_header_size;
    uint16_t program_header_entries;
    uint16_t section_header_size;
    uint16_t section_header_entries;
    uint16_t string_table_index;
} __Derivec_ElfHeader__;


typedef struct {
    uint32_t name;
    uint32_t type;
    uint64_t flags;
    uint64_t addr;
    uint64_t offset;
    uint64_t size;
    uint32_t link;
    uint32_t info;
    uint64_t addralign;
    uint64_t entsize;
} __Derivec_SectionHeader__;




//more of a resizable lookup table than an array list
static __Derivec_ArrayList__ abbreviations_table = {0};



typedef struct {
    uint64_t attribute;
    uint64_t form;
    int64_t implicit_const;
} __Derivec_AbbrevAttribute__;


typedef struct {
    uint64_t tag;
    uint8_t has_children;
    __Derivec_ArrayList__ attributes;
} __Derivec_AbbrevEntry__;




#define __DERIVEC_TYPE_BPTR__     0x01
#define __DERIVEC_TYPE_BOOL__     0x02
#define __DERIVEC_TYPE_FLOAT__    0x04
#define __DERIVEC_TYPE_SIGNED__   0x05
#define __DERIVEC_TYPE_SCHAR__    0x06
#define __DERIVEC_TYPE_UNSIGNED__ 0x07
#define __DERIVEC_TYPE_UCHAR__    0x08

#define __DERIVEC_TYPE_UINT8__    0x40
#define __DERIVEC_TYPE_UINT16__   0x41
#define __DERIVEC_TYPE_UINT32__   0x42
#define __DERIVEC_TYPE_UINT64__   0x43

#define __DERIVEC_TYPE_INT8__     0x44
#define __DERIVEC_TYPE_INT16__    0x45
#define __DERIVEC_TYPE_INT32__    0x46
#define __DERIVEC_TYPE_INT64__    0x47

#define __DERIVEC_TYPE_STRUCT__   0x50
#define __DERIVEC_TYPE_SPTR__     0x51
#define __DERIVEC_TYPE_ENUM__     0x52
#define __DERIVEC_TYPE_EPTR__     0x53

typedef struct{
    char* name;
    uint32_t offset;

    uint32_t type;
    union {
        uint32_t ptr_type;
        uint32_t struct_offset;
        uint32_t struct_index;
        uint32_t enum_index;
        uint32_t enum_offset;
    };
} __Derivec_StructMember__;


typedef struct {
    uint64_t offset;
    __Derivec_ArrayList__ names;
    __Derivec_ArrayList__ members;
} __Derivec_StructType__;


typedef struct{
    char* name;
    uint64_t value;
} __Derivec_EnumMember__;


typedef struct {
    uint64_t offset;
    char* name;
    __Derivec_ArrayList__ members;
} __Derivec_EnumType__;


static __Derivec_ArrayList__ structs = {0};
static __Derivec_ArrayList__ enums = {0};



typedef struct {
    uint64_t cu_offset;
    uint64_t debug_str_offset;
    uint64_t debug_line_str_offset;
} __Derivec_Offsets__;

static uint64_t __derivec_uleb128__(FILE *f) {
    uint64_t result = 0;
    int shift = 0;
    int byte;

    while (1) {
        byte = fgetc(f);
        if (byte == EOF) {
            fprintf(stderr, "Unexpected end of file while reading ULEB128: %lu\n", ftell(f));
            return 0;
        }

        result |= ((uint64_t)(byte & 0x7F)) << shift;

        if ((byte & 0x80) == 0)
            break;

        shift += 7;
        if (shift >= 64) {
            fprintf(stderr, "ULEB128 too large for 64-bit integer.\n");
            return 0;
        }
    }

    return result;
}


static int64_t __derivec_sleb128__(FILE* f) {
    int64_t value = 0;
    int shift = 0;
    int byte;
    const int size = 64; // Max bits for int64_t

    while (1) {
        byte = fgetc(f);
        if (byte == EOF) {
            fprintf(stderr, "Unexpected end of file while reading SLEB128: %lu\n", ftell(f));
            return 0;
        }


        value |= ((int64_t)(byte & 0x7F)) << shift;

        // Check if this is the last byte
        if ((byte & 0x80) == 0) {
            // Sign bit of byte is set
            if (shift < size && (byte & 0x40)) {
                value |= -((int64_t)1 << (shift + 7));
            }
            break;
        }

        shift += 7;

        if (shift >= size) {
            fprintf(stderr, "SLEB128 too large for 64-bit integer.\n");
            return 0;
        }
    }

    return value;
}


static bool __derivec_struct_names_eq__(__Derivec_ArrayList__* names, char* type){
    for(uint64_t i = 0; i < names->size; i++){
        char* type_name = __derivec_array_list_get__((*names), char*, i);
        if(strcmp(type_name, type) == 0) return true;
    }
    return false;
}


#define get_struct_member(type, base, offset) ((type)((uint8_t*)base + offset))


void __derivec_debug__(char* type, void* value, int indent){
    int start_indent = indent;
    bool found_struct = false;
    for(uint64_t i = 0; i < structs.size; i++){
        __Derivec_StructType__ st = __derivec_array_list_get__(structs, __Derivec_StructType__, i);
        if(__derivec_struct_names_eq__(&st.names, type)){
            found_struct = true;
            printf("%*s {\n", indent, type);
            indent += 4;
            for(uint64_t j = 0; j < st.members.size; j++){
                __Derivec_StructMember__ mem = __derivec_array_list_get__(st.members, __Derivec_StructMember__, j);
                printf("%*s%s: ", indent," ", mem.name);

                switch (mem.type) {
                    case __DERIVEC_TYPE_SPTR__:
                        printf("%p\n", *get_struct_member(uint64_t**, value, mem.offset));
                        break;
                    case __DERIVEC_TYPE_BPTR__:
                        if(*get_struct_member(char**, value, mem.offset) == NULL){
                            printf("NULL\n");
                        }
                        else if(mem.ptr_type == __DERIVEC_TYPE_SCHAR__ || mem.ptr_type == __DERIVEC_TYPE_UCHAR__){
                            printf("%s\n", *get_struct_member(char**, value, mem.offset));
                        } else{
                            printf("%p\n", get_struct_member(void*, value, mem.offset));
                        }
                        break;
                    case __DERIVEC_TYPE_BOOL__:
                        printf("%s\n", (*((bool*)value + mem.offset) == 1) ? "true" : "false");
                        break;
                    case __DERIVEC_TYPE_FLOAT__:
                        printf("%f\n", (double)*((uint8_t*)value + mem.offset));
                        break;
                    case 5:
                        printf("%ld\n", (int64_t)*((uint8_t*)value + mem.offset));
                        break;
                    case __DERIVEC_TYPE_SCHAR__:
                    case __DERIVEC_TYPE_UCHAR__:
                        printf("%c\n", (char)*((uint8_t*)value + mem.offset));
                        break;
                    case __DERIVEC_TYPE_UNSIGNED__:
                        printf("%lu\n", (uint64_t)*((uint8_t*)value + mem.offset));
                        break;
                    case __DERIVEC_TYPE_UINT8__:
                        printf("%u\n", *get_struct_member(uint8_t*, value, mem.offset));
                        break;
                    case __DERIVEC_TYPE_INT8__:
                        printf("%d\n", *get_struct_member(int8_t*, value, mem.offset));
                        break;
                    case __DERIVEC_TYPE_UINT16__:
                        printf("%u\n", *get_struct_member(uint16_t*, value, mem.offset));
                        break;
                    case __DERIVEC_TYPE_INT16__:
                        printf("%d\n", *get_struct_member(int16_t*, value, mem.offset));
                        break;
                    case __DERIVEC_TYPE_UINT32__:
                        printf("%u\n", *get_struct_member(uint32_t*, value, mem.offset));
                        break;
                    case __DERIVEC_TYPE_INT32__:
                        printf("%d\n", *get_struct_member(int32_t*, value, mem.offset));
                        break;
                    case __DERIVEC_TYPE_UINT64__:
                        printf("%lu\n", *get_struct_member(uint64_t*, value, mem.offset));
                        break;
                    case __DERIVEC_TYPE_INT64__:
                        printf("%ld\n", *get_struct_member(int64_t*, value, mem.offset));
                        break;
                    case __DERIVEC_TYPE_STRUCT__: {
                        __Derivec_StructType__* nested_struct =
                            &__derivec_array_list_get__(structs, __Derivec_StructType__, mem.struct_index);
                        char* name = __derivec_array_list_get__(nested_struct->names, char*, 0);
                        __derivec_debug__(name, ((uint8_t*)value + mem.offset), indent);
                        break;
                    }
                    case __DERIVEC_TYPE_ENUM__:
                        __Derivec_EnumType__* e = &__derivec_array_list_get__(enums, __Derivec_EnumType__, mem.enum_index);
                        bool found_enum = false;
                        uint64_t enum_value = (uint64_t)*((uint8_t*)value + mem.offset);
                        for(uint64_t k = 0; k < e->members.size; k++){
                            __Derivec_EnumMember__ emem = __derivec_array_list_get__(e->members, __Derivec_EnumMember__, k);
                            if(enum_value == emem.value){
                                printf("%s\n", emem.name);
                                found_enum = true;
                                break;
                            }
                        }
                        if(!found_enum){
                            printf("%ld\n", enum_value);
                        }
                        break;
                }
            }
            printf("%*s}\n", start_indent," ");
            break;
        }
    }
    if(!found_struct){
        printf("Couldn't find struct of type %s\n", type);

    }
}


#define derivec_debug(struct_type, ptr) __derivec_debug__(#struct_type, ptr, 0)

static void __derivec_add_abbreviation_entry__(uint64_t id, uint64_t tag, uint8_t has_children){
    __derivec_array_list_reserve__(abbreviations_table, __Derivec_AbbrevEntry__, id);
    __Derivec_AbbrevEntry__ e = {0};
    e.tag = tag;
    e.has_children = has_children;
    __derivec_array_list_create_cap__(e.attributes, __Derivec_AbbrevAttribute__, 4);
    ((__Derivec_AbbrevEntry__*)abbreviations_table.data)[id - 1] = e;
}


static void __derivec_add_attribute_entry__(uint64_t id, uint64_t attribute, uint64_t form, int64_t form2){
    __Derivec_AbbrevEntry__* abbrev_entry = &__derivec_array_list_get__(abbreviations_table, __Derivec_AbbrevEntry__, id - 1);
    __Derivec_AbbrevAttribute__ a = {0};
    a.attribute = attribute;
    a.form = form;
    a.implicit_const = form2;
    __derivec_array_list_append__(abbrev_entry->attributes, __Derivec_AbbrevAttribute__, a);
}



static void __derivec_create_table__(){
    if(abbreviations_table.data == 0){
        __derivec_array_list_create_cap__(abbreviations_table, __Derivec_AbbrevEntry__, 32);
    } else{
        for(uint64_t i = 0; i < abbreviations_table.size; i++){
            __Derivec_AbbrevEntry__* e = &__derivec_array_list_get__(abbreviations_table, __Derivec_AbbrevEntry__, i);
            e->attributes.size = 0;
            e->attributes.data = 0;
            e->attributes.capacity = 0;
            __derivec_array_list_delete__(e->attributes);
        }
        abbreviations_table.size = 0;
    }
}


static void __derivec_create_abbrevations_table__(uint64_t offset, FILE* f){
    fpos_t pos;
    fgetpos(f, &pos);
    fseek(f, offset, SEEK_SET);

    uint64_t abbrev_id = __derivec_uleb128__(f);
    while(1){
        uint64_t tag = __derivec_uleb128__(f);
        char has_children = fgetc(f);
        __derivec_add_abbreviation_entry__(abbrev_id, tag, has_children);
        while(1){
            uint64_t attribute = __derivec_uleb128__(f);
            if(attribute == 0){

                uint64_t form = __derivec_uleb128__(f);
                if(form != 0){
                    fprintf(stderr,"Error Form should be 0\n");
                }
                break;
            }
            uint64_t form = __derivec_uleb128__(f);
            if(form == FORM_implicit_const){
                uint64_t s = __derivec_sleb128__(f);
                __derivec_add_attribute_entry__(abbrev_id, attribute, form, s);

            } else{
                __derivec_add_attribute_entry__(abbrev_id, attribute, form, 0);
            }

        }
        abbrev_id = __derivec_uleb128__(f);
        if(abbrev_id == 0) break;
    }
    fsetpos(f, &pos);
}


static void __derivec_delete_abbrevations_table__(){
    for(uint64_t i = 0; i < abbreviations_table.capacity; i++){
        __Derivec_AbbrevEntry__ e = __derivec_array_list_get__(abbreviations_table, __Derivec_AbbrevEntry__, i);
        __derivec_array_list_delete__(e.attributes);
    }
    __derivec_array_list_delete__(abbreviations_table);
}

static char* __derivec_get_string__(FILE* f){
    fpos_t pos;
    fgetpos(f, &pos);

    size_t count = 0;
    while(1){
        char c = fgetc(f);
        count++;
        if(c == 0) break;
    }
    fsetpos(f, &pos);
    char* result = (char*)malloc(count);
    if(result == NULL) return NULL;

    for(int i = 0; i < count; i++){
        result[i] = fgetc(f);
    }
    return result;
}


static char* __derivec_get_string_table_value__(uint64_t string_table_offset, uint64_t offset_in_table, FILE* f){
    fpos_t pos;
    fgetpos(f, &pos);
    fseek(f, string_table_offset + offset_in_table, SEEK_SET);

    char* result = __derivec_get_string__(f);

    fsetpos(f, &pos);
    return result;
}

static char* __derivec_get_name__(FILE* f, __Derivec_Offsets__* offsets, uint64_t form){
    if(form == FORM_strp){
        uint32_t str_offset = 0;
        fread(&str_offset, sizeof(str_offset), 1, f);
        return __derivec_get_string_table_value__(offsets->debug_str_offset, str_offset, f);
    } else if (form == FORM_string) {
        return __derivec_get_string__(f);
    } else{
        fprintf(stderr, "Expected form strp or string for struct name\n");
        assert(false && "Not implemented");
    }
}


static void __derivec_skip_attribute__(FILE* f, uint64_t form){
    switch (form) {
        case FORM_ref_addr:
        case FORM_sec_offset:
        case FORM_line_strp:
        case FORM_data4:
        case FORM_ref4:
        case FORM_strp:
            fseek(f, 4, SEEK_CUR);
            break;
        case FORM_flag:
        case FORM_data1: {
            uint8_t data = 0;
            fread(&data, sizeof(data), 1, f);
            break;
        }
        case FORM_data8:
        case FORM_addr: {
            uint64_t data = 0;
            fread(&data, sizeof(data), 1, f);
            break;
        }
        case FORM_data2: {
            uint16_t data = 0;
            fread(&data, sizeof(data), 1, f);
            break;
        }
        case FORM_exprloc:{
            uint64_t expr_size = __derivec_uleb128__(f);
            //skip over the expression
            fseek(f, expr_size, SEEK_CUR);
            break;
        }
        case FORM_udata:
            __derivec_uleb128__(f);
            break;
        case FORM_sdata:
            __derivec_sleb128__(f);
            break;
        case FORM_flag_present:
        case FORM_implicit_const:
            break;
        case FORM_string: {
            while(1){
                char c = fgetc(f);
                if(c == 0) break;
            }
            break;
        }
        default:
            printf("Not implemented: %s\n", __derivec_form_to_string__(form));
            exit(1);
    }
}


static void __derivec_add_name_from_typedef__(FILE* f, __Derivec_Offsets__* offset, char* name, uint32_t type_offset){
    fpos_t pos;
    fgetpos(f, &pos);
    fseek(f, offset->cu_offset + type_offset, SEEK_SET);

    uint64_t id = __derivec_uleb128__(f);

    __Derivec_AbbrevEntry__ entry = __derivec_array_list_get__(abbreviations_table, __Derivec_AbbrevEntry__, id - 1);

    if(entry.tag == TAG_structure_type){
        for(uint64_t i = 0; i < structs.size; i++){
            __Derivec_StructType__* st = &__derivec_array_list_get__(structs, __Derivec_StructType__, i);
            if(st->offset == type_offset){
                __derivec_array_list_append__(st->names, char*, name);
                fsetpos(f, &pos);
                return;
            }
        }
        fprintf(stderr, "Could not find struct for typedef %s, 0x%x\n", name, type_offset);
    } else if (entry.tag == TAG_enumeration_type) {
        for(uint64_t i = 0; i < enums.size; i++){
            __Derivec_EnumType__* et = &__derivec_array_list_get__(enums, __Derivec_EnumType__, i);
            if(et->offset == type_offset && et->name == NULL){
                et->name = name;
                fsetpos(f, &pos);
                return;
            }
        }
        fprintf(stderr, "Could not find enum for typedef %s\n", name);
    } else if(entry.tag == TAG_union_type){
        fprintf(stderr, "Don't support typedefs for unions yet\n");
        assert(false);
    } else if (entry.tag == TAG_base_type) {
        free(name);
        fsetpos(f, &pos);
        return;
    }
    else{
        for(int i = 0; i < entry.attributes.size; i++){
            __Derivec_AbbrevAttribute__ abb = __derivec_array_list_get__(entry.attributes, __Derivec_AbbrevAttribute__, i);
            if(abb.attribute == AT_type){
                uint32_t new_type_offset = 0;
                assert(abb.form == FORM_ref4 && "Expected Form ref4\n");
                fread(&new_type_offset, sizeof(new_type_offset), 1, f);
                __derivec_add_name_from_typedef__(f, offset, name, new_type_offset);
                break;

            } else{
                __derivec_skip_attribute__(f, abb.form);
            }
        }
    }
    fsetpos(f, &pos);
}


static void __derivec_add_member_to_enum__(char* name, uint64_t value){
    __Derivec_EnumType__* et = &__derivec_array_list_get__(enums, __Derivec_EnumType__, enums.size - 1);
    __Derivec_EnumMember__ mem = {name, value};
    __derivec_array_list_append__(et->members, __Derivec_EnumMember__, mem);
}

static void __derivec_add_member_to_struct__(FILE* f, __Derivec_Offsets__* offset, char* name, uint32_t member_location,
        uint32_t member_type_offset){
    __Derivec_StructType__* st = &__derivec_array_list_get__(structs, __Derivec_StructType__, structs.size - 1);
    fpos_t pos;
    fgetpos(f, &pos);
    fseek(f, offset->cu_offset + member_type_offset, SEEK_SET);
    uint64_t id = __derivec_uleb128__(f);
    __Derivec_AbbrevEntry__ entry = __derivec_array_list_get__(abbreviations_table, __Derivec_AbbrevEntry__, id - 1);



    __Derivec_StructMember__ member = {0};
    member.name = name;
    member.offset = member_location;

    bool found_type = false;
    while(!found_type){
        if (entry.tag == TAG_structure_type) {
            member.type = (member.type == __DERIVEC_TYPE_BPTR__) ? __DERIVEC_TYPE_SPTR__ : __DERIVEC_TYPE_STRUCT__;
            // the struct may not be in our structs list yet
            // so we need to store the offset
            member.struct_offset = member_type_offset;
            break;
        } else if (entry.tag == TAG_enumeration_type) {
            member.type = (member.type == __DERIVEC_TYPE_BPTR__) ? __DERIVEC_TYPE_EPTR__ : __DERIVEC_TYPE_ENUM__;
            member.enum_offset = member_type_offset;
            break;
        }
        else if (entry.tag == TAG_union_type){
            //don't support unions yet
            fsetpos(f, &pos);
            free(name);
            return;
        }
        else{
            if(entry.tag == TAG_pointer_type){
                member.type =  __DERIVEC_TYPE_BPTR__;
            }

            bool next_type = false;
            int size = 0;
            for(int j = 0; j < entry.attributes.size; j++){
                __Derivec_AbbrevAttribute__ abb = __derivec_array_list_get__(entry.attributes, __Derivec_AbbrevAttribute__, j);
                if(abb.attribute == AT_name){
                    char* tmp_name = __derivec_get_name__(f, offset, abb.form);
                    // we need to distinguish between char and uint8_t for printing
                    // if the field was declared with type uint8_t/int8_t we print a number
                    // if it was declared with char we print a character
                    if(strcmp(tmp_name, "uint8_t") == 0){
                        if(member.type == __DERIVEC_TYPE_BPTR__){
                            member.ptr_type = __DERIVEC_TYPE_UINT8__;
                        } else{
                            member.type = __DERIVEC_TYPE_UINT8__;
                        }
                        found_type = true;
                    } else if (strcmp(tmp_name, "int8_t") == 0){ 
                        if(member.type == __DERIVEC_TYPE_BPTR__){
                            member.ptr_type = __DERIVEC_TYPE_INT8__;
                        } else{
                            member.type = __DERIVEC_TYPE_INT8__;
                        }
                        found_type = true;
                    }
                    free(tmp_name);
                }
                else if(abb.attribute == AT_encoding){
                    assert(abb.form == FORM_data1 && "Expected data1\n");
                    if(member.type == __DERIVEC_TYPE_BPTR__){
                        fread(&member.ptr_type, 1, 1, f);
                    } else{
                        fread(&member.type, 1, 1, f);
                    }
                    found_type = true;
                }else if(entry.tag == TAG_base_type && abb.attribute == AT_byte_size){
                    assert(abb.form == FORM_data1 && "Expected data1\n");
                    fread(&size, 1, 1, f);
                } 
                else if (abb.attribute == AT_type) {
                    assert(abb.form == FORM_ref4 && "Expected ref4\n");
                    fread(&member_type_offset, 4, 1, f);
                    fseek(f, offset->cu_offset + member_type_offset, SEEK_SET);
                    id = __derivec_uleb128__(f);
                    entry = __derivec_array_list_get__(abbreviations_table, __Derivec_AbbrevEntry__, id - 1);
                    next_type = true;
                    break;
                }
                else{
                    __derivec_skip_attribute__(f, abb.form);
                }
            }

            if(member.type == __DERIVEC_TYPE_UNSIGNED__){
                if(size == 1) member.type = __DERIVEC_TYPE_UINT8__;
                else if(size == 2) member.type = __DERIVEC_TYPE_UINT16__;
                else if(size == 4) member.type = __DERIVEC_TYPE_UINT32__;
                else if(size == 8) member.type = __DERIVEC_TYPE_UINT64__;
            } else if (member.type == __DERIVEC_TYPE_SIGNED__) {
                if(size == 1) member.type = __DERIVEC_TYPE_INT8__;
                else if(size == 2) member.type = __DERIVEC_TYPE_INT16__;
                else if(size == 4) member.type = __DERIVEC_TYPE_INT32__;
                else if(size == 8) member.type = __DERIVEC_TYPE_INT64__;
            }



            if(next_type) continue;
            break;
        }
    }

    fsetpos(f, &pos);

    __derivec_array_list_append__(st->members, __Derivec_StructMember__, member);
}


// Every struct that has a member of type struct or enum needs to have the offset
// replaced with an index into either the structs or enums list
static void __derivec_replace_struct_offset__(uint64_t struct_start, uint64_t enum_start){
    for(uint64_t i = struct_start; i < structs.size; i++) {
        __Derivec_StructType__* st = &__derivec_array_list_get__(structs, __Derivec_StructType__, i);
        for(uint64_t j = 0; j < st->members.size; j++){
            __Derivec_StructMember__* mem = &__derivec_array_list_get__(st->members, __Derivec_StructMember__, j);
            if(mem->type == __DERIVEC_TYPE_STRUCT__ || mem->type == __DERIVEC_TYPE_SPTR__){
                for(uint64_t k = struct_start; k < structs.size; k++) {
                    __Derivec_StructType__* new_st = &__derivec_array_list_get__(structs, __Derivec_StructType__, k);
                    if(new_st->offset == mem->struct_offset){
                        mem->struct_index = k;
                        break;
                    }
                }
            } else if (mem->type == __DERIVEC_TYPE_ENUM__ || mem->type == __DERIVEC_TYPE_EPTR__) {
                for(uint64_t k = enum_start; k < enums.size; k++) {
                    __Derivec_EnumType__* e = &__derivec_array_list_get__(enums, __Derivec_EnumType__, k);
                    if(e->offset == mem->struct_offset){
                        mem->enum_index = k;
                        break;
                    }
                }

            }
        }
    }
}

static void __derivec_get_type_information__(FILE* f, __Derivec_Offsets__* offsets, int depth){
    while(1){
        uint64_t offset = ftell(f);

        uint64_t id = __derivec_uleb128__(f);
        if(id == 0) return;

        __Derivec_AbbrevEntry__ entry = __derivec_array_list_get__(abbreviations_table, __Derivec_AbbrevEntry__, id - 1);


        if(entry.tag == TAG_structure_type){
            __Derivec_StructType__ t = {0};
            t.offset = offset - offsets->cu_offset;
            __derivec_array_list_create_cap__(t.names, char*, 1);
            __derivec_array_list_create_cap__(t.members, __Derivec_StructMember__, 2);
            __derivec_array_list_append__(structs, __Derivec_StructType__, t);
        } else if (entry.tag == TAG_enumeration_type) {
            __Derivec_EnumType__ t = {0};
            t.offset = offset - offsets->cu_offset;
            t.name = NULL;
            __derivec_array_list_create_cap__(t.members, __Derivec_EnumMember__, 2);
            __derivec_array_list_append__(enums, __Derivec_EnumType__, t);
        }


        char* name = NULL;
        uint32_t type_offset = 0;
        uint32_t member_location = 0;

        uint32_t struct_member_type_offset = 0;
        bool is_struct = false;

        uint64_t enum_value = 0;

        for(int j = 0; j < entry.attributes.size; j++){
            __Derivec_AbbrevAttribute__ abb = __derivec_array_list_get__(entry.attributes, __Derivec_AbbrevAttribute__, j);

            if(abb.attribute == AT_name){
                switch (entry.tag) {
                    case TAG_structure_type: {
                        __Derivec_StructType__ * st = &__derivec_array_list_get__(structs, __Derivec_StructType__,structs.size - 1);
                        char* name = __derivec_get_name__(f, offsets, abb.form);
                        __derivec_array_list_append__(st->names, char*, name);
                        break;
                    }
                    case TAG_enumeration_type: {
                        __Derivec_EnumType__* et = &__derivec_array_list_get__(enums, __Derivec_EnumType__,enums.size - 1);
                        et->name = __derivec_get_name__(f, offsets, abb.form);
                        break;
                    }
                    case TAG_typedef:
                    case TAG_member:
                    case TAG_enumerator:
                        name = __derivec_get_name__(f, offsets, abb.form);
                        break;
                    default:
                        __derivec_skip_attribute__(f, abb.form);
                }

            } else if (abb.attribute == AT_type) {
                if(entry.tag == TAG_typedef){
                    assert(abb.form == FORM_ref4 && "Expected Form ref4\n");
                    fread(&type_offset, sizeof(type_offset), 1, f);
                } else if (entry.tag == TAG_member){
                    assert(abb.form == FORM_ref4 && "Expected Form ref4\n");
                    fread(&struct_member_type_offset, sizeof(struct_member_type_offset), 1, f);
                } else{
                    __derivec_skip_attribute__(f, abb.form);
                }

            } else if (abb.attribute == AT_data_member_location && entry.tag == TAG_member) {
                is_struct = true;
                assert(abb.form == FORM_data1 && "Expected data1\n");
                fread(&member_location, 1, 1, f);

            } else if (abb.attribute == AT_const_value && entry.tag == TAG_enumerator) {
                if(abb.form == FORM_data1) fread(&enum_value, 1, 1, f);
                else if(abb.form == FORM_data2) fread(&enum_value, 2, 1, f);
                else if(abb.form == FORM_data4) fread(&enum_value, 4, 1, f);
                else if(abb.form == FORM_data8) fread(&enum_value, 8, 1, f);
                else if (abb.form == FORM_udata) enum_value = __derivec_uleb128__(f);
                else if (abb.form == FORM_sdata) enum_value = __derivec_sleb128__(f);
                else{
                    fprintf(stderr, "INVALID form for enum member: %s", __derivec_form_to_string__(abb.form));
                    assert(false && "Not implemented");
                }
            } else{
                __derivec_skip_attribute__(f, abb.form);
            }
        }

        if(entry.tag == TAG_typedef){
            //don't support unions yet
            if(type_offset == 0){
                free(name);
            } else{
                __derivec_add_name_from_typedef__(f, offsets, name, type_offset);
            }
        } else if (entry.tag == TAG_member){
            if(is_struct){
                __derivec_add_member_to_struct__(f, offsets, name, member_location,
                    struct_member_type_offset);
            }else{
                //free union members
                free(name);
            }
        } else if (entry.tag == TAG_enumerator) {
            __derivec_add_member_to_enum__(name, enum_value);
        }

        if(entry.has_children){
            __derivec_get_type_information__(f, offsets, depth + 1);
        }

        //root doesn't have siblings
        if(depth == 0) break;
    }

}




static bool __derivec_strtable_streq__(FILE* f, __Derivec_SectionHeader__* string_table, uint32_t name, const char* string){
    fpos_t pos;
    fgetpos(f, &pos);
    fseek(f, string_table->offset + name,SEEK_SET);
    int i = 0;
    char c1,c2;
    while(1){
        c1 = fgetc(f);
        c2 = string[i++];

        if(c1 != c2){
            fsetpos(f, &pos);
            return false;
        }

        if(c1 == 0 || c2 == 0) break;
    }
    fsetpos(f,&pos);
    return c1 == c2;
}


bool derivec_init(const char* file_name){
    FILE* f = fopen(file_name, "rb");
    if(f == NULL){
        fprintf(stderr, "Failed to open %s\n", file_name);
        return false;
    }



    __Derivec_ElfHeader__ h = {0};
    fread(&h, sizeof(h), 1, f);

    //read section header table
    fseek(f, h.section_header_offset, SEEK_SET);

    __Derivec_SectionHeader__ st = {0};
    fseek(f, h.section_header_offset + h.section_header_size * h.string_table_index, SEEK_SET);
    fread(&st, sizeof(st), 1, f);

    fseek(f, h.section_header_offset, SEEK_SET);

    //get the abbrevation & debug string table
    __Derivec_SectionHeader__ debug_abbrev = {0};
    __Derivec_SectionHeader__ debug_str = {0};
    __Derivec_SectionHeader__ debug_line_str = {0};
    __Derivec_SectionHeader__ debug_info = {0};

    bool found_debug = false;
    for(int i = 0; i < h.section_header_entries; i++){
        __Derivec_SectionHeader__ temp = {0};
        fread(&temp, sizeof(temp), 1, f);
        if(__derivec_strtable_streq__(f, &st, temp.name, ".debug_abbrev")){
            memcpy(&debug_abbrev, &temp, sizeof(__Derivec_SectionHeader__));
        }
        else if(__derivec_strtable_streq__(f, &st, temp.name, ".debug_str")){
            memcpy(&debug_str, &temp, sizeof(__Derivec_SectionHeader__));
        }else if(__derivec_strtable_streq__(f, &st, temp.name,".debug_line_str")){
            memcpy(&debug_line_str, &temp, sizeof(__Derivec_SectionHeader__));
        } else if(__derivec_strtable_streq__(f, &st, temp.name,".debug_info")){
            memcpy(&debug_info, &temp, sizeof(__Derivec_SectionHeader__));
            found_debug = true;
        }

    }

    if(!found_debug){
        fprintf(stderr, "Failed to find debug info\n");
        fclose(f);
        return false;
    }



    __derivec_array_list_create_cap__(structs,__Derivec_StructType__, 8);
    __derivec_array_list_create_cap__(enums,__Derivec_EnumType__, 8);

    uint64_t struct_start = 0;
    uint64_t enum_start = 0;

    fseek(f, debug_info.offset, SEEK_SET);
    uint64_t start = debug_info.offset;

    __Derivec_Offsets__ offsets = {0};
    offsets.debug_line_str_offset = debug_line_str.offset;
    offsets.debug_str_offset = debug_str.offset;

    while(ftell(f) - start < debug_info.size){
        __DwarfCUHeader__ ch = {0};
        offsets.cu_offset = ftell(f);
        fread(&ch, sizeof(__DwarfCUHeader__), 1, f);

        if(ch.version != 5){
            fprintf(stderr, "Only Dwarf Version 5 is supported\n");
            fclose(f);
            return false;
        }
        switch(ch.type){
            case UT_compile:
            case UT_partial: {
                __derivec_create_abbrevations_table__(debug_abbrev.offset + ch.abbrev_offset, f);
                __derivec_get_type_information__(f, &offsets, 0);
                __derivec_replace_struct_offset__(struct_start, enum_start);
                struct_start = structs.size;
                enum_start = enums.size;
                break;
            }

            case UT_skeleton:
            case UT_split_compile: {
                uint64_t id = 0;
                fread(&id, sizeof(id), 1, f);
                assert(false && "Error this has not been tested\n");
                break;
            }
            case UT_type:
            case UT_split_type: {
                uint32_t toff = 0;
                uint64_t signature = 0;
                fread(&toff, sizeof(toff), 1, f);
                fread(&signature, sizeof(signature), 1, f);
                assert(false && "Error this has not been tested\n");
                break;
            }
        }
    }
    __derivec_delete_abbrevations_table__();
    fclose(f);
    return true;
}

void derivec_terminate(){
    for(uint64_t i = 0; i < structs.size; i++){
        __Derivec_StructType__ t = __derivec_array_list_get__(structs, __Derivec_StructType__, i);
        for(uint64_t j = 0; j < t.names.size; j++){
            free(__derivec_array_list_get__(t.names, char*, j));
        }
        for(uint64_t j = 0; j < t.members.size; j++){
            free(__derivec_array_list_get__(t.members, __Derivec_StructMember__, j).name);
        }

        __derivec_array_list_delete__(t.names);
        __derivec_array_list_delete__(t.members);
    }
    __derivec_array_list_delete__(structs);


    for(uint64_t i = 0; i < enums.size; i++){
        __Derivec_EnumType__ t = __derivec_array_list_get__(enums, __Derivec_EnumType__, i);
        free(t.name);
        for(uint64_t j = 0; j < t.members.size; j++){
            free(__derivec_array_list_get__(t.members, __Derivec_EnumMember__, j).name);
        }
        __derivec_array_list_delete__(t.members);
    }
    __derivec_array_list_delete__(enums);
}




#ifdef __DERIVEC_DEBUG__
static void print_abbrevation_table(){
    for(int i = 0; i < abbreviations_table.size; i++){
        __Derivec_AbbrevEntry__ e = __derivec_array_list_get__(abbreviations_table, __Derivec_AbbrevEntry__, i);
        printf("Id: %d\n", i + 1);
        printf("Tag: %s\n", __derivec_tag_to_string__(e.tag));
        printf("Has Children: %d\n", e.has_children);

        for(int j = 0; j < e.attributes.size; j++){
            __Derivec_AbbrevAttribute__ abb = __derivec_array_list_get__(e.attributes, __Derivec_AbbrevAttribute__, j);
            if(abb.form == FORM_implicit_const){
                printf("%s -> %s, %ld\n", __derivec_attribute_to_string__(abb.attribute),
                        __derivec_form_to_string__(abb.form), abb.implicit_const);
            } else{
                printf("%s -> %s\n", __derivec_attribute_to_string__(abb.attribute),
                        __derivec_form_to_string__(abb.form));
            }
        }
    }
}

static void __derivec_print_structs__(){
    for(uint64_t i = 0; i < structs.size; i++){
        __Derivec_StructType__ t = __derivec_array_list_get__(structs, __Derivec_StructType__, i);
        printf("Offset: 0x%lx, %s: \n", t.offset, __derivec_array_list_get__(t.names, char*, 0));
        for(uint64_t j = 0; j < t.members.size; j++){
            __Derivec_StructMember__ mem = __derivec_array_list_get__(t.members, __Derivec_StructMember__, j);
            printf("%d -> %s: %d\n", mem.offset, mem.name, mem.type);
        }
    }
}


static void __derivec_print_enums__(){
    for(uint64_t i = 0; i < enums.size; i++){
        __Derivec_EnumType__ t = __derivec_array_list_get__(enums, __Derivec_EnumType__, i);
        printf("%s: \n", t.name);
        for(uint64_t j = 0; j < t.members.size; j++){
            __Derivec_EnumMember__ mem = __derivec_array_list_get__(t.members, __Derivec_EnumMember__, j);
            printf("%s: %lu\n", mem.name, mem.value);
        }
    }
}

static const char* __derivec_header_type_to_string__(uint64_t t){
    switch (t) {
        case UT_compile:
            return "compile";
        case UT_type:
            return "type";
        case UT_partial:
            return "partial";
        case UT_skeleton:
            return "skeleton";
        case UT_split_compile:
            return "split_compile";
        case UT_split_type:
            return "split_type";
        case UT_lo_user:
            return "lo_user";
        case UT_hi_user:
            return "hi_user";
    }
    return "INVALID";
}

static const char* __derivec_tag_to_string__(uint64_t tag){
    switch (tag) {
        case TAG_array_type:
            return "array_type";
        case TAG_class_type:
            return "class_type";
        case TAG_entry_point:
            return "entry_point";
        case TAG_enumeration_type:
            return "enumeration_type";
        case TAG_formal_parameter:
            return "formal_parameter";
        case TAG_imported_declaration:
            return "imported_declaration";
        case TAG_label:
            return "label";
        case TAG_lexical_block:
            return "lexical_block";
        case TAG_member:
            return "member";
        case TAG_pointer_type:
            return "pointer_type";
        case TAG_reference_type:
            return "reference_type";
        case TAG_compile_unit:
            return "compile_unit";
        case TAG_string_type:
            return "string_type";
        case TAG_structure_type:
            return "structure_type";
        case TAG_subroutine_type:
            return "subroutine_type";
        case TAG_typedef:
            return "typedef";
        case TAG_union_type:
            return "union_type";
        case TAG_unspecified_parameters:
            return "unspecified_parameters";
        case TAG_variant:
            return "variant";
        case TAG_common_block:
            return "common_block";
        case TAG_common_inclusion:
            return "common_inclusion";
        case TAG_inheritance:
            return "inheritance";
        case TAG_inlined_subroutine:
            return "inlined_subroutine";
        case TAG_module:
            return "module";
        case TAG_ptr_to_member_type:
            return "ptr_to_member_type";
        case TAG_set_type:
            return "set_type";
        case TAG_subrange_type:
            return "subrange_type";
        case TAG_with_stmt:
            return "with_stmt";
        case TAG_access_declaration:
            return "access_declaration";
        case TAG_base_type:
            return "base_type";
        case TAG_catch_block:
            return "catch_block";
        case TAG_const_type:
            return "const_type";
        case TAG_constant:
            return "constant";
        case TAG_enumerator:
            return "enumerator";
        case TAG_file_type:
            return "file_type";
        case TAG_friend:
            return "friend";
        case TAG_namelist:
            return "namelist";
        case TAG_namelist_item:
            return "namelist_item";
        case TAG_packed_type:
            return "packed_type";
        case TAG_subprogram:
            return "subprogram";
        case TAG_template_type_parameter:
            return "template_type_parameter";
        case TAG_template_value_parameter:
            return "template_value_parameter";
        case TAG_thrown_type:
            return "thrown_type";
        case TAG_try_block:
            return "try_block";
        case TAG_variant_part:
            return "variant_part";
        case TAG_variable:
            return "variable";
        case TAG_volatile_type:
            return "volatile_type";
        case TAG_dwarf_procedure:
            return "dwarf_procedure";
        case TAG_restrict_type:
            return "restrict_type";
        case TAG_interface_type:
            return "interface_type";
        case TAG_namespace:
            return "namespace";
        case TAG_imported_module:
            return "imported_module";
        case TAG_unspecified_type:
            return "unspecified_type";
        case TAG_partial_unit:
            return "partial_unit";
        case TAG_imported_unit:
            return "imported_unit";
        case TAG_condition:
            return "condition";
        case TAG_shared_type:
            return "shared_type";
        case TAG_type_unit:
            return "type_unit";
        case TAG_rvalue_reference_type:
            return "rvalue_reference_type";
        case TAG_template_alias:
            return "template_alias";
        case TAG_coarray_type:
            return "coarray_type";
        case TAG_generic_subrange:
            return "generic_subrange";
        case TAG_dynamic_type:
            return "dynamic_type";
        case TAG_atomic_type:
            return "atomic_type";
        case TAG_call_site:
            return "call_site";
        case TAG_call_site_parameter:
            return "call_site_parameter";
        case TAG_skeleton_unit:
            return "skeleton_unit";
        case TAG_immutable_type:
            return "immutable_type";
        case TAG_lo_user:
            return "lo_user";
        case TAG_hi_user:
            return "hi_user";
    }
    return "NULL";
}


static const char* __derivec_attribute_to_string__(uint64_t t){
    switch (t) {
        case AT_sibling:
            return "AT_sibling";
        case AT_location:
            return "AT_location";
        case AT_name:
            return "AT_name";
        case AT_ordering:
            return "AT_ordering";
        case AT_byte_size:
            return "AT_byte_size";
        case AT_bit_size:
            return "AT_bit_size";
        case AT_stmt_list:
            return "AT_stmt_list";
        case AT_low_pc:
            return "AT_low_pc";
        case AT_high_pc:
            return "AT_high_pc";
        case AT_language:
            return "AT_language";
        case AT_discr:
            return "AT_discr";
        case AT_discr_value:
            return "AT_discr_value";
        case AT_visibility:
            return "AT_visibility";
        case AT_import:
            return "AT_import";
        case AT_string_length:
            return "AT_string_length";
        case AT_common_reference:
            return "AT_common_reference";
        case AT_comp_dir:
            return "AT_comp_dir";
        case AT_const_value:
            return "AT_const_value";
        case AT_containing_type:
            return "AT_containing_type";
        case AT_default_value:
            return "AT_default_value";
        case AT_inline:
            return "AT_inline";
        case AT_is_optional:
            return "AT_is_optional";
        case AT_lower_bound:
            return "AT_lower_bound";
        case AT_producer:
            return "AT_producer";
        case AT_prototyped:
            return "AT_prototyped";
        case AT_return_addr:
            return "AT_return_addr";
        case AT_start_scope:
            return "AT_start_scope";
        case AT_bit_stride:
            return "AT_bit_stride";
        case AT_upper_bound:
            return "AT_upper_bound";
        case AT_abstract_origin:
            return "AT_abstract_origin";
        case AT_accessibility:
            return "AT_accessibility";
        case AT_address_class:
            return "AT_address_class";
        case AT_artificial:
            return "AT_artificial";
        case AT_base_types:
            return "AT_base_types";
        case AT_calling_convention:
            return "AT_calling_convention";
        case AT_count:
            return "AT_count";
        case AT_data_member_location:
            return "AT_data_member_location";
        case AT_decl_column:
            return "AT_decl_column";
        case AT_decl_file:
            return "AT_decl_file";
        case AT_decl_line:
            return "AT_decl_line";
        case AT_declaration:
            return "AT_declaration";
        case AT_discr_list:
            return "AT_discr_list";
        case AT_encoding:
            return "AT_encoding";
        case AT_external:
            return "AT_external";
        case AT_frame_base:
            return "AT_frame_base";
        case AT_friend:
            return "AT_friend";
        case AT_identifier_case:
            return "AT_identifier_case";
        case AT_namelist_item:
            return "AT_namelist_item";
        case AT_priority:
            return "AT_priority";
        case AT_segment:
            return "AT_segment";
        case AT_specification:
            return "AT_specification";
        case AT_static_link:
            return "AT_static_link";
        case AT_type:
            return "AT_type";
        case AT_use_location:
            return "AT_use_location";
        case AT_variable_parameter:
            return "AT_variable_parameter";
        case AT_virtuality:
            return "AT_virtuality";
        case AT_vtable_elem_location:
            return "AT_vtable_elem_location";
        case AT_allocated:
            return "AT_allocated";
        case AT_associated:
            return "AT_associated";
        case AT_data_location:
            return "AT_data_location";
        case AT_byte_stride:
            return "AT_byte_stride";
        case AT_entry_pc:
            return "AT_entry_pc";
        case AT_use_UTF:
            return "AT_use_UTF";
        case AT_extension:
            return "AT_extension";
        case AT_ranges:
            return "AT_ranges";
        case AT_trampoline:
            return "AT_trampoline";
        case AT_call_column:
            return "AT_call_column";
        case AT_call_file:
            return "AT_call_file";
        case AT_call_line:
            return "AT_call_line";
        case AT_description:
            return "AT_description";
        case AT_binary_scale:
            return "AT_binary_scale";
        case AT_decimal_scale:
            return "AT_decimal_scale";
        case AT_small:
            return "AT_small";
        case AT_decimal_sign:
            return "AT_decimal_sign";
        case AT_digit_count:
            return "AT_digit_count";
        case AT_picture_string:
            return "AT_picture_string";
        case AT_mutable:
            return "AT_mutable";
        case AT_threads_scaled:
            return "AT_threads_scaled";
        case AT_explicit:
            return "AT_explicit";
        case AT_object_pointer:
            return "AT_object_pointer";
        case AT_endianity:
            return "AT_endianity";
        case AT_elemental:
            return "AT_elemental";
        case AT_pure:
            return "AT_pure";
        case AT_recursive:
            return "AT_recursive";
        case AT_signature:
            return "AT_signature";
        case AT_main_subprogram:
            return "AT_main_subprogram";
        case AT_data_bit_offset:
            return "AT_data_bit_offset";
        case AT_const_expr:
            return "AT_const_expr";
        case AT_enum_class:
            return "AT_enum_class";
        case AT_linkage_name:
            return "AT_linkage_name";
        case AT_string_length_bit_size:
            return "AT_string_length_bit_size";
        case AT_string_length_byte_size:
            return "AT_string_length_byte_size";
        case AT_rank:
            return "AT_rank";
        case AT_str_offsets_base:
            return "AT_str_offsets_base";
        case AT_addr_base:
            return "AT_addr_base";
        case AT_rnglists_base:
            return "AT_rnglists_base";
        case AT_dwo_name:
            return "AT_dwo_name";
        case AT_reference:
            return "AT_reference";
        case AT_rvalue_reference:
            return "AT_rvalue_reference";
        case AT_macros:
            return "AT_macros";
        case AT_call_all_calls:
            return "AT_call_all_calls";
        case AT_call_all_source_calls:
            return "AT_call_all_source_calls";
        case AT_call_all_tail_calls:
            return "AT_call_all_tail_calls";
        case AT_call_return_pc:
            return "AT_call_return_pc";
        case AT_call_value:
            return "AT_call_value";
        case AT_call_origin:
            return "AT_call_origin";
        case AT_call_parameter:
            return "AT_call_parameter";
        case AT_call_pc:
            return "AT_call_pc";
        case AT_call_tail_call:
            return "AT_call_tail_call";
        case AT_call_target:
            return "AT_call_target";
        case AT_call_target_clobbered:
            return "AT_call_target_clobbered";
        case AT_call_data_location:
            return "AT_call_data_location";
        case AT_call_data_value:
            return "AT_call_data_value";
        case AT_noreturn:
            return "AT_noreturn";
        case AT_alignment:
            return "AT_alignment";
        case AT_export_symbols:
            return "AT_export_symbols";
        case AT_deleted:
            return "AT_deleted";
        case AT_defaulted:
            return "AT_defaulted";
        case AT_loclists_base:
            return "AT_loclists_base";
        case AT_lo_user:
            return "AT_lo_user";
        case AT_hi_user:
            return "AT_hi_user";
    }
    return "INVALID";
}


static const char* __derivec_form_to_string__(uint64_t t){
    switch (t) {
        case FORM_addr:
            return "FORM_addr";
        case FORM_block2:
            return "FORM_block2";
        case FORM_block4:
            return "FORM_block4";
        case FORM_data2:
            return "FORM_data2";
        case FORM_data4:
            return "FORM_data4";
        case FORM_data8:
            return "FORM_data8";
        case FORM_string:
            return "FORM_string";
        case FORM_block:
            return "FORM_block";
        case FORM_block1:
            return "FORM_block1";
        case FORM_data1:
            return "FORM_data1";
        case FORM_flag:
            return "FORM_flag";
        case FORM_sdata:
            return "FORM_sdata";
        case FORM_strp:
            return "FORM_strp";
        case FORM_udata:
            return "FORM_udata";
        case FORM_ref_addr:
            return "FORM_ref_addr";
        case FORM_ref1:
            return "FORM_ref1";
        case FORM_ref2:
            return "FORM_ref2";
        case FORM_ref4:
            return "FORM_ref4";
        case FORM_ref8:
            return "FORM_ref8";
        case FORM_ref_udata:
            return "FORM_ref_udata";
        case FORM_indirect:
            return "FORM_indirect";
        case FORM_sec_offset:
            return "FORM_sec_offset";
        case FORM_exprloc:
            return "FORM_exprloc";
        case FORM_flag_present:
            return "FORM_flag_present";
        case FORM_strx:
            return "FORM_strx";
        case FORM_addrx :
            return "FORM_addrx ";
        case FORM_ref_sup4:
            return "FORM_ref_sup4";
        case FORM_strp_sup:
            return "FORM_strp_sup";
        case FORM_data16:
            return "FORM_data16";
        case FORM_line_strp:
            return "FORM_line_strp";
        case FORM_ref_sig8:
            return "FORM_ref_sig8";
        case FORM_implicit_const:
            return "FORM_implicit_const";
        case FORM_loclistx:
            return "FORM_loclistx";
        case FORM_rnglistx:
            return "FORM_rnglistx";
        case FORM_ref_sup8:
            return "FORM_ref_sup8";
        case FORM_strx1:
            return "FORM_strx1";
        case FORM_strx2:
            return "FORM_strx2";
        case FORM_strx3:
            return "FORM_strx3";
        case FORM_strx4:
            return "FORM_strx4";
        case FORM_addrx1:
            return "FORM_addrx1";
        case FORM_addrx2:
            return "FORM_addrx2";
        case FORM_addrx3:
            return "FORM_addrx3";
        case FORM_addrx4:
            return "FORM_addrx4";
    }
    return "Null";
}

#endif //__DERIVEC_DEBUG__

#undef TAG_array_type
#undef TAG_class_type
#undef TAG_entry_point
#undef TAG_enumeration_type
#undef TAG_formal_parameter
#undef TAG_imported_declaration
#undef TAG_label
#undef TAG_lexical_block
#undef TAG_member
#undef TAG_pointer_type
#undef TAG_reference_type
#undef TAG_compile_unit
#undef TAG_string_type
#undef TAG_structure_type
#undef TAG_subroutine_type
#undef TAG_typedef
#undef TAG_union_type
#undef TAG_unspecified_parameters
#undef TAG_variant
#undef TAG_common_block
#undef TAG_common_inclusion
#undef TAG_inheritance
#undef TAG_inlined_subroutine
#undef TAG_module
#undef TAG_ptr_to_member_type
#undef TAG_set_type
#undef TAG_subrange_type
#undef TAG_with_stmt
#undef TAG_access_declaration
#undef TAG_base_type
#undef TAG_catch_block
#undef TAG_const_type
#undef TAG_constant
#undef TAG_enumerator
#undef TAG_file_type
#undef TAG_friend
#undef TAG_namelist
#undef TAG_namelist_item
#undef TAG_packed_type
#undef TAG_subprogram
#undef TAG_template_type_parameter
#undef TAG_template_value_parameter
#undef TAG_thrown_type
#undef TAG_try_block
#undef TAG_variant_part
#undef TAG_variable
#undef TAG_volatile_type
#undef TAG_dwarf_procedure
#undef TAG_restrict_type
#undef TAG_interface_type
#undef TAG_namespace
#undef TAG_imported_module
#undef TAG_unspecified_type
#undef TAG_partial_unit
#undef TAG_imported_unit
#undef TAG_condition
#undef TAG_shared_type
#undef TAG_type_unit
#undef TAG_rvalue_reference_type
#undef TAG_template_alias
#undef TAG_coarray_type
#undef TAG_generic_subrange
#undef TAG_dynamic_type
#undef TAG_atomic_type
#undef TAG_call_site
#undef TAG_call_site_parameter
#undef TAG_skeleton_unit
#undef TAG_immutable_type
#undef TAG_lo_user
#undef TAG_hi_user
#undef AT_sibling
#undef AT_location
#undef AT_name
#undef AT_ordering
#undef AT_byte_size
#undef AT_bit_size
#undef AT_stmt_list
#undef AT_low_pc
#undef AT_high_pc
#undef AT_language
#undef AT_discr
#undef AT_discr_value
#undef AT_visibility
#undef AT_import
#undef AT_string_length
#undef AT_common_reference
#undef AT_comp_dir
#undef AT_const_value
#undef AT_containing_type
#undef AT_default_value
#undef AT_inline
#undef AT_is_optional
#undef AT_lower_bound
#undef AT_producer
#undef AT_prototyped
#undef AT_return_addr
#undef AT_start_scope
#undef AT_bit_stride
#undef AT_upper_bound
#undef AT_abstract_origin
#undef AT_accessibility
#undef AT_address_class
#undef AT_artificial
#undef AT_base_types
#undef AT_calling_convention
#undef AT_count
#undef AT_data_member_location
#undef AT_decl_column
#undef AT_decl_file
#undef AT_decl_line
#undef AT_declaration
#undef AT_discr_list
#undef AT_encoding
#undef AT_external
#undef AT_frame_base
#undef AT_friend
#undef AT_identifier_case
#undef AT_namelist_item
#undef AT_priority
#undef AT_segment
#undef AT_specification
#undef AT_static_link
#undef AT_type
#undef AT_use_location
#undef AT_variable_parameter
#undef AT_virtuality
#undef AT_vtable_elem_location
#undef AT_allocated
#undef AT_associated
#undef AT_data_location
#undef AT_byte_stride
#undef AT_entry_pc
#undef AT_use_UTF
#undef AT_extension
#undef AT_ranges
#undef AT_trampoline
#undef AT_call_column
#undef AT_call_file
#undef AT_call_line
#undef AT_description
#undef AT_binary_scale
#undef AT_decimal_scale
#undef AT_small
#undef AT_decimal_sign
#undef AT_digit_count
#undef AT_picture_string
#undef AT_mutable
#undef AT_threads_scaled
#undef AT_explicit
#undef AT_object_pointer
#undef AT_endianity
#undef AT_elemental
#undef AT_pure
#undef AT_recursive
#undef AT_signature
#undef AT_main_subprogram
#undef AT_data_bit_offset
#undef AT_const_expr
#undef AT_enum_class
#undef AT_linkage_name
#undef AT_string_length_bit_size
#undef AT_string_length_byte_size
#undef AT_rank
#undef AT_str_offsets_base
#undef AT_addr_base
#undef AT_rnglists_base
#undef AT_dwo_name
#undef AT_reference
#undef AT_rvalue_reference
#undef AT_macros
#undef AT_call_all_calls
#undef AT_call_all_source_calls
#undef AT_call_all_tail_calls
#undef AT_call_return_pc
#undef AT_call_value
#undef AT_call_origin
#undef AT_call_parameter
#undef AT_call_pc
#undef AT_call_tail_call
#undef AT_call_target
#undef AT_call_target_clobbered
#undef AT_call_data_location
#undef AT_call_data_value
#undef AT_noreturn
#undef AT_alignment
#undef AT_export_symbols
#undef AT_deleted
#undef AT_defaulted
#undef AT_loclists_base
#undef AT_lo_user
#undef AT_hi_user
#undef FORM_addr
#undef FORM_block2
#undef FORM_block4
#undef FORM_data2
#undef FORM_data4
#undef FORM_data8
#undef FORM_string
#undef FORM_block
#undef FORM_block1
#undef FORM_data1
#undef FORM_flag
#undef FORM_sdata
#undef FORM_strp
#undef FORM_udata
#undef FORM_ref_addr
#undef FORM_ref1
#undef FORM_ref2
#undef FORM_ref4
#undef FORM_ref8
#undef FORM_ref_udata
#undef FORM_indirect
#undef FORM_sec_offset
#undef FORM_exprloc
#undef FORM_flag_present
#undef FORM_strx
#undef FORM_addrx
#undef FORM_ref_sup4
#undef FORM_strp_sup
#undef FORM_data16
#undef FORM_line_strp
#undef FORM_ref_sig8
#undef FORM_implicit_const
#undef FORM_loclistx
#undef FORM_rnglistx
#undef FORM_ref_sup8
#undef FORM_strx1
#undef FORM_strx2
#undef FORM_strx3
#undef FORM_strx4
#undef FORM_addrx1
#undef FORM_addrx2
#undef FORM_addrx3
#undef FORM_addrx4
#undef UT_compile
#undef UT_type
#undef UT_partial
#undef UT_skeleton
#undef UT_split_compile
#undef UT_split_type
#undef UT_lo_user
#undef UT_hi_user
#endif // DERIVEC_IMPLEMENTATION
