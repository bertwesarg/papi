/**
 * @file    roc_profiler.h
 * @author  Giuseppe Congiu
 *          gcongiu@icl.utk.edu
 */

#ifndef __ROC_PROFILER_H__
#define __ROC_PROFILER_H__

typedef struct rocd_ctx *rocp_ctx_t;

/* init and shutdown interfaces */
int rocp_init_environment(void);
int rocp_init(void);
int rocp_shutdown(void);

/* native event interfaces */
int rocp_evt_enum(unsigned int *event_code, int modifier);
int rocp_evt_code_to_descr(unsigned int event_code, char *descr, int len);
int rocp_evt_name_to_code(const char *name, unsigned int *event_code);
int rocp_evt_code_to_name(unsigned int event_code, char *name, int len);

/* profiling context handling interfaces */
int rocp_ctx_open(unsigned int *events_id, int num_events, rocp_ctx_t *ctx);
int rocp_ctx_close(rocp_ctx_t ctx);
int rocp_ctx_start(rocp_ctx_t ctx);
int rocp_ctx_stop(rocp_ctx_t ctx);
int rocp_ctx_read(rocp_ctx_t ctx, long long **counts);
int rocp_ctx_reset(rocp_ctx_t ctx);

#endif /* End of __ROC_PROFILER_H__ */
