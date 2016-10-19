/*================================================================================================*/
/*
 * g2OsThread.h
 *
 *  Created on: 19.10.2016
 *      Author: grzegorz
 */

/*================================================================================================*/
#ifndef G2OSTHREAD_H_
#define G2OSTHREAD_H_
/*================================================================================================*/
#include "g2systemInit.h"
/*================================================================================================*/
#define OS_THREAD_STACK 200
#define OS_MAX_THREAD_CNT 5
/*================================================================================================*/
#define G2OS_PendSV_Handler PendSV_Handler
/*================================================================================================*/
int registerThread(void* thread, const char* name, void* parameters);
void runOS(void);
/*================================================================================================*/
#endif /* G2OSTHREAD_H_ */
/*================================================================================================*/
/*                                              EOF                                               */
/*================================================================================================*/
