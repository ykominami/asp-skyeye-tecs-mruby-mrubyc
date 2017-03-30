/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef GLOBAL_TECSGEN_H
#define GLOBAL_TECSGEN_H


/* import_C により import されるヘッダ #_IMP_# */
#include "tecs_kernel.h"
#include "t_syslog.h"
#include "tecs_mrubyc.h"
/**/

#ifndef TOPPERS_MACRO_ONLY

struct $TAG_0 {
                uint_t         reacnt;
                uint_t         wricnt;
};
typedef struct $TAG_0  T_SERIAL_RPOR;
 extern void nMruby_tsKernel_CB_initialize();
 extern void nMruby_tsKernel_Initializer_CB_initialize();
 extern void nMruby_tsSample_CB_initialize();
 extern void nMruby_tsSample_Initializer_CB_initialize();
 extern void tTask_CB_initialize();
 extern void tInitializeRoutine_CB_initialize();
 extern void tTerminateRoutine_CB_initialize();
 extern void tISR_CB_initialize();
 extern void tConfigInterrupt_CB_initialize();
 extern void tSemaphore_CB_initialize();
 extern void tKernel_CB_initialize();
 extern void tSIOPortSkyeyeMain_CB_initialize();
 extern void tPutLogSkyeye_CB_initialize();
 extern void tSerialPortMain_CB_initialize();
 extern void tSysLog_CB_initialize();
 extern void tLogTaskMain_CB_initialize();
 extern void tSample_CB_initialize();
 extern void tSample1_CB_initialize();
 extern void nMrubyc_tTECSInitializer_CB_initialize();
 extern void nMrubyc_tCharPointer_CB_initialize();
 extern void nMrubyc_tIntPointer_CB_initialize();
 extern void nMrubyc_tULongPointer_CB_initialize();
 extern void nMrubyc_tMrubyc_CB_initialize();

#define INITIALIZE_TECS() \
 	nMruby_tsKernel_CB_initialize();\
 	nMruby_tsKernel_Initializer_CB_initialize();\
 	nMruby_tsSample_CB_initialize();\
 	nMruby_tsSample_Initializer_CB_initialize();\
 	tTask_CB_initialize();\
 	tInitializeRoutine_CB_initialize();\
 	tTerminateRoutine_CB_initialize();\
 	tISR_CB_initialize();\
 	tConfigInterrupt_CB_initialize();\
 	tSemaphore_CB_initialize();\
 	tKernel_CB_initialize();\
 	tSIOPortSkyeyeMain_CB_initialize();\
 	tPutLogSkyeye_CB_initialize();\
 	tSerialPortMain_CB_initialize();\
 	tSysLog_CB_initialize();\
 	tLogTaskMain_CB_initialize();\
 	tSample_CB_initialize();\
 	tSample1_CB_initialize();\
 	nMruby_tTECSInitializer_CB_initialize();\
 	nMruby_tCharPointer_CB_initialize();\
 	nMruby_tIntPointer_CB_initialize();\
 	nMruby_tULongPointer_CB_initialize();\
 	nMruby_tMrubyc_CB_initialize();\
/* INITIALIZE_TECS terminator */

#define INITIALZE_TECSGEN() INITIALIZE_TECS()  /* for backward compatibility */

/* Descriptor for dynamic join */
#define Descriptor( signature_global_name )  DynDesc__ ## signature_global_name
#define is_descriptor_unjoined( desc )  ((desc).vdes==NULL)

#endif /* TOPPERS_MACRO_ONLY */

#define SIO_RDY_SND    ((const uint_t)1)
#define SIO_RDY_RCV    ((const uint_t)2)
#define LogTaskStackSize ((const uint_t)131072)
#define IOCTL_NULL     ((const uint_t)0)
#define IOCTL_ECHO     ((const uint_t)0x0001)
#define IOCTL_CRLF     ((const uint_t)0x0010)
#define IOCTL_FCSND    ((const uint_t)0x0100)
#define IOCTL_FCANY    ((const uint_t)0x0200)
#define IOCTL_FCRCV    ((const uint_t)0x0400)

#endif /* GLOBAL_TECSGEN_H */
