#include <string.h>
#include "meta_command.h"

MetaCommandResult do_meta_command(InputBuffer* input_buffer) {
    if(strcmp(input_buffer->buffer, ".exit") == 0) {
        exit(0);
    } else {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}
