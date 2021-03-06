/*
 * rtc.h
 *
 * Created: 15/06/2015 14:52:50
 *  Author: paul.qureshi
 */ 


#ifndef RTC_H_
#define RTC_H_


typedef struct 
{
	uint8_t	d, m, y;
	uint8_t hrs, mins, secs;
} RTC_time_t;


extern volatile uint8_t	RTC_second_tick_SIG;
extern volatile uint8_t	RTC_minute_tick_SIG;

extern void RTC_init(void);
extern void RTC_wait_for_second_tick(void);
extern void RTC_get_time(RTC_time_t *time)	__attribute__((nonnull));
extern bool RTC_validate(RTC_time_t *time)	__attribute__((nonnull));
extern void RTC_adjust_for_timezone(RTC_time_t *time, int8_t hours_offset)	__attribute__((nonnull));



#endif /* RTC_H_ */