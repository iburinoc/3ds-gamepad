/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.1 at Sat Sep 15 11:58:50 2018. */

#ifndef PB_FRAME_PB_H_INCLUDED
#define PB_FRAME_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _GamepadFrame {
    int32_t lx;
    int32_t ly;
    int32_t rx;
    int32_t ry;
    bool du;
    bool dd;
    bool dl;
    bool dr;
    bool a;
    bool b;
    bool x;
    bool y;
    bool start;
    bool select;
    bool l;
    bool zl;
    bool r;
    bool zr;
/* @@protoc_insertion_point(struct:GamepadFrame) */
} GamepadFrame;

/* Default values for struct fields */

/* Initializer values for message structs */
#define GamepadFrame_init_default                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define GamepadFrame_init_zero                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define GamepadFrame_lx_tag                      1
#define GamepadFrame_ly_tag                      2
#define GamepadFrame_rx_tag                      3
#define GamepadFrame_ry_tag                      4
#define GamepadFrame_du_tag                      5
#define GamepadFrame_dd_tag                      6
#define GamepadFrame_dl_tag                      7
#define GamepadFrame_dr_tag                      8
#define GamepadFrame_a_tag                       9
#define GamepadFrame_b_tag                       10
#define GamepadFrame_x_tag                       11
#define GamepadFrame_y_tag                       12
#define GamepadFrame_start_tag                   13
#define GamepadFrame_select_tag                  14
#define GamepadFrame_l_tag                       15
#define GamepadFrame_zl_tag                      16
#define GamepadFrame_r_tag                       17
#define GamepadFrame_zr_tag                      18

/* Struct field encoding specification for nanopb */
extern const pb_field_t GamepadFrame_fields[19];

/* Maximum encoded size of messages (where known) */
#define GamepadFrame_size                        55

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define FRAME_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
