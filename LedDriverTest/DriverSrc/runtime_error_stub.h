/*
 * runtime_error_stub.h
 *
 *  Created on: 2018Äê8ÔÂ20ÈÕ
 *      Author: THINK
 */

#ifndef DRIVERSRC_RUNTIME_ERROR_STUB_H_
#define DRIVERSRC_RUNTIME_ERROR_STUB_H_

#include "runtime_error.h"

void RuntimeErrorStub_Reset(void);
const char  *RuntimeErrorStub_GetLastError(void);
int RuntimeErrorStub_GetLastParameter(void);

#endif /* DRIVERSRC_RUNTIME_ERROR_STUB_H_ */
