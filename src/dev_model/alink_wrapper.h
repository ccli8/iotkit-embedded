/*
 * Copyright (C) 2015-2018 Alibaba Group Holding Limited
 */

#ifndef __ALINK_WRAPPER_H__
#define __ALINK_WRAPPER_H__

#include "infra_types.h"
#include "infra_defs.h"
#include "infra_log.h"
#include "infra_list.h"
#include "infra_compat.h" 
#include "infra_cjson.h"
#include "infra_timer.h"
#include "infra_sha256.h"
#include "infra_string.h"

#include "wrappers_defs.h"

int8_t HAL_GetPartnerID(char *pid_str);
int8_t HAL_GetModuleID(char *mid_str);
int8_t HAL_GetProductKey(char product_key[IOTX_PRODUCT_KEY_LEN]);
int8_t HAL_GetProductSecret(char product_secret[IOTX_PRODUCT_SECRET_LEN]);
int8_t HAL_GetDeviceName(char device_name[IOTX_DEVICE_NAME_LEN]);
int8_t HAL_GetDeviceSecret(char device_secret[IOTX_DEVICE_SECRET_LEN]);

void *HAL_Malloc(uint32_t size);
void HAL_Free(void *ptr);
int HAL_Snprintf(char *str, const int len, const char *fmt, ...);
uint64_t HAL_UptimeMs(void);

void HAL_SleepMs(uint32_t ms);

void *HAL_MutexCreate(void);
void HAL_MutexDestroy(void *mutex);
void HAL_MutexLock(void *mutex);
void HAL_MutexUnlock(void *mutex);

int HAL_ThreadCreate(
                     void **thread_handle,
                     void *(*work_routine)(void *),
                     void *arg,
                     hal_os_thread_param_t *hal_os_thread_param,
                     int *stack_used);
void HAL_ThreadDelete(void *thread_handle);                     

#endif /* #ifndef __ALINK_WRAPPER_H__ */
