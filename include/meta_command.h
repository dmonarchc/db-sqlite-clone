#ifndef META_COMMAND_H
#define META_COMMAND_H

#include "inputbuffer.h" // Porque se usa InputBuffer*
#include "node.h"
#include "pager.h"
#include "table.h"

typedef enum {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

MetaCommandResult do_meta_command(InputBuffer *input_buffer, Table *table);
void print_constants();

#endif
