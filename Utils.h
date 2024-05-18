/*
 * Utils.h
 *
 * Created: 10/17/2023 12:00:08 AM
 *  Author: KimoStore
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define GET_BIT(reg,bit)  ((reg>>bit)&1)
#define SET_BIT(reg,bit)  (reg=reg|(1<<bit))
#define CLR_BIT(reg,bit)  (reg=reg&~(1<<bit))
#define TOG_BIT(reg,bit)  (reg=reg^(1<<bit))

#endif /* UTILS_H_ */