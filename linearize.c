#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tensor.h"
#include "linearize.h"
#include "utils.h"

ALWAYS_INLINE void simple_op_convert(simple_op_t *simple_op, op_t *op) {
    simple_op->type = op->type;
    simple_op->unary_type = op->unary_type;
    simple_op->binary_type = op->binary_type;
    simple_op->reduce_type = op->reduce_type;
    simple_op->move_type = op->move_type;
    simple_op->var_unary = op->var_unary;
    simple_op->var_a = op->var_a;
    simple_op->var_z = op->var_z;
    simple_op->var_y = op->var_y;
    simple_op->var_x = op->var_x;
    simple_op->out_buffer = op->out_buffer;
    simple_op->in_buffer = op->in_buffer;
    simple_op->tensor_base = op->tensor_base;
}
void simple_op_print(simple_op_t *simple_op, int padding, int offset, const char *name) {
    if(strcmp(name, "") != 0) {
        printf("%*s%s\n", offset, "", name);
    }
    printf("%*s", offset + padding, "");
    switch(simple_op->type) {
        case(operation_unary): {
            switch(simple_op->unary_type) {
                case(unary_add): {
                    printf("U add [%lu, %lu, %lu, %lu] > {%lu, %lu, %lu, %lu} %lu %lf [%p]\n", simple_op->out_buffer->a_inherent, simple_op->out_buffer->z_inherent, simple_op->out_buffer->y_inherent, simple_op->out_buffer->x_inherent, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->var_unary, simple_op->out_buffer);
                    break;
                }
                case(unary_subtract): {
                    printf("U sub [%lu, %lu, %lu, %lu] > {%lu, %lu, %lu, %lu} %lu %lf [%p]\n", simple_op->out_buffer->a_inherent, simple_op->out_buffer->z_inherent, simple_op->out_buffer->y_inherent, simple_op->out_buffer->x_inherent, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->var_unary, simple_op->out_buffer);
                    break;
                }
                case(unary_multiply): {
                    printf("U mul [%lu, %lu, %lu, %lu] > {%lu, %lu, %lu, %lu} %lu %lf [%p]\n", simple_op->out_buffer->a_inherent, simple_op->out_buffer->z_inherent, simple_op->out_buffer->y_inherent, simple_op->out_buffer->x_inherent, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->var_unary, simple_op->out_buffer);
                    break;
                }
                case(unary_divide): {
                    printf("U div [%lu, %lu, %lu, %lu] > {%lu, %lu, %lu, %lu} %lu %lf [%p]\n", simple_op->out_buffer->a_inherent, simple_op->out_buffer->z_inherent, simple_op->out_buffer->y_inherent, simple_op->out_buffer->x_inherent, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->var_unary, simple_op->out_buffer);
                    break;
                }
                case(unary_exp): {
                    printf("U exp [%lu, %lu, %lu, %lu] > {%lu, %lu, %lu, %lu} %lu [%p]\n", simple_op->out_buffer->a_inherent, simple_op->out_buffer->z_inherent, simple_op->out_buffer->y_inherent, simple_op->out_buffer->x_inherent, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->out_buffer);
                    break;
                }
                case(unary_log): {
                    printf("U log [%lu, %lu, %lu, %lu] > {%lu, %lu, %lu, %lu} %lu [%p]\n", simple_op->out_buffer->a_inherent, simple_op->out_buffer->z_inherent, simple_op->out_buffer->y_inherent, simple_op->out_buffer->x_inherent, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->out_buffer);
                    break;
                }
                case(unary_square): {
                    printf("U sqr [%lu, %lu, %lu, %lu] > {%lu, %lu, %lu, %lu} %lu [%p]\n", simple_op->out_buffer->a_inherent, simple_op->out_buffer->z_inherent, simple_op->out_buffer->y_inherent, simple_op->out_buffer->x_inherent, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->out_buffer);
                    break;
                }
                case(unary_sqrt): {
                    printf("U sqt [%lu, %lu, %lu, %lu] > {%lu, %lu, %lu, %lu} %lu [%p]\n", simple_op->out_buffer->a_inherent, simple_op->out_buffer->z_inherent, simple_op->out_buffer->y_inherent, simple_op->out_buffer->x_inherent, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->out_buffer);
                    break;
                }
                case(unary_negate): {
                    printf("U ngt [%lu, %lu, %lu, %lu] > {%lu, %lu, %lu, %lu} %lu [%p]\n", simple_op->out_buffer->a_inherent, simple_op->out_buffer->z_inherent, simple_op->out_buffer->y_inherent, simple_op->out_buffer->x_inherent, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->out_buffer);
                    break;
                }
                case(unary_reciprocal): {
                    printf("U rcp [%lu, %lu, %lu, %lu] > {%lu, %lu, %lu, %lu} %lu [%p]\n", simple_op->out_buffer->a_inherent, simple_op->out_buffer->z_inherent, simple_op->out_buffer->y_inherent, simple_op->out_buffer->x_inherent, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->out_buffer);
                    break;
                }
                case(unary_max): {
                    printf("U max [%lu, %lu, %lu, %lu] > {%lu, %lu, %lu, %lu} %lu %lf [%p]\n", simple_op->out_buffer->a_inherent, simple_op->out_buffer->z_inherent, simple_op->out_buffer->y_inherent, simple_op->out_buffer->x_inherent, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->var_unary, simple_op->out_buffer);
                    break;
                }
                case(unary_min): {
                    printf("U min [%lu, %lu, %lu, %lu] > {%lu, %lu, %lu, %lu} %lu %lf [%p]\n", simple_op->out_buffer->a_inherent, simple_op->out_buffer->z_inherent, simple_op->out_buffer->y_inherent, simple_op->out_buffer->x_inherent, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->var_unary, simple_op->out_buffer);
                    break;
                }
                case(unary_set): {
                    printf("U set [%lu, %lu, %lu, %lu] > {%lu, %lu, %lu, %lu} %lu %lf [%p]\n", simple_op->out_buffer->a_inherent, simple_op->out_buffer->z_inherent, simple_op->out_buffer->y_inherent, simple_op->out_buffer->x_inherent, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->var_unary, simple_op->out_buffer);
                    break;
                }
                case(unary_zero): {
                    printf("U zer [%lu, %lu, %lu, %lu] > {%lu, %lu, %lu, %lu} %lu [%p]\n", simple_op->out_buffer->a_inherent, simple_op->out_buffer->z_inherent, simple_op->out_buffer->y_inherent, simple_op->out_buffer->x_inherent, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->out_buffer);
                    break;
                }
                case(unary_random): {
                    printf("U ran [%lu, %lu, %lu, %lu] > {%lu, %lu, %lu, %lu} %lu [%p]\n", simple_op->out_buffer->a_inherent, simple_op->out_buffer->z_inherent, simple_op->out_buffer->y_inherent, simple_op->out_buffer->x_inherent, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->out_buffer);
                    break;
                }
            }
            break;
        }
        case(operation_binary): {
            switch(simple_op->binary_type) {
                case(binary_add): {
                    printf("B add {%lu, %lu, %lu, %lu} %lu & {%lu, %lu, %lu, %lu} %lu [%p] [%p]\n", simple_op->in_buffer->a_size, simple_op->in_buffer->z_size, simple_op->in_buffer->y_size, simple_op->in_buffer->x_size, simple_op->in_buffer->offset, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->in_buffer, simple_op->out_buffer);
                    break;
                }
                case(binary_subtract): {
                    printf("B sub {%lu, %lu, %lu, %lu} %lu & {%lu, %lu, %lu, %lu} %lu [%p] [%p]\n", simple_op->in_buffer->a_size, simple_op->in_buffer->z_size, simple_op->in_buffer->y_size, simple_op->in_buffer->x_size, simple_op->in_buffer->offset, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->in_buffer, simple_op->out_buffer);
                    break;
                }
                case(binary_multiply): {
                    printf("B mul {%lu, %lu, %lu, %lu} %lu & {%lu, %lu, %lu, %lu} %lu [%p] [%p]\n", simple_op->in_buffer->a_size, simple_op->in_buffer->z_size, simple_op->in_buffer->y_size, simple_op->in_buffer->x_size, simple_op->in_buffer->offset, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->in_buffer, simple_op->out_buffer);
                    break;
                }
                case(binary_divide): {
                    printf("B div {%lu, %lu, %lu, %lu} %lu & {%lu, %lu, %lu, %lu} %lu [%p] [%p]\n", simple_op->in_buffer->a_size, simple_op->in_buffer->z_size, simple_op->in_buffer->y_size, simple_op->in_buffer->x_size, simple_op->in_buffer->offset, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->in_buffer, simple_op->out_buffer);
                    break;
                }
                case(binary_max): {
                    printf("B max {%lu, %lu, %lu, %lu} %lu & {%lu, %lu, %lu, %lu} %lu [%p] [%p]\n", simple_op->in_buffer->a_size, simple_op->in_buffer->z_size, simple_op->in_buffer->y_size, simple_op->in_buffer->x_size, simple_op->in_buffer->offset, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->in_buffer, simple_op->out_buffer);
                    break;
                }
                case(binary_min): {
                    printf("B min {%lu, %lu, %lu, %lu} %lu & {%lu, %lu, %lu, %lu} %lu [%p] [%p]\n", simple_op->in_buffer->a_size, simple_op->in_buffer->z_size, simple_op->in_buffer->y_size, simple_op->in_buffer->x_size, simple_op->in_buffer->offset, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->in_buffer, simple_op->out_buffer);
                    break;
                }
                case(binary_copy): {
                    printf("B cpy {%lu, %lu, %lu, %lu} %lu & {%lu, %lu, %lu, %lu} %lu [%p] [%p]\n", simple_op->in_buffer->a_size, simple_op->in_buffer->z_size, simple_op->in_buffer->y_size, simple_op->in_buffer->x_size, simple_op->in_buffer->offset, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->in_buffer, simple_op->out_buffer);
                    break;
                }
            }
            break;
        }
        case(operation_reduce): {
            switch(simple_op->reduce_type) {
                case(reduce_sum): {
                    printf("R sum {%lu, %lu, %lu, %lu} %lu > {%lu, %lu, %lu, %lu} %lu [%p] [%p]\n", simple_op->in_buffer->a_size, simple_op->in_buffer->z_size, simple_op->in_buffer->y_size, simple_op->in_buffer->x_size, simple_op->in_buffer->offset, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->in_buffer, simple_op->out_buffer);
                    break;
                }
                case(reduce_avg): {
                    printf("R avg {%lu, %lu, %lu, %lu} %lu > {%lu, %lu, %lu, %lu} %lu [%p] [%p]\n", simple_op->in_buffer->a_size, simple_op->in_buffer->z_size, simple_op->in_buffer->y_size, simple_op->in_buffer->x_size, simple_op->in_buffer->offset, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->in_buffer, simple_op->out_buffer);
                    break;
                }
                case(reduce_max): {
                    printf("R max {%lu, %lu, %lu, %lu} %lu > {%lu, %lu, %lu, %lu} %lu [%p] [%p]\n", simple_op->in_buffer->a_size, simple_op->in_buffer->z_size, simple_op->in_buffer->y_size, simple_op->in_buffer->x_size, simple_op->in_buffer->offset, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->in_buffer, simple_op->out_buffer);
                    break;
                }
                case(reduce_min): {
                    printf("R min {%lu, %lu, %lu, %lu} %lu > {%lu, %lu, %lu, %lu} %lu [%p] [%p]\n", simple_op->in_buffer->a_size, simple_op->in_buffer->z_size, simple_op->in_buffer->y_size, simple_op->in_buffer->x_size, simple_op->in_buffer->offset, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->in_buffer, simple_op->out_buffer);
                    break;
                }
            }
            break;
        }
        case(operation_move): {
            switch(simple_op->move_type) {
                case(move_reshape): {
                    printf("M rsp {%lu, %lu, %lu, %lu} %lu - {%lu, %lu, %lu, %lu} %lu [%p]\n", simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->var_a, simple_op->var_z, simple_op->var_y, simple_op->var_x, simple_op->out_buffer->offset, simple_op->out_buffer);
                    break;
                }
                case(move_resize): {
                    printf("M rsp {%lu, %lu, %lu, %lu} %lu - {%lu, %lu, %lu, %lu} %lu [%p]\n", simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->var_a, simple_op->var_z, simple_op->var_y, simple_op->var_x, simple_op->out_buffer->offset, simple_op->out_buffer);
                    break;
                }
                case(move_offset): {
                    printf("M off {%lu, %lu, %lu, %lu} %lu - {%lu, %lu, %lu, %lu} %lu [%p]\n", simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->offset, simple_op->out_buffer->a_size, simple_op->out_buffer->z_size, simple_op->out_buffer->y_size, simple_op->out_buffer->x_size, simple_op->out_buffer->a_stride * simple_op->var_a + simple_op->out_buffer->z_stride * simple_op->var_z + simple_op->out_buffer->y_stride * simple_op->var_y + simple_op->out_buffer->x_stride * simple_op->var_x, simple_op->out_buffer);
                    break;
                }
            }
            break;
        }
    }
}

/* NOTE: Completely made up value. Not tested at all. */
const uint64_t initial_simple_op_capactity = 100;
linearized_t linearized_alloc(void) {
    linearized_t linearized = {
        .op_count = 0,
        .op_capacity = initial_simple_op_capactity,
        .simple = malloc(initial_simple_op_capactity * sizeof(simple_op_t)),
    };

    return(linearized);
}
void linearized_from_op(linearized_t *linearized, op_t *op) {
    while(op->parent_count > 0) {
        linearized_from_op(linearized, op->parent[0]);
    }
    if(linearized->op_capacity == linearized->op_count) {
        linearized->op_capacity *= 2;
        linearized->simple = realloc(linearized->simple, linearized->op_capacity * sizeof(simple_op_t));
    }
    simple_op_convert(&linearized->simple[linearized->op_count++], op);
    op_cleanup(op);
    op_free(op);
    free(op);
}
void linearized_free(linearized_t *linearized) {
    free(linearized->simple);
}
void linearized_clear(linearized_t *linearized) {
    linearized->op_count = 0;
}

void linearized_print(linearized_t *linearized, int padding, int offset, const char *name) {
    if(strcmp(name, "") != 0) {
        printf("%*slen %lu, cap %lu %s\n", offset, "", linearized->op_count, linearized->op_capacity, name);
    } else {
        printf("%*slen %lu, cap %lu\n", offset, "", linearized->op_count, linearized->op_capacity);
    }
    for(uint64_t i = 0; i < linearized->op_count; i++) {
        printf("%*s[%lu] ", padding + offset, "", i);
        simple_op_print(linearized->simple + i, 0, 0, "");
    }
}