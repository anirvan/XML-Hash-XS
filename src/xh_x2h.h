#ifndef _XH_X2H_H_
#define _XH_X2H_H_

#include "xh_config.h"
#include "xh_core.h"

#define XH_X2H_NORMALIZE_REF            1
#define XH_X2H_NORMALIZE_LINE_FEED      2

#define XH_X2H_PARSER_STATE_LIST                                        \
    XH_X2H_PROCESS_STATE(CONTENT_START)                                 \
    XH_X2H_PROCESS_STATE(PARSE_ELEMENT_START)                           \
    XH_X2H_PROCESS_STATE(XML_COMMENT_NODE_OR_CDATA_START)               \
    XH_X2H_PROCESS_STATE(COMMENT1_START)                                \
    XH_X2H_PROCESS_STATE(END_COMMENT1_START)                            \
    XH_X2H_PROCESS_STATE(END_COMMENT2_START)                            \
    XH_X2H_PROCESS_STATE(END_COMMENT3_START)                            \
    XH_X2H_PROCESS_STATE(CDATA_1_1_START)                               \
    XH_X2H_PROCESS_STATE(CDATA_1_2_START)                               \
    XH_X2H_PROCESS_STATE(CDATA_1_3_START)                               \
    XH_X2H_PROCESS_STATE(CDATA_2_1_START)                               \
    XH_X2H_PROCESS_STATE(CDATA_2_2_START)                               \
    XH_X2H_PROCESS_STATE(CDATA_2_3_START)                               \
    XH_X2H_PROCESS_STATE(END_CDATA1_START)                              \
    XH_X2H_PROCESS_STATE(END_CDATA2_START)                              \
    XH_X2H_PROCESS_STATE(END_CDATA3_START)                              \
    XH_X2H_PROCESS_STATE(PARSE_CLOSING_TAG_START)                       \
    XH_X2H_PROCESS_STATE(SEARCH_CLOSING_END_TAG_START)                  \
    XH_X2H_PROCESS_STATE(PARSE_OPENING_TAG_START)                       \
    XH_X2H_PROCESS_STATE(SEARCH_OPENING_END_TAG_START)                  \
    XH_X2H_PROCESS_STATE(NODE_SEARCH_ATTR_START)                        \
    XH_X2H_PROCESS_STATE(SEARCH_END_TAG_START)                          \
    XH_X2H_PROCESS_STATE(NODE_PARSE_ATTR_NAME_START)                    \
    XH_X2H_PROCESS_STATE(NODE_ATTR_SKIP_BLANK_START)                    \
    XH_X2H_PROCESS_STATE(NODE_PARSE_ATTR_VALUE_START)                   \
    XH_X2H_PROCESS_STATE(NODE_1_END_ATTR_VALUE_START)                   \
    XH_X2H_PROCESS_STATE(NODE_2_END_ATTR_VALUE_START)                   \
    XH_X2H_PROCESS_STATE(XML_DECL_1_START)                              \
    XH_X2H_PROCESS_STATE(XML_DECL_2_START)                              \
    XH_X2H_PROCESS_STATE(XML_DECL_3_START)                              \
    XH_X2H_PROCESS_STATE(XML_DECL_ATTR_START)                           \
    XH_X2H_PROCESS_STATE(XML_DECL_ATTR_SEARCH_ATTR_START)               \
    XH_X2H_PROCESS_STATE(XML_DECL_SEARCH_END_TAG2_START)                \
    XH_X2H_PROCESS_STATE(XML_DECL_ATTR_PARSE_ATTR_NAME_START)           \
    XH_X2H_PROCESS_STATE(XML_DECL_ATTR_ATTR_SKIP_BLANK_START)           \
    XH_X2H_PROCESS_STATE(XML_DECL_ATTR_PARSE_ATTR_VALUE_START)          \
    XH_X2H_PROCESS_STATE(XML_DECL_ATTR_1_END_ATTR_VALUE_START)          \
    XH_X2H_PROCESS_STATE(XML_DECL_ATTR_2_END_ATTR_VALUE_START)

#define XH_X2H_PROCESS_STATE(st) st,
typedef enum {
    PARSER_ST_NONE = 0,
    XH_X2H_PARSER_STATE_LIST
    XML_DECL_FOUND,
    PARSER_ST_DONE
} xh_x2h_state_t;
#undef XH_X2H_PROCESS_STATE

#define XH_X2H_NODE_FLAG_NONE        0
#define XH_X2H_NODE_FLAG_FORCE_ARRAY 1

typedef struct {
    SV                **lval;
    unsigned int        flags;
} xh_x2h_node_t;

typedef struct {
    xh_opts_t           opts;
    SV                 *hash;
    xh_char_t           encoding[XH_PARAM_LEN];
    xh_char_t          *tmp;
    size_t              tmp_size;
    xh_char_t          *node, *end, *content;
    unsigned int        need_normalize;
    xh_x2h_node_t      *nodes;
    SV                **lval;
    unsigned int        depth, code;
    xh_x2h_state_t      state;
    xh_reader_t         reader;
} xh_x2h_ctx_t;

SV *xh_x2h(xh_x2h_ctx_t *ctx, SV *xml);

#endif /* _XH_X2H_H_ */
