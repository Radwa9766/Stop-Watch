 


#ifndef STDTYPES_H_
#define STDTYPES_H_


union{
	struct{
		unsigned char b1:1;
		unsigned char b2:1;
		unsigned char b3:1;
		unsigned char b4:1;
		unsigned char b5:1;
		unsigned char b6:1;
		unsigned char b7:1;
		unsigned char b8:1;
	};
	unsigned char reg;
	
}reg_t;


typedef unsigned char u8;
typedef signed char s8;

typedef unsigned int u16;
typedef signed int s16;

typedef unsigned long u32;
typedef signed long s32;

typedef enum{
	FALSE=0X55,
	TRUE=0XAA
}bool_t;

#define NULLPTR  ((void*)0)
typedef enum {
	OK,
	NOK,
	NULL_PTR,
	OUT_OF_RANGE,
	BUSY
}error_t;

#define MAX_U8 ((u8)255)
#define MIN_U8 ((u8)0)

#define MAX_S8 ((s8)128)
#define MIN_S8 ((s8)-128)
#define ZERO_S8 ((s8)0)






#endif /* STDTYPES_H_ */