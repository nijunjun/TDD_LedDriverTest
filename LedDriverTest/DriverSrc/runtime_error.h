/*
 * runtime_error.h
 *
 *  Created on: 2018Äê8ÔÂ20ÈÕ
 *      Author: THINK
 */

#ifndef DRIVERSRC_RUNTIME_ERROR_H_
#define DRIVERSRC_RUNTIME_ERROR_H_

void RuntimeError(const char *message, int parameter, const char *file, int line);

#define RUNTIME_ERROR(description, parameter)\
	RuntimeError(description, parameter, __FILE__, __LINE__)

#endif /* DRIVERSRC_RUNTIME_ERROR_H_ */
