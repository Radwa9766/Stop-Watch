
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"



#define F_CPU 8000000
#include <util/delay.h>
#define SEGMENT_PORT  PORTA
const u8 SegmentArr[]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
const u8 SegmentArr2[]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F,0X77,0X7F,0X39,0X3F,0X79};




void segment_Display_MULBLX(u8 num)
{
	u8 d0,d1;
	d0=num%10;
	d1=num/10;
	
	SET_BIT(PORTC,6);
	SEGMENT_PORT=SegmentArr[d0]<<1;
	CLR_BIT(PORTC,7);
	_delay_ms(1);
	SET_BIT(PORTC,7);
	SEGMENT_PORT=SegmentArr[d1]<<1;
	CLR_BIT(PORTC,6);
	_delay_ms(1);
}


int main()
{
u8 x=30;
u8 flag=0;
DDRC=0XFF;
PORTC=0;
DDRA=0XFF;
PORTA=0;
DDRD=0;
PORTD=0XFF;
DDRB=0XFF;
PORTB=0;

u8 mode=0;
u8 i=0;

while (1)
{
	if (!GET_BIT(PIND,4))
	{
		flag=0;
		mode++;
		if(mode==3)
		{
			mode=0;
		}
		_delay_ms(10);
		while(!GET_BIT(PIND,4))
		{
			segment_Display_MULBLX(x);
		}
		_delay_ms(10);
	}
	if(mode==0)
	{
		
		if(!GET_BIT(PIND,2))
		{
			flag^=1;
			_delay_ms(10);
			while(!GET_BIT(PIND,2));
			{
				segment_Display_MULBLX(x);
			}
			_delay_ms(10);
		}
		if(!GET_BIT(PIND,3))
		{
			x=30;
			flag=0;
			_delay_ms(10);
			while(!GET_BIT(PIND,3))
			{
				segment_Display_MULBLX(x);
			}
			_delay_ms(10);
		}
		if(flag==0)
		{
			segment_Display_MULBLX(x);
		}
		
		if(flag==1)
		{
			for(u8 i=0;i<250 ;i++)
			{
				if(!GET_BIT(PIND,2))
				{
					flag^=1;
					while(!GET_BIT(PIND,2))
					{
						segment_Display_MULBLX(x);
					}
					break;
				}
				segment_Display_MULBLX(x);
			}
			x--;
			if(x==255)
			{
				x=30;
				
			}
			if(x==0)
			{
				
				for(u8 j=0;j<2;j++)
				{
					for(u8 i=0;i<150;i++)
					{
						segment_Display_MULBLX(x);
					}
					SET_BIT(PORTC,5);
					SET_BIT(PORTC,0);
					SET_BIT(PORTC,1);
					for(i=0;i<150;i++)
					{
						segment_Display_MULBLX(x);
					}
					CLR_BIT(PORTC,5);
					CLR_BIT(PORTC,0);
					CLR_BIT(PORTC,1);
					for(i=0;i<150;i++)
					{
						segment_Display_MULBLX(x);
					}
					
					SET_BIT(PORTC,5);
					SET_BIT(PORTC,0);
					SET_BIT(PORTC,1);
					for(i=0;i<150;i++)
					{
						segment_Display_MULBLX(x);
					}for(i=0;i<150;i++)
					{
						segment_Display_MULBLX(x);
					}
					CLR_BIT(PORTC,5);
					CLR_BIT(PORTC,0);
					CLR_BIT(PORTC,1);
					flag=0;
					
				}
				
				
			}
			
			
		}
	}
	if(mode==1)
	{
		while(!GET_BIT(PIND,2))
		{
			x=x+10;
			if((x/10)>9)
			{
				x=x%10;
			}
			for(u8 i=0;i<250 ;i++)
			{
				
				segment_Display_MULBLX(x);
			}
		}
		while(!GET_BIT(PIND,3))
		{
			x=x-10;
			if(x>100)
			{
				x=x+100;
			}
			for(u8 i=0;i<250 ;i++)
			{
				
				segment_Display_MULBLX(x);
			}
		}
		if(flag==0)
		{
			segment_Display_MULBLX(x);
		}
	}
	if(mode==2)
	{
		while(!GET_BIT(PIND,2))
		{
			x++;
			if(x==100)
			{
				x=0;
			}
			if(x%10==0)
			{
				x=x-10;
			}
			
			for(u8 i=0;i<250 ;i++)
			{
				segment_Display_MULBLX(x);
			}
		}
		while(!GET_BIT(PIND,3))
		{
			x--;
			if(x==255)
			{
				x=0;
			}
			if(x%10==9)
			{
				x=x+10;
			}
			for(u8 i=0;i<250 ;i++)
			{
				segment_Display_MULBLX(x);
			}
			
		}
		if(flag==0)
		{
			segment_Display_MULBLX(x);
		}
	}
 	
}
}
