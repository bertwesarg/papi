/**
 * @file    roc_dispatch.h
 * @author  Giuseppe Congiu
 *          gcongiu@icl.utk.edu
 *
 * @brief rocm component dispatch layer. Dispatches profiling
 * to the appropriate backend interface (e.g. rocprofiler).
 */

#ifndef __ROC_DISPATCH_H__
#define __ROC_DISPATCH_H__

#include "roc_profiler_config.h"

typedef struct rocd_ctx *rocd_ctx_t;

/* init and shutdown interfaces */
int rocd_init_environment(void);
int rocd_init(void);
int rocd_shutdown(void);

/* native event interfaces */
int rocd_evt_enum(unsigned int *event_code, int modifier);
int rocd_evt_code_to_descr(unsigned int event_code, char *descr, int len);
int rocd_evt_name_to_code(const char *name, unsigned int *event_code);
int rocd_evt_code_to_name(unsigned int event_code, char *name, int len);

/* error handling interfaces */
int rocd_err_get_last(const char **error_str);

/* profiling context handling interfaces */
int rocd_ctx_open(unsigned int *event_id, int num_events, rocd_ctx_t *ctx);
int rocd_ctx_close(rocd_ctx_t ctx);
int rocd_ctx_start(rocd_ctx_t ctx);
int rocd_ctx_stop(rocd_ctx_t ctx);
int rocd_ctx_read(rocd_ctx_t ctx, long long **counters);
int rocd_ctx_reset(rocd_ctx_t ctx);

#endif /* End of __ROC_DISPATCH_H__ */
