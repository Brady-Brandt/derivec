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



const char* tag_to_string(uint64_t tag);
const char* attribute_to_string(uint64_t att);
const char* form_to_string(uint64_t form);
const char* header_type_to_string(uint64_t h);


typedef struct{
    uint32_t length;
    uint16_t version;
    uint8_t type;
    uint8_t addr_size;
    uint32_t abbrev_offset;
} __attribute__((packed))Dwarf5Header;


typedef struct {
    uint64_t id;
} Dwarf5SkelHeader;


typedef struct {
    uint64_t signature;
    uint32_t type_offset;
} Dwarf5TypeHeader;


typedef struct{
   void* data;
   uint64_t size;
   uint64_t capacity;
} ArrayList;


#define array_list_create_cap(list, type, cap) \
do { \
    list.size = 0; \
    list.capacity = cap; \
    list.data = malloc(sizeof(type) * list.capacity); \
    memset(list.data, 0, sizeof(type) * list.capacity); \
} while(0) 


#define array_list_resize(list, type) \
do { \
    list.capacity *= 2; \
    list.data = realloc(list.data, sizeof(type) * list.capacity); \
} while(0) 


#define array_list_reserve(list, type, size) \
do { \
    if(size > list.capacity){\
        list.capacity = size; \
        list.data = realloc(list.data, sizeof(type) * list.capacity); \
    }\
} while(0) 



#define array_list_append(list, type, value) \
    do { \
        if(list.size == list.capacity){ \
            array_list_resize(list, type); \
        } \
        type* temp = (type*)list.data; \
        temp[list.size] = value; \
        list.size++; \
    } while(0)

#define array_list_get(list, type, index)((type*)list.data)[index]

#define array_list_delete(list) \
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
} ElfHeader;


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
} SectionHeader;





ArrayList abbreviations_table = {0};



typedef struct {
    uint64_t attribute;
    uint64_t form;
    int64_t implicit_const;
} AbbrevAttribute;


typedef struct {
    uint64_t tag;
    uint8_t has_children;
    ArrayList attributes;
} AbbrevEntry;




typedef struct{
    char* name; 
    uint32_t offset;
    uint32_t type; 
} StructMember;


typedef struct {
    uint64_t offset;
    ArrayList names;
    ArrayList members;
} StructType;


typedef struct{
    char* name;
    uint64_t value;
} EnumMember;


typedef struct {
    uint64_t offset;
    char* name;
    ArrayList members;
} EnumType;


ArrayList structs = {0};
ArrayList enums = {0};



typedef struct {
    uint64_t cu_offset;
    uint64_t debug_str_offset;
    uint64_t debug_line_str_offset;
} Offsets;





static void print_structs(){
    for(uint64_t i = 0; i < structs.size; i++){
        StructType t = array_list_get(structs, StructType, i);
        printf("Offset: 0x%lx, %s: \n", t.offset, array_list_get(t.names, char*, 0));
        for(uint64_t j = 0; j < t.members.size; j++){
            StructMember mem = array_list_get(t.members, StructMember, j);
            printf("%d -> %s: %d\n", mem.offset, mem.name, mem.type);
        }
    }
}


static void print_enums(){
    for(uint64_t i = 0; i < enums.size; i++){
        EnumType t = array_list_get(enums, EnumType, i);
        printf("%s: \n", t.name);
        for(uint64_t j = 0; j < t.members.size; j++){
            EnumMember mem = array_list_get(t.members, EnumMember, j);
            printf("%s: %lu\n", mem.name, mem.value);
        }
    }
}




uint64_t read_uleb128(FILE *f) {
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


int64_t read_sleb128(FILE* f) {
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


static bool struct_names_eq(ArrayList* names, char* type){
    for(uint64_t i = 0; i < names->size; i++){
        char* type_name = array_list_get((*names), char*, i);

        if(strcmp(type_name, type) == 0) return true;

    }
    return false;
}



void print_structure(char* type, void* value){
    for(uint64_t i = 0; i < structs.size; i++){
        StructType st = array_list_get(structs, StructType, i);
        if(struct_names_eq(&st.names, type)){
            printf("%s {\n", type);
            for(uint64_t j = 0; j < st.members.size; j++){
                StructMember mem = array_list_get(st.members, StructMember, j);
                printf("%s: ", mem.name);

                switch (mem.type) {
                    case 1:
                        printf("%s\n", (char*)*((int8_t**)value + mem.offset));
                        break;
                    case 2:
                        printf("%s\n", (*((bool*)value + mem.offset) == 1) ? "true" : "false");
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        printf("%ld\n", (uint64_t)*((uint8_t*)value + mem.offset));
                        break;
                    case 6:
                        break;
                    case 7:
                        printf("%ld\n", (uint64_t)*((uint8_t*)value + mem.offset));
                    case 8:
                        break; 
                }
            }

            printf("}\n");
        }

    }
}

static void add_abbreviation_entry(uint64_t id, uint64_t tag, uint8_t has_children){
    array_list_reserve(abbreviations_table, AbbrevEntry, id);
    AbbrevEntry e = {0};
    e.tag = tag;
    e.has_children = has_children;
    array_list_create_cap(e.attributes, AbbrevAttribute, 4);
    ((AbbrevEntry*)abbreviations_table.data)[id - 1] = e;
}


static void add_attribute_entry(uint64_t id, uint64_t attribute, uint64_t form, int64_t form2){
    AbbrevEntry* abbrev_entry = &array_list_get(abbreviations_table, AbbrevEntry, id - 1);
    AbbrevAttribute a = {0};
    a.attribute = attribute;
    a.form = form;
    a.implicit_const = form2;
    array_list_append(abbrev_entry->attributes, AbbrevAttribute, a);
}



static void create_table(){
    if(abbreviations_table.data == 0){
        array_list_create_cap(abbreviations_table, AbbrevEntry, 32);
    } else{
        for(uint64_t i = 0; i < abbreviations_table.size; i++){
            AbbrevEntry* e = &array_list_get(abbreviations_table, AbbrevEntry, i);
            e->attributes.size = 0;
            e->attributes.data = 0;
            e->attributes.capacity = 0;
            array_list_delete(e->attributes);
        }
        abbreviations_table.size = 0; 
    }
}


void create_abbrevations_table(uint64_t offset, FILE* f){
    fpos_t pos;
    fgetpos(f, &pos);
    fseek(f, offset, SEEK_SET);

    uint64_t abbrev_id = read_uleb128(f);
    while(1){    
        uint64_t tag = read_uleb128(f);
        char has_children = fgetc(f);
        add_abbreviation_entry(abbrev_id, tag, has_children);
        while(1){
            uint64_t attribute = read_uleb128(f); 
            if(attribute == 0){

                uint64_t form = read_uleb128(f);
                if(form != 0){
                    fprintf(stderr,"Error Form should be 0\n");
                }
                break;
            }
            uint64_t form = read_uleb128(f);
            if(form == FORM_implicit_const){
                uint64_t s = read_sleb128(f);
                add_attribute_entry(abbrev_id, attribute, form, s);
            
            } else{ 
                add_attribute_entry(abbrev_id, attribute, form, 0);
            }

        }
        abbrev_id = read_uleb128(f);
        if(abbrev_id == 0) break; 
    }
    fsetpos(f, &pos);
}


static void delete_abbrevations_table(){
    for(uint64_t i = 0; i < abbreviations_table.capacity; i++){
        AbbrevEntry e = array_list_get(abbreviations_table, AbbrevEntry, i);
        array_list_delete(e.attributes);
    }
    array_list_delete(abbreviations_table);
}


void print_abbrevation_table(){
    for(int i = 0; i < abbreviations_table.size; i++){
        AbbrevEntry e = array_list_get(abbreviations_table, AbbrevEntry, i);
        printf("Id: %d\n", i + 1);
        printf("Tag: %s\n", tag_to_string(e.tag));
        printf("Has Children: %d\n", e.has_children);

        for(int j = 0; j < e.attributes.size; j++){
            AbbrevAttribute abb = array_list_get(e.attributes, AbbrevAttribute, j);
            if(abb.form == FORM_implicit_const){
                printf("%s -> %s, %ld\n", attribute_to_string(abb.attribute), form_to_string(abb.form), abb.implicit_const);
            } else{
                printf("%s -> %s\n", attribute_to_string(abb.attribute), form_to_string(abb.form));
            }
        }
    }
}


static char* get_string(FILE* f){
    fpos_t pos;
    fgetpos(f, &pos);

    size_t count = 0;
    while(1){
        char c = fgetc(f);
        count++;
        if(c == 0) break;
    }


    fsetpos(f, &pos);
    char* result = malloc(count);
    if(result == NULL) return NULL;

    for(int i = 0; i < count; i++){
        result[i] = fgetc(f);
    }
    return result;
}


static char* get_string_table_value(uint64_t string_table_offset, uint64_t offset_in_table, FILE* f){
    fpos_t pos;
    fgetpos(f, &pos);
    fseek(f, string_table_offset + offset_in_table, SEEK_SET);

    char* result = get_string(f);
    
    fsetpos(f, &pos);
    return result;
}




static void skip_attribute(FILE* f, uint64_t form){
    switch (form) {
        case FORM_strp:{
            uint32_t str_offset = 0;
            fread(&str_offset, sizeof(str_offset), 1, f);
            break;
        } 
        case FORM_line_strp: {
            uint32_t str_offset = 0;
            fread(&str_offset, sizeof(str_offset), 1, f);
            break;
        }
        case FORM_flag:
        case FORM_data1: {
            uint8_t data = 0;
            fread(&data, sizeof(data), 1, f);
            break;
        }
       case FORM_ref4: {
            uint32_t off = 0;
            fread(&off, sizeof(off), 1, f);
            break;
       }
       case FORM_ref_addr:
       case FORM_sec_offset:
       case FORM_data4: {
            uint32_t data = 0;
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
            uint64_t expr_size = read_uleb128(f);
            //skip over the expression
            fseek(f, expr_size, SEEK_CUR);
            break;
        }
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
            printf("Not implemented: %s\n", form_to_string(form));
            exit(1);
    }
}







static void add_name_from_typedef(FILE* f, Offsets* offset, char* name, uint32_t type_offset){
    fpos_t pos;
    fgetpos(f, &pos);
    fseek(f, offset->cu_offset + type_offset, SEEK_SET);

    uint64_t id = read_uleb128(f);

    AbbrevEntry entry = array_list_get(abbreviations_table, AbbrevEntry, id - 1);

    if(entry.tag == TAG_structure_type){
        for(uint64_t i = 0; i < structs.size; i++){
            StructType* st = &array_list_get(structs, StructType, i);
            if(st->offset == type_offset){
                array_list_append(st->names, char*, name);
                fsetpos(f, &pos);
                return;
            } 
        } 
        fprintf(stderr, "Could not find struct for typedef %s, 0x%x\n", name, type_offset);
    } else if (entry.tag == TAG_enumeration_type) {
        for(uint64_t i = 0; i < structs.size; i++){
            EnumType* et = &array_list_get(enums, EnumType, i);
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
            AbbrevAttribute abb = array_list_get(entry.attributes, AbbrevAttribute, i);
            if(abb.attribute == AT_type){ 
                uint32_t new_type_offset = 0;
                assert(abb.form == FORM_ref4 && "Expected Form ref4\n");
                fread(&new_type_offset, sizeof(new_type_offset), 1, f); 
                add_name_from_typedef(f, offset, name, new_type_offset); 
                break;

            } else{
                skip_attribute(f, abb.form);
            }
        }
    }
    fsetpos(f, &pos);
}



static void add_member_to_enum(char* name, uint64_t value){
    EnumType* et = &array_list_get(enums, EnumType, enums.size - 1);
    EnumMember mem = {name, value};
    array_list_append(et->members, EnumMember, mem);
}

static void add_member_to_struct(FILE* f, Offsets* offset, char* name, uint32_t member_location, uint32_t member_type_offset){ 
    StructType* st = &array_list_get(structs, StructType, structs.size - 1);
    fpos_t pos;
    fgetpos(f, &pos);
    fseek(f, offset->cu_offset + member_type_offset, SEEK_SET);
    uint64_t id = read_uleb128(f);
    AbbrevEntry entry = array_list_get(abbreviations_table, AbbrevEntry, id - 1);

    uint32_t encoding = 0;
    if(entry.tag == TAG_pointer_type){
        encoding = 1;
    } else{

        if(entry.tag != TAG_base_type){
            fsetpos(f, &pos);
            return;
        }


        assert(entry.tag == TAG_base_type && "Only support base types in structs right now\n");

        for(int j = 0; j < entry.attributes.size; j++){
            AbbrevAttribute abb = array_list_get(entry.attributes, AbbrevAttribute, j);

            if(abb.attribute == AT_encoding){
                assert(abb.form == FORM_data1 && "Expected data1\n");
                fread(&encoding, 1, 1, f);
                break;
            } else{
                skip_attribute(f, abb.form);
            } 
        }
    }

    fsetpos(f, &pos);

    StructMember mem = {0};
    mem.name = name;
    mem.offset = member_location;
    mem.type = encoding;
    array_list_append(st->members, StructMember, mem);
}


static char* get_name(FILE* f, Offsets* offsets, uint64_t form){
    if(form == FORM_strp){
        uint32_t str_offset = 0;
        fread(&str_offset, sizeof(str_offset), 1, f);
        return get_string_table_value(offsets->debug_str_offset, str_offset, f);
    } else if (form == FORM_string) {
        return get_string(f); 
    } else{
        fprintf(stderr, "Expected form strp or string for struct name\n");
        assert(false && "Not implemented");
    }
}




static uint64_t depth = 0;
void get_type_information(FILE* f, Offsets* offsets){
    while(1){
        uint64_t offset = ftell(f);

        uint64_t id = read_uleb128(f);
        if(id == 0) return;
        
        AbbrevEntry entry = array_list_get(abbreviations_table, AbbrevEntry, id - 1);


        if(entry.tag == TAG_structure_type){
            StructType t = {0};
            t.offset = offset - offsets->cu_offset;
            array_list_create_cap(t.names, char*, 1);
            array_list_create_cap(t.members, StructMember, 2);
            array_list_append(structs, StructType, t);
        } else if (entry.tag == TAG_enumeration_type) {
            EnumType t = {0};
            t.offset = offset - offsets->cu_offset;
            t.name = NULL;
            array_list_create_cap(t.members, EnumMember, 2);
            array_list_append(enums, EnumType, t);
        }


        char* name = NULL;
        uint32_t type_offset = 0;
        uint32_t member_location = 0;

        uint32_t struct_member_type_offset = 0;
        bool is_struct = false;

        uint64_t enum_value = 0;

        for(int j = 0; j < entry.attributes.size; j++){
            AbbrevAttribute abb = array_list_get(entry.attributes, AbbrevAttribute, j);

            if(abb.attribute == AT_name){
                switch (entry.tag) {
                    case TAG_structure_type: {
                        StructType* st = &array_list_get(structs, StructType,structs.size - 1);
                        char* name = get_name(f, offsets, abb.form);
                        array_list_append(st->names, char*, name);
                        break;
                    }
                    case TAG_enumeration_type: {
                        EnumType* et = &array_list_get(enums, EnumType,enums.size - 1);
                        et->name = get_name(f, offsets, abb.form);
                        break;
                    }
                    case TAG_typedef:
                    case TAG_member:
                    case TAG_enumerator:
                        name = get_name(f, offsets, abb.form);
                        break;
                    default:
                        skip_attribute(f, abb.form);
                }

            } else if (abb.attribute == AT_type) {
                if(entry.tag == TAG_typedef){
                    assert(abb.form == FORM_ref4 && "Expected Form ref4\n");
                    fread(&type_offset, sizeof(type_offset), 1, f);
                } else if (entry.tag == TAG_member){
                    assert(abb.form == FORM_ref4 && "Expected Form ref4\n");
                    fread(&struct_member_type_offset, sizeof(struct_member_type_offset), 1, f); 
                } else{
                    skip_attribute(f, abb.form);
                } 

            } else if (abb.attribute == AT_data_member_location && entry.tag == TAG_member) {
                is_struct = true;
                assert(abb.form == FORM_data1 && "Expected data1\n");
                fread(&member_location, 1, 1, f);

            } else if (abb.attribute == AT_const_value && entry.tag == TAG_enumerator) {
                int size = 0;
                if(abb.form == FORM_data1) size = 1;
                else if(abb.form == FORM_data2) size = 2;
                else if(abb.form == FORM_data4) size = 4;
                else if(abb.form == FORM_data8) size = 8;
                else{
                    fprintf(stderr, "INVALID form for enum member: %s", form_to_string(abb.form));
                    assert(false && "Not implemented");
                }
                fread(&enum_value, size, 1, f);
            } else{
                skip_attribute(f, abb.form);
            }
        }

        if(entry.tag == TAG_typedef){
            if(type_offset == 0){
                free(name);
            } else{
                add_name_from_typedef(f, offsets, name, type_offset);
            }
        } else if (entry.tag == TAG_member && is_struct){
            add_member_to_struct(f, offsets, name, member_location, struct_member_type_offset);
        } else if (entry.tag == TAG_enumerator) {
            add_member_to_enum(name, enum_value); 
        }

        if(entry.has_children){
            depth++;
            get_type_information(f, offsets);
            depth--;
        }

        //root doesn't have siblings
        if(depth == 0) break;
    }

}




static bool strtable_streq(FILE* f, SectionHeader* string_table, uint32_t name, const char* string){
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


extern void print_section_header(SectionHeader* h, int i);

void init_derive_debug(FILE* f){
    ElfHeader h = {0};
    fread(&h, sizeof(h), 1, f);

    //read section header table
    fseek(f, h.section_header_offset, SEEK_SET);

    SectionHeader st = {0};
    fseek(f, h.section_header_offset + h.section_header_size * h.string_table_index, SEEK_SET);
    fread(&st, sizeof(st), 1, f);

    fseek(f, h.section_header_offset, SEEK_SET);

    //get the abbrevation & debug string table
    SectionHeader debug_abbrev = {0};
    SectionHeader debug_str = {0};
    SectionHeader debug_line_str = {0};
    SectionHeader debug_info = {0};

    bool found_debug = false;
    for(int i = 0; i < h.section_header_entries; i++){
        SectionHeader temp = {0};
        fread(&temp, sizeof(temp), 1, f);
        if(strtable_streq(f, &st, temp.name, ".debug_abbrev")){
            memcpy(&debug_abbrev, &temp, sizeof(SectionHeader));
        }
        else if(strtable_streq(f, &st, temp.name, ".debug_str")){
            memcpy(&debug_str, &temp, sizeof(SectionHeader));
        }else if(strtable_streq(f, &st, temp.name,".debug_line_str")){
            memcpy(&debug_line_str, &temp, sizeof(SectionHeader));
        } else if(strtable_streq(f, &st, temp.name,".debug_info")){
            memcpy(&debug_info, &temp, sizeof(SectionHeader));
            found_debug = true;
        }

    }

    if(!found_debug){
        fprintf(stderr, "Failed to find debug info\n");
        return;
    }



    array_list_create_cap(structs,StructType, 8);
    array_list_create_cap(enums,EnumType, 8);

 
    fseek(f, debug_info.offset, SEEK_SET);
    uint64_t start = debug_info.offset;

    Offsets offsets = {0};
    offsets.debug_line_str_offset = debug_line_str.offset;
    offsets.debug_str_offset = debug_str.offset;

    while(ftell(f) - start < debug_info.size){
        Dwarf5Header ch = {0};
        offsets.cu_offset = ftell(f);
        fread(&ch, sizeof(Dwarf5Header), 1, f);
        printf("Length: %d\n", ch.length);
        printf("Version: %d\n", ch.version);
        printf("Type: %s\n", header_type_to_string(ch.type));
        printf("Address Size: %d\n", ch.addr_size);
        printf("Abbrev Offset: %d\n", ch.abbrev_offset);
        switch(ch.type){
            case UT_compile:
            case UT_partial: {
                create_abbrevations_table(debug_abbrev.offset + ch.abbrev_offset, f);
                get_type_information(f, &offsets);
                //print_structs();
                //print_enums();
                break;
            }

            case UT_skeleton:
            case UT_split_compile: {
                uint64_t id = 0;
                fread(&id, sizeof(id), 1, f);
                printf("%lu\n", id);
                break;
            }
            case UT_type:
            case UT_split_type: {
                uint32_t toff = 0;
                uint64_t signature = 0;
                fread(&toff, sizeof(toff), 1, f);
                fread(&signature, sizeof(signature), 1, f);
                printf("Type Offset: %d\n", toff);
                printf("Signature: %lu\n", signature);
                break;
            }
        }
    }
    delete_abbrevations_table();
}







const char* header_type_to_string(uint64_t t){
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

const char* tag_to_string(uint64_t tag){
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


const char* attribute_to_string(uint64_t t){
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


const char* form_to_string(uint64_t t){
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
