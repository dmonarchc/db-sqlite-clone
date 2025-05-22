#ifndef META_COMMAND_H
#define META_COMMAND_H

#include "inputbuffer.h"  // Porque se usa InputBuffer*

typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

MetaCommandResult do_meta_command(InputBuffer* input_buffer);

#endif
