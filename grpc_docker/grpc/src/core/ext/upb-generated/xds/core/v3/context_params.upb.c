/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     xds/core/v3/context_params.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg_internal.h"
#include "xds/core/v3/context_params.upb.h"
#include "udpa/annotations/status.upb.h"

#include "upb/port_def.inc"

static const upb_msglayout *const xds_core_v3_ContextParams_submsgs[1] = {
  &xds_core_v3_ContextParams_ParamsEntry_msginit,
};

static const upb_msglayout_field xds_core_v3_ContextParams__fields[1] = {
  {1, UPB_SIZE(0, 0), 0, 0, 11, _UPB_MODE_MAP},
};

const upb_msglayout xds_core_v3_ContextParams_msginit = {
  &xds_core_v3_ContextParams_submsgs[0],
  &xds_core_v3_ContextParams__fields[0],
  UPB_SIZE(8, 8), 1, false, 1, 255,
};

static const upb_msglayout_field xds_core_v3_ContextParams_ParamsEntry__fields[2] = {
  {1, UPB_SIZE(0, 0), 0, 0, 9, _UPB_MODE_SCALAR},
  {2, UPB_SIZE(8, 16), 0, 0, 9, _UPB_MODE_SCALAR},
};

const upb_msglayout xds_core_v3_ContextParams_ParamsEntry_msginit = {
  NULL,
  &xds_core_v3_ContextParams_ParamsEntry__fields[0],
  UPB_SIZE(16, 32), 2, false, 2, 255,
};

#include "upb/port_undef.inc"

