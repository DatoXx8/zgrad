#ifndef TENSOR_H_
#define TENSOR_H_

#include <stdint.h>

#include "utils.h"

#define BUFFER_NAME_SIZE 16
typedef struct {
    int64_t a_inh;
    int64_t z_inh;
    int64_t y_inh;
    int64_t x_inh;
    int64_t a_str;
    int64_t z_str;
    int64_t y_str;
    int64_t x_str;
    int64_t a_sze;
    int64_t z_sze;
    int64_t y_sze;
    int64_t x_sze;
    int64_t off;
    double *val;
    char name[BUFFER_NAME_SIZE + 1];
    int64_t sim_a_str;
    int64_t sim_z_str;
    int64_t sim_y_str;
    int64_t sim_x_str;
    int64_t sim_a_sze;
    int64_t sim_z_sze;
    int64_t sim_y_sze;
    int64_t sim_x_sze;
    int64_t sim_off;
    int64_t sim_a_off;
    int64_t sim_z_off;
    int64_t sim_y_off;
    int64_t sim_x_off;
} buffer_t;

extern buffer_t buffer_alloc(int64_t a, int64_t z, int64_t y, int64_t x);
extern void buffer_free(buffer_t *buffer);

#define BUFFER_AT(buffer, a, z, y, x) ((buffer).val[(buffer).a_str * (a) + (buffer).z_str * (z) + (buffer).y_str * (y) + (buffer).x_str * (x) + (buffer).off])
#define BUFFER_AT_(buffer, a, z, y, x)                                                                                                                         \
    ((buffer)->val[(buffer)->a_str * (a) + (buffer)->z_str * (z) + (buffer)->y_str * (y) + (buffer)->x_str * (x) + (buffer)->off])

enum operation_e { operation_unary, operation_binary, operation_reduce, operation_move };
enum unary_e {
    unary_add,
    unary_subtract,
    unary_multiply,
    unary_divide,
    unary_exp,
    unary_log,
    unary_square,
    unary_sqrt,
    unary_reciprocal,
    unary_max,
    unary_min,
    unary_set,
    /* Never *ever* use this for things like encryption, where the randomnes of the numbers is important! */
    unary_random,
    unary_tanh,
    unary_absolute,
    unary_sign
};
enum binary_e {
    binary_add,
    binary_subtract,
    binary_multiply,
    binary_divide,
    binary_max,
    binary_min,
    binary_copy,
    /* NOTE: Use these as their respective unary ops, but the unary_value is not constant and instead provided by the in_buffer, that has to have a shape of
       `{1, 1, 1, 1}`*/
    binary_add_like,
    binary_subtract_like,
    binary_multiply_like,
    binary_divide_like,
    binary_max_like,
    binary_min_like,
    binary_copy_like
};
enum reduce_e { reduce_sum, reduce_max, reduce_avg, reduce_min };
/* NOTE: Move ops have 0 cost at runtime. */
enum move_e { move_reshape, move_resize, move_offset };

/* TODO: Could maybe merge all the enums for a smaller op_t struct. */
typedef struct op {
    void *tensor_base;
    int64_t parent_count;
    int64_t parent_capacity;
    struct op **parent;
    int64_t child_count;
    int64_t child_capacity;
    struct op **child;
    enum operation_e type;
    enum unary_e unary_type;
    enum binary_e binary_type;
    enum reduce_e reduce_type;
    enum move_e move_type;
    double var_unary;
    int64_t var_a;
    int64_t var_z;
    int64_t var_y;
    int64_t var_x;
    buffer_t *out_buffer;
    buffer_t *in_buffer;
} op_t;

extern op_t op_alloc(void);
extern void op_add_parents(op_t *op, op_t *output_parent, op_t *input_parent);
extern void op_free(op_t *op);
extern void op_cleanup(op_t *op);
extern void op_single_print(op_t *op, int padding, int offset, const char *name);
extern void op_print(op_t *op, int padding, int offset, const char *name);
extern void op_single_op_cpu_realize(op_t *op);
extern void op_cpu_realize(op_t *op);
extern void op_tree(op_t *op);

#define OP_PRINT(op) op_print(&op, 4, 0, (#op))
#define OP_PRINT_(op) op_print(op, 4, 0, (#op))

typedef struct {
    buffer_t *buffer;
    op_t *op;
} tensor_t;

extern tensor_t tensor_alloc(int64_t a, int64_t z, int64_t y, int64_t x);
extern void tensor_free(tensor_t *tensor);

extern void tensor_set_unary(tensor_t *tensor, double value);
extern void tensor_add_unary(tensor_t *tensor, double value);
extern void tensor_subtract_unary(tensor_t *tensor, double value);
extern void tensor_multiply_unary(tensor_t *tensor, double value);
extern void tensor_divide_unary(tensor_t *tensor, double value);
extern void tensor_exp_unary(tensor_t *tensor);
extern void tensor_log_unary(tensor_t *tensor);
extern void tensor_square_unary(tensor_t *tensor);
extern void tensor_sqrt_unary(tensor_t *tensor);
extern void tensor_reciprocal_unary(tensor_t *tensor);
/* Never *ever* use this for things like encryption, where the randomnes of the numbers is important! */
extern void tensor_random_unary(tensor_t *tensor);
extern void tensor_tanh_unary(tensor_t *tensor);
extern void tensor_max_unary(tensor_t *tensor, double value);
extern void tensor_min_unary(tensor_t *tensor, double value);
extern void tensor_absolute_unary(tensor_t *tensor);
extern void tensor_sign_unary(tensor_t *tensor);

extern void tensor_add_binary(tensor_t *out, tensor_t *in);
extern void tensor_subtract_binary(tensor_t *out, tensor_t *in);
extern void tensor_multiply_binary(tensor_t *out, tensor_t *in);
extern void tensor_divide_binary(tensor_t *out, tensor_t *in);
extern void tensor_max_binary(tensor_t *out, tensor_t *in);
extern void tensor_min_binary(tensor_t *out, tensor_t *in);
extern void tensor_copy_binary(tensor_t *out, tensor_t *in);
extern void tensor_add_like_binary(tensor_t *out, tensor_t *in);
extern void tensor_subtract_like_binary(tensor_t *out, tensor_t *in);
extern void tensor_multiply_like_binary(tensor_t *out, tensor_t *in);
extern void tensor_divide_like_binary(tensor_t *out, tensor_t *in);
extern void tensor_max_like_binary(tensor_t *out, tensor_t *in);
extern void tensor_min_like_binary(tensor_t *out, tensor_t *in);
extern void tensor_copy_like_binary(tensor_t *out, tensor_t *in);

extern void tensor_sum_reduce(tensor_t *out, tensor_t *in);
extern void tensor_max_reduce(tensor_t *out, tensor_t *in);
extern void tensor_avg_reduce(tensor_t *out, tensor_t *in);
extern void tensor_min_reduce(tensor_t *out, tensor_t *in);

extern void tensor_reshape_move(tensor_t *tensor, int64_t a, int64_t z, int64_t y, int64_t x);
extern void tensor_resize_move(tensor_t *tensor, int64_t a, int64_t z, int64_t y, int64_t x);
extern void tensor_offset_move(tensor_t *tensor, int64_t a, int64_t z, int64_t y, int64_t x);

extern void tensor_cpu_realize(tensor_t *tensor);

extern void tensor_print(tensor_t *tensor, int padding, int offset, const char *name);
extern void tensor_preview(tensor_t *tensor, int padding, int offset, const char *name);

#define TENSOR_PRINT(tensor) tensor_print(&tensor, 4, 0, (#tensor))
#define TENSOR_PRINT_(tensor) tensor_print(tensor, 4, 0, (#tensor))
#define TENSOR_PREVIEW(tensor) tensor_preview(&tensor, 4, 0, (#tensor))
#define TENSOR_PREVIEW_(tensor) tensor_preview(tensor, 4, 0, (#tensor))

#endif
