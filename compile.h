#ifndef COMPILE_H_
#define COMPILE_H_

/* 
    1. Function recognizes loops in linearized_t (could also be of size 1, meaning a singular op)
    2. Function assigns loops to work groups
    3. Each loop gets split up into multiple work items
 */

#include <stdint.h>

#include "linearize.h"
#include "tensor.h"

/* TODO: Add other compile languages like CUDA. */
/* TODO: Add compilation to fixed binaries and also just the "normal" compilation. */
enum compile_e { compile_none, compile_cl };

/* TODO: Different optimisation enums for debugging. No-Copy, fusing ops once, twice etc. */

/* These are instructions that repeat and only the offsets change, not the relative differences if ya catch my drift. */
typedef struct {
    uint64_t loop_number;
    uint64_t loop_length;
    simple_op_t **loop_instance;
} compile_loop_t;
/* Function name, arg names etc. */
typedef struct {
    const char *name;
    /* NOTE: These are the names of the tensors needed. This way automatically calling with `neuralnet_forward()` is possible. */
    const char **args;
} cl_function_t;
/* These will tell neuralnet_forward how to call each compiled program via the kernels within it. These should exist for each compile option. */
typedef struct {
} cl_kernel_t;
typedef struct {
} cl_program_t;

extern void compile_linearized_to_cl(const char *filename, linearized_t *linearized);

#endif /* COMPILE_H_ */