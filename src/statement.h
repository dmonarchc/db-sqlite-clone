#ifndef STATEMENT_H
#define STATEMENT_H

#include "inputbuffer.h"
#include "row.h"
#include "table.h"

typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT
} StatementType;

typedef enum {
    PREPARE_SUCCESS,
    PREPARE_NEGATIVE_ID,
    PREPARE_STRING_TOO_LONG,
    PREPARE_SYNTAX_ERROR,
    PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

typedef enum { EXECUTE_SUCCESS, EXECUTE_TABLE_FULL } ExecuteResult;

typedef struct {
    StatementType type;
    Row row_to_insert;  // only used by insert statement
} Statement;

PrepareResult prepare_statement(InputBuffer* input_buffer,
                                Statement* statement);

ExecuteResult execute_insert(Statement* statement, Table* table);
ExecuteResult execute_select(Statement* statement, Table* table);
ExecuteResult execute_statement(Statement* statement, Table* table);

#endif // STATEMENT_H
